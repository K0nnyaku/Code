#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

struct z{
	long long x,y;
	long long shi;
};
struct z D[101001];
struct z F[101001];

long long n,m1,m2;

long long Z[3][101001];
long long zuo=0;
long long you=0;

bool oper(z q1,z q2){
	if(q1.x==q2.x) return q1.shi<q2.shi;
	return q1.x<q2.x;
}

long long A[101001];
long long B[101001];

void gai1(long long x,long long n){
	long long t;
	if(x*2>n) return ;
	if(x*2+1>n) t=x*2;
	else {
		if(A[x*2]<A[x*2+1]) t=x*2;
		else t=x*2+1;
	}
	
	if(A[x]>A[t]){
		swap(A[x],A[t]);
		gai1(t,n);
	}
	
	
}
void gai2(long long x,long long n){
	long long t;
	if(x*2>n) return ;
	if(x*2+1>n) t=x*2;
	else {
		if(B[x*2]<B[x*2+1]) t=x*2;
		else t=x*2+1;
	}
	
	if(B[x]>B[t]){
		swap(B[x],B[t]);
		gai2(t,n);
	}
	
	
}
void shang1(long long x){
	if(x/2<1) return ;
	if(A[x]<A[x/2]){
		swap(A[x],A[x/2]);
		shang1(x/2);
	}
}
void shang2(long long x){
	if(x/2<1) return ;
	if(B[x]<B[x/2]){
		swap(B[x],B[x/2]);
		shang2(x/2);
	}
}

long long mmax=0;
int main(){
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin>>n>>m1>>m2;
	
	
	
	for(long long i=1;i<=m1;i++){
		cin>>D[i].x;
		cin>>D[i].y;
		D[i].shi=D[i].x;
	}
	for(long long i=1;i<=m2;i++){
		cin>>F[i].x;
		cin>>F[i].y;
		F[i].shi=F[i].x;
	}
	
	sort(D+1,D+m1+1,oper);
	sort(F+1,F+m2+1,oper);
	
	for(long long i=1;i<=n;i++){
		Z[1][i]=i;
		Z[2][i]=i;
		for(long long p=1;p<=i;p++){
			A[p]=D[p].y;
			B[p]=F[p].y;
		}
		
		for(long long p=1;p<=i;p++){
			shang1(p);
			shang2(p);
		}
		
		if(zuo==0){
			
			for(long long o=i+1;o<=m1;o++){
				if(D[o].x<A[1]) continue;
				Z[1][i]++;
				A[1]=D[o].y;
				gai1(1,i);
			}	
			if(Z[1][i]==m1) zuo=i;
			
		}
		if(zuo!=0) Z[1][i]=m1;
	
		
		
		
		if(you==0){
			for(long long o=i+1;o<=m2;o++){
				if(F[o].x<B[1]) continue;
				Z[2][i]++;
				B[1]=F[o].y;
				gai2(1,i);	
			}
			if(Z[2][i]==m2) you=i;
		}
		if(you!=0) Z[2][i]=m2;
	}
	
	
	for(long long i=0;i<=n;i++){
		mmax=max(mmax,Z[1][i]+Z[2][n-i]);
	}
	

	cout<<mmax<<endl;
	
	
	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
