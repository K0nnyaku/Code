#include<bits/stdc++.h>
using namespace std;
const int M=100009;
int n,m1,m2;
int cnt1,cnt2;
struct edge1{
	int a,b;
	int flag=0;
}e1[M],e2[M];
int g1=1,g2=1;
int maxx1,maxx2;
int f1[M],f2[M];
bool cmp(const edge1 a,const edge1 b){
	if(a.a==b.a)return a.b<b.b;
	return a.a<b.a;
}
//m:表示航班数；g:表示需要多少廊桥；
//f[g]表示在有第g条廊桥时最多可停靠多少航班 
void G1(int m){ 
	for(int i=1;i<=m;i++){
		if(e1[i].flag==0){
			if(e1[i-1].flag<g1 || (e1[i-1].flag==g1 && e1[i].a>e1[i-1].b)){
				f1[g1]++;
				e1[i].flag=g1;
				cnt1--;
			}
		}
	}
	g1++;
	if(cnt1!=0){
		G1(m);
	}
}
void G2(int m){ 
	for(int i=1;i<=m;i++){
		if(e2[i].flag ==0){
			if(e2[i-1].flag<g2 || (e2[i-1].flag==g2 && e2[i].a>e2[i-1].b)){
				f2[g2]++;
				e2[i].flag=g2;
				cnt2--;
			}
		}
	}
	g2++;
	if(cnt2!=0){
		G2(m);
	} 
}
int ans;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&e1[i].a,&e1[i].b);
		maxx1=max(maxx1,e1[i].b);
		cnt1++;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&e2[i].a,&e2[i].b);
		maxx2=max(maxx2,e2[i].b);
		cnt2++;
	}
	if(cnt1+cnt2<=n){
		printf("%d\n",cnt1+cnt2);
		return 0;
	}
	sort(e1+1,e1+1+m1,cmp);
	sort(e2+1,e2+1+m2,cmp);
	int g3=0,g4=0;
	if(e1[1].b!=maxx1){
		G1(m1);
		for(int i=2;i<=g1;i++){
			f1[i]=f1[i]+f1[i-1];
		}
	}else{
		g3=1;
	}
	if(e2[1].b!=maxx2){
		G2(m2);
		for(int i=2;i<=g2;i++){
			f2[i]=f2[i]+f2[i-1];
		} 
	}else{
		g4=1;
	}
	if(g4==1){
		for(int i=0;i<n;i++){
			ans=max(ans,f1[i]+1);
			
		}
		ans=max(ans,f1[n]);
	}
	if(g3==1){
		for(int i=0;i<n;i++){
			ans=max(ans,1+f2[i]);
		}
		ans=max(ans,f2[n]);
	}
	if(g4!=1 && g3!=1){
		for(int i=0;i<=n;i++){
			ans=max(ans,f1[i]+f2[n-i]);
		}
	}

	printf("%d\n",ans);
	return 0;
}
