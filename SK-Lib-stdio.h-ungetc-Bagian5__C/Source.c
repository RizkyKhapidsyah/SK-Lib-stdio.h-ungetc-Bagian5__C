#pragma warning(disable:4996)

#include <ctype.h>
#include <stdio.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

void demo_scanf(const char* fmt, FILE* s) {
    while (*fmt != '\0') {
        if (*fmt == '%') {
            int c;
            switch (*++fmt) {
            case 'u':
                while (isspace(c = getc(s))) {}
                unsigned int num = 0;
                while (isdigit(c)) {
                    num = num * 10 + c - '0';
                    c = getc(s);
                }
                printf("%%u scanned %u\n", num);
                ungetc(c, s);
                break;
            case 'c':
                c = getc(s);
                printf("%%c scanned '%c'\n", c);
                break;
            }
        } else {
            ++fmt;
        }
    }
}

int main(void) {
    FILE* f = fopen("input.txt", "w+");
    if (f != NULL) {
        fputs("123x", f);
        rewind(f);
        demo_scanf("%u%c", f);
        fclose(f);
    }

    _getch();
    return 0;
}