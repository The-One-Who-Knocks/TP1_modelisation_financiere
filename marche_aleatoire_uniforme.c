#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double my_rand_unif(double a, double b);  /* Fonction tirant un nombre selon une loi
                                              uniforme sur [a, b] */

int main(void){

	srand((unsigned)time(NULL));  // Initialisation de la graine


	/* Ouverture du fichier nom_fichier */
	char* nom_fichier = "marche_aleatoire_uniforme.dat";
	FILE* file = NULL;
	file = fopen(nom_fichier, "w");
	if(file == NULL){
		fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", nom_fichier);
		exit(EXIT_FAILURE);
	}


	int n_pas = 0;         // Nombre de pas
	double a = 0.;         // Parametres de la loi uniforme
	double b = 0.;
	double position = 0.;  // Position de la particule


	printf("Nombre de pas ? ");
	scanf("%d", &n_pas);
	printf("\nn_pas = %d\n", n_pas);

	printf("Parametre a ? ");
	scanf("%lf", &a);
	printf("\na = %g\n", a);

	printf("Parametre b ? ");
	scanf("%lf", &b);
	printf("\nb = %g\n", b);

	/* Marche(s) aleatoire(s) */
	//fprintf(file, "%d %g\n", 0, position);
	for(int i=0;i<n_pas;i++){
		position += my_rand_unif(a, b);
		fprintf(file, "%d %g\n", i+1, position);
	}
	
	fclose(file);

	exit(EXIT_SUCCESS);
}


double my_rand_unif(double a, double b){
	return ((double)rand()/(double)RAND_MAX)*(b-a) + a;
}
