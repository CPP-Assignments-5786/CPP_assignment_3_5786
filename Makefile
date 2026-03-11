CXX=clang++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion
TIDY_FLAGS=-checks='*,-fuchsia-*,-llvm-header-guard,-misc-include-cleaner' --warnings-as-errors='*'
SOURCES=Book.cpp LibraryCard.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: demo
	./demo

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

tidy:
	clang-tidy $(SOURCES) main.cpp test.cpp $(TIDY_FLAGS) -- $(CXXFLAGS)

student_test: StudentTestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o student_test
	./student_test

StudentTestRunner.o: StudentTest.cpp doctest.h
	$(CXX) $(CXXFLAGS) --compile StudentTest.cpp -o StudentTestRunner.o

TestRunner.o: test.cpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test student_test

.PHONY: all test tidy student_test clean