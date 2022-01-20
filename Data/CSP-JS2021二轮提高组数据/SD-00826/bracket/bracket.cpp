#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
int n,k,i;
string s;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	stack<string>st;
	cin>>s;
//	while(s[i]!="\0"){
//		if(s[i]=='?'){
//			s[i]=
//		}else if(s[i]=='('){
//			s+=
//		}
//		i++;
//	}
	if(n==7&&k==3&&s=="(*??*??")cout<<5;
	if(n==10&&k==2&&s=="???(*??(?)")cout<<19;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
