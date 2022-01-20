#include<bits/stdc++.h>
using namespace std;

char ans[500010];
int T,n,N,a[500010],b[500010];
bool ppp,c[500010],ccc;

void jc(int i,int j,int k)
{//cout<<"!";
	int y=k;
		for(int q=n;q>=1;q--)
			{	
				k++;
				if(ans[n+q]==a[i]||ans[n+q]==a[j])
					if(ans[n+q]==a[i])
						ans[k]=76;
					else ans[k]=82;	
				else
					{
						ccc=1;
					}	
			}
		k=y;	
	return;	
}

void qp(int i,int j,int k)
{	//cout<<k<<"? ";
	if(c[a[i]]==1&&c[a[j]]==1)
		{//cout<<"^";
			if(k==n+2)
				{//cout<<"&";
					jc(i,j,k);
				}
			if(ccc=1)ppp=1;
			return ;
		}
	for(int p=1;p<=2;p++)
		{
			if(p==1&&c[a[i]]==0)
				{//cout<<"1";
					b[k]=a[i];
					c[a[i]]=1;
					ans[k]=76;
					i++;k++;
					qp(i,j,k);	
					if(ppp=1)return;
					else {i--;k--;}
				}
				
			if(p==2&&c[a[j]]==0)
				{//cout<<"2";
					b[k]=a[j];
					c[a[j]]=1;
					ans[k]=82;
					j--;k++;
					qp(i,j,k);
					if(ppp=1)return;
					else {j++;k--;}
				}		
		}	
}

int main()
{
	freopen(".in","r",stdin);	
	freopen(".out","w",stdout);
	
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		scanf("%d",&n);
		N=n*2;
		for(int i=1;i<=N;i++)
			scanf("%d",&a[i]);
			
		qp(1,N,1);
		
		if(ppp==1)
		for(int i=1;i<=N;i++) 
			cout<<ans;
		else cout<<"-1";				
	}
	return 0;
}
