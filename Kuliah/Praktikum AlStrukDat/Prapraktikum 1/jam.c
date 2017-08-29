/*	File : jam.c 
	Deskripsi :
	Isi :
*/

#include <stdio.h>
#include "jam.h"
#include "boolean.h"

boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{	//Algoritma
	return (H>=0&&H<24)&&(M>=0&&M<60)&&(S>=0&&S<60);
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{	//Kamus
	JAM J;
	//Algoritma
	Hour(J)=HH;
	Minute(J)=MM;
	Second(J)=SS;
	return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{	//Kamus
	int HH,MM,SS;
	//Algoritma
	scanf("%d %d %d",&HH,&MM,&SS);
	while(IsJAMValid(HH,MM,SS)==false){
		printf("Jam tidak valid\n");
		scanf("%d %d %d",&HH,&MM,&SS);
	}
	Hour(*J)=HH;
	Minute(*J)=MM;
	Second(*J)=SS;
}

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{	//Algoritma
	if(Hour(J)<10)
		printf("0");
	printf("%d:",Hour(J));
	if(Minute(J)<10)
		printf("0");
	printf("%d:",Minute(J));
	if(Second(J)<10)
		printf("0");
	printf("%d\n",Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{	//Algoritma
	return Hour(J)*3600+Minute(J)*60+Second(J);
}

JAM DetikToJAM (long N) 
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{	//Algoritma
	JAM J;
	N%=86400;
	Hour(J)=N/3600;
	Minute(J)=(N%3600)/60;
	Second(J)=N%60;
	return J;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{	//Algoritma
	return (Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)==Second(J2));
}

boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{	//Algoritma
	return !(Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)==Second(J2));
}

boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{	//Algoritma
	return JAMToDetik(J1)<JAMToDetik(J2);
}

boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
{	//Algoritma
	return JAMToDetik(J1)>JAMToDetik(J2);
}

JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{	//Algoritma
	return DetikToJAM(JAMToDetik(J)+1);
}

JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{	//Algoritma
	return DetikToJAM(JAMToDetik(J)+N);
}

JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{	//Algoritma
	if(JAMToDetik(J)<1){
		return DetikToJAM(24*3600-1);
	}
	else
		return DetikToJAM(JAMToDetik(J)-1);
}

JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
{	//Algoritma
	if(JAMToDetik(J)<N){
		return DetikToJAM(24*3600-N+JAMToDetik(J));
	}
	else
		return DetikToJAM(JAMToDetik(J)-N);
}

long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{	//Kamus
	long J1 = JAMToDetik(JAw), J2 = JAMToDetik(JAkh);
	//Algoritma
	if(J1>J2)
		J2+=24*3600;
	return J2-J1;
}
