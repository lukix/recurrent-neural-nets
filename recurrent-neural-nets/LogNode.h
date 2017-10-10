#pragma once
#include "Node.h"
class LogNode :
	public Node {
public:
	LogNode();
	~LogNode();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
	virtual void logVector(std::vector<double> vec);
};

