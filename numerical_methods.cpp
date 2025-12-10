#include "numerical_methods.hpp"
#include <cstdlib>
#include <limits>

double BisectionMethod::find_root(double a, double b, double epsilon, double (*f)(double)) {
	double mid = a + (b - a) / 2;

	while (b - a > epsilon) {
		if (f(a) * f(mid) > 0) {
			a = mid;
		}

		else {
			b = mid;
		}

		mid = a + (b - a) / 2;
	}

	return mid;
}

double SecantMethod::find_root(double a, double b, double epsilon, double (*f)(double)) {
	while (std::abs(b - a) > epsilon) {
		a = a - (b - a) * f(a) / (f(b) - f(a));
		b = b - (a - b) * f(b) / (f(a) - f(b));
	}

	return b;
}

double NewtonMethod::find_root(double a, double b, double epsilon, double (*f)(double)) {
	auto df = [f, h = std::numeric_limits<double>::epsilon()](double x) {
		return (f(x + h) - f(x - h)) / (2 * h);
	};

	a += (b - a) / 2;
	double x = a - f(a) / df(a);

	while (std::abs(x - a) > epsilon) {
		a = x;
		x = a - f(a) / df(a);
	}

	return x;
}
