#include<ctype.h>  //Only needed for tolower
#include<stdio.h>

char pangram(char sentence[]) {
  int alphabet[26] = {0};   //Array to check alphabet occurrence counts (a-z)
  int i = 0;

  while (sentence[i] != '\0') {
    char c = tolower((unsigned char)sentence[i]);   //Convert to lowercase
    if (isalpha(c)) {  
      alphabet[c - 'a']++;     //Increment count for that letter
    }
    i++;
  }

  //Check if all alphabets have a count of at least 1 (pangram)
  for (i = 0; i < 26; i++) {
    if (alphabet[i] == 0) {
      return 'i'; // Incomplete (missing letter)
    }
  }

  return 'c'; // Complete (all letters present)
}

int main() {
  char sentence[100]; 

  printf("Enter a sentence: ");
  scanf("%s",sentence);  

  char result = pangram(sentence);

  if (result == 'c') {
    printf("The sentence is a complete pangram.\n");
  } else {
    printf("The sentence is incomplete (missing letters).\n");
  }

  return 0;
}

