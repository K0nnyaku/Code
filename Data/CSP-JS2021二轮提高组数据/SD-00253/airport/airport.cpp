#include <cstdio>
#include <algorithm>

using namespace std;

int n;

typedef struct{
	long long end; //���������β�ŵ����ˣ� 
	int count;// �������һ�����˼����ɻ� 
}GD;
GD guidaoAr[100010],guidaoBr[100010];
int guiAuse = 0,guiBuse = 0;// �ֱ�һ�����˶��ٸ���� 

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	
	for(int i = 0; i < m1; ++i){
		long long a,b;
		scanf("%llu%llu",&a,&b);
		
		for(int j = 0; j <= i && j < n;++j){
			if(guidaoAr[j].end <= a){
				guidaoAr[j].end = b;
				++ guidaoAr[j].count;
				
				guiAuse = max(guiAuse,j + 1);
				break;
			}
		}
	}
	for(int i = 0; i < m2; ++i){
		long long a,b;
		scanf("%llu%llu",&a,&b);
		
		for(int j = 0; j <= i && j < n;++j){
			if(guidaoBr[j].end <= a){
				guidaoBr[j].end = b;
				++ guidaoBr[j].count;
				
				guiBuse = max(guiBuse,j + 1);
				break;
			}
		}
	}
	
	// ���������A�Ĺ������
	int maxnum = 0;// ���ɻ����� 
	//guiAuse = min(guiAuse,n);
	//guiBuse = min(guiBuse,n);
	for(int i = 1; i < guiAuse; ++i)
		guidaoAr[i].count += guidaoAr[i - 1].count;
	
	for(int i = 1; i < guiBuse; ++i)
		guidaoBr[i].count += guidaoBr[i - 1].count;
		
	for(int i = 0; i <= guiAuse; ++i){
		//printf("���ڣ�%d����%d,%d,%d\n",i,(i ? guidaoAr[i - 1].count : 0),((n - i) ? guidaoBr[n - i - 1].count : 0),(i ? guidaoAr[i - 1].count : 0) + ((n - i) ? guidaoBr[n - i - 1].count : 0));
		maxnum = max(maxnum,(i ? guidaoAr[i - 1].count : 0) + ((n - i) ? guidaoBr[n - i - 1].count : 0));
	}
	
	
	printf("%d\n",maxnum);
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}
