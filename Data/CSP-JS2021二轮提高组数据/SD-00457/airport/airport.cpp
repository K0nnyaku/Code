#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N=100010;


pair<int,int> gn[N],gw[N];
long n,m1,m2;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}


int solven(int n){
	int c[N]={0};
	if(n==0) return 0;
	int ans=0;
	for(int i=0;i<m1;i++){
		if(c[gn[i].first]>n-1) continue;
		for(int j=gn[i].first;j<gn[i].second;j++){
			c[j]++;
		}
		ans++;
	}
	return ans;
}
int solvew(int n){
	int d[N]={0};
	if(n==0) return 0;
	int ans=0;
	for(int i=0;i<m2;i++){
		if(d[gw[i].first]>n-1) continue;
		for(int j=gw[i].first;j<gw[i].second;j++){
			d[j]++;
		}
		ans++;
	}
	return ans;
}


int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>gn[i].first>>gn[i].second;
	}
	for(int i=0;i<m2;i++){
		cin>>gw[i].first>>gw[i].second;
	}
	sort(gn,gn+m1,cmp);
	sort(gw,gw+m2,cmp);
	int maxa=-1,maxb=-1;
	int mmax=-1;
	for(int i=0;i<=n;i++){
		mmax=max(mmax,solven(i)+solvew(n-i));
	}
	cout<<mmax;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

