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
		return fastPower(num % modulo, M - 2) % modulo;
	}
	
	void operator=(const mint& num)       { number = num.number % modulo; }
	void operator=(const int& num)        { number = num % modulo; }
	void operator=(const long long& num)  { number = num % modulo; }
	
	int operator+(const mint& num)        { return (number + (num.number % modulo)) % modulo; }
	int operator+(const int& num)         { return (number + (num % modulo)) % modulo; }
	int operator+(const long long& num)   { return (number + (num % modulo)) % modulo; }
	
	void operator+=(const mint& num)      { number = (number + (num.number % modulo)) % modulo; }
	void operator+=(const int& num)       { number = (number + (num % modulo)) % modulo; }
	void operator+=(const long long& num) { number = (number + (num % modulo)) % modulo; }
	
	int operator-(const mint& num)        { return (number - (num.number % modulo) + modulo) % modulo; }
	int operator-(const int& num)         { return (number - (num % modulo) + modulo) % modulo; }
	int operator-(const long long& num)   { return (number - (num % modulo) + modulo) % modulo; }
	
	void operator-=(const mint& num)      { number = (number - (num.number % modulo) + modulo) % modulo; }
	void operator-=(const int& num)       { number = (number - (num % modulo) + modulo) % modulo; }
	void operator-=(const long long& num) { number = (number - (num % modulo) + modulo) % modulo; }
	
	int operator*(const mint& num)        { return (number * (long long)(num.number % modulo)) % modulo; }
	int operator*(const int& num)         { return (number * (long long)(num % modulo)) % modulo; }
	int operator*(const long long& num)   { return (number * (long long)(num % modulo)) % modulo; }
	
	void operator*=(const mint& num)      { number = (number * (long long)(num.number % modulo)) % modulo; }
	void operator*=(const int& num)       { number = (number * (long long)(num % modulo)) % modulo; }
	void operator*=(const long long& num) { number = (number * (long long)(num % modulo)) % modulo; }
	
	int operator/(const mint& num)        { return (number * (long long)(fastInverse(num.number % modulo))) % modulo; }
	int operator/(const int& num)         { return (number * (long long)(fastInverse(num % modulo))) % modulo; }
	int operator/(const long long& num)   { return (number * (long long)(fastInverse(num % modulo))) % modulo; }
	
	void operator/=(const mint& num)      { number = (number * (long long)(fastInverse(num.number % modulo))) % modulo; }
	void operator/=(const int& num)       { number = (number * (long long)(fastInverse(num % modulo))) % modulo; }
	void operator/=(const long long& num) { number = (number * (long long)(fastInverse(num % modulo))) % modulo; }
	
	int operator%(const mint& num)        { return number % num.number; }
	int operator%(const int& num)         { return number % num; }
	int operator%(const long long& num)   { return number % num; }
	
	void operator%=(const mint& num)      { number = number % num.number; }
	void operator%=(const int& num)       { number = number % num; }
	void operator%=(const long long& num) { number = number % num; }
	
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



int NUMBER_OF_TESTS = 1000;

bool constructorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = mint();
		modular.number = rnd() % INF;
		int modulo = rnd() % INF;
		//when
		mint blankMint = mint();
		mint integerMint = mint(integer);
		mint longLongMint = mint(longLong);
		mint modularMint = mint(modular);
		mint integerModuloMint = mint(integer, modulo);
		mint longLongModuloMint = mint(longLong, modulo);
		mint modularModuloMint = mint(modular, modulo);
		//then
		if(blankMint.number != 0) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"result equals: "<<blankMint.number<<nl;
			cout<<"should equal: "<<0<<nl;
			return false;
		}
		if(integerMint.number != integer % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMint.number<<nl;
			cout<<"should equal: "<<integer<<nl;
			return false;
		}
		if(longLongMint.number != longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMint.number<<nl;
			cout<<"should equal: "<<longLong<<nl;
			return false;
		}
		if(modularMint.number != modular.number % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modular.number: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMint.number<<nl;
			cout<<"should equal: "<<modular.number<<nl;
			return false;
		}
		if(integerModuloMint.number != integer % modulo) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"modulo: "<<modulo<<nl;
			cout<<"result equals: "<<integerModuloMint.number<<nl;
			cout<<"should equal: "<<integer % modulo<<nl;
			return false;
		}
		if(longLongModuloMint.number != longLong % modulo) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"modulo: "<<modulo<<nl;
			cout<<"result equals: "<<longLongModuloMint.number<<nl;
			cout<<"should equal: "<<longLong % modulo<<nl;
			return false;
		}
		if(modularModuloMint.number != modular.number % modulo) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modular.number: "<<modular.number<<nl;
			cout<<"modulo: "<<modulo<<nl;
			cout<<"result equals: "<<modularModuloMint.number<<nl;
			cout<<"should equal: "<<modular.number % modulo<<nl;
			return false;
		}
	}
	cout<<"[CONSTRUCTORS TESTS PASSED!]"<<nl;
	return true;
}

