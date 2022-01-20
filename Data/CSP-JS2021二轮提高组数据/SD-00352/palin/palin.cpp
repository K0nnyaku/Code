#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <ctype.h> 
#include <queue>
using namespace std;
#define rep(i, f, t) for(int i(f); i <= t; ++i)
#define per(i, t, f) for(int i(t); i >= f; --i)
#define re(i, t) for(int i(1); i <= t; ++i)
#define pe(i, t) for(int i(t); i >= 1; --i)
#define inf 0x3f3f3f3f

template<class I>
inline I read(I &x) {
	x = 0;
	I f = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-')
			f = f * (-1);
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x = x * f;
}

char buf[1003];

template<class I>
inline void write(I x) {
	if(x == 0) {
		putchar('0');
		return ;
	}
	I tmp = 0, cnt = 0;
	tmp = x < 0 ? (-x) : x;
	if(x < 0) putchar('-');
	while(tmp) {
		buf[cnt++] = (tmp % 10 + '0');
		tmp /= 10;
	}
	while(cnt) putchar(buf[--cnt]);
	return ;
}

#define out(x) write(x), putchar(' ')
#define outn(x) write(x), putchar('\n')
#define pii pair<int, int>
#define mp(i, j) make_pair(i, j)

int t, n;
const int N = 1e6+3;
int val[N];
char ans[N];
int base[N], qwq;

int main () {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(t);
	while(t--) {
		read(n);
		n <<= 1;
		re(i, n) read(val[i]);
		ans[1] = 'Z';
		qwq = -1;
		rep(i, 0, (1<<n)-1) {
			int l = 1, r = n;
			rep(j, 0, n-1) {
				if((1 << j) & i) {
					base[j+1] = val[l++];
				}
				else base[j+1] = val[r--];
			}	
			bool flag = 0;	
			re(j, n) {
				if(base[j] != base[n-j+1]) flag = 1;
			}
			if(!flag) {
				re(j, n) {
					char res = ((1 << (j-1)) & i) ? 'L' : 'R';
					if(res < ans[j]) {
						flag = 0;
						break;
					}
					else if(ans[j] < res) {
						flag = 1;
						break;
					}
				}
				if(!flag) re(j, n) ans[j] = ((1 << (j-1)) & i) ? 'L' : 'R', qwq = i;
			}
		}
		if(qwq == -1) cout << "-1";
		else rep(j, 0, n-1) {
			if((1 << j) & qwq) cout << "L";
			else cout << "R";
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
