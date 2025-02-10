#include <bits/stdc++.h>
#include <iterator>
#include <unordered_map>
 
struct Card {
	int suit, value; // Ace is treated as 14
 
	Card(std::string s) {
		char a = s[0];
 
		if (isdigit(a))
			value = a - '0';
		else if (a == 'T')
			value = 10;
		else if (a == 'A')
			value = 14;
		else if (a == 'J')
			value = 11;
		else if (a == 'Q')
			value = 12;
		else if (a == 'K')
			value = 13;
		else
			value = -1; // error
		
		char b = s[1];
		suit = b; // Club, Diamond, Heart, Spade
	}
 
	friend bool operator < (const Card &a, const Card &b) {
		return a.value < b.value;
	}
 
	friend bool operator == (const Card &a, const Card &b) {
		return a.value == b.value;
	}
};
 
constexpr int Highcard = 1, Pair = 2, TwoPairs = 3, ThreeofaKind = 4, Straight = 5,
Flush = 6, FullHouse = 7, FourofaKind = 8, StraightFlush = 9;
 
struct Hand {
	std::vector<Card> v;
	int type;
 
	Hand() : type(0) {}
 
	Hand(const Hand &o) : v(o.v), type(o.type) {}
 
	Hand(const std::vector<Card> &v) : v(v), type(0) {}
 
	void init_high() {//初始化一手牌的大小,此后才能调用比较
		std::sort(v.begin(), v.end()); // 升序排序
		
		bool straight = false;
		if (v.back().value == 14) {
			if (v[0].value == 2 && v[1].value == 3 && v[2].value == 4 && v[3].value == 5) {
				straight = true;
				std::rotate(v.begin(), v.begin() + 1, v.end());
			}
		}
 
		if (!straight) {
			bool ok = true;
			for (int i = 1; i < 5; i++)
				ok &= (v[i].value == v[i - 1].value + 1);
			
			if (ok)
				straight = true;
		}
 
		bool flush = all_of(v.begin(), v.end(), [&] (const Card &a) {return a.suit == v.front().suit;});
 
		if (flush && straight) { // 同花顺
			type = StraightFlush;
			std::reverse(v.begin(), v.end());
			return;
		}
 
		std::vector<int> c;
		c.assign(15, 0);
 
		for (auto &o : v)
			c[o.value]++;
		
		std::vector<int> kind[5];
 
		for (int i = 2; i <= 14; i++)
			if (c[i] > 1)
				kind[c[i]].push_back(i);
		
		if (!kind[4].empty()) { // 四条
			type = FourofaKind;
 
			for (int i = 0; i < 4; i++)
				if (v[i].value != kind[4].front()) {
					std::swap(v[i], v.back());
					break;
				}
			
			return;
		}
 
		if (!kind[3].empty() && !kind[2].empty()) {
			type = FullHouse;
 
			std::sort(v.begin(), v.end(), [&] (const Card &a, const Card &b) {
				bool ta = (a.value == kind[3].front()), tb = (b.value == kind[3].front());
 
				return ta > tb;
			});
 
			return;
		}
 
		if (flush) {
			type = Flush;
			std::sort(v.begin(), v.end());
			std::reverse(v.begin(), v.end());
 
			return;
		}
 
		if (straight) {
			type = Straight;
			std::reverse(v.begin(), v.end());
			return;
		}
 
		if (!kind[3].empty()) {
			type = ThreeofaKind;
 
			std::sort(v.begin(), v.end(), [&] (const Card &a, const Card &b) {
				bool ta = (a.value == kind[3].front()), tb = (b.value == kind[3].front());
 
				return ta > tb;
			});
			
			if (v[3] < v[4])
				std::swap(v[3], v[4]);
			
			return;
		}
 
		if ((int)kind[2].size() == 2) {
			type = TwoPairs;
 
			std::sort(v.begin(), v.end(), [&] (const Card &a, const Card &b) {
				bool ta = (c[a.value] == 2), tb = (c[b.value] == 2);
 
				if (ta != tb)
					return ta > tb;
				
				return a.value > b.value;
			});
 
			return;
		}
 
		if ((int)kind[2].size() == 1) {
			type = Pair;
 
			std::sort(v.begin(), v.end(), [&] (const Card &a, const Card &b) {
				bool ta = (c[a.value] == 2), tb = (c[b.value] == 2);
 
				if (ta != tb)
					return ta > tb;
				
				return a.value > b.value;
			});
 
			return;
		}
 
		type = Highcard;
 
		std::sort(v.begin(), v.end());
		std::reverse(v.begin(), v.end());
	}
 
