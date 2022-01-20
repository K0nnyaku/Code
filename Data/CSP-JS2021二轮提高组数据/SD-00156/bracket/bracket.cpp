#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 510
#define K 510
#define int long long
#define mod 1000000007
using namespace std;
inline bool isdigit(char x){return x>='0'&&x<='9';}
inline int read(){
	char x=getchar();int fl=1,ans=0;
	while(!isdigit(x)){if(x=='-')fl=-1;x=getchar();}
	while(isdigit(x)){ans=(ans<<3)+(ans<<1)+(int)(x-'0');x=getchar();}
	return fl*ans;
}
char inf[]="bracket.in",ouf[]="bracket.out";
int n,k,ans,f[N],q[N],s[N],rb[N];
char str[N];
int dfs(int cur,int star,int bracket){
	if(bracket<0||star>k||bracket>rb[cur])return 0;
	if(cur==n-1){
		if(bracket==1){
			printf("%lld %lld %lld\n",cur,star,bracket);
			return 1;
		}
		else return 0;
	}
	switch(str[cur]){
		case '*':{
			return dfs(cur+1,star+1,bracket);
		}
		case '(':{
			return dfs(cur+1,0,bracket+1);
		}
		case ')':{
			if(bracket<1)return 0;
			return dfs(cur+1,0,bracket-1);
		}
		default:{
			return ((dfs(cur+1,star+1,bracket)+dfs(cur+1,0,bracket+1))%mod+dfs(cur+1,0,bracket-1))%mod;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	freopen(inf,"r",stdin);
	freopen(ouf,"w",stdout);
	n=read();k=read();
	cin>>str;
	if(str[n-1]=='*'||str[n-1]=='('){
		printf("0");
		return 0;
	}
	for(int i=n-1;i>=0;i--){
		switch(str[i]){
			case '(':{
				rb[i]=rb[i+1]-1;
				break;
			}
			case ')':
			case '?':{
				rb[i]=rb[i+1]+1;
				break;
			}
			default:{
				rb[i]=rb[i+1];
				break;
			}
		}
	}
	int aans=dfs(0,0,0);
	printf("%lld",aans-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

