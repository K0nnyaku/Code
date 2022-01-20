#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;
struct airport{
	int a;
	int b;
};
bool cmp(airport xx,airport yy){
	if(xx.a<yy.a){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,mm1,mm2;
	cin>>n>>mm1>>mm2;
	airport m[100005];
	for(int i=0;i<mm1;i++){
		cin>>m[i].a>>m[i].b;
	}
	for(int i=mm1;i<mm1+mm2;i++){
		cin>>m[i].a>>m[i].b;
	}
	sort(m,m+mm1,cmp);
	sort(m+mm1,m+mm1+mm2,cmp);
	int ans1=0;
	int maxans=0;
	int flag=0;
	//枚举国内航班使用的廊桥数i
	for(int i=0;i<=n;i++){
		int cnt=0;
		int book=0;
		for(int j=1;j<mm1;j++){
			if(i==0){
				break;
			}
			ans1++;
			if(m[j].a<m[j-1].b){
				if(m[j].a<book){
					if(cnt>=i){
						ans1--;
					}
				}
				cnt++;
				book=m[j-1].b;
			}else{
				cnt=0;
				book=0;
			}
		} 
		//国际航班 
		cnt=0;
		book=0;
		int ans2=0;
		for(int j=mm1+1;j<mm1+mm2;j++){
			if(n-i==0){
				break;
			}
			ans2++;
			if(m[j].a<m[j-1].b){
				if(m[j].a<book){
					if(cnt>=n-i){
						ans2--;
					}
				}
				cnt++;
				book=m[j-1].b;
			}else{
				book=0;
				cnt=0;
			}
		} 
		if(ans1+ans2>maxans){
			maxans=ans1+ans2;
		}
		ans1=0;
		ans2=0;
	}
	cout<<maxans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
