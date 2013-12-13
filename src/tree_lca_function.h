struct BTree {
    int data;
    int c;
    BTree* lchild;
    BTree* rchild;
};

BTree* LoadBTree()
{
    int data;
    scanf( "%d", &data );
    if ( data == 0 )
        return NULL;
    BTree* node = new BTree;
    node->data = data;
    node->c = 0;
    node->lchild = LoadBTree();
    node->rchild = LoadBTree();
    return node;
}

void DeleteBTree( BTree* root )
{
    if ( root == NULL )
        return;
    DeleteBTree( root->lchild );
    DeleteBTree( root->rchild );
    delete root;
}

BTree* Find( BTree* root, int key )
{
    if ( root == NULL )
        return NULL;
    if ( root->data == key ) {
        root->c++;
        return root;
    }

    BTree* node = Find( root->lchild, key );
    if ( node ) {
        root->c++;
        return node;
    }

    node = Find( root->rchild, key );
    if ( node ) {
        root->c++;
        return node;
    }
    return NULL;
}

void solve(BTree* root)
{
    BTree *node = root;
    while ( 1 ) {
        if ( node->data == m || node->data == n )
            break;
        if ( node->lchild == NULL || node->rchild == NULL ) {
            node->rchild != NULL ? node = node->rchild : node = node->lchild;
            continue;
        }
        if ( node->lchild->c == 1 && node->rchild->c == 1 )
            break;
        if ( node->lchild->c == 2 )
            node = node->lchild;
        else
            node = node->rchild;
    }
    printf( "%d\n", node->data );
}