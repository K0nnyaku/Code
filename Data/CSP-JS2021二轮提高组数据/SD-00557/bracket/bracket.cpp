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
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;

int n, K, cnt, ans = 0;
char s[MAXN], t[MAXN];
int a[MAXN];
int stc[MAXN], sc = 0;
int p[MAXN], top = 0;
int b[MAXN];
LL f[550][550];

bool Check() {
    for(int i = 1; i <= n; ++i) b[i] = 0;
    int now_ = 1;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '?') {
            if(stc[now_] == 1) t[i] = '(';
            else if(stc[now_] == 2) t[i] = ')';
            else t[i] = '*';
            ++ now_;
        } else {
            t[i] = s[i];
        }
    }
    now_ = 0;
    for(int i = 1; i <= n; ++i) {
        if(t[i] == '*') {
            now_ ++;
            if(now_ > K) return false;
        } else now_ = 0;
    }
    if(t[1] == '*' || t[n] == '*') return false;
    now_ = 0;
    int l = 0;
    for(int i = 1; i <= n; ++i) {
        if(t[i] == '(') {
            now_ ++;
            p[++top] = ++ l;
            b[i] = l;
        } else if(t[i] == ')'){
            now_ --;
            if(now_ < 0) return false;
            b[i] = p[top--];
        }
    }
    if(now_ > 0) return false;
    for(int i = 1; i <= n; ++i) {
        if(t[i] == '(') {
            int r = i;
            bool flag = false;
            for(int j = i + 1; j <= n; ++j) {
                if(b[i] == b[j]) {
                    r = j; break;
                }
                if(t[j] == '(' || t[j] == ')') flag = true;
            }
            if(i < r - 1 && t[i + 1] == '*' && t[r - 1] == '*' && flag) {
//                cout<<i<<" "<<r<<" "<<t + 1<<"\n";
                return false;
            }
        }
    }
//    cout<<now_<<" "<<t + 1<<"\n";
    return true;
}

void dfs(int pos) {
    if(pos == cnt + 1) {
        if(Check()) ans++;
        return ;
    }
    for(int i = 1; i <= 3; ++i) {
        stc[++sc] = i;
        dfs(pos + 1);
        sc--;
    }
}


namespace Subtask2 {
    void Solve() {
        for(int i = 1; i < n; ++i) {
            if(s[i] == '(' || s[i] == '?') {
                if(s[i + 1] == ')' || s[i + 1] == '?') {
                    f[i][i + 1] = 1;
                }
            }
        }
        for(int len = 3; len <= n; ++len) {
            for(int l = 1; l + len - 1<= n; ++l) {
                int r = l + len - 1;
                if((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?')) {
                    for(int k = l + 1; k < r - 1; ++k) {
                        if(s[k] == '(' || s[k] == ')') break;
                        if(k - l > K) break; 
                        f[l][r] = (f[l][r] + f[k + 1][r - 1]) % mod;
                    }
                    for(int k = r - 1; k > l + 1; --k) {
                        if(s[k] == '(' || s[k] == ')') break;
                        if(r - k > K) break; 
                        f[l][r] = (f[l][r] + f[l + 1][k - 1]) % mod;
                    }
                    bool flag = false;
                    for(int k = l + 1; k <= r - 1; ++k) {
                        if(s[k] == '(' || s[k] == ')') {
                            flag = true;
                            break;
                        }
                    }
                    if(!flag) f[l][r] = (f[l][r] + 1) % mod;
                    else f[l][r] = (f[l][r] + f[l + 1][r - 1]) % mod;
                }
                for(int k = l; k < r; ++k) {
                    f[l][r] = (f[l][r] + f[l][k] * f[k + 1][r] % mod) % mod;
                }
                int L = l + 1, R = l + 1;
                for(int k = l + 1; k < r; ++k) {
                    if(s[k] == '(' || s[k] == ')') {
                        L = k + 1, R = k + 1;
                    } else {
                        R = k;
//                        if(l == 1 && r == n) cout<<L<<" "<<R<<"\n";
                        f[l][r] = (f[l][r] + f[l][L - 1] * f[R + 1][r] % mod) % mod;
                    }
                }
//                for(int L = l; L <= r; ++L) {
//                    for(int R = L; R <= r; ++R) {
//                        if(R - L + 1 > K) break;
//                        bool flag = false;
//                        for(int k = L; k <= R; ++k) {
//                            if(s[k] == '(' || s[k] == ')') {
//                                flag = true;
//                                break;
//                            }
//                        } 
//                        if(!flag) f[l][r] = (f[l][r] + f[l][L - 1] * f[R + 1][r] % mod) % mod;
//                    }
//                }
            }
        }
//        for(int l = 1; l <= n; ++l) {
//            for(int r = l; r <= n; ++r) {
//                cout<<f[l][r]<<" ";
//            }
//            puts("");
//        }
        printf("%lld\n", f[1][n]);
    }
}

int main() {
    freopen("bracket.in","r",stdin);
    freopen("bracket.out","w",stdout);

    scanf("%d%d", &n, &K);
    cin >> (s + 1);
    for(int i = 1; i <= n; ++i) if(s[i] == '?') cnt++;
    if(n <= 15) {
        dfs(1);
        printf("%d\n", ans);
    } else {
        Subtask2::Solve();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

