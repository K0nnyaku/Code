#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000001],c[1000001],front=1,reas,ans=-1;
char b[1000001],d[1000001];
void out(){
	bool flag=true;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(d[i]==b[i]&&d[j]<=b[j]){
				flag=false;
				break;
			}
		}
	}
	if(flag)for(int i=0;i<n;i++)b[i]=d[i];
}
void dfs(int x){
	if((x-1>=n/2&&c[x-1]==c[n-x])||x-1<n/2){
		if(x==n){
			if(ans==-1){
				ans=1;
				for(int i=0;i<n;i++)b[i]=d[i];
			}
			else if(ans=1){
				out();
				return;
			}
			else return;
		}
		else{
			d[x]='L';
			c[x]=a[front];
			front++;
			dfs(x+1);
			front--;
			d[x]='R';
			c[x]=a[reas];
			reas--;
			dfs(x+1);
			reas++;
		}
		return;
	}
	else{
		return;
	}
}
int main(){
	//freopen("palin.in","r",stdin);
	//freopen("palin.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>n;
		n*=2;
		for(int i=1;i<=n;i++)cin>>a[i];
		front=1;reas=n;
		dfs(0);
		if(ans==-1)cout<<-1;
		else cout<<b<<endl;
		ans=-1;
	}
	return 0;
}