bool assignmentOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = mint();
		//when
		mint integerMint = mint(rnd() % INF);
		mint longLongMint = mint(rnd() % LINF);
		mint modularMint = mint(rnd() % INF);
		integerMint = integer;
		longLongMint = longLong;
		modularMint = modular;
		//then
		if(integerMint.number != integer % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMint.number<<nl;
			cout<<"should equal: "<<integer % M<<nl;
			return false;
		}
		if(longLongMint.number != longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMint.number<<nl;
			cout<<"should equal: "<<longLong % M<<nl;
			return false;
		}
		if(modularMint.number != modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modular.number: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMint.number<<nl;
			cout<<"should equal: "<<modular.number<<nl;
			return false;
		}
	}
	cout<<"[ASSIGNMENT TESTS PASSED!]"<<nl;
	return true;
}

bool powerTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		mint intBase = rnd() % INF;
		mint longLongBase = rnd() % LINF;
		int power = rnd() % 1000;
		int intResult = 1;
		int longLongResult = 1;
		f(_, power) {
			intResult = (intResult * (long long)intBase.number) % M;
			longLongResult = (longLongResult * (long long)(longLongBase.number % M)) % M;
		}
		//when
		mint intPower = intBase.pow(power);
		mint longLongPower = longLongBase.pow(power);
		//then
		if(intPower != intResult) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"intBase: "<<intBase<<nl;
			cout<<"power: "<<power<<nl;
			cout<<"result equals: "<<intPower.number<<nl;
			cout<<"should equal: "<<intResult<<nl;
			return false;
		}
		if(longLongPower != longLongResult) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"longLongBase: "<<intBase<<nl;
			cout<<"power: "<<power<<nl;
			cout<<"result equals: "<<longLongPower.number<<nl;
			cout<<"should equal: "<<longLongResult<<nl;
			return false;
		}
	}
	cout<<"[POWER TESTS PASSED!]"<<nl;
	return true;
}

bool inverseTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		mint integer = rnd() % INF;
		mint longLong = rnd() % LINF;
		int intResult = integer.pow(M - 2);
		int longLongResult = longLong.pow(M - 2);
		//when
		mint intInverse = integer.inv();
		mint longLongInverse = longLong.inv();
		//then
		if(intInverse != intResult) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"integer: "<<integer.number<<nl;
			cout<<"result equals: "<<intInverse.number<<nl;
			cout<<"should equal: "<<intResult<<nl;
			return false;
		}
		if(longLongInverse != longLongResult) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"longLong: "<<longLong.number<<nl;
			cout<<"result equals: "<<longLongInverse.number<<nl;
			cout<<"should equal: "<<longLongResult<<nl;
			return false;
		}
	}
	cout<<"[INVERSE TESTS PASSED!]"<<nl;
	return true;
}

