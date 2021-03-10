#include"List.hpp"
#include<sstream>
#include<iostream>

struct Node {
	int data;
	Node* next;
};

List::List()
{
	head = nullptr;
	std::cout << "Simple List";
}

List::~List()
{
	// dynamic memory deletion 
	Node* ptr;
	for (Node* pos = head; pos != nullptr; pos = ptr) {
		ptr = pos->next;
		delete pos;
	}
}

void List::empty()
{
	Node* ptr;
	for (Node* pos = head; pos != nullptr; pos = ptr) {
		ptr = pos->next;
		delete pos;
	}
	head = nullptr;
}

std::string List::asString()
{
	// print all the elements 
	std::stringstream out;
	for (Node* pos = head; pos != nullptr; pos = pos->next) {
		out << pos->data;
		if (pos->next != nullptr)out << ", ";
	}
	return out.str();
}

void List::push_back(int d)
{
	// puts d in the last element of list
	if (head == nullptr) {
		head = new Node;
		head->data = d;
		head->next = nullptr;
	}

	else {
		Node* pos;
		for (pos = head; pos->next != nullptr; pos = pos->next);

		pos->next = new Node;
		pos->next->data = d;
		pos->next->next = nullptr;
	}
}

void List::pop_back()
{
	// deletes last element of list
	if (head == nullptr);
	else if (head->next == nullptr) {
		delete head;
		head = nullptr;
	}
	else {
		Node* pos;
		for (pos = head; pos->next->next != nullptr; pos = pos->next);
		delete pos->next;
		pos->next = nullptr;
	}
}

void List::insert(int index, int d)
{
	Node* ins = new Node;
	ins->data = d;
	if (index < 0)delete ins;
	else if (index == 0) {
		ins->next = head;
		head = ins;
	}
	else {
		Node* pos = head;
		for (int i = 0; i < index; i++, pos = pos->next) {
			if (i == index - 1 || pos->next == nullptr) {
				ins->next = pos->next;
				pos->next = ins;
				break;
			}
		}
	}
}

int List::find(int d)
{
	int i = 0;
	for (Node* pos = head; pos != nullptr; pos = pos->next, i++) {
		if (pos->data == d) return i;
	}
	return -1;
}

void List::push_front(int d)
{
	Node* ins = new Node;
	ins->data = d;

	ins->next = head;
	head = ins;
}

void List::pop_front()
{
	if (head != nullptr) {
		Node* pos = head->next;
		delete head;
		head = pos;
	}
}

int List::at(int index)
{
	int i = 0;
	for (Node* ptr = head; ptr != nullptr; ptr = ptr->next) {
		if (index == i) return ptr->data;
		i += 1;
	}
	return -1;
}

int List::back()
{
	Node* ptr;
	for ( ptr = head; ptr->next != nullptr; ptr = ptr->next);
		return ptr->data;
}

void List::erase(int index)
{
	int i = 1;
	Node* pos = head;
	Node* ptr;


	if (head->next == nullptr && index == 0) {
		delete head;
		head = nullptr;
	}
	else if (index == 0) {
		pos = pos->next;
		delete head;
		head = pos;
	}
	else {
		for (ptr = head->next; ptr != nullptr; ptr = ptr->next) {

			if (index == i) {
				pos->next = ptr->next;
				delete ptr;
				break;
			}
			pos = pos->next;
			i += 1;
		}
	}
}

int List::front()
{
	if (head != nullptr) return head->data;
	else return -1;
}

int List::size()
{
	int i = 0;
	for (Node* pos = head; pos != nullptr; pos = pos->next, i += 1);
	return i;
}

void List::reverse()
{
	Node* current = head;
	Node* prev = nullptr, * next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void List::showType()
{
	std::cout << "Simple List" <<std::endl;
}


