#include <iostream> 
using namespace std;
int a1[100001],b1[100001],a2[100001],b2[100001];
int t1[100001]={},t2[100001]={},t3[100001]={},t4[100001]={};
int tf1[100001],tf2[100001],l1[100001],l2[100001];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,sum=100000000,max1=0,min1=100000000;
	int max2=0,min2=100000000,w1=0,w2=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a1[i]>>b1[i];
		if(b1[i]>max1)
			max1=b1[i];
		if(a1[i]<min1)
			min1=a1[i];
		t1[a1[i]]++;tf1[a1[i]]=i;
		t2[b1[i]]++;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>a2[i]>>b2[i];
		if(b2[i]>max2)
			max2=b2[i];
		if(a2[i]<min2)
			min2=a2[i];
		t3[a2[i]]++;tf2[a2[i]]=i;
		t4[b2[i]]++;
	}
	int sum1=0,sum2=0;
	int i=0;
	while(i<=n)
	{
		int nei=0;
		for(int j=min1;j<=max1;j++)
		{
			if(nei+t1[j]<=i)
			{
				nei=nei+t1[j];
			}
			else
			{
				sum1++;
				nei=i;
				t2[b1[tf1[j]]]--;
				l1[w1+1]=b1[tf1[j]];
				w1++;
			}
			nei=nei-t2[j];
		}
		int nei1=0;
		for(int j=min2;j<=max2;j++)
		{
			if(nei1+t3[j]<=n-i)
			{
				nei1=nei1+t3[j];
			}
			else
			{
				sum2++;
				nei1=n-i;
				t4[b2[tf2[j]]]--;
				l2[w2+1]=b2[tf2[j]];
				w2++;
			}
			nei1=nei1-t4[j];
		}
		if(sum1+sum2<sum)
		{
			sum=sum1+sum2;
		}
		sum1=0;
		sum2=0;
		for(int j=1;j<=w1;j++)
		{
			t2[l1[j]]++;
		}
		for(int j=1;j<=w2;j++)
		{
			t4[l2[j]]++;
		}
		i++;
	}
	cout<<m1+m2-sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
