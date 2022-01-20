#include <bits/stdc++.h>
using namespace std;
inline void read(register int &x){
    x = 0; register int f = 1;
    register char ch = getchar();
    while (!(ch >= '0' && ch <= '9')){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
const int MN = 5e6 + 10;
int len;
bool endpos[MN];
string stot = "\\n";
char s[MN];
struct PAM{
    int s[MN], ch[MN][26], fail[MN], len[MN], last, tot, n;
    PAM(){
        memset(fail, -1, sizeof fail);
        fail[0] = fail[1] = 1;
        len[0] = 0; len[1] = -1;
        tot = 1; last = 0;
        s[0] = -1;
        n = 0;
    }
    inline void Insert1(register int c){
        s[++n] = c;
        while (c != s[n - len[last] - 1]) last = fail[last];
        if (!ch[last][c]) {
            len[++tot] = len[last] + 2;
            int k = fail[last];
            while (c != s[n - len[k] - 1]) k = fail[k];
            fail[tot] = ch[k][c];
            ch[last][c] = tot;
        }
        last = ch[last][c];
    }
    inline void Print(){
        printf("digraph test{\n");
        printf("    node[shape=\"circle\"];\n");
        printf("    rankdir=UD;\n");
        printf("    subgraph cluster_sub1{\n");
        printf("        0");
        for (register int i = 2; i <= tot; i++){
            if (len[i] % 2 == 0) printf(",%d", i);
        } printf(";\n");
        for (register int ll = 0; ll <= tot; ll += 2){
            int co = 0;
            for (register int i = 2; i <= tot; i++)
                if (len[i] == ll) ++co;
            if (!co) continue;
            printf("        {rank=same");
            for (register int i = 0, f = 1; i <= tot; i++)
                if (len[i] == ll) printf("%c%d", f ? ';' : ' ', i), f = 0;
            printf("}\n");
        }
        printf("    }\n");
        printf("    subgraph cluster_sub2{\n");
        printf("        1");
        for (register int i = 2; i <= tot; i++){
            if (len[i] % 2 == 0) printf(",%d", i);
        } printf(";\n");
        for (register int ll = -1; ll <= tot; ll += 2){
            int co = 0;
            for (register int i = 2; i <= tot; i++)
                if (len[i] == ll) ++co;
            if (!co) continue;
            printf("        {rank=same");
            for (register int i = 0, f = 1; i <= tot; i++)
                if (len[i] == ll) printf("%c%d", f ? ';' : ' ', i), f = 0;
            printf("}\n");
        }
        printf("    }\n");
        for (register int i = 0; i <= tot; i++)
            for (register int c = 0; c < 26; c++) if (ch[i][c])
                printf("    %d:s->%d:n[color=blue,label=\"%c\";];\n", i, ch[i][c], c + 'a');
        for (register int i = 0; i <= tot; i++)
            printf("    %d->%d[color=green,style=dashed];\n", i, fail[i]);
        register bool f = false;
        printf("    ");
        for (register int i = 0; i <= tot; i++) if (endpos[i]){
            if (!f) {printf("%d", i); f = true;}
            else printf(",%d", i);
        }
        printf("[style=\"filled\",fillcolor=\"chartreuse\"];\n");
        printf("    ");
        printf("\"Palindrome Automaton: \\n"); cout << stot;
        printf("\"");
        printf("[shape=plaintext];\n");
        printf("}");
    }
}pam;
int main(){
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Dot/PAM.dot", "w", stdout);
#endif

    scanf("%s", s + 1);
    len = strlen(s + 1);
    stot = s + 1;
    for (register int i = 1; i <= len; i++) pam.Insert1(s[i] - 'a');
    endpos[pam.last] = true;
    pam.Print();
    return 0;
}
