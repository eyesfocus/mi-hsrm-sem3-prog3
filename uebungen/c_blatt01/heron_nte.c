#include <stdio.h>

double pow(double base, double exp){
  double result = 1;
  int i;
  for (i = 1; i <= exp; i++){
    result = result * base;
  }

  return result;
}

double absolute(double x){
  if(x > 0){
    return x;
  }
  return x*(-1);
}

double ntewurzel(double x, double n){
	double eps;
	double ai;
	double ai_1;
	double diff;

	eps = 0.00000001;
	diff = eps*2;
	ai=x;

	while (diff > eps){
	  ai_1 = ai - ((pow(ai, n) - x)/(n*pow(ai, n-1)));
	  diff = absolute(ai_1 - ai);
	}

	return ai_1;
}

int main(int argc, char *argv[]){
  
  double x = (double) atof(argv[1]);
  double n = (double) atof(argv[2]);

  printf("ergebnis: %f\n", ntewurzel(x,n));

   return 0;
}
