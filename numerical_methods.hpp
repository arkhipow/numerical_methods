#include <memory>
#include <utility>

class INumericalMethod {
public:
	virtual ~INumericalMethod() = default;

	virtual double find_root(double a, double b, double epsilon, double (*f)(double)) = 0;
};

class BisectionMethod : public INumericalMethod {
public:
	double find_root(double a, double b, double epsilon, double (*f)(double)) override;
};

class SecantMethod : public INumericalMethod {
public:
	double find_root(double a, double b, double epsilon, double (*f)(double)) override;
};

class NewtonMethod : public INumericalMethod {
public:
	double find_root(double a, double b, double epsilon, double (*f)(double)) override;
};

class NumericalMethod {
private:
	std::unique_ptr<INumericalMethod> _method;

public:
	void set_method(std::unique_ptr<INumericalMethod> method) {
		_method = std::move(method);
		method = nullptr;
	}

	double find_root(double a, double b, double epsilon, double (*f)(double)) {
		return _method->find_root(a, b, epsilon, f);
	}
};