bool additionOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = rnd() % INF;
		mint modularBase = rnd() % INF;
		//when
		mint integerMint = modularBase + integer;
		mint longLongMint = modularBase + longLong;
		mint modularMint = modularBase + modular;
		mint integerMintBase = modularBase;
		mint longLongMintBase = modularBase;
		mint modularMintBase = modularBase;
		integerMintBase += integer;
		longLongMintBase += longLong;
		modularMintBase += modular;
		//then
		if(integerMint != (modularBase.number + (integer % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number + (integer % M)) % M<<nl;
			return false;
		}
		if(longLongMint != (modularBase.number + (longLong % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number + (longLong % M)) % M<<nl;
			return false;
		}
		if(modularMint.number != (modularBase.number + modular.number) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number + modular.number) % M<<nl;
			return false;
		}
		if(integerMintBase.number != (modularBase.number + (integer % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number + (integer % M)) % M<<nl;
			return false;
		}
		if(longLongMintBase != (modularBase.number + (longLong % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number + (longLong % M)) % M<<nl;
			return false;
		}
		if(modularMintBase.number != (modularBase.number + (modular.number % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number + modular.number) % M<<nl;
			return false;
		}
	}
	cout<<"[ADDITION TESTS PASSED!]"<<nl;
	return true;
}

bool subtractionOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = rnd() % INF;
		mint modularBase = rnd() % INF;
		//when
		mint integerMint = modularBase - integer;
		mint longLongMint = modularBase - longLong;
		mint modularMint = modularBase - modular;
		mint integerMintBase = modularBase;
		mint longLongMintBase = modularBase;
		mint modularMintBase = modularBase;
		integerMintBase -= integer;
		longLongMintBase -= longLong;
		modularMintBase -= modular;
		//then
		if(integerMint != (modularBase.number - (integer % M) + M) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number - (integer % M) + M) % M<<nl;
			return false;
		}
		if(longLongMint != (modularBase.number - (longLong % M) + M) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number - (longLong % M) + M) % M<<nl;
			return false;
		}
		if(modularMint.number != (modularBase.number - modular.number + M) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number - modular.number + M) % M<<nl;
			return false;
		}
		if(integerMintBase.number != (modularBase.number - (integer % M) + M) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number - (integer % M) + M) % M<<nl;
			return false;
		}
		if(longLongMintBase != (modularBase.number - (longLong % M) + M) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number - (longLong % M) + M) % M<<nl;
			return false;
		}
		if(modularMintBase.number != (modularBase.number - modular.number + M) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number - modular.number + M) % M<<nl;
			return false;
		}
	}
	cout<<"[SUBTRACTION TESTS PASSED!]"<<nl;
	return true;
}

bool multiplicationOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = rnd() % INF;
		mint modularBase = rnd() % INF;
		//when
		mint integerMint = modularBase * integer;
		mint longLongMint = modularBase * longLong;
		mint modularMint = modularBase * modular;
		mint integerMintBase = modularBase;
		mint longLongMintBase = modularBase;
		mint modularMintBase = modularBase;
		integerMintBase *= integer;
		longLongMintBase *= longLong;
		modularMintBase *= modular;
		//then
		if(integerMint != (modularBase.number * (long long)(integer % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(integer % M)) % M<<nl;
			return false;
		}
		if(longLongMint != (modularBase.number * (long long)(longLong % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(longLong % M)) % M<<nl;
			return false;
		}
		if(modularMint.number != (modularBase.number * (long long)(modular.number)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(modular.number)) % M<<nl;
			return false;
		}
		if(integerMintBase.number != (modularBase.number * (long long)(integer % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(integer % M)) % M<<nl;
			return false;
		}
		if(longLongMintBase != (modularBase.number * (long long)(longLong % M)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(longLong % M)) % M<<nl;
			return false;
		}
		if(modularMintBase.number != (modularBase.number * (long long)(modular.number)) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(modular.number)) % M<<nl;
			return false;
		}
	}
	cout<<"[MULTIPLICATION TESTS PASSED!]"<<nl;
	return true;
}

bool divisionOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = rnd() % INF;
		mint modularBase = rnd() % INF;
		//when
		mint integerMint = modularBase / integer;
		mint longLongMint = modularBase / longLong;
		mint modularMint = modularBase / modular;
		mint integerMintBase = modularBase;
		mint longLongMintBase = modularBase;
		mint modularMintBase = modularBase;
		integerMintBase /= integer;
		longLongMintBase /= longLong;
		modularMintBase /= modular;
		//then
		if(integerMint != (modularBase.number * (long long)(mint(integer % M).inv())) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(mint(integer % M).inv())) % M<<nl;
			return false;
		}
		if(longLongMint != (modularBase.number * (long long)(mint(longLong % M).inv())) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(mint(longLong % M).inv())) % M<<nl;
			return false;
		}
		if(modularMint.number != (modularBase.number * (long long)(modular.inv())) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMint.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(modular.inv())) % M<<nl;
			return false;
		}
		if(integerMintBase.number != (modularBase.number * (long long)(mint(integer % M).inv())) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(mint(integer % M).inv())) % M<<nl;
			return false;
		}
		if(longLongMintBase != (modularBase.number * (long long)(mint(longLong % M).inv())) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(mint(longLong % M).inv())) % M<<nl;
			return false;
		}
		if(modularMintBase.number != (modularBase.number * (long long)(modular.inv())) % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMintBase.number<<nl;
			cout<<"should equal: "<<(modularBase.number * (long long)(modular.inv())) % M<<nl;
			return false;
		}
	}
	cout<<"[DIVISION TESTS PASSED!]"<<nl;
	return true;
}

