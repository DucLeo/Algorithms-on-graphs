#pragma once
#include <fstream>
#include <string>
#include "..\BRT\List.h"

constexpr auto INF = 1000000000;

class Cell {
public:
	string destination;
	string path;
	int weightPath;

	Cell() {
		this->destination = "";
		this->path = "";
		this->weightPath = INF;
	}
};

class Row {
public:
	string startPoint;
	List<Cell> listDestinations;

	Row() {
		this->startPoint = "";
		this->listDestinations = List<Cell>();
	}
};

class AdjacencyMatrix {
public:
	List<Row> listRows;

	void insert(string newPoint) {
		if (listRows.size == 0) {
			Row newRow = Row();
			newRow.startPoint = newPoint;
			Cell newCell = Cell();
			newCell.destination = newPoint;
			newRow.listDestinations.pushback(newCell);
			listRows.pushback(newRow);
		}
		else {
			if (!isContains(newPoint)) {
				Cell newCell = Cell();
				newCell.destination = newPoint;
				for (size_t i = 0; i < listRows.size; i++) {
					listRows.getIndex(i)->data.listDestinations.pushback(newCell);
				}
				Row newRow = Row();
				newRow.startPoint = newPoint;
				for (size_t i = 0; i < listRows.size; i++) {
					Cell newCell = Cell();
					newCell.destination = listRows.getIndex(i)->data.startPoint;
					newRow.listDestinations.pushback(newCell);
				}
				newRow.listDestinations.pushback(newCell);
				listRows.pushback(newRow);
			}
		}
		listRows.getIndex(listRows.size - 1)->data.listDestinations.getIndex(listRows.size - 1)->data.weightPath = 0;
	}

	int toInt(string org) {
		if (org.length() == 0) throw logic_error("Error number!");
		else {
			if (org[0] == '0' && org.length() > 1) throw invalid_argument("Error number!");
			else {
				int number = 0;
				for (int i = 0; i < org.length(); i++) {
					switch (org[i])
					{
					case '0':
						number += (int)(0 * pow(10, org.length() - 1 - i));
						break;
					case '1':
						number += (int)(1 * pow(10, org.length() - 1 - i));
						break;
					case '2':
						number += (int)(2 * pow(10, org.length() - 1 - i));
						break;
					case '3':
						number += (int)(3 * pow(10, org.length() - 1 - i));
						break;
					case '4':
						number += (int)(4 * pow(10, org.length() - 1 - i));
						break;
					case '5':
						number += (int)(5 * pow(10, org.length() - 1 - i));
						break;
					case '6':
						number += (int)(6 * pow(10, org.length() - 1 - i));
						break;
					case '7':
						number += (int)(7 * pow(10, org.length() - 1 - i));
						break;
					case '8':
						number += (int)(8 * pow(10, org.length() - 1 - i));
						break;
					case '9':
						number += (int)(9 * pow(10, org.length() - 1 - i));
						break;
					default:
						throw invalid_argument("Error number!");
					}
				}
				return number;
			}
		}
	}

	void takeData(string fileName) {
		fstream file(fileName);
		if (!file.is_open()) throw invalid_argument("Could not open file!");
		else {
			string tmp;

			while (getline(file, tmp, '\n')) {
				int j = 0;
				string point1 = "";
				string point2 = "";
				string save = "";
				for (size_t i = 0; i < tmp.length(); i++) {
					if (i == tmp.length() - 1) {
						save += tmp[i];
						if (save != "N/A") {
							listRows.getIndex(order(point2))->data.listDestinations.getIndex(order(point1))->data.weightPath = toInt(save);
							listRows.getIndex(order(point2))->data.listDestinations.getIndex(order(point1))->data.path = point2 + " ---> " + point1;
						}
						save = "";
					}
					else if (tmp[i] != ';') {
						save += tmp[i];
					}
					else {
						if (j == 0) {
							point1 = save;
							insert(point1);
							j++;
						}
						else if (j == 1) {
							point2 = save;
							insert(point2);
							j++;
						}
						else {
							j = 0;
							if (save != "N/A") {
								listRows.getIndex(order(point1))->data.listDestinations.getIndex(order(point2))->data.weightPath = toInt(save);
								listRows.getIndex(order(point1))->data.listDestinations.getIndex(order(point2))->data.path = point1 + " ---> " + point2;
							}
						}
						save = "";
					}
				}
			}
			file.close();
		}
	}
	
	void FloydWarshall() {
		if (listRows.head == NULL) throw invalid_argument("Adjacency matrix is empty!");
		else {
			for (size_t i = 0; i < listRows.size; i++) {
				for (size_t j = 0; j < listRows.size; j++) {
					if (j != i) {
						for (size_t k = 0; k < listRows.size; k++) {
							if (k != i) {
								if (listRows.getIndex(j)->data.listDestinations.getIndex(k)->data.weightPath
									> listRows.getIndex(j)->data.listDestinations.getIndex(i)->data.weightPath +
									listRows.getIndex(i)->data.listDestinations.getIndex(k)->data.weightPath) {

									listRows.getIndex(j)->data.listDestinations.getIndex(k)->data.weightPath =
										listRows.getIndex(j)->data.listDestinations.getIndex(i)->data.weightPath +
										listRows.getIndex(i)->data.listDestinations.getIndex(k)->data.weightPath;

									listRows.getIndex(j)->data.listDestinations.getIndex(k)->data.path =
										listRows.getIndex(j)->data.listDestinations.getIndex(i)->data.path + "\n" +
										listRows.getIndex(i)->data.listDestinations.getIndex(k)->data.path;
								}
							}
						}
					}
				}
			}
		}
	}

	bool isContains(string point) {
		if (listRows.head == NULL) throw invalid_argument("Adjacency matrix is empty!");
		else {
			bool check = 0;
			for (size_t i = 0; i < listRows.size; i++) {
				if (point == listRows.getIndex(i)->data.startPoint) {
					check = 1;
					break;
				}
			}
			return check;
		}
	}

	size_t order(string point) {
		if (listRows.head == NULL) throw logic_error("Graph is not contains this point!");
		else {
			size_t order = listRows.size;
			for (size_t i = 0; i < listRows.size; i++) {
				if (point == listRows.getIndex(i)->data.startPoint) {
					order = i;
					break;
				}
			}
			if (order == listRows.size) throw logic_error("Graph is not contains this point!");
			else return order;
		}
	}

	string shortedPath(string startPoint, string destination) {
		if (listRows.head == NULL) throw logic_error("Graph is empty!");
		else {
			if (listRows.getIndex(order(startPoint))->data.listDestinations.getIndex(order(destination))->data.path == "") return "Not available!";
			else return listRows.getIndex(order(startPoint))->data.listDestinations.getIndex(order(destination))->data.path;
		}
	}

	int weighthSortedPath(string startPoint, string destination) {
		if (listRows.head == NULL) throw logic_error("Graph is empty!");
		else if (listRows.getIndex(order(startPoint))->data.listDestinations.getIndex(order(destination))->data.weightPath == INF)
			throw invalid_argument("Not available!");
		else {
			return listRows.getIndex(order(startPoint))->data.listDestinations.getIndex(order(destination))->data.weightPath;
		}
	}

	AdjacencyMatrix() {
		this->listRows = List<Row>();
	}
};