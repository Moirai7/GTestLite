#include "MemStream.h"

#include <cstring>
#include <cstdio>

 
using namespace std;

template<typename ValueType>
void FormatToStream(MemoryOutStream& stream, char const* format, ValueType const& value)
{
    char txt[32];
    sprintf(txt, format, value);
    stream << txt;
}

int RoundUpToMultipleOfPow2Number (int n, int pow2Number)
{
    return (n + (pow2Number - 1)) & ~(pow2Number - 1);
}

MemoryOutStream::MemoryOutStream(int const size)
    : m_capacity (0)
    , m_buffer (0)

{
    GrowBuffer(size);
}

MemoryOutStream::~MemoryOutStream()
{
    delete [] m_buffer;
}

char const* MemoryOutStream::GetText() const
{
    return m_buffer;
}

MemoryOutStream& MemoryOutStream::operator << (char const* txt)
{
    int const bytesLeft = m_capacity - (int)strlen(m_buffer);
    int const bytesRequired = (int)strlen(txt) + 1;

    if (bytesRequired > bytesLeft)
    {
        int const requiredCapacity = bytesRequired + m_capacity - bytesLeft;
        GrowBuffer(requiredCapacity);
    }

    strcat(m_buffer, txt);
    return *this;
}

MemoryOutStream& MemoryOutStream::operator << (int n)
{
    FormatToStream(*this, "%i", n);
    return *this;
}

MemoryOutStream& MemoryOutStream::operator << (long n)
{
    FormatToStream(*this, "%li", n);
    return *this;
}

MemoryOutStream& MemoryOutStream::operator << (unsigned long n)
{
    FormatToStream(*this, "%lu", n);
    return *this;
}

MemoryOutStream& MemoryOutStream::operator << (float f)
{
    FormatToStream(*this, "%ff", f);
    return *this;    
}

MemoryOutStream& MemoryOutStream::operator << (void const* p)
{
    FormatToStream(*this, "%p", p);
    return *this;    
}

MemoryOutStream& MemoryOutStream::operator << (unsigned int s)
{
    FormatToStream(*this, "%u", s);
    return *this;    
}

MemoryOutStream& MemoryOutStream::operator <<(double d)
{
	FormatToStream(*this, "%f", d);
	return *this;
}

MemoryOutStream& MemoryOutStream::operator << (long long n)
{
    FormatToStream(*this, "%lld", n);
    return *this;
}

MemoryOutStream& MemoryOutStream::operator << (unsigned long long n)
{
    FormatToStream(*this, "%llu", n);
    return *this;
}

int MemoryOutStream::GetCapacity() const
{
    return m_capacity;
}


void MemoryOutStream::GrowBuffer(int desiredCapacity)
{
    int const newCapacity = RoundUpToMultipleOfPow2Number(desiredCapacity, GROW_CHUNK_SIZE);

    char* buffer = new char[newCapacity];
    if (m_buffer)
        strcpy(buffer, m_buffer);
    else
        strcpy(buffer, "");

    delete [] m_buffer;
    m_buffer = buffer;
    m_capacity = newCapacity;
}

void MemoryOutStream::Reset()
{
    if (m_buffer)
        m_buffer[0] = '\0';
}

 

 
