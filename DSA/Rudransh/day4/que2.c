#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* rearrange(char str[]) {
    int freq[26] = {0};

    
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            char lower = tolower(str[i]);
            freq[lower - 'a']++;
        }
    }

   
    int freq_count[101] = {0};
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freq_count[freq[i]]++;
        }
    }

    int unique_freqs = 0;
    int min_freq = 0, min_freq_count = 0;
    int max_freq = 0, max_freq_count = 0;

    
    for (int i = 1; i < 101; i++) {
        if (freq_count[i] > 0) {
            unique_freqs++;
            if (min_freq == 0 || i < min_freq) {
                min_freq = i;
                min_freq_count = freq_count[i];
            }
            if (i > max_freq) {
                max_freq = i;
                max_freq_count = freq_count[i];
            }
        }
    }

    if (unique_freqs == 1) {
        
        return "Valid";
    } 
    else if (unique_freqs == 2) {
       
        if ((min_freq == 1 && min_freq_count == 1) ||
            (max_freq - min_freq == 1 && max_freq_count == 1)) {
            return "Valid";
        }
    }

    return "Invalid";
}

int main() {
    char str[100];
    
    printf("Enter the sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    const char* ans = rearrange(str);
    printf("%s\n", ans);

    return 0;
}
