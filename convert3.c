
#include<stdio.h>
#include<math.h>


int main(int argc, char* argv[])
{
    double z,dlum;
    int Npts;
    char filename[100];
    if (argc<4) {
        printf("command line:\n");
        printf("z dlum(mpc) npoints infilename \n");
        printf("infilename should have rows with wavelength (micron) and fluxes\n");
        exit(0);
    }
    sscanf(argv[1],"%lf",&z);
    sscanf(argv[2],"%lf",&dlum);
    sscanf(argv[3],"%d",&Npts);
    sscanf(argv[4],"%s",filename);
    FILE *fpi;
    fpi = fopen(filename,"r");
    char string[300];
    int i;
    for(i=0;i< Npts;i++){
       fgets(string,300,fpi);
       double wave,f10;
       sscanf(string,"%lf %lf",&wave,&f10);
       double wavecore = wave*(1.0+z);
       double dlog = log10(4.0*3.14*dlum*dlum);
       double f10corr = pow(10.0,(f10 - dlog - 48.9788));
       printf("%.2f %.5e\n",wave,f10corr);
    }
}

