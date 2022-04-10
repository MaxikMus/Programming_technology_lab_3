#ifndef APROG_H
#define APROG_H

#include "sum.h"

class AP : public Sum {
public:
	AP ();
	AP(const double& init, const double& diff);
	~AP ();

	double sumProg(unsigned int count) override;

	double getInit();
	double getDiff();
	unsigned int getCount();
	void setInit(double init);
	void setDiff(double diff);

private:
	static unsigned int count_;
	double init_, diff_;
};


#endif // !APROG_H