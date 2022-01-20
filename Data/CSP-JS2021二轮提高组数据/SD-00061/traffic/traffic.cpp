#include<iostream>
#include<cstdio>
using namespace std;
int n,m,t;
int main()
{
  freopen("traffic.in","r",stdin);
  freopen("traffic.out","w",stdout);
  scanf("%d%d%d",&n,&m,&t);
  while(t--)
  {
    printf("%d\n",n*m*2);
  }
  return 0;
}
