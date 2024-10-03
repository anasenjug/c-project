#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int brojZapisa = 0;
static int brojKorisnika = 0;


void kreiranjeDatoteke(const char* const imeDatoteke) {
	FILE* fp = fopen(imeDatoteke, "wb");

	if (fp == NULL) {
		perror("Kreiranje datoteke");
		exit(EXIT_FAILURE);
	}
	fwrite(&brojKorisnika, sizeof(int), 1, fp);



	fclose(fp);
}

void dodajKorisnika(const char* const imeDatoteke) {
	FILE* fp = fopen(imeDatoteke, "rb+");

	if (fp == NULL) {
		perror("Dodavanje korisnika..");
		exit(EXIT_FAILURE);
	}

	fread(&brojKorisnika, sizeof(int), 1, fp);
	printf("Trenutan broj korisnika: %d\n", brojKorisnika);
	KORISNIK temp = { 0 };
	temp.id = brojKorisnika;
	getchar();
	printf("Unesite ime:\n");
	scanf("%19[^\n]",temp.ime);
	printf("Unesite prezime:\n");
	getchar();
	scanf("%19[^\n]", temp.prezime);
	printf("Datum rodjenja:\n");
	scanf("%d %d %d", &temp.datumRodjenja.dan, &temp.datumRodjenja.mjesec, &temp.datumRodjenja.godina);
	fseek(fp, sizeof(KORISNIK) * brojKorisnika, SEEK_CUR);
	fwrite(&temp, sizeof(KORISNIK), 1, fp);
	rewind(fp);
	brojKorisnika++;
	fwrite(&brojKorisnika, sizeof(int), 1, fp);
	fclose(fp);

}
void* ucitajKorisnika(const char* const imeDatoteke) {
	FILE* fp = fopen(imeDatoteke, "rb");
	if (fp == NULL) {
		perror("Ucitavanje...");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(&brojKorisnika, sizeof(int), 1, fp);
	printf("Broj korisnika: %d\n", brojKorisnika);
	KORISNIK* poljeKorisnika = (KORISNIK*)calloc(brojKorisnika, sizeof(KORISNIK));
	if (poljeKorisnika == NULL) {
		perror("Zauzimanje memorije..");
		return NULL;
			exit(EXIT_FAILURE);
	}
	fread(poljeKorisnika, sizeof(KORISNIK), brojKorisnika, fp);
	

	int i;
	for (i = 0; i < brojKorisnika; i++) {
		printf("Korisnik broj %d\tID:%d\t ime: %s\t prezime:%s \tdatum rodjenja: %d %d %d\n", i + 1,
			(poljeKorisnika + i)->id,
			(poljeKorisnika + i)->ime,
			(poljeKorisnika + i)->prezime,
			poljeKorisnika[i].datumRodjenja.dan,
			poljeKorisnika[i].datumRodjenja.mjesec,
			poljeKorisnika[i].datumRodjenja.godina);
			
	}
	return poljeKorisnika;
}



void noviZapis(const char* const imeDatoteke) {
	FILE* fp = fopen(imeDatoteke, "rb+");
	if (fp == NULL) {
		perror("Dodavanje zapisa..");
		exit(EXIT_FAILURE);
	}
	
	fread(&brojZapisa, sizeof(int), 1, fp);
}

void bmiKalkulator() {

	float bmi, tezina, visina;
	
	printf("Unesite svoju tezinu u kg\n");
	scanf("%f", &tezina);
	printf("Unesite svoju visinu u cm\n");
	scanf("%f", &visina);
	bmi = (tezina / pow(visina, 2))*10000;

	if (bmi > 24.9) {

		printf("Vas BMI je: %.2f \n", bmi);
		printf("Poviseni BMI\n");
	}
	else if (bmi < 24.9 && bmi>18.5) {
		printf("Vas BMI je: %.2f\n", bmi);
		printf("Idealan BMI\n");
	}
	else {
		printf("Vas BMI je: %.2f\n", bmi);
		printf("Nizak BMI\n");
	}

}


int izlaz(KORISNIK* poljeKorisnika) {
	free(poljeKorisnika);
	printf("Izlaz iz programa");	
	return 0;
}