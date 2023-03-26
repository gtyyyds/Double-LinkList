#include<iostream>//���������
using namespace std;//��׼�����ռ�
class ListNode//����˫����ڵ���
{
public:
	ListNode() {};//�޲ι���
	ListNode(int data)//�вι���
	{
		this->m_data = data;//��ֵ
	}
	friend class DLinkList;//˫����������Ԫ������˫��������Է��ʽڵ����˽������
private://˽������
	int m_data;//������
	ListNode* prior;//ָ���ϸ��ڵ�
	ListNode* next;//ָ���¸��ڵ�
};
class DLinkList//˫������
{
public:
	DLinkList()//˫�����޲ι���
	{
		this->initList();//��������ʱ���Զ���ʼ��
	}
	void initList();//��Ա��������ʼ��
	bool insertData(int pos, int data);//��������
	bool deleteData(int pos);//ɾ������
	void printNode();//��ӡ˫����
private://˽������
	ListNode* head;//ͷ�ڵ�
};
void DLinkList::initList()//˫�����������µĳ�Ա��������ʼ��˫����
{
	head = new ListNode;//�ڶ�������һ���½ڵ���Ϊͷ�ڵ㣬���Ұ�ͷ�ڵ�ָ�뷵�ظ�head
	head->next = NULL;//ͷ�ڵ�ĺ��ָ��
	head->prior = NULL;//ͷ�ڵ��ǰ��ָ��
}
bool DLinkList::insertData(int pos, int data)//���߼�λ�õ�ǰ�����ĳ������
{
	int j = 0;//������
	ListNode* p = head;//��ͷ�ڵ�ĵ�ַ����p����
	while (p && j < pos - 1)//�������Ϊ�գ����ߴ����߼�λ��
	{
		p = p->next;//�ƽ�
		j++;//����
	}
	if (!p || j > pos - 1)//�������Ϊ���ˣ�����λ�ò�����ֱ�ӷ���ʧ��
	{
		return false;
	}
	//�ص㣺����pָ���Ҫ����ڵ��ǰ�ڵ�ĵ�ַ
	ListNode* s = new ListNode;//����һ���½ڵ��ڶ��������ҰѸýڵ�ĵ�ַ���ظ�s
	s->next = p->next;//���´����Ľڵ��next��������ԭ����p->next������֮�󣬸ýڵ���s�ĺ󷽣�����Ҫ��p->next����s->next
	p->next = s;//�������s�ڵ��ǰ����next��ԭ����p->next,�ı�Ϊָ��s
	s->prior = p;//���½ڵ��prior���в�����ָ������ǰ��
	p->next->prior = s;//���½ڵ�ĺ���ڵ��prior���в�����ָ��s
	s->m_data = data;//��������
	return true;//�ɹ�����
}
bool DLinkList::deleteData(int pos)//ɾ������
{
	int j = 0;//������
	ListNode* p = head;//��p����head���в���
	while (p && j < pos - 1)//�������Ϊ�գ����ߴ����߼�λ��
	{
		p = p->next;//�ƽ�
		j++;//����
	}
	if (!p || j > pos - 1)//�������Ϊ���ˣ�����λ�ò�����ֱ�ӷ���ʧ��
	{
		return false;
	}
	//�ص㣺����pָ�����Ҫɾ���ڵ��ǰ�ڵ�ĵ�ַ
	ListNode* q = p->next;
//	p->next->next->prior = p;
	if(q->next!=NULL)//���ɾ�����һ���ڵ㣬����Ҫ�������ڵ��prior
	q->next->prior = p;//ɾ������Ҫ��ɾ���ڵ�ĺ�һ���ڵ��ǰ�����в���
	p->next = q->next;//ɾ������Ҫ��ɾ���ڵ��ǰһ���ڵ�ĺ�̽��в���
	delete q;
	return true;
}
void DLinkList::printNode()//��ӡ����
{
	ListNode* L = head->next;//ָ����Ԫ�ڵ�
	while (L != NULL)
	{
		cout << L->m_data << " ";//��ӡ����
		L = L->next;//�ƽ�
	}
	cout << endl;//����
}
void showMenu()//�˵�
{
	cout << "  ***********************" << endl;
	cout << "  ***  1����ʼ������  ***" << endl;
	cout << "  ***  2��ǰ��������  ***" << endl;
	cout << "  ***  3��ɾ��ĳ����  ***" << endl;
	cout << "  ***  4������˫����  ***" << endl;
	cout << "  ***  0����      ��  ***" << endl;
	cout << "  ***********************" << endl;
	cout << "  ���������ѡ�";
}
int main()//������
{
	DLinkList L;//�����������
	int select;
	while (true)//��ѭ�����û���ȷ�������˳�
	{
		showMenu();
		cin >> select;//����ѡ��
		switch (select)
		{
		case 1:
			L.initList();
			cout << "��ʼ���ɹ���" << endl;
			system("pause");//�����������
			system("cls");//����
			break;
		case 2:
		{
			cout << "�����ڵڼ�������ǰ�������ݣ�" << endl;
			int pos, data;
			cin >> pos;
			cout << "�������ʲô���ݣ�" << endl;
			cin >> data;
			if (L.insertData(pos, data))
			{
				cout << "����ɹ���" << endl;
			}
			else
			{
				cout << "����ʧ�ܣ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			cout << "����ɾ���ĸ��߼�λ���ϵ����ݣ�" << endl;
			int pos;
			cin >> pos;
			if (L.deleteData(pos))
			{
				cout << "ɾ���ɹ���" << endl;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�" << endl;
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
		default://�����1~4��ѡ�����ѡ��˳�����
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	return 0;
}