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

struct Dsu {
	
	int n;
	int* representative;
	int* size;
	
	Dsu() {}
	
	Dsu(int newN) {
		this->n = newN;
		this->representative = new int[n];
		this->size = new int[n];
		f(i, n) {
			representative[i] = i;
			size[i] = 1;
		}
	}
	
	int find(int index) {
		if(representative[index] != index) {
			representative[index] = find(representative[index]);
		}
		return representative[index];
	}
	
	void onion(int index1, int index2) {
		index1 = find(index1);
		index2 = find(index2);
		if(size[index1] > size[index2]) {
			swap(index1, index2);
		}
		representative[index1] = index2;
		size[index2] += size[index1];
		size[index1] = 0;
	}
};

int N = 1000;
int NUMBER_OF_TESTS = 1000;

void tests() {
	//given
	int representative[N];
	f(i, N) {
		representative[i] = i;
	}
	Dsu dsu = Dsu(N);
	//when
	f(i, NUMBER_OF_TESTS) {
		int index1 = rnd() % N;
		int index2 = rnd() % N;
		dsu.onion(index1, index2);
		f(j, N) {
			int rep1 = index1;
			int rep2 = index2;
			while(representative[rep1] != rep1) {
				rep1 = representative[rep1];
			}
			while(representative[rep2] != rep2) {
				rep2 = representative[rep2];
			}
			representative[rep1] = rep2;
		}
	}
	//then
	f(i, N) {
		f(j, N) {
			int rep1 = i;
			int rep2 = j;
			while(representative[rep1] != rep1) {
				rep1 = representative[rep1];
			}
			while(representative[rep2] != rep2) {
				rep2 = representative[rep2];
			}
			if((dsu.find(i) == dsu.find(j)) != (rep1 == rep2)) {
				cout<<"[TESTS FAILED on test ("<<i<<", "<<j<<")!]"<<nl;
				cout<<"result equals: "<<(dsu.find(i) == dsu.find(j) ? "TRUE" : "FALSE")<<nl;
				cout<<"should equal: "<<(rep1 == rep2 ? "TRUE" : "FALSE")<<nl;
				return;
			}
		}
	}
	cout<<"[DSU TESTS PASSED!]"<<nl;
}

int main() {
	tests();
	return 0;
}
