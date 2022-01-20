#include<bits/stdc++.h>
using namespace std;
int gn[100010],gw[100010],a[100010][2],b[100010][2],gn1[100010],gw1[100010];//gn[i]表示在有i个廊道时最大的飞机数 

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=0,m1=0,m2=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;++i)
	{
		cin>>a[i][0]>>a[i][1];
	}	
	for(int i=1;i<=m2;++i)
	{
		cin>>b[i][0]>>b[i][1];				
	}
	int max=0,max1=0,max2=0,max1w=0,max2w=0;
	for(int i=1,j=1;i<=n;++i)//模拟开始 
	{

		for(;j<=m1;j++)//加入飞机 
		{
			if(max1>i)
			break;	
			for(int l=a[j][0];l<=a[j][1];++l)
			{
				++gn[l];
	//			max1w=max1>gn[l]?max1w:l;//更新位置 
				max1=max1>gn[l]?max1:gn[l];//更新最大值 
			}	
				
		}
		gn1[i]=j;
	}
	for(int i=1,j=1,j1=1;i<=n;++i)//模拟开始 
	{

		for(;j<=m2;j++)//加入飞机 
		{
				if(max2>i)
			break;		
			for(int l=b[j][0];l<=b[j][1];++l)
			{
				++gw[l];
				//max2w=max2>gw[l]?max2w:l;//更新位置 
				max2=max2>gw[l]?max2:gw[l];//更新最大值 
			}

		}
		gw1[i]=j;
	}
//	for(int i=1;i<=20;i++)
//	cout<<gn[i]<<" "<<gw[i]<<endl;
	for(int i=0;i<=n;i++)
	{
		max=gn1[i]+gw1[n-i]>max?gn1[i]+gw1[n-i]:max;
		
		//cout<<gn1[i]<<" "<<gw1[i]<<endl;
	}
	

	cout<<max<<endl;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


//	
//	
//
//}
//int main()//打表ing 
//{
//	freopen("airport.in","r",stdin);
//	freopen("airport.out","w",stdout);
//	int n=0,m1=0,m2=0;
//	cin>>n>>m1>>m2;
//	for(int i=1;i<=m1;++i)
//	{
//		int j,l;
//		cin>>j>>l;
//		for(int q=1;q<=l;q++)
//		{
//			a[i][q]=1;0
//		}
//	}	
//	for(int i=1;i<=m2;++i)
//	{
//		int j,l;
//		cin>>j>>l;
//		for(int q=1;q<=l;q++)
//		{
//			b[i][q]=1;
//		}			
//	}
//	int max=0,max1=0,m=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m1;i++)
//		
//	}
//	cout<<max<<endl;	
//	fclose(stdin);
//	fclose(stdout);
//	return 0;

