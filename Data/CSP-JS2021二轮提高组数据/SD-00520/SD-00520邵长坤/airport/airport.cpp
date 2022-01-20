#include<cstdio>
#include<algorithm> 

using namespace std;

const int N=100005;
struct pla{
	int s,e;
	bool operator<(const pla &b)const{
		return s<b.s;
	}
}a[N],b[N];
bool aus[N],bus[N]; 
int c[N],mid=N>>1;

inline int read(){
	int a=0,f=1;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=-1;s=getchar();}
	while(s<='9'&&s>='0'){a=a*10+s-'0';s=getchar();}
	return a*f;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=read(),gn=read(),gj=read();
	for(int i=0;i<gn;i++){
		a[i].s=read();
		a[i].e=read();
	} 
	for(int i=0;i<gj;i++){
		b[i].s=read();
		b[i].e=read();
	}
	sort(a,a+gn);
	sort(b,b+gj);
	int lcs=0,rcs=1;
	while(1){
		bool nd=0;
		int lste=0;
		for(int i=0;i<gn;i++){
			if(a[i].s>lste&&!aus[i]){
				nd=1;
				aus[i]=1;
				lste=a[i].e;
				c[mid-lcs]++;
			}
		}
		lcs++;
		if(!nd)break;
	}
	while(1){
		bool nd=0;
		int lste=0;
		for(int i=0;i<gj;i++){
			if(b[i].s>lste&&!bus[i]){
				nd=1;
				bus[i]=1;
				lste=b[i].e;
				c[mid+rcs]++;
			}
		}
		rcs++;
		if(!nd)break;
	}
	int l=mid-lcs+2,r=mid+rcs-2;
	int mx=0;
	for(int i=mid-n+1;i<=mid+1;i++){
		int sum=0;
		for(int j=i;j<=i+n-1;j++){
			sum+=c[j];
		}
		mx=sum>mx?sum:mx;
	}
	printf("%d\n",mx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

