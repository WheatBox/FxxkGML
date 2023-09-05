#include "math.h"

namespace fgm {
	
	double degtorad(double deg) {
		return deg * DEG2RAD_RATIO;
	}

	double radtodeg(double rad) {
		return rad * RAD2DEG_RATIO;
	}

}
