noinst_PROGRAMS += test/integration/IntegrationTests
TESTS += test/integration/IntegrationTests

test_integration_IntegrationTests_SOURCES = test/integration/HelloIntegrationTests.cpp ${catch_source_files}
test_integration_IntegrationTests_CPPFLAGS = -I $(top_srcdir)/src -I $(top_srcdir)/test -Dtiny_sam_executable_suffix=\"${tiny_sam_executable_suffix}\"
