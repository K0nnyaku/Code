/*
By miao5



ALL RIGHTS RESERVED



����fclose�ˣ���Ȼ����ƭ��



�����÷֣�0 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<ctime>
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0));
	cout<<rand()%50;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
