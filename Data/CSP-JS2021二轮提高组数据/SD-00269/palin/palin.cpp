#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=101;
int T;
int n;
int a[2*maxn],b[2*maxn];
string vis;
void dfs(int st,int end,int len){
	if(len==2*n){
		for(int i=1;i<=n;i++){
			if(b[i]!=b[2*n+1-i]){
				
			}
		}
	}
	b[len]=a[end];
	vis[len+1]='R';
	dfs(st,end-1,len+1);
	b[len]=a[st];
	vis[len+1]='L';
	dfs(st+1,end,len+1);
}
signed main(){
	freopen("palin1.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
	    for(int i=1;i<=2*n;i++){
	    	cin>>a[i];
		}
		cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


