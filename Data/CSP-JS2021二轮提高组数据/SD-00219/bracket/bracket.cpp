#include<iostream>
#include<cstdio>
using namespace std;
char a[100090];
int n,m;
int s[10090],t=0,sum=0;
bool vis[1090];
void dfs(int x,int y){
	//cout<<y;
	if(y==0){
		if(a[1]=='*'||a[n]=='*'||a[1]==')'||a[n]=='('){
			return ;
		}
		int v=0;
		for(int i=1;i<=n;++i){
			if(a[i]=='('){
				++i;
				int u=0;
				while(a[i]=='*'){
					++i;
					++u;
				}
				if(u>m){
					return ;
				}
				if(a[i]=='('){
					--i;
					++v;
					vis[v]=1;
				}
			}
			else if(a[i]==')'){
				if(a[i-1]=='*'&&vis[v]==1){
					vis[v]=1;
					return ;
				}
				vis[v]=1;
				--v;
			}
			if(v<0){
				return ;
			}
			if(a[i]=='*'){
				int u=1;
				while(a[i]=='*'){
					++u;
					if(u>m){
						return ;
					}
					++i;
				}
				--i;
			}
		}
		if(v==0){
			++sum;
		}
		return ;
	}
	for(int i=x;i<=n;++i){
		if(a[i]=='?'){
			a[i]='(';
			dfs(i,y-1);
			a[i]=')';
			dfs(i,y-1);
			a[i]='*';
			dfs(i,y-1);
			a[i]='?';
			break;
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>m;
	int h=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]=='?'){
			++h;
		}
	} 
	dfs(1,h);
	cout<<sum;
	return 0;
} 
