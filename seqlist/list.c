#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
void InitList(pList *pplist)//��ʼ������
{
	assert(pplist);
	*pplist = NULL;

}
pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		perror("malloc");//����ʧ��
		return NULL;
	}
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}
void PushBack(pList *pplist,DataType d)//β��
{	
	pNode cur = *pplist;
	pNode newNode = NULL;
	assert (pplist);
	newNode = BuyNode(d);
	if (cur==NULL)//����Ϊ��
	{
		*pplist = newNode;
	}
	else
	{

		while (cur->next!=NULL)//����Ϊ��
		{
			cur = cur->next;//��curһֱ�����ߣ�ֱ�����һ��
		}
		cur->next = newNode;//β��
	}

}
void PrintList(pList plist)
{
	pNode cur = plist;
	if (plist ==NULL)
	{
		printf ("�����ǿ�\n");
		return ;
	}
	
	while (cur)
	{
		printf ("%d--->",cur->data);
		cur = cur->next;
	}
	printf ("NULL\n");
}
void DestroyList(pList *pplist)
{
	pNode cur = *pplist;
	assert (pplist);
	while (cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		printf ("del ");
	}
	*pplist = NULL;

}
void PopBack(pList *pplist)
{
	pNode cur = *pplist;
	pNode del = *pplist;
	assert(pplist);
	if (*pplist==NULL)
	{
		printf ("����Ϊ��\n");
		return;
	}
	if(cur->next==NULL)
	{
		free(cur);
		*pplist = NULL;
		return ;
	}
	while (cur->next!=NULL)
	{
		del = cur;
		cur = cur->next;
	}
	free(cur);
	del->next = NULL;
}
void PushFront(pList *pplist,DataType d)//��ͷ������һ��
{
	pNode cur = *pplist;
	pNode newNode = BuyNode(d);
	assert (pplist);
	if (*pplist==NULL)//Ϊ�գ�ֱ�����
	{
		*pplist = newNode;
	}
	else 
	{
		newNode->next = cur;
		*pplist = newNode;
	}

}
void PopFront(pList *pplist)
{
	pNode cur = *pplist;
	assert(pplist);
	if (cur==NULL)//�޽ڵ�
	{
		printf ("����Ϊ��\n");
		return;
	}
    if (cur->next==NULL)//һ���ڵ�
	{
		free(cur);
		cur = NULL;
		*pplist = NULL;
		//PopBack(pplist);
		return;
	}
	*pplist = cur->next;//����ڵ㣬��ס��һ����ַ
	free(cur);
	cur = NULL;
	
}
pNode Find(pList plist,DataType d)
{
	pNode cur = plist;
	//pNode pre = plist;
	if (plist==NULL)
	{
		printf ("����Ϊ��\n");
		return NULL;
	}
	while((cur->data)!=d)
	{
		//pre = cur;
		cur = cur->next;
		
	}
	return cur;
}
void Remove(pList *pplist,DataType d)
{
	pNode cur = *pplist;
	pNode pre = NULL;

	assert(pplist);
	if (cur==NULL)
	{
		printf ("����Ϊ��\n");
		return;
	}
	while(cur)
	{	
		pNode del = cur;
		if (cur->data==d)
		{
			if (cur==*pplist)//Ҫɾ�����ڵ�һ��
				{
					*pplist = cur->next;
					free(del);
					del = NULL;
					return;
				}
			else
			{
				pre->next = cur->next;
				free(del);
				del = NULL;
				return;
			}

		}
		else 
		{
			pre = cur;
			cur = cur->next;
		}
		
	}

}
void RemoveAll(pList *pplist,DataType d)
{
	pNode cur = *pplist;
	pNode pre = NULL;
	assert(pplist);
	while(cur)
	{
		pNode del = cur;
		if(cur->data==d)
		{
			if (cur==*pplist)
			{
				cur = cur->next;
				PopFront(pplist);

			}
			else
			{
				pre->next = cur->next;
				free(del);
				del = NULL;
				cur = pre->next;

			}
		}
		else 
		{
			pre = cur;
			cur = cur->next;
		}
	}
	return ;
}
void Insert(pList *pplist,pNode pos,DataType d)//��ָ��λ�ú������
{
	pNode newNode = BuyNode(d);
	assert(pplist);
	assert(pos);
	if(pos==NULL)
	{
		PushBack(pplist,d);
		
	}
	else if(pos->next==NULL)
	{
		PushBack(pplist,d);
		
	}
	else 
	{	
		newNode->next = pos->next;
		pos->next = newNode ;
		return;
	}
}
void Erase(pList *pplist,pNode pos)//ָ��λ��ɾ��
{
	pNode cur = NULL;
	assert(pplist);
	if(pos==NULL)
	{
		printf ("Ϊ��\n");
		return ;
	}
	if (pos->next==NULL)
	{
		PopBack(pplist);
		return;
	}
	pos->data = pos->next->data;
	pos->next = pos->next->next;

}

