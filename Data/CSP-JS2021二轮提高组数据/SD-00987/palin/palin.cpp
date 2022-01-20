#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100010],b[100100],ans[100100];
int pos[100010];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		int flag=0;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
			
		}
		
		cout<<"-1"<<endl;
		
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}/*if(!pos[a[i]])pos[a[i]]=i;
			else if((pos[a[i]]-i)%2==1)flag=1;*/
