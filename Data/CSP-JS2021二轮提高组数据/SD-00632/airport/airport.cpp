#include<bits/stdc++.h>
//#include<queue>
#define ll long long 
using namespace std;
//priority_queue<long long,vector<long long>,greater<long long> >m;
//priority_queue<long long,vector<long long>,greater<long long> >m3;
ll n,m1,m2,sum=0,maxstay=0,chempty,foempty,chap=0,foap=0,num=0;//,minn=0
ll ch[2][50000],fo[2][50000],nowstay[2][1]={0,0};
//ll mins[2][1]={100000,100000};
int main()
{
	//freopen("airport.in","r",stdin);
	//freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1+m2;i++)
	{
		if(i<m1) cin>>ch[0][i]>>ch[1][i];
		else cin>>fo[0][i]>>fo[1][i];
	}
	for(int i=0;i<=n;i++)
	{
		//mins[0][0]=100000;mins[1][0]=100000;
		chempty=i;foempty=n-i;
		chap=i;foap=n-i;
		for(int j=0;j<m1;j++)
		{
			/*for(int i1=0;i1<m1;i1++)
			{
				if(ch[0][i1]<mins[0][0])
				{
					mins[0][0]=ch[0][i1];
					mins[1][0]=ch[1][i1];
				}
			}
			for(int i2=0;i2<m1;i2++)
			{
				if(ch[0][i2]==mins[0][0])ch[0][i2]=9999999;
			}
				if(chempty>=1){  =ch[1][i]
			}*/
			if(chap==0) break;
			else{
				if(chempty>=1)
				{
				
					nowstay[0][0]=ch[0][j];nowstay[1][0]=ch[1][j];
					sum++;
					chempty--;	
				}
				else
				{
					if(nowstay[1][0]<=ch[0][j])
					{	
						nowstay[0][0]=ch[0][j];nowstay[1][0]=ch[1][j];
						sum++;
					}
				}
			}
			//mins[0][0]=ch[0][j+1];mins[1][0]=ch[1][j+1];
		}
		nowstay[0][0]=0;nowstay[1][0]=0;
		//mins[0][0]=100000;mins[1][0]=100000;
		for(int t=0;t<m2;t++)
		{
			/*for(int i1=0;i1<m2;i1++)
			{
				if(fo[0][i1]<mins[0][0])
				{
					mins[0][0]=fo[0][i1];
					mins[1][0]=fo[1][i1];
				}
			}
			for(int i2=0;i2<m2;i2++)
			{
				if(fo[0][i2]==mins[0][0])fo[0][i2]=9999999;
			}*/
			if(t==0)nowstay[0][0]=fo[0][t];nowstay[1][0]=fo[1][t];
			if(foap==0) break;
			else {
				if(foempty>=1){
					if(nowstay[1][0]<fo[1][t])
					{
						sum++;
						foempty--;
					}
					else
					{
						nowstay[0][0]=fo[0][t];nowstay[1][0]=fo[1][t];
						sum++;
						foempty--;
					}
					
				}
				else
				{
					if(nowstay[1][0]<=fo[0][t])
					{	
						nowstay[0][0]=fo[0][t];nowstay[1][0]=fo[1][t];
						sum++;
					}
				}
			}
		}
		if(maxstay<=sum){
			maxstay=sum;
			sum=0;
		}
		else sum=0;
	}
	cout<<maxstay;
	return 0;
} 
