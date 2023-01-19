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

struct mint {

	int number;
	int modulo;
	
	mint() {
		this->modulo = M;
		this->number = 0;
	}
	
	mint(long long num) {
		this->modulo = M;
		this->number = num % modulo;
	}
	
	mint(mint& num) {
		this->modulo = M;
		this->number = num.number % modulo;
	}
	
	mint(long long num, int mod) {
		this->modulo = mod;
		this->number = num % mod;
	}
	
	mint(mint& num, int mod) {
		this->modulo = mod;
		this->number = num.number % mod;
	}
	
	int pow(int power) {
		return fastPower(number % modulo, power);
	}
	
	int inv() {
		return fastInverse(number % modulo);
	}
	
	int fastPower(int base, int power) {
		if(power == 0) {
			return 1;
		} else if((power & 1) == 0) {
			int tmp = fastPower(base, (power >> 1)) % modulo;
			return ((long long)tmp * tmp) % modulo;
		} else {
			return ((long long)base * fastPower(base, power - 1)) % modulo;
		}
	}
	
	int fastInverse(int num) {
		return fastPower(num % modulo, modulo - 2) % modulo;
	}
	
	mint operator=(const mint& num)       { return ((*this).number = num.number % modulo); }
	mint operator=(const int& num)        { return ((*this).number = num % modulo); }
	mint operator=(const long long& num)  { return ((*this).number = num % modulo); }
	
	int operator+(const mint& num)        { return (number + (num.number % modulo)) % modulo; }
	int operator+(const int& num)         { return (number + (num % modulo)) % modulo; }
	int operator+(const long long& num)   { return (number + (num % modulo)) % modulo; }
	
	mint operator+=(const mint& num)      { return ((*this).number = (number + (num.number % modulo)) % modulo); }
	mint operator+=(const int& num)       { return ((*this).number = (number + (num % modulo)) % modulo); }
	mint operator+=(const long long& num) { return ((*this).number = (number + (num % modulo)) % modulo); }
	
	int operator-(const mint& num)        { return (number - (num.number % modulo) + modulo) % modulo; }
	int operator-(const int& num)         { return (number - (num % modulo) + modulo) % modulo; }
	int operator-(const long long& num)   { return (number - (num % modulo) + modulo) % modulo; }
	
	mint operator-=(const mint& num)      { return ((*this).number = (number - (num.number % modulo) + modulo) % modulo); }
	mint operator-=(const int& num)       { return ((*this).number = (number - (num % modulo) + modulo) % modulo); }
	mint operator-=(const long long& num) { return ((*this).number = (number - (num % modulo) + modulo) % modulo); }
	
	int operator*(const mint& num)        { return (number * (long long)(num.number % modulo)) % modulo; }
	int operator*(const int& num)         { return (number * (long long)(num % modulo)) % modulo; }
	int operator*(const long long& num)   { return (number * (long long)(num % modulo)) % modulo; }
	
	mint operator*=(const mint& num)      { return ((*this).number = (number * (long long)(num.number % modulo)) % modulo); }
	mint operator*=(const int& num)       { return ((*this).number = (number * (long long)(num % modulo)) % modulo); }
	mint operator*=(const long long& num) { return ((*this).number = (number * (long long)(num % modulo)) % modulo); }
	
	int operator/(const mint& num)        { return (number * (long long)(fastInverse(num.number % modulo))) % modulo; }
	int operator/(const int& num)         { return (number * (long long)(fastInverse(num % modulo))) % modulo; }
	int operator/(const long long& num)   { return (number * (long long)(fastInverse(num % modulo))) % modulo; }
	
	mint operator/=(const mint& num)      { return ((*this).number = (number * (long long)(fastInverse(num.number % modulo))) % modulo); }
	mint operator/=(const int& num)       { return ((*this).number = (number * (long long)(fastInverse(num % modulo))) % modulo); }
	mint operator/=(const long long& num) { return ((*this).number = (number * (long long)(fastInverse(num % modulo))) % modulo); }
	
	int operator%(const int& num)         { return number % num; }
	mint operator%=(const int& num)       { return ((*this).number = number % num); }
	
	int operator<<(const int& num)         { return (number << (num % modulo)) % modulo; }
	mint operator<<=(const int& num)       { return ((*this).number = (number << (num % modulo)) % modulo); }
	
	int operator>>(const int& num)         { return (number >> (num % modulo)) % modulo; }
	mint operator>>=(const int& num)       { return ((*this).number = (number >> (num % modulo)) % modulo); }
	
