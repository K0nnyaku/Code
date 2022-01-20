#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
char a[N];
int n , k;
int ans = 0;
int sta[N] , cnt = 0;
void dfs(int now) {
	if(now == n + 1) {
		cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] == '(')sta[++cnt] = '(';
			if(a[i] == ')') {
				int f = 0 , t = 0;
				
				if(sta[cnt] == '*')f = 1;
				for(; sta[cnt] == '*'; cnt--)
						t++;
				if(t > k)return;
				if(sta[cnt] == '(')sta[cnt] = 'E';
				else {
					int ee = 0;
					for(;sta[cnt] == 'E'; cnt--)ee = 1;
					while(ee == 1) {
					//	printf("%c\n",sta[cnt]);
						ee = 0;
						for(; sta[cnt] == '*'; cnt--)
							t++;
						if(t > k)return ;
						for(;sta[cnt] == 'E'; cnt--)ee = 1 , t = 0;
					}
					
					if((f == 1) && (sta[cnt] == '*' || ee==0))return;
					for(; sta[cnt] == '*'; cnt--)
							t++;
					if(t > k)return;
					
					if(sta[cnt] == '(')sta[cnt] = 'E';
					else return; 					
				}

			}
			if(a[i] == '*')sta[++cnt] = '*';
		}
		for(int j = 1; j <= cnt; j++)
			if(sta[j] != 'E')return;
		for(int i = 1; i <= n; i++)
			printf("%c" , a[i]);
		puts("");
		ans++;
		return;
	}
	if(a[now] != '?') {
		dfs(now + 1);
	//	return;	
	}
	else {
		a[now] = '(';
		dfs(now + 1);
		a[now] = ')';
		dfs(now + 1);
		a[now] = '*';
		dfs(now + 1);	
	}

	
}
//µÚ i ¸öÎ»ÖÃ£¬n¸öÃ»Åä¶ÔµÄ×óÀ¨ºÅ ,Á¬Ğø n¸ö* 
//0:* 1:( 2:)
int main() {
	freopen("bracket.in" , "r" , stdin);
	freopen("bracket.out", "w" , stdout);

	scanf("%d%d" , &n , &k);
	cin >> (a + 1);
/*	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		 if(a[i] != '?') {
		 	if(a[i] == '(')
				for(int j = 0; j <= n; j++)//×óÀ¨ºÅ 
					for(int e = 0; e <= k; e++)
					f[i][j + 1][0] += f[i - 1][j][e];
			if(a[i] == ')')
				for(int j = 1; j <= n; j++)//ÓÒÀ¨ºÅ
					for(int e = 0; e <= k; e++) 
					f[i][j - 1][0] += f[i - 1][j][e];
			if(a[i] == '*')
				for(int j = 1; j <= n; j++)
					for(int e = 0; e < k; e++)
					f[i][j - 1][e + 1] += f[i][j - 1][e];
					
		 }
		 else {
			for(int j = 0; j <= n; j++)//×óÀ¨ºÅ 
				for(int e = 0; e < k; e++) 
				f[i][j + 1][0] += f[i - 1][j];
			for(int j = 1; j <= n; j++)//ÓÒÀ¨ºÅ 
				f[i][j - 1] += f[i - 1][j];
		 }
	}*/
	dfs(1);
	printf("%d\n" , ans);
	return 0;
} 
