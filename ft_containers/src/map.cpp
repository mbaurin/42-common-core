#include "../includes/test.hpp"
#include <map>

/*#include <ctime>
#include <fstream>
#define OFILE_NAME "times.txt"

class TimeLog
{
	public:
		TimeLog() : _currentTime(clock()), _newTime(0), _totalTime(0){
			std::string	name;

			this->_outputFile.open(OFILE_NAME);
			{
				name = "====== FT TIMES: ======";
				this->_outputFile << name << std::endl;
			}
		}
		void	calculateTime(std::string testName) {
			this->_newTime = clock();
			this->_outputFile << testName << this->_newTime - this->_currentTime << std::endl;
			this->_totalTime += this->_newTime - this->_currentTime;
			this->_currentTime = this->_newTime;
		}
		void	totalTime() { this->_outputFile << "Total time elapsed: " << this->_totalTime << std::endl << std::endl; }

	private:
		clock_t			_currentTime;
		clock_t			_newTime;
		clock_t			_totalTime;
		std::ofstream	_outputFile;
};*/

template <class T>
void printMap(T &map) {
	typename T::iterator it = map.begin();
	std::cout << " --- "<< std::endl;
	while (it != map.end()) {
		std::cout << it->first << ": " << it->second << std::endl;
		++it;
	}
	std::cout << " --- " << std::endl;
}

static void printEnTete(std::string str) { std::cout << std::endl <<"*************** " << str << " ***************" << std::endl << std::endl; };

static void checkBool(std::string name, bool check) {
	if (check)
		std::cout << name << ": " <<  "✓"  << std::endl;
	else
		std::cout << name << ": " << "⨯" << std::endl;
};

void MapConstructor() {
	printEnTete("Constructor / Copy Constructor");
	ft::map<int, int> m1;
	std::map<int, int> m2;
	checkBool("Constructor m1 == m2", m1 == m2);
	ft::map<int, int> m3(m1);
	std::map<int, int> m4(m2);
	checkBool("Copy Constructor m3 == m4", m1 == m2);
}

void MapMaxSize() {
	printEnTete("Max Size");
	ft::map<int, int> m1;
	std::map<int, int> m2;
	check("m1.max_size() == m2.max_size()", m1.max_size(), m2.max_size());
}

void MapAccessOperator() {
	printEnTete("[]");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 45;
	m1["b"] = 6;
	m1["indice"] = 12;
	m2["a"] = 45;
	m2["b"] = 6;
	m2["indice"] = 12;
	checkBool("m1[\"a\"] == m2[\"a\"]", m1["a"] == m2["a"]);
	checkBool("m1[\"b\"] == m2[\"b\"]", m1["b"] == m2["b"]);
	checkBool("m1[\"indice\"] == m2[\"indice\"]", m1["indice"] == m2["indice"]);
}

void MapInsert() {
	printEnTete("Insert");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1(a, a + 3);
	std::map<int, int> m2(a, a + 3);
	m1.insert(++m1.begin(), ft::make_pair(5, 5));
	m2.insert(++m2.begin(), std::make_pair(5, 5));
	checkBool("m1 == m2", m1 == m2);
	m1.insert(ft::make_pair(100, 1));
	m2.insert(std::make_pair(100, 1));
	checkBool("m1 == m2", m1 == m2);
}

void MapErase() {
	printEnTete("Erase / Clear");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["zouzou"] = 45;
	m1["a"] = 43;
	m1["b"] = 23;
	m1["c"] = 76;
	m2["zouzou"] = 45;
	m2["a"] = 43;
	m2["b"] = 23;
	m2["c"] = 76;
	m1.erase(m1.begin());
	m2.erase(m2.begin());
	checkBool("m1 == m2", m1 == m2);
	m1.erase("a");
	m2.erase("a");
	checkBool("m1 == m2", m1 == m2);
	m1.erase(m1.begin(), m1.end());
	m2.erase(m2.begin(), m2.end());
	checkBool("m1 == m2", m1 == m2);
	m1["zouzou"] = 45;
	m2["zouzou"] = 45;
	m1.clear();
	m2.clear();
	checkBool("m1 == m2", m1 == m2);
}

void MapSwap() {
	printEnTete("Swap");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m1["a"] = 100;
	m1["b"] = 200;
	m2["a"] = 100;
	m2["b"] = 200;
	m3["a"] = 42;
	m4["a"] = 42;
	m1.swap(m3);
	m2.swap(m4);
	checkBool("m1 == m2", m1 == m2);
	checkBool("m3 == m4", m3 == m4);
}

void MapFind() {
	printEnTete("Find");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 667;
	m1["b"] = 42;
	m2["a"] = 667;
	m2["b"] = 42;
	check("m1.find(\"a\") == m2.find(\"a\")", m1.find("a")->second, m2.find("a")->second);
}

void MapCount() {
	printEnTete("Count");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 77;
	m1["b"] = 21;
	m2["a"] = 77;
	m2["b"] = 21;
	check("m1.count(\"a\") == m2.count(\"a\")", m1.count("a"), m2.count("a"));
}

void MapBounds() {
	printEnTete("Bounds");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 420;
	m1["c"] = 420;
	m1["d"] = 420;
	m2["a"] = 1;
	m2["b"] = 420;
	m2["c"] = 420;
	m2["d"] = 420;
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("a")->first, m2.lower_bound("a")->first);
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("c")->first, m2.lower_bound("c")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("a")->first, m2.upper_bound("a")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("c")->first, m2.upper_bound("c")->first);
}

void MapRange() {
	printEnTete("Equal Range");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 10;
	m1["b"] = 21;
	m1["c"] = 22;
	m1["d"] = 23;
	m2["a"] = 10;
	m2["b"] = 21;
	m2["c"] = 22;
	m2["d"] = 23;
	ft::pair<ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> a = m1.equal_range("a");
	std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> b = m2.equal_range("a");
	check("a.first->first == b.first->first", a.first->first, b.first->first);
	check("a.first->second == b.first->second", a.first->second, b.first->second);
	check("a.second->first == b.second->first", a.second->first, b.second->first);
	check("a.second->second == b.second->second", a.second->second, b.second->second);
}

void MapOperators() {
	printEnTete("Operators");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 10;
	m1["b"] = 21;
	m1["c"] = 22;
	m1["d"] = 23;
	m2["a"] = 10;
	m2["b"] = 21;
	m2["c"] = 22;
	m2["d"] = 23;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m3 = m1;
	m4 = m2;
	checkBool("m1 == m2", m1 == m2);
	check("m1 != m2", m1 != m3, m2 != m4);
	check("m1 > m2", m1 > m3, m2 > m4);
	check("m1 < m2", m1 < m3, m2 < m4);
	check("m1 >= m2", m1 >= m3, m2 >= m4);
	check("m1 <= m2", m1 <= m3, m2 <= m4);
}

// void testFt() {
// 	ft::map<std::string, int> m1;
// }

// void testStd() {
// 	std::map<std::string, int> m1;
// }

void testMap() {
	printEnTete("Map");
	MapConstructor();
	MapMaxSize();
	MapAccessOperator();
	MapInsert();
	MapErase();
	MapSwap();
	MapFind();
	MapCount();
	MapBounds();
	MapRange();
	MapOperators();
}
