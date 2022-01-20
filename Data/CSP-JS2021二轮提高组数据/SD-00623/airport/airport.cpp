#include<bits/stdc++.h>
using namespace std;
const int N =1E5+10;

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar(); 
	}
	return x*f;
}
priority_queue<int,vector<int>,greater<int> >qt1,qt2;

int n,m1,m2;

struct flt{
	int f,s;
};

flt a[N],b[N];

bool cmp(flt a,flt b){
	if(a.s<b.s&&a.f<b.f) return 1;
	else if(a.s<b.s&&a.f>b.f) return 1;
	return 0;
}

int cnt1=0,cnt2=0;


long long ans[N][3];
long long anss=-1e8;

long long Max(long long a,long long b){
	return a>b?a:b;
}
long long Min(long long a,long long b){
	return a>b?b:a;
}
void cqu1(){
	if(!qt1.empty()) qt1.pop();
	cnt1=0;
}
void cqu2(){
	if(!qt2.empty()) qt2.pop();
	cnt2=0;
}
int main(){
	//freopen("airport.in","r",stdin);
	//freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		a[i].s=read();
		a[i].f=read();
	}
	for(int i=1;i<=m2;i++){
		b[i].s=read();
		b[i].f=read();
	}
	
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	/*for(int i=1;i<=m1;i++){
		cout<<a[i].s<<" "<<a[i].f<<endl;
	}
	printf("\n");
	for(int i=1;i<=m2;i++){
		cout<<b[i].s<<" "<<b[i].f<<endl;
	}
	printf("\n");
	*/
	ans[0][0]=ans[0][1]=0;
	
	for(int i=1;i<=n;i++){//n���� 
		for(int j=1;j<=m1;j++){//��¼���ӵķɻ����
			if(cnt1<i){
				cnt1++;//��¼Ŀǰ�������ڵķɻ�
				qt1.push(a[j].f);
				ans[i][0]++;//��¼i������ʱ�����
				//if(cnt1+1==i) cout<<ans[i][0]<<endl; 
			}
			if(cnt1==i){
				int o=qt1.top();
				if(a[j].s>=o){
					qt1.pop();
					qt1.push(a[j].f);
					ans[i][0]++;
				}
			}
			
		}
		cqu1();
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m2;j++){//��¼���ӵķɻ����
			if(cnt2<i){
				qt2.push(b[j].f);
				cnt2++;//��¼Ŀǰ�������ڵķɻ� 
				ans[i][1]++;//��¼i������ʱ�����
				//if(cnt2+1==i) cout<<ans[i][0]<<endl;  
			}
			if(cnt2==i){
				int o=qt2.top();
				if(b[j].s>=o){
					qt2.pop();
					qt2.push(a[j].f);
					ans[i][1]++;
				}
			} 
		}
		cqu2();
	}
	//ans[n][0]=Min(m1,ans[n][0]);
	//ans[n][1]=Min(m2,ans[n][1]);
	for(int i=0;i<=n;i++){
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
		anss=Max(anss,ans[i][0]+ans[n-i][1]);
	}
	 
	printf("%lld\n",anss);
	return 0;
} 
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16 
*/
/*


*/
