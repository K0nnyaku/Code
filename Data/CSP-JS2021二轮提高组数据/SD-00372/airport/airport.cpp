#include <cstdio>
#include <algorithm>
#include <queue> 
using namespace std;
long long int n,m1,m2,st1,st2,cnt1,cnt2,maxn;
priority_queue<long long int,vector<long long int>,greater<long long int> >q;
struct data{
	long long int l,r;
}rec1[200001],rec2[200001];
long long int read(void){
	long long int tans=0;
	char ch=getchar();
	while((ch<'0')||(ch>'9'))
		ch=getchar();
	while((ch>='0')&&(ch<='9')) 
		tans=tans*10+ch-'0',
		ch=getchar();
	return tans;
};
inline bool cmp(const data a,const data b){
	return (a.l<b.l)||((a.l==b.l)&&(a.r<b.r)); 
};
inline long long int fmax(const long long int a,const long long int b){
	return a>b?a:b;
};
int main(void){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(register long long int i=1;i<=m1;i++)
		rec1[i].l=read(),
		rec1[i].r=read();
	for(register long long int i=1;i<=m2;i++)
		rec2[i].l=read(),
		rec2[i].r=read();
	sort(rec1+1,rec1+m1+1,cmp);
	sort(rec2+1,rec2+m2+1,cmp);
	for(register long long int i=0;i<=n;i++){
		st1=i,
		st2=n-i,
		cnt1=cnt2=0;
		while(q.empty()==false)
			q.pop();
		if(st1>=1){
			q.push(rec1[1].r);
			cnt1++;
		};
		for(register long long int j=2;j<=m1;j++){
			while((q.empty()==false)&&(q.top()<rec1[j].l))
				q.pop();
			if(q.size()<st1){
				q.push(rec1[j].r);
				cnt1++;
			};
		};
		while(q.empty()==false)
			q.pop();
		if(st2>=1){
			q.push(rec2[1].r);
			cnt2++;
		};
		for(register long long int j=2;j<=m2;j++){
			while((q.empty()==false)&&(q.top()<rec2[j].l))
				q.pop();
			if(q.size()<st2){
				q.push(rec2[j].r);
				cnt2++;
			};
		};
		maxn=fmax(maxn,cnt1+cnt2);
	};
	printf("%lld\n",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
};
