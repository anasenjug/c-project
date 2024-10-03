#include <stdio.h>
#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
typedef struct datum {

	int dan, mjesec, godina;

}DATUM;

typedef struct korisnik {

	int id;
	char ime[20];
	char prezime[20];
	DATUM datumRodjenja;

}KORISNIK;

typedef struct zapis {

	int kalorije, voda, ugljikohidrati, proteini, san, tezina, visina;
	DATUM datumPracenja;

}ZAPIS;

int izbornik(const char* const);
void bmiKalkulator();
void kreiranjeDatoteke(const char* const);
void dodajKorisnika(const char* const);
void* ucitajKorisnika(const char* const);
void noviZapis(const char* const);
int izlaz(KORISNIK*);

#endif