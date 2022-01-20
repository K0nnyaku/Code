#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#define LL long long
#define orz cout<<"lkp AK IOI!\n"
using namespace std;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;

int n, flag = false;
int a[MAXN], c[MAXN], b[MAXN];
int ans[MAXN], tmp[MAXN];

namespace Subtask1 {
    void Clear() {
        flag = false;
        for(int i = 1; i <= n; ++i) {
            ans[i] = tmp[i] = 0;
        }
    }
    bool Check(int l, int r, int pos) {
//        cout<<l<<" "<<r<<" "<<pos<<"\n";
        if(pos == 2 * n + 1) return true;
        if(a[l] == b[pos]) {
            tmp[pos] = 0;
            if(Check(l + 1, r, pos + 1)) {
                return true;
            }
        } 
        if(a[r] == b[pos]) {
            tmp[pos] = 1;
            if(Check(l, r - 1, pos + 1)) {
                return true;
            }
        }
        return false;
    }
    void Solve() {
        for(int i = 1; i <= n; ++i) {
            c[i] = i;
        }
        do{
            for(int i = 1; i <= n; ++i) b[i] = b[2 * n + 1 - i] = c[i];
            if(Check(1, 2 * n, 1)) {
                bool Flag = false;
                for(int i = 1; i <= 2 * n; ++i) {
                    if(ans[i] < tmp[i]) {
                        break;
                    }
                    if(ans[i] > tmp[i]) {
                        Flag = true;
                        break;
                    }
                }
                if(!flag || Flag) {
                    flag = true;
//                    for(int i = 1; i <= 2 * n; ++i) cout<<b[i]<<" "; puts("");
                    for(int i = 1; i <= 2 * n; ++i) ans[i] = tmp[i];
                }
            }
        } while(next_permutation(c + 1, c + n + 1));
        if(!flag) puts("-1");
        else {
            for(int i = 1; i <= 2 * n; ++i) {
                if(ans[i]) printf("R");
                else printf("L");
            }
            puts("");
        }
    }
}

int main() {
    freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);

    int T; 
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= 2 * n; ++i) {
            scanf("%d", &a[i]);
        }
        if(n <= 10) {
            Subtask1::Solve();
            Subtask1::Clear();
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

