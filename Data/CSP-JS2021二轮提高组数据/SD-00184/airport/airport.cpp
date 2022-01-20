#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct fj
{
	int t,q;
}fj[2][100010];
int amax;
int tot;
int num;
int lq[200050];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int lqs,gns,gjs;
	int i,j,k;
	int nlq,jlq;
	scanf("%d%d%d",&lqs,&gns,&gjs);
	for(i=1;i<=gns;i++)
	{
		scanf("%d%d",&fj[1][i].t,&fj[1][i].q);
	}
	for(i=1;i<=gjs;i++)
	{
		scanf("%d%d",&fj[2][i].t,&fj[2][i].q);
	}
	for(i=0;i<=lqs;i++)
	{
//		cout<<endl<<endl<<endl<<i<<endl;
		tot=0;
		nlq=i;
		jlq=lqs-i;
		if(nlq!=0)
		{
			num=0;
			for(j=1;j<=gns;j++)
			{
//					cout<<i<<" "<<num<<endl;
				for(k=1;k<=num;k++)
				{
//					cout<<lq[k]<<endl;
					if(fj[1][j].t>lq[k]&&nlq!=i&&lq[k]!=0) 
					{
						lq[k]=100000001;
						nlq++;
//				cout<<"nlq.1 "<<nlq<<endl; 
						sort(lq,lq+num+1);
						num--;
					}
				}
//				cout<<"nlq.2 "<<nlq<<endl;
				if(nlq!=0)
				{
					lq[num]=fj[1][j].q;
					tot++;
					num++;
					nlq--;
				}
			}
		}
		if(jlq!=0)
		{
			num=0;
			for(j=1;j<=gjs;j++)
			{
				for(k=1;k<=num;k++)
				{
					if(fj[2][j].t>lq[k]&&jlq!=lqs-i&&lq[k]!=0)
					{
						lq[k]=100000001;
						jlq++;
						sort(lq,lq+num+1);
						num--;
					}
				}
				if(jlq!=0)
				{
					lq[num]=fj[2][j].q;
					tot++;
					num++;
					jlq--;
				}
			}
		}
		if(tot>amax)
		{
			amax=tot;
		}
	}
	cout<<amax;
	return 0;
}
