#include "../includes/test.hpp"

/*#include <ctime>
#include <fstream>
#define OFILE_NAME "times.txt"

class TimeLog
{
	public:
		TimeLog() : _currentTime(clock()), _newTime(0), _totalTime(0)
		{
			std::string	name;

			this->_outputFile.open(OFILE_NAME);
			{
				name = "====== FT TIMES: ======";
				this->_outputFile << name << std::endl;
			}
		}
		void	calculateTime(std::string testName)
		{
			this->_newTime = clock();
			this->_outputFile << testName << this->_newTime - this->_currentTime << std::endl;
			this->_totalTime += this->_newTime - this->_currentTime;
			this->_currentTime = this->_newTime;
			std::cout << std::endl << "==============================================" << std::endl;
		}
		void	totalTime()
		{
			this->_outputFile << "Total time elapsed: " << this->_totalTime << std::endl << std::endl;
		}

	private:
		clock_t			_currentTime;
		clock_t			_newTime;
		clock_t			_totalTime;
		std::ofstream	_outputFile;
};*/

template <typename T>
void printVector(T v) {
	typename T::iterator it;
	it = v.begin();
	while (it != v.end()) {
		std::cout << *it;
		if (it + 1 != v.end())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

static void printEnTete(std::string str) { std::cout << std::endl <<"*************** " << str << " ***************" << std::endl << std::endl; }

static void checkBool(std::string name, bool check) {
	if (check)
		std::cout << name << ": " <<  "✓"  << std::endl;
	else
		std::cout << name << ": " << "⨯" << std::endl;
}

void VectorConstructors() {
	printEnTete("Constructor / Copy Constructor");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(7);
	v1.push_back(5);
	v2.push_back(7);
	v2.push_back(5);
	checkBool("Constructor v1 == v2", v1 == v2);
	ft::vector<int> v3(v1);
	std::vector<int> v4(v2);
	checkBool("Copy Constructor v1 == v3", v1 == v3);
	checkBool("Copy Constructor v2 == v4", v2 == v4);
}

void VectorAccessOperator() {
	printEnTete("[] / at()");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(39);
	v1.push_back(76);
	v2.push_back(39);
	v2.push_back(76);
	check("v1[0] == v2[0]", v1[0], v2[0]);
	check("v1[1] == v2[1]", v1[1], v2[1]);
}

void VectorFrontBack() {
	printEnTete("Front / Back");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.push_back("zozo");
	v1.push_back("zaza");
	v2.push_back("zozo");
	v2.push_back("zaza");
	check("v1.front() == v2.front()", v1.front(), v2.front());
	check("v1.back() == v2.back()", v1.back(), v2.back());
}

void VectorMaxSize() {
	printEnTete("Max Size");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.push_back("42");
	v2.push_back("42");
	check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
}

void VectorResize() {
	printEnTete("Resize");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.resize(42, "voiture");
	v2.resize(42, "voiture");
	checkBool("v1 == v2", v1 == v2);
}

void VectorInsert() {
	printEnTete("Insert");
	int suite[] = {1, 2, 3};
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.insert(v1.begin(), 18);
	v2.insert(v2.begin(), 18);
	checkBool("v1 == v2", v1 == v2);
	v1.insert(v1.begin(), (size_t)5, 10);
	v2.insert(v2.begin(), (size_t)5, 10);
	checkBool("v1 == v2", v1 == v2);
	v1.insert(v1.begin(), suite, suite + 34);
	v2.insert(v2.begin(), suite, suite + 34);
	checkBool("v1 == v2", v1 == v2);
}

void VectorErase() {
	printEnTete("Erase / Clear");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.assign(5, 5);
	v2.assign(5, 5);
	v1.erase(v1.begin() + 2);
	v2.erase(v2.begin() + 2);
	checkBool("v1 == v2", v1 == v2);
	v1.erase(v1.begin());
	v2.erase(v2.begin());
	checkBool("v1 == v2", v1 == v2);
	v1.clear();
	v2.clear();
	checkBool("v1 == v2", v1 == v2);
}

void VectorAssign() {
	printEnTete("Assign");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(10, "oui");
	v2.assign(10, "oui");
	checkBool("v1 == v2", v1 == v2);
	std::string dico[] = {"mot", "clef", "dictionnaire"};
	v1.assign(dico, dico + 3);
	v2.assign(dico, dico + 3);
	checkBool("v1 == v2", v1 == v2);
}

void VectorSwap() {
	printEnTete("Swap");
	ft::vector<int> v1;
	std::vector<int> v2;
	ft::vector<int> v3;
	std::vector<int> v4;
	v1.push_back(166);
	v1.push_back(167);
	v2.push_back(166);
	v2.push_back(167);
	v3.push_back(422);
	v3.push_back(452);
	v4.push_back(422);
	v4.push_back(452);
	v1.swap(v3);
	v2.swap(v4);
	checkBool("v1 == v2", v1 == v2);
	checkBool("v3 == v4", v3 == v4);
}

void VectorOperators() {
	printEnTete("Operators");
	ft::vector<int> v1;
	std::vector<int> v2;
	ft::vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(1);
	v2.push_back(2);
	checkBool("v1 == v2", v1 == v2);
	check("v1 != v2", v1 != v3, v2 != v4);
	check("v1 > v2", v1 > v3, v2 > v4);
	check("v1 < v2", v1 < v3, v2 < v4);
	check("v1 >= v2", v1 >= v3, v2 >= v4);
	check("v1 <= v2", v1 <= v3, v2 <= v4);
}

void testVector() {

	printEnTete("Vector");
	VectorConstructors();
	VectorAccessOperator();
	VectorFrontBack();
	VectorMaxSize();
	VectorResize();
	VectorInsert();
	VectorErase();
	VectorAssign();
	VectorSwap();
	VectorOperators();
}
