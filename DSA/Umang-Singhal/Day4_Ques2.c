#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int freq[26] = {0};
    int len, i, j, unique_freq[26] = {0}, unique_count = 0;
    printf("Enter the string: ");
    scanf("%s", str);   
    len = strlen(str);
    for (i = 0; i < len; i++) {
        freq[str[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            int found = 0;
            for (j = 0; j < unique_count; j++) {
                if (unique_freq[j] == freq[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                unique_freq[unique_count] = freq[i];
                unique_count++;
            }
        }
    }
    if (unique_count == 1) {
        printf("valid\n");
    } else if (unique_count == 2) {
        int count1 = 0, count2 = 0;
        for (i = 0; i < 26; i++) {
            if (freq[i] == unique_freq[0]) count1++;
            else if (freq[i] == unique_freq[1]) count2++;
        }
        if ((count1 == 1 && (unique_freq[0] == 1 || unique_freq[0] - 1 == unique_freq[1])) || 
            (count2 == 1 && (unique_freq[1] == 1 || unique_freq[1] - 1 == unique_freq[0]))) {
            printf("valid\n");
        } else {
            printf("invalid\n");
        }
    } else {
        printf("invalid\n");
    }
    return 0;
}
