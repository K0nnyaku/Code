#include<bits/stdc++.h>
using namespace std;
struct air {
	int astart;
	int bend;
};
air a1[10001];
air a2[10001];
struct numk {
	int anum=0;
	struct bj {
		int ast=0;
		int ben=0;
	} bjihao;
};
numk num1[100001];
numk num2[100001];
inline int read() {
	int x=0,y=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')
			y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+(c-'0'),c=getchar();
	}
	return x*y;
}
void write(int x) {
	if(x<0) {
		putchar('-');
	}
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
}

int main() {
//	freopen("airport.in","r",stdin);
//	freopen("airport.out","w",stdout);
	int n,m,k;
	n=read();//廊桥数量
	m=read();//a1数量
	k=read();//a2数量
	int nummax1=-1;
	for(int i=0; i<m; i++) {
		cin>>a1[i].astart;
		cin>>a1[i].bend;
		nummax1=max(nummax1,a1[i].bend);
		num1[a1[i].astart-1].bjihao.ast=i;
		num1[a1[i].bend-1].bjihao.ben=i;
		for(int k=a1[i].astart; k<=a1[i].bend; k++) {
			num1[k].anum++;
		}
		//输入国内 开始结束时间
	}
	int imax1=-1,imax2=-1;
	int nummax2=-1;
	for(int i=0; i<k; i++) {
		cin>>a2[i].astart;//输入国外开始结束时间
		cin>>a2[i].bend;
		nummax2=max(nummax2,a2[i].bend);//覆盖的长度
		num2[a2[i].astart-1].bjihao.ast=i;//标记开始
		num2[a2[i].bend-1].bjihao.ben=i;//标记结束
		for(int k=a2[i].astart; k<=a2[i].bend; k++) {
			num2[k].anum++;
		}
	}

	for(int i=0; i<nummax1; i++) {
		imax1=max(imax1,num1[i].anum);//都能容下的数量
	}
	for(int i=0; i<nummax1; i++) {
		imax2=max(imax2,num2[i].anum);
	}
	int imax=-1;
	int zhan1,zhan2;
	int now;
	for(int i=0; i<n; i++) {
		zhan1=n-i;
		zhan2=i;
		for(int j=0; j<=nummax1; j++) {
			if(num1[j].anum>zhan1) {
				for(int k=j; k>=0; k++) {
					if(num1[k].bjihao.ast!=0) {
						now=num1[k].bjihao.ast;
						for(int u=now;; u++) {
							if(num1[u].bjihao.ben==now) {
								break;
							} else {
								num1[u].anum--;
							}
							m--;
						}
					}
				}
			}
		}
		for(int j1=0; j1<=nummax2; j1++) {
			if(num1[j1].anum>zhan2) {
				for(int k1=j1; k1>=0; k1++) {
					if(num1[k1].bjihao.ast!=0) {
						now=num1[k1].bjihao.ast;
						for(int u1=now; num1[u1].bjihao.ben==now; u1++) {
							num1[u1].anum--;
							k--;
						}
					}
				}
			}
		}
		imax=max(imax,k+m);
	}
	cout<<imax;
	return 0;
}




