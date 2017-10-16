#include "stdafx.h"
#include "SelectNode.h"


SelectNode::SelectNode(std::vector<bool> mask) {
	this->mask = mask;
}

SelectNode::~SelectNode() {
}

std::vector<std::vector<double>> SelectNode::processInputs() {
	std::vector<double> result;
	for (int i = 0; i < this->mask.size(); i++) {
		if (this->mask[i]) {
			result.push_back(this->inputVectors[0][i]);
		}
	}
	return { result };
}

std::vector<std::vector<double>> SelectNode::processOutputErrors() {
	std::vector<double> result;
	int index = 0;
	for (int i = 0; i < this->mask.size(); i++) {
		if (this->mask[i]) {
			result.push_back(this->inputVectors[0][index]);
			index++;
		} else {
			result.push_back(0.0);
		}
	}

	return { result };
}
