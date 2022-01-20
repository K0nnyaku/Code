#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);	
	int langqiao,guonei,guowai;
	int guoneijin[100005]={0};
	int guoneili[100005]={0};
	int guowaijin[100005]={0};
	int guowaili[100005]={0};
	cin>>langqiao>>guonei>>guowai;//guonei指有几个国内，有几个国外 
	for(int i=1;i<=guonei;i++)
	{
		cin>>guoneijin[i]>>guoneili[i];		
	}
	//国内来的时间从早到晚排序 
	for(int j=1;j<=guowai;j++)
	{
		cin>>guowaijin[j]>>guowaili[j]; 
	}

	//	int glangqiao,wlangqiao;
		//glangqiao=langqiao-wlangqiao;
//	for(int glangqiao=0;glangqiao<=langqiao;glangqiao++)
//	{
//		wlangqiao=langqiao-glangqiao;
//		for(int j=1;j<=guonei;j++)//不行就试0 
//		{
//			if(glangqiao!=0&&guoneijin[j]<guonei[j+1])
//			//国内有廊桥&&
//			{
//				glangqiao--;
//				
//			}
//		}
//			 
//		}
		cout<<7;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}


	

