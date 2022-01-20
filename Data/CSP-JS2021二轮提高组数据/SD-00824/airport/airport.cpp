#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define M 200200
#define INF 0x3f
using namespace std;
int Ans;char C;bool O;
int inp(){
	O=false;
	while((C=getchar())<'0'||C>'9') if(C=='-') O=true;Ans=C-48;
	while((C=getchar())<='9'&&C>='0') Ans=(Ans<<3)+(Ans<<1)+C-48;
	return O?-Ans:Ans;
}

int n,m1,m2,ans,cnt1,cnt2,sum1,sum2,lq1[M],lq2[M];

struct node{
	int l,r;
};
node a1[M],a2[M];

bool cmp(node a,node b){
	return a.l<b.l;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=inp();m1=inp();m2=inp();
	for(int i=1;i<=m1;i++){
		a1[i].l=inp();a1[i].r=inp();
	} 
	for(int i=1;i<=m2;i++){
		a2[i].l=inp();a2[i].r=inp();
	}
	sort(a1+1,a1+m1+1,cmp);sort(a2+1,a2+m2+1,cmp);
	for(int k=0;k<=n;k++){
		memset(lq1,0,sizeof(lq1));
		memset(lq2,0,sizeof(lq2));
		cnt1=cnt2=0;
		sum1=k;sum2=n-k;
		for(int i=1;i<=m1;i++){
			for(int j=1;j<=sum1;j++){
				if(a1[i].l>lq1[j]){
					lq1[j]=a1[i].r;
					cnt1++;
					break;
				}
			}
		}
		for(int i=1;i<=m2;i++){
			for(int j=1;j<=sum2;j++){
				if(a2[i].l>lq2[j]){
					lq2[j]=a2[i].r;
					cnt2++;
					break;
				}
			}
		}
		ans=max(ans,cnt1+cnt2);
	}
	return !printf("%d",ans);
}

