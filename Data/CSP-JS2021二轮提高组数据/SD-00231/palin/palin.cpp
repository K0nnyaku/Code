#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>


using namespace std;

int read(){
	int x = 0,w = 1;char ch = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch - '0');ch = getchar();}
	return x * w;
}

int n,t;
int a[2000060];
int nex[2000060],las[2000060];
int vis[2000060];
int tmp;
int ans[2000060],cnt;
int p[2000060];

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t = read();
	while(t --){
		
		memset(vis,0,sizeof vis);
		
		n = read();
		bool flag = 1;
		for(int i = 1;i <= n * 2;i ++){
			a[i] = read();
			nex[i] = i + 1;
			las[i] = i - 1;
			if(!vis[a[i]])vis[a[i]] = i;
			if(vis[a[i]]){
				p[i] = vis[a[i]];
				p[vis[a[i]]] = i;
			}
		}
		
		int st = 1,ed = 2 * n;

		tmp = p[st];	
		
		int las1 = las[p[1]];
		int nex1 = nex[p[1]];
		int res;
		
		if(p[las1] != 2 && p[las1] != n * 2){
			if(p[nex1] != 2 && p[nex1] != n * 2){
				ans[ ++ cnt] = a[ed];
				tmp = p[ed];
				res = las[tmp];
				nex[ed] = 2 * n + 1;
				nex[las[tmp]] = nex[tmp];
				las[nex[tmp]] = las[tmp];
				tmp = res;
			}
		}
		
			for(int i = 1;i <= n;i ++){
//				cout << tmp << '\n';
//				cout << st <<' ' << ed << '\n';
				if(i == 1 && flag == 0) continue;
				
				if(tmp == st){
					
					ans[i] = a[st];
					
					res = las[tmp];
					nex[las[p[tmp]]] = nex[p[tmp]];
					las[nex[p[tmp]]] = las[p[tmp]];
					
					if(a[st] == a[ed]) ed = las[ed];
					
					st = nex[st];
					las[st] = 0;
					tmp = res;
					
					
					continue;
				}
				
				
				else if(st == p[tmp]){
					ans[i] = a[st];
					
					res = las[tmp];
					nex[las[tmp]] = nex[tmp];
					las[nex[tmp]] = las[tmp];
					
					if(a[st] == a[ed]) ed = las[ed];
					
					st = nex[st];
					las[st] = 0;
					tmp = res;
					
					
					continue;
				}
				
				
				else if(nex[tmp]  == st){
					ans[i] = a[st];
					tmp = nex[tmp];
					
					res = las[tmp];
					nex[las[p[tmp]]] = nex[p[tmp]];
					las[nex[p[tmp]]] = las[p[tmp]];
					
					
					if(a[st] == a[ed]) ed = las[ed];

					
					st = nex[st];
					las[st] = 0;
					tmp = res;
					continue;
				}
				else if(st == p[nex[tmp]]){
					ans[i] = a[st];
					tmp = nex[tmp];
					
					res = las[tmp];
					nex[las[tmp]] = nex[tmp];
					las[nex[tmp]] = las[tmp];
					
					
					if(a[st] == a[ed]) ed = las[ed];

					
					st = nex[st];
					las[st] = 0;
					tmp = res;
					continue;
				}
				
				else if(tmp == ed){
					ans[i] = a[ed];
					res = las[tmp];
					nex[las[tmp]] = nex[tmp];
					las[nex[tmp]] = las[tmp];
					
					if(a[ed] == a[st]) st = nex[st];

					
					ed = las[ed];
					nex[ed] = n * 2 + 1;
					tmp = res;
					continue;
				}
				else if(ed == p[tmp] ){
					ans[i] = a[ed]
					res = las[tmp];
					nex[las[tmp]] = nex[tmp];
					las[nex[tmp]] = las[tmp];
					
					if(a[ed] == a[st]) st = nex[st];

					
					ed = las[ed];
					nex[ed] = n * 2 + 1;
					tmp = res;
					continue;
				}
				else if(ed == p[nex[tmp]]){
					ans[i] = a[ed];
					
					tmp = nex[tmp];
					
					res = las[tmp];
					nex[las[tmp]] = nex[tmp];
					las[nex[tmp]] = las[tmp];
					
					if(a[ed] == a[st]) st = nex[st];

					
					ed = las[ed];
					nex[ed] = n * 2 + 1;
					tmp = res;
					continue;
				}
				
				else if(nex[tmp] == ed))
				else {
					cout << -1 << '\n';
					break;
				}
				
			}
//		for(int i = 1;i<=n;i ++) cout << ans[i] << ' ';
	for(int i = 1;i <= n;i ++) ans[2 * n + 1 - i] = ans[i];
	int l = 1,r = 2 * n;
	for(int i = 1;i <=n * 2;i ++){
		if(ans[i] == a[l]){
			l ++;
			cout << "L";
			continue;
		}
		else if(ans[i] == a[r]){
			r --;
			cout << "R";
			continue;
		}
	}
}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
