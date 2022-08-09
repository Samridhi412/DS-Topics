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
unordered_map<string,bool> mp;
bool f(string& s,string& t,string& in){
	if(s.size()==0&&t.size()==0&&in.size()==0)return true;
	else if(in.empty()==0)return false;
	else if(s.size()==0&&t.size()&&in.size()!=0)return false;
	string str=s+"|"+t+"|"+in;
	if(mp.count(str))return mp[str];
	bool l=(s.size()&&s[0]==in[0])?f(s.substr(1),t,in.substr(1)):false;
	bool r=(t.size()&&t[0]==in[0])?f(s,t.substr(1),in.substr(1)):false;
	return mp[str]=l || r;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string first,second,interleave;
	cin.ignore();
	getline(cin,first);
	getline(cin,second);
	getline(cin,interleave);
	cout<<f(first,second,interleave);
	return 0;
}