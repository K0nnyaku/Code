//

/*
	Name: bracket/bracket.cpp
	Copyright: 2021
	Author: AFGXF
	Date: 23/10/21 16:30
	Description: None
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=500+10;

int n,k;

int nxt[MAXN],head;

char s[MAXN];

int ans;

int top=0;

bool check() {
	top=0;
	int st=0;
	for(int i=1; i<=n; i++) {
		if(s[i]=='(') {
			top++;
		}
		if(s[i]==')') {
			top--;
			if(top<0)
				return 0;
		}
		if(s[i]=='*') {
			st++;
			if(st>k||i==1||i==n)
				return 0;
		} else {
			st=0;
		}
//    if((s[i-1]=='*'&&s[i]!='*'&&s[i]!='(')||(s[i+1]=='*'&&s[i]!='*'&&s[i]!=')')) {
//      return 0;
//    }
	}
	return top==0;
}


void dfs(int a) {
	static char CH[]= {0,'(',')','*'};

	if(a==0) {
		if(check()) {
			ans++;
		}
		return ;
	}
	for(int i=1; i<=3; i++) {
		s[a]=CH[i];
		dfs(nxt[a]);
	}
}

int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

	cin>>n>>k;
	cin>>(s+1);


	int last=0;
	for(int i=1; i<=n; i++) {
		if(s[i]=='?') {
			if (last==0) {
				head=i;
			}
			nxt[last]=i;
			last=i;
		}
	}

	dfs(head);

	cout<<ans<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
