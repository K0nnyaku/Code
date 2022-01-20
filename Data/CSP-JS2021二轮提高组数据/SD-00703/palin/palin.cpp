#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int T,n,a[110],b[110],l,r;
string str,ans;
void s()
{
	for(int i=0;i<=2*n-1;i++)
	{
		if(str[i]=='L')
		{
			b[i+1]=a[l];
			l++;
		}
		else
		{
			b[i+1]=a[r];
			r--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=b[2*n-i+1])
		{
			return;
		}
	}
	if(ans==""||str<ans)
	{
		ans=str;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int ij=1;ij<=T;ij++)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		l=1,r=2*n;
		for(int i=1;i<=2*n;i++)
		{
			str+="L";
		}
		for(int i=1;i<=2*n;i++)
		{
			s();
			
			for(int i=str.length()-1;i>=0;i--)
			{
				if(str[i]=='L')
				{
					str[i]='R';
					break;
				}
				else
				{
					str[i]='L';
				}
			}
		}
		if(ans=="")
			{
				cout<<"-1";
			}
			else
			{
				cout<<str;
			}
			cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
