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
			int c = s[i] - 'a' + 1;//�ַ��ı�ʱ�޸�
			if (!trie[p][c]){//�മ���죬���ֻ��һ����������жϵ�Ȼû����
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

			//fail˵��
			//�����ڸ��ڵ�ĺ�׺���ҵ���Ӧ�ַ������ڵ��׺����ȱʧ���һ���ַ�����
			//����û���ҵ���Ӧ�ַ�����Ȼ�������Ҳ�����׺�ˣ����Ծʹ���϶���ƥ���ˣ���ô���Լ������ݡ�
			for (int i = 1; i <= CH - 1; i++)
			{
				//��1��������ҵ��ַ�������fail������ǰ����
				if (trie[p][i])
				{
					int v = trie[p][i];
					q.push(v);
					fail[v] = trie[fail[p]][i];
				}//��2���������Ϊû���ҵ��ַ�������ֱ�ӻ���
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