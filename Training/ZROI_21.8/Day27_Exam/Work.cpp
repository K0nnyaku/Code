#include <cstdio>
#include <cstring>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>
#define ll long long 
#define ri register int 
#define ull unsigned long long
using namespace std; 
template <class T>inline void read(T &x){
  x=0;int ne=0;char c;
  while(!isdigit(c=getchar()))ne=c=='-';
  x=c-48;
  while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+c-48;
  x=ne?-x:x;return ;
}
const int maxn=3005;
const int inf=0x7fffffff;
struct Edge{
  int ne,to;
}edge[maxn<<1],_edge[maxn<<1];
int h[maxn],num_edge=1;
inline void add_edge(int f,int to){
  edge[++num_edge].ne=h[f];
  edge[num_edge].to=to;
  h[f]=num_edge;
}
int _h[maxn],_num_edge=1; 
inline void _add_edge(int f,int to){
  _edge[++_num_edge].ne=_h[f];
  _edge[_num_edge].to=to;
  _h[f]=_num_edge;
}
int n,m,sc,sb;
bool vis[maxn];
vector <int> g;
void _dfs(int now,int fa){
  int v;if(vis[now])return ;
  vis[now]=1;g.push_back(now);
  for(ri i=_h[now];i;i=_edge[i].ne){
      v=_edge[i].to;
      if(v==fa)continue;
      _dfs(v,now);
  }
  return ;    
}
void dfs(int now,int fa){
  int v;if(vis[now])return ;
  sb++;vis[now]=1;
  for(ri i=h[now];i;i=edge[i].ne){
      v=edge[i].to;
      if(v==fa)continue;
      dfs(v,now);
  }
  return ;    
}
int main(){
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
  int T,x,y,z;
  srand(19260817); 
  read(T);
  while(T--){
      ll ans=0;
      read(n),read(m);
      memset(h,0,sizeof(h));
      memset(_h,0,sizeof(_h));
      num_edge=_num_edge=1;       
      for(ri i=1;i<=m;i++){
          read(x),read(y);
          add_edge(x,y);
          _add_edge(y,x);
      }
      int ss=(n+1)*sizeof(bool);
      for(ri i=1;i<=n;i++){
          memset(vis,0,ss);
          g.clear();
          _dfs(i,0);
          memset(vis,0,ss);
          for(ri j=0;j<g.size();j++){
              sb=0;
              dfs(g[j],0); 
              ans+=sb;
          }
      }
      printf("%lld\n",ans);
  }
  return 0;
}