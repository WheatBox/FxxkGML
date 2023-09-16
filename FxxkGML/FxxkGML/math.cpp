#include "math.h"

#include <random>

namespace fgm {
	
	double degtorad(double deg) {
		return deg * DEG2RAD_RATIO;
	}

	double radtodeg(double rad) {
		return rad * RAD2DEG_RATIO;
	}

	std::mt19937 __randomer;

	void randomize() {
		__randomer.seed(time(NULL));
	}

	void randomise() {
		__randomer.seed(time(NULL));
	}

	double random_range(double n1, double n2) {
		long long tmpn1 = n1 * 1e6;
		long long tmpn2 = n2 * 1e6;
		long long tmp = __randomer() * 1e6;
		return (tmp % (tmpn2 - tmpn1 + 1) + tmpn1) / 1e6;
	}

}
