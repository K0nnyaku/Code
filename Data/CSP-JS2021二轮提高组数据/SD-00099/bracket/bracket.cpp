#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,k;
char s[505];
long long mod=1e9+7;
char aa[505];
int can[505];
int tt;
stack<int> sta;
long long ans=0;
long long dfs(int step,int top,int num)
{
	int tmp=0;
	if(step==n+1&&top==0){

//		for(int i=1;i<=tt;i++)
//		cout<<aa[i];
//		cout<<endl;
		ans++;
		return 1;
	}
	if(n-top<top) return 0;
	long long an=0;
	if(s[step]!='?'){
		if(s[step]=='('){
			if(s[step-1]=='*') sta.push(1);//888
			else sta.push(0);
			aa[++tt]='(',an+=dfs(step+1,top+1,0),tt--,sta.pop();
		}
		if(s[step]==')'&&top==0) return 0;
		if(s[step]==')'){
			tmp=0;
			if(sta.top()==1){
				tmp=1;
				can[step+1]=1;
			}
			sta.pop();
			aa[++tt]=')',an+=dfs(step+1,top-1,0),tt--;
			sta.push(tmp);
			can[step+1]=0;
		}
		if(s[step]=='*'&&num==k||s[step]=='*'&&(step==n||step==1)) return 0;
		if(s[step]=='*'){
			if(can[step]==1){
				return 0;
			}
			aa[++tt]='*',an+=dfs(step+1,top,num+1),tt--;
		}
		return an%mod;
	}
	if(top>0){
		tmp=0;
		if(sta.top()==1){
			tmp=1;
			can[step+1]=1;
//			printf("ok\n");
		}
		sta.pop();
		aa[++tt]=')';
		an+=dfs(step+1,top-1,0);
		tt--;
		sta.push(tmp);
		can[step+1]=0;
	}
	if(num+1<=k&&step!=n&&step!=1)
	{
		if(can[step]==1) {
//			printf("ok\n");
			return 0;
		}
		aa[++tt]='*';
		an+=dfs(step+1,top,num+1);
		tt--;
	}
	tmp=0;
	if(aa[step-1]=='*') {
//		printf("ok\n");888
		tmp=1;
	}
	sta.push(tmp);
	aa[++tt]='(';
	an+=dfs(step+1,top+1,0);
	sta.pop();
	tt--;
	return an%mod;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	dfs(1,0,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??

10 2
???(*??(?)

10 3
??????????
*/
