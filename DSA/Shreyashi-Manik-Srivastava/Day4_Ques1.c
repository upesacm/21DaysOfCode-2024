#include <stdio.h>
#include <string.h>

int main() {
    char ch[100], str[100], str1[100], substrings[100][100];
    int len, i, j, k, count = 0;

    printf("Enter string ch: ");
    scanf("%s", ch);

    printf("Enter substring length: ");
    scanf("%d", &len);

    for (i = 0; i < strlen(ch); i++) {
        for (j = i; j < strlen(ch); j++) {
            int str_idx = 0;
            for (k = i; k <= j; k++) {
                str[str_idx++] = ch[k];
            }
            str[str_idx] = '\0';

            int str1_idx = 0;
            for (k = strlen(str) - 1; k >= 0; k--) {
                str1[str1_idx++] = str[k];
            }
            str1[str1_idx] = '\0';

            int is_duplicate = 0;
            for (k = 0; k < count; k++) {
                if (strcmp(str, substrings[k]) == 0) {
                    is_duplicate = 1;
                    break;
                }
            }

            if (!is_duplicate && strcmp(str, str1) == 0 && strlen(str) == len) {
                strcpy(substrings[count], str);
                printf("%s %s\n", str, str1);
                count++;
            }
        }
    }

    printf("count= %d\n", count);
    return 0;
}