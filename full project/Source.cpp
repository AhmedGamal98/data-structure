#include<iostream>
using namespace std;
#define max 10
struct stack
{
	int arr[max];
	int top;
	void intistack(stack &s)
	{
		s.top=-1;
	}
	void push(stack &s,int item)
	{
		if(s.top==max)
		{
			cout<<"Overflow"<<endl;
			return;
		}
		else
			s.arr[++s.top]=item;
		
	}
	void pop(stack &s)
	{
		if(s.top==-1)
		{
			cout<<"Empty"<<endl;
			return;
		}
		else
			s.arr[s.top--];
	}
	void search(stack &s)
	{
		int v,i,c;
		cout<<"you want to search for a value or index"<<endl;
		cout<<"1-to search for a posetion of a value "<<endl;
		cout<<"2-to search for an index of value"<<endl;
		cin>>c;
		if (c==1)
		{
			cout<<"enter a value"<<endl;
			cin>>v;
			for(int i=0;i<=s.top;i++)
			{		
				if(s.arr[i]==v)
				{
				cout<<"the indix of the value "<<v<<" is: "<< i<<endl;
				}
			}
		}
		else if (c==2)
		{
			cout<<"enter the index"<<endl;
			cin>>i;
			cout<<"the value of index "<<i<<" is "<<s.arr[i]<<endl;
		}
	}
	void display(stack &s)
	{
		/*cout<<"the elements os the stack : "<<endl;
		for (int i = 0; i < s.top; i++)
		{
			cout<<arr[i];
		}*/
		
		if(s.top!=-1)
	{
	while (s.top!=-1)
	{
		cout<<s.arr[s.top]<<endl;
		s.top--;
	}
	}
	else 
		cout<<"stack is empety"<<endl;
	}
	
}s; //Stack
 //<<------------------------------------------------------------->>
struct simple_queue
{
	int arr1[max];
	int front;
	int rear;
	void intiqueue(simple_queue &q)
	{
		
		q.front=-1;
		q.rear=-1;
	}
	void enqueue(simple_queue &q,int x)
	{
		if(q.rear==max-1)
		{
			cout<<"Full"<<endl;
			return;
		}
		else if(q.front==q.rear==-1)
		{
			q.front=0;
			q.rear=0;
		}
		else
		{
			q.rear++;
			if(q.rear>max-1)
			{
				cout<<"Overflow"<<endl;
				q.rear--;
				return;
			}
		}
		q.arr1[q.rear]=x;
	}
	void dequeue(simple_queue &q)
	{
		if(q.front==q.rear==-1)
		{
			cout<<"Empty"<<endl;
			return;
		}
		else if(q.front==q.rear==0)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front++;
		}
	}
	void display(simple_queue &q)
	{
		cout<<"the elements of Queue : "<<endl;
		for (int i = q.front; i <q.rear; i++)
		{
			cout<<q.arr1[i]<<endl;
		}
	}
}q; //Queue
 //<<------------------------------------------------------------->>
struct circular_queue
{
	int arr2[max];
	int front;
	int raer;
	void initicircular_queue(circular_queue &cq)
	{
		cq.front=-1;
		cq.raer=-1;
	}
	void enqueue(circular_queue &cq,int x)
	{
		if((cq.front==(cq.raer+1)%max)||(cq.front==0&&cq.raer==max-1))
		{
			cout<<"Overflow"<<endl;
			return;
		}
		else if(cq.front==cq.raer==-1)
		{
			cq.front=0;
			cq.raer=0;
		}
		else
		{
			cq.raer=(cq.raer+1)%max;
		}
		cq.arr2[cq.raer]=x;
	}
	void dequeue (circular_queue &cq)
	{
		if(cq.front==cq.raer==-1)
		{
			cout<<"Empty"<<endl;
			return;
		}
		else if(cq.front==cq.raer==0)
		{
			cq.front=-1;
			cq.raer=-1;
		}
		else
		{
			cq.front=(cq.front+1)%max;
		}
	}
	void display(circular_queue &cq)
	{
		if(cq.front==cq.raer==-1)
		{
			cout<<"empty"<<endl;
			return;
		}
		else if(cq.front<=cq.raer)
		{
			for(int i=cq.front;i<=cq.raer;i++)
			{
				cout<<cq.arr2[i]<<endl;
			}
		}
		else if(cq.front>=cq.raer)
		{
			for (int i = cq.front; i < max; i++)
			{
				cout<<cq.arr2[i]<<endl;
			}
			for(int i=0;i<=cq.raer;i++)
			{
				cout<<cq.arr2[i]<<endl;
			}
		}
	}
}cq; //CQ
 //<<------------------------------------------------------------->>

