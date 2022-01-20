#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
int read(){
	int a=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')a=a*10+c-'0',c=getchar();
	return a;
}
int n,m1,m2,ans,f;
struct faq{
	int begin,last;
}a[100001],b[100001];
int q[100001];
int cmp(faq x,faq y){
	return x.begin<y.begin;
}
int dfs(int t){
	if(t>=m1)return m1;
	int l=0,r=1,cnt=0;
	memset(q,0,sizeof(q));
	for(int i=1;i<=m1;i++){
		while(a[i].begin>q[r]&&l>=r)r++;
		if(l-r+1<t){
			q[++l]=a[i].last;
			cnt++;
			stable_sort(q+1,q+1+cnt);
		}
	}
	return cnt;
}
int dfs1(int t){
	if(t>=m2)return m2;
	int l=0,r=1,cnt=0;
	memset(q,0,sizeof(q));
	for(int i=1;i<=m2;i++){
		while(b[i].begin>q[r]&&l>=r)r++;
		if(l-r+1<t){
			q[++l]=b[i].last;
			cnt++;
			stable_sort(q+1,q+1+cnt);
		}
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read(); 
	for(int i=1;i<=m1;i++)a[i].begin=read(),a[i].last=read();
	for(int i=1;i<=m2;i++)b[i].begin=read(),b[i].last=read();
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=0;i<=n;i++){
		int j=n-i;
		int sum=dfs(i)+dfs1(j);
		ans=max(ans,sum);
	} 
	printf("%d",ans);
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
