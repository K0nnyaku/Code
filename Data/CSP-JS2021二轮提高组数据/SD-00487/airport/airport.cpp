#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std; 
const int N = 1e5 + 55;
int n, m1, m2, Ans, Sum[N];
struct Plane{
	int s, t, Last, Next;
}A[N], B[N];

bool Cmp(Plane a, Plane b) {
	return a.s < b.s;
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i = 1; i <= m1; i++) {
		scanf("%d%d",&A[i].s,&A[i].t);
	}
	for (int i = 1; i <= m2; i++) {
		scanf("%d%d",&B[i].s,&B[i].t);
	}
	
	sort(A + 1, A + m1 + 1, Cmp);
	sort(B + 1, B + m2 + 1, Cmp);
	int maxn = max(m1, m2);
	for (int i = 0; i <= maxn; i++) {
		A[i].Last = B[i].Last = i - 1; 
		A[i].Next = B[i].Next = i + 1;
	}
	A[0].Last = B[0].Last = 0;
	A[m1].Next = B[m2].Next = 0;
	//for (int i = 0; i <= m2; i++)	printf("B[%d].last = %d B[%d].next = %d\n",i,B[i].Last,i,B[i].Next);
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int last = 0;
		for (int j = A[0].Next; j; j = A[j].Next) {
			int l = A[j].s, r = A[j].t;
			//printf("j = %d : ",j);
			if (l > last) {
				//printf("last = %d l = %d r = %d  ",last,l,r);
				last = r; sum++;
				//printf("nowlast = %d sum = %d\n",last,sum);
				A[A[j].Last].Next = A[j].Next;
				A[A[j].Next].Last = A[j].Last; 
			}
		}
		Sum[i] = sum; //printf("Sum[%d] = %d\n",i,Sum[i]);
		
		//printf("Sum1[%d] = %d\n",i,Sum[i]);
	}
	
	sum = 0;
	for (int i = 1; i <= n; i++) {
		int last = 0;
		for (int j = B[0].Next; j; j = B[j].Next) {
			int l = B[j].s, r = B[j].t;
			if (l > last) {
				last = r; sum++;
				B[B[j].Last].Next = B[j].Next;
				B[B[j].Next].Last = B[j].Last; 
			}
		}
		Ans = max(Ans, sum + Sum[n - i]);
		//printf("Sum2[%d] = %d\n",i,sum);
	}
	
	printf("%d",max(Ans, Sum[n]));
	//printf("\n%dms",clock());
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

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
