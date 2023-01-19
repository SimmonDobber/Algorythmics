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

struct Sparse {
	
	int n;
	int k;
	function<int(int, int)> associativeFunction;
	int neutralElement;
	int** table;
	
	Sparse() {}
	
	Sparse(int newN, int* array, function<int(int, int)> f) {
		this->n = newN;
		this->k = 32 - __builtin_clz(n);
		this->associativeFunction = f;
		this->neutralElement = 0;
		this->table = new int*[k];
		build(array);
	}
	
	Sparse(int newN, int* array, function<int(int, int)> f, int neutral) {
		this->n = newN;
		this->k = 32 - __builtin_clz(n);
		this->associativeFunction = f;
		this->neutralElement = neutral;
		this->table = new int*[k];
		build(array);
	}
	
	void build(int* array) {
		f(i, k) {
			table[i] = new int[n];
			f(j, n) {
				table[i][j] = 0;
			}
		}
		f(i, n) {
			table[0][i] = array[i];
		}
		fp(i, 1, k) {
			for(int j = 0; j + (1 << i) <= n; j++) {
				table[i][j] = associativeFunction(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	
	int query(int l, int r) {
		int answer = neutralElement;
		fn(i, k) {
			if((1 << i) <= r - l + 1) {
				answer = associativeFunction(answer, table[i][l]);
				l += (1 << i);
			}
		}
		return answer;
	}
	
	int idempotentQuery(int l, int r) {
		int i =  31 - __builtin_clz(r - l + 1);
		return associativeFunction(table[i][l], table[i][r - (1 << i) + 1]);
	}
};

int N = 10;
int NUMBER_OF_TESTS = 10;

int sum(int a, int b) {
	return a + b;
}

int mi(int a, int b) {
	return a < b ? a : b;
}

bool queryTests() {
	//given
	int array[N];
	f(i, N) {
		array[i] = rnd() % N;
	}
	Sparse sparse = Sparse(N, array, sum);
	f(i, NUMBER_OF_TESTS) {
		//when
		int l = rnd() % N;
		int r = rnd() % N;
		if(l > r) {
			swap(l, r);
		}
		int sum = 0;
		fp(j, l, r + 1) {
			sum += array[j];
		}
		int sparseSum = sparse.query(l, r);
		//then
		if(sparseSum != sum) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"l: "<<l<<nl;
			cout<<"r: "<<r<<nl;
			cout<<"result equals: "<<sparseSum<<nl;
			cout<<"should equal: "<<sum<<nl;
			return false;
		}
	}
	cout<<"[QUERY TESTS PASSED!]"<<nl;
	return true;
}

bool idempotentQueryTests() {
	//given
	int array[N];
	f(i, N) {
		array[i] = rnd() % N;
	}
	Sparse sparse = Sparse(N, array, mi);
	f(i, NUMBER_OF_TESTS) {
		//when
		int l = rnd() % N;
		int r = rnd() % N;
		if(l > r) {
			swap(l, r);
		}
		int min = INF;
		fp(j, l, r + 1) {
			min = min > array[j] ? array[j] : min;
		}
		int sparseMin = sparse.idempotentQuery(l, r);
		//then
		if(sparseMin != min) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"l: "<<l<<nl;
			cout<<"r: "<<r<<nl;
			cout<<"result equals: "<<sparseMin<<nl;
			cout<<"should equal: "<<min<<nl;
			return false;
		}
	}
	cout<<"[IDEMPOTENT QUERY TESTS PASSED!]"<<nl;
	return true;
}

int main() {
	bool allPassed = true;
	allPassed &= queryTests();
	allPassed &= idempotentQueryTests();
	return 0;
}
