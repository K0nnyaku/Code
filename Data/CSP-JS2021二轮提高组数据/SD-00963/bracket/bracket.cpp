#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k;
char a[505];
long long ans=0;
const int M=1e9+7;
void dfs(int x,int y,int z){
	if(x==n){
		if(y<=k && z==1){
			ans++;
			ans%=M;
		}
		return ;
	}
	if(a[x]=='(') dfs(x+1 , 0 , z+1);
	else if(a[x]==')'){
		if(z<1) return ;
		dfs(x+1 , 0 , z-1);
		return ;
	}
	else if(a[x]=='*'){
		if(y>=k) return ;
		dfs(x+1 , y+1 , z);
		return ;
	}
	else if(a[x]=='?'){
		if(y<k) dfs(x+1 , y+1 , z);//?=*
		if(z>=1) dfs(x+1 , 0 , z-1);//?=)
		dfs(x+1 , 0 , z+1);//?=(
		return ;
	}
	return ;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	if(a[n]=='*' || a[n]=='('){
		printf("0");
		return 0;
	}
	dfs(2,0,1);
	printf("%lld\n",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

