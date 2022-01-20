#include<iostream>
#include<cstdio>
#include<cctype>
#define ll long long
using namespace std;
int in(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=1e5+10;
int n,m1,m2,ans=0;
int arr1[N],lea1[N],arr2[N],lea2[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=in(),m1=in(),m2=in();
	for(int i=1;i<=m1;++i){
		arr1[i]=in();
		lea1[i]=in();
	}
	for(int i=1;i<=m2;++i){
		arr2[i]=in();
		lea2[i]=in();
	}
	int l1=0,l2=0,id,tot1,tot2,s;
	for(int num1=0;num1<=n;++num1){
		int l2=n-num1;
		l1=num1;
		s=100000010;
		for(int i=1;i<=m1;++i){
			if(l1!=0){
				--l1;
				++tot1;
				s=min(s,lea1[i]);
			}else{
				if(arr1[i]>=s){
					++tot1;
					s=min(s,lea1[i]);
				}
			}
		}
		s=100000010;
		for(int i=1;i<=m2;++i){
			if(l2!=0){
				--l2;
				++tot2;
				s=min(s,lea2[i]);
			}else{
				if(arr2[i]>=s){
					++tot2;
					s=min(s,lea2[i]);
				}
			}
		}
		ans=max(ans,tot1+tot2);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
