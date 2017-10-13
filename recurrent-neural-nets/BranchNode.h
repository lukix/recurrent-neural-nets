#pragma once
#include "Node.h"
class BranchNode :
	public Node {
public:
	BranchNode(unsigned int outputStreamsNumber);
	~BranchNode();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
};

