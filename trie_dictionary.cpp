#if 1
#include<cstdio>
#include<string.h>
const int ALPHABET = 26;
int toNumber(char ch) { return ch - 'A';}

struct TrieNode {
	TrieNode* child[ALPHABET];
	int terminal, first;
	TrieNode() : terminal(-1), first(-1) {
		memset(child, 0, sizeof(child));
	}
	~TrieNode() {
		for(int i = 0; i < ALPHABET; i++){
			if(child[i]) delete child[i];
		}
	}
	TrieNode* find(const char* str) {
		if(*str == 0) return this;
		int next = toNumber(*str);
		if(child[next] == NULL) return NULL;
		return child[next]->find(str+1);
	}

	void insert(const char* str, int id) {
		if(first == -1) first = id;
		if(*str == '\0') {
			terminal = id;
			return ;
		}
		int next = toNumber(*str);
		if(child[next] == NULL) child[next] = new TrieNode();
		child[next]->insert(str+1, id);
	}

	int type(const char* str, int id) {
		if(*str == '\0') return 0;
		if(first == id) return 1;
		int next = toNumber(*str);
		return 1 + child[next]->type(str+1, id);
	}
};

int countKeys(TrieNode* trie, const char* str) {
	TrieNode* node = trie->find(str);
	if(node == NULL || node->terminal == -1) return strlen(str);
	return trie->type(str, node->terminal);
}

int main(){
	char str[6][10] = {"GOLD", "GOOD", "GOOOD", "HOLD", "HOLL", "T"};
	TrieNode trie;
	for(int i = 0; i < 6; i++) {
		trie.insert(str[i], i);
	}
	for(int i = 0; i < 6; i++) {
		printf("%d\n", countKeys(&trie, str[i]));
	}
	if(trie.find("ASHGOLD") != NULL) printf("ASHGOLD exists!!\n");
	if(trie.find("ASHGOLF") != NULL) printf("ASHGOLF exists!!\n");
	return 0;
}
#endif