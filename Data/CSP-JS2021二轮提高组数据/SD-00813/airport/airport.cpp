#include<iostream>
#include<algorithm>
using namespace std;
int n,m1,m2,ans = 0,chance1 = 0,chance2 = 0,chance3 = 0;
struct flight{
	int cam,lef;
	bool tmp = true,now = true;
}local[100001],foreign[100001];
bool cmp(flight a,flight b){
	return a.cam < b.cam;
}
int airport(int n,int m1,int m2){
	for(int i = 1;i <= m1;i++)
		cin >> local[i].cam >> local[i].lef;
	sort(local+1,local+m1+1,cmp);
	for(int i = 1;i <= m2;i++)
		cin >> foreign[i].cam >> foreign[i].lef;
	sort(foreign+1,foreign+m2+1,cmp);
	for(int j = 1;j <= n;j++){
		int tmpc = 0,tmpl = 0,tmpn1 = 0,tmpn2 = 0;
		for(int i = 1;i <= m1;i++){
			tmpc = local[i].cam;
			//cout << tmpc << ' ' << "c1" << endl;
			if(tmpc >= tmpl and local[i].tmp and local[i].now){
				tmpl = local[i].lef;
				//cout  << tmpl << ' ' << "l1" << endl;
				local[i].tmp = false;
				tmpn1++;
			}
		}
		tmpc = 0;
		tmpl = 0;
		for(int i = 1;i <= m2;i++){
			tmpc = foreign[i].cam;
			//cout << tmpc << ' ' << "c2" << endl;
			if(tmpc >= tmpl and foreign[i].tmp and foreign[i].now){
				tmpl = foreign[i].lef;
				//cout << tmpl << ' ' << "l2" << endl;
				foreign[i].tmp = false;
				tmpn2++;
			}
		}
		if(tmpn1 >= tmpn2){
		//	chance1 += tmpn1;
		//	chance3 += tmpn2;
			ans += tmpn1;
			for (int i = 1;i <= m1;i++)
				local[i].now = local[i].tmp;
			for(int i = 1;i <= m1;i++) local[i].tmp = true;
			for(int i = 1;i <= m2;i++) foreign[i].tmp = true;
		}
		else{
		//	chance2 += tmpn2;
		//	chance3 += tmpn1;
			ans += tmpn2;
			for (int i = 1;i <= m2;i++)
				foreign[i].now = foreign[i].tmp;
			for(int i = 1;i <= m1;i++) local[i].tmp = true;
			for(int i = 1;i <= m2;i++) foreign[i].tmp = true;
		}
		//if(j%2 == 0){
		//	if(chance1 == 0) 
		}
	//cout  << tmpn1 << ' ' << tmpn2 << ' ' << ans << endl;	
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin >> n >> m1 >> m2;
	cout << airport(n,m1,m2);
	return 0;
}
