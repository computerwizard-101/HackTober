#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
	
};


void insert_at_head(node *&head, int d)
{
	if(head==NULL)
	{
		head=new node(d);
		return;
	}
	node *n=new node(d);
	n->next=head;
	head=n;
	return;
}
 void print(node *head)
 {
 	while(head!=NULL)
 	{
 		cout<<head->data<<" ";
 		head=head->next;
 	}
 	return;
 }

 int count(node *head)
 {
 	int cnt=0;
 	while(head!=NULL)
 	{
 		cnt++;
 		head=head->next;
 	}
 	return cnt;
 }

 void insert_at_tail(node *&head, int d)
 {
 	if(head==NULL)
 	{
 		insert_at_head(head,d);
 		return;
 	}
 	node *temp=head;
 	while(temp->next!=NULL)
 	{
 		temp=temp->next;
 	}
 	node *n=new node(d);
 	temp->next=n;
 	return;
 }


 void insert_at_pos(node *&head, int d, int p)
 {
 	if(head==NULL || p==0)
 	{
 		insert_at_head(head,d);
 		return;
 	}
 	else if(p>count(head))
 	{
 		insert_at_tail(head,d);
 		return;
 	}
 	else
 	{
 		int jump=1;
 		node *temp=head;
 		while(jump<=p-1)
 		{
 			temp=temp->next;
 			jump++;
 		}
 		node *n=new node(d);
 		n->next=temp->next;
 		temp->next=n;
 		return;
 	}
 }

 void delete_at_head(node *&head)
 {
 	if(head==NULL)
 	{
 		return;
 	}
 	node *temp=head;
 	head=head->next;
 	delete temp;
 	return;
 }

void delete_at_tail(node *&head)
{
	if(head==NULL)
	{
		return;
	}
	if(head->next==NULL)
	{
		delete_at_head(head);
		return;
	}
	node *prev=head;
	node *temp=head;
	while(temp->next!=0)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	delete temp;
	return;
}


void delete_at_pos(node *&head, int p)
{
	if(head==NULL || p==0)
 	{
 		return;
 	}
 	else if(p==count(head))
 	{
 		delete_at_tail(head);
 		return;
 	}
 	else
 	{
 		int jump=1;
 		node *temp=head;
 		node *prev=head;
 		while(jump<=p-1)
 		{
 			prev=temp;
 			temp=temp->next;
 			jump++;
 		}
 		prev->next=temp->next;
 		delete temp;
 		return;
 	}
}

bool search(node *head, int key)
{
	if(head==NULL)
	{
		return false;
	}
	if(head->data==key)
	{
		return true;
	}
	else
	{
		return search(head->next,key);
	}
}

node* take_input()
{
	node *head=NULL;
	int d;
	cin>>d;
	while(d!=-1)
	{
		insert_at_head(head,d);
		cin>>d;
	}
	return head;
}

////from a file
node *input_file()
{
	node *head=NULL;
	int d;
	while(cin>>d)
	{
		insert_at_head(head,d);
	}
	return head;
}

ostream& operator << (ostream &os, node *head)
{
	print(head);
	return os;
}

istream& operator >> (istream &is, node *&head)
{
	head=take_input();
	return is;
}

int main()
{
	node *head=NULL;
	insert_at_head(head,1);
	insert_at_head(head,2);
	insert_at_head(head,3);
	insert_at_tail(head,4);
	insert_at_pos(head,5,2);
	cout<< head <<endl;
	delete_at_pos(head,3);
	print(head);
	cout<<endl;
	delete_at_head(head);
	print(head);
	cout<<endl;
	delete_at_tail(head);
	print(head);

	cout<<endl;





	return 0;
}
