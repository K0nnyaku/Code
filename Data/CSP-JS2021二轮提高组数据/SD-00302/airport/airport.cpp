#include<cmath>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200010
#define INF 0x3f3f3f3f
#define LL long long

using namespace std;

int visA[maxn],visB[maxn];
int baseA[maxn],baseB[maxn];
int n,mfir,msec,ans,cnt1,cnt2;
int st1[maxn],st2[maxn],ed1[maxn],ed2[maxn];
int ansA[maxn],ansB[maxn],numA[maxn],numB[maxn];
struct node{int l,r;}a[maxn],b[maxn];
priority_queue<int,vector<int>,greater<int> > q1,q2;

int read(){
  int s=0,w=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
  while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
  return s*w;
}

int main(){
  freopen("airport.in","r",stdin);
  freopen("airport.out","w",stdout);
  n=read();mfir=read();msec=read();
  for(int i=1;i<=mfir;i++) a[i].l=read(),a[i].r=read(),baseA[++cnt1]=a[i].l,baseA[++cnt1]=a[i].r;
  for(int i=1;i<=msec;i++) b[i].l=read(),b[i].r=read(),baseB[++cnt2]=b[i].l,baseB[++cnt2]=b[i].r;
  sort(baseA+1,baseA+cnt1+1);sort(baseB+1,baseB+cnt2+1);
  int tot1=unique(baseA+1,baseA+cnt1+1)-baseA-1;
  int tot2=unique(baseB+1,baseB+cnt2+1)-baseB-1;
  for(int i=1;i<=mfir;i++){
    a[i].l=lower_bound(baseA+1,baseA+tot1+1,a[i].l)-baseA;
    a[i].r=lower_bound(baseA+1,baseA+tot1+1,a[i].r)-baseA;
    visA[i]=2;st1[a[i].l]=i;ed1[a[i].r]=i;q1.push(i);
  }
  for(int i=1;i<=msec;i++){
    b[i].l=lower_bound(baseB+1,baseB+tot2+1,b[i].l)-baseB;
    b[i].r=lower_bound(baseB+1,baseB+tot2+1,b[i].r)-baseB;
    visB[i]=2;st2[b[i].l]=i;ed2[b[i].r]=i;q2.push(i);
  }
  for(int i=1;i<=tot1;i++){
    if(st1[i]){
      int p;p=q1.top();q1.pop();
      visA[p]=0,ansA[p]++,numA[st1[i]]=p;
    }
    if(ed1[i]) visA[numA[ed1[i]]]=2,q1.push(numA[ed1[i]]);
  }
  for(int i=1;i<=mfir;i++) ansA[i]+=ansA[i-1];
  
  for(int i=1;i<=tot2;i++){
    if(st2[i]){
      int p;p=q2.top();q2.pop();
      visB[p]=0,ansB[p]++,numB[st2[i]]=p;
    }
    if(ed2[i]) visB[numB[ed2[i]]]=2,q2.push(numB[ed2[i]]);
  }
  for(int i=1;i<=msec;i++) ansB[i]+=ansB[i-1];
  for(int i=0;i<=n;i++) ans=max(ans,ansA[i]+ansB[n-i]);
  printf("%d\n",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
