#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> sieve(1000001, 1), p;
    for (int i = 2; i * i <= 1000000; i++)
        if (sieve[i])
            for (int j = i * 2; j <= 1000000; j += i)
                sieve[j] = 0;
    for (int i = 2; i <= 1000000; i++)
        if (sieve[i])
            p.push_back(i);
    while (n--) {
        int a, b;
        cin >> a >> b;
        int l = lower_bound(p.begin(), p.end(), a) - p.begin();
        int r = upper_bound(p.begin(), p.end(), b) - p.begin();
        cout << ((r - l) % 2 ? p[(l + r) / 2] : -1) << '\n';
    }
}