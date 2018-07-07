tiny_sam_binaries = src/hello src/writeModels

bin_PROGRAMS += $(tiny_sam_binaries)

src_hello_SOURCES = src/hello.cpp src/GreetingsProvider.cpp src/GreetingsProvider.hpp

src_writeModels_SOURCES = src/writeModels.cpp

## Cleaning ##
clean-local-src:
	$(RM) -rf $(addsuffix .dSYM , $(tiny_sam_binaries))
