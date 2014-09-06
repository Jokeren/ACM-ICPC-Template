#define N 1000

int pre[N];
int mid[N];

class bst{
private:
    struct node{
        node* left;
        node* right;
        int c;
    }tree[N];
    int num_of_node;
public:
    bst(int v):num_of_node(0){
        create(v);
    }

    int get_num_of_node(){
        return num_of_node;
    }

    node* get_root(){
        return &tree[0];
    }

    node* create(int c){
        tree[num_of_node].c = c;
        tree[num_of_node].left = tree[num_of_node].right = NULL;
        return &tree[num_of_node++];
    }

    node *build(node* n, int v){
        if(v>n->c){
            if(n->right == NULL){
                node *t = create(v);
                n->right = t;
                return t;
            } else {
                build(n->right,v);
            }
        } else if(v<n->c){
            if(n->left == NULL){
                node *t = create(v);
                n->left = t;
                return t;
            } else {
                build(n->left,v);
            }
        }
    }

    
    node* build_pre_mid(int s1, int e1, int s2, int e2){
        node* n = create(pre[s1]);
        int index;
        for(int i = s2;i<=e2;i++){
            if(mid[i] == pre[s1]){
                index = i;
                break;
            }
        }

        if(index > s2){
            n->left = build_pre_mid(s1+1,s1+(index-s2),s2,index-1);
        }
		
        if(index < e2){
            n->right = build_pre_mid(s1+index-s2+1,e1,index+1,e2);
        }

        return n;
    }
   

    void post_order(node* t){
        if(t->left!=NULL){
            post_order(t->left);
        }

        if(t->right!=NULL){
            post_order(t->right);
        }

        printf("%d ",t->c);
    }

    void pre_order(node* t){
        printf("%d ",t->c);

        if(t->left!=NULL){
            pre_order(t->left);
        }

        if(t->right!=NULL){
            pre_order(t->right);
        }
    }

    void mid_order(node* t){
        if(t->left!=NULL){
            mid_order(t->left);
        }

        printf("%d ",t->c);

        if(t->right!=NULL){
            mid_order(t->right);
        }
    }
};