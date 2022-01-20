#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
	bool operator < (const node &h) const{
		return l<h.l;
	}
}a[1000010],b[1000010];
int x[2000010],f[2][2000010],ans,cnt,maxt1,maxt2;
int bok[2][2][2000010],v[2][2000010];
int n,m1,m2,last1,last2,l,r,j,dep;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		x[++cnt]=a[i].l;x[++cnt]=a[i].r;
		maxt1=max(maxt1,max(a[i].l,a[i].r));
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
		x[++cnt]=b[i].l;x[++cnt]=b[i].r;
		maxt2=max(maxt2,max(b[i].l,b[i].r));
	}
	sort(x+1,x+cnt+1);
	for(int i=1;i<=m1;i++){
		l=1,r=cnt;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(x[mid]<=a[i].l){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		if(x[r]==a[i].l) {
			a[i].l=r;bok[0][0][r]=i;
		}
		else{
			a[i].l=r-1;bok[0][0][r-1]=i;
		}
		l=1,r=cnt;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(x[mid]<=a[i].r){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		if(x[r]==a[i].r) {
			a[i].r=r;bok[0][1][r]=i;
		}
		else {
			a[i].r=r-1;bok[0][1][r-1]=i;
		}
		//cout<<a[i].l<<" "<<a[i].r<<endl;
//		if(a[i].l==178170) cout<<x[r-1]<<endl;
	}
	for(int i=1;i<=m2;i++){
		l=1,r=cnt;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(x[mid]<=b[i].l){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		if(x[r]==b[i].l){
			b[i].l=r;bok[1][0][r]=i;
		}
		else{
			b[i].l=r-1;bok[1][0][r-1]=i;
		} 
		l=1,r=cnt;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(x[mid]<=b[i].r){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		if(x[r]==b[i].r) {
				b[i].r=r;bok[1][1][r]=i;
		}
		else{
				b[i].r=r-1;bok[1][1][r-1]=i;
		}
	}	
	for(int i=1;i<=maxt1;i++){
		if(bok[0][0][i]){
			for(int j=1;j<=n;j++){
				if(v[0][j]<i){
					v[0][j]=a[bok[0][0][i]].r;
					f[0][j]++;
					break;
				}
			}
		}
	}
	
	for(int i=1;i<=maxt2;i++){
		if(bok[1][0][i]){
			for(int j=1;j<=n;j++){
				if(v[1][j]<i){
					v[1][j]=b[bok[1][0][i]].r;
					f[1][j]++;
					break;
				}
			}
		}
	}	
	for(int i=1;i<=n;i++){
		f[0][i]+=f[0][i-1];
		f[1][i]+=f[1][i-1];
//		cout<<f[0][i]<<" "<<f[1][i]<<endl;
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,f[0][i]+f[1][n-i]);
	}
	cout<<ans<<endl;
}
