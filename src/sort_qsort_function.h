inline int random_in_range(int start, int end)
{
    return rand()%(end-start+1)+start;
}

inline void m_swap(int *a, int *b)
{
    int tmp = b;
    *b = *a;
    *a = tmp;
}

int m_partition(int data[], int length, int start, int end)
{
    if(data == NULL || length<=0 || start <0 || end >= length)
        throw new std::exception("invalid parameters");

    int index = random_in_range(start,end);
    m_swap(&data[index],&data[end]);
    
    int small = start-1;
    for(index = start; index<end;index++){
        if(data[index]<data[end]){
            small++;
            m_swap(&data[index],&data[small]);
        }
    }
    
    small++;
    m_swap(&data[small],&data[end]);
    
    return small;
}

void q_sort(int data[], int length, int start, int end)
{
    if(start==end)
        return ;
    int index = m_partition(data,length,start,end);
    if(index > start){
        q_sort(data,length,start,index-1);
    } else {
        q_sort(data,length,index+1,end);
    }
}