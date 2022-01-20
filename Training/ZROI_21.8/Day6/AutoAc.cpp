#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
#define TR(x, y) (Tr[(x)].son[(y)])

struct AcTrie {
    int son[27];
    int fail;
    int end;

    AcTrie() {
        fail = end = 0;
        memset(son, 0, sizeof son);
    }
}Tr[MAXN];

int iNdex;
void Add(char *T);
void Create();
int Query(char *T);

int main() {

    return 0;
}

void Add(char *T) {
    int p = 0, len = strlen(T);
    for(int i = 0; i < len; i++) {
        int ch = T[i] - 'a';
        if(TR(p, ch)) p = TR(p, ch);
        else TR(p, ch) = ++iNdex, p = iNdex;
    }
    Tr[p].end++;
}

void Create() {
    queue<int> q;
    for(int i = 0;  < 26; i++) 
        q.push(TR(0, i));
    
    while(!q.empty(
    }

}


























