#include<cmath>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 100010
#define INF 0x3f3f3f3f
#define LL long long

using namespace std;

int n,m,t,k,ans=INF,Ans;
int l1,r1,l2,r2;
int c[510][510],Dis[510][510][2];
struct node{int x,y;};

int read(){
  int s=0,w=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
  while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
  return s*w;
}

int main(){
  freopen("traffic.in","r",stdin);
  freopen("traffic.out","w",stdout);
  n=read();m=read();t=read();
  for(int i=1;i<n;i++)
    for(int j=1;j<=m;j++)
      Dis[i][j][1]=read();
  for(int i=1;i<=n;i++)
    for(int j=1;j<m;j++)
      Dis[i][j][2]=read(); 
  if(n<=5&&m<=5){
    while(t--){
      k=read();int tot=n+m,l,r;Ans=0;
      for(int i=1,pos,val,col;i<=k;i++){
        val=read();pos=read();col=read();
        if(pos<=m){
          Dis[0][pos][1]=val;
          c[0][pos]=col;continue;
        } 
        else pos-=m;
        if(pos<=n){
          Dis[pos][m][2]=val;
          c[pos][m]=col;continue;
        } 
        else pos-=n;
        if(pos<=m){
          Dis[n][m-pos+1][1]=val;
          c[n][m-pos+1]=col;continue;
        }   
        else pos-=m;
        Dis[n-pos+1][0][2]=val;
        c[n-pos+1][0]=col; 
      }
      for(int i=0;i<(1<<tot);i++){
        Ans=0;
        for(int j=0;j<tot;j++){
          l=(j+1)/m+1;r=(j+1)-(l-1)*m+1;
          if(i&(1<<j)) c[l][r]=1;
          else c[l][r]=0;
        }
        for(int i=0;i<=n;i++){
          for(int j=0;j<=m;j++){
            if(c[i][j]!=c[i][j+1]&&i) Ans+=Dis[i][j][2];
            if(c[i][j]!=c[i+1][j]&&j) Ans+=Dis[i][j][1];
          }
        }
        ans=min(ans,Ans);
      }
      printf("%d\n",ans);ans=INF;
    }
  }
  else{
    int colfir=INF,colsec=INF;
    int valfir=INF,valsec=INF;
    while(t--){
      k=read();
      for(int i=1,pos,val,col;i<=k;i++){
        val=read();pos=read();col=read();
        if(colfir==INF) colfir=col,valfir=val;
        else colsec=col,valsec=val;
        if(pos<=m){
          Dis[0][pos][1]=val;
          c[0][pos]=col;continue;
          if(i==1) l1=0,r1=pos;
          else l2=0,r2=pos;
        } 
        else pos-=m;
        if(pos<=n){
          Dis[pos][m][2]=val;
          c[pos][m]=col;continue;
          if(i==1) l1=pos,r1=m;
          else l2=pos,r2=m;
        } 
        else pos-=n;
        if(pos<=m){
          Dis[n][m-pos+1][1]=val;
          c[n][m-pos+1]=col;continue;
          if(i==1) l1=n,r1=m-pos+1;
          else l2=n,r2=m-pos+1;
        }   
        else pos-=m;
        Dis[n-pos+1][0][2]=val;
        c[n-pos+1][0]=col; 
        if(i==1) l1=n-pos+1,r1=0;
        else l2=n-pos+1,r2=0;
      }
      if(colfir==colsec) {puts("0");continue;}
      printf("%d\n",min(valfir,valsec));
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
/*

2 3 5
9 4 7
3 8
10 5
2
19 3 1
17 9 0
2
19 3 0
17 9 1
2
19 3 0
17 9 0 
2
19 3 1
17 9 0
2
19 3 0
17 9 1
*/
