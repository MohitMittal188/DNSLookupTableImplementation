//Trie implementation


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ALPHABET_SIZE 26

struct trieNode
{
	struct trieNode* children[ALPHABET_SIZE];
	int isLeaf;
};
struct trieNode* getNode()
{
	struct trieNode* node;
	int i;

	node = (struct trieNode*)malloc(sizeof(struct trieNode));

	for (i = 0; i<ALPHABET_SIZE; i++)
		node->children[i] = NULL;

	node->isLeaf = 0;

	return node;

}
void insert(struct trieNode* root, const char*arr)
{
	int i;
	struct trieNode* tempRoot;
	tempRoot = root;

	for (i = 0; i<strlen(arr); i++)
	{
		if (tempRoot->children[arr[i] - 97] == NULL)
		{
			tempRoot->children[arr[i] - 97] = getNode();
			tempRoot = tempRoot->children[arr[i] - 97];
		}
		else
		{
			tempRoot = tempRoot->children[arr[i] - 97];
		}

	}
	tempRoot->isLeaf = 1;
}

int search(struct trieNode* root, const char* arr)
{
	int i;
	struct trieNode* tempRoot;

	tempRoot = root;

	for (i = 0; i<strlen(arr); i++)
	{
		if (!tempRoot->children[arr[i] - 97])
		break;

		tempRoot = tempRoot->children[arr[i] - 97];
	}
	if (tempRoot->isLeaf == 0 || i != strlen(arr))
		return 0;

	return 1;
}
void main()
{
	struct trieNode*root;
	char arr[] = "abc";
	root = getNode();

	insert(root, arr);

	if (search(root, arr))
		printf("there is present");

	getchar();
}

