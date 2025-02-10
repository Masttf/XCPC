#include<bits/stdc++.h>
#include <windows.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int temp=100;
	while(temp--){
		system("gt.exe > gt.txt");
		system("G.exe < gt.txt > G.txt");
		system("an.exe < gt.txt > an.txt");
		Sleep(100);
		if(system("fc G.txt an.txt"))break;

	}
	

	return 0;
}