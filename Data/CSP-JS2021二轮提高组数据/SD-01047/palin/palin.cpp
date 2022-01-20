#include<iostream>
#include<cstdio>

using namespace std;

const int N = 5e5+10;
template <typename LFJQWQ>
void read(LFJQWQ &NUM){
    NUM = 0;bool FFF = true;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')FFF = false;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		NUM = (NUM << 3) + (NUM << 1) + (ch ^ 48);
		ch = getchar();
	}
	NUM = FFF ? NUM : -NUM;
}
int TTt,n,nn,arr[N << 1],Pos[N][2],ans[N << 1],cnt1,cnt2,HH,TT;
bool vis[N << 1];
int FINDPOS(int X,int PP){//ÏÂ±ê Öµ 
	if(Pos[PP][0] == X)return Pos[PP][1];
	return Pos[PP][0];
}
void print(){
	int hh = 1,tt = nn;
	for(int i = 1 ; i <= nn ; i ++){
		if(ans[i] == tt){hh--;printf("L");}
		else {tt--;printf("R");}
	}
	printf("\n");
}
bool dfs(int h,int t){
	if(vis[h] && vis[t]){
		print();
		return true;
	}
	if(vis[h])h = TT+1;
	else if(vis[t])t = HH +1;
	if(h == 1 && t == nn){
		int TEMP = FINDPOS(nn,arr[nn]);
		ans[++ cnt1] = 1;ans[-- cnt2] = TEMP;vis[TEMP] = true;
		HH = TT = TEMP;
		bool F = dfs(h+1,t);
		if(F)return true;
		else {
			int TEMP = FINDPOS(nn,arr[nn]);
			ans[++ cnt1] = nn;ans[-- cnt2] = TEMP;vis[TEMP] = true;
			HH = TT = TEMP;
			F = dfs(h,t-1);
			if(F)return true;
			else return false;
		}
	}
	int TEMPH = HH - 1,TEMPT = TT + 1;
	if((arr[h] == arr[TEMPH] && TEMPH) || (arr[h] == arr[TEMPT] && TEMPT)){
		int TEMP = FINDPOS(h,arr[h]);
		ans[++ cnt1] = 1;ans[-- cnt2] = TEMP;vis[TEMP] = true;
		HH = min(HH,TEMP);TT = max(TEMP,TT);
		bool F = dfs(h-1,t);
		if(F)return true;
	}
	else if((arr[t] == arr[TEMPH] && TEMPH) || (arr[t] == arr[TEMPT] && TEMPT)){
		int TEMP = FINDPOS(t,arr[t]);
		ans[++ cnt1] = nn;ans[-- cnt2] = TEMP;vis[TEMP] = true;
		HH = min(HH,TEMP);TT = max(TEMP,TT);
		bool F = dfs(h,t-1);
		if(F)return true;
		else return false;
	}
	else return false;
}
int main(){
    freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
    read(TTt);
    while(TTt --){
    	read(n);nn = n * 2;HH = 0;TT = 0;cnt1 = 0;cnt2 = nn + 1;
    	for(int i = 1 ; i <= nn ; i ++)vis[i] = false;
		for(int i = 1 ; i <= nn ; i ++){
			read(arr[i]);
			if(Pos[arr[i]][0])Pos[arr[i]][1] = i;
			else Pos[arr[i]][0] = i;
		} 
		bool FFF = dfs(1,nn);
		if(!FFF)printf("-1\n");
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
