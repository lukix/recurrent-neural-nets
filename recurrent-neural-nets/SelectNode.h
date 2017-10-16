#pragma once
#include "Node.h"
class SelectNode :
	public Node {
public:
	SelectNode(std::vector<bool> mask);
	~SelectNode();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
	std::vector<bool> mask;
};