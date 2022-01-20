#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

string chuan;
int N, K;
stack<string> sta;
stack<string> zhan; 
queue<string> que;
queue<string> dui;
int ans;

string quqian(string oldzi, int du){
	string fanhui;
	for(int i = 0; i <= du; i++){
		fanhui += oldzi[i];
	}
	return fanhui;
}
string quhou(string oldzi, int du, int zong){
	string fanhui;
	for(int i = du; i < zong; i++){
		fanhui += oldzi[i];
	}
	return fanhui;
}

bool check(string bei){
	int jixing = 0;
	int jiyou = 0;
	int jizuo = 0;
	
	for(int i = 0; i < N; i++){
		bool flagxing = true;
		if(bei[i] == '?'){
			return true;
			//让他没有问号之后再来查 
		}else if(bei[i] == '*'){
			for(int j = 1; j <= K; j++){
				if(bei[i+j] != '*'){
					flagxing = false;
				}
			}
			if(flagxing == true){
				return false;
			}
//			i += K;
			//因为这一块都是星，所以可以略了 
		}
		
		
		if(bei[i] == '('){
			jizuo++;
			sta.push("(");
			dui.push("(");
		}
		
		if(bei[i] == ')'){
			if(dui.empty() == true){
				return false;
			}
			jiyou++;
			sta.push(")");
			dui.push(")");
		}
	}
	
	if(jizuo != jiyou || sta.top() == "(" || dui.front() == ")"){
		return false;
	}
	
	if(bei[N-1] == '*' || bei[0] == '*' || bei[0] == ')'){
		return false;
	}
	
	int ge = 0;
	for(int i = 0; i <= N; i++){
		
		string zhe = sta.top();
		sta.pop();
		if(zhe == ")"){
			ge++;
		}else if(zhe == "("){
			ge--;
		}
		if(ge == 0){
//			if(sta.top() == "("){
//				return false;
//			}
		}
	}
	
	
	return true;
	
	
}

//bool check2(string bei){
//}

int main( ){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
	cin >> N >> K;
	
	cin >> chuan;
	
	que.push(chuan);
	
	while(!que.empty()){
		bool flag = false;
		string now = que.front();
//		cout << "now-wai: "<< now << endl;

		
		que.pop();
		
		if(check(now) == false){
			continue;
		}
		
		for(int i = 0; i < N; i++){
			if(now[i] == '?'){
				flag = true;
				
				string qian = quqian(now, i-1);
//				cout << "qian:" << qian;
				string hou = quhou(now, i+1, now.length());
//				cout << "  hou:" << hou << endl;
				string a = qian + "*" + hou;
				string b = qian + "(" + hou;
				string c = qian + ")" + hou;
//				cout << "now:" << now << " a:"<< a << " b:" << b <<" c:" << c << endl;
				que.push(a);
				que.push(b);
				que.push(c);
				break;
			}
		}
		
		if(flag == false){
			zhan.push(now);
//			cout << "flag" << endl;
			ans++;
		}
	}
	
//	cout << "ans" << endl;
//	while(!zhan.empty()){
//		cout << zhan.top() << endl;
//		zhan.pop();
//	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
