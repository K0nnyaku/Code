#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct arr
{
	bool plane;
	int cha;
	bool nei;
	bool used;
};
arr t[100000010];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int n,a,b;
	cin >> n >> a >> b;
	int tmax=0;
	for(int i=0;i<a+b;i++)
	{
		int t1,t2;
		cin >> t1 >> t2;
		if(t2>tmax)
		{
			tmax=t2;
		}
		t[t1].plane=true;
		t[t2].plane=true;
		t[t1].cha=t2-t1;
		t[t2].cha=t1-t2;
		if(i<a)
		{
			t[t1].nei=true;
			t[t2].nei=true;
		}
		else
		{
			t[t1].nei=false;
			t[t2].nei=false;
		}
	}
	
	int allmax=0;
	for(int i=0;i<=n;i++)
	{
		int neib=i;
		int waib=n-i;
		int neiused=0;
		int waiused=0;
		for(int j=1;j<=tmax;j++)
		{
			if(t[j].plane==false)
			{
				continue;
			}
			if(t[j].nei==true)
			{
				if(t[j].cha>0)
				{
					if(neib>0)
					{
						neib--;
						t[j].used=true;
					}
				}
				if(t[j].cha<0)
				{
					if((neib+1<=i)&&(t[j+t[j].cha].used==true))
					{
						neib++;
						neiused++;
						t[j+t[j].cha].used=false;
					}
				}
			}
			else
			{
				if(t[j].cha>0)
				{
					if(waib>0)
					{
						waib--;
						t[j].used=true;
					}
				}
				if(t[j].cha<0)
				{
					if((waib+1<=n-i)&&(t[j+t[j].cha].used==true))
					{
						waib++;
						waiused++;
						t[j+t[j].cha].used=false;
					}
				}
			}
		} 
		int allused=neiused+waiused;
		if(allused>allmax)
		{
			allmax=allused;
		}
	}
	cout << allmax << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
