#include <stdio.h>
int printing(int lb_scores[],int py_scores[],int rank[],int n,int m);
int main()
{
  int i, n, m;
  printf("enter number of leader board scores:");
  scanf("%d", &n);
  int lb_scores[n];
  for (i = 0; i < n; i++) // entering leader board scores
  {
    printf("enter %d score:", i + 1);
    scanf("%d", &lb_scores[i]);
  }
  for (i=0; i<n; i++) //coverting data in descending order
  {
    for (int j=i+1;j<n;j++)
    {
      if (lb_scores[i] < lb_scores[j])
      {
        int t;
        t=lb_scores[i];
        lb_scores[i]=lb_scores[j];
        lb_scores[j]=t;
      }
    }
  }
 printf("enter number of rounds played by a player:");
 scanf("%d",&m);
 int py_scores[m],rank[m];
 for(i=0;i<m;i++) //entering player's score
 {
  printf("enter score in round %d:",i+1);
  scanf("%d",&py_scores[i]);
 }
 for(i=0;i<m;i++) //ranking
 {
  rank[i]=1;
  for(int j=0;j<n;j++)
  {
    if(py_scores[i]<lb_scores[j])
    {
      rank[i]++;
    }
  }
 }
printing(lb_scores,py_scores,rank,n,m);
return 0;
}
int printing(int lb_scores[],int py_scores[],int rank[],int n,int m)
{
  int i;
  printf("Leaderboard Scores in descending order:[");
  for (i = 0; i < n; i++)
  {
    printf("%d", lb_scores[i]);
    if(i<m-1)
    printf(",");
  }
  printf("]\n");
  printf("Player Scores:[");
  for (i = 0; i < m; i++)
  {
    printf("%d",py_scores[i]);
    if(i<m-1)
    printf(",");
  }
  printf("]\n");
  printf("Rankings:[");
  for (i = 0; i < m; i++)
  {
    printf("%d", rank[i]);
    if(i<m-1)
    printf(",");
  }
  printf("]\n");
  return 0;
}

