void search()
{
	int left = 0;
	int right = n-1;
	int mid = (left+right)/2;
	bool find = false;

	while(left<=right){
		int tmp = //compare arr[index] with mid
		if(tmp<0){
			right = mid-1;
		} else if(tmp>0){
			left = mid+1;
		} else{
			find = true;
			break;
		}
		mid = (left+right)/2;
	}
}