#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stack>
#define ll long long

using namespace std;
ll n,k,sum;
stack <int> st;
char s[50],ans[50],pd[50];
inline ll Read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*w;
}
inline void dfs(ll p){
	if(p==n){
		ll cnt=0,cntt=0,flag=0,c1=0,c2=0;
		memset(pd,0,sizeof(pd));
		while(!st.empty()) st.pop();
		for(int i=1;i<=n;i++){
			if(ans[i]=='(') cntt++;
			if(ans[i]==')') cntt--;
			if(cntt<0) return;
			if(ans[i]=='*'&&cntt==0){
				return;
			}
		}
		if(cntt) return;
		for(int i=1;i<=n;i++){
			if(ans[i]=='(') st.push(i);
			else if(ans[i]==')') pd[i]=st.top(),st.pop();
		} 
		for(int i=1;i<=n;i++){
			if(ans[i]=='*'&&ans[i-1]==')'){
				if(ans[pd[i-1]-1]=='*')
					return;
			}
		}
		for(int i=1;i<=n;i++){
			if(ans[i]=='*'){
				cnt++;
				if(cnt>k) return;
			}else{
				cnt=0;
			}
		}
		sum++;

		return;
	}
	if(s[p]=='(') ans[p]='(';
	else if(s[p]==')') ans[p]=')';
	else if(s[p]=='*') ans[p]='*';
	else{
		ans[p]='(';
		dfs(p+1);
		ans[p]=')';
		dfs(p+1);
		ans[p]='*';
		dfs(p+1);
		ans[p]=0;
	} 
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=Read();
	cin>>s;
	dfs(1);
	cout<<sum<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}

