#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
int n,mn,mi,ans=0,maxx=0;
struct p{
	long long a,b;
	
}p[100005];

int main()
{
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
 

     cin>>n>>mn>>mi;
    for(int i=0;i<mn+mi;i++){
    	cin>>p[i].a>>p[i].b;
       
	}
	
	int fl=0;
	struct p tmp;
    for(int i=0;i<mn;i++){
    	for(int j=0;j<mn;j++){
    		if(p[i].a>p[j].b)
    		{
    			tmp=p[j];
    			p[j]=p[i];
    			p[i]=tmp;
    			fl=1;
			}
		}
		if(fl==0) break;
		fl=0;
	}
	fl=0;
	for(int i=mn;i<mn+mi;i++){
    	for(int j=mn;j<mn+mi;j++){
    		if(p[i].a>p[j].b)
    		{
    			tmp=p[j];
    			p[j]=p[i];
    			p[i]=tmp;
    			fl=1;
			}
		}
		if(fl==0) break;
		fl=0;
	}
	int brn,bri;
	long long t,mar;
	for(int i=0;i<=n;i++){
		brn=i;
		bri=n-brn;
		t=0;
		mar=p[0].b;
		for(int j=0;j<mn;j++){
			if(p[j].a>t){
				t=p[j].b;
				ans++;
				if(t>mar) brn++;
			
			}else{
				if(brn>0){
					ans++;
					brn--;
					if(t>p[j].b) {
					mar=t;	
					t=p[j].b;	
					}
				}
			}
			
		}
		t=0;
		mar=p[mn].b;
		    for(int j=mn;j<mi;j++){
			if(p[j].a>t){
				t=p[j].b;
				ans++;
				if(t>mar)bri++;
				
			}else{
				if(bri>0){
					ans++;
					bri--;
					if(t>p[j].b) {
					mar=t;	
					t=p[j].b;	
					}
				}
			}
		
		}
		maxx=max(ans,maxx);
		ans=0;
		
	}
	cout<<maxx;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