bool modulationOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = rnd() % INF;
		mint modularBase = rnd() % INF;
		//when
		mint integerMint = modularBase % integer;
		mint longLongMint = modularBase % longLong;
		mint modularMint = modularBase % modular;
		mint integerMintBase = modularBase;
		mint longLongMintBase = modularBase;
		mint modularMintBase = modularBase;
		integerMintBase %= integer;
		longLongMintBase %= longLong;
		modularMintBase %= modular;
		//then
		if(integerMint != modularBase.number % integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMint.number<<nl;
			cout<<"should equal: "<<modularBase.number % integer<<nl;
			return false;
		}
		if(longLongMint != modularBase.number % longLong) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMint.number<<nl;
			cout<<"should equal: "<<modularBase.number % longLong<<nl;
			return false;
		}
		if(modularMint.number != modularBase.number % modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMint.number<<nl;
			cout<<"should equal: "<<modularBase.number % modular.number<<nl;
			return false;
		}
		if(integerMintBase.number != modularBase.number % integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: "<<integerMintBase.number<<nl;
			cout<<"should equal: "<<modularBase.number % integer<<nl;
			return false;
		}
		if(longLongMintBase != modularBase.number % longLong) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularMintBase: "<<modularBase.number<<nl;
			cout<<"longLong: "<<longLong<<nl;
			cout<<"result equals: "<<longLongMintBase.number<<nl;
			cout<<"should equal: "<<modularBase.number % longLong<<nl;
			return false;
		}
		if(modularMintBase.number != modularBase.number % modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularBase: "<<modularBase.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: "<<modularMintBase.number<<nl;
			cout<<"should equal: "<<modularBase.number % modular.number<<nl;
			return false;
		}
	}
	cout<<"[MODULATION TESTS PASSED!]"<<nl;
	return true;
}

bool equalOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = rnd() % INF;
		mint correctIntegerMint = integer;
		mint correctLongLongMint = longLong;
		mint correctModularMint = modular;
		mint incorrectIntegerMint = integer + 1;
		mint incorrectLongLongMint = longLong + 1;
		mint incorrectModularMint = modular + 1;
		//then
		if(correctIntegerMint.number != integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctIntegerMint: "<<correctIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctLongLongMint.number != longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctLongLongMint: "<<correctLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctModularMint.number != modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctModularMint: "<<correctModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(incorrectIntegerMint.number == integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectIntegerMint: "<<incorrectIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectLongLongMint.number == longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectLongLongMint: "<<incorrectLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectModularMint.number == modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectModularMint: "<<incorrectModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
	}
	cout<<"[EQUAL OPERATOR TESTS PASSED!]"<<nl;
	return true;
}

bool unequalOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF;
		long long longLong = rnd() % LINF;
		mint modular = rnd() % INF;
		mint correctIntegerMint = integer + 1;
		mint correctLongLongMint = longLong + 1;
		mint correctModularMint = modular + 1;
		mint incorrectIntegerMint = integer;
		mint incorrectLongLongMint = longLong;
		mint incorrectModularMint = modular;
		//then
		if(correctIntegerMint.number == integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctIntegerMint: "<<correctIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctLongLongMint.number == longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctLongLongMint: "<<correctLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctModularMint.number == modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctModularMint: "<<correctModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(incorrectIntegerMint.number != integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectIntegerMint: "<<incorrectIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectLongLongMint.number != longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectLongLongMint: "<<incorrectLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectModularMint.number != modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectModularMint: "<<incorrectModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
	}
	cout<<"[UNEQUAL OPERATOR TESTS PASSED!]"<<nl;
	return true;
}

