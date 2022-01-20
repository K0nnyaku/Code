#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
//ok
int n,m1,m2;
queue<int> q;

struct node{
	int e;
	int s;
}a1[100001],a2[100001];


bool comp(node x,node y){
	return x.s <y.s ;
}

int main() {
//	srand((int)time(NULL));
//	for(int i=1; i<=1000; i++) {
//		cout << rand() << endl;
//	}
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//freopen("airport.out","w",stdout);
	cin >> n >> m1 >> m2;
	for(int i=1;i<=m1;i++){
		cin >> a1[i].s >> a1[i].e;
		//cout << a1[i][1] << " " << a1[i][2] << endl;
	}
	for(int i=1;i<=m2;i++){
		cin >> a2[i].s  >> a2[i].e ;
	}
	sort(a1+1,a1+m1+1,comp);
	sort(a2+1,a2+m2+1,comp);
	
	int maxN=0;
	for(int i=0;i<=n;i++){
		int tot=0;
		int ans=0;
		priority_queue<int,vector<int>,greater<int> > q1;
	//	cout << i << "  ";
		for(int j=1;j<=m1;j++){
			if(i==0) break;
			if(tot<i){
				tot++;
				q1.push(a1[j].e); 
				ans++;
				
	//			cout << j << " ";
			}
			else{
				if(a1[j].s<q1.top()) continue;
				else{
					//cout << q1.top() ;
					q1.pop();
					q1.push(a1[j].e); 
					ans++;
	//				cout << j << " ";
				}
			}
		}//cout << endl;
		tot=0;
		priority_queue<int,vector<int>,greater<int> > q2;
	//	cout << n-i << "  ";
		for(int j=1;j<=m1;j++){
			if(n-i==0) break;
			//
			if(tot<n-i){
				tot++;
				q2.push(a2[j].e); 
				
				ans++;
	//			cout << j << " ";
			}
			else{
				if(a2[j].s<q2.top()) continue;
				else{
					q2.pop();
					q2.push(a2[j].e); 
					ans++;
	//				cout << j << " ";
				}
			}
		}
		if(maxN<ans){
			maxN=ans;
		} 
	//	cout << endl << endl;
	}
	cout << maxN << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
21!9-324@emb

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10


*/
