builddir=../build/

file=manual

target=$(builddir)/$(file).pdf

all: resources $(target)

resources:
	mkdir -p $(builddir)

$(builddir)/%.pdf: %.tex
	echo Hi $(basename $@)
	latexmk -pdf -output-directory=$(builddir) $< 