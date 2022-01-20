#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 505
#define mod 1000000007
long long n,k;
char a[N];
long long dp_ans[N][N],dp_cankh[N][N],dp_nc[N][N];
bool cans[N][N];
bool canbs(long long x,long long y)
{
  if(y-x+1>k)
    return 0;
  for(long long i=x;i<=y;i++)
    if(a[i]=='('||a[i]==')')
      return 0;
  return 1;
}
int main()
{
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  scanf("%lld%lld",&n,&k);
  scanf("%s",a+1);
  for(long long i=1;i<=n;i++)
    for(long long j=i;j<=n;j++)
      cans[i][j]=canbs(i,j);
  for(long long i=1;i<n;i++)
    if((a[i]=='('&&a[i+1]==')')||(a[i]=='?'&&a[i+1]=='?')||
    (a[i]=='('&&a[i+1]=='?')||(a[i]=='?'&&(a[i+1]==')')))
      dp_ans[i][i+1]=1,dp_nc[i][i+1]=1;
  for(long long l=2;l<=n;l++)
    for(long long i=1,j=l;j<=n;i++,j++)
    {
      //dp_cankh
      for(long long k=i;k<=j-1;k++)
        if(cans[i][k])
          (dp_cankh[i][j]+=dp_ans[k+1][j])%=mod;
      //dp_ans dp_nc
      if((a[i]=='('&&a[j]==')')||(a[i]=='?'&&a[j]=='?')||
      (a[i]=='('&&a[j]=='?')||(a[i]=='?'&&(a[j]==')')))
      {
        (dp_ans[i][j]+=dp_ans[i+1][j-1])%=mod;
        (dp_ans[i][j]+=cans[i+1][j-1])%=mod;
        (dp_nc[i][j]+=dp_ans[i+1][j-1])%=mod;
        (dp_nc[i][j]+=cans[i+1][j-1])%=mod;
        for(long long k=i+1;k<j-1;k++)
          if(cans[i+1][k])
            (dp_ans[i][j]+=dp_ans[k+1][j-1])%=mod,
            (dp_nc[i][j]+=dp_ans[k+1][j-1])%=mod;
        for(long long k=i+2;k<=j-1;k++)
          if(cans[k][j-1])
            (dp_ans[i][j]+=dp_ans[i+1][k-1])%=mod,
            (dp_nc[i][j]+=dp_ans[i+1][k-1])%=mod;
      }
      for(long long k=i+1;k<=j-1;k++)
        (dp_ans[i][j]+=(dp_nc[i][k]*dp_cankh[k+1][j])%mod)%=mod;
      (dp_cankh[i][j]+=dp_ans[i][j])%=mod;
    }
  printf("%lld\n",dp_ans[1][n]);
  return 0;
}
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/
