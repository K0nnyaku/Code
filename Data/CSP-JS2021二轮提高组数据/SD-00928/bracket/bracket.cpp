#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
vector<int>v;
char c[505];
int n,k;
int ans=0;
bool check(char now[]){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i]!='*')
			cnt=0;
		else
			cnt++;
		if(cnt>k)
			return 0;
	}
	return 1;
}
void dfs(int x,char now[],int l){
	if(x==v.size()){
		if(check(now))
			ans=(ans+1)%p;
		return;
	}
	int pos=v[x];
	now[pos]='(';
	dfs(x+1,now,l+1);
	if(x){
		now[pos]='*';
		dfs(x+1,now,l);
	}
	if(l){
		now[pos]=')';
		dfs(x+1,now,l-1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	bool flag=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		c[i]=getchar();
		if(c[i]=='?')
			v.push_back(i);
		else
			flag=0;
	} 
	dfs(0,c,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
