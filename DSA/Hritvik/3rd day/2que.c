#include<stdio.h>
#include<string.h>
#include<ctype.h>
char* is_symmetrical(char* string)
{
    int length=strlen(string);
    int ASCII[length];
    for(int i=0;string[i]!='\0';i++)
    {
        ASCII[i]=(int)string[i];
    }

    for(int i=0;i<length/2;i++)
    {
        if(ASCII[i]!=ASCII[length - i - 1])
        {
            return "not symmetrical";
        }
    }
    return "symmetrical";

}
void main()
{
    char string[]="acxz";
    printf("%s\n",is_symmetrical(string));
}