	bool operator==(const mint& num)      { return number == (num.number % modulo); }
	bool operator==(const int& num)       { return number == (num % modulo); }
	bool operator==(const long long& num) { return number == (num % modulo); }
	
	bool operator!=(const mint& num)      { return number != (num.number % modulo); }
	bool operator!=(const int& num)       { return number != (num % modulo); }
	bool operator!=(const long long& num) { return number != (num % modulo); }
	
	bool operator>(const mint& num)       { return number > (num.number % modulo); }
	bool operator>(const int& num)        { return number > (num % modulo); }
	bool operator>(const long long& num)  { return number > (num % modulo); }
	
	bool operator>=(const mint& num)      { return number >= (num.number % modulo); }
	bool operator>=(const int& num)       { return number >= (num % modulo); }
	bool operator>=(const long long& num) { return number >= (num % modulo); }
	
	bool operator<(const mint& num)       { return number < (num.number % modulo); }
	bool operator<(const int& num)        { return number < (num % modulo); }
	bool operator<(const long long& num)  { return number < (num % modulo); }
	
	bool operator<=(const mint& num)      { return number <= (num.number % modulo); }
	bool operator<=(const int& num)       { return number <= (num % modulo); }
	bool operator<=(const long long& num) { return number <= (num % modulo); }
	
	mint operator[](const int& index) { return (*this)[index]; }
	
	friend ostream& operator<<(ostream& out, const mint& modular);
};
ostream& operator<<(ostream& out, const mint& modular) {
	return (out << modular.number);
}

struct math {
	
	int n;
	mint* power2 = nullptr;
	mint* factorial = nullptr;
	mint* binomial = nullptr;
	bool* primeSieve = nullptr;
	vector<int>* factorsSieve = nullptr;
	vector<int>* divisorsSieve = nullptr;
	
	math() {}
	
	math(int newN) {
		this->n = newN + 1;
	}
	
	void initializePower2() {
		power2 = new mint[n];
		power2[0] = 1;
		fp(i, 1, n) {
			power2[i] = power2[i - 1] << 1;
		}
	}
	
	void initializeFactorial() {
		factorial = new mint[n];
		factorial[0] = 1;
		fp(i, 1, n) {
			factorial[i] = factorial[i - 1] * i;
		}
	}
	
	void initializeBinomial() {
		if(factorial == nullptr) {
			initializeFactorial();
		}
		binomial = new mint[n];
		f(i, n) {
			binomial[i] = factorial[n - 1] / (factorial[i] * factorial[n - i - 1]);
		}
	}
	
	void initializePrimeSieve() {
		primeSieve = new bool[n];
		primeSieve[0] = primeSieve[1] = false;
		fp(i, 2, n) {
			primeSieve[i] = true;
		}
		int j;
		fp(i, 2, n) {
			if(primeSieve[i]) {
				j = i << 1;
				while(j < n) {
					primeSieve[j] = false;
					j += i;
				}
			}
		}
	}
	
	void initializeFactorsSieve() {
		primeSieve = new bool[n];
		factorsSieve = new vector<int>[n];
		primeSieve[0] = primeSieve[1] = false;
		factorsSieve[0].clear();
		factorsSieve[1].clear();
		fp(i, 2, n) {
			primeSieve[i] = true;
			factorsSieve[i].clear();
		}
		int j;
		fp(i, 2, n) {
			if(primeSieve[i]) {
				j = i << 1;
				while(j < n) {
					primeSieve[j] = false;
					factorsSieve[j].pb(i);
					j += i;
				}
				factorsSieve[i].pb(i);
			}
		}
	}
	
	void initializeDivisorsSieve() {
		primeSieve = new bool[n];
		divisorsSieve = new vector<int>[n];
		primeSieve[0] = primeSieve[1] = false;
		divisorsSieve[1].pb(1);
		fp(i, 2, n) {
			primeSieve[i] = true;
			divisorsSieve[i].clear();
			divisorsSieve[i].pb(1);
		}
		int j;
		fp(i, 2, n) {
			j = i << 1;
			while(j < n) {
				primeSieve[j] = false;
				divisorsSieve[j].pb(i);
				j += i;
			}
			divisorsSieve[i].pb(i);
		}
	}
	
