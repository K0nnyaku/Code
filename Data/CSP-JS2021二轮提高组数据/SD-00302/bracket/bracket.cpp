#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 100010
#define INF 0x3f3f3f3f
#define LL long long
#define Mod 1000000007 

using namespace std;

int n,k,ans,cnt,all,tot;
string s,t[maxn],p[maxn];
int a[maxn],cntt[maxn];

int read(){
  int s=0,w=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
  while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
  return s*w;
}

void dfs(int pos){
  if(pos==n+1){
    ++all;
    for(int i=1;i<=n;i++){
      if(s[i-1]!='?') t[all].push_back(s[i-1]);
      else{
        if(a[i]==1) t[all].push_back('(');
        if(a[i]==2) t[all].push_back(')');
        if(a[i]==3) t[all].push_back('*');
      }
    }
    return; 
  }
  for(int i=1;i<=3;i++){
    a[pos]=i;dfs(pos+1); 
  }
}

int main(){
  freopen("bracket.in","r",stdin);
  freopen("bracket.out","w",stdout);
  n=read();k=read();
  cin>>s;dfs(1);
  sort(t+1,t+all+1);
  p[1]=t[1];tot=1;
  for(int i=2;i<=all;i++){
    bool flag=0;
    for(int j=0;j<n;j++)
      if(t[i][j]!=p[tot][j]) {flag=1;break;}
    if(flag) p[++tot]=t[i]; 
  }
  for(int i=1;i<=tot;i++){
    int sum=0;bool flag=0;
    int len=0;
    for(int j=0;j<n;j++){
      if(p[i][j]=='(') sum++,len=0;
      if(p[i][j]==')'){
        sum--,len=0;
        cntt[sum+1]=0;
      }
      if(p[i][j]=='*'){
        if(j==0||j==n-1) {flag=1;break;}
        len++;
        if(len==1) cntt[sum]++;
        if(len>k) {flag=1;break;}
      }
      if(sum<0) {flag=1;break;}
      if(cntt[sum]>=2&&sum>0) {flag=1;break;}
    }
    for(int j=0;j<=n;j++) cntt[j]=0;
    if(sum) flag=1;
    if(len) flag=1;
    if(!flag) ans++;
    if(ans>Mod) ans-=Mod;
  }
  printf("%d\n",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
/*
10 2
???(*??(?)

*/ 
