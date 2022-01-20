#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int vec[100005];
int find1[100005],find2[100005];
struct node{
	int a,b;
}k[3][100005];
int n,m[3],ans;
bool cmp(node x,node y){
	return x.a<y.a;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m[1]>>m[2];
	for(int i=1;i<=m[1];i++) cin>>k[1][i].a>>k[1][i].b;
	sort(k[1]+1,k[1]+m[1]+1,cmp);
	for(int i=1;i<=m[2];i++) cin>>k[2][i].a>>k[2][i].b;
	sort(k[2]+1,k[2]+m[2]+1,cmp);
	for(int i=1;i<=m[1];i++){
		for(int j=1;j<=n;j++){
			if(k[1][i].a>vec[j]){
				find1[j]++;
				vec[j]=k[1][i].b;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++) find1[i]=find1[i]+find1[i-1];
	memset(vec,0,sizeof(vec));
	for(int i=1;i<=m[2];i++){
		for(int j=1;j<=n;j++){
			if(k[2][i].a>vec[j]){
				find2[j]++;
				vec[j]=k[2][i].b;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++) find2[i]=find2[i]+find2[i-1];
	for(int i=0;i<=n;i++){
		ans=max(ans,find1[i]+find2[n-i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
