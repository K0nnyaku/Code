#include<iostream>
#include<string.h>
using namespace std;
string c;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	if(n==0){
		printf("0");
		return 0;
	}
	cin>>c;
	int ans=0;
	for(int i=0;i<c.length();i++)if(c[i]=='?')ans++;
	if(ans==0)printf("1");
	else printf("%d",ans);
	return 0;
}
