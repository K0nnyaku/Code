//dfs����,2^n 
//���Լ�֦������������������ˣ����Ҳ��ǻ��ģ�ֱ�ӷ��ء�
//���ʣ����Ĵ���ź�һ�� 
#include<bits/stdc++.h>
using namespace std;
int T,n,l,r,flag;
int a[10100],b[10100],vis[10100];
bool check()//����Ƿ��ǻ��� 
{
	int temp1=l,temp2=r;
	for(int i=1;i<=2*n;i++)
	{
		if(vis[i]==1)//L
		{
			b[i]=a[l];
			l++;
		} 
		else//R
		{
			b[i]=a[r];
			r--;
		}
	}
	l=temp1,r=temp2;
	int ll=1,rr=2*n;
	while(ll<rr)
	{
		if(b[ll]==b[rr])
		{
			ll++;
			rr--;
		}
		else return 0;
	}
	return 1;
}
void print()
{
	for(int i=1;i<=2*n;i++)
	{
		if(vis[i]==1)
		{
			printf("L");
		} 
		else printf("R");
	} 
	cout<<endl;
}
void dfs(int x)//�ڼ��� 
{
	if(flag==1)//���� 
	return ;
	if(x==2*n+1)
	{
		if(check())
		{
			print();
			flag=1;//��־ 
		}
		return ;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	
	vis[x]=2;
	dfs(x+1);
	vis[x]=0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		l=1,r=2*n,flag=0;
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1);
		if(!flag)
		printf("-1\n");
	}
	return 0;
}
