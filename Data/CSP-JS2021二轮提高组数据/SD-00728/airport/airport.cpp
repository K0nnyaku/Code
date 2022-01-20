#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct plane{
	int from;
	int to;
}a[100001],b[100001];
bool cmp(plane x,plane y){
	return x.from<y.from;
}
int maxxa,maxxb;
int A(int k){
	int ans=0,now=0;
	sort(a+1,a+1+m1,cmp);
	map<int,int> mp1,mp2;
	for(int i=1;i<=m1;i++){
		mp1[a[i].from]=i;
	}
	for(int i=1;i<=maxxa;i++){
		if(mp2[i])now--;
		if(now<k&&mp1[i]){
			now++;ans++;
			mp2[a[mp1[i]].to]=1;
		}
	}
	return ans;
}
int B(int k){
	int ans=0,now=0;
	sort(b+1,b+1+m2,cmp);
	map<int,int> mp1,mp2;
	for(int i=1;i<=m2;i++){
		mp1[b[i].from]=i;
	}
	for(int i=1;i<=maxxb;i++){
		if(mp2[i])now--;
		if(now<k&&mp1[i]){
			now++;ans++;
			mp2[b[mp1[i]].to]=1;
		}
	}
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].from>>a[i].to;
		maxxa=max(maxxa,a[i].to);
	}
	for(int i=1;i<=m2;i++){
		cin>>b[i].from>>b[i].to;
		maxxb=max(maxxb,b[i].to);
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,A(i)+B(n-i));
	}
	cout<<ans;
	return 0;
}



