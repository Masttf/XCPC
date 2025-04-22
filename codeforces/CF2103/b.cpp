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
long long calculate_cost(int n, const std::string& s) {
    // If the string is empty, the cost is 0
    if (n == 0) {
        return 0;
    }
    
    // Base cost is n operations for pressing the buttons n times
    long long cost = n; 
    
    // Calculate the additional cost from moving the finger
    long long moves = 0;
    
    // Initial move: If the first character is '1', we need one move operation 
    // because the finger starts on button '0'.
    if (s[0] == '1') {
        moves++; 
    }
    
    // Subsequent moves: For each pair of adjacent characters, if they differ,
    // we need one move operation to switch the finger to the other button.
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i+1]) {
            moves++; 
        }
    }
    
    // Total cost is the sum of presses and moves
    return cost + moves;
}
void solve(){
    int n; // Variable to store the length of the binary string
        std::cin >> n; // Read the length
        std::string s; // Variable to store the binary string
        std::cin >> s; // Read the string

        // Calculate the cost of typing the original string without any reversal
        long long current_cost = calculate_cost(n, s);
        
        long long min_delta_V = 0; // Initialize with 0 reduction (no reversal or no beneficial reversal)

        bool possible_minus_2 = false; // Flag to track if a cost reduction of 2 is possible

        
        if (n >= 2 && s[0] == '1') {
             for (int r = 0; r < n - 1; ++r) { 
                // If we find the pattern '01' at indices r and r+1 within the prefix starting with '1'
                if (s[r] == '0' && s[r+1] == '1') {
                    possible_minus_2 = true; // Reduction of 2 is possible
                    break; // No need to check further r values
                }
            }
        }

        if (!possible_minus_2 && n >= 2) {
             // Use a set to keep track of the distinct adjacent differing pairs encountered so far.
             std::set<std::pair<char, char>> seen_diff_pairs;
             for (int i = 0; i < n - 1; ++i) {
                 // If the adjacent characters differ
                 if (s[i] != s[i+1]) { 
                     std::pair<char, char> p = {s[i], s[i+1]}; // Create the pair
                     // Check if this pair has been seen before
                     if (seen_diff_pairs.count(p)) {
                         possible_minus_2 = true; // Found a repeated differing pair, reduction of 2 is possible
                         break; // No need to check further pairs
                     }
                     // If not seen before, insert it into the set
                     seen_diff_pairs.insert(p);
                 }
             }
        }
        
        // If we found that a reduction of 2 is possible
        if (possible_minus_2) {
             min_delta_V = -2; // Set the maximum reduction to -2
        } else {
            // --- If delta V = -2 is not possible, check conditions for delta V = -1 ---
            bool possible_minus_1 = false; // Flag to track if a cost reduction of 1 is possible
            
            // Condition 1: Reversing the entire string s[0...n-1].
            // This is beneficial by -1 if s[0]=='1' and s[n-1]=='0'.
             if (n > 0 && s[0] == '1' && s[n-1] == '0') {
                 possible_minus_1 = true; // Reduction of 1 is possible
             }
            
             
             if (!possible_minus_1 && n > 1) { 
                  // Iterate through possible starting indices l (0-based) from 1 up to n-1
                  for (int l = 1; l < n; ++l) { 
                      // Check the condition: character before l matches the last character,
                      // and differs from the character at l.
                      if (s[l-1] == s[n-1] && s[l-1] != s[l]) {
                          possible_minus_1 = true; // Reduction of 1 is possible
                          break; // No need to check further l values
                      }
                  }
             }

            // If we found that a reduction of 1 is possible
             if (possible_minus_1) {
                 min_delta_V = -1; // Set the maximum reduction to -1
             } 
             // Otherwise, min_delta_V remains 0, meaning no reduction is possible.
        }
        
        // The minimum possible cost is the original cost plus the minimum delta V (which is the maximum reduction)
        std::cout << current_cost + min_delta_V << "\n"; // Output the result for the current test case
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