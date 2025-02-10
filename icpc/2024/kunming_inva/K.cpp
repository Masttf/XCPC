#include <bits/stdc++.h>

int n;
std::mt19937 rnd(time(0));

int ask(int l, int r, int x1, int x2) {
	std::cout << "0 ";
	for(int i = 1; i < l; ++i) std::cout << "0 ";
	int mid = l + r >> 1;
	for(int i = l; i <= mid; ++i) std::cout << x1 << ' ';
	for(int i = mid + 1; i <= r; ++i) std::cout << x2 << ' ';
	for(int i = r + 1; i <= n; ++i) std::cout << "0 ";
	std::cout << std::endl;
	int x;
	std::cin >> x;
	return x;
}

int getRnd() { return rnd() % 2; }

std::vector<std::vector<int>> L, R;
std::vector<std::vector<int>> tmpV;
int ans[1005];

void dfs(int l, int r) {
	if(l == r) {
		assert(tmpV.size() == 1);
		ans[l] = tmpV.back().back();
		tmpV.clear();
		return ;
	}
	int mid = l + r >> 1;
	while(tmpV.size() >= 2) {
		auto x1 = std::move(tmpV.back());
		tmpV.pop_back();
		auto x2 = std::move(tmpV.back());
		tmpV.pop_back();
		int op = ask(l, r, x1.back(), x2.back());
		if(op == 0) {
			R.push_back(std::move(x1));
			L.push_back(std::move(x2));
		} else if(op == 2) {
			L.push_back(std::move(x1));
			R.push_back(std::move(x2));
		} else {
			while(!x2.empty()) {
				x1.push_back(x2.back());
				x2.pop_back();
			}
			tmpV.push_back(std::move(x1));
		}
	}
	if(tmpV.size() == 1) {
		auto x = std::move(tmpV.back());
		tmpV.pop_back();
		int op = ask(l, r, x.back(), 0);
		if(op == 0) R.push_back(std::move(x));
		else L.push_back(std::move(x));
	}
	tmpV.swap(L);
	dfs(l, mid);
	tmpV.swap(R);
	dfs(mid + 1, r);

}	

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> n;
	for(int i = 1; i <= n; ++i) tmpV.push_back(std::vector<int>{i});
	dfs(1, n);
	std::cout << "1 ";
	for(int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
	std::cout << std::endl;
}