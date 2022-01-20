#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int a,b,sum=0;
	cin>>a>>b;
	string s;
	cin>>s;
	for(int i=0;i<a;i++){
		if(s[i]=='?') sum++;
	}
	cout<<sum*3+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

