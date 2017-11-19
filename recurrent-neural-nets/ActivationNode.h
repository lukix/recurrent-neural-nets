#pragma once
#include "Node.h"
#include "Callable.h"
class ActivationNode :
	public Node {
public:
	ActivationNode(Callable* activationFunc, Callable* activationFuncDerivative);
	~ActivationNode();
protected:
	virtual std::vector<std::vector<double>> processInputs();
	virtual std::vector<std::vector<double>> processOutputErrors();
	Callable* activationFunc;
	Callable* activationFuncDerivative;
};

