#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

stack<char> s;
char ch[505];
char a[505];
char change[5]={' ','(','*',')'};
int head,tail;
int ok,ans;
int n,k;
int cnt;

void DFS(int i,char x){
	
	if(x=='?') for(int j=1;j<=3;j++) DFS(i,change[j]);
	if(x=='('){
		s.push(x);
		DFS(i+1,ch[i+1]);
	}
	if(x=='*'){
		s.push(x);
		DFS(i+1,ch[i+1]);
	}
	if(x==')'){
		while(s.top()!='('){
			s.pop();
		}
		DFS(i+1,ch[i+1]);
	}
	if(i>=n&&s.empty()) ans++;
	s.pop();
}

int main(){

	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++) cin>>ch[i];
	
	DFS(1,ch[1]); 
	
	cout<<ans<<endl;
	
	return 0;

}
