#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++) 
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define ZERO(x) memset(x, 0, sizeof x);

const int MAXN = 50 + 10;
const int INF = 03f3f3f3f;

int Head[MAXN], Next[MAXN<<2], Ver[MAXN<<2], Eg[MAXN<<2];
int idx = 1;
void Add(int pre, int to, int val);

vector<int> Cost[MAXN];
int Mon[MAXN];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    IOR(i, 1, m+1) {
        scanf("%d", &Mon[i]);

        char tools[10000];
        memset(tools,0,sizeof tools);
        cin.getline(tools,10000);
        int ulen=0,tool;
        while (sscanf(tools+ulen,"%d",&tool)==1)//之前已经用scanf读完了赞助商同意支付该实验的费用
        {//tool是该实验所需仪器的其中一个      
            //这一行，你可以将读进来的编号进行储存、处理，如连边。
            Cost[i].push_back(tool);

            if (tool==0) 
                ulen++;
            else {
                while (tool) {
                    tool/=10;
                    ulen++;
                }
             }
            ulen++;
        }
    }
    IOR(i, 1, m+1) {
        Add(1, i+1, )
    }

    return 0;
}