	int rhoPollard(int number, int retries) {
		if(number <= 1) {
			return 1;
		}
		if(number % 2 == 0) {
			return 2;
		}
		int x = rnd() % number + 1;
		int y = x;
		int a = rnd() % number + 1;
		int g = 1;
		while(g == 1) {
			x = ((x * (long long)x) + a) % number;  
			y = ((y * (long long)y) + a) % number;
			y = ((y * (long long)y) + a) % number;  
			g = gcd(abs(x - y), number);
		}
		if(number == g && retries > 0) {
			return rhoPollard(number, retries - 1);
		}
		return g;
	}
	
	int log(long long number, int base)
	{
		int logarithm = 0;
		while(number / base)
		{
			 logarithm++;
			number /= base;
		}
		return  logarithm;
	}
	
	mint bigBinomial(int p, int q) {
		mint topPart = 1;
		mint bottomPart = 1;
		fp(i, p - q + 1, p + 1)
		{
			topPart *= i;
		}
		fp(i, 2, q + 1)
		{
			bottomPart *= i;
		}
		return topPart * bottomPart.inv();
	}
	
	bool isPrime(int x) {
		if(x < 2) {
			return false;
		}
		if((x & 1) == 0 && x > 2) {
			return false;
		}
		for(int i = 3; i * i <= x; i += 2) {
			if(x % i == 0) {
				return false;
			}
		}
		return true;
	}
	
	bool rhoPollardIsPrime(int number, int retries) {
		return number >= 2 && rhoPollard(number, retries) == number;
	}
	
	vector<int> getFactors(int number) {
		vector<int> factors;
		if(number < 2) {
			return factors;
		}
		if((number & 1) == 0) {
			factors.pb(2);
		}
		while((number & 1) == 0) {
			number >>= 1;
		}
		for(int i = 3; i * i <= number; i += 2) {
			if(number % i == 0) {
				factors.pb(i);
			}
			while(number % i == 0) {
				number /= i;
			}
		}
		if(number > 1) {
			factors.pb(number);
		}
		return factors;
	}
	
	vector<int> getDivisors(int number) {
		vector<int> factors;
		for(int i = 1; i * i <= number; i++) {
			if(number % i == 0) {
				factors.pb(i);
				if(i * i != number) {
					factors.pb(number / i);
				}
			}
		}
		return factors;
	}
	
	mint* getPower2() {
		if(power2 == nullptr) {
			initializePower2();
		}
		return power2;
	}
	
	mint* getFactorial() {
		if(factorial == nullptr) {
			initializeFactorial();
		}
		return factorial;
	}
	
	mint* getBinomial() {
		if(binomial == nullptr) {
			initializeBinomial();
		}
		return binomial;
	}
	
	bool* getPrimes() {
		if(primeSieve == nullptr) {
			initializePrimeSieve();
		}
		return primeSieve;
	}
	
	vector<int>* getFactors() {
		if(factorsSieve == nullptr) {
			initializeFactorsSieve();
		}
		return factorsSieve;
	}
	
	vector<int>* getDivisors() {
		if(divisorsSieve == nullptr) {
			initializeDivisorsSieve();
		}
		return divisorsSieve;
	}
};

#define N 1000
math m = math(N);
int NUMBER_OF_TESTS = 1000;

bool power2Tests() {
	//given
	m.getPower2();
	int powers2[N];
	powers2[0] = 1;
	fp(i, 1, N) {
		powers2[i] = ((long long)powers2[i - 1] * 2) % M;
	}
	//then
	f(i, N) {
		if(m.getPower2()[i] != powers2[i]) {
			cout<<"[TEST FAILED!]"<<nl;
			cout<<"index: "<<i<<nl;
			cout<<"result equals: "<<m.getPower2()[i]<<nl;
			cout<<"should equal: "<<powers2[i]<<nl;
			return false;
		}
	}
	cout<<"[POWER OF 2 TESTS PASSED!]"<<nl;
	return true;
}

bool factorialTests() {
	//given
	m.getFactorial();
	int factorials[N];
	factorials[0] = 1;
	fp(i, 1, N) {
		factorials[i] = ((long long)factorials[i - 1] * i) % M;
	}
	//then
	f(i, N) {
		if(m.getFactorial()[i] != factorials[i]) {
			cout<<"[TEST FAILED!]"<<nl;
			cout<<"index: "<<i<<nl;
			cout<<"result equals: "<<m.getFactorial()[i]<<nl;
			cout<<"should equal: "<<factorials[i]<<nl;
			return false;
		}
	}
	cout<<"[FACTORIAL TESTS PASSED!]"<<nl;
	return true;
}

