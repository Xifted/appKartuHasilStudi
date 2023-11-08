// 1. Dariel Muhammad(2023071048)
// 2. Muhammad Rafi Irfan(2023071053)
// 3. Ferdinan Indra Ferta(2023071059)
// 4. Raihan Ilham Ramadhan(2023071075)

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define strcasecmp _stricmp

COORD coord = { 0, 0 };
int nmr;
char kodeMK[10];
char namaMK[30];
int sks;
char grade[3];
float mutu;
float SxM;
int totalSKS = 0;
float totalSxM = 0;
float IPS = 0;

void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void inputKodeMK() {
    scanf_s("%s", &kodeMK, 10);
}

void inputNamaMK() {
    scanf_s("%s", &namaMK, 30);
}

void inputSKS() {
    scanf_s("%d", &sks);
}

void inputGrade() {
    scanf_s("%s", &grade, 3);
}

void inputMatkul() {
    for (nmr = 1; nmr <= 7; nmr++) {
        gotoxy(0, 3 + nmr); printf("%d.", nmr);

        // Input data
        gotoxy(6, 3 + nmr); inputKodeMK();
        gotoxy(16, 3 + nmr); inputNamaMK();
        gotoxy(27, 3 + nmr); inputSKS();
        gotoxy(33, 3 + nmr); inputGrade();

        // Perhitungan Mutu
        if (strcasecmp(grade, "A") == 0) {
            mutu = 4.0;
        }
        else if (strcasecmp(grade, "A-") == 0) {
            mutu = 3.7;
        }
        else if (strcasecmp(grade, "B+") == 0) {
            mutu = 3.3;
        }
        else if (strcasecmp(grade, "B") == 0) {
            mutu = 3.0;
        }
        else if (strcasecmp(grade, "B-") == 0) {
            mutu = 2.7;
        }
        else if (strcasecmp(grade, "C+") == 0) {
            mutu = 2.3;
        }
        else if (strcasecmp(grade, "C") == 0) {
            mutu = 2.0;
        }
        else if (strcasecmp(grade, "C-") == 0) {
            mutu = 1.7;
        }
        else if (strcasecmp(grade, "D") == 0) {
            mutu = 1.0;
        }
        else if (strcasecmp(grade, "E") == 0) {
            mutu = 0;
        }
        else {
            printf("INVALID");
            mutu = 0;
        }

        // Perhitungan SxM
        SxM = mutu * sks;

        // Hasil Mutu dan SxM 
        gotoxy(40, 3 + nmr); printf("%.2f", mutu);
        gotoxy(48, 3 + nmr); printf("%.2f", SxM);

        // Total SKS, total SxM
        totalSKS += sks;
        totalSxM += SxM;
    }
}

int main() {
    printf("Kartu Hasil Studi");
    printf("\n------------------------------------------------------");
    printf("\nNo.   Kode MK   Nama MK   SKS   Grade   Mutu    SxM");
    printf("\n------------------------------------------------------");

    inputMatkul();

    printf("\n------------------------------------------------------");
    printf("\nTotal");
    gotoxy(27, 12); printf("%d", totalSKS);
    gotoxy(48, 12); printf("%.2f", totalSxM);
    printf("\n------------------------------------------------------\n");
    // Perhitungan IPS
    if (totalSKS != 0) {
        IPS = totalSxM / totalSKS;
    }

    gotoxy(44, 14); printf("IPS: %.2f", IPS);
    printf("\n------------------------------------------------------");

    return 0;
}