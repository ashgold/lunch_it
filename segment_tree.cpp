#include<cstdio>
#include<vector>
using namespace std;

struct RMQ {
	int n;
	vector<int> tree;
	RMQ(const vector<int>& arr) {
		n = arr.size();
		tree.resize(n*4);
		init(arr, 0, n-1, 1);
	}
	int init(const vector<int>& arr, int left, int right, int node) {
		if(left == right) return tree[node] = arr[left];
		int mid = (left + right) / 2;
		int leftMin = init(arr, left, mid, node*2);
		int rightMin = init(arr, mid+1, right, node*2+1);
		return tree[node] = min(leftMin, rightMin);
	}
	//interface
	int query(int left, int right) {
		return query(left, right, 1, 0, n-1);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if(left > nodeRight || right < nodeLeft) return INT_MAX;
		if(left <= nodeLeft && right >= nodeRight) return tree[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node*2, nodeLeft, mid),
				   query(left, right, node*2+1, mid+1, nodeRight));
	}
	
	int update(int idx, int value) {
		return update(idx, value, 1, 0, n-1);
	}
	int update(int idx, int value, int node, int nodeLeft, int nodeRight) {
		if(idx > nodeRight || idx < nodeLeft) return tree[node];
		if(nodeLeft == nodeRight) return tree[node] = value;
		int mid = (nodeLeft + nodeRight) / 2;
		return tree[node] = min(update(idx, value, node*2, nodeLeft, mid), 
								update(idx, value, node*2+1, mid+1, nodeRight));
	}
};

int main() {
	vector<int> v;
	for(int i = 1; i <= 10; i++) v.push_back(i);
	RMQ rmq(v);
	printf("%d\n", rmq.query(1,5));
	rmq.update(1, 10);
	
	printf("%d\n", rmq.query(1,5));
	return 0;
}