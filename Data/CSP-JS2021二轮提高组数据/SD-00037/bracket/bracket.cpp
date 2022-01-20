#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define mod 1000000007
int f[100000];
char c;
int l,r;
int n,m,ans;
bool check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if((i==1||i==n)&&f[i]==0)return 0;
		if(sum<0)return 0;
		sum+=f[i];
	}
	if(!sum){ 
		return 1;
	}
	return 0;
}
void dfs(int p){
	if(p==n+1){
		if(check()){
		
			ans++;
	
		}
		return ;
	}
	if(f[p]==2){
		if(l<m){
			f[p]=0;
			l++;
			dfs(p+1);
			l--;
		}
		f[p]=-1;
		dfs(p+1);
		f[p]=1;
		dfs(p+1);
		f[p]=2;
	}
	else dfs(p+1);
	return ;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='('){
			f[i]=1;
		}
		else if(c==')'){
			f[i]=-1;
		}
		else if(c=='*')f[i]=0,l++;
		else f[i]=2;
	}
	if(f[1]==0&&f[1]==-1){
		cout<<0£»
		return 0;  
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
