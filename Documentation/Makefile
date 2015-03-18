SEC=Scanner
PAR=Parser
PART1=teil1
PART2=teil2

all:
	make -C src

$(PART1): $(SEC)
$(PART1).pdf: $(SEC)
$(SEC): 
	make $(SEC) -C src

$(PART2): $(PAR)
$(PART2).pdf: $(PAR)
$(PAR): 
	make $(PAR) -C src


nclean:
	make nclean -C src

clean:
	make clean -C src