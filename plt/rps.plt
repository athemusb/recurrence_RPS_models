Ny= ` sed -n "/#define Nx / p" ../rps.h | cut -f3 -d" "`
Nx= ` sed -n "/#define Ny / p" ../rps.h | cut -f3 -d" "`
NF= ` sed -n "/#define NF / p" ../rps.h | cut -f3 -d" "`
NS= ` sed -n "/#define NS / p" ../rps.h | cut -f3 -d" "`

set terminal pngcairo size 720, 720 crop

unset xtics
unset ytics
unset colorbox
unset key

set xrange [0.5: Nx+0.5]
set yrange [0.5: Ny+0.5]
set cbrange [0:NS]
set border
set size ratio -1

set palette define (0 "#ffffff", 1 "#a455ff", 2 "#ffa455", 3 "#55ffff")
i= 0
j=0.03
while (i <= 100){
	set output sprintf("fig/%.2f-%d.png", i*j, 0)
	set title sprintf("pm= %.2f | REP= %d", i*j, 0)
	plot sprintf("../dat/fig/%.2f-%d.dat", i*j, 0) u ($1+1):($2+1):($3) matrix w image
	i= i+1
}
