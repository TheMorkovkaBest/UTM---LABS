#include <stdio.h>

int main() {
    char *vvod ="After a long and anxious autumn, Alice adopted a adorable alpaca.";
    int lenght = 0;
    char zaddaniismall_simbol= 'a';
    char zaddaniibig_simbol=zaddaniismall_simbol-('a'-'A');

    for (int i = 0; vvod[i] != '\0'; i++) {
        if (vvod[i] == '\n') break;
        if (i == 0 || vvod[i - 1] == ' ' || vvod[i - 1] == '.' || vvod[i - 1] == ',') {
            if (vvod[i] == zaddaniismall_simbol || vvod[i] == zaddaniibig_simbol) lenght++;
        }
    }

    printf("%s\n%i", vvod, lenght);
}





















