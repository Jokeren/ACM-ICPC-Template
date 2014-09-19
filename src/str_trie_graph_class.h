class TrieGraph
{
private:
	int trie[N][CH];
	int fail[N];
	int num[N];
	int cur_idx;
	char str_main[N];

public:
	TrieGraph() :cur_idx(1) {
		
	}
	
	void init() {
		memset(trie[0], 0, sizeof(trie[0]));
		cur_idx = 1;
		num[0] = 0;
	}
	
	void insert(char* s) {
		int i = 0, p = 0;
		int len = strlen(s);

		for (i = 0; i <= len - 1; i++)
		{
			int c = s[i] - 'a' + 1;//字符改变时修改
			if (!trie[p][c]){//多串构造，如果只有一个串，这个判断当然没有用
				memset(trie[cur_idx], 0, sizeof(trie[cur_idx]));
				num[cur_idx] = 0;
				trie[p][c] = cur_idx++;
			}
			p = trie[p][c];
		}
		num[p]++;
	}
	
	void build() {
		std::queue<int> q;
		for (int i = 1; i <= CH - 1; i++) {
			if (trie[0][i]) {
				fail[trie[0][i]] = 0;
				q.push(trie[0][i]);
			}
		}

		while (!q.empty())
		{
			int p = q.front();
			q.pop();

			//fail说明
			//可能在父节点的后缀中找到对应字符（父节点后缀本身缺失最后一个字符）。
			//可能没有找到对应字符。既然在这里找不到后缀了，所以就代表肯定不匹配了，那么可以继续回溯。
			for (int i = 1; i <= CH - 1; i++)
			{
				//第1种情况，找到字符，设置fail，继续前进。
				if (trie[p][i])
				{
					int v = trie[p][i];
					q.push(v);
					fail[v] = trie[fail[p]][i];
				}//第2种情况，因为没有找到字符，所以直接回溯
				else
				{
					trie[p][i] = trie[fail[p]][i];
				}
			}
		}
	}

	bool find() {
		int ans = 0, i = 0, p = 0;

		int len = strlen(str_main);
		for (i = 0; i <= len - 1; i++)
		{
			int c = str_main[i] - 'a' + 1;
			p = trie[p][c];
			int tmp = p;
			while (tmp && num[tmp] != -1)
			{
				if (num[tmp] > 0) {
					return true;
				}
				ans += num[tmp];
				num[tmp] = -1;
				tmp = fail[tmp];
			}
		}

		return false;
	}

	char* get_main() {
		return str_main;
	}
};