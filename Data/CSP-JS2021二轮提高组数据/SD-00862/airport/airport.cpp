#include <bits/stdc++.h>
using namespace std;
int n = 0;
int m1 = 0;
int m2 = 0;
int sum = 0;
int x1 = 0;
int x2 = 0;
int flag = 0;
int vis = 0;
int ans = 0;
struct node1 {
	int id1;
	int a1;
	int b1;
}a[100005], ax[100005];
struct node2 {
	int id2;
	int a2;
	int b2;
}b[100005], bx[100005];
int main() {
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 0; i < m1; i++) {
		scanf("%d %d", &a[i].a1, &a[i].b1);
		a[i].id1 = 0;
		ax[i].a1 = a[i].a1;
		ax[i].b1 = a[i].b1;
		ax[i].id1 = a[i].id1;
	}
	for (int i = 0; i < m2; i++) {
		scanf("%d %d", &b[i].a2, &b[i].b2);
		b[i].id2 = 0;
		bx[i].a2 = b[i].a2;
		bx[i].b2 = b[i].b2;
		bx[i].id2 = b[i].id2;
	}
	for (int i = 0; i <= n; i++) {
		sum = 0;
		for (int j = 0; j < m1; j++) {
		    a[j].a1 = ax[j].a1;
		    a[j].b1 = ax[j].b1;
		    a[j].id1 = ax[j].id1;
	    }
	    for (int j = 0; j < m2; j++) {
		    b[j].a2 = bx[j].a2;
		    b[j].b2 = bx[j].b2;
		    b[j].id2 = bx[j].id2;
	    }
		x1 = i;
		if (x1 > 0) {
			flag = 0;
			for (int j = 0; j < m1; j++) {
			    if (x1 > 0) {
				    sum++;
				    x1--;
				    a[j].id1 = 1;
				    flag = 1;
			    }
			    else {
			    	flag = 0;
				}
				if (flag == 0) {
					vis = 0;
					for (int k = 0; k <= j; k++) {
				        if (a[j].a1 > a[k].b1 && a[k].id1 == 1 && vis == 0) {
				            a[j].id1 = 1;
				            a[k].id1 = 0;
				            sum++;
				            vis = 1;
				        }
			        }
				}
		    }
		}
		x2 = n - i;
		if (x2 > 0) {
			flag = 0;
			for (int j = 0; j < m2; j++) {
			    if (x2 > 0) {
				    sum++;
				    x2--;
				    b[j].id2 = 1;
				    flag = 1;
			    }
			    else {
			    	flag = 0;
				}
				if (flag == 0) {
					vis = 0;
					for (int k = 0; k <= j; k++) {
				        if (b[j].a2 > b[k].b2 && b[k].id2 == 1 && vis == 0) {
				            b[j].id2 = 1;
				            b[k].id2 = 0;
				            sum++;
				            vis = 1;
				        }
			        }
				}
		    }
		}
		ans = max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}
