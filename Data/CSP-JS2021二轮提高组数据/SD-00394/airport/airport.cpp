#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
inline int read() {
	int x(0),f(1);
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct intt {
	int s;
};
struct fj {
	int l;
	int q;
};
priority_queue<intt> nq2;
priority_queue<intt> yq2;
priority_queue<intt> nq;
priority_queue<intt> yq;
bool operator < (const intt a,const intt b) {
	return a.s>b.s;
}
bool cmp (fj a,fj b) {
	if(a.l<b.l)return 1;
	else return 0;
}
int nn,mn,my;
fj n[100005],y[100005];
int maxx(-1);


int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	nn=read();
	mn=read();
	my=read();
	for(int i=1; i<=mn; i++) {
		n[i].l=read();
		n[i].q=read();
	}
	for(int i=1; i<=my; i++) {
		y[i].l=read();
		y[i].q=read();
	}
	sort(n+1,n+1+mn,cmp);
	sort(y+1,y+1+my,cmp);
	int cur(0);
	for(int i=1; i<=mn; i++) { //国内最大重叠
		cur++;
		intt k;
		k.s=n[i].q;
		nq.push(k);
		int kk;
		kk=nq.top().s;
		while(n[i].l>kk) {
			nq.pop();
			kk=nq.top().s;
			cur--;
		}
		maxx=max(maxx,cur);
	}
	int minn=maxx;
	maxx=-1;
	cur=0;
	for(int i=1; i<=my; i++) { //国外最大重叠
		cur++;
		intt k;
		k.s=y[i].q;
		yq.push(k);
		int kk;
		kk=yq.top().s;
		while(y[i].l>kk) {
			yq.pop();
			kk=yq.top().s;
			cur--;
		}
		maxx=max(maxx,cur);
	}
	minn=min(maxx,minn);
	cur=0;
	int mans(-1);
	//cout<<minn<<endl;
	if(minn>=nn)minn=nn;
	for(int i=minn; i>=0; i--) {
		int ans(0);
		int nw,yw;
		if(maxx>minn) {
			nw=i;
			yw=nn-i;
		} else {
			nw=nn-i;
			yw=i;
		}
		cur=0;
		
		for(int j=1; j<=mn; j++) {
			if(nw==0)break;//cout<<nw<<endl;
			cur++;
			if(cur<=nw) {
				ans++;
				intt k;
				k.s=n[j].q;
				nq2.push(k);
			}
			
			if(cur>nw) {
				cur--;
				int k=nq2.top().s;
				
				if(n[j].l>k) {
					nq2.pop();
					intt kk;
					kk.s=n[j].q;
					nq2.push(kk);
					ans++;
				}
			}
		}
		
		cur=0;
		
		for(int j=1; j<=my; j++) {
			if(yw==0)break;
			cur++;
			if(cur<=yw) {
				ans++;
				intt k;
				k.s=y[j].q;
				yq2.push(k);
			}
			if(cur>yw) {
				cur--;
				int k=yq2.top().s;
				if(y[j].l>k) {	
					yq2.pop();
					intt kk;
					kk.s=y[j].q;
					yq2.push(kk);
					ans++;
				}
			}
		}
		mans=max(ans,mans);
		int curr=nw;
		while(curr) {
			curr--;
			nq.pop();
		}
		curr=yw;
		while(curr) {
			curr--;
			yq.pop();
		}
	}
	cout<<mans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

