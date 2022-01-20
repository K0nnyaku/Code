#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long 
ll t,n,cnt,a[1010000],b[1010000],hd,tl,vis[510000];
char ans[1010000];
bool state=0;
void dfs(int k){//当前枚举到第k位 
	if(k==2*n+1){
		//if(ck())
			for(int i=1;i<=2*n;++i)
				cout<<ans[i];
	//	cout<<endl;
	//		for(int i=1;i<=2*n;++i)
	//			cout<<b[i]<<" ";
	//	cout<<endl;
			state=1;
			
		return ;
	}
	if(state!=1){
		if((k<=n && vis[a[hd]]==0) || (k>n && vis[a[hd]]==2*n-k+1)){//k在中间及之前，a的头没有放过或k在后半部，放的与原来回文 
			int q=vis[a[hd]];
			vis[a[hd]]=k;
			ans[k]='L';
			
			b[k]=a[hd];
			++hd;
			dfs(k+1);
			--hd;
			vis[a[hd]]=q;
		}
		if(state!=1){
			if((k<=n && vis[a[tl]]==0 ) || (k>n && vis[a[tl]]==2*n-k+1)){
				int q=vis[a[tl]];
				vis[a[tl]]=k;
				ans[k]='R';
				b[k]=a[tl];
				--tl;
				dfs(k+1);
				++tl;
				vis[a[tl]]=q;
			}
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i)
			vis[i]=0;
		state=0;
		hd=1,tl=2*n;
		for(int i=1;i<=2*n;++i)
			cin>>a[i];
		dfs(1);//要枚举第k位 
		if(state==0)
			cout<<-1;
	//	else
		//	for(int i=1;i<=2*n;++i)
	//			cout<<ans[i];
	//	cout<<endl;
	//		for(int i=1;i<=2*n;++i)
	//			cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
} 
// ccf nmsl
