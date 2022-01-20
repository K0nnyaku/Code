#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

int rd();
int n,m1,m2;
const int MUN=100005;

struct air {
	int l,r;
} a[MUN],b[MUN];

int sizea[MUN],sizeb[MUN],lena[MUN],lenb[MUN];
int ans1[MUN];
int ans2[MUN];

bool cmp(air fi,air sc) {
	return fi.l<sc.l;
}

void solve1() {
	std::sort(a+1,a+m1+1,cmp);
	std::sort(b+1,b+m2+1,cmp);
	sizea[0]=1;
	sizea[1]=a[1].r;
	lena[1]=1;
	for(int i=2;i<=m1;i++){
		bool falg=0;
		for(int j=1;j<=sizea[0];j++){
			if(a[i].l>=sizea[j]){
				sizea[j]=a[i].r;
				lena[j]++;
				falg=1;
				break;
			}
		}
		if(falg==0){
			sizea[0]++;
			sizea[sizea[0]]=a[i].r;
			lena[sizea[0]]=1;
		}
	}
	
	sizeb[0]=1;
	sizeb[1]=b[1].r;
	lenb[1]=1;
	for(int i=2;i<=m2;i++){
		bool falg=0;
		for(int j=1;j<=sizeb[0];j++){
			if(b[i].l>=sizeb[j]){
				sizeb[j]=b[i].r;
				lenb[j]++;
				falg=1;
				break;
			}
		}
		if(falg==0){
			sizeb[0]++;
			sizeb[sizeb[0]]=b[i].r;
			lenb[sizeb[0]]=1;
		}
	}
//	for(int i=1;i<=sizeb[0];i++) printf("%d ",lenb[i]);
}

void solve2(){
	
	int ml=sizea[0];
	int mr=sizeb[0];
	
	for(int i=1;i<=ml;i++) ans1[i]=lena[i]+ans1[i-1];
	for(int i=1;i<=mr;i++) ans2[i]=lenb[i]+ans2[i-1];
	if(n>=ml+mr) {
		printf("%d\n",ans1[ml]+ans2[mr]);
		return ;
	}
//	for(int i=1;i<=ml;i++){
//		for(int j=1;j<=mr;j++){
//			if(i+j>n) break;
//			ans[i][j]=ans[i][0]+ans[0][j];
//		}
//	}
//	for(int i=0;i<=ml;i++){
//		for(int j=0;j<=mr;j++){
//			printf("%d ",ans[i][j]); 
//		}
//		putchar('\n');
//	}
	int nans=0;
	for(int i=0;i<=std::min(mr,n);i++){
		nans=std::max(nans,ans1[n-i]+ans2[i]); //ans[n-i][i]
	}
	printf("%d\n",nans); 
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=rd();
	m1=rd();
	m2=rd();
	for(int i=1; i<=m1; i++) {
		a[i].l=rd();
		a[i].r=rd();
	}
	for(int i=1; i<=m2; i++) {
		b[i].l=rd();
		b[i].r=rd();
	}
	solve1();
	solve2();
	return 0;
}

int rd() {
	char ch=getchar();
	int f,c=0;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		c=c*10+ch-'0';
		ch=getchar();
	}
	return c*f;
}
