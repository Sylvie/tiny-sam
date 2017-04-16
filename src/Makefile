CXX=g++
CXXFLAGS+=-g -std=c++14 -Wall -pedantic
DEPS=

targetnames=hello.out
objectnames=hello.o
builddir=../build/
targets=$(addprefix $(builddir), $(targetnames))
objects=$(addprefix $(builddir), $(objectnames))

all: resources $(targets)

resources:
	mkdir -p $(builddir)

$(builddir)%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(targets): $(objects)
	$(CXX) -o $@ $^ $(CXXFLAGS)

dist: $(targets)
	cp $(targets) ../$(distDir)