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
int solve(string& s,int ind,string& res=""){
	if(ind<0){
		cout<<res<<endl;
		return 1;
	}
	else if(s[ind]=='0'){
		return 0;
	}
	int ans=0;
	ans=solve(s,ind-1,res+(char)(s[ind]+96));
	if(ind>=1){
		int num=s[ind-1]*10+s[ind];
		if(num<=26){
		char ch=(char)(num+96);
		ans=(ans+solve(s,ind-2,res+ch))%mod;
	}
	}
	if(ans<0){
		ans=ans+mod;
	}
	return ans%mod;
	
}
	
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	getline(cin,str);
	int n=s.size();
	cout<<solve(str,n-1);
	return 0;
}