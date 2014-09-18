/*
 * 深搜（后序遍历），每次都比较最长长度。利用一个拐点的最长值和次长值更新，上层节点只利用最长值。
 */
std::vector<std::vector<int> > g(N);
bool visit[N];
int max = 0;
int root;

std::pair<int, int> traverse(int start)
{
	std::pair<int, int> tmp;
	visit[start] = true;

	if (g[start].size() == 1 && visit[g[start][0]]) {
		tmp.first = 0;
		tmp.second = 0;
		return tmp;
	}
	else {
		std::pair<int, int> ret;
		ret.first = 0;
		ret.second = 0;
		for (int i = 0; i < g[start].size(); i++) {
			if (visit[g[start][i]])
				continue;

			tmp = traverse(g[start][i]);

			/* only the first value is used to update the first and second value
			 */
			if (tmp.first > ret.first) {
				ret.second = ret.first;
				ret.first = tmp.first;
			}
			else if (tmp.first > ret.second) {
				ret.second = tmp.first;
			}
			//printf("2:start %d first %d second %d\n", start, ret.first, ret.second);
		}

		/* if there's no left or right tree
		*/
		ret.first++;
		if ((g[start].size() == 2 && start != root) ||
			(start == root && g[start].size() == 1))
			ret.second = 0;
		else
			ret.second++;

		max = std::max(max, ret.first + ret.second);
		//printf("1:start %d first %d second %d\n", start, ret.first, ret.second);
		return ret;
	}
}
