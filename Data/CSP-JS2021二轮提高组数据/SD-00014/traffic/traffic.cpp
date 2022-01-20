#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	ifstream file_in;
	ofstream file_out;
	file_in.open("traffic.in");
	file_out.open("traffic.out");
	
	file_out<<rand()%100;
	file_out.close();
	file_in.close();
	return 0;
}
