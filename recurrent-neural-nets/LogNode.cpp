#include "stdafx.h"
#include "LogNode.h"
#include <iostream>

LogNode::LogNode() {

}


LogNode::~LogNode() {

}

std::vector<std::vector<double>> LogNode::processInputs() {
	std::vector<std::vector<double>> result = Node::processInputs();
	std::cout << "LogNode vector (propagation):" << std::endl;
	this->logVector(result[0]);
	return result;
}

std::vector<std::vector<double>> LogNode::processOutputErrors() {
	std::vector<std::vector<double>> result = Node::processOutputErrors();
	std::cout << "LogNode vector (backpropagation):" << std::endl;
	this->logVector(result[0]);
	return result;
}

void LogNode::logVector(std::vector<double> vec) {
	for (double val : vec) {
		std::cout << val << std::endl;
	}
}
