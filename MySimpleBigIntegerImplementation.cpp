// what operations do I need?
// Plus, equal to, multiply.

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

typedef vector<int> BigInt;

const int base = 1000000000;

BigInt Set(BigInt a) {
	while(a.size() > 1 && a.back() == 0) a.pop_back();
	return a;
}

BigInt Convert(ll x) {
	BigInt num;
	ll b = 0;
	if(x == 0) num.push_back(b);
	while(x > 0){
		b = x % base;
		x = x / base;
		num.push_back(b);
	}
	num = Set(num);
	return num;
}

BigInt Convert(int x) {
	return Convert((ll)x);
}

BigInt operator * (BigInt lhs, BigInt rhs) {
	lhs = Set(lhs);
	rhs = Set(rhs);
	BigInt result;
	result.assign(lhs.size()+rhs.size(), 0);
	for(ll i = 0; i < lhs.size(); ++i) {
		ll l_digit = lhs[i];
		ll carry = 0ll;
		for(ll j = 0; j < rhs.size() || carry > 0; ++j) {
			ll r_digit = rhs[j];
			ll sub_result = result[i+j] + carry + (j < rhs.size() ? r_digit : 0ll) * (ll)l_digit;
			carry = sub_result / base;
			result[i+j] = sub_result % base;
		}
	}
	// if(carry) result.push_back(carry);
	result = Set(result);
	return result;
}

BigInt operator * (BigInt lhs, ll rhs) {
	return lhs * Convert(rhs);
}

BigInt operator * (ll lhs, BigInt rhs) {
	return Convert(lhs) * rhs;
}

BigInt operator + (const BigInt& lhs, const BigInt& rhs) {
	BigInt result;
	ll limit = max(lhs.size(), rhs.size());
	// result.assign(limit+1, 0);
	ll carry = 0;
	/*
	for(ll i = 0; i < limit || carry > 0; ++i) {
		if(i < lhs.size() && i < rhs.size()) {
			ll sub_result = lhs[i] + rhs[i] + carry;
			result[i] = sub_result % base;
			carry = sub_result / base;
		}
		else if(i >= lhs.size()) {
			ll sub_result = (i < rhs.size() ? rhs[i] : 0) + carry;
			result[i] = sub_result % base;
			carry = sub_result / base;
		}
		else if(i >= rhs.size()){
			ll sub_result = (i < lhs.size() ? lhs[i] : 0) + carry;
			result[i] = sub_result % base;
			carry = sub_result / base;
		}
		// result = Set(result);
	}
	*/
	for(ll i = 0; i < limit; ++i) {
		if(i < lhs.size()) carry += lhs[i];
		if(i < rhs.size()) carry += rhs[i];
		result.push_back(carry % base);
		carry /= base;
	}
	if(carry) result.push_back(carry);
	result = Set(result);
	return result;
}

void Print(BigInt b) {
	b = Set(b);
	if(b.size() == 0) {
		printf("%d", 0);
		return;
	}
	else printf("%d", b.back());

	for(ll j = b.size() - 2; j >= 0; --j) {
		ll digit = b[j];
		// if(b[j] < ) printf("%d", b[j]);
	 	printf("%09lld", digit);
	}
}

void operator << (ostream& out, BigInt b) {
	/*
	b = Set(b);
	if(b.size() == 0) printf("%d", 0);
	for(ll j = b.size() - 1; j >= 0; --j) {
		ll digit = b[j];
		// printf("%d", digit);
		out << digit;
	}
	*/
	Print(b);
}

BigInt Fibo(int n, BigInt& t1, BigInt& t2) {
	if(n == 2) return t2;
	else if(n == 1) return t1;
	else return Fibo(n-1, t1, t2) * Fibo(n-1, t1, t2) + Fibo(n-2, t1, t2);
}
/*
int Fibo(int n, int t1, int t2) {
	if(n == 2) return t2;
	else if(n == 1) return t1;
	else return Fibo(n-1, t1, t2) * Fibo(n-1, t1, t2) + Fibo(n-2, t1, t2);
}
*/
int main() {
    int _a, _b, n;
    cin >> _a >> _b >> n;

    BigInt t1 = Convert(_a);
	BigInt t2 = Convert(_b);
	BigInt result = Fibo(n, t1, t2);
	// int answer = Fibo(n, _a, _b);
    cout << result;
	cout << endl;
    return 0;
}

