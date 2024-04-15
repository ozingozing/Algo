#include<iostream>
using namespace std;
struct Trie {
	Trie* ch[26];
	bool end;
	Trie() {
		end = false;
		for (int i = 0; i < 26; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (!*s) {
			this->end = true;
			return;
		}
		int now = *s - 'A';
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
	bool find(const char* s) {
		if (!*s) {
			if (end) return true;
			return false;
		}
		int now = *s - 'A';
		if (!ch[now]) return false;
		return ch[now]->find(s + 1);
	}
};
int main(void) {
	Trie* root = new Trie;
	string s = "AAA";
	root->insert(s.c_str());
	string tmp = "AAA";
	if (root->find(tmp.c_str())) cout << "Find!";
	else cout << "No";
	delete root;
}