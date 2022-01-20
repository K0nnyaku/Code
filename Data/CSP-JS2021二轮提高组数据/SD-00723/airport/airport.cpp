#include<iostream>
#include<cstdio>
#include<cstring>
const int MAX = 10001 ; 
using namespace std;
int n , m1 , m2 ;
int sum[MAX] ;
int a[MAX][2] ;
int c[MAX][2] ;
int air(int i , int j , int n ,int m)
{
	int o = i , p = j  , q = 0 , w = 0 ;
	int s1 = 0, s2 = 0 ;
	bool flag = 1 ;
	while(q <= n) 
	{ 
		if(o > 0) 
		{
			o -- ;
			q ++ ;
			s1++ ;
		}
		else if(i == 0 )
			break ;
		else 
		{
			for(int k = 0 ; k < q ; k ++)
				if(a[k][1] < a[q][0])
				{
					q++ ;
					s1 ++ ;
					flag = 0 ;
					break ;
				}
			if(flag == 0)
				q++ ;
			flag = 1 ;
		}
	}
	while(w <= m) 
	{
		if(p > 0 )
		{
			p -- ;
			w ++ ;	
			s2++ ;
		}
		else if(j == 0 )
			break ;
		else
		{
			for(int k = 0 ; k < w ; k++)
				if(c[k][2] < c[w][1])
				{
					w ++ ;
					s2 ++ ;
					flag = 1;
					break ;
				}
			if(flag == 0)
				q++ ; 
			flag = 1 ;
		}
}
	sum[i] = s1 +s2 ; 

	
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int b = 0 ;
	cin >> n >> m1 >> m2 ;
	for(int i = 0 ; i < m1 ; i++ )
	{
		cin >> a[i][0] >>a[i][1];
	}
	for(int f = 0 ; f < m2 ; f++ )
	{
		cin >>c[f][0]>>c[f][1] ;
	}
	for(int y = 0 ; y <= n ; y ++)
		air(y , n-y , m1 , m2);
	for(int l = 0; l< n+1 ; l++)
	{
		cout << sum[l]<<" ";
		if(sum[l] > b)
			b = sum[l];	
	}
	cout << b ;
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}


