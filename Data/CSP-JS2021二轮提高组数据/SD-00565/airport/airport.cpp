#include<bits/stdc++.h>
using namespace std;

int n, x, y;

struct airport{
	long long ct, gt;
	int ty;//ty1�ǹ��ڻ���ty2�ǹ���� 
	int st;//����1���������ˣ�2Ϊ���ȣ�0���ǻ�û�� 
};

airport a[100010];

int sj[100010];

int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> n >> x >> y;
	for(int i = 1; i <= x + y; i++){//�����Ŵ�1��x�Ĺ��ڷɻ��ĸ������� 
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
	
	for(gj = 0; gj <= n; gj++){//������ڻ��ȸ��������㵽N���� 
		wj = n - gj;//�������ȸ�������  n��ȥ���ڻ��ȸ�����		
		
		if(gj != 0){//�Թ��ڻ��ȴ��� 
			int remn = gj; //���ڿջ���ʣ���� 
			for(int i = 1; i <= x; i++){//1~x(m1)								
				for(int j = 1; j < i; j++){
	/*����һ��һ��*/if(a[j].st == 1 && (a[j].gt < a[i].ct) ){//ͣ�ڻ���
						a[j].st = 2;
						remn++;
					}
				}
				if(remn > 0){
					a[i].st = 1;
					sj[gj]++;//ͣ�ڻ��ȵķɻ��ĸ���
					remn--;
				} 
			}
		}	
		if(wj != 0){//�Թ�����ȴ��� 
			int remw = wj; //�ջ���ʣ���� 
			for(int i = x + 1; i <= y + x; i++){//1~x(m1)								
				for(int j = x + 1; j < i; j++){ //FALSE�������� 
	/*����һ��һ��*/if(a[j].st == 1 && (a[j].gt < a[i].ct) ){//ͣ�ڻ���
						a[j].st = 2;
						remw++;
					}
				}
				if(remw > 0){
					a[i].st = 1;
					sj[gj]++;//ͣ�ڻ��ȵķɻ��ĸ���
					remw--;
				}
			}
		}
	}
	sort(sj, sj + n + 1);
	cout << sj[n];
	return 0;
}
