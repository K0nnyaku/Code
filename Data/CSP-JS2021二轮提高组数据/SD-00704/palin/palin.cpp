#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<deque>
#include<vector>
#include<map>
#define ri int
#define ll long long
#define N 100005
using namespace std;
inline int read(){
	int rd=0,ch,flag=1;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') flag=-1;
	do rd=(rd<<1)+(rd<<3)+(ch^48);while((ch=getchar())>='0'&&ch<='9');
	return rd*flag;
}
int n;
int a[N],m[N],t[N],b[N];
stack<int> s,s2;
bool dfs(int l,int r,int L,int R,int step){
	if(step==n){
		for(ri i=n;i>=1;--i) b[i]=s.top(),s.pop();
		for(ri i=1;i<=n;++i) cout<<(b[i]?'R':'L');
		while(!s2.empty()){
			cout<<(s2.top()?'R':'L');s2.pop();
		}
		cout<<endl;
		return 1;
	}
	if(step==0){
//		while(!s.empty())
		s.push(0);s2.push(0);
		if(dfs(2,n*2,m[1],m[1],step+1)) return 1;
		s.pop();s2.pop();
		s.push(1);s2.push(0);
		if(dfs(1,n*2-1,m[n*2],m[n*2],step+1)) return 1;
		s.pop();s2.pop();
	}
	if(m[l]==L-1&&L>l){
		s.push(0);s2.push(0);
		if(dfs(l+1,r,L-1,R,step+1)) return 1;
		s.pop();s2.pop();
	}
	if(m[l]==R+1&&R<r&&l<L){
		s.push(0);s2.push(1);
		if(dfs(l+1,r,L,R+1,step+1)) return 1;
		s.pop();s2.pop();
	}
	if(m[r]==L-1&&L>l&&R<r){
		s.push(1);s2.push(0);
		if(dfs(l,r-1,L-1,R,step+1)) return 1;
		s.pop();s2.pop();
	}
	if(m[r]==R+1&&R<r){
		s.push(1);s2.push(1);
		if(dfs(l,r-1,L,R+1,step+1)) return 1;
		s.pop();s2.pop();
	}
	return 0;
}
int T;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
	memset(t,0,sizeof t);
	n=read();
	for(ri i=1;i<=(n<<1);++i){
		int x=read();
		a[i]=x;
		if(t[x]) m[t[x]]=i,m[i]=t[x];
		if(!t[x]) t[x]=i;
	}
//	for(ri i=1;i<=(n<<1);++i) cout<<m[i]<<" ";
	if(!dfs(1,n*2,0,0,0)) cout<<-1<<endl;;
	}
	return 0;
}
/*
5
4 1 2 4 5 3 1 2 3 5
*/
