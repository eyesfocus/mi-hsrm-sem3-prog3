#include <stdio.h>

int main(int argc, char *argv[]){
	double x;
	double ai;
	double ai_1;
	int bed = 1;
	double eps = 0.0000001;

	if (argc > 1) { /* es gibt Parameter */
		sscanf(argv[1], "%lf", &x); 
	} else {
		scanf("%lf", &x);
	}
	
	ai = (1+x)/2;
	do{
		ai_1 = (0.5 * (ai + (x/ai)));
	
		if (ai-ai_1 > eps){
			ai = ai_1;	
		} else{
			bed = 0;
		}
	} while (bed);


	printf("%lf \n", ai);

	return 0;

}
