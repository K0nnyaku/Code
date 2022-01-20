#include<iostream> 
#include<cstdio>
#include<cstring>
#include<set>
#include<deque>
using namespace std;
void file(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}
const int MAX_N=550;
char s[MAX_N];
int n,k;
char rs[MAX_N];
int f(int i,int pb,int ps){
	if(ps>k||pb<0)return 0;
	if(pb>n-i+1){
		return 0;
	}
	if(i==n+1){
		if(pb!=0||ps!=0)return 0;
		set<int> st;
		for(int i=1;i<=n;i++){
			if(rs[i]=='*'){
				int j;
				for(j=i;rs[j]=='*';j++);
				j--;
				if(rs[i-1]==')'&&rs[j+1]=='('){
					st.insert(i);
					st.insert(j);
				}
			}
		}
		deque<int> dq;
		for(int i=1;i<=n;i++){
			if(rs[i]=='('){
				dq.push_back(i);
			}
			if(rs[i]==')'){
				int x=dq.back();
				if(rs[x-1]=='*'&&rs[i+1]=='*'&&st.count(x-1)+st.count(i+1)==0){
					return 0;
				}
				dq.pop_back();
			}
		}
		return 1;
	}
	
	if(s[i]=='('){
		rs[i]='(';
		return f(i+1,pb+1,0);
	}else if(s[i]==')'){
		rs[i]=')';
		return f(i+1,pb-1,0);
	}else if(s[i]=='*'){
		rs[i]='*';
		return f(i+1,pb,ps+1);
	}else{
		int ans=0;
		rs[i]='('; 
		ans+=f(i+1,pb+1,0);
		if(i!=1){
			rs[i]='*';
			ans+=f(i+1,pb,ps+1);
		}
		rs[i]=')';
		ans+=f(i+1,pb-1,0);
		return ans;
	}
}
signed main(){
	file();
	scanf("%d %d %s",&n,&k,s+1);
	cout<<f(1,0,0)%int(1e9+7);
	
	return 0;
} 

/*
7 3
(*??*??
*/
