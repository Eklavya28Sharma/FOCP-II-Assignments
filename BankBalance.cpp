#include <iostream>
#include <unordered_map>
using namespace std;

class Bank {
    unordered_map<string, int> acc;
public:
    bool CREATE(string x, int y) {
        if (acc.find(x) == acc.end()) {
            acc[x] = y;
            return true;
        }
        acc[x] += y;
        return false;
    }

bool DEBIT(string x, int y) {
        if (acc.find(x) == acc.end() || acc[x] < y)
            return false;

        acc[x] -= y;
        return true;
    }

    bool CREDIT(string x, int y) {
        if (acc.find(x) == acc.end())
            return false;

        acc[x] += y;
        return true;
    }

int BALANCE(string x) {
    if (acc.find(x) == acc.end())
         return -1;
return acc[x];
    }
};

int main() {
int Q;
cin >> Q;

Bank b;

    while (Q--) {
        string o, x;
        int y;

        cin >> o;

        if (o == "CREATE") {
            cin >> x >> y;
            cout << (b.CREATE(x, y) ? "true" : "false") << endl;
        }
        else if (o == "DEBIT") {
            cin >> x >> y;
            cout << (b.DEBIT(x, y) ? "true" : "false") << endl;
        }
        else if (o == "CREDIT") {
            cin >> x >> y;
            cout << (b.CREDIT(x, y) ? "true" : "false") << endl;
        }
        else if (o == "BALANCE") {
            cin >> x;
            cout << b.BALANCE(x) << endl;
        }
    }
 return 0;
}