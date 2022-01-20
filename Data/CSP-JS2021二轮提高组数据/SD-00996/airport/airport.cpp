#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 9;
int n, m1, m2, j, maxn;
struct node{
	int l, r;
}s[N], a[N];
bool flag, flag2;
int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			f = -1; 
		} 
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

bool vis1[N], vis2[N];
void dfs(){
	while(j <= n){//国内航班 
		int k = n - j;//国际航班 
		int cnt1 = 0, cnt2 = 0; 
		int d = j;
		for(register int i = 1;i <= m1;i++){
			flag = 0;
			for(register int h = 1;h <= i;h++){
				if(s[i].l >= s[h].r && vis1[h] == 1){
					flag = 1;
					vis1[h] = 0; 
					vis1[i] = 1;//占机位 
					cnt1++;
					//下一次开始时间 
					break;
				} //可以替 
			}//在前面找到位置 
			if(flag == 0){//没进 
				if(d == 0){//没有可替换的 
//					cnt1++;
					continue; 
				} 
				else {
					d--;
					vis1[i] = 1; 
					cnt1++;
				}
			}
		}
//		cout << cnt1 << "&&&" << endl;
		for(register int i = 1;i <= m2;i++){
			flag2 = 0; 
			for(register int h = 1;h < i;h++){
				if(a[i].l >= a[h].r && vis2[h] == 1){
					flag2 = 1;
					vis2[h] = 0; 
					vis2[i] = 1;
					cnt2++;
					break;
				} //可以替   
			}
			
			if(flag2 == 0){//没进 
				if(k == 0){//没有可替换的 
					continue; 
				} 
				else {
					k--;
					vis2[i] = 1; 
					cnt2++;
				}
			}
		}
//		cout << cnt2 << "***" << endl;
		maxn = max(maxn, cnt1 + cnt2);
//		cout << maxn << endl;
		j++;
	}
}

int main(){
//	freopen("airport.in", "r", stdin);
//	freopen("airport.out", "w", stdout);
//	scanf("%d%d%d", &n, &m1, &m2);
	n = read(), m1 = read(), m2 = read();
	
	for(register int i = 1;i <= m1;i++){
//		cin >> s[i].l >> s[i].r;
		s[i].l = read(), s[i].r = read();
	}
	
	for(register int i = 1;i <= m2;i++){
		a[i].l = read(), a[i].r = read();
	}

	dfs();
	printf("%d", maxn);
	
//	fclose(stdin);
//	fclose(stdout);

	return 0;
} 
