#include <bits/stdc++.h>

using namespace std;

const int N = 100000000;
int n,m1,m2; 
int l[N][3];//�ɻ�
int a,b; 



int mee(int x){
	
	int total = 0;
	int n1,n2;
	n1 = x;//�������� 
	n2 = (x-n);//�������� 
	int l2[N][3];//���ŷɻ����ʱ��

	memset(l2,-1,sizeof(l2));
	int b1,b2;//ʹ���������� 
	 b1 = 0;
	 b2 = 0;
	
	 
	for(int i = 0;i<=N;i++){
		//���� 
		if(l[i][1] == 11){//���ڷɻ����� 
			if(n1>b1){//�п� 
				b1++;//��ռ��һ������
				total++;
				l2[l[i][2]][1] = 11;
			}
		}
		if(l[i][1] == 22){//����ɻ����� 
			if(n2>b2){//�п� 
				b2++;//��ռ��һ������
				total++;
				l2[l[i][2]][1] = 22;
			}
		}
		//���� 
		if(l2[i][1] == 11){//���ڷɻ���� 
			l2[i][1] = -1;
			b1--;//��һ������ 
		}
		if(l2[i][1] == 22){//���ڷɻ���� 
			l2[i][1] = -1;
			b2--;//��һ������ 
		}
	}
	return total;
} 




int main(){
	
	scanf("%d",&n);
	scanf("%d",&m1);
	scanf("%d",&m2);
	
	for(int i = 1;i<=m1;i++){
		scanf("%d %d",&a,&b); //a�ǵ���ʱ�� 
		l[a][1] = 11;//���ڷɻ�
		l[a][2] = b;//���ʱ�� 
	}
	
	for(int i = 1;i<=m2;i++){
		scanf("%d %d",&a,&b); //b�����ʱ�� 
		l[a][1] = 22;//����ɻ�
		l[a][2] = b;//���ʱ�� 
	}
	
	int max_planes = 0;
	for(int j = 0;j<=n;j++){
		max_planes = max(mee(j),max_planes);

	}
	cout<<max_planes; 
	
	
	
	return 0;
} 
