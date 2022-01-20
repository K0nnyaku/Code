#include <bits/stdc++.h>

using namespace std;

const int N = 100000000;
int n,m1,m2; 
int l[N][3];//飞机
int a,b; 



int mee(int x){
	
	int total = 0;
	int n1,n2;
	n1 = x;//国内廊桥 
	n2 = (x-n);//国外廊桥 
	int l2[N][3];//廊桥飞机起飞时间

	memset(l2,-1,sizeof(l2));
	int b1,b2;//使用廊桥数量 
	 b1 = 0;
	 b2 = 0;
	
	 
	for(int i = 0;i<=N;i++){
		//进厂 
		if(l[i][1] == 11){//国内飞机进厂 
			if(n1>b1){//有空 
				b1++;//多占用一个廊桥
				total++;
				l2[l[i][2]][1] = 11;
			}
		}
		if(l[i][1] == 22){//国外飞机进厂 
			if(n2>b2){//有空 
				b2++;//多占用一个廊桥
				total++;
				l2[l[i][2]][1] = 22;
			}
		}
		//出厂 
		if(l2[i][1] == 11){//国内飞机起飞 
			l2[i][1] = -1;
			b1--;//空一个廊桥 
		}
		if(l2[i][1] == 22){//国内飞机起飞 
			l2[i][1] = -1;
			b2--;//空一个廊桥 
		}
	}
	return total;
} 




int main(){
	
	scanf("%d",&n);
	scanf("%d",&m1);
	scanf("%d",&m2);
	
	for(int i = 1;i<=m1;i++){
		scanf("%d %d",&a,&b); //a是到达时间 
		l[a][1] = 11;//国内飞机
		l[a][2] = b;//起飞时间 
	}
	
	for(int i = 1;i<=m2;i++){
		scanf("%d %d",&a,&b); //b是起飞时间 
		l[a][1] = 22;//国外飞机
		l[a][2] = b;//起飞时间 
	}
	
	int max_planes = 0;
	for(int j = 0;j<=n;j++){
		max_planes = max(mee(j),max_planes);

	}
	cout<<max_planes; 
	
	
	
	return 0;
} 
