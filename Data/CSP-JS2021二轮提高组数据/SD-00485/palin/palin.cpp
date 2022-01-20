#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long l[500011],r[500011],bk[500011],cp[500011],a[500011],n;
char b[500011],c[500011];
long long readx()
{
	long long i,j=1ll;char k=0;
	while(k<48||k>57){
		k=getchar();if(k=='-')j=-1ll; 
	}i=k-48;
	while(1){
		k=getchar();if(k<48||k>57)break;
		i=i*10+k-48;
	}return i*j;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	long long h,i,j,k=0,m,t,p,q,u,v,x,y,z,hsf;t=readx();
	for(h=1;h<=t;h++){
		n=readx();n*=2ll;
		for(i=1;i<=n;i++){a[i]=readx();r[i]=2;}
		for(i=1;i<=n;i++){
			if(!bk[a[i]])bk[a[i]]=i;
			else {cp[bk[a[i]]]=i;cp[i]=bk[a[i]];}
		}for(k=3;k<=n;k++){if(k)r[k]--;hsf=0;
			x=k;y=0;z=n+1ll;u=k;v=k+1;
			while(z-y-1>n/2){
				if(n-z-y+1>0){
					if(b[n-z+y-1]<c[n-z-y+1]){hsf++;}
					if(b[n-z+y-1]>c[n-z-y+1]&&!hsf){memset(b,0,sizeof(b));break;}
				}if(cp[y+1]==u){b[n-z+y]='L';b[z-y-2]='L';y++;u--;continue;}
				if(cp[y+1]==v){b[n-z+y]='L';b[z-y-2]='R';y++;v++;continue;}
				if(cp[z-1]==u){b[n-z+y]='R';b[z-y-2]='L';z--;u--;continue;}
				if(cp[z-1]==v){b[n-z+y]='L';b[z-y-2]='R';z--;v++;continue;}
				memset(b,0,sizeof(b));break;
			}if(b[0])for(i=0;i<n;i++)c[i]=b[i];//printf("%lld %lld\n",z,n);
		}printf("%s\n",c);
	}fclose(stdin);
	fclose(stdout);
	return 0;
}

