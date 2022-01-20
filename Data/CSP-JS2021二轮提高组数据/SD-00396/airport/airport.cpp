#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
#define inf 1e9
struct node{
	int l,r;
};
inline long long read(){
	int x=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') flag=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	if(flag) return x;
	return ~(x-1);
}
int n,m1,m2;
node a1[N],a2[N];
int d1[N],d2[N];
int cnt1[N],cnt2[N];
int t,p;
int ans=0;
int s=0;
int vis1[N],vis2[N];
int cmp(node a,node b){return a.l<b.l;}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++){
		a1[i].l=read();a1[i].r=read();
	}
	for(int i=1;i<=m2;i++){
		a2[i].l=read();a2[i].r=read();
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	//for(int i=1;i<=m1;i++) cout<<a1[i].l<<" "<<a1[i].r<<endl;
	//cout<<endl;
	//for(int i=1;i<=m2;i++) cout<<a2[i].l<<" "<<a2[i].r<<endl;
	t=1;d1[1]=1;p=1;
	for(int i=2;i<=m1;i++){
		int f=1;
		t++;
		int minn=inf,o;
		for(int j=1;j<i;j++){
			if(a1[i].l>a1[j].r&&!vis1[j]){
				f=0;
				if(minn>a1[j].r) minn=a1[j].r,o=j;
			}
		}
		if(f) d1[i]=t;
		else d1[i]=d1[o];vis1[o]=1;t--;
	}
	t=1;d2[1]=1;p=1;
	for(int i=2;i<=m2;i++){
		int f=1;
		t++;
		int minn=inf,o;
		for(int j=1;j<i;j++){
			if(a2[i].l>a2[j].r&&!vis2[j]){
				f=0;
				if(minn>a2[j].r) minn=a2[j].r,o=j;
			}
		}
		if(f) d2[i]=t;
		else d2[i]=d2[o];vis2[o]=1;t--;
	}
	for(int i=1;i<=m1;i++) cnt1[d1[i]]++;
	for(int i=1;i<=m2;i++) cnt2[d2[i]]++;
	//for(int i=1;i<=m1;i++) cout<<d1[i]<<endl;
	//cout<<endl;
	//for(int i=1;i<=m2;i++) cout<<d2[i]<<endl;
	//for(int i=1;i<=m1;i++) cout<<cnt1[i]<<endl;
	//cout<<endl;
	//for(int i=1;i<=m2;i++) cout<<cnt2[i]<<endl;
	for(int i=0;i<=n;i++){
		s=0;
		int x1=i,x2=n-i;
		while(x1){s+=cnt1[x1];x1--;}
		while(x2){s+=cnt2[x2];x2--;}
		ans=max(s,ans);
	}
	cout<<ans<<endl;
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
