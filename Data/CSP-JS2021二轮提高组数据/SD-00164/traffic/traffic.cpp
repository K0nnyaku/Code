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

signed main(){
  freopen("traffic.in","r",stdin);
  freopen("traffic.out","w",stdout);
  puts("Fuck you CCF!");
  return 0;
}//I'll be back in NOIp2021, CCF give me wait...
