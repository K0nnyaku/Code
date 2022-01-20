#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000010],b[1000010];
int d=1;
int c[500010];//操作 
int top;
int s[500010];//之前有没有过 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n;
	int ti,i;
	int j=0;
	cin>>t;
	for(ti=1;ti<=t;ti++)
	{
		cin>>n;
		int head=1;
		int last=n;
		for(i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<=2*n-1;i++)
		{
			if(i<=n)//前半截 
			{
				if(s[a[head]]!=1)//没有过 
				{
					b[d]=a[head];//shuru
					d++;
					s[a[head]]=1;//xianzaiyoule
					head++;
					top++;
				}
				else//youguo
				{
					if(c[top]==1)//两种操作都做过
					{
						c[top]=0;
						top--;//退位 
					}
					else
					{
						if(s[a[last]]!=1)
						{
							c[top]=1;
							b[d]=a[last];
							s[a[last]]=1;
							d++;
							last--;	
						}
						else
						{
							c[top]=0;
							top--;
						}
					}
				}
				continue;
			}
			else//后半截 
			{
				if(n*2-d+1==a[head])//回文 
				{
					b[d]=a[head];
					d++;
					s[a[head]]=1;
					top++;
					head++;
				}
				else
				{
					if(s[a[last]]!=1)
					{
						c[top]=1;
						b[d]=a[last];
						s[a[last]]=1;
						d++;
						last--;	
					}
					else
					{
						c[top]=0;
						top--;
					}
				}
				continue;
			}
			j=1;
			cout<<"-1"<<endl;
			break; 
		}
		if(j==1)
		{
			continue;
		}
		for(i=1;i<=n*2;i++)
		{
			if(c[i]==0)
			{
				cout<<"L";
			}
			else
			{
				cout<<"R";
			}
		}
		cout<<endl;
	}
	return 0;
}
