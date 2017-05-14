CXX=g++
CXXFLAGS+=-g -std=c++14 -Wall -pedantic
CPPFLAGS+=-static-libstdc++ -static-libgcc
DEPS=

targetnames=hello
objectnames=hello.o
builddir=../build/
targets=$addsuffix($(addprefix $(builddir), $(targetnames)), $(SUFFIX_SYS))
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