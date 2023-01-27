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

template <typename T> struct Fenwick {
	
	int n;
	T* array;
	
	Fenwick(){}
	
	Fenwick(int newN){
		this->n = newN + 1;
		array = new T[n];
		f(i, n) {
			array[i] = 0;
		}
	}
	
	T prefSum(int index) {
		T sum = 0;
		index++;
		while(index > 0) {
			sum += array[index];
			index -= (index & (-index));
		}
		return sum;
	}
	
	int query(int l, int r) {
		int rSum = prefSum(r);
		int lSum = prefSum(l - 1);
		return rSum - lSum;
	}
	
	void update(int index, T value) {
		index++;
		while(index < n) {
			array[index] += value;
			index += (index & (-index));
		}
	}
};

int N = 10;
int NUMBER_OF_TESTS = 10;

void tests() {
	//given
	int array[N];
	f(i, N) {
		array[i] = 0;
	}
	Fenwick<int> f = Fenwick<int>(N);
	//when
	f(i, NUMBER_OF_TESTS) {
		int index = rnd() % N;
		int value = rnd() % N;
		array[index] += value;
		f.update(index, value);
	}
	//then
	f(i, N) {
		fp(j, i, N) {
			int sum = 0;
			fp(k, i, j + 1) {
				sum += array[k];
			}
			int fenwickSum = f.query(i, j);
			if(fenwickSum != sum) {
				cout<<"[TESTS FAILED on test ("<<i<<", "<<j<<")!]"<<nl;
				cout<<"result equals: "<<fenwickSum<<nl;
				cout<<"should equal: "<<sum<<nl;
				return;
			}
		}
	}
	cout<<"[FENWICK TESTS PASSED!]"<<nl;
}

int main() {
	tests();	
	return 0;
}
