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

const int maxn=1e5+5;

struct Node
{
  int a,b;
}p1[maxn],p2[maxn];
int r1[maxn],r2[maxn];
int n,m1,m2,ans=0,tot1=0,tot2=0,ans1=0,ans2=0,his_ans1=0,his_ans2=0;

inline int read()
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
bool cmp(Node x,Node y)
{
  return x.a<y.a;
}
inline void clr()
{
  memset(r1,0,sizeof(r1));
  memset(r2,0,sizeof(r2));
  tot1=0;
  tot2=0; 
  ans1=0;
  ans2=0;
}
inline void init()
{
  scanf("%d%d%d",&n,&m1,&m2);
  for(int i=1;i<=m1;i++)
  {
    scanf("%d%d",&p1[i].a,&p1[i].b);
   } 
  for(int i=1;i<=m2;i++)
  {
    scanf("%d%d",&p2[i].a,&p2[i].b);
  }
  sort(p1+1,p1+m1+1,cmp);
  sort(p2+1,p2+m2+1,cmp);
 } 
void dfs1(int cnt,int sum,int cnt_pln,int lnd)//停靠的飞机数，廊桥总数，飞机序号，停靠的历史飞机数 
{
  if(lnd+m1-cnt_pln<his_ans1) return;
  if(sum==0) return;
  if(cnt_pln>m1)
  {
     ans1=lnd;
     return;
  } 
  for(int i=1;i<=tot1;i++)
      if(p1[cnt_pln].a>r1[i]&&i>0)
      {
        r1[i]=0x3f3f3f3f;
        cnt--;
      }
  if(cnt<sum)
  {
    r1[++tot1]=p1[cnt_pln].b;
    dfs1(cnt+1,sum,cnt_pln+1,lnd+1);
  }
  else dfs1(cnt,sum,cnt_pln+1,lnd);
}
void dfs2(int cnt,int sum,int cnt_pln,int lnd)
{
  if(lnd+m2-cnt_pln<his_ans2) return;
  if(sum==0) return;
  if(cnt_pln>m2) 
  {
    ans2=lnd;
    return;
  }
  for(int i=1;i<=tot2;i++)
      if(p2[cnt_pln].a>r2[i]&&i>0)
      {
        r2[i]=0x3f3f3f3f;
        cnt--;
      }
  if(cnt<sum)
  {
    r2[++tot2]=p2[cnt_pln].b;
    dfs2(cnt+1,sum,cnt_pln+1,lnd+1);
  }
  else dfs2(cnt,sum,cnt_pln+1,lnd);
}
inline void solve()
{
  for(int i=0;i<=n;i++)
  {
    int j=n-i;
    clr();
    dfs1(0,i,1,0);
    dfs2(0,j,1,0);
    his_ans1=ans1;
    his_ans2=ans2;
    ans=max(ans,ans1+ans2);
   } 
}
inline void print()
{
  printf("%d\n",ans);
}
int main()
{
  freopen("airport.in","r",stdin);
  freopen("airport.out","w",stdout);
  init();
  solve();
  print();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
