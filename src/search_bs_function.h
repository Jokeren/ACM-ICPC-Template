////This version of implemention will lead some unexpected problems. Do not use!!!
////Instead using upper_bound and lower_bound equivalent version below
//void search()
//{
//	int left = 0;
//	int right = n-1;
//	int mid = (left+right)/2;
//	bool find = false;
//
//	while(left<=right){
//		int tmp = //compare arr[index] with mid
//			if(tmp<0){
//				right = mid-1;
//			} else if(tmp>0){
//				left = mid+1;
//			} else{
//				find = true;
//				break;
//			}
//		mid = (left+right)/2;
//	}
//}

//We should notic that in the general versions and ICPC versions, indices "end" should be assigned to the last
//legal index + 1, hence the return value for no target key situations are last index + 1. Also arr array should be
//declared before using these functions.
//General version
	template <class ForwardIterator, class T>
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
	ForwardIterator it;
	iterator_traits<ForwardIterator>::difference_type count, step;
	count = std::distance(first,last);
	while (count>0)
	{
		it = first; step=count/2; std::advance (it,step);
		if (!(val<*it))                 // or: if (!comp(val,*it)), for version (2)
		{ first=++it; count-=step+1;  }
		else count=step;
	}
	return first;
}

//ICPC version
	template <typename T>
int bsearch_upper(int begin, int end, T val)
{
	int cur;
	int ncount = 0, step = 0;
	ncount = last - begin;
	while (ncount > 0) {
		cur = begin; step = ncount / 2; cur += step;
		if (arr[cur] <= val) {
			begin =++cur; ncount-=step + 1;
		} else {
			ncount = step;
		}
	}	
	return begin;
}

//General version
	template <class ForwardIterator, class T>
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
	ForwardIterator it;
	iterator_traits<ForwardIterator>::difference_type count, step;
	count = distance(first,last);
	while (count>0)
	{
		it = first; step=count/2; advance (it,step);
		if (*it<val) {                 // or: if (comp(*it,val)), for version (2)
			first=++it;
			count-=step+1;
		}
		else count=step;
	}
	return first;
}

//ICPC version
	template<typename T>
int bsearch_lower(int begin, int end, T val)
{
	int cur;
	int ncount = 0, step = 0;
	ncount = last - begin;
	while (ncount > 0) {
		cur = begin; step = ncount / 2; cur += step;
		if (arr[cur] < val) {
			begin=++cur; ncount-=step + 1;
		} else {
			ncount = step;
		}
	}	
	return begin;
}
