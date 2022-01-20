#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define SIZE 100000
int ttt,n,aa[SIZE],ans[SIZE]={0},bb[SIZE]={0},l,r;
int work1()
{
	l=1;r=2*n;
	for(int i=1;i<=2*n;i++)
	{
		if(ans[i]==0){bb[i]=aa[l];l++;continue;}
		else {bb[i]=aa[r];r--;}
	}
	
	for(int i=1;i<=n;i++)
	if(bb[i]==bb[2*n+1-i]) ;
	else return 0;
	return 1;
}
void work2()
{
	ans[2*n-1]++;
	if(ans[2*n-1]==2)
	for(int i=2*n-1;i>=1;i--)
	{
		if(ans[i]==2)  
		{
		ans[i]=0;ans[i-1]++;
		if(ans[i-1]==1)  break;
		}
	}
}
void work()
{
	for(long long i=1;i<=pow(2,2*n-1);i++)
	{
		if(work1()) {ans[0]=1;return;}
		else work2();
	}
	ans[0]=0;return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>ttt;
	for(int i=1;i<=ttt;i++)
	{
		cin>>n;l=1;r=2*n;
		for(int j=0;j<=2*n;j++)
		{
			ans[j]=0;
		}
		for(int j=1;j<=2*n;j++)
		{
			cin>>aa[j];
		
		}
		work();
		if(ans[0]==0) cout<<"-1"<<endl;
		else
		for(int j=1;j<=2*n;j++)
		if(ans[i])  cout<<"R";
		else cout<<"L";
		cout<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
