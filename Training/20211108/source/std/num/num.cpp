#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef vector<int>V;
const int N=75;
int n,m,each,a[N];
int main(){
  freopen("num.in","r",stdin);freopen("num.out","w",stdout);
  scanf("%d%d",&n,&m);
  each=n/m;
  V tmp;
  tmp.resize(m+1);
  for(int i=0;i<=m;i++)tmp[i]=0;
  map<V,ll>pre,nxt;
  pre[tmp]=0;
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  sort(a,a+n);
  for(int i=0;i<n;i++){
    int x=a[i];
    nxt.clear();
    for(map<V,ll>::iterator it=pre.begin();it!=pre.end();it++){
      V A=it->first;
      ll B=it->second;
      for(int j=1;j<=m;j++)if(A[j]<each){
        if(A[j]>A[0]&&i&&x==a[i-1])continue;
        V C=A;
        C[j]++;
        ll D=B;
        if(C[j]==1)D-=x;
        if(C[j]==each)D+=x;
        C[0]=0;
        sort(C.begin(),C.end());
        C[0]=A[j];
        if(nxt.find(C)==nxt.end())nxt[C]=D;
        else nxt[C]=min(nxt[C],D);
      }
    }
    swap(pre,nxt);
  }
  ll inf=~0ULL>>1;
  ll ans=inf;
  for(map<V,ll>::iterator it=pre.begin();it!=pre.end();it++)ans=min(ans,it->second);
  if(ans==inf)ans=-1;
  printf("%lld",ans);
  fclose(stdin);fclose(stdout);
  return 0;
}