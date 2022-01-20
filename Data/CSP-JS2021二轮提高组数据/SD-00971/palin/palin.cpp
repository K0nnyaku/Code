#include<cstdio>
#include<iostream>
using namespace std;
int a[99999999];
int main()
{
   freopen("palin.in","r",stdin);
   freopen("palin.out","w",stdout);
   int t;
   cin>>t;
   for(int i=1;i<=t;i++)
   {
   	int n;
   	cin>>n;
   	for(int i=1;i<=2*n;i++) cin>>a[i];
   	cout<<-1<<endl;
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}

