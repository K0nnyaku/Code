#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
string ans;
char step[1000005];
int a[1000005],n,b[1000005],flag;
bool vis[1000005];
void dfs(int q[],int l,int r,int lth,char sp[]){
	if(flag==1){
		return;
	}
	if(lth==2*n){
		flag=1;
		ans=sp;
		return;
	}
	if(lth<n){
		if(vis[a[l]]==0){
			vis[a[l]]=1;
			q[lth+1]=a[l];
			sp[lth]='L';
			dfs(q,l+1,r,lth+1,sp);
			vis[a[l]]=0;
		}
		if(vis[a[r]]==0){
			vis[a[r]]=1;
			q[lth+1]=a[r];
			sp[lth]='R';
			dfs(q,l,r-1,lth+1,sp);
			vis[a[r]]=0;
		}
	}
	else{
		if(a[l]==q[2*n-lth]){
			q[lth+1]=a[l];
			sp[lth]='L';
			dfs(q,l+1,r,lth+1,sp);
		}
		if(a[r]==q[2*n-lth]){
			q[lth+1]=a[r];
			sp[lth]='R';
			dfs(q,l,r-1,lth+1,sp);
		}
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		memset(step,0,sizeof(step));
		ans="";
		flag=0;
		cin>>n;
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		b[1]=a[1];
		vis[a[1]]=1;
		step[0]='L';
		dfs(b,2,2*n,1,step);
		if(flag==1){
			cout<<ans<<endl;
			continue;
		}
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		memset(step,0,sizeof(step));
		ans="";
		flag=0;
		b[1]=a[2*n];
		step[0]='R';
		dfs(b,1,2*n-1,1,step);
		if(flag==1){
			cout<<ans<<endl;
			continue;
		}
		cout<<-1<<endl;		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
