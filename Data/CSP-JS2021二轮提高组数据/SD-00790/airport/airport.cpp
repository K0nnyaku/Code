#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b)for(int i=(a),ed##i=(b);i<=ed##i;++i)
#define re(i,a)rep(i,1,a)
#define per(i,a,b)for(int i=(a),ed##i=(b);i>=ed##i;--i)
#define in Read()
#define up(a,b) (((a)<(b))and((a)=(b)))
#define down(a,b) (((a)>(b))and((a)=(b)))
#define dbg(x) (cerr<<#x" = "<<(x)<<'\n')
#define fio(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)

int Read(){
	int x=0,c=getchar();
	while(not isdigit(c))c=getchar();
	while(isdigit(c))x*=10,x+=c^'0',c=getchar();
	return x;
}

void out(int x){
	printf("%d",x);
}
#define ENDL putchar('\n')

const int N=4e5+9;

int n,m1,m2;
struct Node{
	int f,t;
}a[N],b[N];

bool Cmp(const Node&x,const Node&y){
	return x.f<y.f;
}

bool operator<(const Node&x,const Node&y){
	return x.t>y.t;
}

int l1=0,l2=0,val;
priority_queue<Node>q1,q2;

int F1(){
	auto&cur=a[++l1];
	while(q1.size()){
		Node x=q1.top();
		if(x.t<cur.f){
//			cerr<<"q1 pop "<<x.f<<' '<<x.t<<endl;
			q1.pop();
		}else break;
	}
//	dbg(q1.size());
	if((int)q1.size()<val){
//		cerr<<"push "<<l1<<" to q1"<<endl;
		return q1.push(a[l1]),1;
	}
//	cerr<<"push "<<l1<<" NO q1"<<endl;
	return 0;
}

int F2(){
	auto&cur=b[++l2];
	while(q2.size()){
		Node x=q2.top();if(x.t<cur.f){
//			cerr<<"q2 pop "<<x.f<<' '<<x.t<<endl;
			q2.pop();
		}else break;
	}
//	dbg(q2.size());
	if((int)q2.size()<n-val){
//		cerr<<"push "<<l1<<" to q2"<<endl;
		return q2.push(b[l2]),1;
	}
//	cerr<<"push "<<l1<<" NO q2"<<endl;
	return 0;
}

int Try(int vall){val=vall;
	l1=0,l2=0;
	int cnt=0;
	q1=priority_queue<Node>();
  q2=priority_queue<Node>();
	while(l1!=m1 or l2!=m2){
		if(l1==m1){
			cnt+=F2();
		} else if(l2==m2){
			cnt+=F1();
		}else if(a[l1+1].f<b[l2+1].f){
			cnt+=F1();
		}else{
			cnt+=F2();
		}
	}
	return cnt;
}

int ans;

void Baoli(){
		rep(i,0,n){
//		cerr<<i<<' '<<Try(i)<<endl;
		up(ans,Try(i));
	}printf("%d",ans),ENDL;
}

signed main(){
	fio("airport");
	n=in,m1=in,m2=in;
	re(i,m1){
		a[i].f=in,a[i].t=in;
	}
	re(i,m2){
		b[i].f=in,b[i].t=in;
	}
	sort(a+1,a+m1+1,Cmp),sort(b+1,b+m2+1,Cmp);
	if(n*(m1+m2)<=5e6){
		Baoli();
		exit(0);
	}
	int l,r;
	l=0,r=n;while(r-l>1){
		int mid=(l+r)/2,midd=(mid+r)/2;
		if(Try(mid)>Try(midd))r=midd;else l=mid;
	}
	up(ans,max(Try(l),Try(r)));
	l=0,r=n;while(r-l>1){
		int mid=(l+r)/2,midd=(mid+r)/2;
		if(Try(mid)>=Try(midd))r=midd;else l=mid;
	}
	up(ans,max(Try(l),Try(r)));
	printf("%d",ans),ENDL;
	return 0;
}
