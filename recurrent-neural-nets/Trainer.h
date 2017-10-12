#pragma once
#include <vector>
#include <climits>
#include "Node.h"
#include "WeightedSumsNode.h"
struct DataRecord{
	std::vector<double> inputs;
	std::vector<double> outputs;
};
class Trainer {
public:
	Trainer(std::vector<DataRecord> dataset, double trainingDataSetSize = 0.7, double validationDataSetSize = 0.15, double testDataSetSize = 0.15);
	Trainer(std::vector<DataRecord> trainingDataSet, std::vector<DataRecord> validationDataSet, std::vector<DataRecord> testDataSet);
	~Trainer();
	void setInputNode(Node* inputNode);
	void setOutputNode(Node* outputNode);
	void setAdjustableNodes(std::vector<WeightedSumsNode*> adjustableNodes);
	void train(double learningRate, double maxError, unsigned int maxIterations = 0, bool(*validationCallback)(double) = NULL);
	double test();
protected:
	std::vector<DataRecord> trainingDataSet;
	std::vector<DataRecord> validationDataSet;
	std::vector<DataRecord> testDataSet;
	Node* inputNode;
	Node* outputNode;
	std::vector<WeightedSumsNode*> adjustableNodes;
};