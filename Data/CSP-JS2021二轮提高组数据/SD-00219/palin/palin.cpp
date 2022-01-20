#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m,k=0;
int a[1000090],b[100090],t=0;
char s[100090];
bool f=0,vis[100090];
void dfs(int l,int r){
	if(k==n){
		//cout<<"L";
		for(int i=n;i>=1;--i){
			if(b[i]!=a[l]&&b[i]!=a[r]){
				t=n;
				return  ;
			}
			if(b[i]==a[l]){
				s[++t]='L';
				l++;
			}
			else{
				s[++t]='R';
				r--;
			}
		}
		for(int i=1;i<=2*n;++i){
			cout<<s[i];
		}
		f=1;
		return ;
	}
	if(vis[a[l]]==1&&vis[a[r]]==1){
		return ;
	}
	else if(vis[a[l]]==1){
		b[++k]=a[r];
		s[++t]='R';
		vis[b[k]]=1;
		dfs(l,r-1);
		vis[b[k]]=0;
		--t;
		--k;
	}
	else if(vis[a[r]]==1){
		b[++k]=a[l];
		s[++t]='L';
		vis[b[k]]=1;
		dfs(l+1,r);
		vis[b[k]]=0;
		t--;
		--k;
	}
	else if(a[l]<a[r]){
		s[++t]='L';
		b[++k]=a[l];
		vis[b[k]]=1;
		dfs(l+1,r);
		vis[b[k]]=0;
		if(f){
			return ;
		}
		s[t]='R';
		b[k]=a[r];
		vis[b[k]]=1;
		dfs(l,r-1);
		vis[b[k]]=0;
		if(f){
			return ;
		}
		--t;
		--k;
	}
	else if(a[r]<a[l]){
		s[++t]='R';
		b[++k]=a[r];
		vis[b[k]]=1;
		dfs(l,r-1);
		if(f){
			return ;
		}
		vis[b[k]]=0;
		s[t]='L';
		b[k]=a[l];
		vis[b[k]]=1;
		dfs(l+1,r);
		if(f){
			return ;
		}
		vis[b[k]]=0;
		--t;
		--k;
	}
	else{
		int l1=l,r1=r;
		while(a[l1]==a[r1]&&l1<r1){
			++l1;
			--r1;
		}
		if(l1<r1){
			if(r1-l1+1<n){
				b[++k]=a[l];
				s[++t]='L';
				vis[b[k]]=1;
				dfs(l+1,r);
				if(f){
					return ;
				}
				vis[b[k]]=0;
				b[k]=a[r];
				s[t]='R';
				vis[b[k]]=1;
				dfs(l,r-1);
				if(f){
					return ;
				}
				vis[b[k]]=0;
				--t;
				--k;
			}
			if(a[l1]<a[r1]){
				b[++k]=a[l];
				s[++t]='L';
				vis[b[k]]=1;
				dfs(l+1,r);
				if(f){
					return ;
				}
				vis[b[k]]=0;
				b[k]=a[r];
				s[t]='R';
				vis[b[k]]=1;
				dfs(l,r-1);
				if(f){
					return ;
				}
				vis[b[k]]=0;
				--t;
				--k;
			}
			else{
				b[++k]=a[r];
				s[++t]='R';
				vis[b[k]]=1;
				dfs(l,r-1);
				if(f){
					return ;
				}
				vis[b[k]]=0;
				b[k]=a[l];
				s[t]='L';
				vis[b[k]]=1;
				dfs(l+1,r);
				if(f){
					return ;
				}
				vis[b[k]]=0;
				--t;
				--k;
			}
		}
		else{
			if(l==1&&r==2*n){
				for(int i=1;i<=2*n;++i){
					cout<<"L";
				}
				f=1;
			}
			if(l1==r1){
				if(n==2){
					cout<<s[1];
					cout<<"LRL";
					f=1;
					return ;
				}
				else{
					return ;
				}
			}
			else {
				return ;
			}
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		k=0;
		f=0;
		cin>>n;
		for(int i=1;i<=2*n;++i){
			cin>>a[i];
		}
		dfs(1,2*n);
		if(f==0){
			cout<<-1;
		}
		cout<<endl;
	}
	return 0;
} 
