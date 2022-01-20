#include<bits/stdc++.h>
using namespace std;
struct up{
	long long a;
	long long xuhao;
}stu[9000];
up stu2[9000];
int cmp(up l,up r){
	if(l.a==r.a)
		return l.xuhao<r.xuhao;
	return l.a<r.a;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	long long n,Q;
	cin>>n>>Q;
	for(long long i=1;i<=n;i++){
		cin>>stu[i].a;
		stu[i].xuhao=i;
	}
	for(long long i=1;i<=Q;i++){
		long long b;
		cin>>b;
		if(b==1){
			long long tmp,tmp_i;
			cin>>tmp_i>>tmp;
			stu[tmp_i].a=tmp;
		}
		if(b==2){
			long long tmp_i,tmp;
			cin>>tmp_i;
			tmp=stu[tmp_i].a;
			for(long long i=1;i<=n;i++){
				stu2[i].a=stu[i].a;
				stu2[i].xuhao=stu[i].xuhao;
			}
			sort(stu2+1,stu2+1+n,cmp);
			int p;
			for(int i=1;i<=n;i++){
				if(stu2[i].a==tmp&&stu2[i].xuhao==tmp_i){
					p=i;break;
				}
			}
			cout<<p<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

