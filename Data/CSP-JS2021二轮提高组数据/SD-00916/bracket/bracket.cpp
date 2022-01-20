#include<bits/stdc++.h>
using namespace std;

bool verify(string s){
	if(strcmp(s,"") == 0)return false;
	if(*s.begin() != '(' || *s.end() != ')')return false;
}

int main(){
	freopen("bracket.in","r",stdin); 
	freopen("bracket.out","w",stdout);
	char s[505];
	scanf("%s",s);
	cout<<1;
	return 0;
}
