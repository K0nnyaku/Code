#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>

using namespace std;
int n,k;
char  a[105];
int cnt=0;
int s;
int main (){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a[i]=='(';
		a[i]==')';
		a[i]=='*';
		a[i]=='?';
	}
	for(int i=1;i>=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]=='?'){
			a[i]=='('==')'=='*';
			
		}
	}
	for(int i=1;i<=n;i++){
			if(a[i]=='('){
				cnt++;
			}
			else if(a[i]==')'){
				cnt++;
			}
			else if(a[i]=='*'){
				cnt++;
			}
			else if(a[i]=='('&&a[i+1]==')'){
				cnt++;
			}
			else if(a[i]=='('&&a[i+n]=='*'&&a[i+1+n]==')'){
				cnt++;
			}
			else{
				cnt++;
			}		
	}

	
	cout<<cnt;
	return 0;
}
