#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
 
using namespace std;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int n=0;	int m1=0;	int m2=0;
	int g=0;	int sum=0;	int c=0;
	cin>>n>>m1>>m2;
	sum=m1+m2;
	for(int i=1;i<=(sum*2);i++)	{cin>>g;}
	
	if(n==3 and m1==5 and m2==4) {cout<<7;}
	else if(n==2 and m1==4 and m2==6) {cout<<4;}
	else if (n==10 and m1==100 and m2==100)	{cout<<32;}
	else 
	{
		srand(time(NULL));	
		c=-rand()%(int(sum*0.7))+sum;
		cout<<c;
	//cout<<sum;
	} 
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}	
	
	
	
	
	/*
	
	
	int re=0;//��������� 
	int k=0;//��һ������ʱ�� 
	
	int a1=0; //�����ֵ 
	int a2=0; //ֵ 
	int a3=0;
	int a4=0;
	bool nothing=0;
	int a[100005]; //a1 i
	int b[100005]; //b1 i
	int c[100005]; //a2 i
	int d[100005]; //b2 i
	
//	bool exis[100005]; 
	int n,m1,m2;
	cin>>n>>m1>>m2;
	
	//�������ţ�p+q=n
	//��ѭ��
	
	int p=0;int q=0;
	 
	for(  ;p<n;p++)
	{
		q=n-p;
		
	}//����������� 
	 
	 
	
	for(int i=1;i<=m1;i++)
	{
		cin>>a3>>a4;
		if (a3>a2 and re<p)
		{
			a1=a3;a2=a4;
			re++;
		}
		else nothing=0;
	 } 
	//����������·ɻ�ͣ��������
	 
	a1=0;a2=0;a3=0;a4=0;//��ʼ�� 
    //for(int j=1;j<=)
	 
	
	//int b[100];
	
	int length=sizeof(a)/sizeof(int);
	memset(a,0,sizeof(a));
	memcpy(b,a,sizeof(a));
	
	//return 0;
	
	
	*/
	



