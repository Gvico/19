#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(int argc, char **argv)
{
	int nbrMyst;
	int	nbrUsr;
	int	nbrMax;
	int coups;

	nbrUsr = 1;
	nbrMax = -1;
	coups = 0;
	srand(time(NULL));
	while (nbrUsr != 0)
	{
		while (nbrMax < 0)
		{
			printf("\nChoisissez un niveau !\n1 = entre 1 et 100\n2 = entre 1 et 1000\n3 = entre 1 et 10000\n\nVotre niveau ? ");
			scanf("%d", &nbrUsr);
			if (nbrUsr == 1)
				nbrMax = 100;
			else if (nbrUsr == 2)
				nbrMax = 1000;
			else if (nbrUsr == 3)
				nbrMax = 10000;
		}
		nbrMyst = (rand() % nbrMax) + 1;
		while (nbrMyst != nbrUsr)
		{
			coups++;
			printf("\nQuel est le nombre ? ");
			scanf("%d", &nbrUsr);
			if (nbrMyst > nbrUsr)
				printf("C'est plus !\n");
			else if (nbrMyst < nbrUsr)
				printf("C'est moins !\n");
			else
				printf("Bravo, vous avez trouve le nombre mystere en %d coups !\n\n", coups);
		}
		nbrUsr = -1;
		nbrMax = -1;
		while (!(nbrUsr == 0 || nbrUsr == 1))
		{	
			printf("Voulez-vous rejouer (1/0) ? ");
			scanf("%d", &nbrUsr);
		}
	}
	return (0);
}
