#include <stdio.h>
#include <stdlib.h> // exit fonksiyonu için gerekli
#include <string.h> // strcmp fonksiyonu için gerekli
#include "fields.h"

void yaz(char *str) {
    FILE *dosya;
    dosya = fopen("cikis/cikis.dat", "a"); // "a" modunda dosyayı aç, varsa sonuna ekle
    if (dosya == NULL) {
        perror("cikis/cikis.dat");
        exit(1);
    }

    char *ptr = str;
    char karakter;
    int adet;
    while (*ptr) {
        if (*ptr >= '0' && *ptr <= '9') { // Sayı varsa kaç kere yazılacağını al
            adet = *ptr - '0';
            karakter = *(ptr + 2);
            for (int i = 0; i < adet; i++) {
                fprintf(dosya, "%c", karakter); // Karakteri kaç kere yazacağız
            }
            ptr += 3; // Sayı, boşluk ve karakteri geç
        } else {
            ptr++;
        }
    }

    fclose(dosya); // Dosyayı kapat
}

int main(int argc, char **argv) {
    IS is;
    int i;

    if (argc != 2) {
        fprintf(stderr, "usage: printwords filename");
        exit(1);
    }

    is = new_inputstruct(argv[1]);
    if (is == NULL) {
        perror(argv[1]);
        exit(1);
    }

    while (get_line(is) >= 0) {
        if (strncmp(is->text1, "yaz:", 4) == 0) {
            printf("yaz: görevi ekstra başladı %s", is->text1);
            yaz(is->text1 + 4); // "yaz:" kısmını atlayarak dosyaya yazdır
        }
    }

    jettison_inputstruct(is);
    exit(0);
}
