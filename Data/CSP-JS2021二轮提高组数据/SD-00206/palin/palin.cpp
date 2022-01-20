#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
char ans[1000010],lmax[1000010];
int anslen;
int T,n,a[1000010],b[1000010],blen,alast,abegin,zflag,tot;
int search(int step)
{
	for(int ty=1;ty<=2;ty++)
	{
		if(ty==1)
		{
			
			for(int i=2*n-blen;i<=2*n;i++)
			{
				b[i-1]=b[i];
			}
			b[2*n]=a[abegin];
			blen++;
			abegin++;
			anslen++;
			ans[anslen]='L';
		}
		else if(ty==2)
		{
			for(int i=2*n-blen;i<=2*n;i++)
			{
				b[i-1]=b[i];
			}
			b[2*n]=a[alast];
			blen++;
			alast--;
			anslen++;
			ans[anslen]='R';
		}
		if(step==2*n)
		{
			/*for(int i=1;i<=2*n;i++)
			{
				cout<<b[i];
			}
			cout<<endl<<ans<<endl;*/
			int flag=1;
			for(int i=1;i<=2*n+1;i++)
			{
				if(b[i]!=b[blen+1-i])
				{
					flag=0;
					break;
				}
			}
			if(flag==0) ;
			else if(flag==1)
			{
				zflag=1;
				tot++;
				cout<<tot<<":"<<endl;
				for(int i=1;i<=2*n;i++)
				{
					cout<<b[i];
				}
				cout<<endl;
				for(int j=1;j<=2*n;j++)
				{
					cout<<ans[j];
				}
				cout<<endl;
				/*
				if(tot==1)
				{
					for(int i=1;i<=anslen;i++)
					{
						lmax[i]=ans[i];
					}
				}
				else
				{
					for(int i=1;i<=anslen;i++)
					{
						if(ans[i]<lmax[i])
						{
							for(int j=1;j<=anslen;j++)
							{
								lmax[j]=ans[j];
							}
							break;
						}
						else ;
					}
				}
				for(int i=1;i<=2*n;i++)
				{
					cout<<b[i];
				}
				cout<<endl;
				for(int i=1;i<=anslen;i++)
				{
					cout<<ans[i];
				}
				cout<<endl;*/
			}
		}
		else search(step+1);
		if(ty==1)
		{
			blen--;
			abegin--;
			anslen--;
		}
		else if(ty==2)
		{
			blen--;
			alast++;
			anslen--;
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int c=1;c<=T;c++)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		/*anslen=0;
		zflag=0;
		alast=2*n;
		blen=0;
		abegin=1;
		search(1);
		if(zflag==0)
		{
			cout<<"-1";
			cout<<endl;
		}
		else if(zflag==1)
		{
			for(int j=1;j<=2*n;j++)
			{
				cout<<lmax[j];
			}
			cout<<endl;
		}*/
		cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
