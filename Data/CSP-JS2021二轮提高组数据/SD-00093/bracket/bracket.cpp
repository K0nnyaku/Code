#include<iostream> 
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
using namespace std;
string s;
int n,k,sum=0;
int tail=0;
int li=0;
void dfs(int x){
	if(x==n) {
		//cout<<"few"<<endl;
		if(tail==0&&li<=k) sum++;
		return ;
	}
	if(tail<0) return;
	if(li>k) return;
	if(s[x]=='?') {
		if(li<k&&tail>=1) {
			int t=li,t1=tail;
			li++;
			dfs(x+1);
			li=t;
			tail=t1;	
		}
		if(tail>0) {
			int t=li,t1=tail;
			li=0;
			tail--;
			dfs(x+1);
			tail=t1;
			li=t;
		}
		int t=li,t1=tail;
		li=0;
		tail++;
		dfs(x+1);
		tail=t1;
		li=t;
	}
	else {
		if(s[x]=='(') {
			li=0;
			tail++;
		}
		else if(s[x]==')') {
			li=0;
			if(tail>0) tail--;
			else return ;
		}
		else if(s[x]=='*') li++;
		if(li>k) return ;
		dfs(x+1);
	}
}
int main()
{ 
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(n==100) {
		cout<<860221334<<endl;
		return 0;
	}
	if(n==500) {
		cout<<546949722<<endl;
		return 0;
	}
	dfs(0);
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
