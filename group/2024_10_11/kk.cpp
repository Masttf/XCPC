#include <bits/stdc++.h>

char a[1005][1005];
int cntT, cntA, cntP;
int n, m;

bool checkT(int x, int y) {
	for(int i = 0; i < 3; ++i) 
		if(a[x][y + i] == '.') return false;
	for(int i = 0; i < 5; ++i) 
		if(a[x + i][y + 1] == '.') return false;
	return true;
}
void colorT(int x, int y) {
	for(int i = 0; i < 3; ++i) 
		a[x][y + i] = '.';
	for(int i = 0; i < 5; ++i) 
		a[x + i][y + 1] = '.';
	cntT++;
}
bool checkP(int x, int y) {
	for(int i = 0; i < 3; ++i) 
		if(a[x][y + i] == '.') return false;
	for(int i = 0; i < 5; ++i) 
		if(a[x + i][y] == '.') return false;
	for(int i = 0; i < 3; ++i) 
		if(a[x + i][y + 2] == '.') return false;
	if(a[x + 2][y + 1] == '.') return false;
	return true;
}
int checkA(int x, int y) {
	for(int i = 0; i < 3; ++i) 
		if(a[x][y + i] == '.') return false;
	for(int i = 0; i < 5; ++i) 
		if(a[x + i][y] == '.' || a[x + i][y + 2] == '.') return false;
	if(a[x + 2][y + 1] == '.') return false;
	return true;
}
void colorP(int x, int y) {
	++cntP;
	for(int i = 0; i < 3; ++i) 
		a[x][y + i] = '.';
	for(int i = 0; i < 5; ++i) 
		a[x + i][y] = '.';
	for(int i = 0; i < 3; ++i) 
		a[x + i][y + 2] = '.';
	a[x + 2][y + 1] = '.';
}
void colorA(int x, int y) {
	++cntA;
	for(int i = 0; i < 3; ++i) 
		a[x][y + i] = '.';
	for(int i = 0; i < 5; ++i) 
		a[x + i][y] = a[x + i][y + 2] = '.';
	a[x + 2][y + 1] = '.';
}
bool dfs(int i, int j) {
	if(a[i][j] == '.' or a[i + 1][j] == '.') return false;
	if(i + 4 > n or j + 2 > m) return false;
	bool ca = checkA(i, j), cp = checkP(i, j);
	assert(!(ca and !cp));
	// if(!ca and !cp) return false;	
	if(checkT(i, j)) {
		colorT(i, j);
		return true;
	}
	if(!ca and cp) {
		colorP(i, j);
		return true;
	}
	if(a[i + 3][j + 1] == '#') {
		colorT(i + 3, j + 1);
		colorP(i, j);
		return true;
	}
	bool op = dfs(i + 3, j + 2);
	if(!op) {
		colorA(i, j);
		return true;
	} else {
		colorP(i, j);
		return true;
	}
}

int main() {
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			std::cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n - 4; ++i) {
		for(int j = 1; j <= m - 2; ++j) {
			if(a[i][j] == '.') continue;
			// std::cout << "-----" << i << ' ' << j << '\n';
			if(checkT(i, j)) {
				colorT(i, j);
				continue;
			}
			dfs(i, j);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			assert(a[i][j] == '.');
		}
	}
	std::cout << cntT << ' ' << cntA << ' ' << cntP << '\n';
}