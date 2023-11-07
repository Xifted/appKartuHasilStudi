#include <stdio.h>
#include <conio.h>
#include <windows.h>

COORD coord = { 0, 0 };
int nmr;
char kodeMK[7][10];
char namaMK[7][30];
int sks[7];
char grade[7][3];
float mutu[7];
float SxM[7];
float totalSKS = 0;
float totalSxM = 0;
float IPS = 0;

void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    printf("Kartu Hasil Studi");
    printf("\n------------------------------------------------------");
    printf("\nNo.   Kode MK   Nama MK   SKS   Grade   Mutu    SxM");
    printf("\n------------------------------------------------------");

    for (nmr = 1; nmr <= 7; nmr++) {
        gotoxy(0, 3 + nmr); printf("%d.", nmr);

        // Input data
        gotoxy(7, 3 + nmr); scanf_s("%s", kodeMK[nmr], 10);
        gotoxy(16, 3 + nmr); scanf_s("%s", namaMK[nmr], 30);
        gotoxy(27, 3 + nmr); scanf_s("%d", &sks[nmr]);
        gotoxy(33, 3 + nmr); scanf_s("%s", &grade[nmr], 3);

        // Perhitungan Mutu
        if (grade[nmr][0] == 'A') {
            mutu[nmr] = 4.0;

            if (grade[nmr][1] == '-') {
                mutu[nmr] = 3.7;
            }
        }
        else if (grade[nmr][0] == 'B') {
            mutu[nmr] = 3.0;

            if (grade[nmr][1] == '+') {
                mutu[nmr] = 3.3;
            }
            else if (grade[nmr][1] == '-') {
                mutu[nmr] = 2.7;
            }
        }
        else if (grade[nmr][0] == 'C') {
            mutu[nmr] = 2.0;

            if (grade[nmr][1] == '+') {
                mutu[nmr] = 2.3;
            }
            else if (grade[nmr][1] == '-') {
                mutu[nmr] = 1.7;
            }
        }
        else if (grade[nmr][0] == 'D') {
            mutu[nmr] = 1.0;
        }
        else if (grade[nmr][0] == 'E') {
            mutu[nmr] = 0;
        }
        else {
            printf("INVALID");
        }

        // Perhitungan SxM, total SKS, total SxM
        SxM[nmr] = mutu[nmr] * sks[nmr];
        totalSKS += sks[nmr];
        totalSxM += SxM[nmr];

        // Hasil Mutu dan SxM 
        gotoxy(40, 3 + nmr); printf("%.2f", mutu[nmr]);
        gotoxy(48, 3 + nmr); printf("%.2f", SxM[nmr]);
    }

    printf("\n------------------------------------------------------");
    printf("\nTotal");
    gotoxy(27, 12); printf("%.2f", totalSKS);
    gotoxy(48, 12); printf("%.2f", totalSxM);

    // Perhitungan IPS
    if (totalSKS != 0) {
        IPS = totalSxM / totalSKS;
    }

    gotoxy(45, 13); printf("IPS: %.2f", IPS);
    printf("\n------------------------------------------------------");

    return 0;
}