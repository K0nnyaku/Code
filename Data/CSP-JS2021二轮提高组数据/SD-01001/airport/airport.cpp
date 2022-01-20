#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<queue>
#include<bitset>
#include<algorithm>
using namespace std;
pair<int,int> p1[100010],p2[100010];
priority_queue<int,vector<int>,greater<int> > qin,qou;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0,ti,to;i<m1;i++){
		scanf("%d%d",&ti,&to);
		p1[i]=make_pair(ti,to);
	}
	for(int i=0,ti,to;i<m2;i++){
		scanf("%d%d",&ti,&to);
		p2[i]=make_pair(ti,to);
	}
	sort(p1,p1+m1);
	sort(p2,p2+m2);
	int maxc=-1;
	for(int maxi=0,curi,maxo,curo,cnti,cnto;maxi<=n;maxi++){
		maxo=n-maxi,curo=curi=cnti=cnto=0;
		while(!qin.empty()) qin.pop();
		for(int i=0;i<m1;i++){
			while((!qin.empty())&&(qin.top()<=p1[i].first)){
				//fprintf(stderr,"*%d\n",qin.top());
				qin.pop(),curi--;
			}
			if(curi>=maxi) continue;
			else{
				qin.push(p1[i].second);
				//fprintf(stderr,"/%d\n",p1[i].second);
				curi++;cnti++;
				//fprintf(stderr,"+%d\n",i);
			}
		}
		//fprintf(stderr,"-----\n");
		while(!qou.empty()) qou.pop();
		for(int i=0;i<m2;i++){
			while((!qou.empty())&&(qou.top()<=p2[i].first)){
				//fprintf(stderr,"*%d\n",qou.top());
				qou.pop(),curo--;
			}
			if(curo>=maxo) continue;
			else{
				qou.push(p2[i].second);
				curo++;cnto++;
				//fprintf(stderr,"+%d\n",i);
			}
		}
		if(cnto+cnti>maxc) maxc=cnto+cnti;
		//fprintf(stderr,"(%d,%d):%d+%d=%d\n",maxi,maxo,cnti,cnto,cnto+cnti);
	}
	printf("%d\n",maxc);
	fclose(stdin);fclose(stdout);
	return 0;
}


/*#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<algorithm>
using namespace std;
pair<int,bool> plin[100010],plou[100010];
int fii[100010],foo[100010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0,ti,to;i<m1;i++){
		scanf("%d%d",&ti,&to);
		plin[i]=make_pair(ti,false);
		plou[i]=make_pair(to,false);
	}
	for(int i=m1,ti,to;i<m1+m2;i++){
		scanf("%d%d",&ti,&to);
		plin[i]=make_pair(ti,true);
		plou[i]=make_pair(to,true);
	}
	sort(plin,plin+m1+m2);
	sort(plou,plou+m1+m2);
	int curi=0,curo=0;
	int coi=0,cou=0; 
	for(;1;){
		if(plin[coi].first>=plou[cou].first){
			if(plou[cou].second) curo--;
			else curi--;
			cou++;
		}
		if(plin[coi].first<=plou[cou].first){
			if(plin[coi].second) foo[++curo]++;
			else fii[++curi]++;
			coi++;
		}
		if(!plin[coi].first) break; 
	}
	for(int i=1;i<=n;i++){
		foo[i]+=foo[i-1];
		fii[i]+=fii[i-1];
	}
	int maxx=-1;
	for(int i=0;i<=n;i++){
		if(foo[i]+fii[n-i]>maxx)
			maxx=foo[i]+fii[n-i];
	}
		
	printf("%d\n",maxx);
	fclose(stdin);fclose(stdout);
	return 0;
}*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<queue>
#include<bitset>
#include<algorithm>
using namespace std;
bitset<100010> bii,boo;
pair<int,int> pin[100010],pou[100010];
priority_queue<int,vector<int>,greater<int> > qin,qou;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0,ti,to;i<m1;i++){
		scanf("%d%d",&ti,&to);
		pin[i]=make_pair(ti,to);
	}
	for(int i=0,ti,to;i<m2;i++){
		scanf("%d%d",&ti,&to);
		pou[i]=make_pair(ti,to);
	}
	sort(pin,pin+m1);
	sort(pou,pou+m2);
	for(int maxi=0,curi=0,curo=0;maxi<=n;maxi++,curi=curo=0){
		for(int i=0;i<m1;i++){
			if(bii.test(i)) continue;
			if(curi<maxi-1){
				curi++;
				qin.push(pin[i].second);
				bii.set(i);
			}else if(curi==maxi-1){
				while(curi&&qin.top()<=pin[i].first)qin.pop(),curi--;
				if(curi==maxi-1)
				while(i<m1&&pin[i].first<qin.top())i++;
				curi++;
				qin.push(pin[i].second);
				bii.set(i);
			}
		}
		for(int i=0;i<m2;i++){
			if(boo.test(i)) continue;
			if(curo<maxi-1){
				curo++;
				qou.push(pou[i].second);
				boo.set(i);
			}else if(curo==maxi-1){
				while(curo&&qou.top()<=pou[i].first)qou.pop(),curi--;
				if(curo==maxi-1)
				while(i<m2&&pou[i].first<qou.top())i++;
				curo++;
				qou.push(pou[i].second);
				boo.set(i);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}*/

