TEX=xelatex
SEC=Scanner
PAR=Parser
PART1=teil1
PART2=teil2

all: $(SEC) $(PAR)

$(PART1): $(SEC)
$(PART1).pdf: $(SEC)

$(SEC): 
	$(TEX) $(PART1)
	mv $(PART1).pdf ../$(SEC).pdf

$(PAR):
	$(TEX) $(PART2)
	mv $(PART2).pdf ../$(PAR).pdf

nclean: 
	$(nclean)

clean:
	$(nclean) ../*.pdf

nclean:= rm -f *.aux *.bbl *.bcf *.blg *.lof *.log *.out *.toc
