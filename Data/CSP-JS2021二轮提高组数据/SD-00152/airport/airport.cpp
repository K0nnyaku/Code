#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
long long read(){
	long long x = 0,w = 1;char ch = getchar();
	while (!isdigit(ch)){if (ch == '-') w = -1;ch = getchar();}
	while (isdigit(ch)){x = x * 10 + ch - '0';ch = getchar();}
	return x * w;
}
long long sexyn,sexym1,sexym2;
long long limi[5007];
long long cnt = 0,maaaxxx = -11451419,sum;
struct guonei{
	long long lef1,rig1;
}nei[5007];
struct guowai{
	long long lef2,rig2;
}wai[5007];
bool cmp1(const guonei &a,const guonei &b){
	return a.lef1 < b.lef1;
}
bool cmp2(const guowai &a,const guowai &b){
	return a.lef2 < b.lef2;
}
long long searcguonei(long long lim){
	memset(limi,0,sizeof limi);
	cnt = 0;
	for (int j = 0;j <sexym1;j++){
		if (limi[nei[j].lef1] < lim){
			for (int u = nei[j].lef1;u <= nei[j].rig1;u++) limi[u] ++;
			cnt ++;
		}
	}
	return cnt;
}
long long searcguowai(long long lim){
	memset(limi,0,sizeof limi);
	cnt = 0;
	for (int j = 0;j <sexym2;j++){
		if (limi[wai[j].lef2] < lim){
			for (int u = wai[j].lef2;u <= wai[j].rig2;u++) limi[u] += 1;
			cnt ++;
		}
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	sexyn = read();
	sexym1 = read();
	sexym2 = read();
	for(int i = 0;i < sexym1;i++){
		nei[i].lef1 = read();
		nei[i].rig1 = read();
	}
	sort(nei,nei + sexym1,cmp1);
	for(int i = 0;i < sexym2;i++){
		wai[i].lef2 = read();
		wai[i].rig2 = read();
	}//0是起，1是终
	sort(wai,wai + sexym2,cmp2);
	for (int i = 0;i <= sexyn;i++){//i是国内的，n-i是国外的 
//			cout<<searcguonei(i)<<" ";
//			cout<<searcguowai(sexyn - i)<<endl;
			sum = searcguowai(sexyn - i) + searcguonei(i);
			if (maaaxxx <= sum) maaaxxx = sum; 
	}
	cout<<maaaxxx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
