#include <bits/stdc++.h>
 
#define INF 1000000311
#define LINF 1000000000000000311
#define M 1000000007
#define M1 998244353
 
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pl=pair<ll, ll>;
using vi=vector<int>;
using vl=vector<ll>;
using gr=vector<vector<int> >;
 
#define fp(x, a, b) for (int (x) = (a); (x) < (b); (x)++)
#define f(x, n) for (int (x) = 0; (x) < (n); (x)++)
#define fnp(x, a, b) for (int (x) = (b) - 1; (x) >= (a); (x)--)
#define fn(x, n) for (int (x) = (n - 1); (x) >= 0; (x)--)
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a) * (b) / gcd((a), (b))
#define x first
#define y second
#define mp make_pair 
#define pb push_back
#define s(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ans(x) cout<<(x)<<"\n"
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define nl "\n"
#define fl cout.flush()

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int propagateNodeValue(int a, int b, int d) {
	return a + b * d;
}

int propagateValueToProcess(int a, int b) {
	return a + b;
}

int calculate(int a, int b, int c, int d) {
	return a + b + c * d;
}

template <typename T> struct Segtree {
	
	int n;
	T neutralValue;
	T* nodeValue;
	T* valueToProcess;
	function<T(T, T, T)> propagateNodeValueFunction;
	function<T(T, T)> propagateValueToProcessFunction;
	function<T(T, T, T, T)> calculateFunction;
	
	Segtree() {}
	
	Segtree(int newN, function<T(T, T, T)> propagateNodeValueFunc, function<T(T, T)> propagateValueToProcessFunc, function<T(T, T, T, T)> calculateFunc, T neutral) {
		this->n = (1 << (32 - __builtin_clz(newN - 1)));
		this->nodeValue = new T[n << 1];
		this->valueToProcess = new T[n << 1];
		this->neutralValue = neutral;
		this->propagateNodeValueFunction = propagateNodeValueFunc;
		this->propagateValueToProcessFunction = propagateValueToProcessFunc;
		this->calculateFunction = calculateFunc;
		f(i, (n << 1)) {
			nodeValue[i] = neutralValue;
			valueToProcess[i] = neutralValue;
		}
	}
	
	void update(int l, int r, T value) {
		updateReq(1, 0, n - 1, l, r, value);
	}
	
	T query(int l, int r) {
		return queryReq(1, 0, n - 1, l, r);
	}
	
	void updateReq(int node, int currL, int currR, int targetL, int targetR, T value) {
		int segmentLength = currR - currL + 1;
		if(targetL <= currL && currR <= targetR) {
			nodeValue[node] = propagateNodeValue(nodeValue[node], value, segmentLength);
			valueToProcess[node] = propagateValueToProcessFunction(valueToProcess[node], value);
		} else {
			push(node, segmentLength);
			int pivot = ((currL + currR) >> 1);
			if(targetL <= pivot) {
				updateReq((node << 1), currL, pivot, targetL, targetR, value);
			}
			if(targetR > pivot) {
				updateReq((node << 1) + 1, pivot + 1, currR, targetL, targetR, value);
			}
			nodeValue[node] = calculateFunction(nodeValue[(node << 1)], nodeValue[(node << 1) + 1], valueToProcess[node], segmentLength);
		}
	}
	
	T queryReq(int node, int currL, int currR, int targetL, int targetR) {
		int segmentLength = currR - currL + 1;
		if(targetL <= currL && currR <= targetR) {
			return nodeValue[node];
		} else {
			push(node, segmentLength);
			int pivot = ((currL + currR) >> 1);
			T leftValue = neutralValue;
			T rightValue = neutralValue;
			if(targetL <= pivot) {
				leftValue = queryReq((node << 1), currL, pivot, targetL, targetR);
			}
			if(targetR > pivot) {
				rightValue = queryReq((node << 1) + 1, pivot + 1, currR, targetL, targetR);
			}
			return calculateFunction(leftValue, rightValue, valueToProcess[node], segmentLength);
		}
	}
	
	void push(int node, int segmentLength) {
		if(valueToProcess[node] != neutralValue) {
			nodeValue[(node << 1)] = propagateNodeValueFunction(nodeValue[(node << 1)], valueToProcess[node], (segmentLength >> 1));
			valueToProcess[(node << 1)] = propagateValueToProcessFunction(valueToProcess[(node << 1)], valueToProcess[node]);
			nodeValue[(node << 1) + 1] = propagateNodeValue(nodeValue[(node << 1) + 1], valueToProcess[node], (segmentLength >> 1));
			valueToProcess[(node << 1) + 1] = propagateValueToProcessFunction(valueToProcess[(node << 1) + 1], valueToProcess[node]);
			valueToProcess[node] = neutralValue;
		}
	}
};

int N = 100;
int NUMBER_OF_TESTS = 1000;

void tests() {
	//given
	Segtree<int> s = Segtree<int>(N, propagateNodeValue, propagateValueToProcess, calculate, 0);
	int sumArray[N];
	f(i, N) {
		sumArray[i] = 0;
	}
	//when
	f(i, NUMBER_OF_TESTS) {
		int l = rnd() % N;
		int r = rnd() % N;
		int v = rnd() % N;
		if(l > r) {
			swap(l, r);
		}
		fp(j, l, r + 1) {
			sumArray[j] += v;
		}
		s.update(l, r, v);
		//then
		f(j, N) {
			fp(k, j, N) {
				int query = s.query(j, k);
				int sum = 0;
				fp(q, j, k + 1) {
					sum += sumArray[q];
				}
				if(query != sum) {
					cout<<"[TESTS FAILED on test ("<<j<<", "<<k<<")!]"<<nl;
					cout<<"result equals: "<<query<<nl;
					cout<<"should equal: "<<sum<<nl;
					return;
				}
			}
		}
	}
	cout<<"[SEGMENT TREE TESTS PASSED!]"<<nl;
}

int main() {
	tests();
	return 0;
}
