#include "numerical_methods.hpp"
#include <cstdlib>
#include <stdexcept>

double BisectionMethod::find_root(
	double a, 
	double b, 
	double epsilon, 
	double(*f)(double)
) {
	if (epsilon <= 0) {
		throw std::invalid_argument("epsilon <= 0");
	}

	if (f(a) * f(b) > 0) {
		throw std::invalid_argument("f(a) * f(b) > 0");
	}

	double mid = a + (b - a) / 2;

	for (int i = 0; (i < 1000) && (b - a > epsilon); ++i) {
		double f_mid = f(mid);

		if (std::abs(f_mid) < epsilon) {
			return mid;
		}

		if (f(a) * f_mid > 0) {
			a = mid;
		}

		else {
			b = mid;
		}

		mid = a + (b - a) / 2;
	}

	return mid;
}

double SecantMethod::find_root(
	double a, 
	double b, 
	double epsilon, 
	double(*f)(double)
) {
	for (int i = 0; (i < 1000) && (std::abs(b - a) > epsilon); ++i) {
		a = a - (b - a) * f(a) / (f(b) - f(a));
		b = b - (a - b) * f(b) / (f(a) - f(b));
	}

	return b;
}

double NewtonMethod::find_root(
	double a, 
	double b, 
	double epsilon, 
	double(*f)(double)
) {
	auto df = [f, h = 1e-6](double x) -> double {
		return (f(x + h) - f(x - h)) / (2 * h);
	};

	a += (b - a) / 2;
	double x = a - f(a) / df(a);

	for (int i = 0; (i < 1000) && (std::abs(x - a) > epsilon); ++i) {
		a = x;
		x = a - f(a) / df(a);
	}

	return x;
}