bool binomialTests() {
	//given
	m.getBinomial();
	int binomials[N];
	f(i, N) {
		int top = 1;
		int bottom1 = 1;
		int bottom2 = 1;
		fp(j, 1, N + 1) {
			top = ((long long)top * j) % M;
		}
		fp(j, 1, i + 1) {
			bottom1 = ((long long)bottom1 * j) % M;
		}
		fp(j, 1, N - i + 1) {
			bottom2 = ((long long)bottom2 * j) % M;
		}
		binomials[i] = ((long long)top * mint().fastInverse(((long long)bottom1 * bottom2) % M)) % M;
	}
	//then
	f(i, N) {
		if(m.getBinomial()[i] != binomials[i]) {
			cout<<"[TEST FAILED!]"<<nl;
			cout<<"index: "<<i<<nl;
			cout<<"n: "<<N<<nl;
			cout<<"k: "<<i<<nl;
			cout<<"result equals: "<<m.getBinomial()[i]<<nl;
			cout<<"should equal: "<<binomials[i]<<nl;
			return false;
		}
	}
	cout<<"[BINOMIAL TESTS PASSED!]"<<nl;
	return true;
}

bool bigBinomialTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int top = rnd() % N + 1;
		int bottom = rnd() % top;
		mint topBinom = 1;
		mint bottomBinom1 = 1;
		mint bottomBinom2 = 1;
		fp(j, 1, top + 1) {
			topBinom *= j;
		}
		fp(j, 1, bottom + 1) {
			bottomBinom1 *= j;
		}
		fp(j, 1, (top - bottom) + 1) {
			bottomBinom2 *= j;
		}
		mint binom = topBinom / (bottomBinom1 * bottomBinom2);
		//when
		mint bigBinomial = m.bigBinomial(top, bottom);
		//then
		if(bigBinomial.number != binom.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"top: "<<top<<nl;
			cout<<"bottom: "<<bottom<<nl;
			cout<<"result equals: "<<bigBinomial.number<<nl;
			cout<<"should equal: "<<binom.number<<nl;
			return false;
		}
	}
	cout<<"[BIG BINOMIAL TESTS PASSED!]"<<nl;
	return true;
}

bool isPrimeTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int number = rnd() % N;
		bool prime = number > 1;
		fp(j, 2, number) {
			if(number % j == 0) {
				prime = false;
				break;
			}
		}
		//when
		bool isPrime = m.isPrime(number);
		//then
		if(isPrime != prime) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<number<<nl;
			cout<<"result equals: "<<(isPrime ? "TRUE" : "FALSE")<<nl;
			cout<<"should equal: "<<(prime ? "TRUE" : "FALSE")<<nl;
			return false;
		}
	}
	cout<<"[IS PRIME TESTS PASSED!]"<<nl;
	return true;
}

bool rhoPollardIsPrimeTests() {
	int numberOfFailedTests = 0;
	f(i, NUMBER_OF_TESTS) {
		//given
		int number = rnd() % INF;
		bool prime = m.isPrime(number);
		//when
		bool isPrime = m.rhoPollardIsPrime(number, 2);
		//then
		if(isPrime != prime) {
			numberOfFailedTests++;
		}
	}
	if(numberOfFailedTests > NUMBER_OF_TESTS / 100) {
		cout<<"[OVER 1% TESTS FAILED"<<nl;
		cout<<"failed "<<numberOfFailedTests<<" of "<<NUMBER_OF_TESTS<<" tests"<<nl;
		return false;
	}
	cout<<"[RHO POLLARD IS PRIME TESTS PASSED!]"<<nl;
	return true;
}

bool getFactorsTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int number = rnd() % NUMBER_OF_TESTS;
		vector<int> factors;
		int num = number;
		fp(j, 2, num + 1) {
			if(num % j == 0) {
				factors.pb(j);
			}
			while(num % j == 0) {
				num /= j;
			}
		}
		//when
		vector<int> allFactors = m.getFactors(number);
		//then
		if(s( allFactors) != s(factors)) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<number<<nl;
			cout<<"size of result vector equals: "<<s( allFactors)<<nl;
			cout<<"size of result vector should equal: "<<s(factors)<<nl;
			return false;
		}
		f(j, s(factors)) {
			if( allFactors[j] != factors[j]) {
				cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
				cout<<"number: "<<number<<nl;
				cout<<"result equals:";
				f(k, s( allFactors)) {
					cout<<" "<< allFactors[k];
				}
				cout<<nl;
				cout<<"should equal:";
				f(k, s(factors)) {
					cout<<" "<<factors[k];
				}
				cout<<nl;
				return false;
			}
		}
	}
	cout<<"[FACTORIZE TESTS PASSED!]"<<nl;
	return true;
}

