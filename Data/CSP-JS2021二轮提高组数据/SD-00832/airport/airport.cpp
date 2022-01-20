#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

struct Air{
	int ru;
	int chu;
	
	void chushi(){
		ru = chu = 0;
	}
};
//struct Zhong{
//	int biao;
//	int shu;
//};

int N, nei, wai;
Air air[100005], geshi[100005];
int visit[100005];

//int airshu[200005];
//vector< vector <int> > hao;
//vector< vector <int> > ci;
int sumhao = 0;
int ans;

bool xiao_da(Air a, Air b){
	return a.ru < b.ru;
}
bool da_xiao(Air a, Air b){
	return a.ru > b.ru;
}
//bool vecda_xiao(vector<int> a,  vector<int> b){
//	return a[0] > b[0];
//}

int main( ){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	cin >> N >> nei >> wai;
	
	for(int i = 1; i <= 100005; i++){
		air[i].chushi();
		geshi[i].chushi();
	}
	
	for(int i = 1; i <= nei+wai; i++){
		cin >> air[i].ru >> air[i].chu;
//		airshu[i] = 
	}
	
	//һ���ų�˳�� 
	sort(air, air+nei+wai, xiao_da);
//	sort(); 
	
//	for(int i = 1; i <= nei+wai; i++){
//		cout << air[i].ru << " " << air[i].chu << endl;
//	}	

	//�����ҳ�����ͬʱͣ�µĲ��ұ��
//	cout << 4;
	for(int i = 1; i <= nei+wai; i++){
//		cout << "in" << " " << endl;
		if(visit[i] == 1){
//			cout << "12";
			//����̰�ģ�����ҵ����������������������� 
			continue;
		}
//		cout << "next " << endl;
		//ÿ������ʼ����һ�ֱ��i��ʵ������������������еĹ��̣�
		int nowmax = -1;
		for(int j = i; j <= nei+wai; j++){
//			cout << "ok for for" << j << endl;
			if(air[j].chu >= nowmax){
				nowmax = air[j].chu;
//				hao[j][0]++;
//				hao[j].push_back(i);
//				ci[i][0]++;
//				ci[i].push_back(j);
				//�ǲ���һ����Ŷ�Ϊi?�����
				visit[j] = 1;
				geshi[i].ru = i;//biaohao
				geshi[i].chu++;//youjige
			}
		} 
		sumhao++;
	}
	
//	cout << 3;
	
	//����sum����ͬ����ǰn���
	sort(geshi, geshi+nei+wai, da_xiao);
//	cout << 2;
	for(int i = 1; i <= N; i++){
		int biaohao = geshi[i].ru;
		int geshu = geshi[i].chu;
		ans += geshu;
	}
	
//	cout << 1 << endl << "ans:" ;
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//�Ż������ÿ�κ󶼵���ͬһ��ͣ�����������
//���Ǳ���10^10��ѭ���Ĺؼ� 
