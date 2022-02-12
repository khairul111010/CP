#include <iostream>
using namespace std;
class List;

class Node
{
	int data;
	
public:
	Node* next;
	Node(int d):data(d),next(NULL){} //Constructor
	int getData(){
		return data;
	}
	friend class List;
};


class List{
	Node *head;
	Node *tail;
public:
	
	List():head(NULL),tail(NULL){}
	Node *begin(){
		return head;
	}
	Node *end(){
		return tail;
	}
	void push_f(int d){
		if(head == NULL){
			Node * n = new Node(d);
			head = tail = n;
		}else{
			Node *n = new Node(d);
			n->next = head;
			head = n;
		}
	}

	void push_b(int d){
		if(head == NULL){
			Node * n = new Node(d);
			head = tail = n;
		}else{
			Node *n = new Node(d);
			tail->next = n;
			tail = n;
		}
	}

	void insert(int d ,int pos){
		if (pos == 0)
		{
			push_f(d);
			return;
		}

		Node *temp = head;
		for (int i = 1; i <= pos - 1; i++)
		{
			temp =  temp->next;

		}
		Node *n = new Node(d);
		n->next = temp->next;
		temp->next = n;
	}
};


bool search(Node *head, int key){
	Node *temp = head;
	while(temp!=NULL){
		if (head->getData() == key)
		{
			return true;
		}
		head = head->next;
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	List l;
	l.push_f(1);
	l.push_f(0);
	l.push_b(2);
	l.push_b(3);
	l.push_b(5);
	l.insert(85,4);
	
	Node* head = l.begin();
	while(head!=NULL){
		cout << head->getData() << "->" ;
		head = head->next;
	}
	cout << endl;
	cout << search(head,85);
	return 0;
}