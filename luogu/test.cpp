#include <cstdio>

inline int Max(int x, int y) { return x > y ? x : y; }

const int MN = 100005;
const int MS = 6200005;
const int BK = 29;

int N, Q;
int A[MN];
int eh[MN], nxt[MN * 2], to[MN * 2], tot;
inline void insw(int x, int y) {
	nxt[++tot] = eh[x]; to[tot] = y; eh[x] = tot;
	nxt[++tot] = eh[y]; to[tot] = x; eh[y] = tot;
}

int sz[MS], ch[MS][2], cnt;
int rt1[MN], rt2[MN];
inline void Ins(int &rt, int x, int j) {
	ch[++cnt][0] = ch[rt][0], ch[cnt][1] = ch[rt][1], sz[cnt] = sz[rt], rt = cnt;
	++sz[rt];
	if (~j) Ins(ch[rt][x >> j & 1], x, j - 1);
}

int ldf[MN], rdf[MN], dep[MN], faz[MN][17], dfc;

void DFS(int u, int fa) {
	ldf[u] = ++dfc; faz[u][0] = fa; dep[u] = dep[fa] + 1;
	Ins(rt1[dfc] = rt1[dfc - 1], A[u], BK);
	Ins(rt2[u] = rt2[fa], A[u], BK);
	for (int j = 1; 1 << j < dep[u]; ++j) faz[u][j] = faz[faz[u][j - 1]][j - 1];
	for (int i = eh[u]; i; i = nxt[i]) if (to[i] != fa) DFS(to[i], u);
	rdf[u] = dfc;
}

inline int LCA(int x, int y) {
	if (dep[x] < dep[y]) x ^= y ^= x ^= y;
	for (int d = dep[x] - dep[y], j = 0; d; d >>= 1, ++j) if (d & 1) x = faz[x][j];
	if (x == y) return x;
	for (int j = 16; ~j; --j) if (faz[x][j] != faz[y][j]) x = faz[x][j], y = faz[y][j];
	return faz[x][0];
}

int Qu(int rt1, int rt2, int x, int j) {
	if (j == -1) return 0;
	int p = (x >> j & 1) ^ 1;
	if (sz[ch[rt1][p]] - sz[ch[rt2][p]])
		return Qu(ch[rt1][p], ch[rt2][p], x, j - 1) | 1 << j;
	return Qu(ch[rt1][p ^ 1], ch[rt2][p ^ 1], x, j - 1);
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i)
		scanf("%d", A + i);
	for (int i = 1, x, y; i < N; ++i) {
		scanf("%d%d", &x, &y);
		insw(x, y);
	}
	DFS(1, 0);
	for (int i = 1, opt, x, y, z; i <= Q; ++i) {
		scanf("%d", &opt);
		if (opt == 1) {
			scanf("%d%d", &x, &z);
			printf("%d\n", Qu(rt1[rdf[x]], rt1[ldf[x] - 1], z, BK));
		}
		else {
			scanf("%d%d%d", &x, &y, &z);
			int w = faz[LCA(x, y)][0];
			printf("%d\n", Max(Qu(rt2[x], rt2[w], z, BK), Qu(rt2[y], rt2[w], z, BK)));
		}
	}
	return 0;
}
