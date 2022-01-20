#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1000010],T,f;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[2*n-i+1])f=1;
		}
		if(f)cout<<-1;
		else for(int i=1;i<=2*n;i++)cout<<"L";
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
