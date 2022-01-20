#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 210001
#define inf 2147483647
#include<bits/stdc++.h>
using namespace std; 

//--------------------------------------------------------

struct node{
	int a,b;
}e[maxn],sb[maxn];

int n,m1,m2,ans=-1,xx,yy,x,y,js[maxn],t;
bool f1;

//---------------------------------------------------------

bool cmp(node a,node b){
	return a.a<b.a;
}

int g(int x,int m,int f){
	xx=0;t=0;
	memset(js,0,sizeof(js));
	if(x==0) return 0;
	xx++;x--; js[1]=1;t=1;
	for(int l=2;l<=m;l++){
		if(x>=0){
			f1=0;
			for(int k=1;k<=t;k++){
				if(js[k]!=0){
					if(f==1){
			            if(e[l].a>=e[js[k]].b){
			            	xx++;js[++t]=l;f1=1;js[k]=0;
		            	}
					}
					else if(f==2){
						if(sb[l].a>=sb[js[k]].b){
			            	xx++;js[++t]=l;f1=1;js[k]=0;
		            	}
					}
				}
			}
			if(!f1){
				if(x>0){
			    	xx++;x--; js[++t]=l;
				}
				else continue;
			}
		}
	}
	return xx;
}

//----------------------------------------------------------

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d""%d""%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d""%d",&e[i].a,&e[i].b);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d""%d",&sb[i].a,&sb[i].b);
	}
	sort(e+1,e+m1+1,cmp);
	sort(sb+1,sb+m2+1,cmp);
	for(int i=0;i<=n;i++){
		x=i,y=n-i;
		ans=max(ans,g(x,m1,1)+g(y,m2,2));
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

