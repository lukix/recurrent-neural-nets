#include "stdafx.h"
#include "Trainer.h"
#include <iostream>


Trainer::Trainer(std::vector<DataRecord> dataSet, double trainingDataSetSize, double validationDataSetSize, double testDataSetSize) {
	int sizesSum = trainingDataSetSize + validationDataSetSize + testDataSetSize;
	int size = dataSet.size();
	this->trainingDataSet = std::vector<DataRecord>(dataSet.begin(), dataSet.begin() + size * trainingDataSetSize / sizesSum);
	this->validationDataSet = std::vector<DataRecord>(dataSet.begin() + size * trainingDataSetSize / sizesSum, dataSet.begin() + size * (trainingDataSetSize + validationDataSetSize) / sizesSum);
	this->testDataSet = std::vector<DataRecord>(dataSet.begin() + size * (trainingDataSetSize + validationDataSetSize) / sizesSum, dataSet.end());
}

Trainer::Trainer(std::vector<DataRecord> trainingDataSet, std::vector<DataRecord> validationDataSet, std::vector<DataRecord> testDataSet) {
	this->trainingDataSet = trainingDataSet;
	this->validationDataSet = validationDataSet;
	this->testDataSet = testDataSet;
}

Trainer::~Trainer() {
}

void Trainer::setInputNode(Node* inputNode) {
	this->inputNode = inputNode;
}

void Trainer::setOutputNode(Node* outputNode) {
	this->outputNode = outputNode;
}

void Trainer::setAdjustableNodes(std::vector<WeightedSumsNode*> adjustableNodes) {
	this->adjustableNodes = adjustableNodes;
}

void Trainer::train(double learningRate, double maxError, unsigned int maxIterations, bool(*validationCallback)(double)) {
	if (maxIterations < 0) {
		maxIterations = UINT_MAX;
	}
	for (int i = 0; i < maxIterations; i++) {
		//Training
		for (int j = 0; j < this->trainingDataSet.size(); j++) {
			this->inputNode->propagate(this->trainingDataSet[j].inputs, true);
			std::vector<double> result = this->outputNode->getLastOutput()[0];
			std::vector<double> errors;
			for (int k = 0; k < result.size(); k++) {
				errors.push_back(result[k]  - this->trainingDataSet[j].outputs[k]);
			}
			this->outputNode->backpropagate(errors);
			for (WeightedSumsNode* layer : this->adjustableNodes) {
				layer->adjustWeights(learningRate);
			}
		}

		//Validation
		double validationError = 0.0;
		for (int j = 0; j < this->validationDataSet.size(); j++) {
			this->inputNode->propagate(this->validationDataSet[j].inputs);
			std::vector<double> result = this->outputNode->getLastOutput()[0];
			double meanSquareError = 0.0;
			for (int k = 0; k < result.size(); k++) {
				meanSquareError += pow(result[k] - this->validationDataSet[j].outputs[k], 2);
			}
			validationError += meanSquareError;
		}
		validationError /= 2 * this->validationDataSet.size();
		if (!validationCallback(validationError)) {
			break;
		}
		if (validationError <= maxError) {
			break;
		}
	}
}
double Trainer::test() {
	double testError = 0.0;
	for (int j = 0; j < this->testDataSet.size(); j++) {
		this->inputNode->propagate(this->testDataSet[j].inputs);
		std::vector<double> result = this->outputNode->getLastOutput()[0];
		double meanSquareError = 0.0;
		for (int k = 0; k < result.size(); k++) {
			meanSquareError += pow(result[k] - this->testDataSet[j].outputs[k], 2);
		}
		testError += meanSquareError;
	}
	testError /= 2 * this->testDataSet.size();
	return testError;
}
