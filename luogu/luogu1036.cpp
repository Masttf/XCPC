#include<iostream>
#include<vector>
using namespace std;
vector<int> res;
void backtrack(int &sum,vector<int> &choice,int start,int k,int &count);
bool isPrime(int n);
int main(){
	int k,n;
	cin>>n>>k;
	vector<int> chioce;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		chioce.push_back(x);
	}	
	int sum=0,count=0;
	backtrack(sum,chioce,0,k,count);
	int ans=0;
	for(int i=0;i<res.size();i++){
		if(isPrime(res[i]))ans++;
	}
	cout<<ans;
	return 0;
}
void backtrack(int &sum,vector<int> &choice,int start,int k,int &count){
	if(count==k){
		res.push_back(sum);
		return ;
	}
	for(int i=start;i<choice.size();i++){
		sum+=choice[i];
		count++;
		backtrack(sum,choice,i+1,k,count);
		sum-=choice[i];
		count--;
	}
}
bool isPrime(int n){
	if(n==1)
		return false;
	for(int i=2;i*i<n;i++){
		if(n%i==0)return false;
	}
	return true;
}
