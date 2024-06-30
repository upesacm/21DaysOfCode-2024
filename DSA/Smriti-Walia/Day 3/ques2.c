#include<stdio.h>
#include<ctype.h>
#include<string.h>

int is_ascii_symmetric(char s[]) {
  int len = strlen(s);

  for (int i = 0; i < len / 2; i++) {
    if (tolower(s[i]) != tolower(s[len - i - 1])) {
      return 0; //Not symmetrical
    }
  }

  return 1; //Symmetrical
}

int main() {
  char s[100];
  
  printf("Enter a string: ");
  scanf("%s",s);

  if (is_ascii_symmetric(s)) {
    printf("%s is symmetrical\n", s);
  } else {
    printf("%s is non symmetrical\n", s);
  }

  return 0;
}
