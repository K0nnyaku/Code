#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#define lll long long
using namespace std;
template<class T>
T read(T& x){
	x=0;
	T f=1;
	char c;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
int a[500001];
int t;
int n;
int vis[1000001];
string s;
string ans;
string emp;
void dfs(int l,int r){
//	cout<<l+r<<endl; 
//	cout<<l<<" "<<r<<endl;
//	cout<<s<<endl;
	if(l+r==2*n){
	//	cout<<s<<endl;
		if(ans==emp){
			ans=s;
		}else{
			if(s<ans){
				ans=s;
			}
		}
		return ;
	} 
	string tem=s;
	if(!vis[a[l+1]]){
		vis[a[l+1]]=l+r+1;
		s+='L';
		dfs(l+1,r);
		s=tem;
		vis[a[l+1]]=0;
	}
	if(vis[a[l+1]]){
		if(vis[a[l+1]]+l+r==2*n){
			s+='L';
			dfs(l+1,r);
			s=tem;
		}
	}
	if(!vis[a[2*n-r]]){
		vis[a[2*n-r]]=l+r+1;
		s+='R';
		dfs(l,r+1);
		s=tem;
		vis[a[2*n-r]]=0;
	}
	if(vis[a[2*n-r]]){
		if(vis[a[2*n-r]]+l+r==2*n){
			s+='R';
			dfs(l,r+1);
			s=tem;
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	//fclose(stdin);
	//fclose(stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
	//	cout<<n<<endl;
		ans=emp;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=2*n;++i){
			scanf("%d",&a[i]);
		}
		dfs(0,0);
		if(ans==emp){
			cout<<-1<<endl; 
		} else{
			cout<<ans<<endl;
		}
	} 
	return 0;
}

