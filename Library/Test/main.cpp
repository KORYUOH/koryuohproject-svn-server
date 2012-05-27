//#include	"../Lib/KORYUOH_LIB.h"
#include	"../Lib/Dice.h"
#ifdef _DEBUG
#pragma comment(lib,"../Lib/Dice_d.lib")
#else
#pragma comment(lib,"../Lib/Dice_r.lib")
#endif
#include	<iostream>
#include	<vector>
#include	<string>
#include	<cstdlib>
#include	<algorithm>
class Tools{
public:
	template<typename Vec,typename Func>
	static Func for_each(Vec& v,Func fn){
		return std::for_each(v.begin(),v.end(),fn);
	}
};

void main(){
	using namespace std;
	string tmp;
	Dice d;
	cin >> tmp;
	cin.sync();
	string xd = tmp.substr(0,tmp.find("d"));
	string dy = tmp.substr(xd.size()+1);
	string ps = tmp.substr(tmp.find("+"));
	int x = atoi(xd.c_str());
	int y = atoi(dy.c_str());
	int s = atoi(ps.c_str());;
	cout << xd<<endl;
	cout << dy << endl;
	cout << ps <<endl;
	cout << x << ","<<y<<","<<s<<endl;
	cout << d.XdY_S(x,y,s);

	system("pause");


}