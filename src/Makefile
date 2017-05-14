CXX=g++
CXXFLAGS+=-g -std=c++14 -Wall -pedantic
CXXFLAGS+=-static-libstdc++ -static-libgcc
DEPS=

targetnames=hello
objectnames=hello.o
builddir=../build/
targets=$(addsuffix $(SUFFIX_SYS), $(addprefix $(builddir), $(targetnames)))
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