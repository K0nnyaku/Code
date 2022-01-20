#include<bits/stdc++.h>
using namespace std;
char a[20005];
int sum=0;
int n,k;
int ans;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
    	if(a[i]='?') sum++;
    }
    ans=pow(2,sum);
    cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

