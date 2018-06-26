noinst_PROGRAMS += test/integration/IntegrationTests
TESTS += test/integration/IntegrationTests

test_integration_IntegrationTests_SOURCES = test/integration/HelloIntegrationTests.cpp ${catch_source_files}
test_integration_IntegrationTests_CPPFLAGS = -I $(top_srcdir)/src -I $(top_srcdir)/test -Dtiny_sam_executable_extension=\"${tiny_sam_executable_extension}\"
test_integration_IntegrationTests_LDADD = TinySamIntegrationTestUtils.a

if WINDOWS
test_integration_CreateParentProcess_SOURCES = test/integration/CreateParentProcess.cpp test/integration/strsafe.h
test_integration_CreateChildProcess_SOURCES = test/integration/CreateChildProcess.cpp test/integration/strsafe.h
endif

include test/integration/utils/Makefile.mk