//n1:国内机场的分配廊桥数目
//n2:国际机场的分配廊桥数目
//sum1:记录此时国内的廊桥的正在使用数
//sum2:记录此时国际的廊桥的正在使用数
//num:总共多少架飞机 
#include<iostream>
//#include<bits/stdc++.h>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 

using namespace std;
long long n , m1 , m2,k = 1,q = 1,mb = 0;
long long a = 1 , b = 1 , c = 1 , d = 1;
long long a1[1000001] , a2[1000001] , b1[1000001] , b2[1000001] , cnt1[1000001] , cnt2[1000001] , hh[1000001];  
int  main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long n1 , n2 , sum1 = 0 , sum2 = 0 , num1 = 0,num2 = 0;
	scanf("%lld%lld%lld", &n , &m1 , &m2);
	for(long long i = 1 ; i <= m1 ; i++)//国内 
	{
		cin>>a1[i]>>a2[i];
		if(a2[i] > k)
			k = a2[i];
	}
	for(long long i = 1 ; i <= m2 ; i++)//国际 
	{
		cin>>b1[i]>>b2[i];
		if(b2[i] > q)
			q = b2[i];
	}
//输入-------------------------------------------------------------------------	
	n1 = 0 ;
	n2= n; 
	for(long long z = 1 ; z <= n + 1 ; z ++)//总循环 
	{
		sum1 = 0;
		sum2 = 0;
		for(long long i = 1 ; i <= k ; i ++)//国内 
		{
			if(n1 == 0) break;//优化 
			if(i == a2[a])
			{
				a++;
				if(sum1 > 0)
					sum1 --;
			}
			if(i == a1[b])
			{
				b++;	
				if(sum1 < n1)
				{
					sum1 ++;
					num1 ++;
				}
			}
		}
		a = 1;
		b = 1;
		hh[z] += num1;
		num1 = 0 ;
		for(long long j = 1 ; j <= q ; j ++)//国际 
		{
			if(n2 == 0) break;//优化 
			if(j == b2[c])
			{
				c++;
				if(sum2 > 0)
					sum2 --;
			}
			if(j == b1[d])
			{
				d++;
				
				if(sum2 < n2)
				{
					sum2 ++;
					num2 ++;						
				}
			}
		}
		c = 1;
		d = 1;
		hh[z] += num2;
		num2 = 0 ;
		n1++;
		n2--;	
	}
	for(long long i = 1 ; i <= n + 1 ; i ++)
	{
		if(hh[i] < hh[i+1])
			hh[100001] = hh[i+1];
	}
	for(long long j = 1 ; j <= m1  ; j ++ )
	{
		if(a1[j]>a1[j +1])
		{
			mb ++;
		}
		
	}
	cout<<hh[100001]+mb-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

