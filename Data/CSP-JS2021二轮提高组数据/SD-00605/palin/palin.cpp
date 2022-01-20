//T3:100pts???
#include<iostream>
#include<cstdio>
const int N=1000005;
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
int T,n,a[2*N],mp[2*N],p[2*N],p1[2*N];
struct node{
	int l,r;
} loc[2*N];
char chg(int k){
	if (k==1)
	  return 'L';
	else 
	  return 'R';
}
int cnt,l,r,ll,rr,flag;
void sovle(){
	        while (cnt<n){
        	int x=0,y=0;
        	if (loc[a[l-1]].l!=l-1)
        	  x=loc[a[l-1]].l;
        	else
        	  x=loc[a[l-1]].r;
        	if (loc[a[r+1]].l!=r+1)
        	  y=loc[a[r+1]].l;
        	else
        	  y=loc[a[r+1]].r;
        	if (l==1) x=0;
        	if (r==2*n) y=0;
        	if (x==ll||y==ll){
        		p[++cnt]=1;
        		if (x==ll)
        		  l--,p1[n-cnt+1]=1;
        		else
        		  r++,p1[n-cnt+1]=2;
				ll++;
        		continue;
        	}
        	if (x==rr||y==rr){
        	  p[++cnt]=2;
			  if (x==rr)
			    l--,p1[n-cnt+1]=1;
			  else
			    r++,p1[n-cnt+1]=2;
			  rr--;
			  continue;
			}
			flag=true;
			break;
	    }
	}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while (T--){
		n=read();
		for (int i=1;i<=n;i++)
		  mp[i]=0;
		for (int i=1;i<=2*n;i++){
			a[i]=read();
			if (mp[a[i]]!=0){
			  loc[a[i]].l=mp[a[i]];
			  loc[a[i]].r=i;
		    }
			else
			  mp[a[i]]=i;
		}
        flag=false,cnt=1,l=loc[a[1]].r,r=loc[a[1]].r,ll=2,rr=2*n,p[1]=1,p1[n]=1;
        sovle();
	    if (!flag){
	      for (int i=1;i<=n;i++)
	        cout<<chg(p[i]); 
		  for (int i=1;i<=n;i++)
		    cout<<chg(p1[i]);
		  cout<<endl;
	    }
	    else{
	    	flag=false,cnt=1,l=loc[a[2*n]].l,r=loc[a[2*n]].l,ll=1,rr=2*n-1,p[1]=2,p1[n]=1;
	    	sovle();
	    	if (!flag){
	    	for (int i=1;i<=n;i++)
	          cout<<chg(p[i]); 
		    for (int i=1;i<=n;i++)
		      cout<<chg(p1[i]);
		    cout<<endl;
	        }
	        else{
	        	cout<<-1<<endl;
	        }
	    }
	}
	return 0;
}
