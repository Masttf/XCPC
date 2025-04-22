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
    int n; // Variable to store the size of the array 'a' for the current test case.
        std::cin >> n; // Read the size of the array.

        // --- Problem Analysis ---
        // We need to find the maximum size of a "beautiful" subsequence of the given array 'a'.
        // An array (or subsequence) x = [x1, ..., xm] is beautiful if there exists another array y = [y1, ..., ym] such that:
        // 1. All elements in 'y' are distinct (y_i != y_j for i != j).
        // 2. The product x_i * y_i is the same constant value (let's call it C) for all i.
        
        // --- Derivation ---
        // From condition 2, we have y_i = C / x_i for all i.
        // Condition 1 requires that all y_i must be distinct. This means C / x_i != C / x_j for all i != j.
        // Assuming C is non-zero (which it must be since a_i >= 1, so x_i >= 1), this implies 1 / x_i != 1 / x_j.
        // This, in turn, implies that x_i != x_j for all i != j.
        
        // --- Conclusion ---
        // A necessary condition for a subsequence 'x' to be beautiful is that all elements within 'x' must be distinct.
        
        // --- Sufficiency ---
        // Can any subsequence 'x' with distinct elements be beautiful? Yes.
        // Let x = [x1, ..., xm] be a subsequence of 'a' where all x_i are distinct.
        // We can choose a constant C which is a common multiple of all x_i (e.g., C = LCM(x1, ..., xm)).
        // Then we define y_i = C / x_i. Since C is a multiple of each x_i, y_i will be an integer.
        // Since all x_i are distinct positive integers, the values C / x_i will also be distinct.
        // Thus, we have found an array 'y' with distinct elements satisfying the conditions.
        
        // --- Final Problem Statement ---
        // The problem asks for the *maximum* size of a beautiful subsequence.
        // Since any beautiful subsequence must have distinct elements, and any subsequence with distinct elements is beautiful,
        // the problem is equivalent to finding the maximum size of a subsequence of 'a' that contains only distinct elements.
        // This maximum size is simply the number of unique (distinct) values present in the original array 'a'.

        // --- Implementation Strategy ---
        // We can efficiently count the number of distinct elements using a boolean array (or a hash set/set).
        // Given the constraint 1 <= a_i <= n <= 100, a boolean array is very efficient.
        
        // Create a boolean vector 'seen' of size n + 1. 
        // Indices 1 to n will correspond to the possible values in array 'a'.
        // Initialize all elements to 'false', indicating no value has been seen yet.
        // Index 0 will not be used as values start from 1.
        std::vector<bool> seen(n + 1, false); 
        
        int distinct_count = 0; // Initialize a counter for the number of unique elements found.

        // Iterate 'n' times to read each element of the input array 'a'.
        for (int i = 0; i < n; ++i) {
            int a_i; // Variable to store the current element of 'a'.
            std::cin >> a_i; // Read the current element from input.
            
            // Check if the value 'a_i' has been encountered before using the 'seen' array.
            // 'a_i' serves as the index (valid because 1 <= a_i <= n).
            if (!seen[a_i]) {
                // If 'seen[a_i]' is false, this is the first time we are seeing this value.
                seen[a_i] = true;    // Mark this value as seen by setting the corresponding flag to true.
                distinct_count++;    // Increment the count of distinct elements.
            }
            // If seen[a_i] is already true, we've encountered this value before, so we do nothing.
        }
        
        // After iterating through all elements of 'a', 'distinct_count' holds the number of unique elements.
        // Output the result for the current test case, followed by a newline character.
        std::cout << distinct_count << "\n";
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