#include<cstdio>
#include<iostream>
using namespace std;
long long ans;
int n,k,a=-10;
char s[600];
int f(int t1,int t2,int x)
{
	if(t1<0) return 0;
	if(x>n&&t1!=0) return 0;
	if(x>n) return 1;
	
	if(s[x]=='(') 
	{
		t1++;t2=0;
		if(s[x-1]=='*') a=t1;
	}
	if(s[x]=='*') 
	{
		t2++;
		if(s[x-1]==')'&&t1+1==a) {a=-10;return 0;} 
	}
	else  if(s[x-1]==')'&&t1+1==a) a=-10;
	if(s[x]==')') {t1--;t2=0; }
	if(t2>k) return 0;
	if(s[x]!='?') return f(t1,t2,x+1);
	else 
	{
		s[x]='(';
		int ans=f(t1+1,0,x+1);
		s[x]='*';
		ans=ans+f(t1,t2+1,x+1);
		s[x]=')';
		ans=ans+f(t1-1,0,x+1);
		s[x]='?';
		return ans;
	}
}
int main()
{
   freopen("bracket.in","r",stdin);
   freopen("bracket.out","w",stdout);
   scanf("%d %d",&n,&k);
   if(n==0)
   {
   	cout<<0;return 0;
	} 
   for(int i=1;i<=n;i++) cin>>s[i];
   printf("%d",f(0,0,1)/2%1000000007);
   fclose(stdin);
   fclose(stdout);
   return 0;
}

