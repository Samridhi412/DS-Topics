#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
const ld eps=1e-9;
const ll maxn=1e5+1;
const ll inf=5e18;
const ll minf=-inf;
#define mp make_pair
#define pb push_back
#define endl "\n"
//LENGTH OF A AND B WILL ALWAYS BE EQUAL.......
bool solve(string a ,string b,unordered_map<string,bool>& mp){
	if(a.compare(b)==0)return true;
	else if(a.size()<=1)return false;
	else if(mp.find(a+'$'+b)!=mp.end())return mp[a+'$'+b];
	int n=a.size();
	bool flag=false;
	for(int i=1;i<=n-1;i++){
		bool c1=solve(a.substr(0,i),b.substr(0,i))&&solve(a.substr(i,n-i),b.substr(i,n-i));
		bool c2=solve(a.substr(0,i),b.substr(n-i,i))&&solve(a.substr(i,n-i),b.substr(0,n-i));
		if(c1||c2){
			flag=true;
			break;
		}
		
	}
	return mp[a+'$'+b]=flag;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a,b;
	getline(cin,a);
	getline(cin,b);
	if(a.size()!=b.size()){
		cout<<"not scrambled";
	}
	else if(a.size()==0&&b.size()==0){
		cout<<"scrambled";
	}
	unordered_map<string,bool> mpp;
	solve(a,b,mpp);
	return 0;
}