#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt,n,m1,m2,temp[4040],leave[4040];
struct unit{
	int l,r;
	bool operator < (const unit t)const{
		return l<t.l;
	}
}a[1010],b[1010];
void init(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i].l>>a[i].r;
		temp[++cnt]=a[i].l,temp[++cnt]=a[i].r;
	}
	for(int i=1;i<=m2;i++){
		cin>>b[i].l>>b[i].r;
		temp[++cnt]=b[i].l,temp[++cnt]=b[i].r;
	}
	sort(temp+1,temp+1+cnt);
	for(int i=1;i<=m1;i++){
		a[i].l=lower_bound(temp+1,temp+1+cnt,a[i].l)-temp;
		a[i].r=lower_bound(temp+1,temp+1+cnt,a[i].r)-temp;
	}
	for(int i=1;i<=m2;i++){
		b[i].l=lower_bound(temp+1,temp+1+cnt,b[i].l)-temp;
		b[i].r=lower_bound(temp+1,temp+1+cnt,b[i].r)-temp;
	}
    sort(a+1,a+1+m1);
    sort(b+1,b+1+m2);
}
int disp(){
	int csq=0;
	for(int i=0;i<=n;i++){
		int now=1,tot=0,ans=m1+m2;
		fill(leave,leave+1+cnt+3,0);
	    for(int j=0;j<=cnt+3;j++){
		    tot-=leave[j];
		    if(a[now].l==j){
		    	if(tot<i)leave[a[now].r]=1,tot++;
		    	else ans--;
				now++;
			}
	    }
	    now=1,tot=0;
		fill(leave,leave+1+cnt+3,0);
	    for(int j=0;j<=cnt+3;j++){
		    tot-=leave[j];
		    if(b[now].l==j){
		    	if(tot<n-i)leave[b[now].r]=1,tot++;
		    	else ans--;
				now++;
			}
	    }
	    csq=max(ans,csq);
	}
	return csq;
}
int main(){
	init();
	cout<<disp();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
