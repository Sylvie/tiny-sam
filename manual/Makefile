builddir=build/

inputfile=manual.tex
output=sambadoc

all: resources manual

resources:
	mkdir -p $(builddir)

manual: $(inputfile)
	latexmk -jobname=$(output) $(inputfile) -pdf

clean:
	latexmk -C -jobname=$(output)