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

int evaluate(string& s,int i,int j,bool istrue=1){
	if(i>j)return 0;
	else if(i==j){
		if(istrue)return s[i]=='T';
		else s[i]=='F';
	}
	int res=0;
	for(int k=i+1;k<j;k+=2){
		int lt=evaluate(s,i,k-1,1);
		int lf=evaluate(s,i,k-1,0);
		int rt=evaluate(s,k+1,j,1);
		int rf=evaluate(s,k+1,j,0);
		if(s[k]=='&'){
			if(istrue){
				res=res+ rt*lt;
			}
			else{
				res= res+rt*lf+rf*lt+rf*lf;
			}
		}
		else if(s[k]=='|'){
			if(istrue){
				res= res+rt*lf+rf*lt+rt*lt;
			}
			else{
				res= res+rf*lf;
			}
		}
		else if(s[k]=='^'){
			if(istrue){
				res= res+rt*lf+rf*lt;
			}
			else{
				res= res+rt*lt+rf*lf;
			}
		}
	}
	return res;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string operand,op;
	getline(cin,operand);
	getline(cin,op);
	string expression="";
	int len=operand.size()+op.size();
	int i=0,j=0;
	for(int k=0;k<len;k++){
		if(k%2==0)expression.push_back(operand[i++]);
		else expression.push_back(op[j++]);
	}
	// cout<<expression<<" "<<len<<endl;
	cout<<evaluate(expression,0,len-1);
	
	return 0;
}