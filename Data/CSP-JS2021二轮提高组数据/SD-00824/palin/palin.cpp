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

int n,m1,m2,ans,cnt1,cnt2,Sum1[M],Sum2[M];
//sum1是国内分配i个廊桥时停靠的飞机数量 
bool vis1[M],vis2[M];

struct node{
	int l,r,nxt,sum;
};
node a1[M],a2[M];

bool cmp(node a,node b){
	return a.l<b.l;
}

int main(){
	freopen("airport1.in","r",stdin);
	//freopen("airport.out","w",stdout);
	n=inp();m1=inp();m2=inp();
	for(int i=1;i<=m1;i++){
		a1[i].l=inp();a1[i].r=inp();
	} 
	for(int i=1;i<=m2;i++){
		a2[i].l=inp();a2[i].r=inp();
	}
	sort(a1+1,a1+m1+1,cmp);sort(a2+1,a2+m2+1,cmp);
	for(int i=1;i<=m1;i++){
		//cout<<a1[i].l<<" "<<a1[i].r<<endl; 
		bool Flag=0;
		for(int j=i+1;j<=m1;j++){
			if(a1[j].l>a1[i].r&&!vis1[j]){
				a1[i].nxt=j;
				a1[j].sum=a1[i].sum+1;
				Flag=1;
				vis1[j]=1;
				break;
			}
		}
		if(!Flag) Sum1[++cnt1]=a1[i].sum+Sum1[cnt1-1]+1;
	}
	for(int i=1;i<=n;i++) if(!Sum1[i])Sum1[i]=Sum1[i-1];
	for(int i=1;i<=m1;i++) cout<<a1[i].sum<<endl;
	cout<<endl;
	for(int i=1;i<=m2;i++){
		bool Flag=0;
		for(int j=i+1;j<=m2;j++){
			if(a2[j].l>a2[i].r&&!vis2[j]){
				a2[i].nxt=j;
				a2[j].sum=a2[i].sum+1;
				vis2[j]=1;
				Flag=1;
				break;
			} 
		}
		if(!Flag) Sum2[++cnt2]=a2[i].sum+Sum2[cnt2-1]+1;
	}
	for(int i=1;i<=n;i++) if(!Sum2[i])Sum2[i]=Sum2[i-1];
	//!a[i].last a[i].sum++;else ifa[i].l>a[i-1].last 
	//if(a[i].l>a[i-1].) a[i].sum++;
	for(int i=0;i<=n;i++){
		//cout<<Sum1[i]<<" "<<Sum2[i]<<endl;
	}
	for(int i=0;i<=n;i++) ans=max(ans,Sum1[i]+Sum2[n-i]);
	return !printf("%d",ans);
}

