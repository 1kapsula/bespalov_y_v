#include<iostream>
#include"queuep.h"

int main() {
	QueueP queue, queue2;
	for (int i = 0; i < 10; i++) {
		queue.push(10 - i % 4);
	}
	for (int i = 0; i < 5; i++) {
		queue2.push(i);
	}
	queue2 = queue;
	QueueP queue3(queue);
	while (!queue.isEmpty()) {
		std::cout << queue.top() << " ";
		queue.pop();
	}
	std::cout << "\n";
	while (!queue2.isEmpty()) {
		std::cout << queue2.top() << " ";
		queue2.pop();
	}

	std::cout << "\n";
	while (!queue3.isEmpty()) {
		std::cout << queue3.top() << " ";
		queue3.pop();
	}

}