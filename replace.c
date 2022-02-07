#include <stdio.h>
#include <stdlib.h>

int valid(int c) {
    if ('A' <= c && c <= 'Z') return 1;
    if ('a' <= c && c <= 'z') return 1;
    // if (c == '_') return 1;
    return 0;
}

int main() {
    FILE *f1, *f2;
    f1 = fopen("story.txt", "r");
    f2 = fopen("story2.txt", "w");
    int c;
    char s1[] = "xfP7Xng_paSF@}izoJIMhQbVYyH8KL4m!G01RwA6uNBed{qWrlsC3U5TtDEkv9";
    char s2[] = "qHyUMf6QXlOR18SbjsIk7PWYoC3chpgx94wirt0uenNKm5AdDTvEFZ2BJzGLVa";

    while ((c = fgetc(f1)) != EOF) {
        for (int i = 0; i < 62; i++) {
            if (s1[i] == c) {
                c = s2[i];
                break;
            }
        }
        if (valid(c)) fprintf(f2, "%c", c);
    }
    return 0;
}
