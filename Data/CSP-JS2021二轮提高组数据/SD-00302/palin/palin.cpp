#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 1000010
#define INF 0x3f3f3f3f
#define LL long long

using namespace std;

int t,n,a[maxn];
int b[maxn],cnt,all;
struct node{
  int num[22];
  string ans;
  bool operator < (const node &y) const{
    for(int j=0;j<n*2;j++){
      if(ans[j]<y.ans[j]) return 1;
      if(ans[j]>y.ans[j]) return 0;
    }
    return 1;
  }
}x[maxn];

int read(){
  int s=0,w=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
  while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
  return s*w;
}

int main(){
  freopen("palin.in","r",stdin);
  freopen("palin.out","w",stdout);
  t=read();
  while(t--){
    n=read();all=0;
    for(int i=1;i<=n*2;i++) a[i]=read();
    for(int i=0;i<(1<<(n*2));i++){
      int l=1,r=2*n;bool flag=0;cnt=0;
      for(int j=0;j<(n*2);j++){
        if(i&(1<<j)) b[++cnt]=a[l],l++;
        else b[++cnt]=a[r],r--;
      }
      for(int j=1;j<=n;j++)
        if(b[j]^b[2*n-j+1]) {flag=1;break;} 
      if(flag) continue;all++;
      for(int j=1;j<=n*2;j++){
        x[all].num[j]=b[j];
        if(i&(1<<j-1)) x[all].ans.push_back('L');
        else x[all].ans.push_back('R');
      }
    }
    if(all==0) {puts("-1");continue;} 
    sort(x+1,x+all+1);
    cout<<x[1].ans<<endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/

