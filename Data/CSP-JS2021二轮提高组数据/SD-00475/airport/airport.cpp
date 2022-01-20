#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std; 
const int N=10000+10; 
struct node{
	int x,y;
	bool f;
};
node a[N];node b[N];
int n,m,q;
int ans=-1;
bool cmp(node e,node f){return e.x<f.x;}
int Max(int e,int f){return (e>f?e:f);}
int ap(int c,int d){
	int r=c,t=d;
	int cnt=0,num=0;
	sort(a+1,a+m+1,cmp);
	sort(b+1,b+q+1,cmp);
	if(c==0){
		for(int i=1;i<=q;++i){
		    if(t>0){t--;b[i].f=1;num++;continue;}
		    for(int j=1;j<i;++j){
			    if(b[i].x>b[j].y&&b[j].f){
				    b[j].f=0;b[i].f=1;
				    num++; 
				    break;
			    } 
		    }
	    }
	}
	else  if(d==0){
		for(int i=1;i<=m;++i){
		    if(r>0){r--;a[i].f=1;cnt++;continue;}
		    for(int j=1;j<i;++j){
			    if(a[i].x>a[j].y&&a[j].f){
				    a[j].f=0;a[i].f=1;
				    cnt++;
				    break;
			    }
		    }
    	}
	}
    else{
    	for(int i=1;i<=m;++i){
		    if(r>0){r--;a[i].f=1;cnt++;continue;}
		    for(int j=1;j<i;++j){
			    if(a[i].x>a[j].y&&a[j].f){
				    a[j].f=0;a[i].f=1;
				    cnt++;
				    break;
			    }
		    }
	    }
	    for(int i=1;i<=q;++i){
		    if(t>0){t--;b[i].f=1;num++;continue;}
		    for(int j=1;j<i;++j){
			    if(b[i].x>b[j].y&&b[j].f){
				    b[j].f=0;b[i].f=1;
				    num++; 
				    break;
			    } 
		    }
	    }
	}
	int g=Max(m,q);
	for(int i=1;i<=g;++i){a[i].f=0;b[i].f=0;}
	return (num+cnt);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i){scanf("%d%d",&a[i].x,&a[i].y);a[i].f=0;}
	for(int i=1;i<=q;++i){scanf("%d%d",&b[i].x,&b[i].y);b[i].f=0;}
	int h=n;
	while(n>=0){
		ans=Max(ans,ap(h-n,n));
		n--;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