bool greaterOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF + 1;
		long long longLong = rnd() % LINF + 1;
		mint modular = rnd() % INF + 1;
		mint correctIntegerMint = integer + (rnd() % (M - integer)) + 1;
		mint correctLongLongMint = (longLong % M) + (rnd() % (M - (longLong % M))) + 1;
		mint correctModularMint = modular + (int)(rnd() % (M - modular.number)) + 1;
		mint incorrectIntegerMint = rnd() % integer + 1;
		mint incorrectLongLongMint = rnd() % (longLong % M) + 1;
		mint incorrectModularMint = rnd() % modular.number + 1;
		if(rnd() % 2 == 0) {
			incorrectIntegerMint = integer;
			incorrectLongLongMint = longLong;
			incorrectModularMint = modular.number;
		}
		//then
		if(correctIntegerMint.number <= integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctIntegerMint: "<<correctIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctLongLongMint.number <= longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctLongLongMint: "<<correctLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctModularMint.number <= modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctModularMint: "<<correctModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(incorrectIntegerMint.number > integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectIntegerMint: "<<incorrectIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectLongLongMint.number > longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectLongLongMint: "<<incorrectLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectModularMint.number > modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectModularMint: "<<incorrectModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
	}
	cout<<"[GREATER OPERATOR TESTS PASSED!]"<<nl;
	return true;
}

bool greaterOrEqualOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF + 1;
		long long longLong = rnd() % LINF + 1;
		mint modular = rnd() % INF + 1;
		mint correctIntegerMint = integer + (rnd() % (M - integer)) + 1;
		mint correctLongLongMint = (longLong % M) + (rnd() % (M - (longLong % M))) + 1;
		mint correctModularMint = modular + (int)(rnd() % (M - modular.number)) + 1;
		mint incorrectIntegerMint = rnd() % integer + 1;
		mint incorrectLongLongMint = rnd() % (longLong % M) + 1;
		mint incorrectModularMint = rnd() % modular.number + 1;
		if(rnd() % 2 == 0) {
			correctIntegerMint = integer;
			correctLongLongMint = longLong;
			correctModularMint = modular.number;
		}
		//then
		if(correctIntegerMint.number < integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctIntegerMint: "<<correctIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctLongLongMint.number < longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctLongLongMint: "<<correctLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctModularMint.number < modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctModularMint: "<<correctModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(incorrectIntegerMint.number >= integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectIntegerMint: "<<incorrectIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectLongLongMint.number >= longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectLongLongMint: "<<incorrectLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectModularMint.number >= modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectModularMint: "<<incorrectModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
	}
	cout<<"[GREATER OR EQUAL OPERATOR TESTS PASSED!]"<<nl;
	return true;
}

bool lesserOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF + 1;
		long long longLong = rnd() % LINF + 1;
		mint modular = rnd() % INF + 1;
		mint correctIntegerMint = rnd() % integer;
		mint correctLongLongMint = rnd() % (longLong % M);
		mint correctModularMint = rnd() % modular.number;
		mint incorrectIntegerMint = integer + (rnd() % (M - integer)) + 1;
		mint incorrectLongLongMint = (longLong % M) + (rnd() % (M - (longLong % M))) + 1;
		mint incorrectModularMint = modular + (int)(rnd() % (M - modular.number)) + 1;
		if(rnd() % 2 == 0) {
			incorrectIntegerMint = integer;
			incorrectLongLongMint = longLong;
			incorrectModularMint = modular.number;
		}
		//then
		if(correctIntegerMint.number >= integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctIntegerMint: "<<correctIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctLongLongMint.number >= longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctLongLongMint: "<<correctLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctModularMint.number >= modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctModularMint: "<<correctModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(incorrectIntegerMint.number < integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectIntegerMint: "<<incorrectIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectLongLongMint.number < longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectLongLongMint: "<<incorrectLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectModularMint.number < modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectModularMint: "<<incorrectModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
	}
	cout<<"[LESSER OPERATOR TESTS PASSED!]"<<nl;
	return true;
}

