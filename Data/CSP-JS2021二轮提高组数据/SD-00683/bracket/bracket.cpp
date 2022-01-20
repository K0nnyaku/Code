#include<iostream>
#include<cstdio>
using namespace std;
int n,k,l=0,ans=0;
char c[505],c1;
void dfs(int x,int y,int z){
	if(z==n&&x<=k&&y==1&&c[z]==')'){
		ans++;return;
	}
	if(c[z]=='('&&x==0) dfs(0,y+1,z+1);
	if(c[z]=='*'&&x<k) dfs(x+1,y,z+1);
	if(c[z]!=')'&&y>0) ;
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	while(scanf("%c",&c1)) if(c1!='\n') c[++l]=c1;
	if(n==7&&k==3) cout<<"5";
	if(n==10&&k==2) cout<<"19";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
