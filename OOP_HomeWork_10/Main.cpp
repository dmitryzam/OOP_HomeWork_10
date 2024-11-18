#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>

// ф-ия вывода сотрудников всех компаний:
void print(const std::list<std::map<std::string, double>>& list){
	std::list<std::map<std::string, double>>::const_iterator it_list;
	std::map<std::string, double>::const_iterator it_map;
	for (it_list = list.cbegin(); it_list != list.cend(); ++it_list) {
		std::cout << "Employee:\n";
		for (it_map = (*it_list).cbegin(); it_map != (*it_list).cend(); ++it_map)
			std::cout << "Name - " << it_map->first << ", salary - " << it_map->second << '\n';
	}
}
// ф-ия, возвращающая вектор самых высокооплачиваемых сотрудников из всех компаний 
// (по одному сотруднику из всех компаний)
std::vector<std::string> find_best_salary(std::list<std::map<std::string, double>>& list) {
	std::vector<std::string> tmp;
	std::list<std::map<std::string, double>>::const_iterator it_list;
	std::map<std::string, double>::const_iterator it_map;
	for (it_list = list.cbegin(); it_list != list.cend(); ++it_list) {
		double best_salary;
		std::string best_empl;
		it_map = (*it_list).cbegin();
		best_salary = it_map->second;
		for (it_map = (*it_list).cbegin(); it_map != (*it_list).cend(); ++it_map) {
			// в цикле for находим максимальную зарплату и добавляем ее обладателя в vector
			if (best_salary < it_map->second) {
				best_salary = it_map->second;
				best_empl = it_map->first;
			}
		}
		tmp.push_back(best_empl);
	}
	return tmp;
}

// ф-ия вывода вектора:
void print_vec(const std::vector<std::string>& vec) {
	for (auto& el : vec)
		std::cout << el << '\n';
	std::cout << std::endl;
}


int main() {
	setlocale(LC_ALL, "RU");

	// создадим объект класса list, полями которого будут объекты класса map. 
	// Каждый объект - это описание сотрудников компании. 
	// Ключи - фамилии сотрудников, а значения - их зарплаты.
	std::cout << "Task #10\n";
	std::map<std::string, double> comp1, comp2;
	std::list<std::map<std::string, double>> list;

	// добавим работников с их зарплатами в comp1:
	comp1.insert(std::make_pair("John Smith", 23.5));
	comp1.insert(std::make_pair("Sara Connor", 33.5));
	comp1.insert(std::make_pair("John Travolta", 15.8));
	list.push_back(comp1);

	// добавим работников с их зарплатами в comp2:
	comp2.insert(std::make_pair("Lady Gaga", 45.5));
	comp2.insert(std::make_pair("Elizabath Swan", 25.5));
	comp2.insert(std::make_pair("Bruce Willis", 15.5));
	list.push_back(comp2);

	print(list);

	std::cout << "\nEmployees have the best sallary:\n";
	std::vector<std::string> vec_best;
	vec_best = find_best_salary(list);
	print_vec(vec_best);

	return 0;
}