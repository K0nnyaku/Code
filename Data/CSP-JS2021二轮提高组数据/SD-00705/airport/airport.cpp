#include<iostream>
#include<cstdio>
#include<string>
#include<bits/stdc++.h>
using namespace std;

long long n,guo,inter;
int ansguo,ansinter;
int ans;
int moren;//��0��ʼ��
int moreni;
const int N=100000+5;
int gu[N];
int in[N];
long long zou;
long long zous;
bool pang(int x,int y,long long q) //x����ʱ�� y�ߵ�ʱ�� q���ŵ������� 
{
	if(q==0) return false;
	if(q>=guo) return true;
	if(q<guo)
	{
		if(x>moren) 
		{
			moren=y;
		return true;
		}
		if(x<=moren)
		{
			q--;
			if(q<0) return false;
			else return true; 
		}
	}
	
}
bool pani(int x,int y,long long q) //x����ʱ�� y�ߵ�ʱ�� q���ŵ������� 
{
	if(q==0) return false;
	if(q>=inter) return true;
	if(q<inter)
	{
		if(x>moreni) 
		{
			moreni=y;
		return true;
		}
		if(x<=moreni)
		{
			q--;
			if(q<0) return false;
			else return true; 
		}
	}
	
}
int main()
{
	freopen("airport.in","r",stdin);
 	freopen("airport.out","w",stdout);
 long long  min=100000000+5; long long mins=100000000+5;
    scanf("%lld%lld%lld",&n,&guo,&inter);
    	while(guo) //����������� 
		{
			int i=-1; i+=2; int q; q=0; q+=2;  
			  cin>>gu[i]>>gu[q];
			  guo--;
		}
		
		while(inter) //����������� 
		{
			int i=-1; i+=2; int q; q=0; q+=2;  
			cin>>in[i]>>in[q];
			inter--;
		}
	for(int i=0; i<=n; i++) //ö�ٹ������� 
   	{
    		inter=n-i;//��������
    	while(guo)
    	{
    		for(int i=1; i<=n; i+=2) //�����ȵ�������ķɻ� 
    		{
    			if(min>gu[i])
    			{
    				min=gu[i];
				}
				gu[i]==100000000+5;
				zou=gu[i+1];
			}
			if(pang(min,zou,i)==true)
					ansguo++;
    		guo--;
		}
		while(inter)
    	{
    		for(int i=1; i<=n; i+=2) //�����ȵ�������ķɻ� 
    		{
    			if(mins>in[i])
    			{
    				mins=in[i];
				}
				in[i]==100000000+5;
				zous=in[i+1];
			}
			if(pani(mins,zous,inter)==true)
					ansinter++;
    		inter--;
		}
		ans=ansguo+ansinter;    
		if(ans<ansguo+ansinter) //�ҵ����ŷ��� 
			ans=ansguo+ansinter;
	}
	printf("%d",ans+1);
fclose(stdin);
fclose(stdout);
return 0;
}


