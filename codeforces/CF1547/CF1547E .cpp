//先安好空调然后将空调的温度扩散即可
#include<iostream>
#include<vector>
using namespace std;
vector<int> postion;
int main(){
	int q;cin>>q;
	while(q--){
		int n,k;
		cin>>n>>k;
		vector<int>s(n,2000000001);
		int set,tem;
		for(int i=0;i<k;i++){
			cin>>set;
			postion.push_back(set);
		}
		for(int i=0;i<k;i++){
			cin>>tem;
			s[postion[i]-1]=tem;
		}
		for(int i=1;i<n;i++) s[i]=min(s[i],s[i-1]+1);
		for(int i=n-2;i>=0;i--) s[i]=min(s[i],s[i+1]+1);
		for(int i=0;i<n;i++){
			cout<<s[i]<<' ';
		}
		cout<<'\n';
		postion.clear();
	}
	return 0;
}
