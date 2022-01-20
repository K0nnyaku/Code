#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,t,sumc=0,heada=1,taila,headb=1,tailb;
int a[500005],b[500005];
int buzhou[500005];
int maxn=1;
bool flag=0;
bool check()
{
	for(int i=1;i<=n;i++) {
		if(b[i]!=b[2*n+1-i]) {
			return 0;
		}
	}
	return 1;
}
void dfs(int step)
{
	if(flag==1)
	{
		return;
	}
	if(step==2*n+1) {
		sumc++;
		if(check())
		{
			for(int i=1;i<=2*n;i++) {
				if(buzhou[i]==1) {
					cout<<"L";
				}else{
					cout<<"R";
				}
			}
			printf("\n");
			flag=1;
			return;
		}
		if(sumc>=maxn) {
			printf("-1\n");
			flag=1;
			return;
		}
	}else{
		buzhou[step]=1;
		b[tailb]=a[heada];
		heada++;
		tailb++;
		dfs(step+1);
		heada--;
		tailb--;
		buzhou[step]=2;
		b[tailb]=a[taila];
		taila--;
		tailb++;
		dfs(step+1);
		taila++;
		tailb--;
	}
	
	
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
    scanf("%d",&t);
    for(int u=0;u<t;u++) {
    	scanf("%d",&n);
    	memset(buzhou,0,sizeof(buzhou));
    	memset(b,0,sizeof(b));
    	flag=0;
    	sumc=0;
    	heada=1;
    	headb=1;
    	taila=2*n;
    	tailb=1;
    	maxn=1;
    	for(int i=1;i<=2*n;i++) {
    		maxn*=2;
    	}
    	for(int i=1;i<=2*n;i++) {
    		scanf("%d",&a[i]);
    	}
    	if(t==1) {
    		printf("-1\n");
    		return 0;
    	}
    	dfs(0);
    }
	return 0;
}

