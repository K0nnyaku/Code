#include<iostream>
#include<cstdio>
long long n,a[50],t,scl[50];
int main()
{
  freopen("palin.in","r",stdin);
  freopen("palin.out","w",stdout);
  scanf("%lld",&t);
  while(t--)
  {
    scanf("%lld",&n);
    for(long long i=1;i<=n*2;i++)
      scanf("%lld",&a[i]);
    bool can=0;
    for(long long i=0;i<(1<<((n*2)));i++)
    {
      long long l=1,r=(n<<1);
      for(long long j=(n*2-1);j>=0;j--)
      {
        if(!((i>>j)&1))
          scl[j+1]=a[l++];
        else
          scl[j+1]=a[r--];
      }  
      bool hw=1;
      for(long long j=1;j<=n;j++)
        if(scl[j]!=scl[2*n-j+1])
        {
          hw=0;
          break;
        }
      if(hw)
      {
        can=1;
        for(long long j=((n<<1)-1);j>=0;j--)
        {
          if(!((i>>j)&1))
            printf("L");
          else
            printf("R");
        } 
        printf("\n");
        break;
      }
    }  
    if(!can)
      printf("-1\n");
  } 
  return 0;
}
