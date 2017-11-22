#pragma once
#include "Node.h"
#include <stack>
class WeightedSumsNode :
	public Node {
public:
	WeightedSumsNode(int inputsCount, int outputsCount);
	~WeightedSumsNode();
	void clearWeightsErrors();
	void adjustWeights(double learningRate);
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
	std::vector<std::vector<double>> weights;	//[outputsCount][inputsCount]	//List of outputs. Each output is a list of weights of connections to each input
	std::vector<std::vector<double>> weightsErrors;
	std::stack<std::vector<double>> lastInputVectors;
};

