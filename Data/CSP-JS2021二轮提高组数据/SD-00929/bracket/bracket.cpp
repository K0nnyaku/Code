#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
bool a[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='?'){
			a[i]=1;	
		}
	}
}
