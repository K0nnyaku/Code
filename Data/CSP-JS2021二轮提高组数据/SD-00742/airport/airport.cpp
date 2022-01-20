#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m1, m2;
struct node1{
	int a, b;
}s1[N];
struct node2{
	int a, b;
}s2[N];
int ans = 0;
int last[N];

bool cmp1(node1 x, node1 y)
{
	return x.a < y.a;
}

bool cmp2(node2 x, node2 y)
{
	return x.a < y.a;
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i ++)
		scanf("%d %d", &s1[i].a, &s1[i].b);
	for(int i = 1; i <= m2; i ++)
		scanf("%d %d", &s2[i].a, &s2[i].b);
	
	sort(s1 + 1, s1 + 1 + m1, cmp1);
	sort(s2 + 1, s2 + 1 + m2, cmp2);
	
	int sum1, sum2;
	for(int i = 0; i <= n; i ++)
	{
		sum1 = 0;
		sum2 = 0;
		memset(last, 0, sizeof(last));
		
		if(i >= m1) sum1 += m1;
		else{
			int use = 0;
			for(int j = 1; j <= m1; j ++)
			{
				if(j == 1){
					use ++;
					last[use] = s1[j].b;
					sum1 ++; 
				}
				else{
					bool flag = false;
					for(int k = 1; k <= use; k ++)
					{
						if(s1[j].a >= last[k]){
							last[k] = s1[j].b;
							sum1 ++;
							flag = true;
							break;  
						}
					}
					if(flag == false){
						use ++;
						last[use] = s1[j].b;
						sum1 ++;
					}
				}
				
				if(use > i){
					sum1 --;
					use --;
				}	
			}
		}
		
		memset(last, 0, sizeof(last));
		
		if(n - i >= m2) sum2 += m2;
		else{
			int use = 0;
			for(int j = 1; j <= m2; j ++)
			{
				if(j == 1){
					use ++;
					last[use] = s2[j].b;
					sum2 ++; 
				}
				else{
					bool flag = false;
					for(int k = 1; k <= use; k ++)
					{
						if(s2[j].a >= last[k]){
							last[k] = s2[j].b;
							sum2 ++;
							flag = true;
							break;  
						}
					}
					if(flag == false){
						use ++;
						last[use] = s2[j].b;
						sum2 ++;
					}
				}
				if(use > n - i){
					sum2 --;
					use --;
				}	
			}
		}
		
		ans = max(ans, sum1 + sum2);
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


