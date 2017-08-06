## Process this file with automake to produce Makefile.in

#SUBDIRS = manual

destDirPrefix=tiny-sam-

EXTRA_DIST = $(top_srcdir)/.version
BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

bin_PROGRAMS = hello
hello_SOURCES = src/hello.cpp

#dist_doc_DATA = manual/manual.tex manual/bibliography.bib

#sambadoc_SOURCES = manual/manual.tex manual/bibliography.bib


#dist: updateVersionNumber
#	$(eval distDir := $(destDirPrefix)$(versionNumber)$(OSNamePostfix) )
#	mkdir -p $(distDir)
#	cp VERSION $(distDir)
#	+$(MAKE) dist -C src/ distDir=$(distDir)
#	+$(MAKE) dist -C manual/ distDir=$(distDir)
#	tar -zcvf $(strip $(distDir)).tar.gz $(distDir)

pdf-local: pdf-local-manual

MOSTLYCLEANFILES =
CLEANFILES =
DISTCLEANFILES =
MAINTAINERCLEANFILES =
REPOCLEANFILES = $(addprefix $(srcdir)/, aclocal.m4 Makefile.in configure depcomp install-sh missing)

clean-local: clean-local-manual
	rm -fr build/ $(destDirPrefix)v*/ $(destDirPrefix)*.tar.gz

repo-clean: maintainer-clean repo-clean-local-manual
	rm -rf $(REPOCLEANFILES)

updateVersionNumber:
	$(srcdir)/update-version-number.sh
	$(eval versionNumber := $(shell head -1 VERSION))
	$(eval buildNumber := $(shell head -2 VERSION | tail -1))
	echo "$(versionNumber)" "$(buildNumber)"

include manual/Makefile.mk
