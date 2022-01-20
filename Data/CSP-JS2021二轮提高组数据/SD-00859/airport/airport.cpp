// airport/airport.cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef  unsigned int uint;
typedef  unsigned long ulong;
typedef unsigned long long ull;
const int MAXM=1E5+10;
int n,m1,m2;
struct plane {
	int from,to;
} p1[MAXM],p2[MAXM];
struct point {
	enum {LEAVE=true,COME=false};
	int t;
	int no;
	bool type;
	point(int t_,int no_,int type_) {
		t=t_;
		no=no_;
		type=type_;
	}
	void print() {
		cerr<<"NO."<<no<<" is "<<(type==LEAVE?"leaving":"coming")<<" at "<<t<<endl;
	}
};

bool operator<(const point&a,const point &b) {
	return a.t<b.t;
}

vector<point>q1,q2;
bool in[MAXM];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1; i<=m1; i++) {
		scanf("%d %d",&p1[i].from,&p1[i].to);
		q1.push_back(point(p1[i].from,i,point::COME));
		q1.push_back(point(p1[i].to,i,point::LEAVE));

	}
	for(int i=1; i<=m2; i++) {
		scanf("%d %d",&p2[i].from,&p2[i].to);
		q2.push_back(point(p2[i].from,i,point::COME));
		q2.push_back(point(p2[i].to,i,point::LEAVE));
	}
	sort(q1.begin(),q1.end());
	sort(q2.begin(),q2.end());
	int mans=0;
	for(int i=0; i<=n; i++) {
		int ans=0;
		int s1=0;
		for(uint j=0; j<q1.size(); j++) {
			switch (q1[j].type) {
				case point::COME: {
					if(s1<i) {
						s1++;
						in[q1[j].no]=1;
						ans++;
					}
					break;
				}
				case point::LEAVE: {
					if(in[q1[j].no]) {
						s1--;
						in[q1[j].no]=0;
					}
					break;
				}
			}
		}
		int s2=0;
		for(uint j=0; j<q2.size(); j++) {
			switch (q2[j].type) {
				case point::COME: {
					if(s2<(n-i)) {
						s2++;
						in[q2[j].no]=1;
						ans++;
					}
					break;
				}
				case point::LEAVE: {
					if(in[q2[j].no]) {
						s2--;
						in[q2[j].no]=0;
					}
					break;
				}
			}
		}
		mans=max(ans,mans);
	}
	printf("%d",mans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
