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

struct Utils {
	
	int stringToInt(string str) {
		bool sign = false;
		int number = 0;
		if(s(str) > 0 && str[0] == '-') {
			sign = true;
		}
		fp(i, sign, s(str)) {
			number = number * 10 + str[i] - '0';
		}
		if(sign) {
			number *= -1;
		}
		return number;
	}
	
	string intToString(ll number) {
		bool sign = false;
		string str = "";
		if(number == 0) {
			return "0";
		}
		if(number < 0) {
			sign = true;
			number *= -1;
		}
		while(number > 0) {
			str += number % 10 + '0';
			number /= 10;
		}
		if(sign) {
			str += '-';
		}
		reverse(all(str));
		return str;
	}
	
	int sumOfDigits(ll number) {
		int sum = 0;
		while(number > 0) {
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
	
	int numberOfDigits(ll number) {
		int digitsNumber = 0;
		if(number == 0) {
			return 1;
		}
		while(number > 0) {
			digitsNumber++;
			number /= 10;
		}
		return digitsNumber;
	}
};

Utils u = Utils();

bool stringToIntTests() {
	//given
	int numberOftests = 12;
	string strings[numberOftests] = {"123456789", "987654321", "111111111", "1122334455", "1", "0", "", "-123456789", "-987654321", "-111111111", "-1122334455", "-1"};
	int numbers[numberOftests] = {123456789, 987654321, 111111111, 1122334455, 1, 0, 0, -123456789, -987654321, -111111111, -1122334455, -1};
	//when
	int stringsToNumbers[numberOftests];
	f(i, numberOftests) {
		stringsToNumbers[i] = u.stringToInt(strings[i]);
	}
	//then
	f(i, numberOftests) {
		if(stringsToNumbers[i] != numbers[i]) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"string: "<<strings[i]<<nl;
			cout<<"result equals: "<<stringsToNumbers[i]<<nl;
			cout<<"should equal: "<<numbers[i]<<nl;
			return false;
		}
	}
	cout<<"[STRING TO INT TESTS PASSED!]"<<nl;
	return true;
}

bool intToStringTests() {
	//given
	int numberOftests = 11;
	int numbers[numberOftests] = {123456789, 987654321, 111111111, 1122334455, 1, 0, -123456789, -987654321, -111111111, -1122334455, -1};
	string strings[numberOftests] = {"123456789", "987654321", "111111111", "1122334455", "1", "0", "-123456789", "-987654321", "-111111111", "-1122334455", "-1"};
	//when
	string numbersToString[numberOftests];
	f(i, numberOftests) {
		numbersToString[i] = u.intToString(numbers[i]);
	}
	//then
	f(i, numberOftests) {
		if(numbersToString[i] != strings[i]) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<numbers[i]<<nl;
			cout<<"result equals: "<<numbersToString[i]<<nl;
			cout<<"should equal: "<<strings[i]<<nl;
			return false;
		}
	}
	cout<<"[INT TO STRING TESTS PASSED!]"<<nl;
	return true;
}

bool sumOfDigitsTests() {
	//given
	int numberOftests = 10;
	int numbers[numberOftests] = {123456789, 987654321, 111111111, 1122334455, 1, 0, 999999999, 44444, 77, 1000};
	int sums[numberOftests] = {45, 45, 9, 30, 1, 0, 81, 20, 14, 1};
	//when
	int sumsOfDigits[numberOftests];
	f(i, numberOftests) {
		sumsOfDigits[i] = u.sumOfDigits(numbers[i]);
	}
	//then
	f(i, numberOftests) {
		if(sumsOfDigits[i] != sums[i]) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<numbers[i]<<nl;
			cout<<"result equals: "<<sumsOfDigits[i]<<nl;
			cout<<"should equal: "<<sums[i]<<nl;
			return false;
		}
	}
	cout<<"[SUM OF DIGITS TESTS PASSED!]"<<nl;
	return true;
}

bool numberOfDigitsTests() {
	//given
	int numberOftests = 11;
	int numbers[numberOftests] = {0, 1, 12, 655, 6543, 64536, 543252, 9867556, 67324872, 908564393, 1245989605};
	int digitsNumber[numberOftests] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//when
	int numberOfDigits[numberOftests];
	f(i, numberOftests) {
		numberOfDigits[i] = u.numberOfDigits(numbers[i]);
	}
	//then
	f(i, numberOftests) {
		if(numberOfDigits[i] != digitsNumber[i]) {
			cout<<"[TESTS FAILED on test "<<i + 1<<"!]"<<nl;
			cout<<"number: "<<numbers[i]<<nl;
			cout<<"result equals: "<<numberOfDigits[i]<<nl;
			cout<<"should equal: "<<digitsNumber[i]<<nl;
			return false;
		}
	}
	cout<<"[NUMBER OF DIGITS TESTS PASSED!]"<<nl;
	return true;
}

int main() {
	bool allPassed = true;
	allPassed &= stringToIntTests();
	allPassed &= intToStringTests();
	allPassed &= sumOfDigitsTests();
	allPassed &= numberOfDigitsTests();
	return 0;
}
