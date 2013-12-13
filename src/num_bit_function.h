int inline first_bit_one(int num)
{
    int k = 0x1, i = 1;
    for(i = 1;i<=31;i++){
        if((num&k) != 0){
            break;
        }
        k = (k<<1);
    }

    return i;
}