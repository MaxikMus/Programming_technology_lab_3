#include "gprog.h"
#include <cmath>

unsigned int GP::count_ = 0;

GP::GP() {
	init_ = 0;
	ratio_ = 0;
	count_++;
}

GP ::~GP() {
	count_--;
}


void GP::setInit(double init) {
	init_ = init;
}

void GP::setRatio(double ratio) {
	ratio_ = ratio;
}

unsigned int GP::getCount() {
	return count_;
}

double GP::getInit() {
	return init_;
}

double GP::getRatio() {
	return ratio_;
}

double GP::sumProg(unsigned int count) {
	return ((init_*(pow(ratio_, count) - 1)) / (ratio_ - 1));
}