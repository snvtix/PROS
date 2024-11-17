//Natalia Slepowronska
//22.10.2024
//PROS lab1

#include <stdio.h>

int main(void){
    char tab[9][9]; //deklaracja tablicy
	char z1 = 'O'; //kolko wstawiane do tablicy
	char z2 = 'X'; //krzyzyk wstawiany do tablicy
	int moves = 17;
	//petla ktora zapelnia kolkami tablice
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			tab[j][i] = z1;
		}
	}
	printf("START\n");
	//prezentacja tablicy przed gra
	printf("  ");
	for(int i = 0; i < 9; i++){
		printf("|");
		printf(" %d ", (i+1));
	}
	printf("\n");
	printf("-------------------------------------\n");
	for(int i = 0; i < 9; i++){
		printf("%d ", (i+1));
		for(int j = 0; j < 9; j++){
			printf("|");
			printf(" %c ",tab[j][i]);
		}
		printf("\n");
		printf("-------------------------------------\n");
	}
	//faktyczny start gry
	for(int count = 0; count < moves; count++){
		int c; //numer kolumny
		int w; //nume wiersza
		printf("pozostala liczba ruchow: %d\n", moves-count);
		printf("podaj kolumne: ");
		scanf("%d", &c);
		if(c > 9){
			break;
		}
		else if(c < 1){
			break;
		}
		printf("podaj wiersz: ");
		scanf("%d", &w);
		if(w > 9){
			break;
		}
		else if(w < 1){
			break;
		}
		printf("\n");
		//wstawienie krzyzyka do kolumny
		if(c == 1 && w == 1){
		    tab[c-1][w-1] = z2;
		    tab[c][w-1] = z2; //prawo
		    tab[c-1][w] = z2; //doly
		}else if(c == 1 && w == 9){
		    tab[c-1][w-1] = z2;
		    tab[c][w-1] = z2; //prawo
		    tab[c-1][w-2] = z2; //gora
		}else if(c == 9 && w == 1){
		    tab[c-1][w-1] = z2;
		    tab[c-2][w-1] = z2; //lewo
		    tab[c-1][w] = z2; //dol
		}else if(c == 9 && w == 9){ 
		    tab[c-1][w-1] = z2;
		    tab[c-2][w-1] = z2; //lewo
		    tab[c-1][w-2] = z2; //gora
		}else if(c == 1 && w != 9){
		    tab[c-1][w-1] = z2;
		    tab[c][w-1] = z2; //prawo
		    tab[c-1][w-2] = z2; //gora
		    tab[c-1][w] = z2; //dol
		}else if(c == 9 && w != 1){
		    tab[c-1][w-1] = z2;
		    tab[c-2][w-1] = z2; //lewo
		    tab[c-1][w] = z2; //gora
		    tab[c-1][w-2] = z2; //gora
		}else if(c != 9 && w == 9){
		    tab[c-1][w-1] = z2;
		    tab[c][w-1] = z2; //prawo
		    tab[c-2][w-1] = z2; //lewo
		    tab[c-1][w-2] = z2; //gora
		}else if(c != 1 && w == 1){
		    tab[c-1][w-1] = z2;
		    tab[c][w-1] = z2; //prawo
		    tab[c-2][w-1] = z2; //lewo
		    tab[c-1][w] = z2; //dol
        }else{
            tab[c-1][w-1] = z2;
		    tab[c][w-1] = z2; //prawo
		    tab[c-2][w-1] = z2; //lewo
		    tab[c-1][w] = z2; //dol
		    tab[c-1][w-2] = z2; //gora
		}
		//wyswietlenie tablicy po zmianach
		printf("  ");
		for(int i = 0; i < 9; i++){
			printf("|");
			printf(" %d ", (i+1));
		}
		printf("\n");
		printf("--------------------------------------\n");
		for(int i = 0; i < 9; i++){
			printf("%d ", (i+1));
			for(int j = 0; j < 9; j++){
				printf("|");
				printf(" %c ",tab[j][i]);
			}
			printf(" \n");
			printf("-------------------------------------\n");
		}
	}
	int pom = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(tab[i][j] != z2){
			    pom++;
			}
		}
	}
	if(pom == 0){
		printf("WYGRANA\n");
	}else{
		printf("PRZEGRANA\n");
	}
	return 0;
 }
