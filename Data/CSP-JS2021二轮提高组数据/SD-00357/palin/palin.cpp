#include<bits/stdc++.h>
#define N 500005
using namespace std;
int a[N],b[N],n,k=0;
char s[N];
bool flag=0,vis[N];
void dfs(int L,int R) {
	if(L==R){
		flag=1;
		return;
	}
	if(flag)return;
	if(((a[L]==b[2*n-k])||(b[2*n-k]==0))&&(vis[a[L]]==1||k<n)){
		vis[a[L]]=1;
		b[++k]=a[L];
		s[k]='L';
		dfs(L+1,R);
		if(flag)return;
		b[k]=0;
		k--;
	}
	if((a[R]==b[2*n-k]||b[2*n-k]==0)&&(vis[a[R]]==1||k<n)){
		vis[a[R]]=1;
		b[++k]=a[R];
		s[k]='R';
		dfs(L,R-1);
		if(flag)return;
		b[k]=0;
		k--;
	}
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		memset(s,0,sizeof(s));
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		k=0;
		cin>>n;
		for(int i=1;i<=2*n;i++) {
			cin>>a[i];
		}
		dfs(1,2*n);
		
		if(flag){
			cout<<s+1<<"L"<<endl;
		}
		else cout<<-1<<endl;
		flag=0;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

