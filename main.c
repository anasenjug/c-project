#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"


int main(void) {

	int uvijet = 1;
	char imeDatoteke[20] = { '\0' };
	printf("Unesite ime datoteke s kojom zelite raditi\n");
	scanf("%19[^\n]", imeDatoteke);

	
	while (uvijet) {
		uvijet = izbornik(imeDatoteke);
	}

	return 0;
}