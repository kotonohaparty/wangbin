//#include 

template <typename T>

class Node
{
public:
  Node()
	{
		this->next = NULL;
	}

	Node(T data, Node<T> *next = NULL)
	{
		this->data = data;
		this->next = next;
	}

private:
	T data;
	Node<T> *next;
}

template <typename T>

class SingleList
{
public:  
	SingleList();//构造空的单链表。  
	SingleList(T value[], intn);//构造由指定的数组提供的单链表  
	~SingleList();//析构  
	bool isEmpty();//判断是否为空。  
	int length();//获取长度  
	Node<T>* getNode(inti);//返回第i(i>=0)个节点指针  
	T get(inti);//返回第i个元素  
	bool set(inti,T x);//设置第i个元素为x  
	template<classT> friend std::ostream& operator<<(std::ostream& out,SinglyLinkedList<T> &list);  
	Node<T>* insert(inti,T x);//插入第I个节点并返回第i个节点的指针  
	bool remove(inti,T& old);//删除第i个元素，将删除的元素存放到old  
	void clear();//清空单链表  
	void concat(SinglyLinkedList<T> &list);//将List链接在当前单链表之后  

private:
	Node<T> *head;//单链表的头指针。
}

template <typename T>  
SingleList<T>::SingleList()//构造空的单链表  
{  
	this->head = NULL;  
}

template <typename T>  
SingleList<T>::~SingleList()//析构  
{  
	clear();  
}  

template <typename T> 
bool SingleList<T>::isEmpty()//判断链表是否为空  
{  
	return this->head == NULL;  
} 

template <typename T> 
int SingleList<T>::length()  
{  
　  int i = 0;  
	Node<T> *p = head;//创建一个用于遍的变量  
	while(p!=NULL)  
	{  
		i++;  
		std::cout<<p->data;  
		p=p->next;  
	}  
　  return i;  
}  

template <typename T> 
Node<T>* SingleList<T>::getNode(inti)  
{  
	if(i<0)  
	return NULL;  
	int j = 0;  

	Node<T> *p=head;  
	while(p != NULL && j < i)  
	{  
		j++;  
		p = p->next;  
	}  
	return p;  
}
/*
template <typename T> 
T SingleList<T>::get(int i)  
{  
	Node<T> *p=getNode(i);  
	if(p!=NULL)  
	return p->data;  
	T d;  
	return d;  
//throw "单链表为空或者参数指定的元素不存在";  
}  
*/
template <typename T>  
bool SingleList<T>::set(int i,T x)  
{  
	Node<T> *p = getNode(i);  
	if(p != NULL)  
	{  
		p->data = x;  
		return true;  
	}  
	return false;  
} 

template <typename T>   
std::ostream& operator<<(std::ostream& out,SingleList<T> &list)  
{  
	Node<T> *p=list.head;  
	out<<"(";  
	while(p != NULL)  
	{  
		out << p->data;  
		p = p->next;  
		if(p != NULL)  
		out << ",";  
	}  
	out << ") ";  
	return out;  
}  

template <typename T>  
void SingleList<T>::clear()  
{  
	Node<T> *p=head;  
	while(p!=NULL)  
	{  
		Node<T> *q = p;  
		p = p->next;  
		delete q;  
	}  
	head=NULL;  
} 

template <typename T>  
Node<T>* SingleList<T>::insert(int i,T x)  
{  
	Node<T> *q = NULL;  
	if(head == NULL || i < 0)//头插入(单链表为空或者)  
	{  
		q = new Node<T>(x,head);  
		head = q;  
	}  
	else 
	{  
		int j = 0;  
		Node<T> *p = head;  
		while(p->next != NULL && j < i-1)  
		{  
			j++;  
			p = p->next;  
		}  
		q = new Node<T>(x,p->next);  
　 		p->next=q;  
	}  
	return q;  
}  


template <typename T>  
SingleList<T>::SingleList(T table[],int n)  
{  
	head = NULL;  
	if(n > 0)  
	{  
		head = new Node<T>(table[0]);//创建节点  
　 		Node<T> *rear = head;//创建一个指向头节点的指针  
		int i = 1;  
　		while(i < n)  
		{  
			rear->next = new Node<T>(table[i++]);  
			rear = rear->next;  
		}  
	}  
} 

template <typename T>  
SingleList<T>::remove(int i,T &old)  
{  
	if(i < 0 || head == NULL)  
	{  
		Node<T> *q = head;  
		old = q->data;  
		head = head->next;  
		delete q;  
	}  
	else 
	{  
		Node<T> *p = getNode(i-1);//获取删除节点的前驱  
　      if(p != NULL && p->next != NULL)//判断删除节点和删除节点是否为空  
		{  
			Node<T> *q = p->next;//新建一个节点指针，将删除接点复制过去  
			old = q->data;  
			p->next = q->next;//让删除节点的前驱Next指针下一节点  
			delete q;//删除该节点  
　			return true;  
		}		  
　  }  
	return false;  
}  
//单链表的链接函数：concat()  
template <typename T>  
void SingleList<T>::concat(SingleList<T> &list)  
{  
	if(this->head == NULL)  
	{  
		this->head = list->head;  
	}  
	else 
	{  
		Node<T> *p = head;  
		while(p->next != NULL)  
		{  
			p = p->next;  
		}  
		p = list->head;  
	}  
	list->head = NULL;//设置单链表为空，否则运行出错  
} 
