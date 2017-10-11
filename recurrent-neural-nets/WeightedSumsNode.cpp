#include "stdafx.h"
#include "WeightedSumsNode.h"


WeightedSumsNode::WeightedSumsNode(int inputsCount, int outputsCount) {
	this->weights.resize(outputsCount);
	this->weightsErrors.resize(outputsCount);
	for (int i = 0; i < outputsCount; i++) {
		this->weights[i].reserve(inputsCount + 1);	//+1 because of a bias neuron
		this->weightsErrors[i].reserve(inputsCount + 1);	//+1 because of a bias neuron
		for (int j = 0; j < inputsCount + 1; j++) {
			double r = ((double)rand() / (double)(RAND_MAX + 1)) * 2.0 - 1.0;	//random number between -1 and 1
			this->weights[i].push_back(r);
			this->weightsErrors[i].push_back(0.0);
		}
	}
}


WeightedSumsNode::~WeightedSumsNode() {
}

void WeightedSumsNode::clearWeightsErrors() {
	for (int i = 0; i < this->weightsErrors.size(); i++) {
		for (int j = 0; j < this->weightsErrors[i].size(); j++) {
			this->weightsErrors[i][j] = 0.0;
		}
	}
}

std::vector<std::vector<double>> WeightedSumsNode::processInputs() {
	std::vector<std::vector<double>> result;
	result.push_back(std::vector<double>());	//One output vector

	result[0].reserve(this->weights.size());	//Size of output vector
	for (int i = 0; i < this->weights.size(); i++) {
		double outputValue = this->weights[i][0] * 1.0;	//bias neuron
		for (int j = 1; j < this->weights[i].size(); j++) {
			outputValue += this->weights[i][j] * this->inputVectors[0][j - 1];
		}
		result[0].push_back(outputValue);
	}
	return result;
}

std::vector<std::vector<double>> WeightedSumsNode::processOutputErrors() {
	std::vector<std::vector<double>> result;
	result.push_back(std::vector<double>());

	//Calculate weights errors
	std::vector<double> lastInputVector = this->prevNodes[0]->getLastOutput()[0];
	for (int i = 0; i < this->weightsErrors.size(); i++) {
		this->weightsErrors[i][0] += this->outputErrorsVectors[0][i] * 1.0;	//Weights connected to bias neuron
		for (int j = 1; j < this->weightsErrors[i].size(); j++) {
			this->weightsErrors[i][j] += this->outputErrorsVectors[0][i] * lastInputVector[j - 1];
		}
	}

	//Create data to return
	result[0].reserve(this->weights[0].size() - 1);	//Number of inputs excluding bias neuron
	for (int j = 0; j < this->weights[0].size(); j++) {
		double value = 0.0;
		for (int i = 0; i < this->weights.size(); i++) {
			value += this->outputErrorsVectors[0][i] * this->weights[i][j];
		}
		result[0].push_back(value);
	}
	return result;
}
