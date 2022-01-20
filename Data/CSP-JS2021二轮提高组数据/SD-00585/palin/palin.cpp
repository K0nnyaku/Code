#include<bits/stdc++.h>
using namespace std;
int qwq[100005];
int buckat[100005];
char etsger[100005];
bool appe[100005];
int rl,rr;
bool wc=0;
int n;
void dfs(int index,int l,int r){
	if(wc)return;
	if(index==n){
		wc=1;
		for(int i=0;i<2*n-1;i++){
			printf("%c",etsger[i]);
		}cout<<"L";
		cout<<endl;
	}
	if(index==0){
		etsger[0]='L';
		etsger[n*2-1]='L';
		rl=buckat[qwq[0]*2];
		rr=buckat[qwq[0]*2];
		dfs(1,1,n*2-1);
	//	cout<<"----------------------------"<<endl;
		etsger[0]='R';
		etsger[n*2-1]='R';
		rl=buckat[qwq[n*2-1]*2-1];
		rr=buckat[qwq[n*2-1]*2-1];
		dfs(1,0,n*2-2);
	}else{
	//	cout<<index<<" "<<l<<" "<<r<<endl;
		if(rl>0&&qwq[l]==qwq[rl-1]&&l<rl-1){
		//	printf("1index=%d,rl=%d,rr=%d,l=%d,r=%d,searching%d\n",index,rl,rr,l,r,qwq[l]);
			etsger[index]='L';
			etsger[n*2-1-index]='L';
			rl--;
			dfs(index+1,l+1,r);
			rl++;
			return;
		}if(rr<n*2-1&&qwq[l]==qwq[rr+1]&&l!=rr+1){
	//		printf("2index=%d,rl=%d,rr=%d,searching%d\n",index,rl,rr,qwq[l]);
			etsger[index]='L';
			etsger[n*2-1-index]='R';
			rr++;
			dfs(index+1,l+1,r);
			rr--;
				return;
		}if(rl>0&&qwq[r]==qwq[rl-1]&&r!=rl-1){
	//		printf("3index=%d,rl=%d,rr=%d,searching%d\n",index,rl,rr,qwq[r]);
			etsger[index]='R';
			etsger[n*2-1-index]='L';
			rl--;
			dfs(index+1,l,r-1);
			rl++;
				return;
		}if(rr<n*2-1&&qwq[r]==qwq[rr+1]&&r>rr+1){
	//		printf("4index=%d,rl=%d,rr=%d,searching%d\n",index,rl,rr,qwq[r]);
			etsger[index]='R';
			etsger[n*2-1-index]='R';
			rr++;
			dfs(index+1,l,r-1);
			rr--;
				return;
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		wc=0;
		memset(appe,0,sizeof(appe));
		for(int i=0;i<2*n;i++){
			scanf("%d",&qwq[i]);
			if(appe[qwq[i]]){
				buckat[qwq[i]*2]=i;
			}else buckat[qwq[i]*2-1]=i;
			appe[qwq[i]]=1;
		}
		dfs(0,0,n*2-1);
		if(!wc)cout<<-1<<endl;
	}
	//这是我唯一有思路的一道题（
	//T1打了20分暴力 T4估计0了 全靠这题拿分了（
	//要是进不了NOIP就AFO了（
	//然而事实上去年分数线130 我就算按照去年的分数线搞而且A了这题也过不了啊（
	//那没办法了 摆烂呗（ 
	//但是不想直接写goodbyeOI 万一就过了呢（
	//感谢你来收拾我的东西 请抽烟.jpg 
	//This .cpp file is blessed by the one and only true god,Huajige.
	//This .cpp file is blessed by cincoutcerrclog,the godly-ben of godly-bens.
	//This .cpp file is blessed by wangzhi05,the godly-ben of sleeping.
	//This .cpp file is blessed by etsger,the godly-ben of fantastic hands.
	//This .cpp file is blessed by LTY,the godly-ben of gays.
	//This .cpp file is blessed by mensanjin,the godly-ben of cuteness.
	//This .cpp file is blessed by shaibai,the godly-ben of bad hands.
	//This .cpp file is blessed by SPJ,the godly-ben of soft eggs.
	//This .cpp file is blessed by sendiago,the godly-ben of diyaing.
	//With their blessings,I shall get the first prise of CSP-S 2021.
	//written by syko_canir84,the godly-ben of true hands.
	return 0;
}

