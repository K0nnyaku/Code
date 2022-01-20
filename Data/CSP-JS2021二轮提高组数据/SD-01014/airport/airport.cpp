#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
int timen[150001],timej[150001],gnneed[150001],gjneed[150001];

struct gnhangban{
	int c,g;//��ȥʱ�� 
}gnhb[150001];

struct gjhangban{
	int c,g;
}gjhb[150001];

int dodogn(int k,int gn) {//k���������� gn�Ǻ������� 
	if(k==0)return 0;
	int ans=0;
	for(int i=1;i<=gn;i++){
		//�ȼ�鿪ͷ�Ƿ��� 
		if(timen[gnhb[i].c]+1<=k){
			ans++;
			for(int j=gnhb[i].c;j<=gnhb[i].g;j++)timen[j]++;
		}
	}
	return ans;
}

int dodogj(int k,int gj) {
	if(k==0)return 0;
	int ans=0;
	for(int i=1;i<=gj;i++){
		if(timej[gjhb[i].c]+1<=k){
			ans++;
			for(int j=gjhb[i].c;j<=gjhb[i].g;j++)timej[j]++;
		}
	}
	return ans;
}

bool cmpgn(gnhangban a,gnhangban b){
	return a.c<b.c;
}

bool cmpgj(gjhangban a,gjhangban b){
	return a.c<b.c;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	//���� �������� ���ڹ��ʺ�������
	int lq,gn,gj;
	cin>>lq>>gn>>gj;
	//���� ���ʺ�����ȥʱ�� 
	for(int i=1;i<=gn;i++) cin>>gnhb[i].c>>gnhb[i].g;
	for(int i=1;i<=gj;i++) cin>>gjhb[i].c>>gjhb[i].g;
	//��������Ｗ ���������� ��ÿһ�����฽��һ��ֵ ��Ҫ���ŵ�ֵ 
	
	//��������ʱ������
	sort(gnhb+1,gnhb+1+gn,cmpgn);
	sort(gjhb+1,gjhb+1+gj,cmpgj);
	
	//ת��˼· ����ģ��
	int maxn=-0x3f3f;
	for(int ign=0;ign<=lq;ign++){
		int igj=lq-ign;		
		maxn=max(maxn,dodogn(ign,gn)+dodogj(igj,gj));
		memset(timen,0,sizeof timen);memset(timej,0,sizeof timej);
	}cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
