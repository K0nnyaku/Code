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

const long long maxN=100090;
long long totN;
long long totA;
long long totB;

struct Line {
	long long l,r;
} As[maxN],Bs[maxN];



long long subA[maxN];
long long subB[maxN];

struct Node {
	long long tim;
	bool typ;
};

bool operator<(Node a,Node b) {
	if(a.tim==b.tim) {
		return a.typ<b.typ;
	} else {
		return a.tim<b.tim;
	}
}

vector<Node > VA;
vector<Node > VB;
long long nowSUM;
long long sumA[maxN];
long long sumB[maxN];
long long maxSUMa;
long long maxSUMb;
long long maxANS;
long long last[maxN];

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
//	totN=read();
//	totA=read();
//	totB=read();
	scanf("%lld%lld%lld",&totN,&totA,&totB);
//	printf("%lld %lld %lld",totN,totA,totB);
	for(int i=1; i<=totA; ++i) {
//		As[i].l=read();
//		As[i].r=read();
		scanf("%lld%lld",&As[i].l,&As[i].r);
		VA.push_back({As[i].l,1});
		VA.push_back({As[i].r,0});
	}
	sort(VA.begin(),VA.end());
//	for(auto i:VA){
//		printf("%lld %d\n",i.tim,i.typ);
//	}
	for(int i=1; i<=totB; ++i) {
//		Bs[i].l=read();
//		Bs[i].r=read();
		scanf("%lld%lld",&Bs[i].l,&Bs[i].r);
		VB.push_back({Bs[i].l,1});
		VB.push_back({Bs[i].r,0});
	}
	sort(VB.begin(),VB.end());
	nowSUM=0;
	bool flag=false;
	for(int i=1; i<=totA; ++i) {
		for(int j=1; j<=maxSUMa; ++j) {
			if(last[j]<=As[i].l) {
//				printf("%lld %lld %lld %lld %lld\n",i,j,last[j],maxSUMa,As[i].l);
				last[j]=As[i].r;
				++subA[j];
				flag=true;
				break;
			}
		}
		if(!flag) {
			++maxSUMa;
			last[maxSUMa]=As[i].r;
			++subA[maxSUMa];
		}
		flag=false;
	}
	nowSUM=0;
	memset(last,0,sizeof last);
	flag=false;
	for(int i=1; i<=totB; ++i) {
		for(int j=1; j<=maxSUMb; ++j) {
			if(last[j]<=Bs[i].l) {
				last[j]=Bs[i].r;
				++subB[j];
				flag=true;
				break;
			}
		}
		if(!flag) {
			++maxSUMb;
			last[maxSUMb]=Bs[i].r;
			++subB[maxSUMb];
		}
		flag=false;
	}
