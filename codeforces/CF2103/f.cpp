#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map> 
using namespace std;

int k_nor(int x, int y, int k) {
    int or_val = x | y;
    int nor_val = ~or_val;
    int mask = (1 << k) - 1;
    return nor_val & mask; 
}


struct Node {
    int max_val = 0; // Stores the maximum value found in the range represented by this node
    int lazy_val = 0; // Stores a pending maximum update value to be propagated down to children
};


vector<Node> tree;
// Stores the size of the original array, used for segment tree indexing boundaries.
int N_segtree; 
void push(int node, int start, int end) {
    // If there's no pending update (lazy_val is 0) or if it's a leaf node, do nothing.
    if (tree[node].lazy_val == 0 || start == end) { 
        return;
    }
    
    // Apply the lazy value to children's max_val. Children's max value should be at least the lazy value.
    tree[2 * node].max_val = max(tree[2 * node].max_val, tree[node].lazy_val);
    tree[2 * node + 1].max_val = max(tree[2 * node + 1].max_val, tree[node].lazy_val);
    
    // Propagate the lazy value down. Children's lazy value should be at least the current node's lazy value.
    tree[2 * node].lazy_val = max(tree[2 * node].lazy_val, tree[node].lazy_val);
    tree[2 * node + 1].lazy_val = max(tree[2 * node + 1].lazy_val, tree[node].lazy_val);
    
    // Clear the current node's lazy value as it has been propagated.
    tree[node].lazy_val = 0;
}
void update_range(int node, int start, int end, int l, int r, int val) {
    // If the current node's range is completely outside the update range, return.
    if (start > end || start > r || end < l) { 
        return;
    }
    
    // If the current node's range is fully contained within the update range.
    if (l <= start && end <= r) {
        // Apply the update directly to this node. Update its max_val and set lazy_val.
        tree[node].max_val = max(tree[node].max_val, val);
        tree[node].lazy_val = max(tree[node].lazy_val, val);
        return;
    }
    
    // If the current node's range partially overlaps with the update range.
    // First, push any pending lazy updates down to children.
    push(node, start, end); 
    
    // Calculate the midpoint to divide the range.
    int mid = start + (end - start) / 2;
    // Recurse on the left and right children.
    update_range(2 * node, start, mid, l, r, val);
    update_range(2 * node + 1, mid + 1, end, l, r, val);
    
    // After children are updated, update the current node's max_val based on their values.
    // This ensures the max_val reflects the maximum in the current node's range.
    tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
}

/**
 * @brief Queries the segment tree for the maximum value at a specific index idx.
 * 
 * This function traverses down the tree to the leaf corresponding to `idx`,
 * applying lazy updates along the path, and returns the final maximum value stored at that leaf.
 * 
 * @param node The index of the current node in the `tree` vector.
 * @param start The starting index of the range represented by this node.
 * @param end The ending index of the range represented by this node.
 * @param idx The index for which to query the maximum value.
 * @return The maximum value associated with index `idx`.
 */
int query_point(int node, int start, int end, int idx) {
    // Base case: reached the leaf node corresponding to the index idx.
    if (start == end) {
        return tree[node].max_val;
    }
    
    // Before recursing down, push any pending lazy updates from the current node.
    push(node, start, end); 
    
    // Calculate the midpoint to decide which child path to follow.
    int mid = start + (end - start) / 2;
    // If idx is in the left half, recurse on the left child.
    if (idx <= mid) {
        return query_point(2 * node, start, mid, idx);
    } 
    // Otherwise, recurse on the right child.
    else {
        return query_point(2 * node + 1, mid + 1, end, idx);
    }
}

// Main function to solve a single test case
void solve() {
    int n; // Number of elements in the array
    int k; // Number of bits for each element
    cin >> n >> k;
    vector<int> a(n); // Input array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // `E_prev` stores the distinct cumulative NOR values for subarrays ending at index r-1.
    // The map key is the NOR value, and the map value is the minimum starting index 'l' 
    // among all subarrays ending at r-1 that result in this NOR value.
    map<int, int> E_prev; 
    
    N_segtree = n; // Set the size parameter for the segment tree
    // Initialize the segment tree vector with size 4*n (standard size for segment tree)
    // All nodes are initialized with max_val = 0 and lazy_val = 0.
    tree.assign(4 * N_segtree, {0, 0}); 

    // Iterate through the array elements from left (index 0) to right (index n-1)
    for (int r = 0; r < n; ++r) {
        // `E_curr` will store the distinct cumulative NOR values for subarrays ending at the current index r.
        map<int, int> E_curr; 
        
        // Consider the subarray consisting of only the element a[r]. 
        // Its NOR value is a[r], and it starts at index l=r.
        int val_r = a[r];
        // Insert this pair (a[r], r) into E_curr. If a[r] already exists (unlikely here, but for completeness),
        // update its minimum starting index if 'r' is smaller.
        if (E_curr.find(val_r) == E_curr.end()) {
             E_curr[val_r] = r;
        } else {
             E_curr[val_r] = min(E_curr[val_r], r); 
        }
       
        // Extend the subarrays that ended at index r-1 by applying NOR with a[r].
        // Iterate through all distinct NOR values (`val_prev`) that were achieved ending at r-1.
        for (auto const& [val_prev, min_l_prev] : E_prev) {
            // Calculate the new NOR value by NORing `val_prev` with the current element `a[r]`.
            int next_val = k_nor(val_prev, a[r], k);
            
            // Check if this `next_val` has already been encountered for subarrays ending at r.
            if (E_curr.find(next_val) == E_curr.end()) {
                // If it's a new NOR value for index r, record it along with its minimum starting index `min_l_prev`.
                E_curr[next_val] = min_l_prev;
            } else {
                // If `next_val` was already seen (perhaps generated from a different `val_prev`),
                // update its associated minimum starting index (`min_l`) if `min_l_prev` is smaller.
                // This ensures we always store the leftmost starting index for each distinct NOR value.
                E_curr[next_val] = min(E_curr[next_val], min_l_prev);
            }
        }

        // Update the segment tree based on the computed results for index r.
        // Each pair (val, min_l) in E_curr represents a distinct NOR value `val` achievable
        // for a subarray ending at r, starting at the minimum index `min_l`.
        for (auto const& [val, min_l] : E_curr) {
           // This `val` is a candidate for the maximum NOR value for all indices `i` in the range [min_l, r].
           // Perform a range maximum update on the segment tree for this range [min_l, r] with value `val`.
           update_range(1, 0, N_segtree - 1, min_l, r, val);
        }
        
        // Prepare for the next iteration: The results computed for the current index `r` (`E_curr`)
        // will be used as the previous results (`E_prev`) for the next index `r+1`.
        E_prev = E_curr; 
    }

    // After iterating through all elements and updating the segment tree accordingly,
    // query the segment tree for the final maximum NOR value computed for each index `i`.
    for (int i = 0; i < n; ++i) {
        // Query the maximum value stored at leaf node corresponding to index `i`.
        cout << query_point(1, 0, N_segtree - 1, i) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

// Main function: Handles input reading and calls solve() for each test case.
int main() {
    // Use faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}