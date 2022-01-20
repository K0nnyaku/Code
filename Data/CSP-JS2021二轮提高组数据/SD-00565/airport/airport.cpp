#include<bits/stdc++.h>
using namespace std;

int n, x, y;

struct airport{
	long long ct, gt;
	int ty;//ty1是国内机，ty2是国外机 
	int st;//等于1就是入廊了，2为出廊，0就是还没到 
};

airport a[100010];

int sj[100010];

int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> n >> x >> y;
	for(int i = 1; i <= x + y; i++){//输入编号从1到x的国内飞机的各个属性 
		cin >> a[i].ct >> a[i].gt;
		a[i].st = 0;
		if(i <= x)a[i].ty = 1;
		else a[i].ty = 2;
	}//ty-nei == 1, ty-wai == 2
	
	for(int i = 1; i <= x; i++){
		for(int j = i; j <= x; j++){
			if(a[i].ct > a[j].ct)
			swap(a[i], a[j]);
		}
	}
	for(int i = x + 1; i <= x + y; i++){
		for(int j = i; j <= x + y; j++){
			if(a[i].ct > a[j].ct)
			swap(a[i], a[j]);
		}
	}
	
	int gj, wj;
	
	for(int i = 0; i <= n; i++){
		sj[i] = 0;
	}
	
	for(gj = 0; gj <= n; gj++){//假设国内机廊个数，从零到N个； 
		wj = n - gj;//则国外机廊个数就是  n减去国内机廊个数；		
		
		if(gj != 0){//对国内机廊处理 
			int remn = gj; //国内空机廊剩余量 
			for(int i = 1; i <= x; i++){//1~x(m1)								
				for(int j = 1; j < i; j++){
	/*可能一来一走*/if(a[j].st == 1 && (a[j].gt < a[i].ct) ){//停在机廊
						a[j].st = 2;
						remn++;
					}
				}
				if(remn > 0){
					a[i].st = 1;
					sj[gj]++;//停在机廊的飞机的个数
					remn--;
				} 
			}
		}	
		if(wj != 0){//对国外机廊处理 
			int remw = wj; //空机廊剩余量 
			for(int i = x + 1; i <= y + x; i++){//1~x(m1)								
				for(int j = x + 1; j < i; j++){ //FALSE！！！！ 
	/*可能一来一走*/if(a[j].st == 1 && (a[j].gt < a[i].ct) ){//停在机廊
						a[j].st = 2;
						remw++;
					}
				}
				if(remw > 0){
					a[i].st = 1;
					sj[gj]++;//停在机廊的飞机的个数
					remw--;
				}
			}
		}
	}
	sort(sj, sj + n + 1);
	cout << sj[n];
	return 0;
}
