noinst_PROGRAMS += test/unit/FactorialTests test/unit/GreetingsProviderTests test/unit/UnitTests
TESTS += test/unit/FactorialTests test/unit/GreetingsProviderTests test/unit/UnitTests

test_unit_FactorialTests_SOURCES = test/unit/factorial.cpp ${catch_source_files}
test_unit_FactorialTests_CPPFLAGS = -I $(top_srcdir)/src -I $(top_srcdir)/test/utils

test_unit_GreetingsProviderTests_SOURCES = test/unit/GreetingsProviderTests.cpp src/GreetingsProvider.cpp src/GreetingsProvider.hpp ${catch_source_files}
test_unit_GreetingsProviderTests_CPPFLAGS = -I $(top_srcdir)/src -I $(top_srcdir)/test/utils

test_unit_UnitTests_SOURCES = test/unit/factorial.cpp test/unit/GreetingsProviderTests.cpp src/GreetingsProvider.cpp src/GreetingsProvider.hpp ${catch_source_files}
test_unit_UnitTests_CPPFLAGS = -I $(top_srcdir)/src -I $(top_srcdir)/test/utils

## Cleaning ##
clean-local-test-unit:
	 $(RM) -rf $(addsuffix .dSYM , $(TESTS))
