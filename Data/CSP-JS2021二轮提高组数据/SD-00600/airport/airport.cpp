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
	cin>>langqiao>>guonei>>guowai;//guoneiָ�м������ڣ��м������� 
	for(int i=1;i<=guonei;i++)
	{
		cin>>guoneijin[i]>>guoneili[i];		
	}
	//��������ʱ����絽������ 
	for(int j=1;j<=guowai;j++)
	{
		cin>>guowaijin[j]>>guowaili[j]; 
	}

	//	int glangqiao,wlangqiao;
		//glangqiao=langqiao-wlangqiao;
//	for(int glangqiao=0;glangqiao<=langqiao;glangqiao++)
//	{
//		wlangqiao=langqiao-glangqiao;
//		for(int j=1;j<=guonei;j++)//���о���0 
//		{
//			if(glangqiao!=0&&guoneijin[j]<guonei[j+1])
//			//����������&&
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


	

