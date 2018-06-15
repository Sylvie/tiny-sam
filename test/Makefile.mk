catch_source_files = \
	test/main-catch.cpp \
	test/catch.hpp

include test/unit/Makefile.mk

include test/integration/Makefile.mk

## Cleaning ##
clean-local-test: clean-local-test-unit
