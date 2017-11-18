#pragma once
#include "Node.h"
class ActivationNode :
	public Node {
public:
	ActivationNode(double (*activationFunc)(double), double(*activationFuncDerivative)(double));
	~ActivationNode();
	static double sigmoid(double x);
	static double sigmoidDerivative(double x);
	static double hyperbolicTangent(double x);
	static double hyperbolicTangentDerivative(double x);
	static double relu(double x);
	static double reluDerivative(double x);
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
	double(*activationFunc)(double);
	double(*activationFuncDerivative)(double);
};

