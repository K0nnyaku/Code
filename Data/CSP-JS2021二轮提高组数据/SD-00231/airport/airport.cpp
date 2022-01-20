#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

int read(){
	int x = 0,w = 1;char ch = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch - '0');ch = getchar();}
	return x * w;
}

int n,m1,m2,cnt;
int a1[100050],b1[100050],max1,min1,to1[100050],in1[100050],out1[100050];
int a2[100050],b2[100050],max2,min2,to2[100050],in2[100050],out2[100050];
int c[300050];
int ans,anss;

bool vis[100050];


int get1(int x){
	memset(vis,0,sizeof vis);
	int tot = 0;
	for(int i = min1;i <= max1;i ++){
		if(vis[i]) continue;
		if(in1[i] == 1){
			if(x) x --,tot ++;
			else vis[to1[i]] = 1;
		}
		if(out1[i] == 1) x++;
	}
	return tot;
}

int get2(int x){
	memset(vis,0,sizeof vis);	
	int tot = 0;
	for(int i = min2;i <= max2;i ++){
		if(vis[i]) continue;
		if(in2[i] == 1){
			if(x) x --,tot ++;
			else vis[to2[i]] = 1;
		}
		if(out2[i] == 1) x++;
	}
	return tot;
}

int ef(int a[],int n,int x){
	int l = 1,r = n;
	int mid;
	while(l <= r){
		mid = (l + r) >> 1; 
		if(a[mid] == x) return x;
		if(a[mid] < x) l = mid + 1;
		if(a[mid] > x) r = mid - 1;
	}
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read(),m1 = read(),m2 = read();
	for(int i = 1;i <= m1;i ++) c[++ cnt] = a1[i] = read(),c[++ cnt] = b1[i] = read();
	for(int i = 1;i <= m2;i ++) c[++ cnt] = a2[i] = read(),c[++ cnt] = b2[i] = read();
	
	sort(c + 1,c + cnt + 1);
	
	for(int i = 1;i <= m1;i ++){

		a1[i] = ef(c,cnt,a1[i]);
		b1[i] = ef(c,cnt,b1[i]);

		max1 = max(max1,b1[i]);
		min1 = min(min1,a1[i]);
		to1[a1[i]] = b1[i];
		in1[a1[i]] = 1;
		out1[b1[i]] = 1;
	}
	for(int i = 1;i <= m2;i ++){

		a2[i] = ef(c,cnt,a2[i]);
		b2[i] = ef(c,cnt,b2[i]);

		max2 = max(max2,b2[i]);
		min2 = min(min2,a2[i]);
		to2[a2[i]] = b2[i];
		in2[a2[i]] = 1;
		out2[b2[i]] = 1;
	}
	//ÀëÉ¢»¯ 
	
	for(int i = 0;i <= n;i ++){
		ans = 0;
		ans += get1(i);
		ans += get2(n - i);
		anss = max(anss,ans);
	}
	
	printf("%d",anss);
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}
