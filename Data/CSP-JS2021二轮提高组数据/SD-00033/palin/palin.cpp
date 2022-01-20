#include<iostream> 
#include<cstdio>
#include<string>
using namespace std;
char s[100001];
int a[100001],n,ans=0,l,r,A=0,b[100001];
bool check(){
	for(int i=1;i<=n-i+1;++i){
		if(b[i]!=b[n-i+1]) return 0;
	}
	return 1;
}
void dfs(int idx){
	if(idx-1>n-idx+2) if(b[idx-1]!=b[n-idx+2]) return;
	if(A) return;
	if(idx>n){
		for(int i=1;i<=n;++i) cout<<s[i];
		cout<<endl;
		A=1;
		return;
	}
	b[idx]=a[++l],s[idx]='L',dfs(idx+1),--l;
	b[idx]=a[--r],s[idx]='R',dfs(idx+1),++r;
	b[idx]=0,s[idx]=0;
}
void work(){
	cin>>n;
	n+=n;
	l=0,r=n+1,A=0;
	for(int i=0;i<=1e5;++i) s[i]=0;
	for(int i=1;i<=n;++i) cin>>a[i];
	dfs(1);
	if(A==0) cout<<"-1\n";
}
int main(){
	freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--) work();
	return 0;
}
