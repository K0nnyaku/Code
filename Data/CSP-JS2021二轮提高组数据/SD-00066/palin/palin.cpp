#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int M=4e6;
int T;
int n,a[M];
//L 1 R 2
int ans[M],cc[M],c[M],cnt[M],head,tail;

inline void input() {
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++) {
		scanf("%d",&a[i]);
	}
	head=1;tail=2*n;
}
int flag;
void dFs(int wayy,int now) {
	if (head>tail) return;
	if (flag==1) return;
	if (now>=2*n&&flag==0) {
		flag=1;
		for (int i=1;i<=2*n;i++) ans[i]=c[i];
		return;	
	}
	
	if (wayy==1) {
		int tx=a[head];
		if (now<=n&&cnt[tx]) return;
		if (now>n&&cc[2*n-now+1]!=tx) return;
		
		cc[now]=tx;
		cnt[tx]++;
		c[now]=wayy;
		head++;
		
		dFs(1,now+1);
		dFs(2,now+1);
		
		cnt[tx]--;
		c[now]=0;
		cc[now]=0;
		head--;
	}
	if (wayy==2) {
		int tx=a[tail];
		if (now<=n&&cnt[tx]) return;
		if (now>n&&cc[2*n-now+1]!=tx) return;
		cc[now]=tx;
		tail--;
		cnt[tx]++;
		c[now]=wayy;
		dFs(1,now+1);
		dFs(2,now+1);
		cnt[tx]--;
		cc[now]=0;
		c[now]=0;
		tail++;
	}
	return;
}

inline void init() {
	memset(ans,0,sizeof(ans));
	memset(cc,0,sizeof(cc));
	memset(cnt,0,sizeof(cnt));
	memset(c,0,sizeof(c));
	flag=0;
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	//
	scanf("%d",&T);
	while (T--) {
		init();
		input();
		dFs(1,1);
		dFs(2,1);
		for (int i=1;i<=n*2;i++) {
			if (ans[i]==1) printf("L");
			if (ans[i]==2) printf("R");
		}
		if (!ans[1]) printf("-1");
		else printf("L");
		printf("\n");
		
	}
	return 0;
	
	
	
}
