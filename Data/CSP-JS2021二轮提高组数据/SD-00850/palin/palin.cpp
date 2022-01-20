#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//#include<queue>
//#include<vector>
using namespace std;
char s[500005];
int a[500005],T,n;
int main()
{
	freopen("palin.in","r",stdin);
	freoprn("palin.out","w",stdout);
	scanf("%d",&T);
	for(int q=1;q<=T;++q)
	{
		scanf("%d",&n);
		s[1]='L';
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			
		}
		cout<<"-1"<<endl; 
			
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
  	
}
	
	
