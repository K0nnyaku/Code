#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
int n,k,cnt,id[20], ans, num[20], sum[510];
char s[510];
map<int,char>mp;
inline void updt(){
	for(int i=1;i<=cnt;++i)
		s[id[i]]=mp[num[i]];
}
inline bool check(){ 
	if(s[1]=='*'||s[n]=='*')
		return 0;
	int cntx=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='*'){
			++cntx;
			if(cntx>k)
				return 0;
		}
		else
			cntx=0;
		sum[i]=sum[i-1]+(s[i]=='*');
	}
	stack<int>st;
	for(int i=1;i<=n;++i){
		switch(s[i]){
		case '(':
			st.push(i);
			break;
		case ')':
			if(st.empty())
				return 0;
			if(sum[i]-sum[st.top()]^i-st.top()-1&&s[i-1]=='*'&&s[st.top()+1]=='*')
				return 0;
			st.pop();
			break;
		}
	}
	if(st.size())
	return 0;
//	for(int i=1;i<=n;++i)
//	putchar(s[i]);
//	putchar('\n');
	return 1;
} 
inline void getnxt(){
	++num[1];
	int i=1;
	while(num[i]>2){
		num[i]-=3;
		++i;
		++num[i];
	}
}
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	if(!n||s[1]=='*'||s[n]=='*')
		putchar('0');
	mp[0]='*';
	mp[1]='(';
	mp[2]=')';
	for(int i=1;i<=n;++i)
		if(s[i]=='?'){
		++cnt;
		id[cnt]=i;
	}
	if(cnt>15){
		putchar('0');
		return 0;
	}
	do{
		updt();
		ans+=check();
		getnxt();
	}while(!num[cnt+1]);
	printf("%d",ans);
	return 0;
}
