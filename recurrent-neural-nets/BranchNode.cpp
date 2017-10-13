#include "stdafx.h"
#include "BranchNode.h"


BranchNode::BranchNode(unsigned int outputStreamsNumber) {
	this->outputStreamsNumber = outputStreamsNumber;
}

BranchNode::~BranchNode() {
}

std::vector<std::vector<double>> BranchNode::processInputs() {
	std::vector<std::vector<double>> result;
	for (int i = 0; i < outputStreamsNumber; i++) {
		result.push_back(this->inputVectors[0]);
	}
	return result;
}

std::vector<std::vector<double>> BranchNode::processOutputErrors() {
	std::vector<double> result = this->outputErrorsVectors[0];
	for (int i = 1; i < outputStreamsNumber; i++) {
		for (int j = 0; j < this->outputErrorsVectors[i].size(); j++) {
			result[j] += this->outputErrorsVectors[i][j];
		}
	}
	return { result };
}
