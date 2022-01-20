#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100010,M=40;
int n,m,len,i,j,x,y,w[N],op[N],cnt[M][2],ce;char tmp[9];
ll ans[N][M];
struct E{int x,y,o;E(){}E(int _x,int _y,int _o){x=_x,y=_y,o=_o;}}e[N];
inline bool cmp(const E&a,const E&b){return a.x>b.x;}
void dfs(int x,int y,int z,int o){
  ans[y][z]++;
  e[++ce]=E(y,z,o);
  if(x*2<=n)dfs(x*2,min(y,w[x*2]),z+1,o);
  if(x*2+1<=n)dfs(x*2+1,min(y,w[x*2+1]),z+1,o);
}
inline void solve(int x){
  ce=0;
  if(x*2<=n)dfs(x*2,w[x*2],1,0);
  if(x*2+1<=n)dfs(x*2+1,w[x*2+1],1,1);
  sort(e+1,e+ce+1,cmp);
  int i,j,y,o;
  for(j=1;j<=len;j++)cnt[j][0]=cnt[j][1]=0;
  for(i=1;i<=ce;i++){
    x=e[i].x,y=e[i].y,o=e[i].o;
    cnt[y][o]++;
    for(j=1;j<=len;j++)ans[x][y+j]+=cnt[j][o^1];
  }
}
int main(){
  freopen("dis.in","r",stdin);freopen("dis.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1,len=0;i<=n;i*=2)len++;
  for(i=1;i<=n;i++)w[i]=m+1;
  for(i=1;i<=m+1;i++)for(j=1;j<=len*2;j++)ans[i][j]=0;
  for(i=1;i<=m;i++){
    scanf("%s%d",tmp,&y);
    if(tmp[0]=='-'){
      op[i]=0;
      w[y]=i;
    }else{
      y=min(y,len*2);
      op[i]=y;
    }
  }
  for(i=1;i<=n;i++)solve(i);
  for(i=m;i;i--)for(j=1;j<=len*2;j++)ans[i][j]+=ans[i+1][j];
  for(i=1;i<=m;i++)for(j=1;j<=len*2;j++)ans[i][j]+=ans[i][j-1];
  for(i=1;i<=m;i++)if(op[i])printf("%lld\n",ans[i][op[i]]);
  fclose(stdin);fclose(stdout);
  return 0;
}