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
	//TODO
	throw std::exception("Method is not implemented");
	return std::vector<std::vector<double>>();
}
