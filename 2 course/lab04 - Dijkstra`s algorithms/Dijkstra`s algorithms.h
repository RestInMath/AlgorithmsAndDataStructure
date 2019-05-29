#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "../AaDS_4sem/Template list.h"
#include "../RBTree/RBTree_.h"

struct route {
	std::string city = "";
	int distance;
	route() {

	}
	route(std::string c, int l) {
		city = c;
		distance = l;
	}
};

std::ostream & operator<<(std::ostream & stream, route l)
{
	stream << l.city << ' ' << l.distance << ' ';
	return stream;
}

void addRoute(RBTree<std::string, List<route>*> *map, std::string key_city, std::string end_city, std::string dist) {
	if (dist == "N/A")
		return;
	
	int distance;
	std::istringstream iss(dist);
	//check if good
	iss >> distance;

	try {
		List<route> *current_routes = map->find(key_city);
		current_routes->push_back(route(end_city, distance));
		map->insert(key_city, current_routes);
	}
	catch (std::exception e) {
		List<route> *new_route = new List<route>();
		new_route->push_back(route(end_city, distance));
		map->insert(key_city, new_route);
	}
}

RBTree<std::string, List<route>*>* getMatrix(std::string file_name, List<std::string>* all_cities, std::string *start_city) {
	setlocale(LC_ALL, "RUSSIAN");
	setlocale(LC_NUMERIC, "eng");

	std::ifstream inFile;
	std::string way = "C:\\Users\\Admin\\source\\repos\\AaDS_4sem\\Dijkstra`s algorithms\\" + file_name + ".txt";
	inFile.open(way);
	if (!inFile) {
		throw std::exception("No file!");
	}

	std::getline(inFile, *start_city);

	RBTree<std::string, List<route>*> *map = new RBTree<std::string, List<route>*>();
	List<std::string> *line;
	std::string line_str = "", word = "";
	while (std::getline(inFile, line_str)) {
		line = new List<std::string>();
		for (char c : line_str) {
			if (c != ';') {
				word += c;
			}
			else {
				line->push_back(word);
				word = "";
			}
		}
		line->push_back(word);
		word = "";
		
		addRoute(map, line->at(0), line->at(1), line->at(2));
		addRoute(map, line->at(1), line->at(0), line->at(3));
		
		//collect all_cities
		for (size_t i = 0; i < 2; i++) {
			if (!all_cities->contains(line->at(i))) {
				all_cities->push_back(line->at(i));
			}
		}
	}
	map->print_map();

	inFile.close();

	return map;
}

std::string find_min_new_route(RBTree<std::string, List<route>*>* map, RBTree<std::string, int>* city_routes, List<std::string>* visited) {
	DFT_sort_TreeIterator<std::string, int> *map_it = city_routes->create_sort_iterator();
	int min_dist;
	std::string min_city;

	bool no_min = true;

	while (map_it->has_next()) {
		bool node_is_not_visited = !visited->contains(map_it->getCurrent()->key);
		bool min_value = no_min || map_it->getCurrent()->value < min_dist;
		if (node_is_not_visited && min_value) {
			min_dist = map_it->getCurrent()->value;
			min_city = map_it->getCurrent()->key;
		}
		
		map_it->next();
	}

	return min_city;
}

void copy_values(List<std::string>* l, List<std::string>* r) {
	l->clear();
	Node<std::string>* cur = r->getRoot();
	while (cur != nullptr) {
		l->push_back(cur->value);
		cur = cur->goNext();
	}
}

void Dijsktra(RBTree<std::string, List<route>*> *map, std::string start_ñity, List<std::string>* all_cities){
	RBTree<std::string, List<std::string>*> *way = new RBTree < std::string, List<std::string>*>();
	List<std::string>* visited = new List<std::string>();
	
	//create map (distance from start to every city)
	Node<route> *temp = map->find(start_ñity)->getRoot();
	RBTree<std::string, int> *distance = new RBTree<std::string, int>();
	List<std::string> first_way;
	first_way.push_back(start_ñity);
	while (temp != nullptr) {
		distance->insert(temp->value.city, temp->value.distance);
		way->insert(temp->value.city, &first_way);
		temp = temp->goNext();
	}
	delete temp;

	//first init
	visited->push_back(start_ñity);
	size_t num_of_cities = all_cities->get_size();

	while (num_of_cities > visited->get_size()) {
		std::string min_route_city = find_min_new_route(map, distance, visited);
		visited->push_back(min_route_city);

		Node<route> *cur_node = map->find(min_route_city)->getRoot();
		while (cur_node != nullptr) {
			if (!visited->contains(cur_node->value.city)) {
				int new_dist = distance->find(min_route_city) + cur_node->value.distance;
				try {
					if (distance->find(cur_node->value.city) > new_dist) {
						distance->insert(cur_node->value.city, new_dist);
						
						//save way
						List<std::string>* cur_way = new List<std::string>();
						copy_values(cur_way, way->find(min_route_city) );
						cur_way->push_back(min_route_city);
						way->insert(cur_node->value.city, cur_way);
					}
				}
				catch (std::exception e) {
					distance->insert(cur_node->value.city, new_dist);
					//save way
					List<std::string>* cur_way = new List<std::string>();
					copy_values(cur_way, way->find(min_route_city));
					cur_way->push_back(min_route_city);
					way->insert(cur_node->value.city, cur_way);
				}
			}
			cur_node = cur_node->goNext();
		}
	}

	std::cout << "________________________________________\n";
	std::cout << "From " << start_ñity << " to:\n";
	distance->print_map();
	std::cout << "________________________________________\n";
	std::cout << "Ways:\n";
	way->print_map();
}

void doDijkstra(std::string file_name) {
	List<std::string> *all_cities = new List<std::string>();
	std::string beg_city;
	RBTree<std::string, List<route>*> *map = getMatrix(file_name, all_cities, &beg_city);

	if (all_cities->contains(beg_city))
		Dijsktra(map, beg_city, all_cities);
	else
		throw std::exception("No such city in data set");
}
