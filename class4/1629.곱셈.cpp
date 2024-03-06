#include <iostream>

int fast_pow(long long a, long long b, long long c)
{
	long long ret = 1;
	a %= c;
	while (b > 0) {
		if (b % 2 == 1) {
			ret = (ret * a) % c;
		}
		a = (a * a) % c;
		b /= 2;
	}
	return ret;
}

int main()
{
	int a, b, c; std::cin >> a >> b >> c;
	std::cout << fast_pow(a, b, c);
}