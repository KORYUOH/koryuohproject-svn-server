#ifndef _DICE_H_
#define _DICE_H_

#include <random>
#include <vector>

namespace std{
	template<typename _Ty>
	class  basic_ostream<_Ty>;
}

class Dice{
public:
	typedef std::vector<int> rollData_t;
	Dice();
	Dice(int num,int surface);
	virtual ~Dice(){}
	
	int roll();
	int roll(std::ostream& ost);
	int roll(int num,int surface);
	rollData_t getRollData()const;
	void setDice(int num,int surface);
private:
	int generate();
private:
	std::mt19937 mEngine;
	std::uniform_int_distribution<int> mDistribution;
	rollData_t mData;
};
#endif
