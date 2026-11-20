#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), used(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            used[p[i]] = 1;
        }
        int low = n, high = 1;
        for (int i = 0; i < n; i++) {
            if (p[i] != 0)
                continue;
            while (used[low]) {
                low--;
            }
            p[i] = low--;
            break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (p[i] != 0)
                continue;
            while (used[high]) {
                high++;
            }
            p[i] = high++;
            break;
        }
        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (i + 1 != p[i]) {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 != p[i]) {
                r = i;
                break;
            }
        }
        int ans;
        if (l == -1 || r == -1)
            ans = 0;
        else
            ans = r - l + 1;
        cout << ans << '
';
    }
}