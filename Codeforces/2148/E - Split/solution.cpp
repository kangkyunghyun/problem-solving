#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int flag = 0;
        map<int, int> aim;
        for (auto p : cnt) {
            if (p.second % k != 0) {
                flag = 1;
                break;
            }
            aim[p.first] = p.second / k;
        }
        if (flag) {
            cout << 0 << '
';
            continue;
        }
        map<int, int> curr;
        int ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            curr[a[r]]++;
            while (curr[a[r]] > aim[a[r]]) {
                curr[a[l]]--;
                l++;
            }
            ans += r - l + 1;
        }
        cout << ans << '
';
    }
}