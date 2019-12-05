#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 26

typedef struct trieNode {
	char data;
	int count;
	bool isWord;
	struct trieNode *next[MAX];
}trieNode;

trieNode *createNewTrieNode() {
	trieNode *newNode = malloc(sizeof(trieNode));
	newNode->count = 1;
	newNode->isWord = false;
	for (int i = 0; i < MAX; i++)
		newNode->next[i] = NULL;

	return newNode;
}

void insert(trieNode *root, char str[]) {
	int i, len = strlen(str);
	trieNode *p = root;

	root->count += 1;

	for (i = 0; i < len; i++) {
		if (p->next[str[i] - 'a'] == NULL) {
			trieNode *newNode = createNewTrieNode();
			newNode->data = str[i];
			p->next[str[i] - 'a'] = newNode;
		} else {
			p->next[str[i] - 'a']->count += 1;
		}
		p = p->next[str[i] - 'a']; 
	}
	p->isWord = true;
}

void preOrder(trieNode *p) {
	if (p == NULL)
		return;

	printf("(%c, %d)\t", p->data, p->count);
	for (int i = 0; i < MAX; i++)
		preOrder(p->next[i]);
}

void printTrie(trieNode *root) {
	printf("Total Words counts: %d\n", root->count);
	for (int i = 0; i < MAX; i++) {
		preOrder(root->next[i]);
		putchar('\n');
	}
}

bool search(trieNode *root, char *str) {
	int i, len = strlen(str);
	trieNode *p = root;
	for (i = 0; i < len; i++) {
		if (p->next[str[i] - 'a'] == NULL)
			return false;
		p = p->next[str[i] - 'a'];
	}
	
	return p->isWord == true;
}

int prefixCount(trieNode *root, char *str) {
	if (root == NULL)
		return 0;
	trieNode *p = root;

	int i, len = strlen(str);
	printf("len = %d\n", len);
	for (i = 0; i < len; i++) {
		if (p->next[str[i] - 'a'] == NULL)
			return 0;
		p = p->next[str[i] - 'a'];
	}

	return p->count;
}

int main() {
	trieNode *root = createNewTrieNode();
	root->count = 0;
	char word[MAX];
	char *str[] = {"abcd", "apple", "inn", "ink", "hello", "he", "in", "hi"};	
	int dataSize = 8;
	for (int i = 0; i < dataSize; i++)
		insert(root, str[i]);
	printTrie(root);

/*
	printf("\nInput a word: ");
	scanf("%s", word);
	if (search(root, word))
		printf("Found - %s\n", word);
	else
		printf("UnFound - %s\n", word);
*/	
	printf("\nPrefix count...\nInput a string: ");
	scanf("%s", word);
	printf("Prefix - %s count: %d\n", word, prefixCount(root, word));
	

	return 0;
}
