#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
string s;

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(s[0]!='(')
		s[0]='(';
	if(s[n-1]!=')')
		s[n-1]=')';
	bool flag=false;
	for(int i=0;i<n;i++){
		if(s[i]=='?')
			flag=true;
	}
	if(flag==false)
	{
		cout<<0<<endl;
		return 0;
	}
	return 0;
}



	
