static const int N = 20 * 10;
static const int CH = 28;

struct Trie {
    //N代表节点个数，通常为字符串长度*字符串个数
    //数据量太大时要用new
    int ch[N][CH];
    int value[N][CH];
    int sz;
    Trie():sz(1) {
        memset(ch[0], 0, sizeof(ch[0]));
        memset(value[0], 0, sizeof(value[0]));
    }

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(value[0], 0, sizeof(value[0]));
    }

    void insert(char *s, int v) {
        int u = 0, n = strlen(s);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a' + 1;
            if (!ch[u][c]) {
                //大量节省时间
                memset(ch[sz], 0, sizeof(ch[sz]));
                memset(value[sz], 0, sizeof(value[sz]));
                ch[u][c] = sz++;
            }
            ++value[u][c];
            u = ch[u][c];
        }
    }

    int search(char *s) {
        int u = 0, n = strlen(s);
        int ret;
        int c;

        for (int i = 0; i < n; i++) {
            c = s[i] - 'a' + 1;
            if (ch[u][c] != 0) {
                ret = value[u][c];
                u = ch[u][c];
            } else {
                return 0;
            }
        }

        return ret;
    }
};