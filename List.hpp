#pragma once
#include<string>

struct Node;

class List {
	Node* head;

public:

	List();
	~List();

	void empty();
	std::string asString();
	void push_back(int);
	void pop_back();
	void insert(int, int);
	int find(int);
	void push_front(int);
	void pop_front();
	int at(int);
	int back();
	void erase(int);
	int front();
	int size();
	void reverse();
	void sort();
	void showType();
};