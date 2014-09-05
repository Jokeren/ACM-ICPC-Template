char search[N];
char word[M];
int next[M];

void kmp_table()
{
	next[0] = -1;

	int len_word = strlen(word);
	int k = 0;
	for (int i = 1; i < len_word; i++) {
		/*
		 * step 1:
		 * cur idx not match, back the prefix section which is the same as the suffix ones.
		 */
		while (k > -1 && word[k] != word[i]) {
			k = next[k];
		}

		/*
		 * step 2:
		 * tag it
		 */
		next[i] = k; 

		/*
		 * k = -1 indicates there's no match, next idx should begin by k = 0
		 */
		if (k == -1) {
			k = 0;
		} else if (word[k] == word[i]) {
			k++;
		}
	}
}

int kmp_search()
{
	int len_search = 0, len_word = 0;
	int ncount = 0;

	len_search = strlen(search);
	len_word = strlen(word);

	for (int k = -1, i = 0; i < len_search; i++) {
		/*
		 * step 1:
		 * compare to the one which matches
		 */
		while (k > -1 && search[i] != word[k + 1]) k = next[k];	
		
		/* 
		 * step 2:
		 * if two words match, increase value of k
		 */
		if (word[k + 1] == search[i]) {
			k++;
		}

		/*
		 * step 3:
		 * find a matched word
		 */
		if (len_word - 1 == k) {
			k = next[k];
			ncount++;
		}
	}

	return ncount;
}