tiny_sam_integration_tests = test/integration/HelloIntegrationTests \
 		test/integration/WriteModelsTests \
 		test/integration/CompareModelsTests

noinst_PROGRAMS += ${tiny_sam_integration_tests}
TESTS += ${tiny_sam_integration_tests}

test_integration_HelloIntegrationTests_SOURCES = test/integration/HelloIntegrationTests.cpp ${catch_source_files}
test_integration_HelloIntegrationTests_CPPFLAGS = -I $(top_srcdir)/src \
 		-I $(top_srcdir)/test/utils \
 		-I $(top_srcdir)/test/integration/utils \
 		-Dtiny_sam_executable_extension=\"${tiny_sam_executable_extension}\"
test_integration_HelloIntegrationTests_LDADD = $(top_builddir)/test/integration/utils/libTinySamIntegrationTestUtils.a

test_integration_WriteModelsTests_SOURCES = test/integration/WriteModelsTests.cpp ${catch_source_files}
test_integration_WriteModelsTests_CPPFLAGS = -I $(top_srcdir)/test/utils -I $(top_srcdir)/test/integration/utils -Dtiny_sam_executable_extension=\"${tiny_sam_executable_extension}\"
test_integration_WriteModelsTests_LDADD = $(top_builddir)/test/integration/utils/libTinySamIntegrationTestUtils.a

test_integration_CompareModelsTests_SOURCES = test/integration/CompareModelsTests.cpp ${catch_source_files}
test_integration_CompareModelsTests_CPPFLAGS = -I $(top_srcdir)/src \
 		-I $(top_srcdir)/test/utils \
 		-I $(top_srcdir)/test/integration/utils \
 		-Dtiny_sam_executable_extension=\"${tiny_sam_executable_extension}\"

test_integration_CompareModelsTests_LDADD = \
 		$(top_builddir)/test/integration/utils/libTinySamIntegrationTestUtils.a \
 		$(top_builddir)/test/utils/libTinySamTestUtils.a

include test/integration/utils/Makefile.mk
include test/integration/createprocess/Makefile.mk