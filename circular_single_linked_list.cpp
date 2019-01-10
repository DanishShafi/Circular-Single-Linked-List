#include<iostream>
using namespace std;

struct node{
	int info;
	node *next,*temp; 
};
class list{
	private:
		node *temp, *head, *ptr;
			
	public:
		list()
		{
			head=NULL;
			temp=NULL;
			ptr=NULL;
		}
	
	void insert_front(int x)
	{
		if(head==NULL)
		{
			head=new node();
			head->info=x;
			head->next=head;
			return;
		}
		
			ptr=head;
			while(ptr->next!=head){
				ptr=ptr->next;
			}
			temp=new node();
			temp->info=x;
			temp->next=head;
			head=temp;
			ptr->next=head;
		
	}
	int insert_middle(int x, int key)
	{
		temp=head;
		while(temp->next!=head)
		{
			if(temp->info==key)
			{
				ptr=new node();
				ptr->info=x;
				ptr->next=temp->next;
				temp->next=ptr;
			}
			temp=temp->next;
		}
	}	
	void delete_middle(int x)
	{
		temp=head;
		while(temp->next!=head)
		{
			if(temp->next->info==x)
			{
				temp->next=ptr;
				temp->next=temp->next->next;
				delete ptr;
				ptr=NULL;
			}
			temp=temp->next;
			
		}
	}
	
	int delete_end(int x)
	{
		temp=head;
		while(temp->next!=head)
		{
			if(temp->next->info==x)
			{
				temp->next=ptr;
				temp->next=head;
				delete ptr;
				ptr=NULL;
			}
			temp=temp->next;
		}
	}
	int delete_front(int x)		// mistake in this code does not work  
	{
		temp=head;
		while(temp->next!=head)
		{
			if(temp->next==head)
			{
				temp->next=ptr;
				temp->next=head->next;	
				head=temp->next->next;
				delete ptr;
				ptr=NULL;
			}
			temp=temp->next;
		}
	}
	void search(int x)
	{
		temp=head;
		while(temp->next!=head)
		{
			if(temp->info==x)
			{
				cout<<"found value = "<<x<<endl;
			}
			temp=temp->next;
		}
	}
	void print()
	{
		temp=head;
	
			while(temp->next!=head){
				cout<<temp->info<<"  ";
				temp=temp->next;
			}
			cout<<temp->info;
			cout<<endl;
	}
};



int main(){
	list l;
	l.insert_front(1);
	l.insert_front(2);
	l.insert_front(4);
	l.insert_front(5);

	
	l.print();
	
	cout<<"insert the value in middle list "<<endl;
	l.insert_middle(3,4);
	l.print();
	
	l.search(4);
	
	cout<<"delete middle value of list"<<endl;
	l.delete_middle(3);
	l.print();
	
	cout<<"delete end value of list"<<endl;
	l.delete_end(1);
	l.print();
	
	cout<<"delete front value of list"<<endl;
	l.delete_front(5);
	l.print();
	return 0;
}