void ReverseList(pList *pplist)//����
{
	pNode newHead = *pplist;
	pNode cur = NULL;
	pNode tmp = NULL;
	assert(pplist);
	if (*pplist==NULL)
	{
		printf ("kong\n");
		return;
	}
	if ((*pplist)->next==NULL)
	{
		printf ("һ��Ԫ��\n");
		return;
	}
	cur = newHead->next;//curָ��ڶ���
	newHead->next = NULL;
	while(cur)
	{
		tmp =cur;
		cur = cur->next;
		tmp->next = newHead;//��һ��������ָ��ǰһ��
		newHead = tmp;
	}
	*pplist = newHead;

}
void BubbleSort(pList *pplist)//ð������,����һ��βָ��
{
	pNode cur = *pplist;
	pNode tail = NULL;
	assert(pplist);
	if (cur==NULL)
	{
		printf ("Ϊ��\n");
		return;
	}
	if (cur->next==NULL)
	{
		printf ("ֻ��һ��Ԫ��\n");
		return;
	}
	while (cur!=tail)
	{
		while (cur->next!=tail)
		{
			if (cur->data>cur->next->data)
			{
				DataType tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
				tail = NULL;
			}
			cur= cur->next;
		}
		tail = cur;
		cur = *pplist;
	}
}
void DelNotTailNode(pNode pos)//ɾ��ָ��λ�õ���һ��������β���
{
	pNode del = NULL;
	assert (pos->next!=NULL);
	del = pos->next;
	pos->data = pos->next->data;//����һ������ǰһ��
	pos->next = pos->next->next;//�����ָ��������ָ������һ��
	free(del);//�ͷź�Ҫ�ÿ�
	del = NULL;
}
void InsertFrontNode(pNode pos,DataType d)//��ָ��λ�õ�ǰ�����һ��,��ͷ
{
	DataType tmp = 0;
	pNode newnode = BuyNode(d);
	newnode->next = pos->next;//newnodeָ���next������ָ��posָ���next�Ϳ���ָ����һ��
	pos->next = newnode;//pos������ָ��newnode
	tmp =pos->data;//������������ֵ���Ϳ���ʵ��ǰ��
	pos->data = pos->next->data;
	pos->next->data = tmp;

}
void ReversePrint(pList plist)//�����ӡ����
{
	pNode cur = plist;

	if(plist==NULL)
	{
		printf ("weikong\n");
		return;
	}
	if (plist->next==NULL)
	{
		printf ("%d ",plist->data);
		return;
	}
	ReversePrint(cur->next);
	printf ("%d ",cur->data);

}
pNode FindMidNode(pList plist)//�ҵ��м��㣬����һ��
{
	pNode fast = plist;      //���ÿ���ָ������Ĺ�ϵ
	pNode slow = plist;
	if (plist==NULL)
	{
		printf ("weikong\n");
		return NULL;
	}
	while (fast&&(fast->next))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void DelKNode(pList *pplist,int k)//ɾ������ĵ�����K�����
{
	pNode fast = *pplist;
	pNode slow = *pplist;
	if(*pplist==NULL)
	{
		printf ("kong\n");
		return;
	}
	while (fast&&(fast->next))
	{
		fast = fast->next;
		if (--k<=0)
		{
			slow = slow->next;
		}
	}
	if(k<=0)
	{
		pNode del = slow->next;
		slow->data = slow->next->data;
		slow->next = slow->next->next;
		free(del);
		del = NULL;
	}
}
pList Merge(pList l1,pList l2)//�ϲ����������ϲ�����Ȼ����
{
	pNode cur1 = l1;
	pNode cur2 = l2;
	pNode newhead = NULL;
	pNode tail = NULL;
	if ((l1==NULL)&&(l2==NULL))
	{
		return NULL;
	}
	if(l1==NULL)
	{
		return l2;
	}
	if (l2==NULL)
	{
		return l1;
	}
	
		if(cur1->data<=cur2->data)
		{
			newhead = cur1;
			cur1 = cur1->next;
			tail = newhead;
			//tail->next = Merge(cur1,cur2);

		}
		else 
		{
			newhead = cur2;
			cur2 = cur2->next;
			tail = newhead;
			//tail->next = Merge(cur1,cur2);
		}
		while(cur1&&cur2)
		{
			if (cur1->data<cur2->data)
			{
				tail->next = cur1;
				cur1 = cur1->next;
				tail = tail->next;
			}
			else
			{
				tail->next = cur2;
				cur2= cur2->next;
				tail = tail->next;
			}
			if (cur1==NULL)
			{
				tail->next = cur2;
			}
			if (cur2==NULL)
			{
				tail->next = cur1;
			}	
		}
		
	return newhead;
}
pNode JosephCircle(pList *pplist,int num)//Լɪ��
{
	pNode cur = *pplist;
	pNode del = NULL;
	assert(pplist);
	while(1)
	{
		int count = num;
		if(cur == cur->next)
		{
			break;
		}
		while(--count)
		{
			cur = cur->next;

		}	
		printf ("%d ",cur->data);
		del = cur->next;
		cur->data = cur->next->data;
		cur->next = cur->next->next;
		free(del);
		del = NULL;
	}
	return cur;
}

pNode CheckCircle(pList plist)//�ж��Ƿ����
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
	{
		return NULL;
	}
	while (fast&&fast->next)//�����Ȳ�ͬͣ�µ�����Ҳ��ͬ
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)//�����˵�������ˣ�������
		{
			return slow;
		}
	}
	return NULL;
}
int GetCircleLen(pNode meet)//�󻷵ĳ���
{

	pNode cur = meet;
	int count = 0;
	do 
	{
		count++;
		cur = cur->next;
	} while (cur!=meet);
	return count;
}
pNode GetCircleEntry(pList plist,pNode meet)//�󻷵���ڵ�
{
	pNode cur = plist;
	pNode fast = plist;
	pNode slow = plist;
	while(cur!=meet)//���ݻ�ͼ�ɷ�����
	{
		cur  = cur->next;
		meet = meet->next;
	}
	return cur;
}
int CheckCross(pList l1,pList l2)//�ж������������Ƿ��ཻ
{
	pNode cur1 = l1;
	pNode cur2 = l2;
	if((l1==NULL)||(l2==NULL))
	{
		return 0;
	}
	while(l1->next)
	{
		l1 = l1->next;
	}
	while (l2->next)
	{
		l2 = l2->next;
	}
   return l1 == l2;
}
pComplexNode CrecteComplexNode(DataType d)//������������Ľ��

