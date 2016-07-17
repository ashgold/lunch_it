#include<cstdio>
#include<string.h>
const int ALPHABET = 26;
int toNumber(char ch) { return ch - 'A';}

struct TrieNode {
	TrieNode* child[ALPHABET];
	bool terminal;
	TrieNode() : terminal(false) {
		memset(child, 0, sizeof(child));
	}
	~TrieNode() {
		for(int i = 0; i < ALPHABET; i++){
			if(child[i]) delete child[i];
		}
	}

	void insert(const char* str) {
		if(*str == '\0') {
			terminal = true;
			return ;
		}
		int next = toNumber(*str);
		if(child[next] == NULL) child[next] = new TrieNode();
		child[next]->insert(str+1);
	}

	TrieNode* find(const char* str) {
		if(*str == 0) return this;
		int next = toNumber(*str);
		if(child[next] == NULL) return NULL;
		return child[next]->find(str+1);
	}
};


int main(){
	TrieNode trie;
	trie.insert("ASHGOLD");
	trie.insert("APPLE");
	trie.insert("SUPERAHN");

	if(trie.find("ASHGOLD") != NULL) printf("ASHGOLD exists!!\n");
	if(trie.find("ASHGOLF") != NULL) printf("ASHGOLF exists!!\n");
	return 0;
}