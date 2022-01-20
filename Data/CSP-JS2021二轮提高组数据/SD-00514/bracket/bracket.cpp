#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string a;
long long n,k;
long long f[505][505][255];
long long dfs(int len,int num,int left){
	if(len==n){
		if(left==0){
			f[len][num][left]=1;
			return 1;
		}
		else{
			f[len][num][left]=0;
			return 0;
		}
	}
	if(f[len][num][left]!=-1){
		return f[len][num][left];
	}
	long long ans=0;
	if(a[len]=='('){
		ans+=dfs(len+1,0,left+1);
	}
	else if(a[len]==')'){
		if(left>0){
			ans+=dfs(len+1,0,left-1);
		}
		else{
			f[len][num][left]=0;
			return 0;
		}
	}
	else if(a[len]=='*'){
		if(num<k){
			ans+=dfs(len+1,num+1,left);
		}
		else{
			f[len][num][left]=0;
			return 0;
		}
	}
	else{
		if(len==n-1){
			if(left>0){
				ans+=dfs(len+1,0,left-1);
			}
			else{
				ans=0;
			}
			f[len][num][left]=ans;
			ans%=1000000007;
			return ans;
		}
		if(left+1<=n-len-1){
			ans+=dfs(len+1,0,left+1);
		}
		if(left>0){
			ans+=dfs(len+1,0,left-1);
		}
		if(num<k){
			ans+=dfs(len+1,num+1,left);
		}
	}
	ans%=1000000007;
	f[len][num][left]=ans;
	return ans;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	memset(f,-1,sizeof f);
	if(a[0]!='('){
		if(a[0]=='?'){
			a[0]='(';
		}
		else{
			cout<<0;
			return 0;
		}
	}
	long long ans=dfs(1,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
