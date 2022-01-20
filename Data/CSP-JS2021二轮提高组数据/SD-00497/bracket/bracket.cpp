#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
const int MOD=1e9+7;
int  n,k,an;
string s;
char ans[101];

void check()
{
	int top=0;
	int nu=0;
	if(ans[1]!='('||ans[n]!=')'){
		return;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]=='('){
			nu=0;
			top++;
		}else if(ans[i]==')'){
			top--;
			nu=0;
			if(top<0) return;
		}else if(ans[i]=='*'){
			nu++;
			
			if(nu>k){
				return;
			}
		}
	} 
	if(top) return;
	an=(an+1)%MOD;
	/*for(int i=1;i<=n;i++){
		printf("%c ",ans[i]);
	}
	cout<<endl;*/
}



void dfs(int step)
{
	if(step==s.size()+1) 
	{
		check();
		return;
	}
	if(s[step-1]=='?'){
		ans[step]='*';
		dfs(step+1);
		ans[step]='(';
		dfs(step+1);
		ans[step]=')';
		dfs(step+1);
		
	}else{
		ans[step]=s[step-1];
		dfs(step+1);
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>s;
	dfs(1);
	printf("%d",an);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/

