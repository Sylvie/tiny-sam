CXX=g++
CXXFLAGS+=-g -std=c++14 -Wall -pedantic
DEPS=
OBJ=hello.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

hello.out: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)
