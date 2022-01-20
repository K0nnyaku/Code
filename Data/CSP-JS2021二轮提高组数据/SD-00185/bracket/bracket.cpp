#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,k;
int main()
{   freopen("brack.in","r",stdin);
    freopen("brack.out","w",stdout);
    int l;
    char s[10000];
	cin>>n>>k;
    scanf("%s",s);
    l=strlen(s);
    cout<<(n+k)/2;
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
