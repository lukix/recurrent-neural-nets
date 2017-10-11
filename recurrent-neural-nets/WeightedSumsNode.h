#pragma once
#include "Node.h"
class WeightedSumsNode :
	public Node {
public:
	WeightedSumsNode(int inputsCount, int outputsCount);
	~WeightedSumsNode();
	void clearWeightsErrors();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
	std::vector<std::vector<double>> weights;	//[outputsCount][inputsCount]	//List of outputs. Each output is a list of weights of connections to each input
	std::vector<std::vector<double>> weightsErrors;
};

