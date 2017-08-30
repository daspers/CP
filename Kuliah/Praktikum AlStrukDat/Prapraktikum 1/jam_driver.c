/*	File : jam_driver.c
	Deskripsi : Driver ADT JAM
*/

#include "jam.h"
#include <stdio.h>

int main(){
	//kamus
	JAM J1, J2;
	int n;
	//algoritma
	printf("Masukkan jam pertama secara berturut-turut JJ, MM, dan SS\n");
	BacaJAM(&J1);
	printf("Jam yang anda masukkan\n");
	TulisJAM(J1);
	printf("satu detik yang lalu : ");
	TulisJAM(PrevDetik(J1));
	printf("satu detik yang akan datang : ");
	TulisJAM(NextDetik(J1));
	printf("Masukkan nilai N : ");
	scanf("%d", &n);
	printf("%d detik yang akan datang : ",n);
	TulisJAM(NextNDetik(J1,n));
	printf("%d detik yang lalu : ",n);
	TulisJAM(PrevNDetik(J1,n));
	printf("Masukkan jam kedua secara berturut-turut JJ, MM, dan SS\n");
	BacaJAM(&J2);
	if(JNEQ(J1,J2))
		printf("Kedua Waktu tidak sama\n");
	else 
		printf("Kedua Waktu sama\n");
	if(JLT(J1,J2))
		printf("Waktu 1 lebih kecil dibanding waktu 2\n");
	else if(JGT(J1,J2))
		printf("Waktu 1 lebih besar dibanding waktu 2\n");
	printf("selisih waktu : %lds atau ", Durasi(J1,J2));
	TulisJAM(DetikToJAM(Durasi(J1,J2)));
	return 0;
}
