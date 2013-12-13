static const int N = 10010;

void permutation(int n)
{
    int perm[N];

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    do {
        for (int i = 0; i < n; i++) {
            printf("%d ", perm[i]);
        }
        printf("\n");
    } while (std::next_permutation(perm, perm + n));

}