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
const int N=100010;
int n,m1,m2;
struct Node {
  int l,r;
  bool operator < (const Node &rhs)const{
    return l<rhs.l;
  }
}a[2][N];
struct Chain {
  int pre[N],nxt[N];set<pii > lps;//left pos
  void Del(int o,int x){
    pre[nxt[x]]=pre[x],nxt[pre[x]]=nxt[x];
    lps.erase(mkp(a[o][x].l,x));
  }
  void Init(int o,int lmt){
    for(int i=1;i<=lmt;i++)pre[i]=i-1,nxt[i]=i+1;
    for(int i=1;i<=lmt;i++)lps.insert(mkp(a[o][i].l,i));
    nxt[0]=1,nxt[lmt]=0;
  }
  int Calc(int o){
    int res=0,lst=0;
    for(int i=nxt[0];i;){
      res++,Del(o,i),lst=i;
      auto it=lps.lower_bound(mkp(a[o][i].r,i));
      if(it==lps.end())break;
      i=(*it).y;
    }
    return res;
  }
}l1,l2;
int ans1[N],ans2[N],ans;
int main(){
  freopen("airport.in","r",stdin);
  freopen("airport.out","w",stdout);
  Read(n),Read(m1),Read(m2);
  for(int i=1;i<=m1;i++)Read(a[0][i].l),Read(a[0][i].r);
  for(int i=1;i<=m2;i++)Read(a[1][i].l),Read(a[1][i].r);
  sort(a[0]+1,a[0]+1+m1),sort(a[1]+1,a[1]+1+m2);
  l1.Init(0,m1),l2.Init(1,m2);
  for(int x=1;x<=n;x++){
    ans1[x]=ans1[x-1]+l1.Calc(0);
    ans2[x]=ans2[x-1]+l2.Calc(1);
  }
  for(int i=0;i<=n;i++){
    ans=max(ans,ans1[i]+ans2[n-i]);
  }
  printf("%d\n",ans);
  KafuuChino HotoKokoa
}
