#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int maxn,n,m1,m2,ans,a[10000100],b[10000100],ta[100100],tb[100100],qta[100100],qtb[100100];
struct work{
	int a,b;
} gn[100100],gj[100100];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	if(m1+m2<=n){
		cout<<m1+m2<<endl;
		fclose(stdin); fclose(stdout);
		return 0;
	}
	for(int i=1;i<=m1;i++){
		cin>>gn[i].a>>gn[i].b;
		a[gn[i].a]++;
		a[gn[i].b+1]--;
		maxn=max(maxn,gn[i].b);
	}
	for(int i=1;i<=m2;i++){
		cin>>gj[i].a>>gj[i].b;
		b[gj[i].a]++;
		b[gj[i].b+1]--;
		maxn=max(maxn,gj[i].b);
	}
	for(int i=1;i<=maxn;i++){
		a[i]=a[i-1]+a[i];
		b[i]=b[i-1]+b[i];
	}
	for(int i=1;i<=m1;i++){
		ta[a[gn[i].a]]++;
	}
	for(int i=1;i<=m2;i++){
		tb[b[gj[i].a]]++;
	}
	for(int i=1;i<=n;i++){
		qta[i]=qta[i-1]+ta[i];
		qtb[i]=qtb[i-1]+tb[i];
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,qta[i]+qtb[n-i]);
	}
	cout<<ans<<endl;
	fclose(stdin); fclose(stdout);
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
