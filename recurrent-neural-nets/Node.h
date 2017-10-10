#pragma once
#include <vector>
#include <stack>
class Node {
public:
	Node();
	~Node();
	void propagate(std::vector<double> inputValues);
	void backpropagate(std::vector<double> outputErrors);
	void connectOutput(Node* nextNode);
	void connectInput(Node* prevNode);
	std::vector<std::vector<double>> getLastOutput();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();

	std::vector<Node*> prevNodes;
	std::vector<Node*> nextNodes;
	std::vector<std::vector<double>> inputVectors;
	std::vector<std::vector<double>> outputErrorsVectors;
	std::stack<std::vector<std::vector<double>>> outputVectorsHistory;
	unsigned int inputStreamsNumber = 1;
	unsigned int outputStreamsNumber = 1;
};

