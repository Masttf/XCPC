#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <functional>
#include <set>
#include <assert.h>
using namespace std;
#define int long long
const int MOD	= 1e9+7;

using DoubleHash = pair<int,int>;
using Tuple = vector<string>;
using TupleHash = vector<DoubleHash>;

DoubleHash Hash(const string & s) {
	int hash1 = 0,hash2 = 0;
	int n = s.length();
	for (int i=0; i<n; i++)	{
		hash1 = hash1 * 131 % MOD + s[i]-'a'+1, hash1 %= MOD;
		hash2 = hash2 * 1331 % MOD + s[i]-'a'+1, hash2 %= MOD;
	}
	return {hash1, hash2};
}

vector<string> fields;
map < string, int> fieldname2idx;
map < DoubleHash, string > hash2string;

// -1 -1 - commit放弃，abort保留
// -2 -2 - commit保留，abort放弃
// -3 -3 - commit放弃，abort放弃

class Table {
public:
	list<TupleHash> table;
	
	Table(const vector<string> &field) {
		for (int i=0; i<field.size(); i++) {
			fieldname2idx[ field[i] ] = i;
		}
	}
	
	void Insert(const Tuple &v) {
		if(v.size() != fields.size()) {
			assert(0);
		}
		
		TupleHash th;
		for(auto &s : v) {
			th.push_back(Hash(s));
		}
		th.push_back({-2,-2});
		table.push_back(th);
		
		for(auto s : v) {
			hash2string[ Hash(s) ] = s;
		}
	}
	
	vector<DoubleHash> Select(const string &output_field, const string &cond_field, const vector<DoubleHash> &cond) {
		assert(fieldname2idx.find(cond_field) != fieldname2idx.end());
		assert(fieldname2idx.find(output_field) != fieldname2idx.end());
		
		int cond_idx = fieldname2idx[cond_field];
		int output_idx = fieldname2idx[output_field];
		
		set<DoubleHash> st;
		for(auto o : cond) {
			st.insert(o);
		}
		
		vector<DoubleHash> res;
		
		for(const auto & o : table) {
			if(o.back()!=make_pair(-1ll, -1ll) && o.back()!=make_pair(-3ll, -3ll) && st.count(o[cond_idx])) {
				res.push_back(o[output_idx]);
			}
		}
		
//		for(auto hsh : table) {
//			if(st.count( hash2tuple[hsh][cond_idx] )) {
//				res.push_back(hash2tuple[hsh][output_idx]);
//			}
//		}
		
		return res;
	}
	
	int Delete(const string &field, const vector<DoubleHash> &cond) {
		assert(fieldname2idx.find(field) != fieldname2idx.end());
		int idx = fieldname2idx[field];
		
		set<DoubleHash> st;
		for(auto o : cond) {
			st.insert(o);
		}
		
		int cnt = 0;
		for (auto it=table.begin(); it!=table.end(); it++) {
			auto &t = *it;
			if(t.back()!=make_pair(-1ll, -1ll) && t.back()!=make_pair(-3ll, -3ll) && st.count(t[idx])) {
				cnt++;
				if(t.back() == make_pair(-2ll, -2ll))
					t.back() = {-3,-3};
				else
					t.push_back({-1,-1});
			}
		}
		
		return cnt;
	}
	
	void Begin() {
		
	}
	
	void Commit() {
		for(auto it = table.begin(); it!=table.end();) {
			if(it->back() == make_pair(-1ll, -1ll) || it->back() == make_pair(-3ll, -3ll)) {
				it = table.erase(it);
			} else if(it->back() == make_pair(-2ll, -2ll)) {
				it->pop_back();
				it ++;
			} else {
				it ++;
			}
		}
	}
	
	void Abort() {
		for(auto it = table.begin(); it!=table.end();) {
			if(it->back() == make_pair(-1ll, -1ll)){
				it->pop_back();
				it ++;
			} else if(it->back() == make_pair(-2ll, -2ll)|| it->back() == make_pair(-3ll, -3ll)) {
				it = table.erase(it);
			} else {
				it++;
			}
		}
	}
	
};

class Executor {
public:
	vector<string> v;
	Table db;
	
	Executor(Table db_) : db(db_) {}
	
	void Init(const string &src) {
		v.clear();
		v.push_back("");
		string tmp;
		for(auto ch : src) {
			if (ch == '\'' || ch=='"') {
				continue;
			}
			if (ch==' ' || ch=='(' || ch==')' || ch==',') {
				v.push_back("");
				continue;
			}
			v.back().push_back(ch);
		}
		while(v.back() == ""){
			v.pop_back();
		}
	}
	
	vector<DoubleHash> Dfs(int l, int r) {
		
		if (v[l] == "select") {
			assert(r-l+1 == 4);
			vector<DoubleHash> vv = {Hash(v[l+3])};
			return db.Select(v[l+1], v[l+2], vv);
			
		} else if(v[l] == "select_in") {
			assert(r-l+1 > 4);
			auto res = Dfs(l+3, r);
			return db.Select(v[l+1], v[l+2], res);
			
		} else if(v[l] == "delete") {
			assert(r-l+1 == 3);
			vector<DoubleHash> vv = {Hash(v[l+2])};
			return{{db.Delete(v[l+1], vv), 0}};
			
		} else if(v[l] == "delete_in") {
			assert(r-l+1 > 3);
			auto res = Dfs(l+2, r);
			return {{db.Delete(v[l+1], res), 0}};
			
		} else if(v[l] == "insert") {
			assert(r-l+1 == (int)fields.size()+1);
			Tuple tuple;
			for (int i=l+1; i<=r; i++) {
				tuple.push_back(v[i]);
			}
			db.Insert(tuple);
			return {{0ll, 0ll}};
		}
		assert(0);
	}
	
	vector<DoubleHash> Execute(const string & s) {
		if(s == "begin()") {
			db.Begin();
			return {};
		} else if(s == "commit()") {
			db.Commit();
			return {};
		} else if(s == "abort()") {
			db.Abort();
			return {};
		}
		Init(s);
		return Dfs(0, v.size()-1);
	}
};

int n, Q;

void Sol() {
	Table table(fields);
	Executor exec(table);
	int last_ans = 0;
	
	while (Q--) {
		string query;
		cin >> query;
		auto res = exec.Execute(query);
		if(query[0] == 's') {
			printf("%lu\n", res.size());
			if(res.size()) {
				cout << hash2string[res[0]] << "\n";
				cout << hash2string[res[((int)res.size()+1)/2-1]] << "\n";
				cout << hash2string[res[(int)res.size()-1]] << "\n";
			}
		} else if(query[0] == 'd') {
			printf("%lld\n", res.front().first);
		}
	}
	
}


signed main() {
	
	scanf("%lld %lld", &n, &Q);
	
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		fields.push_back(s);
	}
	Sol();
	
	return 0;
}