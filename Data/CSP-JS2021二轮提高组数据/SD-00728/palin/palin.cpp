#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[500001];
int ans[500001];
int val[500001];
bool flag;
void dfs(int now,int l,int r){
	if(flag)return;
	if(l>r){
		for(int i=1;i<=n/2;i++){
			if(ans[i]!=ans[n-i+1])return;
		}
		for(int i=1;i<=n;i++){
			if(val[i]==1){
				cout<<"L";
			}else{
				cout<<"R";
			}
		}
		cout<<endl;
		flag=true;
		return;
	}
	ans[now]=a[l];
	val[now]=1;
	dfs(now+1,l+1,r);
	ans[now]=a[r];
	val[now]=-1;
	dfs(now+1,l,r-1);
}
map<int,int> pos;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;n*=2;
		bool is_ok=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(!pos[a[i]]){
				pos[a[i]]=i;
			}else{
				if((i-pos[a[i]])%2==0){
					printf("-1");
					is_ok=false;
				}
			}
		}
		flag=false;
		if(is_ok)dfs(1,1,n);
	}
}
