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
int people[11][101];
ll dp[101][(1<<11)];
void helper(int n){
	string s;
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin,s);
		stringstream in(s);
		int a;
		while(in>>a){
			people[i+1][a]=1;
		}
		
	}
}
int helper(int shirt,int mask.int n){
	int count=__builtin_popcount();
	if(count==n){
		return 1;
	}
	else if(shirt>100){
		return 0;
	}
	else if(dp[shirt][mask]!=-1)return dp[shirt][mask];
	int ans=0;
	for(int j=0;j<n;j++){
		if(!mask&(1<<j)){
			if(people[j+1][shirt]){
				ans=(ans+helper(shirt+1,(mask|(1<<j)),n));
			}
		}
	}
	ans=(ans+helper(shirt+1,mask,n));
	return dp[shirt][mask]=ans;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=0;i<t;i++){
		memset(people,0,sizeof people);
		memset(dp,-1,sizeof dp)
		int n;
		cin>>n;
		solve(n);
		helper(1,0,n);
	}
	return 0;
}