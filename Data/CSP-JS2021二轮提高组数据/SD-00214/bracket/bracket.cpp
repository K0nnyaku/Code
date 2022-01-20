#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
long long n,k,ans;
char a[1009];
int top[1009],zhan,x;
void dfs(int p){
	if(p==n){
		if(zhan)return;
		ans++;
		return;
	}
	int l;
	if(a[p]=='('){
		l=x;
		x=0;
		zhan++;
		if(a[p-1]=='*')top[zhan]=1;
		dfs(p+1);
		zhan--;
		x=l;
	}
	if(a[p]==')'&&(!top[zhan]||a[p+1]!='*')){
		l=x;
		x=0;
		zhan--;
		if(zhan<0){
			zhan++;
			x=l;
			return;
		}
		dfs(p+1);
		zhan++;
		x=l;
	}
	if(a[p]=='*'){
		if(p==0||p==n-1)return;
		x++;
		if(x>k){
			x--;
			return;
		}
		dfs(p+1);
		x--;
	}
	if(a[p]=='?'){
		l=x;
		x=0;
		zhan++;
		if(a[p-1]=='*')top[zhan]=1;
		dfs(p+1);
		zhan--;
		x=l;
		if(zhan>0&&(!top[zhan]||a[p+1]!='*')){
			l=x;
			x=0;
			zhan--;
			dfs(p+1);
			zhan++;
			x=l;
		}
		if(x!=k&&p!=0&&p!=n-1){
			x++;
			dfs(p+1);
			x--;
		}
	}
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	if(a[n-1]=='?')a[n-1]=')';
	if(a[n-1]!=')'){
		cout<<0;
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
} 
