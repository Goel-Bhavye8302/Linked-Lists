#include"Double list.h"
#include<sstream>
#include<iostream>



struct Node {
	int data;
	Node* next, *prev;
};



DoubleList::DoubleList()
{
	head = nullptr;
	tail = nullptr;
	indTail = 0;
}

DoubleList::~DoubleList()
{
	Node* ptr;
	for (Node* pos = head; pos != nullptr; pos = ptr) {
		ptr = pos->next;
		delete pos;
	}
}

void DoubleList::showTail()
{
	std::cout << indTail << "\n";
}

void DoubleList::empty()
{
	Node* ptr;
	for (Node* pos = head; pos != nullptr; pos = ptr) {
		ptr = pos->next;
		delete pos;
	}
	head = nullptr;
	tail = nullptr;
	indTail = 0;
}

std::string DoubleList::asString()
{
	// print all the elements 
	std::stringstream out;
	for (Node* pos = head; pos != nullptr; pos = pos->next) {
		out << pos->data;
		if (pos->next != nullptr)out << ", ";
	}
	return out.str();
}

void DoubleList::push_back(int d)
{
	Node* pos = new Node;
	pos->data = d;
	pos->next = nullptr;
	pos->prev = tail;

	if (head == nullptr) head = pos;
	if (tail != nullptr) {
		tail->next = pos;
		indTail += 1;
	}
	tail = pos;
}

void DoubleList::pop_back()
{
	if (tail != nullptr)
	{
		Node* pos = tail;
		tail = tail->prev;
		if (tail != nullptr)indTail -= 1;
		delete pos;
		if (tail == nullptr) head = nullptr;
		else tail->next = nullptr;
	}
}

void DoubleList::insert(int index, int d)
{
	if (index > indTail) return;

	Node* pos = new Node;
	pos->data = d;

	if (head == nullptr) {
		head = pos;
		tail = head;
		pos->next = nullptr;
		pos->prev = nullptr;
	}
	else {
		Node* ptr = nullptr;

		if (index <= indTail / 2) {
			ptr = head;
			for (int i = 0; i < index; i++, ptr = ptr->next);
		}

		else {
			ptr = tail;
			for (int i = indTail; i > index; i--, ptr = ptr->prev);
		}
		pos->next = ptr;
		pos->prev = ptr->prev;
		ptr->prev = pos;
		if (pos->prev != nullptr)pos->prev->next = pos;
		else head = pos;
		indTail += 1;
	}
}

int DoubleList::find(int d)
{
	int i = 0;
	for (Node* pos = head; pos != nullptr;i++, pos = pos->next) {
		if (pos->data == d) return i;
	}
	return -1;
}

void DoubleList::push_front(int d)
{
	Node* pos = new Node;
	pos->data = d;
		pos->next = head;
		if (head != nullptr)
		{
			head->prev = pos;
			indTail += 1;
		}
		pos->prev = nullptr;
		head = pos;

}

void DoubleList::pop_front()
{
	if (head == nullptr) return;
	Node* pos = head->next;
	delete head;
	if (pos != nullptr)pos->prev = nullptr;
	head = pos;
	if (indTail != 0) indTail -= 1;
}

int DoubleList::at(int index)
{
	Node* pos = nullptr;
	if (head == nullptr || index > indTail || index < 0) return -1;
	else if (index <= indTail / 2) {
		pos = head;
		for (int i = 0; i < index; i++, pos = pos->next);
		return pos->data;
	}
	else {
		pos = tail;
		for (int i = indTail; i > index; i--, pos = pos->prev);
		return pos->data;
	}
	return -1;
}

int DoubleList::back()
{
	if (tail != nullptr)return tail->data;
	else return -1;
}

void DoubleList::erase(int index)
{
	Node* pos = nullptr;
	if (head == nullptr || index < 0 || index > indTail) return;
	else if (index == 0) {
		if (head->next == nullptr) {
			delete head;
			return;
		}
		else {
			pos = head;
			pos->next->prev = nullptr;
			head = pos->next;
			delete pos;
			indTail -= 1;
			return;
		}
	}
	else if (index == indTail) {
		pos = tail;
		pos->prev->next = nullptr;
		tail = pos->prev;
		delete pos;
		indTail -= 1;
		return;
	}
	else if (index <= indTail / 2) {
		pos = head;
		for (int i = 0; i < index; i++, pos = pos->next);
	}
	else {
		pos = tail;
		for (int i = indTail; i > index; i--, pos = pos->prev);
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	indTail -= 1;
}

int DoubleList::front()
{
	if (head != nullptr)return head->data;
	else return -1;
}

int DoubleList::size()
{
	if (tail != nullptr)return indTail + 1;
	else return 0;
}

void DoubleList::reverse()
{
	if (head == nullptr || head->next == nullptr);
	else {
		Node* pos = tail;
		tail = head;
		head = pos;
		Node* ptr = nullptr;
		for (int i = indTail; i >= 0; i--) {
			pos->next = pos->prev;
			pos->prev = ptr;
			pos = pos->next;
			if (pos != nullptr)ptr = pos->next;
		}
	}
}

void DoubleList::sort()
{
}

void DoubleList::showType()
{
	std::cout << "Double List" << std::endl;
}
