#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct hb{
	long long l,r;
};hb gn[100011],gj[100011],gn1[100011],gj1[100011];
long long nt[100011],nx[100011],bk[100011],rd[100011],a[100011],b[100011];
bool shah(hb x,hb y){return x.l<y.l?1:0;}
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
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long i,mid,j,k,m1,m2,n,l1,r1,q,maxx=-2147483647;
	n=readx();m1=readx();m2=readx();
	for(i=1;i<=m1;i++)
		{gn[i].l=readx();gn[i].r=readx();
		gn1[i].l=gn[i].l;gn1[i].r=gn[i].r;}
	for(i=1;i<=m2;i++)
		{gj[i].l=readx();gj[i].r=readx();
		gj1[i].l=gj[i].l;gj1[i].r=gj[i].r;}
	sort(gn+1,gn+m1+1,shah);sort(gj+1,gj+m2+1,shah);
	for(i=1;i<=m1;i++)if(!bk[i]){j=i;rd[i]++;
		while(1){bk[j]++;
			l1=j+1;r1=m1;
			if(gn[m1].l<=gn[j].r)break;
			while(l1<=r1){
				mid=(l1+r1)/2;
				if(gn[mid].l>gn[j].r&&gn[mid-1].l<=gn[j].r)break;
				else {if(gn[mid].l>gn[j].r)r1=mid-1;else l1=mid+1;}
			}for(k=mid;bk[k];k++);
			if(k>m1){m1=mid;break;}
			nt[j]=k;j=k;
		}
	}k=0;
	for(i=1;i<=m1;i++)if(rd[i]){k++;
		for(j=i;j;j=nt[j])a[k]++;
		a[k]+=a[k-1];
	}memset(bk,0,sizeof(bk));memset(rd,0,sizeof(rd));memset(nt,0,sizeof(nt));
	for(i=1;i<=m2;i++)if(!bk[i]){j=i;rd[i]++;
		while(1){bk[j]++;
			l1=j+1;r1=m2;
			if(gj[m2].l<=gj[j].r)break;
			while(l1<=r1){
				mid=(l1+r1)/2;
				if(gj[mid].l>gj[j].r&&gj[mid-1].l<=gj[j].r)break;
				else {if(gj[mid].l>gj[j].r)r1=mid-1;else l1=mid+1;}
			}for(k=mid;bk[k];k++);
			if(k>m2){m2=mid;break;}
			nt[j]=k;j=k;
		}
	}q=0;
	for(i=1;i<=m2;i++)if(rd[i]){q++;
		for(j=i;j;j=nt[j])
			b[q]++;
		b[q]+=b[q-1];
	}for(i=0;i<=n;i++){
		if(a[i]+b[n-i]>maxx)
			maxx=a[i]+b[n-i];
	}printf("%lld\n",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
