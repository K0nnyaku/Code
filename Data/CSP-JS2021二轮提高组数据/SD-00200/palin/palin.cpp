#include <iostream>
using namespace std;
const int size = 1000001;
int T,n,key,l,r,len;
long a[size],b[size];long long cz;
int main()
{
	freopen("palin1.in","r",stdin);
//	freopen("palin.out","w",stdout);
	cin >> T;
	for(int k=1;k<=T;k++)
	{
		cin >> n;
		for(int i=1;i<=2*n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			if(a[i]!=a[2*n-i])
			{
				key=1;break;
			}
		if(key)
		{
			if(a[1]==a[2*n])
			{
				cout << "-1";continue;
			}
			//正儿八经 不会
			int flag=1;
			while(flag==1)
			{
				l=1;r=2*n;len=1;flag=0;
				for(int i=2*n-1;i>=0;i--)
				{
					if(cz & (1ull << i)==1)//R
					{
						b[len]=a[r];
						len++;
						r--;
					}
					else//L
					{
						b[len]=a[l];
						len++;
						l++;
					}
				}
				for(int i=1;i<=n;i++)
				{
					if(b[i]!=b[2*n-i])
					{
						cz++;key++;flag=1;
						if(key>=(1ull<<(2*n)))
						{
							cout << "-1" << endl;
							flag=2;
						}
						break;
					}
				}
			}
			if(flag==0)
			{
					for(int i=2*n-1;i>=0;i--)
				{
					if(cz & (1ull << i)==1)
						cout << "R";
					else
						cout << "L";
				}
				cout << endl;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
				cout << "LL";
			cout << endl;
		} 
	}
	return 0;
}
