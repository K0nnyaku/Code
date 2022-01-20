#include<iostream>

using namespace std; 

int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int a;
	int max = 0, max1 = 0;
	int n, m1, m2;
	scanf("%d%d%d", &n, &m1, &m2); 
	
	int temp[m1], temp2[m2];
	int plus[n + 1], plus2[n + 1];
	for(int i = 0; i <= n; i++){
		plus[i] = 0;
		plus2[i] = 0;
	}
	int in[3][m1 + 1], abr[3][m2 + 1];
	for(int i = 1; i < m1 + 1; i++){
		for(int j = 1; j < 3; j++){
			scanf("%d", &in[j][i]);
		}
		temp[i] = 0;
	}
	for(int i = 1; i < m2 + 1; i++){
		for(int j = 1; j < 3; j++){
			scanf("%d", &abr[j][i]);
		}
		temp2[i] = 0;
	}
	
	for(int i = 0; i <= n; i++){
		plus[i] += i;
		if(i > 0){
			for(int i1 = i + 1; i1 < m1 + 1; i1++){
				for(int j1 = i + 1; j1 > 1; j1--){
					if(in[1][i1] >in[2][j1 - 1]){
						if(temp[i1 - 1] == 0){
							plus[i] += 1;
							temp[i1]++;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i <= n; i++){
		plus2[i] += i;
		if(i > 0){
			for(int i1 = i + 1; i1 < m2 + 1; i1++){
				for(int j1 = i + 1; j1 > 1; j1--){
					if(abr[1][i1] > abr[2][j1 - 1]){
						if(temp2[i1 - 1]  == 0){
							plus2[i] += 1;
							temp2[i1]++;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i <= n; i++){
		max1 = plus[i] + plus2[n - i];
		if(max1 > max){
			max = max1;
		}
	}
	printf("%d\n", max);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
