#include <cstdio>
#include <vector>
#include <algorithm>

struct Event
{
	int s, t, type;
	Event(): s(0), t(0), type(0) {}
	Event(int _s, int _t, int _type = 0):
		s(_s), t(_t), type(_type){}
	bool operator < (const Event &a) const {
		return s == a.s ? t < a.t : s < a.s;
	}
	bool contain(const Event &a) const {
		return s <= a.s && a.t <= t;
	}
};

void Solve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<Event> events;
	for (int i = 0; i < n; i++)
	{
		int b, e; scanf("%d %d", &b, &e);
		events.emplace_back(b, e, 0);
	}
	for (int i = 0; i < m; i++)
	{
		int s, t; scanf("%d %d", &s, &t);
		events.emplace_back(s, t, 1);
	}
	// change this to merge() is ok
	std::sort(events.begin(), events.end());
	for (int i = 1; i < events.size(); i++)
		if (events[i - 1].t > events[i].s)
			return puts("No"), void();
	if (events.front().type != 1)
		return puts("No"), void();
	Event maybe_wakeup;
	for (Event now : events)
	{
		if (now.type == 1)
		{
			int s = now.s;
			int t = now.t;
			maybe_wakeup = Event(t, t + 2 * (t - s));
		}
		else // now.type == 0
		{
			if (!maybe_wakeup.contain(now))
				return puts("No"), void();
		}
	}
	puts("Yes");
	return ;
}

int main(int argc, char *argv[])
{
	int T; scanf("%d", &T);
	while (T--) Solve();
	return 0;
}