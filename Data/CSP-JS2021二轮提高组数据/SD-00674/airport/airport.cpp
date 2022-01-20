#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define il inline
#define re register
using namespace std;
il int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct air {
	int jl,qf;
} m11[100000],m22[100000];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,max1=1,max2=1;
	n=read();
	m1=read();
	m2=read();
	for(re int i=1; i<=m1; i++) {
		m11[i].jl=read();
		m11[i].qf=read();
	}
	for(re int i=1; i<=m2; i++) {
		m22[i].jl=read();
		m22[i].qf=read();
	}

	for(re int i=1; i<m1; i++) {
		for(re int j=2; j<=m1; j++) {

			int y=i,f1=0;
			do {
				if (m11[y].qf<m11[j].jl) {
					f1=1;
				}
				y--;
			} while(y!=0);
			if(f1==0) {
				max1++;
			}
		}
	}
	for(re int i=1; i<m2; i++) {
		for(re int j=2; j<=m2; j++) {

			int y=i,f1=0;
			do	 {
				if (m22[y].qf<m22[j].jl) {
					f1=1;                                          
				}
				y--;
			} while(y!=0);
			if(f1==0) {
				max2++;
			}
		}
	}
	cout<<max(max1,max2)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


