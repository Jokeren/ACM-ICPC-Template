static const int N = 20;
static const int CH = 28;

struct Trie {
    int ch[N * CH][CH];
    int value[N * CH];
    int sz;
    Trie():sz(1) {
        memset(ch[0], 0, sizeof(ch[0]));
        memset(value, 0, sizeof(value));
    }

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(value, 0, sizeof(value));
    }

    void insert(char *s, int v) {
        int u = 0, n = strlen(s);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a' + 1;
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                value[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }

        value[u] = v;
    }

    bool search(char *s) {
        int u = 0, n = strlen(s);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a' + 1;
            if (ch[u][c] != 0) {
                u = ch[u][c];
            } else {
                return false;
            }
        }

        return true;
    }
};