destDirPrefix=tiny-sam-

all: updateVersionNumber
	+$(MAKE) -C src/
	+$(MAKE) -C manual/

dist: updateVersionNumber
	$(eval distDir := $(destDirPrefix)$(versionNumber)$(OSNamePostfix) )
	mkdir -p $(distDir)
	cp VERSION $(distDir)
	+$(MAKE) dist -C src/ distDir=$(distDir)
	+$(MAKE) dist -C manual/ distDir=$(distDir)
	tar -zcvf $(strip $(distDir)).tar.gz $(distDir)

clean:
	rm -fr build/ $(destDirPrefix)v*/ $(destDirPrefix)*.tar.gz
	+$(MAKE) clean -C manual/

updateVersionNumber:
	./update-version-number.sh
	$(eval versionNumber := $(shell head -1 VERSION) )
	$(eval buildNumber := $(shell head -2 VERSION | tail -1) )
	echo $(versionNumber) $(buildNumber)