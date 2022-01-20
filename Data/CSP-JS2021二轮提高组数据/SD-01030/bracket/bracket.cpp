#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;

int read()
{
  int x=0,f=1;
  char ch=getchar();
  while(ch<'0'||ch>'9')
  {
    if(ch=='-') f=-1;
    ch=getchar();
  }
  while(ch>='0'&&ch<='9')
  {
    x=(x<<1)+(x<<3)+(ch^48);
    ch=getchar();
  }
  return f*x;
}
int main()
{
  return 0;
}

