#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,ans,l;
char s[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);l=strlen(s+1);
	ans=n/2+1;
	printf("%d",ans);

	return 0;
}
