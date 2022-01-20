#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#include<stack>
using namespace std;
const int N=1000000007;
int n,k;
int xnum,znum;
long long ans;
char s[505];
int read()
{
	int f=1,sum=0;
	char ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9')
	{
		sum*=10;
		sum+=ch-'0';
		ch=getchar();
	}
	return sum*f;
}
bool judge()
{
	stack<int> q;
	bool fl=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='('){
			fl=0;
			q.push(i);
		} 
		else if(s[i]==')'){
			int t=q.top();
			if(s[t+1]=='*' && s[i-1]=='*' && fl) return false;
			q.pop();
			if(!fl) fl=1;
		} 
	}
	return true;
}
void dfs(int w,int x,int z)
{
	if(w==n){
		if(z==0 && s[w-1]==')' && s[0]=='(' && judge() ) ans++;
		if(ans>N) ans%=N;
		return;
	}
	if(s[w]=='?'){
		if(z<n-w && w!=n-1){
			s[w]='(';
			dfs(w+1,0,z+1);
		}
		if(x<k&& z<n-w && w!=0 && w!=n-1){
			s[w]='*';
			dfs(w+1,x+1,z);
		}
		if(z>0){
			s[w]=')';
			dfs(w+1,0,z-1);
		}
		s[w]='?';
	}
	else if(s[w]=='('){
		dfs(w+1,0,z+1); 
	} 
	else if(s[w]==')'){
		z--;
		if(z<0){
			return;
		}
		else dfs(w+1,0,z);
	} 
	else if(s[w]=='*'){
		x++;
		if(x>k){
			return;
		}
		else dfs(w+1,x,z);
	}
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='('){
			znum++;
			xnum=0;
		} 
		else if(s[i]==')'){
			znum--;
			xnum=0;
			if(znum<0){
				break;
			}
		} 
		else if(s[i]=='*'){
			xnum++;
			if(xnum>k){
				break;
			}
		}
		else if(s[i]=='?'){
			dfs(i,xnum,znum);
			break;
		} 
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
