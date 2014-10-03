/*
 * 应用：单串匹配
 * 复杂度：O(m + n)，因为K值最多+N次，但是K值不可能小于-1，所以k = next[k]最多操作N次。
 * 核心思想：
 * 1. 建表：找到模式串中，与后缀匹配的最长前缀。
 * k值记录最长前缀位置，i值记录当前字符串位置。
 * 为什么不是最短前缀？如果是最短前缀，就会漏过匹配了，肯定是错的。
 * 2. 查表：和建表思想一下，唯一不同是在于可以统计匹配串的数目。
 */
char search[N];
char word[M];
int next[M];

/*
 * 这里next数组为匹配的下一个位置，例：
 * aaaaa$
 * 012345
 * 最后一位也是有用的
 */
void kmp_table()
{
	next[0] = 0;
    next[1] = 0;
	int len_word = strlen(word);

    for (int i = 1; i < len_word; i++) {
        int j = next[i];
        while (j && word[i] != word[j])
            j = next[j];

        next[i + 1] = word[i] == word[j] ? j + 1: 0;
    }
}

bool kmp_search( )//统计次数的时候要改为int
{
	int len_search = 0, len_word = 0;
	int ncount = 0;

	len_search = strlen(search);
	len_word = strlen(word);

	for (int j = 0, i = 0; i < len_search; i++) {
		/*
		 * step 1:
		 * compare to the one which matches
		 */
		while (j && search[i] != word[j]) j = next[j];

		/*
		 * step 2:
		 * if two words match, increase value of k
		 */
		if (word[j] == search[i]) {
			j++;
		}

		/*
		 * step 3:
		 * find a matched word
		 */
		if (len_word == j) {
            return true;
			j = next[j];
			ncount++;
		}
	}

	return false;
}