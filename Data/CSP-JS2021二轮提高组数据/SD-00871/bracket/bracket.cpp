#include <bits/stdc++.h>
#define f(i,a,b) for(register int i=(a);i<=(b);++i)
#define F(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
const int mod=1e9+7;
int n,k,sum;
int top,ans,ls,sl,mus,mm=-1;
char s[505];
int a[505],b[505];
inline int subm(int a,int b) {
	return a*b%mod;
}
inline int summ(int a,int b) {
	return (a+b)%mod;
}
void solve(int now) {
	if(now==n+1) {
		if(!top)
			++ans;
		return;
	}
	sl=ls,mus=sum;
	if(s[now]=='(') {
//		if((!ls)&&sum) return;
		if(((!ls)&&sum))mm=top;
		++top,ls=0,sum=0;
		solve(now+1);
		--top,ls=sl,sum=mus;
		return;
	}
	else if(s[now]==')') {
//		if(ls&&sum) return;
		
		if(top==0) return;
		--top,ls=1,sum=0;
/*		if(top==mm){
			if(ls&&mus)return;
			else mm=-1;
		} */
		solve(now+1);
		++top,ls=sl,sum=mus;
		return;
	}
	if(s[now]=='*') {
		if(sum>k) return;
		++sum;
		solve(now+1);
		--sum;
		return;
	}


/* * */	if(sum<k)
		{
			++sum;
			solve(now+1);
			--sum;
		}
//		else cout<<"\n";
/* ( */// if(!((!ls)&&sum)) {
		if(((!ls)&&sum))mm=top;
			++top,ls=0,sum=0;
			solve(now+1);
			--top,ls=sl,sum=mus;
		
//		}
/* ) *///	if((!(ls&&sum))&&top>0) {
		
		if(top>0) {
			--top,ls=1,sum=0;
/*			if(top==mm){
				if(ls&&mus)return;
				else mm=-1;	
			} */
			solve(now+1);
			++top,ls=sl,sum=mus;	
		}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s+1;
/*OK?*/
	int koko=0;
	if(s[1]=='*'||s[n]=='*'){cout<<0;return 0;}
	f(i,1,n) {
		if(s[i]=='*'){++sum;if(sum>k){cout<<0;return 0;}}
		else sum=0;
		if(s[i]=='(')++top;
		else if(s[i]==')'){--top;if(top<0){cout<<0;return 0;}}
		if(s[i]=='?')koko=1; 
	}
	f(i,1,n) {
		if(s[i]=='*') {
			if(s[i-1]=='(') {
				while(s[++i]=='*');
				if(s[i]=='('){cout<<0;return 0;}
			}
			else if(s[i-1]==')') {
				while(s[++i]=='*');
				if(s[i]==')'){cout<<0;return 0;}
			}
		}
	}
	if(!koko){cout<<1; return 0;}
/*OK?*/
	sum=0,top=0;
	if(s[1]=='?')s[1]='(';
	if(s[n]=='?')s[n]=')';
	solve(1);
	cout<<ans;
	return 0;
}
/*
10 2 ???(*??(?)
*/

/* 
7 3 (*??*??
*/
