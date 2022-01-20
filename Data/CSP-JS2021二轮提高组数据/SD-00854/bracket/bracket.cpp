#include<bits/stdc++.h>
#define int long long
#define s(x,y) x==y
using namespace std;
int n,k;
string s,ss="";
inline int read(){
	int f=1,q=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
	while(isdigit(ch))q=(q<<3)+(q<<1)+(ch^48),ch=getchar(); 
	return f?q:-q;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
inline int dfs(int x,string ss){
	if(!(x^n)){
		int l=0,r=0,cnt=0;
		for(register int i=0;i<n;++i){
			if(s(ss[i],'('))++l;
			if(s(ss[i],')'))++r;
			if(s(ss[i],'*'))++cnt;
			if(r>l)return 0;
			if(cnt>k)return 0;
			if(i<n-1&&cnt&&s(ss[i+1],')'))return 0;
		}
		return 1;
	}
	if(s[x]^'?')return dfs(x+1,ss+s[x]);
	else{
		int anss=0;
		anss+=dfs(x+1,ss+'(');
		anss+=dfs(x+1,ss+')');
		anss+=dfs(x+1,ss+'*');
		return anss;
	}
}
signed main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n=read(),k=read();
	cin>>s;
	print(dfs(0,ss));
	return 0;
}
