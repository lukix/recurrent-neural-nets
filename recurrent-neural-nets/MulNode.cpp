#include "stdafx.h"
#include "MulNode.h"


MulNode::MulNode() {
	this->inputStreamsNumber = 2;
	this->outputStreamsNumber = 1;
}


MulNode::~MulNode() {
}

std::vector<std::vector<double>> MulNode::processInputs() {
	std::vector<std::vector<double>> result;
	result.push_back(std::vector<double>());
	result[0].reserve(this->inputVectors[0].size());
	for (int i = 0; i < this->inputVectors[0].size(); i++) {
		result[0].push_back(this->inputVectors[0][i] * this->inputVectors[1][i]);
	}
	return result;
}

std::vector<std::vector<double>> MulNode::processOutputErrors() {
	std::vector<std::vector<double>> result;
	result.push_back(std::vector<double>());
	result.push_back(std::vector<double>());

	std::vector<double> lastInput0 = this->prevNodes[0]->getLastOutput()[0];
	std::vector<double> lastInput1 = this->prevNodes[1]->getLastOutput()[0];

	result[0].reserve(this->outputErrorsVectors[0].size());
	result[1].reserve(this->outputErrorsVectors[0].size());
	for (int i = 0; i < this->outputErrorsVectors[0].size(); i++) {
		result[0].push_back(this->outputErrorsVectors[0][i] * lastInput1[i]);
	}
	for (int i = 0; i < this->outputErrorsVectors[1].size(); i++) {
		result[1].push_back(this->outputErrorsVectors[1][i] * lastInput0[i]);
	}
	return result;
}
