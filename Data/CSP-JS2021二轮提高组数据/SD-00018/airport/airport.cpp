#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100100
int n,m1,m2,chka[N],chkb[N];
struct node{
	int x,y;
}a[N],b[N];
struct sig{
	int l,r,minn,mint;
}Tree[N];
bool cmp(node x,node y){
	return x.x<y.x;
}
void built(int x,int l,int r){
	if(l>r) return;
	Tree[x].l=l;Tree[x].r=r;
	Tree[x].minn=0;Tree[x].mint=l;
	if(l-r){
		int mid=(l+r)>>1;
		built(x<<1,l,mid);
		built((x<<1)+1,mid+1,r);
	}
}
void add2(int x,int y,int z){
	int l=Tree[x].l,r=Tree[x].r,mid=(l+r)>>1;
	if(l==r){
		Tree[x].minn=z;
		return;
	}
	if(y<=mid) add2(x<<1,y,z);	
	else add2((x<<1)+1,y,z);
	if(Tree[x<<1].minn<=Tree[(x<<1)+1].minn){
		Tree[x].minn=Tree[x<<1].minn;
		Tree[x].mint=Tree[x<<1].mint;
	}
	else{
		Tree[x].minn=Tree[(x<<1)+1].minn;
		Tree[x].mint=Tree[(x<<1)+1].mint;
	}
}
int chk(int x){
	int i,ans=0;
	built(1,1,x);
	for(i=1;i<=m1&&x;i++){
		if(a[i].x>Tree[1].minn){
			add2(1,Tree[1].mint,a[i].y);
			ans++;
		}
	}
	built(1,1,n-x);
	for(i=1;i<=m2&&n-x;i++){
		if(b[i].x>Tree[1].minn){
			add2(1,Tree[1].mint,b[i].y);
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	int i,tmp1,tmp2;
	for(i=1;i<=m1;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=m2;i++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	tmp1=chk(0);
	for(i=1;i<=n;i++,tmp1=tmp2){
		tmp2=chk(i);
		if(tmp1>tmp2) break;
	}
	printf("%d",tmp1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
