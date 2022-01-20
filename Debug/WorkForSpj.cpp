#include<bits/stdc++.h>
using namespace std;

int main() {

    for(int T = 1; T <= 5000; T++) {
        system("I:/Code/Debug/Make.exe"); 
        double st = clock();
        system("I:\\Code\\Debug\\WA.exe");
        double ed = clock();
        system("I:\\Code\\Debug\\Checker.exe");

        if(system("fc I:\\Code\\Debug\\AC.out I:\\Code\\Debug\\WA.out")) {
            puts("Wrong Anser\n");
            return 0;
        }
        else
            printf("Accepted, #%d, %.0lfms\n", T, ed - st);
    }

	cout << "Done\n";

    return 0;
}
