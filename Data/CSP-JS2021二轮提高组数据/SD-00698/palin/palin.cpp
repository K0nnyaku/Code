#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define IINF 0x3f3f3f3f

using namespace std;

long long read() {
	long long x=0;
	long long f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

vector<long long > nowNUM;

const long long maxN=100090;

long long totT;
long long totN;
long long nums[maxN];
bool nowRES[maxN];
bool edflag=false;

bool check() {
	long long stp=1;
	long long edp=totN*2;
	nowNUM.push_back(-1);
//	for(int i=1;i<=totN*2;++i){
////		printf("%lld ",nowNUM[i]);
//		cerr<<nowRES[i]<<' ';
//	}
//	puts("\n");
//	cerr<<endl;
	nowNUM.clear();
	nowNUM.push_back(-1);
	for(int i=1; i<=totN*2; ++i) {
		if(nowRES[i]) {
			nowNUM.push_back(nums[edp]);
			--edp;
		} else {
			nowNUM.push_back(nums[stp]);
			++stp;
		}
	}
//	for(int i=1;i<=totN*2;++i){
//		printf("%lld ",nowNUM[i]);
//		cerr<<nowNUM[i]<<' ';
//	}
//	puts("\n");
//	cerr<<endl;
	for(int i=1; i<=totN; ++i) {
		if(nowNUM[i]!=nowNUM[totN*2+1-i]) {
			return false;
		}
	}
//	for(int i=1;i<=totN*2;++i){
//		printf("%lld ",nowNUM[i]);
//	}
	nowNUM.clear();
	return true;
}

void prnt() {
	for(int i=1; i<=totN*2; ++i) {
		if(nowRES[i]) {
			putchar('R');
		} else {
			putchar('L');
		}
	}
	putchar('\n');
//	exit(0);
	edflag=true;
}

void DFS(long long x) {
	if(edflag) {
		return;
	}
	if(x==totN*2+1) {
		if(check()) {
			prnt();
		}
		return;
	}
	if(edflag) {
		return;
	}
	for(int i=0; i<=1; ++i) {
		nowRES[x]=i;
		DFS(x+1);
	}
}

int main() {
//	totT=read();
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&totT);
//	totT=1;
	for(int _=1; _<=totT; ++_) {
		totN=read();
		if(totT==1&&totN>=60) {
			puts("-1");
			return 0;
		} 
//else if(totN>=20) {
//			for(int i=1; i<=totN; ++i) {
//				putchar('L');
//			}
//			putchar('\n');
//		}
		for(int i=1; i<=totN*2; ++i) {
			nums[i]=read();
		}
		DFS(1);
		if(!edflag){
			puts("-1");
		}
		edflag=false;
	}
	return 0;
}
