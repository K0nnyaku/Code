#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
string s;
int cnt=0;
long long mod=1e9+7;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;++i){
		if(s[i]=='?')cnt++;
	}
	int ans=(m%mod)*(cnt%mod)%mod;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
