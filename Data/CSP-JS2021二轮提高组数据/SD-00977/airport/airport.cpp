#include <cstdio>
#include <algorithm>
#include <queue>
struct s {
	int x, y;
	bool operator<(const s& rhs) const {
		return x < rhs.x;
	}
} s1[200000], s2[200000];
std::priority_queue<int> q1,q2;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	s *t1=s1;
	for(int i=0; i<m1; i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		t1->x = x;
		t1->y = y;
		t1++;
	}
	std::sort(s1,t1);
	s *t2=s2;
	for(int i=0; i<m2; i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		t2->x = x;
		t2->y = y;
		t2++;
	}
	std::sort(s2,t2);
	int k, result = 0;
	for(int i=0; i<=n; i++) {
		k=0;
		while(!q1.empty()) q1.pop();
		for(s *it=s1; it!=t1; ++it) {
			while((!q1.empty()) && (-q1.top()) < it->x) {
				q1.pop();
			}
			if(q1.size() < i) {
				q1.push(-(it->y));
				k++;
			}
		}
		while(!q2.empty()) q2.pop();
		for(s *it=s2; it!=t2; ++it) {
			while((!q2.empty()) && (-q2.top()) < it->x) {
				q2.pop();
			}
			if(q2.size() < (n-i)) {
				q2.push(-(it->y));
				k++;
			}
		}
		if(k>result)
			result=k;
	}
	printf("%d\n", result);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

