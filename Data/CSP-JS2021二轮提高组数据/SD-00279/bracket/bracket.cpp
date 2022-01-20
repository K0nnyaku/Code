#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
deque<int> q;
int a[1000005];
int read(){
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
int cnt,len;
int n,k;
string s;
void dfs(int now){
	if(now>=n){
		if(q.size()==0) cnt++;
		if(cnt>mod) cnt%=mod;
		return;
	}
	if(s[now]=='('){
		q.push_back(0);
		dfs(now+1);
	}
	else if(s[now]==')'){
		q.pop_back();
		dfs(now+1); 
	} 
	else if(s[now]=='*'){
		int tmp=q.back(); 
		if(tmp+1<=k){
			q.pop_back();
			q.push_back(tmp+1);
		}
		else return;
	}
	else if(s[now]=='?'){
		int tot=0;
		while(!q.empty()){
			a[++tot]=q.front();
			q.pop_front();
		}
		s[now]='(';
		while(!q.empty()) q.pop_front();
		for(int i=1;i<=tot;i++) q.push_back(a[i]);
		q.push_back(0);
		dfs(now+1);
		while(!q.empty()) q.pop_front();
		for(int i=1;i<=tot;i++) q.push_back(a[i]);
		s[now]=')';
		q.pop_back();
		dfs(now+1);
		while(!q.empty()) q.pop_front();
		for(int i=1;i<=tot;i++) q.push_back(a[i]);
		s[now]='*';
		int tmp=q.back();
		if(tmp+1<=k){
			q.pop_back();
			q.push_back(tmp+1);
		} 
		else return;
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(); k=read();
	cin>>s;
	dfs(0);
	printf("%d",cnt%mod);
	return 0;
}
