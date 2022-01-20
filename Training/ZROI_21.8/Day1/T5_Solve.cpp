#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 10;
const double E = 1e-7;

struct Node {
	int a;
	int b;
	double s;

	friend bool operator<(Node x, Node y) {
		return x.a < y.a;
	}
}H[MAXN];

double v, sum;
int n, ans, cnt;

bool Cmp(Node x, Node y);

int main() {
	freopen("In.in", "r", stdin);

	scanf("%d%lf", &n, &v);
	for(int i = 0; i < n; i++) scanf("%d%d", &H[i].a, &H[i].b), H[i].s = H[i].a * v / H[i].b;

	sort(H, H + n, Cmp); 

	priority_queue<Node> q;
	for(int i = 0; i < n; i++) {
		q.push(H[i]);
		sum += H[i].a;
//		ans++;
		cnt++;
		while(sum - H[i].s >= E && q.size()) {
			sum -= q.top().a; q.pop();
			cnt--;
		}
		ans = max(cnt, ans);
	}
	
	printf("%d", ans);


	return 0;
}

bool Cmp(Node x, Node y) {
	return x.s > y.s;
}

