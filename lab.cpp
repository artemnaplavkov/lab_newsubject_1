#include <iostream>
#include <fstream>

using namespace std;


struct List {
    float val;
	List* next= nullptr;
};

void free(List* head) {
	while (head) {
		List* tmp = head;
		head = head->next;
		delete tmp;
	};
}

List* read(istream&in) {
	List* head = nullptr;
	List* tail = nullptr;
	for (float el; in >> el && !in.eof() && !in.fail();) {
		if (tail) {
			tail->next = new List{};
			tail = tail->next;
		}
		else {
			tail = new List{};
			head = tail;
		}
		tail->val = el;
	}
	return head;
}

void print(List* head) {
	for (;  head; head = head->next) {
		cout << head->val << " ";
	}
	cout << "\n";
}

void stable_partition(List* head) {
	List* i = head;
	List* j = head;
	for (; i; i = i->next) {
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

	List* head = nullptr;
	if (ask) {
		ifstream in("C:\\Users\\79648\\Downloads\\lab1_newsubject_final\\lab.txt");
		head = read(in);
	}
	else {
		head = read(cin);
	}
	print(head);
	stable_partition(head);
	print(head);
	free(head);

	cout << "done\n";
}
