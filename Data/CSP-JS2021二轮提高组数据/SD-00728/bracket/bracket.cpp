#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
bool mdf[501];
char a[501];
char ans[501];
void dfs(int pos){
	if(pos==n+1){
		int tot=0;
		for(int i=1;i<=n;i++){
			if(ans[i]=='*')tot++;
		}
		if(ans[1]!='('||ans[n]!=')')return;
		int sl=0,sr=0;
		for(int i=1;i<=n;i++){
			if(ans[i]=='(')sl++;
			if(ans[i]==')')sr++;
			if(sr>sl)return;
		}
		if(sl!=sr)return;
		if(tot>k)return ;
		int l=1,r=n;
		while(l<=r){
			while(l<=r&&ans[l]=='*')l++;
			while(l<=r&&ans[r]=='*')r--;
			if(l==r&&ans[l]=='*')break;
			if(ans[l]+ans[r]=='('+')'){
				l++,r--;
				continue;
			}
			return;
		}
		for(int i=1;i<=n;i++)cout<<ans[i];cout<<endl;
		sum++;
		return ;
	}
	if(!mdf[pos]){
		ans[pos]=a[pos];
		dfs(pos+1);
	}
	ans[pos]='*';
	dfs(pos+1);
	ans[pos]='(';
	dfs(pos+1);
	ans[pos]=')';
	dfs(pos+1);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='?')mdf[i]=1;
	}
	dfs(1);
	cout<<sum;
	return 0;
} 
