#include<iostream>
#include<cmath>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cstdlib>
using namespace std;
const int N=1e6+5;
int n,T,flag,orz;
int ans[N],vis[N],aans[N];
void file(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}
struct node{
	int p,w;
}a[N];
void clear(){
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	memset(ans,0,sizeof(ans));
	orz=0;
}
void solve1(int now,int head,int tail,int cnt){
	if(cnt==n/2) return;
	int po=now;
	flag=0;
	if(po==a[head].w&&flag==0){
		flag=1;
		ans[++cnt]=2;
		solve1(tail,head,tail-1,cnt);
	}
	if(po==a[tail].w&&flag==0){
		flag=1;
	}
	if(a[po-1].w==a[head].w&&flag==0){
		flag=1;
		ans[++cnt]=1;
		solve1(po-1,head+1,tail,cnt);
	}
	if(a[po+1].w==a[head].w&&flag==0){
		flag=1;
		ans[++cnt]=1;
		solve1(po+1,head+1,tail,cnt);
	}
	if(a[po-1].w==a[tail].w&&flag==0){
		flag=1;
		ans[++cnt]=2;
		solve1(po-1,head,tail-1,cnt);
	}
	if(a[po+1].w==a[tail].w&&flag==0){
		flag=1;
		ans[++cnt]=2;
		solve1(po+1,head,tail-1,cnt);
	}
	if(flag==0){
		orz++;
		return;
	}
}
int main(){
	file();
	cin>>T;
	while(T--){
		clear();
		cin>>n;
		n*=2;
		for(int i=1;i<=n;i++){
			cin>>a[i].w;
			if(vis[a[i].w]==0)
				vis[a[i].w]=i;
			else{
				a[i].p=vis[a[i].w];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].p){
				a[a[i].p].p=i;
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i].p<<" ";
//		}
		ans[1]=1;//1=L,2=R
		memset(vis,0,sizeof(vis));
		vis[1]=1;
		solve1(a[1].p,2,n,1);
		
		int head=1,tail=n;
		for(int i=1;i<=n/2;i++){
			if(ans[i]==1){
				aans[i]=a[head].w;
				head++;
			}
			if(ans[i]==2){
				aans[i]=a[tail].w;
				tail--;
			}
		}
		int cnt=n/2;
		for(int i=n/2;i>=1;i--){
			if(a[head].w==aans[i]){
				ans[++cnt]=1;
				head++;
			}
			if(a[tail].w==aans[i]){
				ans[++cnt]=2;
				tail--;
			}
		}
		if(orz){
			cout<<"-1"<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				if(ans[i]==1) cout<<"L";
				if(ans[i]==2) cout<<"R";
			}
			cout<<endl;
		}
	}
	return 0;
} 
