#include <stdio.h>

int main() {
    char str[100];
    int count[26] = {0}; //assuming only lowercase letters
    int max_freq, min_freq, freq_count = 0;

    printf("Enter a string: ");
    scanf("%99s", str);

    for (int i = 0; str[i]; i++) {
        count[str[i] - 'a']++; //count frequency of each letter
    }

    max_freq = min_freq = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            if (count[i] > max_freq) 
                max_freq = count[i];
            if (count[i] < min_freq || min_freq == 0) 
                min_freq = count[i];
            freq_count++;
        }
    }

    if (freq_count == 1 || max_freq - min_freq <= 1) {
        printf("valid\n");
    } else {
        printf("invalid\n");
    }

    return 0;
}
