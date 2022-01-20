#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int n,m1,m2;
int a[5][100005],b[5][100005];

int rd(){
	int w=0,r=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){	
		if(ch=='-') r=-1;
		ch=getchar();	
	}
	while(ch>='0'&&ch<='9'){
		w=(w<<1)+(w<<3)+ch-48;
		ch=getchar();	
	}
	return r*w;
}

int main(){

	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	
	return 0;

}