	friend int cmp_high(const Hand &a, const Hand &b) {
		if (a.type != b.type)
			return a.type < b.type ? -1 : 1;
		
		if (a.v != b.v)
			return a.v < b.v ? -1 : 1;
		
		return 0;
	}
 
	friend bool small_high(const Hand &a, const Hand &b) {
		return cmp_high(a, b) < 0;
	}
 
	bool operator ! () const {
		return v.empty();
	}
 
	std::string str() const {
		std::stringstream ss;
 
		for (auto &o : v)
			ss << o.value << ' ';
		
		return ss.str();
	}
};
 
 
const std::vector<std::string> suit = {"H", "D", "C", "S"};
const std::vector<std::string> value = {"", "", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
 
int T;
 
std::map<std::string, bool> vis;
std::vector<Card> cards;
std::vector<Card> pub; // 桌上已知的公共牌(3张)
std::vector<Card> pri[4]; // Capoo 的私有牌(2张)
 
void init(){
	vis.clear();
	cards.clear();
	pub.clear();
	for(int i = 0; i < 4; i++) pri[i].clear();
	for(int i = 0; i < 4; i++) {
		for(int j = 2; j < 15; j++) {
			cards.emplace_back(value[j] + suit[i]);
		}
	}
}
 
Hand dfs(std::vector<Card> pool) { // 这 7 张牌能得到的最大的牌
	Hand ret;
	bool is_dirty = false;
	for(int i = 0; i < 7; i++){
		for(int j = i + 1; j < 7; j++){
			std::vector<Card> tmp;
			for(int k = 0; k < 7; k++) {
				if(k == i || k == j) continue;
				tmp.emplace_back(pool[k]);
			}
			Hand now(tmp);
			now.init_high();
			if(is_dirty) {
				ret.init_high();
				if(small_high(ret, now)) ret = now;
			} else {
				ret = now;
				is_dirty = true;
			}
		}
	}
 
	return ret;
}
 
int calc(int target) { // 以当前的部分pub和pri枚举pub的全部情况, 计算第 target 只 Capoo 获胜的次数
	int sum = 0;
	for(int it = 0; it < 52; it++){
		//printf("it = %d\n", it);
		for(int it2 = it + 1; it2 < 52; it2++) {
			//printf("it2 = %d\n", it2);
			if(vis[value[cards[it].value] + (char)cards[it].suit] || vis[value[cards[it2].value] + (char)cards[it2].suit]) continue;
			//std::cout << value[cards[it].value] + (char)cards[it].suit << ' ' << value[cards[it2].value] + (char)cards[it2].suit << std::endl;
			//puts("3");
			std::vector<Card> m_pub(pub);
			m_pub.emplace_back(cards[it]);
			m_pub.emplace_back(cards[it2]);
			std::vector<Card> m_pri[4] = {pri[0], pri[1], pri[2], pri[3]};
			std::pair<Hand, int> max_id;
			//puts("BRK");
			for(int i = 0; i < 4; i++){
				std::vector<Card> tmp(m_pub);
				tmp.insert(tmp.end(), m_pri[i].begin(), m_pri[i].end());
				if(i == 0) {
					max_id = {dfs(tmp), 0};
				} else {
					Hand now = dfs(tmp);
					now.init_high();
					max_id.first.init_high();
					if(small_high(max_id.first, now) || (i == target && cmp_high(max_id.first, now) == 0)){ // 平局所有最大的都获胜
						max_id = {now, i};
					}
				}
			}
			if(max_id.second == target){
				//std::cout << max_id.first.str() << std::endl;
				sum++;
			}
		}
	}
	return sum;
}
 
 
void Solve() {
	for(int i = 0; i < 3; i++) {
		std::string s;
		std::cin >> s;
		pub.emplace_back(Card(s));
		vis[value[pub[i].value] + (char)pub[i].suit] = true;
	}
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			std::string s;
			std::cin >> s;
			pri[i].emplace_back(Card(s));
			vis[value[pri[i][j].value] + (char)pri[i][j].suit] = true;
		}
	}
	int target;
	std::cin >> target;
	// 选两张牌交换, 然后用这个枚举这么换之后的有多少组公共牌情形可以让target获胜
	// 随后判断是否比当前记录的换法更优, 更新答案
	std::pair<std::pair<Card, Card>, int> ans = {{Card("AH"), Card("AH")}, -1};
	// iter 1: 不进行交换
	int no_swap = calc(target);
	bool hasSWAP = false;
	if(no_swap > ans.second) {
		ans.second = no_swap;
	}
	//printf("noswap: %d\n", ans.second);
	for(int i = 0; i < 4; i++){ // 选择一只 Capoo 和 pub 换牌
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 3; k++){
				std::swap(pri[i][j], pub[k]); // 交换, 比较的时候记得复制一份pri
				int tmp = calc(target);	
				//printf("swp(%d:%d, pub:%d) tgt: %d\n", i, j, k, tmp);
				if(tmp >= ans.second) {
					if(tmp == ans.second){
						if(hasSWAP){ // 优先用不交换的方案
							std::string tmp_A = value[pri[i][j].value] + (char)pri[i][j].suit;
							std::string tmp_B = value[pub[k].value] + (char)pub[k].suit;
							std::string ans_A = value[ans.first.first.value] + (char)ans.first.first.suit;
							std::string ans_B = value[ans.first.second.value] + (char)ans.first.second.suit;
							if(tmp_A > tmp_B) std::swap(tmp_A, tmp_B);
							if(ans_A > ans_B) std::swap(ans_A, ans_B);
							if(tmp_A + tmp_B < ans_A + ans_B){
								ans.first = {pri[i][j], pub[k]};
								ans.second = tmp;
								hasSWAP = true;
							}
						}
					} else { 
						ans.first = {pri[i][j], pub[k]};
						ans.second = tmp;
						hasSWAP = true;
					}
				}
				std::swap(pri[i][j], pub[k]); // 换回来
			}
		}
	}	
	for(int i = 0; i < 4; i++){ // 选择一只 Capoo 和别的 Capoo 换牌
		for(int j = 0; j < 2; j++){
			for(int k = i + 1; k < 4; k++){
				for(int k2 = 0; k2 < 2; k2++){
					std::swap(pri[i][j], pri[k][k2]); // 交换, 比较的时候记得复制一份pri
					int tmp = calc(target);	
					//printf("swp(%d:%d, %d:%d) tgt: %d\n", i, j, k, k2, tmp);
					if(tmp >= ans.second) {
						if(tmp == ans.second){
							if(hasSWAP){ // 优先用不交换的方案
								std::string tmp_A = value[pri[i][j].value] + (char)pri[i][j].suit;
								std::string tmp_B = value[pri[k][k2].value] + (char)pri[k][k2].suit;
								std::string ans_A = value[ans.first.first.value] + (char)ans.first.first.suit;
								std::string ans_B = value[ans.first.second.value] + (char)ans.first.second.suit;
								if(tmp_A > tmp_B) std::swap(tmp_A, tmp_B);
								if(ans_A > ans_B) std::swap(ans_A, ans_B);
								if(tmp_A + tmp_B < ans_A + ans_B){
									ans.first = {pri[i][j], pri[k][k2]};
									ans.second = tmp;
									hasSWAP = true;
								}
							}
						} else {
							ans.first = {pri[i][j], pri[k][k2]};
							ans.second = tmp;
							hasSWAP = true;
						}
					}
					std::swap(pri[i][j], pri[k][k2]); // 换回来
				}
			}
		}
	}
	//printf("%d\n", ans.second);
	if(value[ans.first.first.value] + (char)ans.first.first.suit > value[ans.first.second.value] + (char)ans.first.second.suit) std::swap(ans.first.first, ans.first.second);
	if(!hasSWAP){
		printf("None\n");
	} else {
		std::cout << value[ans.first.first.value] + (char)ans.first.first.suit << ' ' << value[ans.first.second.value] + (char)ans.first.second.suit << std::endl;
	}
}
 
int main(){
	scanf("%d", &T);
	while(T--) {
		init();
		Solve();
	}
	return 0;
}
