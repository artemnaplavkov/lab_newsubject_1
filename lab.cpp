#include <iostream>
#include <fstream>

using namespace std;


struct List {
	struct Node{
		float val;
		Node* next= nullptr;
	};
	Node* head=nullptr;
	Node* tail= nullptr;
	void push_back(float el) {
		if (tail) {
			tail->next = new Node{};
			tail = tail->next;
		}
		else {
			tail = new Node{};
			head = tail;
		}
		tail->val = el;
	}
	void free() {
		Node* ptr = head;
		while (ptr) {
			Node* tmp = ptr;
			ptr = ptr->next;
			delete tmp;
		}
		head = nullptr;
		tail = nullptr;
	}
};

void read(istream&in, List&out) {
	for (float el; in >> el && !in.eof() && !in.fail();) {
		out.push_back(el);
	}
}

void print(List& list) {
	List::Node* ptr = list.head;
	while (ptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << "\n";
}

void stable_partition(List&list) {
	List::Node* j = list.head;
	for (List::Node* i = list.head; i; i = i->next) {
		if (i->val!=0) {
			j->val = i->val;
			j = j->next;
		}
	}
	for (; j; j = j->next) {
		j->val = 0;
	}
}


int main(int argc, char *argv[]) {
	int ask;
	cout << "Insert 0: keyboard; 1: file\n";
	cin >> ask;
	

	List list;
	if (ask) {
		ifstream in("C:\\Users\\79648\\Downloads\\lab1_newsubject_final\\lab.txt");
		read(in, list);
	}
	else {
		read(cin,list);
	}
	print(list);
	stable_partition(list);
	print(list);
	list.free();

	cout << "done\n";
}