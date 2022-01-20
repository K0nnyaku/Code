#include<bits/stdc++.h>
#define LL long long
#define il inline
#define us unsigned
#define INF 0x3f3f3f3f
#define pub push_back
#define pii pair<int,int>
#define mkp make_pair
#define x first
#define y second
#define ls (k<<1)
#define rs (k<<1|1)
#define nmid ((l+r)>>1)
#define tmid ((tr[k].l+tr[k].r)>>1)
#define KafuuChino return
#define HotoKokoa 0;
using namespace std;
il void Read(int &x){
  int f=1;x=0;char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=x*10+c-'0',c=getchar();
  }
  x*=f;
}
const int N=1000010;
int T,n,a[N],ans[N];
bool DFS(int now){
  if(now>n+n){
    int lt=1,rt=n+n;vector<int> qwq;
    for(int i=1;i<=n+n;i++){
      if(ans[i]==0)qwq.pub(a[lt++]);
      else qwq.pub(a[rt--]);
      if(lt>rt&&i<n+n)return 0;
      if(qwq.size()<=n)continue;
      if(qwq[qwq.size()-1]!=qwq[n+n-qwq.size()])return 0;
    }
    return 1;
  }
  ans[now]=0;
  if(DFS(now+1))return 1;
  ans[now]=1;
  if(DFS(now+1))return 1;
  ans[now]=-1;
  return 0;
}
int main(){
  freopen("palin.in","r",stdin);
  freopen("palin.out","w",stdout);
  Read(T);
  while(T--){
    Read(n),memset(ans,-1,sizeof ans);
    for(int i=1;i<=n+n;i++)Read(a[i]);
    if(!DFS(1))puts("-1");
    else {
      for(int i=1;i<=n+n;i++)putchar(ans[i]?'R':'L');
      puts("");
    }
  }
  KafuuChino HotoKokoa
}
