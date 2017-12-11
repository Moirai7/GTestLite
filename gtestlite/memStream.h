#ifndef  _MEMORYOUTSTREAM_H
#define  _MEMORYOUTSTREAM_H


#include <sstream>
#include <cstddef>

class  MemoryOutStream {
public:
    explicit MemoryOutStream(int const size = 256);
    ~MemoryOutStream();

    char const* GetText() const;

    MemoryOutStream& operator << (const char* txt);
    MemoryOutStream& operator << (int n);
    MemoryOutStream& operator << (long n);
    MemoryOutStream& operator << (unsigned long n);
    MemoryOutStream& operator << (float f);
    MemoryOutStream& operator << (double d);
    MemoryOutStream& operator << (void const* p);
    MemoryOutStream& operator << (unsigned int s);
    MemoryOutStream& operator << (long long n);
    MemoryOutStream& operator << (unsigned long long n);

    enum { GROW_CHUNK_SIZE = 32 };
    int GetCapacity() const;
    void Reset();

private:
    void operator= (MemoryOutStream const&);
    void GrowBuffer(int capacity);

    int m_capacity;
    char* m_buffer;
};

#endif

 
