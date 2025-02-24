#include <set>
#include <cstdio>

const int N = 100'005;

struct Dir
{
	int dir;
	Dir():dir(0){}
	int dx() const {
		if (dir & 1)
			return 0;
		return dir == 0 ? -1 : 1;
	}
	int dy() const {
		if (!(dir & 1))
			return 0;
		return dir == 1 ? -1 : 1;
	}
	void turn_left() {
		++dir;
		if (dir == 4)
			dir = 0;
		return ;
	}
	void turn_right() {
		--dir;
		if (dir == -1)
			dir = 3;
		return ;
	}
};

int n;
char s[N];

void Solve()
{
	int n; scanf("%d", &n);
	scanf("%s", s);
	std::set<std::pair<int, int>> vis;
	Dir d;
	int now_x = 0, now_y = 0;
	for (int i = 0; i < n; i++)
	{
		if (vis.find({now_x, now_y}) != vis.end())
			return puts("-1"), void();
		vis.insert({now_x, now_y});
		if (s[i] == 'L')
			d.turn_left();
		else if (s[i] == 'R')
			d.turn_right();
		now_x += d.dx();
		now_y += d.dy();
	}
	if (now_x != 0 || now_y != 0)
		return puts("0"), void();
	if (d.dir != 0)
		return puts("0"), void();
	puts("1");
	return ;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--) Solve();
	return 0;
}
