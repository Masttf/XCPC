#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n;
        std::cin >> n;
        std::vector<int> a(n);
        int k_max = 0;
        int final_idx = -1;
        std::map<int, std::vector<int>> groups;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] != -1) {
                groups[a[i]].push_back(i);
                if (a[i] > k_max) {
                    k_max = a[i];
                }
            } else {
                final_idx = i;
            }
        }

        std::vector<int> p(n);
        int low = 1;  
        int high = n; 

        for (int k = 1; k <= k_max; ++k) {
            if (groups.find(k) == groups.end()) {
                continue;
            }
            const std::vector<int>& indices_to_remove = groups[k];

            if (k % 2 != 0) { // 第 k 轮是奇数 (移除局部非最小值)
                // 这些元素未能成为局部最小值。
                // 给它们分配当前可用的最大值，使它们更不可能是最小值。
                for (int idx : indices_to_remove) {
                    p[idx] = high;
                    high--; // 移动到下一个较小的大值
                }
            } else { // 第 k 轮是偶数 (移除局部非最大值)
                // 这些元素未能成为局部最大值。
                // 给它们分配当前可用的最小值，使它们更不可能是最大值。
                for (int idx : indices_to_remove) {
                    p[idx] = low;
                    low++; // 移动到下一个较大的小值
                }
            }
        }

        // 处理从未被移除的元素 (a[i] == -1)
        // 循环结束后，low 和 high 之间恰好剩下一个值 (low == high + 1)
        // 将这个剩余的值赋给最终留下的元素
        if (final_idx != -1) {
            // 断言 low == high + 1 (理论上应该总是成立)
            // assert(low == high + 1);
            p[final_idx] = low; // 或者 p[final_idx] = high + 1;
        }

        // 输出构造的排列 p
        for (int i = 0; i < n; ++i) {
            std::cout << p[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}