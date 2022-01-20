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
long long cnt = 0,sexyn,sexyk,wenhao = 0,cnt1 = 0,cnt2 = 0;
int vis[507],tuunn[507],las;
char s[507];
stack < int > sta;
bool cmp1(int a,int b){
	return a > b;
}
int xiaozhan(long long lef){
//	for (int t = 0;t < zk;t ++){
//		if (zuokuohao[t] == lef) zk = t;
//	}
////	for (int i = 0;i < 12;i++) cout << zuokuohao[i] <<' ';
////	cout<<endl;
////	for (int i = 0;i < 12;i++) cout << youkuohao[i] <<' ';
////	cout<<endl;
////	cout<<youkuohao[zk]<<endl;
//	return youkuohao[zk];
	for (int t = sexyn - 1;t >=0;t --){
		if (sta.top() == lef){
			for (int e = t;e >= lef;e--){
				if (tuunn[e] == 2) return e; 
			}
		}
        if (tuunn[t] == 2) {
    		sta.pop();
		}
	}
}
bool check(){
	if(tuunn[1] == 3 || tuunn[sexyn] == 3 || tuunn[1] != 1 || tuunn[sexyn] != 2) return false;
	if(cnt1 != cnt2) return false;
    for (int u = 2;u < sexyn;u++){
    	if (tuunn[u] == 1) {
    		for (int t = 2;t < sexyn;t ++){
        	if (tuunn[t] == 1) {
        		sta.push(t);
			}
		}
    		int cmp = xiaozhan(u);
    		if ((tuunn[u - 1] == 3)&&(tuunn[cmp] == 2)&&(tuunn[cmp + 1] == 3)) return false;
		}
    	if (tuunn[u] == 3) {
    		long long starnum = u;
    		long long cntstars = 0;
    		while (1){
    			if (tuunn[starnum] != 3) break;
    			starnum ++;
    			cntstars ++;
			}
			if (cntstars > sexyk) return false;
		}
	}
	return true;
}
void dfs(long long lim){//lim指问号个数
	if (lim == 0){
//		memset(zuokuohao,0,sizeof zuokuohao);
//		memset(youkuohao,0,sizeof youkuohao);
//		zk = 0;
//		yk = 0;
//		for (int t = 1;t <= sexyn;t++){
//		if (tuunn[t] == 1 ) {
//			zuokuohao[zk] = t;
//			zk ++;
//		}
//		if (tuunn[t] == 2) {
//			youkuohao[yk] = t;
//			yk ++;
//		}
		if (check() == true){
			cnt ++;
//		for (int i = 1;i <= sexyn;i++) cout<<tuunn[i];
//		cout<<endl;
//		cout<<cnt1<<" "<<cnt2<<endl;
//		for (int t = 1;t <= sexyn;t++){
//			cout<<tuunn[t]<<" ";
//		}
//		cout<<endl;
		}
		return;
	}
	for (int t = 1;t <= sexyn;t ++){
		if (vis[t] == 1){
			vis[t] = 0;
			tuunn[t] = 1,cnt1 ++;
			dfs(lim - 1);
			cnt1--;
			tuunn[t] = 2,cnt2 ++;
			dfs(lim - 1);
			cnt2--;
			tuunn[t] = 3;
			dfs(lim - 1);
			vis[t] = 1;
			return;
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
    sexyn = read();sexyk = read();
    scanf("%s",s + 1);
//    for (int i = 1;i <= sexyn;i ++) cout<<s[i];
	for (int i = 1;i <= sexyn;i++){
		if (s[i] == '(') {
			tuunn[i] = 1,cnt1++;
		}
		if (s[i] == ')') {
			tuunn[i] = 2,cnt2++;
		}
		if (s[i] == '*') tuunn[i] = 3;
		if (s[i] == '?') wenhao ++,vis[i] = 1;
	}
	dfs(wenhao);
	cout<<cnt<<endl;
//	for (int i = 1;i <= sexyn;i ++) cout<<tuunn[i];
//	cout<<wenhao;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
