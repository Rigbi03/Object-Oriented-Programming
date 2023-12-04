#pragma once

class Figure
{
public:
	
	const char* getType() const;
	virtual double getPerimeter() const = 0;
	virtual double getSurfaceArea() const = 0;
	virtual bool isIn(double, double) const = 0;
private:

};

