#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXV = 1e3 + 10;
const int MAXL = 4 + 10;
#define TR(x, y) (Tr[(x)].son[(y)])

struct AcTrie {
    int son[10];
    int fail;
    int end;

    AcTrie() {
        fail = end = 0;
        memset(son, 0, sizeof son);
    }
}Tr[10000010];

void Add(char *T);
void Create();
int Query(char *T);

int n, l, r;

int main() {
    scanf("%d%d%d", &n, &l, &r);
    for(int i = 1; i <= n; i++) {
        char T[MAXL];
        scanf("%s", T);
        reverse(T, T + strlen(T));
        Add(T);
    }

    for(int i = l; i <= r; i++) {
        char T[MAXL];
        for(int j = 0, x = i; x; j++) {
            T[i] = x % 10;
            x /= 10;
        }
        int ans = 
    }

    return 0;
}