bool lesserOrEqualOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		int integer = rnd() % INF + 1;
		long long longLong = rnd() % LINF + 1;
		mint modular = rnd() % INF + 1;
		mint correctIntegerMint = rnd() % integer;
		mint correctLongLongMint = rnd() % (longLong % M);
		mint correctModularMint = rnd() % modular.number;
		mint incorrectIntegerMint = integer + (rnd() % (M - integer)) + 1;
		mint incorrectLongLongMint = (longLong % M) + (rnd() % (M - (longLong % M))) + 1;
		mint incorrectModularMint = modular + (int)(rnd() % (M - modular.number)) + 1;
		if(rnd() % 2 == 0) {
			correctIntegerMint = integer;
			correctLongLongMint = longLong;
			correctModularMint = modular.number;
		}
		//then
		if(correctIntegerMint.number > integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctIntegerMint: "<<correctIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctLongLongMint.number > longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctLongLongMint: "<<correctLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(correctModularMint.number > modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"correctModularMint: "<<correctModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: FALSE"<<nl;
			cout<<"should equal: TRUE"<<nl;
			return false;
		}
		if(incorrectIntegerMint.number <= integer) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectIntegerMint: "<<incorrectIntegerMint.number<<nl;
			cout<<"integer: "<<integer<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectLongLongMint.number <= longLong % M) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectLongLongMint: "<<incorrectLongLongMint.number<<nl;
			cout<<"longLong: "<<longLong % M<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
		if(incorrectModularMint.number <= modular.number) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"incorrectModularMint: "<<incorrectModularMint.number<<nl;
			cout<<"modular: "<<modular.number<<nl;
			cout<<"result equals: TRUE"<<nl;
			cout<<"should equal: FALSE"<<nl;
			return false;
		}
	}
	cout<<"[LESSER OR EQUAL OPERATOR TESTS PASSED!]"<<nl;
	return true;
}

bool arrayOperatorTests() {
	f(i, NUMBER_OF_TESTS) {
		//given
		mint modular1 = rnd() % INF;
		mint modular2 = rnd() % INF;
		mint modular3 = rnd() % INF;
		mint modularArray[3];
		mint multidimensionalModularArray[3][3];
		//when
		modularArray[0] = modular1;
		modularArray[1] = modular2;
		modularArray[2] = modular3;
		f(i, 3) {
			f(j, 3) {
				multidimensionalModularArray[i][j] = modularArray[j];
			}
		}
		//then
		if(modularArray[0] != modular1) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularArray[0]: "<<modularArray[0].number<<nl;
			cout<<"modular1: "<<modular1.number<<nl;
			cout<<"result equals: "<<modularArray[0]<<nl;
			cout<<"should equal: "<<modular1<<nl;
			return false;
		}
		if(modularArray[1] != modular2) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularArray[1]: "<<modularArray[1].number<<nl;
			cout<<"modular2: "<<modular2.number<<nl;
			cout<<"result equals: "<<modularArray[1]<<nl;
			cout<<"should equal: "<<modular2<<nl;
			return false;
		}
		if(modularArray[2] != modular3) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"modularArray[2]: "<<modularArray[2].number<<nl;
			cout<<"modular3: "<<modular3.number<<nl;
			cout<<"result equals: "<<modularArray[2]<<nl;
			cout<<"should equal: "<<modular3<<nl;
			return false;
		}
		f(i, 3) {
			f(j, 3) {
				if(multidimensionalModularArray[i][j] != modularArray[j]) {
					cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
					cout<<"multidimensionalModularArray["<<i<<"]["<<j<<"]: "<<multidimensionalModularArray[i][j].number<<nl;
					cout<<"modularArray["<<j<<"]: "<<modularArray[j].number<<nl;
					cout<<"result equals: "<<multidimensionalModularArray[i][j].number<<nl;
					cout<<"should equal: "<<modularArray[j].number<<nl;
					return false;
				}
			}
		}
	}
	cout<<"[ARRAY OPERATOR TESTS PASSED!]"<<nl;
	return true;
}

int main() {
	bool allPassed = true;
	allPassed &= constructorTests();
	allPassed &= assignmentOperatorTests();
	allPassed &= powerTests();
	allPassed &= inverseTests();
	allPassed &= additionOperatorTests();
	allPassed &= subtractionOperatorTests();
	allPassed &= multiplicationOperatorTests();
	allPassed &= divisionOperatorTests();
	allPassed &= modulationOperatorTests();
	allPassed &= equalOperatorTests();
	allPassed &= unequalOperatorTests();
	allPassed &= greaterOperatorTests();
	allPassed &= greaterOrEqualOperatorTests();
	allPassed &= lesserOperatorTests();
	allPassed &= lesserOrEqualOperatorTests();
	allPassed &= arrayOperatorTests();
	cout<<"-------------------------------------------\n"<<((allPassed) ? "ALL TESTS PASSED!" : "TESTS FAILED!")<<nl;
}
