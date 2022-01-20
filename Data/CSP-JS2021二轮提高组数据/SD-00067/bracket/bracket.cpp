#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	string s;
	cin>>s;
	int x=s.length()-1;
	cout<<x*x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

