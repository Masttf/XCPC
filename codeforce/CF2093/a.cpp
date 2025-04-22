#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s1, s2, s3;
        std::cin >> s1 >> s2 >> s3;
        std::cout << s1[0] << s2[0] << s3[0] << std::endl;
    }
    return 0;
}