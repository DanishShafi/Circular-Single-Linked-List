#include <iostream>
using namespace std;


struct node{
	int value;
	node *next;
};

class Doubly_circular_list
{
	private:
		node *head;
		node *temp;
		node *ptr;
		node *tempe;
		int key;
		int vara;
		int counter;
	public:
		Doubly_circular_list()
		{
			head = NULL;
			temp = NULL;
			ptr = NULL;
			key =0;
			vara = 0;
			counter =0;
		}
		int making_Doubly_circular_list(){
			for (int i = 0; i < 10; i++)
			{
				if(head == NULL)
				{
					head = new node;
					head -> next = head;
					cout << "Enter the value " << endl;
					cin >> head -> value;
					ptr = head;
					temp = head;
				}
				else
				{
					temp ->next = new node;
					temp = temp ->next;
					cout << "Enter the value " << endl;
					temp ->next = head;
					cin >> temp ->value;
				}
			}
		}
		int Doubly_circular_printing()
		{
			temp = head;
			cout << "Here are requried value " << endl;
			for(int i =0; i<12;i++)
			{
				cout << temp -> value << endl;
				temp = temp ->next;
			}
			cout << endl;
		}
		int insert_at_circular_list(){
			temp = head;
			tempe = head ;
			cout << "Enter the key " << endl;
			cin >> key;
			if (head == NULL)
			{
				head = new node;
				head -> value = key;
				head ->next = head;	
			}
			if (head->value == key)
			{
				ptr = head; 
				do
				{
					tempe = tempe ->next;

				}while(tempe ->next != head);

				ptr = new node;
				ptr ->next = temp;
				cout << "Enter the value of Inserting Node " << endl;
				cin >> ptr->value;
				tempe ->next = ptr;
				head = ptr;

			}
			else
			{
				do
				{
					if(key == temp->next->value)
					{
						ptr =temp ->next;
						temp->next = new node;
						temp = temp -> next;
						temp -> next = ptr;
						cout << "Enter the value where you want to insert" << endl;
						cin >> temp -> value; 
					}
						temp =temp ->next;
				} while (temp != head);	
			}
			
		}
		int delete_at_circluar_list(){
			temp = head;
			cout << "Enter the key" << endl;
			cin >> key;
			if (head -> value == key){
				tempe = head;
				do{
					temp = temp ->next;
				}while(temp->next != head);
				ptr = temp ->next;
				temp->next  = temp ->next -> next;
				head = temp-> next;
				delete ptr;
				ptr = NULL;
			}
			else{
				do{
					if(key == temp->next->value)
					{
						ptr = temp -> next;
						temp ->next = temp ->next ->next;
						delete ptr;
						ptr = NULL;
					}
					temp = temp -> next;
				}while(temp != head);
			}
		}
};

int main(){
	Doubly_circular_list D1;
	D1.making_Doubly_circular_list();
	D1.Doubly_circular_printing();
	// D1.insert_at_circular_list();
	// D1.Doubly_circular_printing();
	// D1.Doubly_circular_printing();
	D1.delete_at_circluar_list();
	D1.Doubly_circular_printing();
}