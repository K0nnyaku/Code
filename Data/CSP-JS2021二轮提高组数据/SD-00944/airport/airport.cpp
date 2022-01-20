#include <bits/stdc++.h>
using namespace std;
struct node{
	int a=0;
	int b=0;
}m11[100002],m22[100002];
struct node2{
	int lq=0;
	int lq2=0;
}cnt1[100002],cnt2[100002];
int n=0,m111=0,m222=0,max1=0,max2=0;
bool cmp(node s1,node s2){
	return s1.b>s2.b;
}
bool cmp2(node2 s3,node2 s4){
	return s3.lq2<s4.lq2;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m111>>m222;
	for(int i=0;i<m111;i++){
		cin>>m11[i].a>>m11[i].b;
		if(m11[i].b>max1){
			max1=m11[i].b;
		}
	}
	for(int i=0;i<m222;i++){
		cin>>m22[i].a>>m22[i].b;
		if(m22[i].b>max2){
			max2=m22[i].b;
		}
	}
	if(n>=m111+m222){
		cout<<m111+m222;
		return 0;
	}
	sort(m11,m11+m111,cmp);
	sort(m22,m22+m222,cmp);
	cnt1[0].lq=1;
	cnt1[0].lq2=m11[0].a;
	int ss1=0;
	for(int i=1;i<m111;i++){
		int ss=0;
		while(1){
			if(m11[i].b<cnt1[ss].lq2||cnt1[ss].lq2==0){
				cnt1[ss].lq2=m11[i].a;
				cnt1[ss].lq++;
				if(ss>ss1){
					ss1=ss;
				}
				break;
			}
			ss++;
		}
	}
	cnt2[0].lq=1;
	cnt2[0].lq2=m22[0].a;
	int ss2=0;
	for(int i=1;i<m222;i++){
		int ss=0;
		while(1){
			if(m22[i].b<cnt2[ss].lq2||cnt2[ss].lq2==0){
				cnt2[ss].lq2=m22[i].a;
				cnt2[ss].lq++;
				if(ss>ss2){
					ss2=ss;
				}
				break;
			}
			ss++;
		}
	}
	if(ss1+ss2+2<=n){
		cout<<m111+m222;
		return 0;
	}
	sort(cnt1,cnt1+1+ss1,cmp2);
	sort(cnt2,cnt2+1+ss2,cmp2);
	int ss3=0;
	int ss4=0;
	while(1){
		if(ss1-ss3+ss2-ss4+2<=n){
			int num1=0;
			for(int i=ss3;i<=ss1;i++){
				num1+=cnt1[i].lq;
			}
			for(int j=ss4;j<=ss2;j++){
				num1+=cnt2[j].lq;
			}
			cout<<num1;
			return 0;
		}
		if(cnt1[ss3].lq<cnt2[ss4].lq){
			ss1--;
		}
		else{
			ss2--;
		}
	} 
}
