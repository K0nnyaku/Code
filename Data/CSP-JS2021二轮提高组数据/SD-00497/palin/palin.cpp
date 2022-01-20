#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
int T,n,flag=0;;
int a[41];
int b[41];
string ans="RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";

void check(string p)
{
	
	for(int i=1,j=2*n;i<=n,j>n;i++,j--){
		if(b[i]!=b[j]){
			return;
		}
	}
	flag=1;
	if(p<ans) ans=p;
}
void dfs(int k,int st,int en,string p)
{
	if(k==2*n+1){
		check(p);
		return;
	}else{
		string s=p+"L";b[k]=a[st];
		dfs(k+1,st+1,en,s);
		string r=p+"R";b[k]=a[en];
		dfs(k+1,st,en-1,r);
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		string p="";
		flag=0;
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		dfs(1,1,2*n,p);
		if(flag) cout<<ans<<endl;
		else printf("-1\n");
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
1
5
4 1 2 4 5 3 1 2 3 5
*/

