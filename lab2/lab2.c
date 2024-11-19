//Natalia Slepowronska
//12.11.2024
//PROS lab2

#include "lib_ns.h"

int main(void){
	char tab[9][9]; //deklaracja tablicy
	char z1;
	char z2;
	printf("podaj znak tablicy: ");
	scanf("%c",&z1);
	printf("podaj znak gry: ");
	while (getchar() != '\n');
	scanf("%c",&z2);
	gen_tab(tab,z1); //wygenerowanie tablicy
	printf("\n");
	printf("-------------PREZENTACJA-------------\n");
	printf("\n");
	print_tab(tab); //prezentacja tablicy przed gra
	printf("----------------START----------------\n");
	game(tab,18,z2);//faktyczny start gry
	sum(tab,z2);
	return 0;
 }
