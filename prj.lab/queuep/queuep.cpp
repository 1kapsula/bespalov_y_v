#include"queuep.h"

Node::Node(const int& val) {
	this->pNext = nullptr;
	this->value_ = val;
}

Node::Node(const int& val, std::unique_ptr<Node>& ptr) {
	value_ = val;
	pNext = std::move(ptr);
}

QueueP::QueueP(const QueueP& copy) {
	Node* temp = copy.head.get();
	while (temp != 0) {
		push(temp->value_);
		temp = temp->pNext.get();
	}
}

QueueP::~QueueP() {
	while (head) {
		head = std::move(head->pNext);
	}
}

void QueueP::push(const int& val) {
	/*std::unique_ptr<Node> temp= std::unique_ptr<Node>(new Node(val));*/
	/*temp->pNext = std::move(head);*/
	Node* t_head = new Node();
	t_head = head.get();
	if (head == nullptr) {
		head = std::unique_ptr<Node>(new Node(val));
	}
	else if (head->value_ > val) {
		head = std::unique_ptr<Node>(new Node(val, head));
	}
	else {
		while (t_head->pNext != nullptr && t_head->pNext->value_ <= val) {
			t_head = t_head->pNext.get();
		}
		t_head->pNext = std::unique_ptr<Node>(new Node(val, t_head->pNext));
	}
}

void QueueP::pop() {
	if (head != nullptr) {
		head = std::move(head->pNext);
	}
}

const int& QueueP::top() const {
	return head->value_;
}

bool QueueP::isEmpty() const{
	return head == nullptr;
}

QueueP& QueueP:: operator=(const QueueP& right) {
	Node* temp = right.head.get();
	if (temp != nullptr) {
		head = std::unique_ptr<Node>(new Node(temp->value_));
		temp = temp->pNext.get();
	}
	Node* temp_ = head.get();
	while (temp != nullptr) {
		temp_->pNext = std::unique_ptr<Node>(new Node(temp->value_));
		temp_ = temp_->pNext.get();
		temp = temp->pNext.get();
	}
	return *this;
}

QueueP& QueueP::operator=(QueueP&& right) noexcept {
	if (head != nullptr) {
		head = std::move(right.head);
		Node* temp = head->pNext.get();
		while (temp != nullptr) {
			head->pNext = std::move(head->pNext);
			temp = temp->pNext.get();
		}
	}
	return *this;
}

QueueP::QueueP(QueueP&& right) noexcept {
	*this = right;
}







