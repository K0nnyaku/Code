#include<iostream>
#include<cstdio>
using namespace std;
int t,mid_n,mark,check_num,way_num,d;
int num[100005];
int way[100005];
int check[100005];
int difficult_code(int left,int right)
{
	if(left==right)
	{
		mark=1;
		way_num++;
		way[way_num]=1;
		return 0;
	}
	if(check[num[left]]==0)
	{
		check_num++;
		check[num[left]]=check_num;
		way_num++;
		way[way_num]=1;
		d++;
		difficult_code(left+1,right);
		if(mark==1)
		{
			return 0;
		}
		d--;
		way_num--;
		check[num[left]]=0;
		check_num--;
	}
	else
	{
		if(d>=mid_n)
		{
			if(check[num[left]]==2*mid_n-d)
			{	
				way_num++;
				way[way_num]=1;
				d++;
				difficult_code(left+1,right);
				if(mark==1)
				{
					return 0;
				}
				d--;
				way_num--;
			}
		}
	}
	if(check[num[right]]==0)
	{
		check_num++;
		check[num[right]]=check_num;
		way_num++;
		way[way_num]=2;
		d++;
		difficult_code(left,right-1);
		if(mark==1)
		{
			return 0;
		}
		d--;
		way_num--;
		check[num[right]]=0;
		check_num--;
	}
	else
	{
		if(d>=mid_n)
		{
			if(check[num[right]]==2*mid_n-d)
			{	
				way_num++;
				way[way_num]=2;
				d++;
				difficult_code(left,right-1);
				if(mark==1)
				{
					return 0;
				}
				d--;
				way_num--;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>mid_n;
		for(int j=1;j<=2*mid_n;j++)
		{
			cin>>num[j];
		}
		mark=0;
		check_num=0;
		way_num=0;
		d=0;
		for(int j=1;j<=mid_n;j++)
		{
			check[j]=0;
		}
		difficult_code(1,2*mid_n);
		if(mark==0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(int j=1;j<=way_num;j++)
		{
			if(way[j]==1)
			{
				cout<<"L";
			}
			if(way[j]==2)
			{
				cout<<"R";
			}
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
