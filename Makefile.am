#SUBDIRS = src manual

destDirPrefix=tiny-sam-

EXTRA_DIST = $(top_srcdir)/.version
BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

all: #updateVersionNumber
#	+$(MAKE) -C src/
#	+$(MAKE) -C manual/

bin_PROGRAMS = hello
hello_SOURCES = src/hello.cpp

#dist: updateVersionNumber
#	$(eval distDir := $(destDirPrefix)$(versionNumber)$(OSNamePostfix) )
#	mkdir -p $(distDir)
#	cp VERSION $(distDir)
#	+$(MAKE) dist -C src/ distDir=$(distDir)
#	+$(MAKE) dist -C manual/ distDir=$(distDir)
#	tar -zcvf $(strip $(distDir)).tar.gz $(distDir)

pdf: #updateVersionNumber
	+$(MAKE) pdf -C manual/

clean:
	rm -fr build/ $(destDirPrefix)v*/ $(destDirPrefix)*.tar.gz
	+$(MAKE) clean -C manual/

dist-clean: clean

maintainer-clean: dist-clean

repo-clean: maintainer-clean
	rm -rf autom4te.cache/ aclocal.m4 Makefile Makefile.in config.log config.status configure install-sh missing
	+$(MAKE) maintainer-clean -C manual/


updateVersionNumber:
	$(srcdir)/update-version-number.sh
	$(eval versionNumber := $(shell head -1 VERSION))
	$(eval buildNumber := $(shell head -2 VERSION | tail -1))
	echo "$(versionNumber)" "$(buildNumber)"
