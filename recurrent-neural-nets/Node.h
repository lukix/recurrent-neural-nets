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
	void createConnectionWith(Node* nextNode);
	void clearInputVectors();
	std::vector<std::vector<double>> getLastOutput();
	static void connectInSequence(std::vector<Node*> nodes);
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();

	std::vector<Node*> prevNodes;
	std::vector<Node*> nextNodes;
	std::vector<std::vector<double>> inputVectors;
	std::vector<std::vector<double>> outputErrorsVectors;
	std::vector<std::vector<double>> lastOutput;
	std::stack<std::vector<std::vector<double>>> lastInputVectors;
	unsigned int inputStreamsNumber = 1;
	unsigned int outputStreamsNumber = 1;
	bool saveLastInputsVectors = false;
};