#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
long long n,m1,m2,t;
struct T{
	long long ti;
	long long num;
	long long fl;
};
T A[100005];
int book[100000005];
bool cmp(T a1,T a2){
	if(a1.ti==a2.ti)return a1.fl>a2.fl;
	else return a1.ti<a2.ti;
	
}
long long work(long long k){
	long long sum=0;
	long long sheng=k;
	if(sheng){
		for(long long i=1;i<=2*m1;i++){
			if(A[i].fl==1){
				if(book[A[i].num]){
					book[A[i].num]=0;
					sheng++;
				}
			}
			else {
				if(sheng){
					book[A[i].num]=1;
					sheng--;
			//		cout<<A[i].num<<" "<<sheng<<endl;
					sum++;
				}
			}
		
		}
	}
//cout<<sum<<endl;
	long long sum1=sum;
	sheng=n-k;
	if(sheng){
		for(long long i=2*m1+1;i<=t;i++){
			if(A[i].fl==1){
				if(book[A[i].num]){
					book[A[i].num]=0;
					sheng++;
				}
			}
			else {
				if(sheng){
					book[A[i].num]=1;
					sheng--;
			//		cout<<A[i].num<<" "<<sheng<<endl;
					sum++;
				}
			}
		}
	}
//cout<<sum-sum1<<endl;
	return sum;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	memset(book,0,sizeof(book));
	cin>>n>>m1>>m2;
	long long l,r;
	for(long long i=1;i<=m1+m2;i++){
		cin>>l>>r;
		A[++t].num=i;
		A[t].ti=l;
		A[t].fl=0;
		A[++t].num=i;
		A[t].ti=r;
		A[t].fl=1;
	}
	sort(A+1,A+2*m1+1,cmp);
	sort(A+2*m1+1,A+t+1,cmp);

	long long mmax=0;
	for(long long i=0;i<=n;i++){
		
		mmax=max(mmax,work(i));
	}
	
	cout<<mmax;


	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
