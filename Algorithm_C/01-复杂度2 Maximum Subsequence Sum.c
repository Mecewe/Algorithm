/**
*仍存在一定问题 
*
*/
#include<stdio.h>
#include<stdbool.h>

int main(){
	int k,i,sum,max,first0,first,last;
	bool isPositive=false;
	scanf("%d", &k);
	int a[k];
	sum = 0;
	max = 0;
	first = 0;
	last = 0;
	for (i = 0; i < k; i++){
		scanf("%d", &a[i]);
		if (sum == 0 ){
			first0 = a[i];
		}else if (i==0){
			first0 = a[0];
		}
		sum += a[i];
		if (max < sum){
			max = sum;
			first = first0;
			last = a[i];
		}
		else if (sum < 0){
			sum = 0;
		}
		if (a[i]>=0){
			isPositive=true;
		}
	}
	if (!isPositive){
		first = a[0];
		last = a[k-1];
	}
	printf("%d %d %d", max,first,last);
	return 0;
}


