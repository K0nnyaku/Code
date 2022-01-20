#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int n,k,ans;
string a;
bool vis[510];
int read(){
	int s=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*w;
}
bool check(string s){
	if(s[0]=='*'||s[n-1]=='*'){
		return 0;
	}
	for(int i=0;i<=n-1;){
		if(s[i]=='*'){
			int num=0;
			for(;i+num<=n-1&&s[i+num]=='*';num++){
				if(num>k){
					return 0;
				}
			}
			i=i+num;
			continue;
		}
		i++;
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n-1;i++){
		if(s[i]==')'&&!vis[i]){
			return 0;
		}
		if(s[i]=='('&&!vis[i]){
			bool flag=0;
			for(int q=i+1;q<=n-1;q++){
				if(s[q]==')'&&!vis[q]){
					vis[q]=1;
					flag=1;
					break;
				}
			}
			if(flag){
				vis[i]=1;
			}else{
				return 0;
			}
		}
	}
	string z="(*()**)";
	bool flag=0;
	for(int i=0;i<=n-1;i++){
		if(s[i]!=z[i]){
			flag=1;
			break;
		}
	}
	if(!flag){
		return 0;
	}
	return 1;
}
void dfs(int m,string b){
	if(n==m){
		if(check(b)){
			ans++;
		}
		return;
	}
	if(b[m]=='?'){
		b[m]='(';
		dfs(m+1,b);
		b[m]='*';
		dfs(m+1,b);
		b[m]=')';
		dfs(m+1,b);
		return;
	}
	dfs(m+1,b);
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	dfs(0,a);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

