include test/utils/Makefile.mk

include test/unit/Makefile.mk

include test/integration/Makefile.mk

## Cleaning ##
clean-local-test: clean-local-test-unit
