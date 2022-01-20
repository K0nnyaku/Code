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
#define N 5000
using namespace std;
inline int read(){
	int rd=0,ch,flag=1;
	while((ch=getchar())<'0'||ch>'9') if(ch=='-') flag=-1;
	do rd=(rd<<1)+(rd<<3)+(ch^48);while((ch=getchar())>='0'&&ch<='9');
	return rd*flag;
}
ll n,k,a[N],cnt;
char c[N];
stack<int> s;
void dfs(int num,int p,int last,int i){
	if(i==n+1){
		if(num==0&&p==0) ++cnt;
		return;
	}
	if(a[i]==1){
		if(num>0){
			if(s.top()==1) s.pop(),s.push(2),s.push(0);
			else if(s.top()==0) s.pop(),s.push(3),s.push(0);
			else s.push(0);
		}
		else s.push(0);
		dfs(num+1,0,1,i+1);
		s.pop();
	}
	if(a[i]==2){
		if(num<=0) return;
		if(last==3&&s.top()==2) return;
		bool t=s.top();
		s.pop();
		dfs(num-1,0,2,i+1); 
		s.push(t);
	}
	if(a[i]==3){
		if(p>=k) return;
		if(!s.empty()){
			bool flag=0;
			if(last==1&&s.top()==0) flag=1;
			if(flag) s.pop(),s.push(1); 
			dfs(num,p+1,3,i+1);	
			if(flag) s.pop(),s.push(0);
		}
		else{
			dfs(num,p+1,3,i+1);	
		}
	}
	if(a[i]==0){
		
		int ff=0;
		if(num>0){
			if(s.top()==1) ff=1,s.pop(),s.push(2),s.push(0);
			else if(s.top()==0) ff=2,s.pop(),s.push(3),s.push(0);
			else s.push(0);
		}
		else s.push(0);
		dfs(num+1,0,1,i+1);
		if(ff==0) s.pop();
		if(ff==1) s.pop(),s.pop(),s.push(1);
		if(ff==2) s.pop(),s.pop(),s.push(0);
		
		if(num>0){
			if(!(last==3&&s.top()==2)){
				bool t=s.top();
				s.pop();
				dfs(num-1,0,2,i+1); 
				s.push(t);
			}
		}
		
		if(p<k&&i!=1){
			if(!s.empty()){
				bool flag=0;
				if(last==1&&s.top()==0) flag=1;
				if(flag) s.pop(),s.push(1); 
				dfs(num,p+1,3,i+1);	
				if(flag) s.pop(),s.push(0);
			}
			else{
				dfs(num,p+1,3,i+1);	
			}
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",c+1);
	for(ri i=1;i<=n;++i){
		if(c[i]=='(') a[i]=1;
		if(c[i]==')') a[i]=2;
		if(c[i]=='*') a[i]=3;
		if(c[i]=='?') a[i]=0;
	}
	dfs(0,0,0,1);
	cout<<cnt;
	return 0;
}
/*
7 3
(*??*??
(*()**)
*/
