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
ll minimum_ascii(string& s,string& t,int i,int j){
	if(i<0&&j<0)return 0;
	else if(i<0&&j>=0){
		ll res=0;
		for(int k=0;k<=j;k++){
			res+=t[k];
		}
		return res;
	}
	else if(j<0&&i>=0){
		ll res=0;
		for(int k=0;k<=i;k++){
			res+=s[k];
		}
		return res;
	}
	else if(s[i]==t[j]){
		return minimum_ascii(s,t,i-1,j-1);
	}
	else{
		return min(minimum_ascii(s,t,i-1,j)+s[i],minimum_ascii(s,t,i,j-1)+t[j]);
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s,t;
	getline(cin,s);
	getline(cin,t);
	int m=s.size();
	int n=t.size();
	cout<<minimum_ascii(s,t,m-1,n-1);
	return 0;
}