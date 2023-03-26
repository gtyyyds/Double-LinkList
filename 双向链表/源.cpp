#include<iostream>//输入输出流
using namespace std;//标准命名空间
class ListNode//创建双链表节点类
{
public:
	ListNode() {};//无参构造
	ListNode(int data)//有参构造
	{
		this->m_data = data;//赋值
	}
	friend class DLinkList;//双链表类作友元，这样双链表类可以访问节点类的私有属性
private://私有属性
	int m_data;//数据域
	ListNode* prior;//指向上个节点
	ListNode* next;//指向下个节点
};
class DLinkList//双链表类
{
public:
	DLinkList()//双链表无参构造
	{
		this->initList();//创建对象时，自动初始化
	}
	void initList();//成员函数：初始化
	bool insertData(int pos, int data);//插入数据
	bool deleteData(int pos);//删除数据
	void printNode();//打印双链表
private://私有属性
	ListNode* head;//头节点
};
void DLinkList::initList()//双链表作用域下的成员函数：初始化双链表
{
	head = new ListNode;//在堆区创建一个新节点作为头节点，并且把头节点指针返回给head
	head->next = NULL;//头节点的后继指空
	head->prior = NULL;//头节点的前驱指空
}
bool DLinkList::insertData(int pos, int data)//在逻辑位置的前面插入某个数据
{
	int j = 0;//计数器
	ListNode* p = head;//把头节点的地址交给p操作
	while (p && j < pos - 1)//如果链表不为空，或者存在逻辑位置
	{
		p = p->next;//推进
		j++;//计数
	}
	if (!p || j > pos - 1)//如果链表为空了，或者位置不合理直接返回失败
	{
		return false;
	}
	//重点：这里p指向的要插入节点的前节点的地址
	ListNode* s = new ListNode;//创建一个新节点在堆区，并且把该节点的地址返回给s
	s->next = p->next;//对新创建的节点的next操作，把原来的p->next，插完之后，该节点在s的后方，所以要把p->next赋给s->next
	p->next = s;//插入完后，s节点的前驱的next由原来的p->next,改变为指向s
	s->prior = p;//对新节点的prior进行操作，指向它的前驱
	p->next->prior = s;//对新节点的后面节点的prior进行操作，指向s
	s->m_data = data;//存入数据
	return true;//成功插入
}
bool DLinkList::deleteData(int pos)//删除数据
{
	int j = 0;//计数器
	ListNode* p = head;//让p代替head进行操作
	while (p && j < pos - 1)//如果链表不为空，或者存在逻辑位置
	{
		p = p->next;//推进
		j++;//计数
	}
	if (!p || j > pos - 1)//如果链表为空了，或者位置不合理直接返回失败
	{
		return false;
	}
	//重点：这里p指向的是要删除节点的前节点的地址
	ListNode* q = p->next;
//	p->next->next->prior = p;
	if(q->next!=NULL)//如果删除最后一个节点，则不需要操作最后节点的prior
	q->next->prior = p;//删除后，需要对删除节点的后一个节点的前驱进行操作
	p->next = q->next;//删除后，需要对删除节点的前一个节点的后继进行操作
	delete q;
	return true;
}
void DLinkList::printNode()//打印链表
{
	ListNode* L = head->next;//指向首元节点
	while (L != NULL)
	{
		cout << L->m_data << " ";//打印内容
		L = L->next;//推进
	}
	cout << endl;//换行
}
void showMenu()//菜单
{
	cout << "  ***********************" << endl;
	cout << "  ***  1、初始化链表  ***" << endl;
	cout << "  ***  2、前插入数据  ***" << endl;
	cout << "  ***  3、删除某数据  ***" << endl;
	cout << "  ***  4、遍历双链表  ***" << endl;
	cout << "  ***  0、退      出  ***" << endl;
	cout << "  ***********************" << endl;
	cout << "  请输入你的选项：";
}
int main()//主函数
{
	DLinkList L;//创建链表对象
	int select;
	while (true)//死循环，用户正确操作可退出
	{
		showMenu();
		cin >> select;//输入选择
		switch (select)
		{
		case 1:
			L.initList();
			cout << "初始化成功！" << endl;
			system("pause");//按任意键继续
			system("cls");//清屏
			break;
		case 2:
		{
			cout << "你想在第几个数据前插入数据？" << endl;
			int pos, data;
			cin >> pos;
			cout << "你想插入什么数据？" << endl;
			cin >> data;
			if (L.insertData(pos, data))
			{
				cout << "插入成功！" << endl;
			}
			else
			{
				cout << "插入失败！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			cout << "你想删除哪个逻辑位置上的数据？" << endl;
			int pos;
			cin >> pos;
			if (L.deleteData(pos))
			{
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "删除失败！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 4:
			L.printNode();
			system("pause");
			system("cls");
			break;
		default://这里除1~4的选项，其他选项都退出程序
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}