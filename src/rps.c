#include "../rps.h"

void op(double m, int REP, int *phi);

int main(int argc, char **argv){
	int i, j, t, ac, ps, tp, nb, gd;
	int *phi, *dst;
	double at;

	if (argc != 3) {
		printf("Feed with: %s rep_seed mob_seed\n", argv[0]);
	}

	dst= (int *) calloc((NS+1)*NG, sizeof(int));
	phi= (int *) calloc(Nx*Ny, sizeof(int));

	gsl_rng_default_seed= (argc == 2) ? atoi(argv[1]) : time(NULL);
	gsl_rng *rand= gsl_rng_alloc(gsl_rng_taus);

	int   REP= atoi(argv[1]);
	double pm= atof(argv[2]);
	double pp= (1-pm)/2;

	do {
		for(i = 0; i < (NS+1)*NG; i++){
			dst[i] = 0;
		}
		for(j= 0; j < Ny; j++){
			for(i= 0; i< Nx; i++){
				phi[j*Nx+i]= gsl_rng_uniform(rand)*(NS+1);
				dst[0*NS + phi[j*Nx+i]]++;
			}
		}

		for(t= 1; t<= NG; t++){
			gd= 0;
			for (i = 0; i < NS+1; i++) {
				dst[t*(NS+1)+i]= dst[(t-1)*(NS+1)+i];
			}

			while(gd < Nx*Ny){
				do{
					i= gsl_rng_uniform(rand)*Nx;
					j= gsl_rng_uniform(rand)*Ny;
					ac= i*Ny+j;
				}while(phi[ac] == 0);
				nb= gsl_rng_uniform(rand)*(NS+1);
				switch(nb){
					case 0:
						ps= i*Ny+(j+1)%Ny;
					break;
					case 1:
						ps= i*Ny+(j-1+Ny)%Ny;
					break;
					case 2:
						ps= ((i+1)%Nx)*Ny+j;
					break;
					default:
						ps= ((i-1+Nx)%Nx)*Ny+j;
				}
				at= gsl_rng_uniform(rand);
				if(at < pm){
	//				mobilidade
					tp= phi[ac];
					phi[ac]= phi[ps];
					phi[ps]= tp;
					gd++;
				}else{
					if(at > pm && at < (pm+pp)){
	//					predação
						if(phi[ps] != 0 && gsl_rng_uniform(rand) < mp[(phi[ac]-1)*3+(phi[ps]-1)]){
							dst[t*(NS+1)+phi[ps]]--;
							dst[t*(NS+1)+0]++;
							phi[ps]= 0;
							gd++;
						}
					}else{
	//					reprodução
						if(phi[ps] == 0){
							dst[t*(NS+1)+phi[ac]]++;
							dst[t*(NS+1)+0]--;
							phi[ps]= phi[ac];
							gd++;
						}
					}
				}
			}

			if(dst[t*(NS+1)+1] == 0 || dst[t*(NS+1)+2] == 0 || dst[t*(NS+1)+3] == 0){
				break;
			}
		}
	}while(t != NG+1);

	op(pm, REP, phi);

	char abc[100];
	FILE *arq;

	sprintf(abc, "dat/dst/%.2f-%d.dat", atof(argv[2]), atoi(argv[1]));
	arq= fopen(abc, "w");
	for (j = 0; j < NG; j++) {
		for (i = 0; i < NS+1; i++) {
			fprintf(arq, "%e ", (double) dst[j*(NS+1)+i]/(Nx*Ny));
		}
		fprintf(arq, "\n");
	}
	fclose(arq);

	free(phi);
	free(dst);
	gsl_rng_free(rand);

	return 0;
}


void op(double pm, int REP, int *phi){
	int i, j;
	char name[100];
	sprintf(name, "dat/fig/%.2f-%d.dat", pm, REP);
	FILE *file= fopen(name,  "w");

	for(j= 0; j< Ny; j++){
		for(i= 0; i< Nx; i++){
			fprintf(file, "%d ", phi[j*Nx+i]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
}
