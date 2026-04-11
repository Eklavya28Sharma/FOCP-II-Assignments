#include <iostream>
using namespace std;
bool ok(string &s, int n, int m, int k) {
    int ops = 0;
    for(int i = 0; i < n; ) {
        if (s[i] == '1') {
            if (++ops > m) return false;
            i += k;
        } else i++;
    }
    return true;
}

int main() {
    int n, m; cin>>n>>m;
    string s; cin>>s;

    int l = 1, r = n, ans = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(s, n, m, mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
cout << ans; }