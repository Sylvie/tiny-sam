CXX=g++
CXXFLAGS+=-g -std=c++14 -Wall -pedantic
DEPS=

targetnames=hello.out
objectnames=hello.o
builddir=../build
targets=$(addprefix $(builddir)/, $(targetnames))
objects=$(addprefix $(builddir)/, $(objectnames))

all: resources $(targets)

resources:
	mkdir -p $(builddir)

$(builddir)/%.o: %.cpp $(DEPS)
	echo "Hello"
	echo $(CXX) -c -o $@ $< $(CXXFLAGS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(targets): $(objects)
	echo "Hi"
	echo $(objects)
	echo $(CXX) -o $@ $^ $(CXXFLAGS)
	$(CXX) -o $@ $^ $(CXXFLAGS)
