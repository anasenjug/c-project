#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int izbornik(const char* const imeDatoteke) {
	printf("====================");
	printf("IZBORNIK");
	printf("====================\n");
	printf("\t\t\tOpcija 1: Kreiranje nove datoteke\n");
	printf("\t\t\tOpcija 2: Kreiranje novog korisnika\n");
	printf("\t\t\tOpcija 3: Kreiranje novog zapisa\n");
	printf("\t\t\tOpcija 4: Prikazi sve korisnike\n");
	printf("\t\t\tOpcija 5: BMI kalkulator\n");
	printf("\t\t\tOpcija 6: Izlaz iz programa\n");
	printf("======================================\
======================================\n");
	int uvijet = 0;
	ZAPIS* poljeZapisa = NULL;
	KORISNIK* poljeKorisnika = NULL;

	scanf("%d", &uvijet);

	switch (uvijet) {
	case 1:
		kreiranjeDatoteke(imeDatoteke);
		break;
	
	case 2: 
		dodajKorisnika(imeDatoteke);
		if (poljeKorisnika != NULL) {
			free(poljeKorisnika);
			poljeKorisnika = NULL;
		}
		poljeKorisnika = (KORISNIK*)ucitajKorisnika(imeDatoteke);
		if (poljeKorisnika == NULL) {
			exit(EXIT_FAILURE);
		}
		
		break;

	case 3:
		noviZapis(imeDatoteke);
		break;
	
	case 4:
		if (poljeKorisnika != NULL) {
			free(poljeKorisnika);
			poljeKorisnika = NULL;
		}
		poljeKorisnika = (KORISNIK*)ucitajKorisnika(imeDatoteke);
		if (poljeKorisnika == NULL) {
			exit(EXIT_FAILURE);
		}
		break;

	case 5:

		bmiKalkulator();
		break;

	case 6:
		uvijet = izlaz(poljeKorisnika);
		break;

	default:
		uvijet = 0;
	}
	
	return uvijet;
}