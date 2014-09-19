struct trie{
	struct trie *child[27];
	int ncount;
	char letter;
}*root;

char dict[N];

void inline trie_build(char *str, int len)
{
	struct trie *prev = root;
	for (int i = 0; i < len; i++) {
		int tmp = str[i] - 'a';
		if (prev->child[tmp] == NULL) {
			prev->child[tmp] = (struct trie *) malloc(sizeof(struct trie));
			memset(prev->child[tmp], 0, sizeof(struct trie));
			prev->child[tmp]->letter = str[i];
		}
		prev->child[tmp]->ncount++;
		prev = prev->child[tmp];
	}
}

int inline trie_search(char *word, int len)
{
	struct trie *prev = root;
	for (int i = 0; i < len; i++) {
		int tmp = word[i] - 'a';
		if (prev->child[tmp] == NULL) {
			return 0;
		}
		else {
			prev = prev->child[tmp];
		}
	}

	return prev->ncount;
}
void solve(int n)
{
	root = (struct trie *) malloc(sizeof(struct trie));
	memset(root, 0, sizeof(struct trie));

	for (int i = 0; i < n; i++) {
		scanf("%s", dict);
		trie_build(dict, strlen(dict));
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%s", dict);
		printf("%d\n", trie_search(dict, strlen(dict)));
	}
}