#gnuplot dst.plt
#cd dst && for I in $(seq 0 1 50);do pdflatex $I.tex; rm -f *.aux *.log $I.tex;done
#pdf= ; for I in $(seq 0 1 50);do pdf+="$I.pdf"; rm -f $I.pdf; done; pdftk $pdf cat output merged.pdf

NG= ` sed -n "/#define NG / p" ../rps.h | cut -f3 -d" "`
NF= ` sed -n "/#define NF / p" ../rps.h | cut -f3 -d" "`

set terminal tikz fulldoc size 8.4cm, 5.0cm
ext="tex"

set yrange [0:1]
set xrange [0:NG]
set ytics 0 ,0.2
set xtics 0, NG/4
set xlabel 't'
set ylabel 'ρ'

i= 0
j= 0.03
while (i <= 100){
	set output sprintf("dst/%d.tex", i)
	set title sprintf("pm= %.2f", j*i)
	plot sprintf("../dat/dst/%.2f-0.dat", j*i) u 0:1 w l lc rgb "#000000" t"",\
		 sprintf("../dat/dst/%.2f-0.dat", j*i) u 0:2 w l lc rgb "#FF6666" t"",\
		 sprintf("../dat/dst/%.2f-0.dat", j*i) u 0:3 w l lc rgb "#6666FF" t"",\
		 sprintf("../dat/dst/%.2f-0.dat", j*i) u 0:4 w l lc rgb "#99FF99" t"",\

	i= i+1
}

unset output
