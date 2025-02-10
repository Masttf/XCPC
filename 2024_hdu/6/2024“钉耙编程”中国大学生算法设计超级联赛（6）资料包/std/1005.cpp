#include <cstdio>
#include <vector>
#include <functional>

const int _3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
const int K = 11;

int M;

char s[K];

struct modint
{
	int x;
	bool is_zero;
	modint(): x(0), is_zero(true){}
	modint(int _x): x(_x), is_zero(_x == 0){}
	void operator += (const modint &a) {
		if (a.is_zero)
			return ;
		x += a.x; if (x >= M) x -= M;
		is_zero = false;
		return ;
	}
};

void Solve()
{
	int n, k;
	scanf("%d %d %d", &n, &k, &M);
	std::vector<modint> dp(_3[k]);
	dp[0] = modint(1);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		std::function<int(int)> calc_stat = [&](int x)
		{
			int new_stat = 0;
			for (int i = 0; i < k; i++)
			{
				int t = (x / _3[k - 1 - i]) % 3;
				if (s[i] == '+')
					(t += 1) %= 3;
				else if (s[i] == '-')
					(t += 2) %= 3;
				new_stat = new_stat * 3 + t;
			}
			return new_stat;
		};
		std::vector<modint> ndp = dp;
		for (int j = 0; j < _3[k]; j++)
			ndp[calc_stat(j)] += dp[j];
		dp = ndp;
	}
	for (int i = 0; i < _3[k]; i++)
		if (!dp[i].is_zero)
		{
			for (int j = k - 1; ~j; j--)
			{
				int t = (i / _3[j]) % 3;
				putchar(t + 'A');
			}
			printf(" %d\n", dp[i].x);
		}
	return ;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--) Solve();
	return 0;
}
