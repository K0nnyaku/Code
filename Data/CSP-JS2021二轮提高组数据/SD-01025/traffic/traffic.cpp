#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;

const int maxn = 100010;
const int inf = 0x3f3f3f3f;

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		s = (s<<1) + (s<<3) + (ch^48);
		ch = getchar();
	}
	return s * w;
}

inline void write(int x){
	char f[200];int cnt = 0;
	if(x<0){
		putchar('-');
		x = -x;
	}
	while(x){
		f[++cnt] = x % 10 + '0';
		x /= 10;
	}
	while(cnt){
		putchar(f[cnt]);
		cnt--;
	}
	return;
}

int T;
int n,m;
int a[maxn],b[maxn];

int main()
{
	freopen("traffic","r",stdin);
	freopen("traffic","w",stdout);
	
	n = read(),m = read(),T = read();
	
	int sum1 = 0,sum2 = 0;
	
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j){
			a[i] = read();
			sum1 += a[i];
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j){
			b[i] = read();
			sum2 += b[i];
		}
	}

	while(T--){
		int k;
		for(int i=1;i<=k;++i){
			int x,y,z;
			x = read(),y = read(),z = read();
			if(z==1){
				printf("%d",min(sum1,sum2));
			}
			else{
				printf("%d",min(sum1,sum2)+1);
			}
		}
	}
	return 0;
}

