COMPILER = g++
CCFLAGS = -g -ansi
LIBFLAGS = gtestlite/cppunitlite.a

%.o : %.cpp
	$(COMPILER) $(CCFLAGS) -c $<

objects = main.o MyTestClass.o fixture_test.o

all: gtestlite tests

gtestlite:
	cd gtestlite/; make

tests: $(objects) 
	${COMPILER} -o test $(objects) ${LIBFLAGS} 
	./tests
    
main.o: main.cpp
MyTestClass.o: MyTestClass.cpp
fixture_test.o: fixture_test.cpp


clean:
	cd lib; make clean
	rm $(objects) test
