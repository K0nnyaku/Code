#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m_1,m_2;
struct Plane{
	int St,En;
	bool operator < (const Plane &tmp) const{
		return En>tmp.En;
	}
}a[100010],b[100010];

bool cmp(const Plane &A,const Plane &B){
	return A.St<B.St;
}
void BoliWork(){
	int maxn=0;
	for(int i=0;i<=n;i++){
		int Now=n-i,ans1=0,ans2=0;
		priority_queue<Plane>q;
		for(int j=1;j<=m_1;j++){
			if(q.size()<i) ans1++,q.push(a[j]);
			else if(q.size()==i){
				while(!q.empty() && q.top().En<=a[j].St) q.pop();
				if(q.size()==i) continue;
				q.push(a[j]);ans1++;
			}
		}
	
		priority_queue<Plane>Q;
		for(int j=1;j<=m_2;j++){
			if(Q.size()<Now) ans2++,Q.push(b[j]);
			else if(Q.size()==Now){
				while(!Q.empty() && Q.top().En<=b[j].St) Q.pop();
				if(Q.size()==Now) continue;
				Q.push(b[j]);ans2++;
			}
		} 
		maxn=max(maxn,ans1+ans2);
	}
	printf("%d",maxn);
}

template<typename T>
void read(T &num){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	num=x*f;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m_1);read(m_2);
	for(int i=1;i<=m_1;i++){
		read(a[i].St);read(a[i].En);
	}
	
	for(int i=1;i<=m_2;i++){
		read(b[i].St);read(b[i].En);
	}
	sort(a+1,a+m_1+1,cmp);
	sort(b+1,b+m_2+1,cmp);
	BoliWork();	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

