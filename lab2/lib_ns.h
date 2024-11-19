//Natalia Slepowronska
//22.10.2024
//PROS lab1

#include <stdio.h>

void gen_tab(char (*tab)[9], char z){
	//petla ktora zapelnia kolkami tablice
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
		    *(*(tab+j)+i) = z;
		}
	}
}

void print_tab(char (*tab)[9]){
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
			printf(" %c ",*(*(tab+j)+i));
		}
		printf("\n");
		printf("-------------------------------------\n");
	}
	printf("\n");
}

void insert_char(char (*tab)[9], int c, int w, char z){
		//wstawienie krzyzyka do kolumny
		if(c == 1 && w == 1){
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c))+(w-1)) = z; //prawo
		    *(*(tab+(c-1))+(w)) = z; //dol
		}else if(c == 1 && w == 9){
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c))+(w-1)) = z; //prawo
		    *(*(tab+(c-1))+(w-2)) = z; //gora
		}else if(c == 9 && w == 1){
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c-2))+(w-1)) = z; //lewo
		    *(*(tab+(c-1))+(w)) = z; //dol
		}else if(c == 9 && w == 9){
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c-2))+(w-1)) = z; //lewo
		    *(*(tab+(c-1))+(w-2)) = z; //gora
		}else if(c == 1 && w != 9){
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c))+(w-1)) = z; //prawo
		    *(*(tab+(c-1))+(w-2)) = z; //gora
		    *(*(tab+(c-1))+(w)) = z; //dol
		}else if(c == 9 && w != 1){
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c-2))+(w-1)) = z; //lewo
		    *(*(tab+(c-1))+(w)) = z; //dol
		    *(*(tab+(c-1))+(w-2)) = z; //gora
		}else if(c != 9 && w == 9){
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c))+(w-1)) = z; //prawo
		    *(*(tab+(c-2))+(w-1)) = z; //lewo
		    *(*(tab+(c-1))+(w-2)) = z; //gora
		}else if(c != 1 && w == 1){
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c))+(w-1)) = z; //prawo
		    *(*(tab+(c-2))+(w-1)) = z; //lewo
		    *(*(tab+(c-1))+(w)) = z; //dol
		}else{
		    *(*(tab+(c-1))+(w-1)) = z;
		    *(*(tab+(c))+(w-1)) = z; //prawo
		    *(*(tab+(c-2))+(w-1)) = z; //lewo
		    *(*(tab+(c-1))+(w)) = z; //dol
		    *(*(tab+(c-1))+(w-2)) = z; //gora
		}

}

void game(char (*tab)[9], int moves, char z){
	for(int count = 0; count < moves; count++){
		int c; //numer kolumny
		int w; //nume wiersza
		printf("pozostala liczba ruchow: %d\n", moves-count);
		printf("podaj kolumne: ");
		scanf("%d", &c);
		if(c > 9 || c < 0){
			printf("error\n");
			break;
		}
		printf("podaj wiersz: ");
		scanf("%d", &w);
		if(w > 9 || w < 0){
			printf("error\n");
			break;
		}
		printf("\n");
		insert_char(tab,c,w,z);
		//wyswietlenie tablicy po zmianach
		print_tab(tab);
	}
}

void sum(char (*tab)[9], char z){
	int pom = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(*(*(tab+j)+i) != z){
			    pom++;
			}
		}
	}
	if(pom == 0){
		printf("WYGRANA\n");
	}else{
		printf("PRZEGRANA\n");
	}
}
