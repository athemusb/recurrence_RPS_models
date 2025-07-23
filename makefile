rps:
	@gcc -O3 -Wall src/rps.c -lgsl -lgslcblas -lm -o rps.out

clean:
	@rm -f dat/dst/*.dat
	@rm -f dat/fig/*.dat
	@rm -f *.out
	@rm -f abund.dat
	@rm -f plt/fig/*.png
	@rm -f plt/*.pdf
