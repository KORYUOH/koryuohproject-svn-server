#include "Dice.h"

#include <algorithm>

Dice::Dice():
mEngine(std::random_device()),
	mDistribution(1,6),
	mData(1)
{}


Dice::Dice(int num,int surface):
	mEngine(std::random_device()),
	mDistribution(1,surface),
	mData(num)
{}


int Dice::generate(){
	return mDistribution(mEngine);
}

int Dice::roll(){
	std::for_each(mData.begin(),mData.end(),[&](int& elem){ return elem = generate();});
	int sum=0;
	std::for_each(mData.begin(),mData.end(),[&](const int elem){return sum+=elem;});
	return sum;
}

int Dice::roll(std::ostream& ost){
	int res = roll();
	std::for_each(
		mData.begin(),
		mData.end(),
		[&](int elem){ost<<"["<<elem<<"]";});

	ost << "\t" << "SUM["<<res<<"]";
	return res;
}
int Dice::roll(int num,int surface){
	int result = 0;
	std::uniform_int_distribution<int> dist(1,surface);
	for(int i=0;i<num;i++)
		result+=dist(mEngine);
	return result;
}


void Dice::setDice(int num,int surface){
	mDistribution = std::uniform_int_distribution<int>(1,surface);
	mData = rollData_t(num);
}


Dice::rollData_t Dice::getRollData()const{
	return mData;
}




