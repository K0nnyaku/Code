#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

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

	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	
	
	return 0;

}
