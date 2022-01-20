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

const int maxn=45;
using namespace zhangtao;

int T,n,a[maxn];
char ans[maxn];
bool flag;

inline bool check(){
  int b[maxn],it0=0,it1=0,it2=n*2+1;
  for(int i=1;i<=n*2;++i) 
    if(ans[i]=='L'){
      ++it0,++it1;
      b[it0]=a[it1];
    }else{
      ++it0,--it2;
      b[it0]=a[it2];
    }
  for(int i=1;i<=n;++i)
    if(b[i]!=b[n*2-i+1]) return false;
  return true;
}

void dfs(const int x){
  if(flag==1) return;
  if(x==n*2+1){
    if(check()){
      for(int i=1;i<=n*2;++i)
        putchar(ans[i]);
      putchar('\n');
      flag=1;
    }else return;
  }
  ans[x]='L';
  dfs(x+1);
  ans[x]='R';
  dfs(x+1);
}

signed main(){
  freopen("palin.in","r",stdin);
  freopen("palin.out","w",stdout);
  read(T);
  while(T--){
    memset(ans,'\0',sizeof ans);
    memset(a,0,sizeof a);
    flag=0;
    read(n);
    for(int i=1;i<=n*2;++i)
      read(a[i]);
    dfs(1);
    if(!flag) puts("-1");
  }
  return 0;
} 
