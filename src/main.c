#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int number;

    // Dosyayı açma
    fp = fopen("/home/ozgur/Desktop/c_odev/giris/giris.dat", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Dosyadan veri okuma işlemi
    while (fscanf(fp, "%d", &number) == 1) {
        // Okunan sayıyı ekrana yazdırma
        printf("%d\n", number);
    }

    fclose(fp);

    return 0;
}
