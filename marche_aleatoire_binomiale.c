#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int my_rand_int(int a, int b, double p);  /* Fonction tirant la valeur a selon la probabilite
                                             et la valeur b sinon */

int main(void){

	srand((unsigned)time(NULL));  // Initialisation de la graine


	/* Ouverture du fichier nom_fichier */
	char* nom_fichier = "marche_aleatoire_binomiale.dat";
	FILE* file = NULL;
	file = fopen(nom_fichier, "w");
	if(file == NULL){
		fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", nom_fichier);
		exit(EXIT_FAILURE);
	}


	int n_iter = 0;       // Nombre d'iterations de la marche aleatoire
	int n_pas = 0;        // Nombre de pas
	double p = 0.;        // Probabilite de tirer un pas de 1
	double position = 0.;  // Position de la particule
	double sum = 0.;      // Contient la somme des pas pour un n des differentes marches

	printf("Nombre de marches aleatoires ? ");
	scanf("%d", &n_iter);
	printf("\nn_iter = %d\n", n_iter);

	printf("Nombre de pas ? ");
	scanf("%d", &n_pas);
	printf("\nn_pas = %d\n", n_pas);

	printf("Probabilite d'obtenir un pas de 1 ? ");
	scanf("%lf", &p);
	printf("\np = %g\n", p);

	/* Marche(s) aleatoire(s) */
	//fprintf(file, "%d %g\n", 0, position);
	for(int i=0;i<n_pas;i++){
		sum = 0.;
		for(int j=0;j<n_iter;j++){
			sum += (double)my_rand_int(1, -1, p);
		}
		position += sum/(double)n_iter;
		fprintf(file, "%d %g\n", i+1, position);
	}
	
	fclose(file);

	exit(EXIT_SUCCESS);
}


int my_rand_int(int a, int b, double p){
	double x = (double)rand() / (double)RAND_MAX;  // x dans [0, 1]
	if(x <= p) return a;
	else return b;
}