{
	pComplexNode newNode = (pComplexNode)malloc(sizeof(ComplexNode));
	if (newNode == NULL)
	{
		perror("malloc");
		return NULL;
	}
	newNode->D = d;
	newNode->next = NULL;
	newNode->random = NULL;
	return newNode;

}
void PrintComplexList(pComplexNode head)
{
	pComplexNode cur = head;
	while(cur)
	{
		printf ("%d-->",cur->D);
		printf ("random-->[%d]--->next",cur->random->D);
		cur = cur->next;
	}
	printf ("\n");
}

pComplexNode CloneComplexNode(pComplexNode head)//���Ƹ�������
{
	pComplexNode cur = head;
	pComplexNode tmp = NULL;
	pComplexNode copy = NULL;
	pComplexNode tail = NULL;
	while(cur)
	{
		pComplexNode newnode = CrecteComplexNode(cur->D);
		tmp = cur;
		cur= cur->next;
		newnode->next = cur;
		tmp->next = newnode;
	}//����ÿ���ڵ㲢���뵽�ڵ��
	cur = head;
	while(cur)
	{
		cur->next->random = cur->random->next;
		cur = cur->next->next;
	}//����randomָ��
	cur = head;
	copy= cur->next;
	tail = copy;
	while(tail->next)
	{
		tail->next = tail->next->next;
		cur->next = tail->next;
		cur = cur->next;
		tail = tail->next;
		cur->next = NULL;
		return copy;
	}

	

}