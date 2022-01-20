#include <bits/stdc++.h>
#define ll long long
#define re register
inline ll read(){
	ll s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar();}
	return s * w;
}
int main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);


	fclose(stdin);
	fclose(stdout);

	return 0;
}

