#include<iostream> 
#include<cstdio>
using namespace std;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;//n������������m�ǹ��ں���������k�ǹ��ʺ������� 
	int ans[n+1];//��¼ÿһ�ַ��䷽������ͨ���ķɻ������� 
	int a[m+1][2],b[k+1][2];//��������ÿ���������� 
	int mtot=0,ktot=n;//mtot�ǹ������Ÿ�������ʼΪ0��mtot�ǹ������Ÿ�������ʼΪn�������Ȱ����ŷָ������� 
	for(int i=1;i<=m;i++) 
	{
		cin>>a[i][1]>>a[i][2];//������ں������ 
	}
	for(int i=1;i<=k;i++) 
	{
		cin>>b[i][1]>>b[i][2];//������ʺ������ 
	}
	for(int i=1;i<=n;i++)//ѭ��i�Σ����������ȫ��һ�� 
	{
	    for(int i=1;i<=m;i++) //�жϹ��ں��� 
	    {
		    if(mtot==0)//������������� 
		    {
			    mtot++;//��һ����� 
			    continue;
		    }
		    if(mtot>=m) //��������������ڵ��ڷɻ����� 
		    {
			    ans[i]+=m;
			    mtot++; 
			    continue;
		    }
		    for(int j=1;j<=m;j++)
		    {
			    if(j>mtot)
			    {
			        for(int l=1;l<=mtot;l++)
			        {
			    	    if(a[l][2]<=a[j][1])//�������ʱ������뿪ʱ��2
			    	    {
			    	        ans[i]++;
			    		    continue; 
			    	    }
			        }
			   }
			   if(j<=mtot)
			   {
				    ans[i]++;
				    continue;
			   }
		    }
	    }
		mtot++;	
	}
	for(int i=1;i<=n;i++)//ѭ��i�Σ����������ȫ��һ�� 
	{
	    for(int i=1;i<=k;i++) //�жϹ��ʺ��� 
	    {
		    if(ktot==0)//������������� 
		    {
			    ktot++;//��һ����� 
			    continue; 
		    }
		    if(ktot>=k) //��������������ڵ��ڷɻ����� 
		    {
			    ans[i]+=k;
			    ktot++; 
			    continue;
		    }
		    for(int j=1;j<=k;j++)
		    {
			    if(j>ktot)
			    {
			        for(int l=1;l<=ktot;l++)
			        {
			    	    if(b[l][2]<=b[j][1])//�������ʱ������뿪ʱ��
			    	    {
			    	        ans[i]++;
			    		    continue; 
			    	    }
			        }
			   }
			   if(j<=ktot)
			   {
				    ans[i]++;
				    continue;
			   }
		    }
	    }
		ktot++;	
	}
	for(int i=1;i<n+1;i++)
	{
		if(ans[i]>=ans[i+1])
		{
			int temp=0;
			temp=ans[i];
			ans[i]=ans[i+1];
			ans[i+1]=temp;
		}
	}
	cout<<ans[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
