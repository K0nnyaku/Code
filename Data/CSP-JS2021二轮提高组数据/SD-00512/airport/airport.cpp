
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

struct f{
	int a,b;
};
int maxlq=0,n; 
int ck[100010]; 
vector<f> gn,gj;
bool cmp(const f& a,const f& b){
	return a.a<b.a;
} 
int tmax(int a,int b,int c){
	if(a>=b){
		if(a>c)return a;
		else if(b>c) return b;
		else return c;
	}
	else{
		if(b>c) return b;
		else return c;
	}
}

void check(int);

void sf(int l,int r){
	if(l==r)return;
	else if(r-l==1){
		return;
	}
	else if(r-l==2)check(l+1);
	else{
		int d=(r-l+1)/3;
		int k1=l+d,k2=k1+d;
		check(k1);check(k2);
		int m;
		if(l>r)m=tmax(ck[k1],ck[k2],ck[l]);
		else m=tmax(ck[k1],ck[k2],ck[r]);
		if(m==ck[k1]){
			if(ck[l]>ck[k2])sf(l,k1);
			else if(ck[k2]>ck[l])sf(k1,k2);
			else sf(l,k2);
		}
		else if(m==ck[k2]){
			if(ck[k1]>ck[r])sf(k1,k2);
			else if(ck[k1]>ck[r])sf(k2,r);
			else sf(k1,r);
		}
		else if(m==ck[l]) sf(l,k1);
		else if(m==ck[r]) sf(k2,r);
	}
	return;
}

int main(){
	freopen("airport1.in","r",stdin);
	freopen("airport1.out","w",stdout);
	int m1,m2;
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=0;i<m1;i++){
		f t;
		scanf("%d %d",&(t.a),&(t.b));
		gn.push_back(t);
	}
	for(int i=0;i<m2;i++){
		f t;
		scanf("%d %d",&(t.a),&(t.b));
		gj.push_back(t);
	}
	sort(gn.begin(),gn.end(),cmp);
	sort(gj.begin(),gj.end(),cmp);
	check(0);
	check(n);
	sf(0,n);
	printf("%d",maxlq);
	return 0;
}
void check(int k){
	if(ck[k])return;
	int lq=0,lq1=0,lq2=0;
	vector<f> gn1(gn);
	vector<f> gj1(gj);
	for(int i=0;i<k;i++){
		int t=0;
		for(vector<f>::iterator it=gn1.begin();it!=gn1.end();it++){
			if((*it).a>t){
				t=(*it).b;
				it=gn1.erase(it)-1;
				lq1++;
			}
		}
	
	}
	int kk=n-k;
	for(int i=0;i<kk;i++){
		int t=0;
		for(vector<f>::iterator it=gj1.begin();it!=gj1.end();it++){
			if((*it).a>t){
				t=(*it).b;
				it=gj1.erase(it)-1;
				lq2++;
			}
		}
	}
	lq=lq1+lq2;
	ck[k]=lq;
	if(lq>maxlq)maxlq=lq;
	return;
}

