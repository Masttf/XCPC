#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=100;i++){
		system("gtree.exe > g.txt");
		system("ans.exe <g.txt >bbb.txt");
		system("luogu4592.exe < g.txt > aaa.txt");
		//_sleep(1000);
		if(system("fc aaa.txt bbb.txt"))break;
	}
	
	return 0;
}