#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include<vector>
#define ll long long

using namespace std;

priority_queue <ll, vector<ll>,greater<ll> > q;
ll n,m1,m2,cnt1,ans,cnt2,now1,now2,idx1[100010],idx2[100010],vis1[100010],vis2[100010],t1[100010],t2[100010],qz1[100010],qz2[100010];
struct node{
	ll l,r;
}a[100010],b[100010];
struct pt{
	ll p,bh,op;
}c[400010],d[400010];
inline ll Read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*w;
}
inline bool cmp(pt x,pt y){
	return x.p<y.p;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=Read();m1=Read();m2=Read();
	for(int i=1;i<=m1;i++){
		a[i].l=Read();a[i].r=Read();
		c[++cnt1].bh=i;
		c[cnt1].p=a[i].l;
		c[++cnt1].bh=i;
		c[cnt1].p=a[i].r;
		c[cnt1].op=1;
	} 
	for(int i=1;i<=m2;i++){
		b[i].l=Read();b[i].r=Read();
		d[++cnt2].bh=i;
		d[cnt2].p=b[i].l;
		d[++cnt2].bh=i;
		d[cnt2].p=b[i].r;
		d[cnt2].op=1;
	}
	sort(c+1,c+1+cnt1,cmp);
	sort(d+1,d+1+cnt2,cmp);
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	for(int i=1;i<=cnt1;i++){
		if(!c[i].op){//×ó¶Ëµã 
			if(!q.empty()) now1++,t1[q.top()]++,idx1[c[i].bh]=q.top(),q.pop();
			else{
				vis1[c[i].bh]=1;
			}
		}else{//ÓÒ¶Ëµã 
			if(!vis1[c[i].bh]){
				now1--;
				q.push(idx1[c[i].bh]);
			}
		}
	} 
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	for(int i=1;i<=cnt2;i++){
		if(!d[i].op){//×ó¶Ëµã 
			if(!q.empty()) now2++,t2[q.top()]++,idx2[d[i].bh]=q.top(),q.pop();
			else{
				vis2[d[i].bh]=1;
			}
		}else{//ÓÒ¶Ëµã 
			if(!vis2[d[i].bh]){
				now2--;
				q.push(idx2[d[i].bh]);
			}
		}
	} 
	for(int i=1;i<=n;i++){
		qz1[i]=qz1[i-1]+t1[i];
	}
	for(int i=1;i<=n;i++){
		qz2[i]=qz2[i-1]+t2[i];
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,qz1[i]+qz2[n-i]);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}