//	for(int i=1; i<=maxSUMa; ++i) {
//		printf("%lld ",subA[i]);
//	}
//	putchar('\n');
//	for(int i=1; i<=maxSUMb; ++i) {
//		printf("%lld ",subB[i]);
//	}
//	putchar('\n');
	for(int i=1; i<=maxSUMa; ++i) {
		sumA[i]=sumA[i-1]+subA[i];
	}
	for(int i=1; i<=maxSUMb; ++i) {
		sumB[i]=sumB[i-1]+subB[i];
	}
	for(int i=0; i<=totN&&i<=maxSUMa; ++i) {
		maxANS=max(maxANS,sumA[i]+sumB[totN-i]);
//		printf("%lld %lld %lld\n",i,totN-i,sumA[i]+sumB[totN-i]);
	}
	printf("%lld",maxANS);
	return 0;
}
//#include<bits/stdc++.h>
//#define INF 0x3f3f3f3f3f3f3f3f
//#define IINF 0x3f3f3f3f
//
//using namespace std;
//
//long long read() {
//	long long x=0;
//	long long f=1;
//	char ch;
//	ch=getchar();
//	while(ch<'0'||ch>'9') {
//		if(ch=='-') {
//			f=-1;
//		}
//		ch=getchar();
//	}
//	while(ch>='0'&&ch<='9') {
//		x=(x<<1)+(x<<3)+(ch^48);
//		ch=getchar();
//	}
//	return x*f;
//}
//
//const long long maxN=100090;
//long long totN;
//long long totA;
//long long totB;
//
//struct Line {
//	long long l,r;
//} As[maxN],Bs[maxN];
//
//
//
//long long subA[maxN];
//long long subB[maxN];
//
//struct Node {
//	long long tim;
//	bool typ;
//};
//
//bool operator<(Node a,Node b) {
//	if(a.tim==b.tim) {
//		return a.typ<b.typ;
//	} else {
//		return a.tim<b.tim;
//	}
//}
//
//vector<Node > VA;
//vector<Node > VB;
//long long nowSUM;
//long long sumA[maxN];
//long long sumB[maxN];
//long long maxSUMa;
//long long maxSUMb;
//long long maxANS;
//long long last[maxN];
//long long maxLAST;
//long long rks[maxN];
//
////long long split(long long MTree,long long )
//
//struct Tree{
//	long long l,r;
//	Tree *lch,*rch;
//	long long min,wei;
//	void pushup(){
//		if(lch->min<rch.min){
//			wei=lch.wei;
//		}else{
//			wei=rch.wei;
//		}
//		min=min(lch->min,rch->min);
//	}
//	Tree(long long L,long long R){
//		l=L;
//		r=R;
//		if(L==R){
//			min=INF;
//			wei=L;
//			lch=rch=NULL;
//			return;
//		}
//		long long Mid=(L+R)>>1;
//		lch=new Node(L,Mid);
//		rch=new Node(Mid+1,R);
//		pushup();
//	}
//	void update(long long pos,long long w){
//		if(L==R&&L==pos){
//			min=w;
//			return;
//		}
//		if(lch.r>=pos){
//			lch.update(pos,w);
//		}else{
//			rch.update(pos,w);
//		}
//		pushup();
//	}
//	void INrange(long long L,long long R){
//		return (L<=l)&&(r<=R);
//	}
//	void OUTrange(long long L,long long R){
//		return (l>R)||(L>r);
//	}
////	long long query(long long L,long long R){
////		if(INrange(L,R)){
////			return wei;
////		}else if(OUTrange(L,R)){
////			return 0;
////		}
////		if(lch.min
////	}
//};
//
//int main() {
//	freopen("airport.in","r",stdin);
//	freopen("airport.out","w",stdout);
////	totN=read();
////	totA=read();
////	totB=read();
//	scanf("%lld%lld%lld",&totN,&totA,&totB);
////	printf("%lld %lld %lld",totN,totA,totB);
//	for(int i=1; i<=totA; ++i) {
////		As[i].l=read();
////		As[i].r=read();
//		scanf("%lld%lld",&As[i].l,&As[i].r);
//		VA.push_back({As[i].l,1});
//		VA.push_back({As[i].r,0});
//	}
//	sort(VA.begin(),VA.end());
////	for(auto i:VA){
////		printf("%lld %d\n",i.tim,i.typ);
////	}
//	for(int i=1; i<=totB; ++i) {
////		Bs[i].l=read();
////		Bs[i].r=read();
//		scanf("%lld%lld",&Bs[i].l,&Bs[i].r);
//		VB.push_back({Bs[i].l,1});
//		VB.push_back({Bs[i].r,0});
//	}
//	sort(VB.begin(),VB.end());
//	nowSUM=0;
//	bool flag=false;
//	for(int i=1; i<=totA; ++i) {
//		if(As[i].l<last[i]){
//			++maxSUMa;
////			j=lower_bound(last+1,last+maxSUMa+1,As[i].l);
//			last[maxSUMa]=As[i].r;
//			++subA[maxSUMa];
//			
//		}
//		j=lower_bound(last+1,last+maxSUMa+1,As[i].l);
//		
//		last[]
//		for(int j=1; j<=maxSUMa; ++j) {
//			if(last[j]<=As[i].l) {
////				printf("%lld %lld %lld %lld %lld\n",i,j,last[j],maxSUMa,As[i].l);
//				last[j]=As[i].r;
//				
//				++subA[j];
//				flag=true;
//				break;
//			}
//		}
////		if(!flag) {
////			
////		}
////		flag=false;
//	}
//	nowSUM=0;
//	memset(last,0,sizeof last);
//	flag=false;
//	for(int i=1; i<=totB; ++i) {
//		for(int j=1; j<=maxSUMb; ++j) {
//			if(last[j]<=Bs[i].l) {
//				last[j]=Bs[i].r;
//				++subB[j];
//				flag=true;
//				break;
//			}
//		}
//		if(!flag) {
//			++maxSUMb;
//			last[maxSUMb]=Bs[i].r;
//			++subB[maxSUMb];
//		}
//		flag=false;
//	}
////	for(int i=1; i<=maxSUMa; ++i) {
////		printf("%lld ",subA[i]);
////	}
////	putchar('\n');
////	for(int i=1; i<=maxSUMb; ++i) {
////		printf("%lld ",subB[i]);
////	}
////	putchar('\n');
//	for(int i=1; i<=maxSUMa; ++i) {
//		sumA[i]=sumA[i-1]+subA[i];
//	}
//	for(int i=1; i<=maxSUMb; ++i) {
//		sumB[i]=sumB[i-1]+subB[i];
//	}
//	for(int i=0; i<=totN&&i<=maxSUMa; ++i) {
//		maxANS=max(maxANS,sumA[i]+sumB[totN-i]);
////		printf("%lld %lld %lld\n",i,totN-i,sumA[i]+sumB[totN-i]);
//	}
//	printf("%lld",maxANS);
//	return 0;
//}
