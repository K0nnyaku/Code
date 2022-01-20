#include<bits/stdc++.h>
using namespace std;
int T,n,a[2021],c[1101],ans[2021];
bool b[1001],b0;
void dfs(int l,int r,int now){
	if(b0)return;
	if(now==2*n){
		ans[2*n]=1;b0=1;
		/*for(int i=1;i<=2*n;i++){
			if(ans[i]==1)cout<<"L";
			else cout<<"R";
			}*/
		return ;
	}
	if(now<=n){
		if(!b[a[l]]){
			b[a[l]]=1;c[now]=a[l];
			ans[now]=1;
			dfs(l+1,r,now+1);
			b[a[l]]=0;
		} 
		if(b0)return;
		if(!b[a[r]]){
			b[a[r]]=1;c[now]=a[r];
			ans[now]=2;
			dfs(l,r-1,now+1);
			b[a[r]]=0;
		} 
		if(b0)return;
	}
	else{
		if(b0)return;
		if(a[l]==c[2*n+1-now]){
			ans[now]=1;dfs(l+1,r,now+1);
		}
		else{
			if(a[r]==c[2*n+1-now]){
				ans[now]=2;dfs(l,r-1,now+1);
			}
		}
		if(b0)return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(b,0,sizeof(b));b0=0;
		for(int i=1;i<=2*n;i++)cin>>a[i];
		if(n<1001)dfs(1,2*n,1);
		else {
			b0=1;
			int l1=1,r1=2*n,tot=0;
			while(a[l1]!=a[l1-1]&&tot<=n){
				ans[++tot]=1;c[tot]=a[l1];l1++;
			} 
			while(a[r1]!=a[r1+1]&&tot<=n){
				ans[++tot]=2;c[tot]=a[r1];r1--;
			} int tot2=n;
			if(tot<n)b0=1;
			else
			while(l1<=r1){
				if(a[l1]==c[tot]){
					ans[++tot2]=1;l1++;tot--;
				}
				else{
					if(a[r1]==c[tot]){
						ans[++tot2]=2;r1--;tot--;
					}
					else{
						b0=0;break;
					}
				}
			}
		}if(b0){
	//	for(int i=1;i<=n;i++)cout<<c[i]<<" ";
			for(int i=1;i<=2*n;i++){
				if(ans[i]==1)cout<<"L";
				else cout<<"R";
				}
			}
		else cout<<"-1";
		cout<<endl;
	}
	return 0;
}/*
1 10
5 4 3 2 1 1 2 3 4 5 6 7 8 9 10 10 9 8 7 6*/
