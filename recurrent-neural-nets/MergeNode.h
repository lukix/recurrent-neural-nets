#pragma once
#include "Node.h"
class MergeNode :
	public Node {
public:
	MergeNode(unsigned int inputStreamsNumber);
	~MergeNode();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
	std::vector<unsigned int> lastInputSizes;
};

