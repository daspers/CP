/*	File : point_driver.c
	Deskripsi : Driver ADT POINT
*/

#include "point.h"
#include "boolean.h"
#include <stdio.h>

int main(){
	//Kamus
	POINT P1, P2;
	float sudut, X, Y;
	//Algoritma
	printf("Masukkan Titik 1 (Dalam format 'x y')\n");
	BacaPOINT(&P1);
	printf("Titik ");
	TulisPOINT(P1);
	printf("Berada di ");
	if(IsOrigin(P1))
		printf("titik origin");
	else if(IsOnSbX(P1))
		printf("sumbu X");
	else if(IsOnSbY(P1))
		printf("sumbu Y");
	else
		printf("kuadran %d", Kuadran(P1));
	printf("\n");
	printf("Jarak titik ke titik origin adalah %.2f\n",Jarak0(P1));
	printf("Hasil pencerminan dengan sumbu X : ");
	TulisPOINT(MirrorOf(P1,true));
	printf("Hasil pencerminan dengan sumbu Y : ");
	TulisPOINT(MirrorOf(P1,false));
	printf("Nilai titik setelah absis ditambah 1 : ");
	TulisPOINT(NextX(P1));
	printf("Nilai titik setelah ordinat ditambah 1 : ");
	TulisPOINT(NextY(P1));
	printf("Masukkan Titik 2 (Dalam format 'x y')\n");
	BacaPOINT(&P2);
	if(EQ(P1,P2))
		printf("Titik 1 dan Titik 2 sama\n");
	else if(NEQ(P1,P2))
		printf("Titik 1 dan Titik 2 tidak sama\n");
	printf("Jarak antar 2 titik adalah %.2f\n", Panjang(P1,P2));
	printf("Putar titik 2 sebesar (derajat) : ");
	scanf("%f",&sudut);
	printf("Hasil perputran titik 2 : ");
	Putar(&P2,sudut);
	TulisPOINT(P2);
	printf("Geser titik 1 sebesar :\n");
	printf("Delta x : ");
	scanf("%f",&X);
	printf("Delta y : ");
	scanf("%f",&Y);
	Geser(&P1,X,Y);
	printf("Hasil penggeseran titik 1 : ");
	TulisPOINT(P1);
	return 0;
}
