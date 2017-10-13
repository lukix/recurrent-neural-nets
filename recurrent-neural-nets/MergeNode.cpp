#include "stdafx.h"
#include "MergeNode.h"


MergeNode::MergeNode(unsigned int inputStreamsNumber) {
	this->inputStreamsNumber = inputStreamsNumber;
}

MergeNode::~MergeNode() {
}

std::vector<std::vector<double>> MergeNode::processInputs() {
	this->lastInputSizes.clear();
	std::vector<double> result;
	for (int i = 0; i < this->inputStreamsNumber; i++) {
		result.insert(result.end(), this->inputVectors[i].begin(), this->inputVectors[i].end());
		this->lastInputSizes.push_back(this->inputVectors[i].size());
	}
	return { result };
}

std::vector<std::vector<double>> MergeNode::processOutputErrors() {
	std::vector<std::vector<double>> result;
	int index = 0;
	for (int i = 0; i < this->inputStreamsNumber; i++) {
		result.push_back(std::vector<double>(
			this->outputErrorsVectors[0].begin() + index,
			this->outputErrorsVectors[0].begin() + index + this->lastInputSizes[i]
		));
		index += this->lastInputSizes[i];
	}
	return result;
}