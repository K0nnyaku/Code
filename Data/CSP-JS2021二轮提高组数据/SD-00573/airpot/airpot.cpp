#include <iostream>
#include <ctudio>
using namespace std;
int n,m1,m2,maxx;
int natina[100005],natouta[100005];
int natinb[100005],natoutb[100005];
int ntin[100005],ntout[100005];
int na[100005],nb[100005];
int main() 
{
	freout("airpot.in",r,stdin);
	freout("airpot.out",w,stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>natina[i]>>natinb[i];
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>natouta[i]>>natoutb[i];
	}
	//���� 
	for(int i=1;i<=n;i++)
	{
		
		ntin[i]+=i;//ǰi��ȫ��ͣ��
		int mint=100000005;//�����뿪��ʱ�� 
		int h=1;//��ͣ��ȥ�� 
		for(int j=1;j<=i;j++)
		{
			mint=min(mint,natinb[j]);
			na[h]=natinb[j];
			h++;
		}
		
		for(int j=i+1;j<=m1;j++)
		{
			if(mint<natina[j])
			{
				mint=100000005;
				na[h]=natinb[j];
				for(int k=h;k>h-i;k--)
				{
					mint=min(mint,natinb[k]);
				}
				h++;
				ntin[i]++;
			}
		}
		//��m1-i��
		
	}//���� 
	
	for(int i=1;i<=n;i++)
	{
		
		ntout[i]+=i;//ǰi��ȫ��ͣ��
		int mint=100000005;//�����뿪��ʱ�� 
		int h=1;//��ͣ��ȥ�� 
		for(int j=1;j<=i;j++)
		{
			mint=min(mint,natoutb[j]);
			nb[h]=natoutb[j];
			h++;
		}
		
		for(int j=i+1;j<=m2;j++)
		{
			if(mint<natouta[j])
			{
				mint=100000005;
				nb[h]=natoutb[j];
				for(int k=h;k>h-i;k--)
				{
					mint=min(mint,natoutb[k]);
				}
				h++;
				ntout[i]++;
			}
		}
		//��m1-i��
		
	}//�� 
	for(int i=0;i<=n;i++)
		maxx=max(maxx,ntin[i]+ntout[n-i]);
	cout<<maxx;
	return 0;
}