bool getDivisorsTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int number = rnd() % NUMBER_OF_TESTS;
		vector<int> divisors;
		int num = number;
		fp(j, 1, num + 1) {
			if(num % j == 0) {
				divisors.pb(j);
			}
		}
		//when
		vector<int> allDivisors = m.getDivisors(number);
		sort(all(allDivisors));
		//then
		if(s(allDivisors) != s(divisors)) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<number<<nl;
			cout<<"size of result vector equals: "<<s(allDivisors)<<nl;
			cout<<"size of result vector should equal: "<<s(divisors)<<nl;
			return false;
		}
		f(j, s(divisors)) {
			if(allDivisors[j] != divisors[j]) {
				cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
				cout<<"number: "<<number<<nl;
				cout<<"result equals:";
				f(k, s(allDivisors)) {
					cout<<" "<<allDivisors[k];
				}
				cout<<nl;
				cout<<"should equal:";
				f(k, s(divisors)) {
					cout<<" "<<divisors[k];
				}
				cout<<nl;
				return false;
			}
		}
	}
	cout<<"[FACTORIZE ALL FACTORS TESTS PASSED!]"<<nl;
	return true;
}

bool primeSieveTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int number = rnd() % N + 1;
		//when
		bool prime = m.isPrime(number);
		//then
		if(m.getPrimes()[number] != prime) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<number<<nl;
			cout<<"result equals: "<<(m.getPrimes()[number] ? "TRUE" : "FALSE")<<nl;
			cout<<"should equal: "<<(prime ? "TRUE" : "FALSE")<<nl;
			return false;
		}
	}
	cout<<"[PRIME SIEVE TESTS PASSED!]"<<nl;
	return true;
}

bool factorsSieveTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int number = rnd() % N + 1;
		//when
		vector<int> factors = m.getFactors(number);
		vector<int> allFactors = m.getFactors()[number];
		//then
		if(s(allFactors) != s(factors)) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<number<<nl;
			cout<<"size of result vector equals: "<<s(allFactors)<<nl;
			cout<<"size of result vector should equal: "<<s(factors)<<nl;
			return false;
		}
		f(j, s(factors)) {
			if(allFactors[j] != factors[j]) {
				cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
				cout<<"number: "<<number<<nl;
				cout<<"result equals:";
				f(k, s(allFactors)) {
					cout<<" "<<allFactors[k];
				}
				cout<<nl;
				cout<<"should equal:";
				f(k, s(factors)) {
					cout<<" "<<factors[k];
				}
				cout<<nl;
				return false;
			}
		}
	}
	cout<<"[FACTORS SIEVE TESTS PASSED!]"<<nl;
	return true;
}

bool divisorsSieveTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int number = rnd() % N + 1;
		//when
		vector<int> divisors = m.getDivisors(number);
		vector<int> allDivisors = m.getDivisors()[number];
		sort(all(divisors));
		//then
		if(s(allDivisors) != s(divisors)) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<number<<nl;
			cout<<"size of result vector equals: "<<s(allDivisors)<<nl;
			cout<<"size of result vector should equal: "<<s(divisors)<<nl;
			return false;
		}
		f(j, s(divisors)) {
			if(allDivisors[j] != divisors[j]) {
				cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
				cout<<"number: "<<number<<nl;
				cout<<"result equals:";
				f(k, s(allDivisors)) {
					cout<<" "<<allDivisors[k];
				}
				cout<<nl;
				cout<<"should equal:";
				f(k, s(divisors)) {
					cout<<" "<<divisors[k];
				}
				cout<<nl;
				return false;
			}
		}
	}
	cout<<"[DIVISORS SIEVE TESTS PASSED!]"<<nl;
	return true;
}

int main() {
	bool allPassed = true;
	allPassed &= power2Tests();
	allPassed &= factorialTests();
	allPassed &= binomialTests();
	allPassed &= bigBinomialTests();
	allPassed &= isPrimeTests();
	allPassed &= rhoPollardIsPrimeTests();
	allPassed &= getFactorsTests();
	allPassed &= getDivisorsTests();
	allPassed &= primeSieveTests();
	allPassed &= factorsSieveTests();
	allPassed &= divisorsSieveTests();
	cout<<"-------------------------------------------\n"<<((allPassed) ? "ALL TESTS PASSED!" : "TESTS FAILED!")<<nl;
	return 0;
}
