builddir=../build/

file=manual

target=$(builddir)/$(file).pdf

all: resources $(target)

resources:
	mkdir -p $(builddir)

$(builddir)/%.pdf: %.tex
	latexmk -help
	latexmk -pdf -output-directory=$(builddir) $< 