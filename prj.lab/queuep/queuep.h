#pragma once
#include<memory>
#include<iostream>

struct Node {
	Node() = default;
	Node(const int& val);
	Node(const int& val, std::unique_ptr<Node>& ptr);
	~Node() = default;
	std::unique_ptr<Node> pNext ;
	int value_ = 0;
};

class QueueP {
public:
	QueueP() = default;
	QueueP(const QueueP& copy);
	QueueP(QueueP&& copy) noexcept;
	~QueueP();
	void push(const int& val);
	void pop();
	const int& top() const;
	bool isEmpty() const;
	QueueP& operator=(const QueueP& right);
	QueueP& operator=(QueueP&& right) noexcept;
private:
	int32_t size = 0;
	std::unique_ptr<Node> head;
};