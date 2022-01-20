#include<iostream>
#include<cstdio>
#include<cstring>
#define MOD 1000000007
using namespace std;
int n,k,l,r,s;
long long ans;
char ss[503];int st[503];
bool ok()
{
	memset(st,0,sizeof(st));
	for(int i=1;i<n-1;i++)
	{
		if(ss[i]=='*'){
			st[i]=st[i-1]+1;
		}
		if(st[i]>k)return false;
	}return true;
}
void dfs(int s)
{
	if(s==0){
		if(l==r&&ok()){
			ans++;
		}
		return;
	}else{
		for(int i=1;i<n-1;i++){
			if(ss[i]=='?'){
				ss[i]='*';
				dfs(s-1);
				ss[i]='(';
				l++;
				dfs(s-1);
				l--;
				ss[i]=')';
				r++;
				dfs(s-1);
				r--;
				ss[i]='?';
				break;
			}
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	scanf("%s",ss);
	if(ss[0]=='*'){cout<<ans;
	return 0;
	}
	if(ss[n-1]=='*'){cout<<ans;
	return 0;
	}
	if(ss[0]=='?'){ss[0]='(';
	}
	if(ss[n-1]=='?'){ss[n-1]=')';
	}
	for(int i=0;i<n;i++)
	{
		if(ss[i]=='?'){
			s++;
		}
		if(ss[i]=='(')l++;
		if(ss[i]==')')r++;
	}
	if(s==0)ans=1;
	else{
	dfs(s);}
	cout<<ans%MOD;
	return 0;
}
