#include <stdio.h>
int check(int st1[], int st2[], int st3[], int n1, int n2, int n3)
{
    int sumSt1 = 0, sumSt2 = 0, sumSt3 = 0;

    for (int i = 0; i < n1; i++)
     {
   sumSt1 += st1[i];
     }  
    for (int i = 0; i < n2; i++){
        sumSt2 += st2[i];
        }
    for (int i = 0; i < n3; i++){
        sumSt3 += st3[i];
  }
    int i = 0, j = 0, k = 0;

    while (1)
    {
        if(i == n1 || j == n2 || k == n3)
            return 0;
        if (sumSt1 == sumSt2 && sumSt2 == sumSt3)
            return sumSt1;
        if(sumSt1 > sumSt2 && sumSt1 > sumSt3)
        {
            sumSt1 -= st1[i];
            i++ ;
        }
        else if(sumSt2 > sumSt1 && sumSt2 > sumSt3)
        {
            sumSt2 -= st2[j];
            j++;
        }
        else
        { sumSt3 -= st3[k];
            k++ ;
        }
    }
    return sumSt1;
}

int main()
{
    int st1[] = {3, 2, 1, 1, 1};
    int st2[] = {4, 3, 2};
    int st3[] = {1, 1, 4, 1};
    int n1 = sizeof(st1) / sizeof(st1[0]);
    int n2 = sizeof(st2) / sizeof(st2[0]);
    int n3 = sizeof(st3) / sizeof(st3[0]);

    int ans = check(st1, st2, st3, n1, n2, n3);
    printf("The maximum possible height of stacks is: %d\n", ans);
    return 0;
}