struct node
{
	int data;
	node *next;
	struct linked_list
	{
		node* head;
		node *tail;
	};
	void insert(node *head,int x)
	{
		if(head==NULL)
		{
			node *newnode=new node;
			head=newnode;
			newnode->next=NULL;
		}
		else
		{
			node *newnode=new node;
			node *temp=new node;
			temp=head;
			while (temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->data=x;
			newnode->next=NULL;
		}
	}
	void del(node *head,node *tail)
	{
		if(head==NULL)
		{
			cout<<"Empty"<<endl;
		}
		else 
		{
			node *temp=new node;
			
			temp=head;
			while (temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			tail=temp;
			temp=temp->next;
			tail->next=NULL;
			delete temp;
		}
	}
	void delposetion(node *head,int pos)
	{
		if(head==NULL)
		{
			cout <<"Empty"<<endl;
		}
		else
		{
			node * temp;
			node *x;
			temp=head;
			for(int i=0;i<pos-1;i++)
			{
				temp=temp->next;
				if(temp==NULL)
				{
					cout<<"list less than "<<pos<<endl;
					return;
				}
			}
			x=temp->next;
			temp->next=x->next;
			delete x;
		}
	}
	void addafterpostion(node *head,int pos,int d)
	{
		    node * temp;
			node *x;
			temp=head;
			for(int i=0;i<pos;i++)
			{
				temp=temp->next;
				if(temp==NULL)
				{
					cout<<"list less than "<<pos<<endl;
					return;
				}
			}
			node *newnode;
			newnode->data=d;
			newnode->next=temp->next;
			temp->next=newnode;
	}
	void deldata(node *head,int d)
	{
		    node *temp1,*temp2;
			temp1=head;
		if(head==NULL)
		{
			cout <<"Empty"<<endl;
			return;
		}
		else if(temp1->data=d)
		{
			
			head=temp1->next;
			delete temp1;
			return;
		}
		else
		{ 
			temp1=temp2;
			while (temp1!=NULL)
			{
			if(temp1->data==d)
			{
				if(temp1->next==NULL)
				{
					temp2->next=NULL;
					delete temp1;
					return;
				}
				else
				{
				temp2->next=temp1-> next;
				delete temp1;
				return;
				}
			}
			temp2=temp1;
			temp1=temp1->next;
			}
		}
	}
	void count(node *head)
	{
		if(head==NULL)
		{
			cout<<"Empty"<<endl;
			return;
		}
		else
		{
			int c=0;
			node *temp=head;
			while (temp!=NULL)
			{
				temp=temp->next;
				c++;
			}
			cout<<c<<endl;
		}
	}
	void display (node *head)
	{
		if(head==NULL)
		{
			cout<<"empty"<<endl;
			return;
		}
		else
		{
			node *temp=head;
			while (temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
	}
}n; //Linked_List
 //<<------------------------------------------------------------->>
 struct node
{
	int data;
	node *next;
	struct linked_list_stack
	{
		node* head;
		node *tail;
	};
	void insert (node *head,int num)
	{
		node *newnode;
		if(head==NULL)
		{
			newnode->data=num;
			newnode->next=NULL;
			head=newnode;
		}
		else
		{
			newnode->data=num;
			newnode->next=head;
			head=newnode;
		}
	}
	void del(node *head)
	{
		if(head==NULL)
		{
			cout<<"Empty"<<endl;
			return;
		}
		else
		{
			node *temp;
			temp=head;
			head=temp->next;
			delete temp;
		}
	}
 }stack; //linked list using stack
 //<<--------------------------------------------------------------------->>
 struct node
 {
	 int data;
	node *next;
	struct linked_list_queue
	{
		node* head;
		node *tail;
	};
	void insert(node * head,int num)
	{
		if(head==NULL)
		{
			node *newnode;
			newnode->data=num;
			newnode->next=NULL;
			head=newnode;
		}
		else
		{
			node *temp=head;
			node *newnode;
			while (temp->next!=NULL)
			{
				temp=temp->next;
			}
			newnode->data=num;
			temp->next=newnode;
			newnode->next=NULL;
		}
	}
	void del(node *head)
	{
		if(head==NULL)
		{
			cout<<"Empty"<<endl;
			return;
		}
		else
		{
			node *temp;
			temp=head;
			head=temp->next;
			delete temp;
		}
	}
 }queue; //linked list using queue
 //<<-------------------------------------------------------------->>

 void bubblesort(int a[],int n)
 {
	 int i,j,swap;
	 for(int i=0;i<n-1;i++)
	 {
		 for(int j=0;j<n-1;j++)
		 {
			 if(a[j]>a[j+1])
			 {
				 swap=a[j];
				 a[j]=a[j+1];
				 a[j+1]=swap;
			 }
		 }
	 }
 }            
 //Bubble sort
 //<<-------------------------------------------------------->>
 void selectionsort (int a[],int n)
 {
	 int i,j,loc,swap;
	 for(i=0;i<n-1;i++)
	 {
		 loc=i;
		 for(j=i+1;j<n;j++)
		 {
			 if(a[j]<a[loc])
				 loc=j;
		 }
		 if(loc!=i)
		 {
			 swap=a[i];
			 a[i]=a[loc];
			 a[loc]=swap;
		 }
	 }
 }
 //selection sort
 //<<-------------------------------------------------------->>
