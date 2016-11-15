#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <time.h>

#define PI 4*atan(1)

double my_rand_gauss(double mu, double sigma);  /* Fonction tirant un nombre selon une
                                                loi gaussienne de parametres mu et sigma */

int main(void){

	srand((unsigned)time(NULL));  // Initialisation de la graine


	/* Ouverture du fichier nom_fichier */
	char* nom_fichier = "marche_aleatoire_gaussienne.dat";
	FILE* file = NULL;
	file = fopen(nom_fichier, "w");
	if(file == NULL){
		fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", nom_fichier);
		exit(EXIT_FAILURE);
	}


	int n_pas = 0;         // Nombre de pas
	double mu = 0.;        // Parametres de la distribution gaussienne
	double sigma = 0.;
	double position = 0.;  // Position de la particule

	printf("Nombre de pas ? ");
	scanf("%d", &n_pas);
	printf("\nn_pas = %d\n", n_pas);

	printf("Parametre mu ? ");
	scanf("%lf", &mu);
	printf("\nmu = %g\n", mu);

	printf("Parametre sigma ? ");
	scanf("%lf", &sigma);
	printf("\nsigma = %g\n", sigma);

	/* Marche(s) aleatoire(s) */
	//fprintf(file, "%d %g\n", 0, position);
	for(int i=0;i<n_pas;i++){
		position += my_rand_gauss(mu, sigma);
		fprintf(file, "%d %g\n", i+1, position);
	}
	
	fclose(file);

	exit(EXIT_SUCCESS);
}


double my_rand_gauss(double mu, double sigma){
	double R = sqrt(-2 * log((double)rand()/(double)RAND_MAX));
	double theta = 2 * PI * ((double)rand()/(double)RAND_MAX);
	return mu + sigma*R*cos(theta);
}
