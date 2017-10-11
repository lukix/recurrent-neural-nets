#include "stdafx.h"
#include "ActivationNode.h"


ActivationNode::ActivationNode(double (*activationFunc)(double), double(*activationFuncDerivative)(double)) {
	this->activationFunc = activationFunc;
	this->activationFuncDerivative = activationFuncDerivative;
}

ActivationNode::~ActivationNode() {
}

double ActivationNode::sigmoid(double x) {
	double beta = 1.0;
	return 1.0 / (1.0 + exp(-beta * x));
}

double ActivationNode::sigmoidDerivative(double x) {
	double beta = 1.0;
	double f = 1.0 / (1.0 + exp(-beta * x));
	return f * (1.0 - f);
}

double ActivationNode::hyperbolicTangent(double x) {
	return sinh(x) / cosh(x);
}

double ActivationNode::hyperbolicTangentDerivative(double x) {
	return 1.0 - pow(sinh(x) / cosh(x), 2);
}

std::vector<std::vector<double>> ActivationNode::processInputs() {
	std::vector<std::vector<double>> result;
	result.push_back(std::vector<double>());
	result[0].reserve(this->inputVectors[0].size());
	for (int i = 0; i < this->inputVectors[0].size(); i++) {
		result[0].push_back(this->activationFunc(this->inputVectors[0][i]));
	}
	return result;
}

std::vector<std::vector<double>> ActivationNode::processOutputErrors() {
	std::vector<std::vector<double>> result;
	result.push_back(std::vector<double>());
	result[0].reserve(this->outputErrorsVectors[0].size());
	std::vector<double> lastInputVector = this->prevNodes[0]->getLastOutput()[0];
	for (int i = 0; i < this->outputErrorsVectors[0].size(); i++) {
		result[0].push_back(this->outputErrorsVectors[0][i] * this->activationFuncDerivative(lastInputVector[i]));
	}
	return result;
}
