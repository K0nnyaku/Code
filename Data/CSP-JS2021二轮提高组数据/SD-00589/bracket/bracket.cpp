#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod=1e9+7;
const int maxn=505;
int n,k,sum,len,ans;
char s[maxn],ds[3]={'(',')','*'};
bool vis[maxn];
bool check(){
	int sum1=1,x,suml=0,sumr=0;
	if(s[0]=='*'||s[len-1]=='*'||s[0]==')'||s[len-1]=='(') return 0;
	for(int i=1;i<len;++i){
		if(s[i-1]=='*'&&s[i]=='*') sum1++;
		else sum1=1;
		if(sum1>k) return 0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=len-1;i>=0;--i){
		if(s[i]=='('){
			suml++;
			for(int j=i+1;j<len;++j){
				if(s[j]==')'&&!vis[j]){
					x=j;
					vis[j]=1;
					break;
				}
				if(j==len-1) return 0;
			}
			if(s[i+1]=='*'&&s[x-1]=='*'&&x-i-1>k) return 0;
		}
		else if(s[i]==')') sumr++;
	}
	if(suml!=sumr) return 0;
	return 1;
}
void dfs(int x){
	int tp;
	if(sum==len){
		if(check()){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=x;i<len;++i){
		if(s[i]=='?'){
			for(int j=0;j<3;++j){
				s[i]=ds[j];
				sum++;
				dfs(i);
				sum--;
				s[i]='?';
			}
		}
	}
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;++i)
		if(s[i]!='?') sum++;
	dfs(0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
