manual_directory := "manual/"
manual_sources := $(srcdir)/manual/manual.tex
manual_pdf := $(builddir)/manual/manual.pdf

EXTRA_DIST += $(manual_sources) $(manual_pdf)

LATEXMK = latexmk -r $(srcdir)/manual/latexmkrc -output-directory=$(manual_directory)
LATEXMK_CLEAN = latexmk -r ../$(srcdir)/manual/latexmkrc


prepare_manual_directory:
	if [ "$(srcdir)" != "." ]; then \
		mkdir -p $(manual_directory); \
		cp $(srcdir)/manual/bibliography.bib $(manual_directory); \
		cp $(srcdir)/manual/manual.tex $(manual_directory); \
	fi

pdf-local-manual : $(manual_pdf)

%.pdf : %.tex | prepare_manual_directory
	$(LATEXMK) -pdf $^

dist-local-manual: $(outputFile)
	cp $(manualTargets) ../$(distDir)

clean-local-manual:
	cd $(manual_directory); \
	$(LATEXMK_CLEAN) -c

repo-clean-local-manual:
	cd $(manual_directory); \
	$(LATEXMK_CLEAN) -C
	if [ "$(srcdir)" != "." ]; then \
		rm manual/bibliography.bib ; \
		rm manual/manual.tex ; \
	fi
