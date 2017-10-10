#include "stdafx.h"
#include "Node.h"
#include <iostream>


Node::Node() {
	this->inputVectors.reserve(this->inputStreamsNumber);
	this->outputErrorsVectors.reserve(this->outputStreamsNumber);
	std::cout << "Node()" << std::endl;
}

Node::~Node() {
	
}

void Node::propagate(std::vector<double> inputValues) {
	this->inputVectors.push_back(inputValues);
	if (this->inputVectors.size() == this->inputStreamsNumber) {
		std::vector<std::vector<double>> resultVectors = this->processInputs();
		for (int i = 0; i < this->nextNodes.size(); i++) {
			this->nextNodes[i]->propagate(resultVectors[i]);
		}
		this->inputVectors.clear();
	}
}

void Node::backpropagate(std::vector<double> outputErrors) {
	this->outputErrorsVectors.push_back(outputErrors);
	if (outputErrors.size() == this->outputStreamsNumber) {
		std::vector<std::vector<double>> resultVectors = this->processOutputErrors();
		for (int i = 0; i < this->prevNodes.size(); i++) {
			this->prevNodes[i]->backpropagate(resultVectors[i]);
		}
		this->outputErrorsVectors.clear();
	}
}

void Node::connectOutput(Node * nextNode) {
	if (this->nextNodes.size() == this->outputStreamsNumber) {
		throw std::exception("Trying to connect too many output nodes");
	}
	this->nextNodes.push_back(nextNode);
}

void Node::connectInput(Node * prevNode) {
	
	if (this->prevNodes.size() == this->inputStreamsNumber) {
		throw std::exception("Trying to connect too many input nodes");
	}
	this->prevNodes.push_back(prevNode);
}

std::vector<std::vector<double>> Node::processInputs() {
	return this->inputVectors;
}

std::vector<std::vector<double>> Node::processOutputErrors() {
	return this->outputErrorsVectors;
}
