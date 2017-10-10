#pragma once
#include "Node.h"
class MulNode :
	public Node {
public:
	MulNode();
	~MulNode();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
};

