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
void solve(){
	ll n;
	cin>>n;
	string old_pass;
	bool isupper=false;
	bool islower=false;
	bool isdigit=false;
	bool isspecial=false;
	for(int i=0;i<n;i++){
		char ch;
		cin>>ch;
		old_pass=old_pass+ch;
		if(48<=ch&&ch<=57){
			isdigit=true;
		}
		else if(97<=ch&&ch<=122){
			islower=true;
		}
		else if(65<=ch&&ch<=90){
			isupper=true;
		}
		else{
			isspecial=true;
		}
	}
	// old_pass[n]='\0';
	if(n>=7&&islower&&isupper&&isdigit&&isspecial){
		cout<<old_pass<<endl;
		return;
	}
	if(!islower){
		old_pass=old_pass+'a';
	}
	if(!isupper){
		old_pass=old_pass+'A';
	}
	if(!isdigit){
		old_pass=old_pass+'1';
	}
	if(!isspecial){
		old_pass=old_pass+'#';
	}
	while(old_pass.size()<7){
		old_pass=old_pass+'a';
	}
	cout<<old_pass<<endl;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}