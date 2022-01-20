#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*w;
}
struct node{
	int l,r;
};
node m__1[100005],m__2[100005];
int a1[100005],a2[100005];
bool b1[100005],b2[100005];
int n,m_1,m_2;
bool cmp(node a,node b){
	return a.l<b.l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m_1=read(),m_2=read();
	for(int i=1;i<=m_1;i++){
		m__1[i].l=read(),m__1[i].r=read();
	}
	for(int i=1;i<=m_2;i++){
		m__2[i].l=read(),m__2[i].r=read();
	}
	sort(m__1+1,m__1+1+m_1,cmp);
	sort(m__2+1,m__2+1+m_2,cmp);
	//for(int i=1;i<=m_1;i++)
	//cout<<m__1[i].l<<" ";
	int ans1=min(m_1,n),ans2=min(m_2,n);
	for(int i=1;i<=ans1;i++){
		int rr=0,ll=0;
		int ans=0;
		for(int j=i;j<=m_1;j++){
			if(!b1[j]){
				if(m__1[j].l>rr){
				//cout<<"µÚ"<<i<<endl;
				//cout<<m__1[j].l<<" "<<m__1[j].r<<endl;
				rr=m__1[j].r,ll=m__1[j].l;
				b1[j]=1;
				ans++;
				}
			}
			else continue;
		}
		a1[i]=a1[i-1]+ans;
		if(a1[i]==m_1)
		break;
	}
	for(int i=1;i<=ans2;i++){
		int rr=0,ll=0;
		int ans=0;
		for(int j=i;j<=m_2;j++){
			if(!b2[j]){
				if(m__2[j].l>rr){
				//cout<<"µÚ"<<i<<endl;
				//cout<<m__1[j].l<<" "<<m__1[j].r<<endl;
				rr=m__2[j].r,ll=m__2[j].l;
				b2[j]=1;
				ans++;
				}
			}
			else continue;
		}
		a2[i]=a2[i-1]+ans;
		if(a2[i]==m_2)
		break;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	ans=max(ans,a1[i]+a2[n-i]);
	cout<<ans<<endl;
	return 0;
}
