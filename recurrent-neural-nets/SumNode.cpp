#include "stdafx.h"
#include "SumNode.h"


SumNode::SumNode(unsigned int inputStreamsNumber) {
	this->inputStreamsNumber = inputStreamsNumber;
}


SumNode::~SumNode() {
}

std::vector<std::vector<double>> SumNode::processInputs() {
	std::vector<double> result = this->inputVectors[0];
	for (int i = 1; i < inputStreamsNumber; i++) {
		for (int j = 0; j < this->inputVectors[i].size(); j++) {
			result[j] += this->inputVectors[i][j];
		}
	}
	return { result };
}

std::vector<std::vector<double>> SumNode::processOutputErrors() {
	std::vector<std::vector<double>> result;
	for (int i = 0; i < inputStreamsNumber; i++) {
		result.push_back(this->outputErrorsVectors[0]);
	}
	return result;
}
