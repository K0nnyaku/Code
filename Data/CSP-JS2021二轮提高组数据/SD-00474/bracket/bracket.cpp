#include<bits/stdc++.h>
using namespace std;
int n,k,ans;string s;
bool b[10000];
void pt(int h){
	for(int i=0;i<=5;i++)cout<<b[i]<<" ";
	cout<<endl;
}
void dfs(int pos,int h,int l){
//	printf("%d (:%d *:%d---%d\n",pos,h,l,ans);
//	pt(h);
	if(l>k||h<0)return;
	if(pos==n){
		if(l)return;
		if(h!=0)return;
		ans++;
	}
	switch(s[pos]){
	case '(':
		b[h]=(l!=0);
		dfs(pos+1,h+1,0);
		b[h]=0;
		break;
	case '*':
		if(b[h])return;
		dfs(pos+1,h,l+1);
		break;
	case ')':
		dfs(pos+1,h-1,0);
		break;
	case '?':
		if(pos==n-1){
			dfs(pos+1,h-1,0);
			break;
		}
		
		b[h]=(l!=0);
		dfs(pos+1,h+1,0);
		b[h]=0;
		if(l<k&&!b[h-1])dfs(pos+1,h,l+1);
		if(h>0)dfs(pos+1,h-1,0);
		break;
	}
	
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	dfs(0,0,0);
	cout<<ans+1;
	fclose(stdin);fclose(stdout);
	return 0;
} 
