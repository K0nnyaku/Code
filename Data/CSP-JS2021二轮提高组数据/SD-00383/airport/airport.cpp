	#include<iostream>
	#include<queue>
	#include<cmath>
	#include<cstdio>
	#include<algorithm>
	using namespace std;
	const int N = 1e6 + 9;
	typedef long long ll;
	int n, m_1, m_2;
	struct hb{
		int begin;
		int end;
	}m1[N], m2[N];
	
	bool cmp(hb a, hb b){
		return a.begin < b.begin;
	}
	bool cmp1(hb a, hb b){
		return a.begin < b.begin;
	}
	int zt[N],zt1[N];
	int main(){
		freopen("airport.in","r",stdin);
		freopen("airport.out","w",stdout);
		cin >> n >> m_1 >> m_2;
		for(int i = 1; i <= m_1;i++){
			cin >> m1[i].begin >> m1[i].end;
		}	
		for(int i = 1; i <= m_2;i++){
			cin >> m2[i].begin >> m2[i].end;
		}
		int ans = -1e9;
		sort(m1 + 1,m1 + m_1 + 1,cmp);
		sort(m2 + 1,m2 + m_2 + 1,cmp1);

		for(int i = 0; i <= n; i++)
		{
			for(int k = 1; k <= m_1; k++)
			zt[k] = m1[k].end;
			for(int k = 1; k <= m_2; k++)
			zt1[k] = m2[k].end;
			
			
			int lq = i;
			int fj = 0;
			int j = n - i;
			int lq1 = j;
			bool bj = 0;
			
			for(int o = 1; o <= m_1 ; o++){
				int cnt = 0;
				for(int pp = 1; pp < o; pp++){
					if(zt[pp] <= m1[o].begin && lq <= i){
						zt[pp] = m1[o].end;
						lq++;
	
						break;
					}
				}
				if(lq > 0){
					lq--;
					fj++;
				}
				else{	
				zt[o] = 0x3f3f3f;
				}	
			}
			int k = 0;	
			for(int o = 1; o <= m_2 ; o++){
				int cnt = 0;
				for(int pp = 1; pp < o; pp++){
					if(zt1[pp] <= m2[o].begin && lq1 <= j)
					{		
						zt1[pp] = m2[o].end; 
						lq1++;
						break;
						
					}
				}
				if(lq1 > 0){
					lq1--;
					fj++;	
				}
				else{	
				zt1[o] = 0x3f3f3f;
				}	
			}ans = max(fj, ans);

		}
	
		cout << ans;
		return 0;
	}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16




*/

