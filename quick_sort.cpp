#include<cstdio>
#include<algorithm>
using namespace std;

int pick_pivot(int* a, int left, int right){
	int mid = (left+right)/2;
	if(a[left] > a[mid]) swap(left, mid);
	if(a[left] > a[right]) swap(left, right);
	if(a[mid] > a[right]) swap(mid, right);
	return mid;
}

int partition(int* a, int left, int right) {
	int p = pick_pivot(a, left, right);
	swap(a[p], a[left]);
	int l = left+1, r = right;
	while (l < r) {        
		while (l < right && a[l] < a[left]) l++;
		while (r > left && a[r] >= a[left]) r--;
		if (l < r) swap(a[l], a[r]);
	}
	if(a[left]>a[r]) swap(a[left], a[r]);
	return r;
}

void quick_sort(int* a, int left, int right) {
	if(left >= right) return ;
	int mid = partition(a, left, right);
	quick_sort(a, left, mid-1);
	quick_sort(a, mid+1, right);
}

int main() {
	int D[10] = {5,2,7,6,1,3,9,0,8,10};
	quick_sort(D, 0, 9);

	for(int i = 0; i < 10; i++){
		printf("%d ", D[i]);
	}
}