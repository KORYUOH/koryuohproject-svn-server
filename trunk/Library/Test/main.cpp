#include	"../Lib/KORYUOH_LIB.h"
#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>
#include	<functional>
class BOX{
private:
	std::string mName;
public:
	BOX(const std::string& name):mName(name){
	}
	void print()const{
		std::cout<<mName<<std::endl;
	}
};
//template <typename T_container, typename T_function>
//T_function for_each(T_container& rcontainer, T_function function) {
//    return for_each(rcontainer.begin(), rcontainer.end(), function);
//}
void main(){
	using namespace std;
	vector<BOX> box;
	box.push_back(BOX("承太郎"));
	box.push_back(BOX("花京院"));
	box.push_back(BOX("ジョセフ"));
	box.push_back(BOX("アヴドゥル"));
	box.push_back(BOX("ポルナレフ"));
	cout << "std::for_each" << endl;
	std::for_each(box.begin(),box.end(),[&](BOX& p){p.print();});
	cout <<"Tool::for_each"<< endl<<endl;
	Tools::for_each(box,mem_fun_ref(&BOX::print));
	//for_each(box,mem_fun_ref(&BOX::print));

}