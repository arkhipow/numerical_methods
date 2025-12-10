#include "pch.h"
#include "numerical_methods.hpp"
#include <cmath>

double f1(double x) { return x * x - 5; }
double f2(double x) { return std::sin(x); }
double f3(double x) { return x * x * x - 5 * x + 10; }

TEST(BisectionMethodTest, FindRootF1) {
    BisectionMethod method;
    double root = method.find_root(2.0, 3.0, 1e-6, f1);
    EXPECT_TRUE(std::abs(root - std::sqrt(5)) < 1e-6);
}

TEST(BisectionMethodTest, FindRootF2) {
    BisectionMethod method;
    double root = method.find_root(3.0, 3.2, 1e-6, f2);
    EXPECT_TRUE(std::abs(root - 3.141592653589793) < 1e-6);
}

TEST(SecantMethodTest, FindRootF1) {
    SecantMethod method;
    double root = method.find_root(2.0, 3.0, 1e-6, f1);
    EXPECT_TRUE(std::abs(root - std::sqrt(5)) < 1e-6);
}

TEST(SecantMethodTest, FindRootF2) {
    SecantMethod method;
    double root = method.find_root(3.0, 3.2, 1e-6, f2);
    EXPECT_TRUE(std::abs(root - 3.141592653589793) < 1e-6);
}

TEST(SecantMethodTest, FindRootF3) {
    SecantMethod method;
    double root = method.find_root(-3.0, -2.0, 1e-6, f3);
    EXPECT_TRUE(std::abs(f3(root)) < 1e-6);
}

TEST(NewtonMethodTest, FindRootF1) {
    NewtonMethod method;
    double root = method.find_root(2.0, 3.0, 1e-6, f1);
    EXPECT_TRUE(std::abs(root - std::sqrt(5)) < 1e-6);
}

TEST(NewtonMethodTest, FindRootF2) {
    NewtonMethod method;
    double root = method.find_root(3.0, 3.2, 1e-6, f2);
    EXPECT_TRUE(std::abs(root - 3.141592653589793) < 1e-6);
}

TEST(NewtonMethodTest, FindRootF3) {
    NewtonMethod method;
    double root = method.find_root(-3.0, -2.0, 1e-6, f3);
    EXPECT_TRUE(std::abs(f3(root)) < 1e-6);
}

TEST(NumericalMethodTest, SetMethod1) {
    NumericalMethod method;
    method.set_method(std::make_unique<BisectionMethod>());
    double root = method.find_root(2.0, 3.0, 1e-6, f1);
    EXPECT_TRUE(std::abs(root - std::sqrt(5)) < 1e-6);
}

TEST(NumericalMethodTest, SetMethod2) {
    NumericalMethod method;
    method.set_method(std::make_unique<SecantMethod>());
    double root = method.find_root(2.0, 3.0, 1e-6, f1);
    EXPECT_TRUE(std::abs(root - std::sqrt(5)) < 1e-6);
}
