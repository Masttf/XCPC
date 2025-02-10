#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=100;i++){
		system("ge.exe > ge.txt");
		system("bf.exe <ge.txt >bf.txt");
		system("a.exe <ge.txt >a.txt");
		if(system("fc a.txt bf.txt"))break;
	}
	
	return 0;
}