CXX=g++
CXXFLAGS+=-g -std=c++11 -Wall -pedantic
DEPS=
OBJ=hello.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

hello: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)
