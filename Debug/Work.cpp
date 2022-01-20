#include<bits/stdc++.h>
using namespace std;

int main() {

    for(int T = 1; T <= 100; T++) {
        system("/home/k0nnyaku/Code/Debug/Make"); 
        double st = clock();
		system("/home/k0nnyaku/Code/Training/22.1.13PYYZ/T1");
        double ed = clock();
        system("/home/k0nnyaku/Code/Cpp/Test");
		cerr << T << "\n";
        if(system("diff /home/k0nnyaku/Code/Data/WA.out /home/k0nnyaku/Code/Data/AC.out")) {
            puts("Wrong Anser\n");
            return 0;
        }
        else
            printf("Accepted, #%d, %.0lfms\n", T, ed - st);
    }

	cout << "Done\n";

    return 0;
}
