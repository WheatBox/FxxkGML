#include "math.h"

#include <random>

namespace fgm {
	
	double degtorad(double deg) {
		return deg * DEG2RAD_RATIO;
	}

	double radtodeg(double rad) {
		return rad * RAD2DEG_RATIO;
	}

	int __randomer_seed = 0;
	std::mt19937 __randomer(__randomer_seed);

	void randomize() {
		__randomer_seed = time(NULL);
		__randomer.seed(__randomer_seed);
	}

	void randomise() {
		__randomer_seed = time(NULL);
		__randomer.seed(__randomer_seed);
	}

	double random(double n) {
		return __randomer() % (static_cast<int>(n) + 1)
			+ (__randomer() % 10000000) / 1e6;
	}

	double random_range(double n1, double n2) {
		long long tmpn1 = n1 * 1e6;
		long long tmpn2 = n2 * 1e6;
		long long tmp = __randomer() * 1e6;
		return (tmp % (tmpn2 - tmpn1 + 1) + tmpn1) / 1e6;
	}

	int irandom(int n) {
		return __randomer() % (n + 1);
	}

	int irandom_range(int n1, int n2) {
		return __randomer() % (n2 - n1 + 1) + n1;
	}
	
	void random_set_seed(int val) {
		__randomer_seed = val;
		__randomer.seed(val);
	}
	
	int random_get_seed() {
		return __randomer_seed;
	}

}
