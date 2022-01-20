#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int wc=1e6+5;
int t,n,a[wc],a1[wc+5],vis[wc]={0},ans[wc]={0};
char s[wc];
int cheak(int a[]){
	for(int i=1;i<=n*2;i++){
		a1[n*2-i+1]=a[i];
	}
	for(int i=1;i<=2*n;i++){
		if(a[i]!=a1[i]) return 1;
	}
	return 0;
}
int cheakvis(int vis[])
{
	for(int i=1;i<=n*2;i++){
		if(vis[i]==0)return 1;
	}
	return 0;
}
void dfs(int a[],int step,int be,int ed){
	dfs(a,step+1,be+1,ed);
	ans[be]=0;
	dfs(a,step+1,be-1,ed);
}
void solve(){
	int be=1,en;
	for(int i=2;i<=2*n;i++){
		if(a[i]==a[1]){
			en=i;
			break;
		}
	}
	dfs(a,1,be,en);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int a[2*n+5];
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		if(cheak(a)==0){
			for(int i=1;i<=2*n;i++){
				cout<<"L";
			}
			cout<<endl;
		}else{
			ans[1]=a[1];
			cout<<-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
