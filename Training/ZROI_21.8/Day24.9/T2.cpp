#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MAXN = 1e5 + 10;

long long A[MAXN << 2];
int t, n, k;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    cin >> t;
    while(t--) {
        memset(A, 0, sizeof A);
        cin >> n >> k;
        IOR(i, 0, n)
            cin >> A[i], A[i+n] = A[i];
        
        if(k > 3) {
            printf("Yes\n");
            continue;
        }
        else 
        if(k == 1) {
            bool flag = 1;
            IOR(i, 1, n) 
                if(A[i] - A[i-1] < 0) {
                    flag = 0;
                    break;
                }
            if(!flag) 
                printf("No\n");
            else
                printf("Yes\n");
            continue;
        }        
        
        bool flag = 0;
        int sum = 0;
        IOR(i, 1, n*2) {
            if(A[i] - A[i-1] > 0) 
                sum++;
            if(sum >= n) {
                printf("Yes\n");
                flag = 1;
                break;
            }
            if(A[i] - A[i-1] < 0) 
                sum = 0;
        }
        if(flag) 
            printf("Yes\n");
        else
            printf("No\n");
    }

	return 0;
} /**/