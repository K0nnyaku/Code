#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<ctime>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=510;
int n,k,ans;
char a[N];
int pd(){
	int p=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='*')
			continue;
		if(a[i]=='(')
			p++;
		if(a[i]==')')
			p--;
		if(p<0)
			return 0;
	}
	if(p!=0)
		return 0;
	stack<int> st;
	for(int i=1;i<=n;i++){
		if(a[i]=='*')
			continue;
		if(a[i]=='(')
			st.push(i);
		if(a[i]==')'){
			int pp=st.top();
			if(a[pp-1]=='*'&&a[i+1]=='*')
				return 0;
			st.pop();
		}
	}
	if(a[1]=='*'||a[n]=='*')
		return 0;
	for(int i=1;i<=n;i++)
		cout<<a[i];
	cout<<endl;
	return 1;
}
void dfs(int x,int y){
	if(y>k)
		return;
	if(x==n+1){
		if(pd())
			ans++;
		return;
	}
	if(a[x]!='?'){
		if(a[x]=='*')
			dfs(x+1,y+1);
		else dfs(x+1,0);
		return;
	}
	a[x]='(';
	dfs(x+1,0);
	a[x]=')';
	dfs(x+1,0);
	a[x]='*';
	dfs(x+1,y+1);
	a[x]='?';
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",a+1);
	dfs(1,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

