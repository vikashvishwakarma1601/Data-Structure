#include<iostream>
#include<stdlib.h>
using namespace std;

int len_of_list = 0;

struct Node 
{
	int data;
	Node *next;
}*head=NULL;

Node *insertion_at_begin(int key)
{
	len_of_list++;
	Node *temp = new Node;
	temp->data = key;
	temp->next = head;
	head = temp;
}

Node *insertion_at_end(int key)
{
	len_of_list++;
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	Node *t = head;
	while(t->next!=NULL)
	{
		t = t->next;
	}
	t->next = temp;
	
}

Node *insertion_at_position(int key,int position)
{
	if(position-1 <1 || position-1>len_of_list)
	{
		cout<<"\n\t\t\tInvalid Position...Try Again!";
		return 0;
	}
	Node *temp = new Node;
	temp->data = key;
	Node *t = head;
	int p=0;
	if(position-1==1)
	{
		insertion_at_begin(key);
		return 0;
	}
	while(p!=position-2)
	{
		t=t->next;
		p++;
	}
	temp->next = t->next;
	t->next = temp;
	
}

void deletion_of_head()
{
	if(head==NULL)
	{
		cout<<"\n\t\t\tLinked List is empty. Try Again !";
		return;
	}
	Node *temp = head;
	temp = temp->next;
	head = temp;
}

void deletion_of_tail()
{
	if(head==NULL)
	{
		cout<<"\n\t\t\tLinked List is empty. Try Again !";
		return;
	}
	Node *temp = head;
	while(temp->next->next!=NULL)
	{
		temp= temp->next;
	}
	temp->next = NULL;
	
}

void deletion(int key)
{
	if(head==NULL)
	{
		cout<<"\n\t\t\tLinked List is empty. Try Again !";
		return;
	}
	Node *temp = head;
	if(temp->data==key)
	{
		deletion_of_head();
		return;
	}
	while(temp->next->data!=key)
	{
		temp=temp->next;
		if(temp->next==NULL && temp->data!=key)
		{
			cout<<"\n\t\t\tData Not Found...Try Again!\n";
			return;
		}
	}
	temp->next = temp->next->next;
}

void display(Node *head)
{
	if(head==NULL)
	{
		cout<<"\n\t\t\tLinked List is empty. Try Again !";
		return;
	}
	Node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ->  ";
		temp = temp->next;
	}
	cout<<"NULL\n";
	
}

int main()
{
	int choice;
	X:
		cout<<"\t\t\t1.Insertion_at_Begin\n\t\t\t2.Insertion_at_End\n\t\t\t3.Insertion_at_position\n\t\t\t4.Deletion_of_FirstNode\n\t\t\t5.Deletion_of_LastNode\n\t\t\t6.Deletion\n\t\t\t7.Display\n\t\t\t8.Quit\n";
		cout<<"\t\t\tEnter Choice : ";
		cin>>choice;
		int data;
		switch(choice)
		{
			case 1:
				cout<<"\n\t\t\tEnter Data : ";
				cin>>data;
				insertion_at_begin(data);
				goto X;
			case 2:
				cout<<"\n\t\t\tEnter Data : ";
				cin>>data;
				insertion_at_end(data);
				goto X;
			case 3:
				int position;
				cout<<"\n\t\t\tEnter Data & Position : ";
				cin>>data>>position;
				insertion_at_position(data,position);
				goto X;
			case 4:
				deletion_of_head();
				goto X;
			case 5:
				deletion_of_tail();
				goto X;
			case 6:
				cout<<"\n\t\t\tEnter Node Data to Delete : ";
				cin>>data;
				deletion(data);
				goto X;
			case 7:
				display(head);
				goto X;
			case 8:
				return 0;
			default:
				cout<<"\n\t\t\tEntered Wrong Option. Try Again...!\n";
				goto X;
		}
}


