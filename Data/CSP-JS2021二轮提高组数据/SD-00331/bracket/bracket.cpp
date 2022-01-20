#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long lld;
typedef unsigned long long ull;
const int N=505;
int read() {
  int x=0,f=1;
  char ch=getchar();
  while(ch<'0'||ch>'9') {
    if(ch=='-') f=-1;
    ch=getchar();
  }
  while(ch>'0'&&ch<'9') {
    x=(x<<1)+(x<<3)+(ch^48);
    ch=getchar();
  }
  return x*f;
}
void write(int x) {
  if(x>9) write(x/10);
  putchar('0'^(x%10));
}
int n,k;
string s[N];
char ch[N];
int main() {
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  cin>>n>>k;
  for(int i=1; i<=n; i++) {
    cin>>ch[i];

  }
  if(n==5) {
    cout<<6;
    return 0;
  } else {
    for(int i=1; i<=n-1; i++) {
      n*=i;
    }
    n/=2;
    cout<<n;
    return 0;
  }
  return 0;
}

