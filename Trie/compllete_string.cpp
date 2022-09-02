#include<iostream>
#include<vector>
using namespace std;
struct node{
	node* links[26];
	bool flag=false;
	bool containsKey(char ch){
		return (links[ch-'a']!=NULL);
	}
	node* get(char ch){
		return links[ch-'a'];
	}
	void put(char ch,node* nn){
		links[ch-'a']=nn;
	}
	void setEnd(){
		flag=true;
	}
	bool isEnd(){
		return flag;
	}
};
class Trie{
	node* root;
public:
	Trie(){
		root=new node();
	}
	void insert(string word){
		node* nn=root;
		for(int i=0;i<word.size();i++){
			if(!nn->containsKey(word[i])){
				nn->put(word[i],new node());
			}
			nn=nn->get(word[i]);
		}
		nn->setEnd();
	}
	bool checkprefix(string word){
		node* nn=root;
		// bool fl=true;
		for(int i=0;i<word.size();i++){
			if(!nn->containsKey(word[i])){
				return false;
			}
			nn=nn->get(word[i]);
			if(nn->isEnd()==false)return false;
		}
		return true;
	}
};
string completestring(int n,vector<string>& s){
	Trie tt;
	for(int i=0;i<s.size();i++){
		tt.insert(s[i]);
	}
	string longest;
	for(int i=0;i<s.size();i++){
		if(tt.checkprefix(s[i])){
			if(s[i].size()>longest.size())
			{longest=s[i];}
		    else if(s[i].size()==longest.size()&&s[i]<longest){
		    	longest=s[i];
		    }
		}
	}
	return longest==""?"None":longest;
	
}