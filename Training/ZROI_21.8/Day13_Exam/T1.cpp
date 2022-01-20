#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

#define LOCAL

const int MAXN = 2000001 + 10;

int Pos[2];
int n, sum, pos;
char S[MAXN];

unsigned long long Ask(int x, int y);

int main() {
#ifdef LOCAL
	freopen("In.in", "r", stdin);
#endif	

    scanf("%d", &n);
    scanf("%s", S+1);

    if(n % 2 == 0) { printf("NOT POSSIBLE"); return 0; }

    int hf = n / 2, mk = 1;

    for(int i = 1, j = n-hf+1, flag = 0; j <= n; i++, j++) {
        if(S[i] != S[j]) if(flag) { mk = 0; break; } else flag = 1, Pos[0] = i, j--; 
    }
    sum += mk;

    mk = 1;
    for(int i = 1, j = hf+1, flag = 0; i <= hf; i++, j++) {
        if(S[i] != S[j]) if(flag) { mk = 0; break; } else flag = 1, Pos[1] = j, i--;
    }
    sum += mk; if(mk == 1) pos = 1;

    if(!sum) printf("NOT POSSIBLE");
    else 
    if(sum > 1) printf("NOT UNIQUE");
    else {
        if(Pos[pos] <= hf) 
            for(int i = n-hf+1; i <= n; i++) printf("%c", S[i]);
        else 
            for(int i = 1; i <= hf; i++) printf("%c", S[i]);
    }

	return 0;
}
