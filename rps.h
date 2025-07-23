#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gsl/gsl_rng.h>

#define Nx 1000
#define Ny 1000
#define NG 5000
#define NS 3
#define NF 1
#define r (double)NG/NF

const double mp[NS*NS]= {0.0, 1.0, 1.0,\
		   	 1.0, 0.0, 1.0,\
			 1.0, 1.0, 0.0};
