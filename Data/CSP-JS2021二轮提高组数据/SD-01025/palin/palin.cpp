#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;

const int maxn = 1000010;
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
int top,tem,cur;
int a[maxn];
int rl[maxn],len[maxn];
int p[maxn],cnt[maxn];

int main()
{
	freopen("palin","r",stdin);
	freopen("palin","w",stdout);

	T = read();

	while(T--){
		n = read();
		
		bool op = 0;
		
		for(int i=1;i<=(n<<1);++i){
			a[i] = read();
			if(len[a[i]]!=0){
				len[a[i]] = i - len[a[i]];
				if(len[a[i]] > n){
					op = 1;
				}
			}
			len[a[i]] = i;
		}
		
		bool flag = 0;
			for(int i=1;i<=n+1;++i){
				memset(cnt,0,sizeof(cnt));
				for(int j=0;j<n;++j){
					cnt[a[i+j]]++;
					if(cnt[a[i+j]]>1){
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					cur = i;
				}
			}
			
			if(flag ==0){
				for(int i=1;i<cur;++i){
					rl[a[i]] = 1;
				}
				
				for(int i=cur+n;i<=(n<<1);++i){
					rl[a[i]] = 2;
				}
				
				for(int i=cur;i<cur+n;++i){
					if(rl[a[i]]==1){
						printf("L");
					}
					else{
						printf("R");
					}
				}
				
				for(int i=1;i<=n;++i){
					if(i==n) printf("L");
					else printf("R");
				}
				
				
				printf("\n");
			}
			
			if(op==1&&flag == 1){
				printf("-1\n");
				continue;
			}
			
			
	}

	return 0;
}

