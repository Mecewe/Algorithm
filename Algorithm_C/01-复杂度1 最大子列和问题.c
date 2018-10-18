#include<stdio.h>

int main(){
	int k,i,sum,max;
	scanf("%d", &k);
	int a[k];
	sum = max = 0;
	for (i = 0; i < k; i++){
		scanf("%d", &a[i]);
		sum += a[i];
		if (max < sum){
			max = sum;
		}
		else if (sum < 0){
			sum = 0;
		}
	}
	printf("%d", max);
	return 0;
}
