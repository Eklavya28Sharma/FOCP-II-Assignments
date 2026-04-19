#include<iostream>
using namespace std;

int parityUpTo(long long n) {
    switch (n % 4) {
        case 0:return n % 2;
        case 1:return 1;
        case 2:return (n + 1) % 2;
        case 3:return 0;
    }
return 0;
}
int main() {
    long long L, R;
    cin >> L >> R;

int parity = parityUpTo(R) ^ parityUpTo(L - 1);

    if(parity == 0)
        cout << "even" << endl;
    else
        cout << "odd" << endl;

    return 0;
}