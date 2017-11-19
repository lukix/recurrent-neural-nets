#pragma once
class Callable {
public:
	Callable();
	virtual double call(double arg) = 0;
	~Callable();
};

