#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
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
	double moment_1 = 0.;  // Contient la somme des pas pour un n des differentes marches
	double moment_2 = 0.;  // Contient la somme des pas au carre pour un n des differentes marches
	double std_dev = 0.;  // Ecart type

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
		moment_1 = 0.;
		moment_2 = 0.;
		for(int j=0;j<n_iter;j++){
			double rand_num = (double)my_rand_int(1, -1, p);
			moment_1 += rand_num;
			moment_2 += rand_num*rand_num;
		}
		moment_1 /= (double) n_iter;
		moment_2 /= (double) n_iter;
		position += moment_1;
		std_dev += sqrt(moment_2 - moment_1*moment_1);
		fprintf(file, "%d %g %g\n", i+1, position, std_dev);
	}
	
	fclose(file);

	exit(EXIT_SUCCESS);
}


int my_rand_int(int a, int b, double p){
	double x = (double)rand() / (double)RAND_MAX;  // x dans [0, 1]
	if(x <= p) return a;
	else return b;
}
