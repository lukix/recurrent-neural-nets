#include "stdafx.h"
#include "ActivationNode.h"


ActivationNode::ActivationNode(Callable* activationFunc, Callable* activationFuncDerivative) {
	this->activationFunc = activationFunc;
	this->activationFuncDerivative = activationFuncDerivative;
}

ActivationNode::~ActivationNode() {
}

std::vector<std::vector<double>> ActivationNode::processInputs() {
	std::vector<std::vector<double>> result;
	result.push_back(std::vector<double>());
	result[0].reserve(this->inputVectors[0].size());
	for (int i = 0; i < this->inputVectors[0].size(); i++) {
		result[0].push_back(this->activationFunc->call(this->inputVectors[0][i]));
	}
	return result;
}

std::vector<std::vector<double>> ActivationNode::processOutputErrors() {
	std::vector<std::vector<double>> result;
	result.push_back(std::vector<double>());
	result[0].reserve(this->outputErrorsVectors[0].size());
	std::vector<double> lastInputVector = this->prevNodes[0]->getLastOutput()[0];
	for (int i = 0; i < this->outputErrorsVectors[0].size(); i++) {
		result[0].push_back(this->outputErrorsVectors[0][i] * this->activationFuncDerivative->call(lastInputVector[i]));
	}
	return result;
}
