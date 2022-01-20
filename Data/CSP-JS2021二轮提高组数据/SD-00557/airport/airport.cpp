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
const int MAXN = 1e5 + 1000;
const int mod = 1e9 + 7;
const int INF = 1e9 + 7;

struct node{
    int l, r;
    bool operator < (const node &c) const { return l < c.l; }
}a[MAXN], b[MAXN];

int n, m1, m2, ans = 0;
//int date1[MAXN << 1], date2[MAXN << 1], Cnt1 = 0, Cnt2 = 0;
//int c1[MAXN << 1], c2[MAXN << 1];
int cntl[MAXN], cntr[MAXN];


int Calc(int lim) {
    int L = lim, R = n - lim;
    priority_queue<int, vector<int>, greater<int> > q;
    while(!q.empty()) q.pop();
    int now = 0, res = 0;
    for(int i = 1; i <= m1; ++i) {
        while(!q.empty() && q.top() < a[i].l) q.pop(), now--;
        if(now < L) {
            q.push(a[i].r);
            now++, res++;
        }
    }
    
    now = 0;
    while(!q.empty()) q.pop();
    for(int i = 1; i <= m2; ++i) {
        while(!q.empty() && q.top() < b[i].l) q.pop(), now--;
        if(now < R) {
            q.push(b[i].r);
            res++, now++;
        }
    }
    return res;
}

void Solve1() {
    for(int i = 0; i <= n; ++i) {
        int res = Calc(i);
//        cout<<i<<" "<<res<<"\n";
        ans = max(ans, res);
    }
    printf("%d\n", ans);
    return ;
}

namespace Subtask2 {
    struct Node {
        int id, r;
        bool operator < (const Node &b) const { return r > b.r; }
    };
    priority_queue<Node> q;
    priority_queue<int, vector<int>, greater<int> > q2;
    void Solve() {
        for(int i = 1; i <= n; ++i) q2.push(i);
        for(int i = 1; i <= m1; ++i) {
            while(!q.empty() && q.top().r < a[i].l) {
                q2.push(q.top().id), q.pop();
            }
            if(!q2.empty()) {
                int u = q2.top(); q2.pop();
                q.push((Node){u, a[i].r});
                cntl[u]++;
            } 
        }
        while(!q.empty()) q.pop();
        while(!q2.empty()) q2.pop();
        
        for(int i = 1; i <= n; ++i) q2.push(i);
        for(int i = 1; i <= m2; ++i) {
            while(!q.empty() && q.top().r < b[i].l) q2.push(q.top().id), q.pop();
            if(!q2.empty()) {
                int u = q2.top(); q2.pop();
                q.push((Node){u, b[i].r});
                cntr[u]++;
            } 
        }
        for(int i = 1; i <= n; ++i) {
            cntl[i] = cntl[i - 1] + cntl[i];
            cntr[i] = cntr[i - 1] + cntr[i];
        }
        for(int i = 0; i <= n; ++i) {
            ans = max(cntl[i] + cntr[n - i], ans);
        } 
        printf("%d\n", ans);
        
    }
}

int main() {
    freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);

    scanf("%d%d%d", &n, &m1, &m2);
    for(int i = 1; i <= m1; ++i) {
        scanf("%d%d", &a[i].l, &a[i].r);
//        date1[++Cnt1] = a[i].l; 
//        date1[++Cnt1] = a[i].r;
    }
    for(int i = 1; i <= m2; ++i) {
        scanf("%d%d", &b[i].l, &b[i].r);
//        date2[++Cnt2] = b[i].l; 
//        date2[++Cnt2] = b[i].r;
    }
    
    sort(a + 1, a + m1 + 1);
    sort(b + 1, b + m2 + 1);

    if(n <= 100) {
        Solve1();
    } else {
        Subtask2::Solve();
    }
    
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

out 7 
*/
