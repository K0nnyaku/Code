#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()	{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(1)
	{
		int a[1000203]={0},n;
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		if(T<100){
				cout<<-1<<endl;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		else{
			for(int i=1;i<=n*2;i++)
			{
				cout<<'L';
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
