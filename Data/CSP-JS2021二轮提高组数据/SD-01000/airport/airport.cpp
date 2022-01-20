#include<bits/stdc++.h>
using namespace std;
inline long long read() {
	long long x=0,w=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')
		ch=getchar();
	if(ch=='-') {
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
long long n,m;
struct pl {
	long long l,r;
} a[6005],b[6005];
struct jj {
	long long jia,dao;
};
long long ans;
long long m1,m2;
bool cmp(const pl x,const pl y) {
	return x.l<y.l;
}
priority_queue<pair<int,int> > q1;
priority_queue<pair<int,int> > q2;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1; i<=m1; i++) {
		a[i].l=read();
		a[i].r=read();
	}
	sort(a+1,a+1+m1,cmp);
//	for(int i=1;i<=m1;i++)
//	cout<<a[i].l<<" "<<a[i].r<<" ";
	for(int i=1; i<=m2; i++) {
		b[i].l=read();
		b[i].r=read();
	}
	sort(b+1,b+1+m2,cmp);
	bool k1=0,k2=0;
	int t1=0,t2=0,fj1=0,fj2=0;
	long long anss=0;
	for(int i=0; i<=n; i++) {
		fj1=i;
		fj2=n-i;
		int cnt1=0,cnt2=0;
		anss=0;
		for(int k1=1; k1<=m1; k1++) {
			//int l=q.size();
			while(!q1.empty()&&fj1<i) {
				int ls=q1.top().first;
				ls=-ls;
				if(ls<=a[k1].l) {
					q1.pop();
					fj1++;
				}
				else
				break;
			}
			if(fj1>0) {
			//	cout<<"%"<<k1<<"%";
				anss++;
				q1.push({-a[k1].r,k1});
				fj1--;
			}
		}
	//	cout<<endl;
		while(!q1.empty())
		q1.pop();
		//cout<<anss<<endl;
		for(int k2=1; k2<=m2; k2++) {
			//int l=q.size();
			while(!q2.empty()&&fj2<(n-i)) {
			//	cout<<1;
				int ls=q2.top().first;
				ls=-ls;
				if(ls<=b[k2].l) {
					q2.pop();
					fj2++;
				}
				else
				break;
			}
			//cout<<fj2<<" ";
			if(fj2>0) {
			//	cout<<"%"<<k2<<"%"; 
				//cout<<"p";
				anss++;
				q2.push({-b[k2].r,k2});
				fj2--;
			}
		}
	//	cout<<endl;
		while(!q2.empty())
		q2.pop();
	//	cout<<anss<<endl;
		ans=max(anss,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
