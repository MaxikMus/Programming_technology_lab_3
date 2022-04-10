#include "aprog.h"

unsigned int AP::count_ = 0;

unsigned int AP::getCount() {
	return count_;
}

AP::AP() {
	init_ = 0;
	diff_ = 0;
	count_++;
}

AP::AP(const double& init, const double& diff) {
	init_ = init;
	diff_ = diff;
	count_++;
}


AP ::~AP() {
	count_--;
}


void AP::setInit(double init) {
	init_ = init;
}

void AP::setDiff(double diff) {
	diff_ = diff;
}


double AP::getInit() {
	return init_;
}

double AP::getDiff() {
	return diff_;
}



double AP::sumProg(unsigned int count) {
	return ((double)count / 2 * (2 * init_ + (count - 1) * diff_));
}