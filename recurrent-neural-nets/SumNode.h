#pragma once
#include "Node.h"
class SumNode :
	public Node {
public:
	SumNode(unsigned int inputStreamsNumber = 2);
	~SumNode();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
};

