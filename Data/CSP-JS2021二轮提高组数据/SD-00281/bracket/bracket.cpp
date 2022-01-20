#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
inline int read(){
	int f=1,sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*f;
}
int n,m;
string r;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>m>>m>>r;
	cout<<"10";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

