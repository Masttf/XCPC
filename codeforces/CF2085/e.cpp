#include <bits/stdc++.h>
using namespace std;

vector<int> get_factors(int c) {
    vector<int> factors;
    if (c == 0) return factors;
    for (int i = 1; i * i <= c; ++i) {
        if (c % i == 0) {
            if (i <= 1e9) factors.push_back(i);
            int j = c / i;
            if (j != i && j <= 1e9) factors.push_back(j);
        }
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        int max_a = *max_element(a.begin(), a.end());
        int max_b = *max_element(b.begin(), b.end());
        unordered_set<int> a_set(a.begin(), a.end());
        
        // Preprocess check
        bool possible = true;
        for (int bj : b) {
            if (max_a >= bj) continue;
            if (!a_set.count(bj)) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << -1 << '\n';
            continue;
        }
        
        // Check if b is a permutation of a
        vector<int> a_sorted(a), b_sorted(b);
        sort(a_sorted.begin(), a_sorted.end());
        sort(b_sorted.begin(), b_sorted.end());
        if (a_sorted == b_sorted) {
            cout << max(max_a, max_b) + 1 << '\n';
            continue;
        }
        
        // Generate candidates
        unordered_set<int> candidates;
        unordered_set<int> b_vals(b.begin(), b.end());
        bool found_max = false;
        for (int ai : a) {
            if (ai == max_a) {
                for (int bj : b_vals) {
                    if (max_a < bj) continue;
                    if (max_a == bj) {
                        candidates.insert(max_b + 1);
                    } else {
                        int c = max_a - bj;
                        vector<int> factors = get_factors(c);
                        for (int d : factors) {
                            if (d > max_b && d > bj) {
                                candidates.insert(d);
                            }
                        }
                    }
                }
                found_max = true;
                break;
            }
        }
        
        // Prepare b count and set
        unordered_map<int, int> b_count;
        unordered_set<int> b_set(b.begin(), b.end());
        for (int num : b) b_count[num]++;
        
        int ans = -1;
        vector<int> possible_k(candidates.begin(), candidates.end());
        possible_k.push_back(max_a + 1); // Additional candidate
        sort(possible_k.begin(), possible_k.end(), greater<int>()); // Check larger k first
        
        // Verify candidates
        for (int k : possible_k) {
            if (k <= max_b) continue;
            bool valid = true;
            unordered_map<int, int> tmp_count;
            for (int ai : a) {
                int mod = ai % k;
                if (!b_set.count(mod)) {
                    valid = false;
                    break;
                }
                tmp_count[mod]++;
                if (tmp_count[mod] > b_count[mod]) {
                    valid = false;
                    break;
                }
            }
            if (valid && tmp_count == b_count) {
                ans = k;
                break;
            }
        }
        
        // Check large k if no answer found
        if (ans == -1) {
            int start = max(max_b + 1, max_a + 1);
            for (int k = start; k <= start + 1000; ++k) {
                unordered_map<int, int> tmp_count;
                bool valid = true;
                for (int ai : a) {
                    int mod = ai % k;
                    if (!b_set.count(mod)) {
                        valid = false;
                        break;
                    }
                    tmp_count[mod]++;
                    if (tmp_count[mod] > b_count[mod]) {
                        valid = false;
                        break;
                    }
                }
                if (valid && tmp_count == b_count) {
                    ans = k;
                    break;
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}