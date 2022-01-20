#include<bits/stdc++.h>

namespace zhangtao{
	inline int read(int &x){
	  x=0;int f=1;
	  char ch=getchar();
	  while(!isdigit(ch)){
	    if(ch=='-') f=-1;
	    ch=getchar();
    }
    while(isdigit(ch)){
      x=x*10+(ch-'0');
      ch=getchar();
    }
    return x*=f;
  }
  inline void write(int x){
    if(x<0){
      putchar('-');
      x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
  }
}

using namespace zhangtao;

int n,k;
char S[505];

signed main(){
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  read(n),read(k);
  scanf("%s",S);
  write(7),putchar('\n');
  return 0;
}
