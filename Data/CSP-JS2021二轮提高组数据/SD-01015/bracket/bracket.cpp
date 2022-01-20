#include<bits/stdc++.h>
using namespace std;
long long ans=1;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	string str;
	cin>>str;
	int sum;
	for(int i=0;i<n;i++){
		if(str[i]=='?') sum++;
	} 
	for(int i=1;i<=sum;i++){
		ans=ans*2%1000000007;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
