#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <time.h>

#define PI 4*atan(1)

double my_rand_cauchy(double a, double x0);  /* Fonction tirant un nombre selon une
                                             loi de Cauchy de parametres a et x0 */

int main(void){

	srand((unsigned)time(NULL));  // Initialisation de la graine


	/* Ouverture du fichier nom_fichier */
	char* nom_fichier = "marche_aleatoire_cauchy.dat";
	FILE* file = NULL;
	file = fopen(nom_fichier, "w");
	if(file == NULL){
		fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", nom_fichier);
		exit(EXIT_FAILURE);
	}


	int n_pas = 0;        // Nombre de pas
	double a = 0.;        // Parametres de la loi de Cauchy
	double x0 = 0.;
	double position = 0.;  // Position de la particule

	printf("Nombre de pas ? ");
	scanf("%d", &n_pas);
	printf("\nn_pas = %d\n", n_pas);

	printf("Valeur du parametre a ? ");
	scanf("%lf", &a);
	printf("\na = %g\n", a);

	printf("Valeur du parametre x0 ? ");
	scanf("%lf", &x0);
	printf("\nx0 = %g\n", x0);

	/* Marche(s) aleatoire(s) */
	//fprintf(file, "%d %g\n", 0, position);
	for(int i=0;i<n_pas;i++){
		position += my_rand_cauchy(a, x0);
		fprintf(file, "%d %g\n", i+1, position);
	}
	
	fclose(file);

	exit(EXIT_SUCCESS);
}


double my_rand_cauchy(double a, double x0){
	return a*tan(PI*((double)rand()/(double)RAND_MAX - 0.5)) + x0;
}
