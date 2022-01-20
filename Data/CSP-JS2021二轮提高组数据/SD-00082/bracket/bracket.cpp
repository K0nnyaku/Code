#include<bits/stdc++.h>
using namespace std;
int toi=1,n,k,tot,ans,b[505];
char ci[505];
char z[505];
int find(int x,int y,int r){
	if(x==0||y>k){
		return 0;
	}
	if(z[x-1]=='(')return x-1;
	if(z[x-1]=='*'){
		y++;
		if(r==0)r=2;
		if(r==1)return 0;
	}
	if(z[x-1]=='-'&&r==2)r=1;
	
	find(x-1,y,r);
}
bool pan(){
	toi=1;
	z[toi]=ci[1];
	if(z[toi]=='*'||z[toi]==')')return false;
	for(int i=2;i<=n;i++){
		toi++;
		z[toi]=ci[i];
		if(z[toi]==')'){
			int j=find(toi,0,0);
			if(j==0)return false;
			else{
				z[j]='-';
				toi=j;
			}
		}
	}
	int zuo=0,nm=0;
	for(int j=1;j<=toi;j++){
		if(z[j]=='(')return false;
		if(z[j]=='*'){
			nm++;
			if(j==1||j==toi)return false;
			if(nm>k)return false;
		}
	}
	return true;
}
void dfs(int x,int y){
	if(y==1)ci[b[x]]='(';
	if(y==0)ci[b[x]]='*';
	if(y==2)ci[b[x]]=')';
	if(x==tot){
		/*for(int i=1;i<x;i++){
			cout<<ci[b[i]];
		}
		cout<<endl;*/
		bool p=pan();
		if(p)ans++;
		return;
	}
	for(int i=0;i<=2;i++){
		dfs(x+1,i);
	}
}//1 (    0  *

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ci[i];
		if(ci[i]=='?'){
			tot++;
			b[tot]=i;
		}
	}
	dfs(1,0);
	dfs(1,1);
	dfs(1,2);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
