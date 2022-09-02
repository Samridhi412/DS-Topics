#include<iostream>
#include<vector>
using namespace std;
struct node{
	node* links[26];
	bool containsKey(char ch){
		return (links[ch-'a']!=NULL);
	}
	void put(char ch,node* nn){
		links[ch-'a']=nn;
	}
	node* get(char ch){
		return links[ch-'a'];
	}
};
int main(){
	int n;
	cin>>n;
	vector<string> vect(n);
	for(int i=0;i<n;i++){
		cin>>vect[i];
	}
	// Trie tt;
	int res=0;
	node* root=new node();
	for(int i=0;i<n;i++){
		for(int j=0;j<vect[i].size();j++){
		node* nn=root;
		for(int k=j;k<vect[i].size();k++){
			if(!nn->containsKey(vect[i][k])){
				res++;
				nn->put(vect[i][k],new node());
			}
			nn=nn->get(vect[i][k]);
		}
	}
	}
	res+=1;  //empty string
	cout<<res<<endl;
}
