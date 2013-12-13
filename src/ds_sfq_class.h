class sq{
private:
    int n,rear,front;
    struct q{
        int id,v;
    }*queue;

public:
    sq(int n1):n(n1),rear(-1),front(0){
        queue = (struct q*)malloc(n1*sizeof(q));
    }

    void push(int id,int v){
        rear++;
        queue[rear].id=id;
        queue[rear].v=v;
        while(rear-1>=front&&queue[rear-1].v>queue[rear].v)
        {
            rear--;
            queue[rear]=queue[rear+1];
        }
    }

    int query(int id)
    {
        while(front<=rear&&queue[front].id<id)
        {
            front++;
        }
        if(front>rear)return 0;
        return queue[front].v;
    }
};