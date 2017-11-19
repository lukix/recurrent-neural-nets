#pragma once
#include "Callable.h"

namespace ActivationFunctions {

	class Sigmoid : public Callable {
	public:
		Sigmoid(double beta = 1.0) : beta(beta) {};
		double beta;
		double call(double x) {
			return 1.0 / (1.0 + exp(-this->beta * x));
		};
	};
	class SigmoidDerivative : public Callable {
	public:
		SigmoidDerivative(double beta = 1.0) : beta(beta) {};
		double beta;
		double call(double x) {
			double f = 1.0 / (1.0 + exp(-this->beta * x));
			return f * (1.0 - f);
		};
	};

	class ReLU : public Callable {
	public:
		ReLU(double slope = 1.0, double leakage = 0.0) : slope(slope), leakage(leakage) {};
		double slope;
		double leakage;
		double call(double x) {
			return x > 0.0 ? this->slope * x : this->leakage * x;
		};
	};
	class ReLUDerivative : public Callable {
	public:
		ReLUDerivative(double slope = 1.0, double leakage = 0.0) : slope(slope), leakage(leakage) {};
		double slope;
		double leakage;
		double call(double x) {
			return x > 0.0 ? this->slope : this->leakage;
		};
	};

	class hyperbolicTangent : public Callable {
	public:
		hyperbolicTangent() {};
		double call(double x) {
			return sinh(x) / cosh(x);
		};
	};
	class hyperbolicTangentDerivative : public Callable {
	public:
		hyperbolicTangentDerivative() {};
		double call(double x) {
			return 1.0 - pow(sinh(x) / cosh(x), 2);
		};
	};

}

