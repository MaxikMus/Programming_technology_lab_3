#ifndef GPROG_H
#define GPROG_H

#include "sum.h"

class GP : public Sum {
public:
	GP ();
	~GP ();

	double sumProg(unsigned int count) override;

	double getInit();
	double getRatio();
	unsigned int getCount();
	void setInit(double init);
	void setRatio(double ratio);

private:
	static unsigned int count_;
	double init_, ratio_;
};

#endif // !GPROG