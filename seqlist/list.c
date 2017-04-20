#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
void InitList(pList *pplist)//初始化链表
{
	assert(pplist);
	*pplist = NULL;

}
pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		perror("malloc");//开辟失败
		return NULL;
	}
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}
void PushBack(pList *pplist,DataType d)//尾插
{	
	pNode cur = *pplist;
	pNode newNode = NULL;
	assert (pplist);
	newNode = BuyNode(d);
	if (cur==NULL)//链表为空
	{
		*pplist = newNode;
	}
	else
	{

		while (cur->next!=NULL)//链表不为空
		{
			cur = cur->next;//让cur一直往后走，直到最后一个
		}
		cur->next = newNode;//尾插
	}

}
void PrintList(pList plist)
{
	pNode cur = plist;
	if (plist ==NULL)
	{
		printf ("链表是空\n");
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
		printf ("链表为空\n");
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
void PushFront(pList *pplist,DataType d)//在头部增加一个
{
	pNode cur = *pplist;
	pNode newNode = BuyNode(d);
	assert (pplist);
	if (*pplist==NULL)//为空，直接添加
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
	if (cur==NULL)//无节点
	{
		printf ("链表为空\n");
		return;
	}
    if (cur->next==NULL)//一个节点
	{
		free(cur);
		cur = NULL;
		*pplist = NULL;
		//PopBack(pplist);
		return;
	}
	*pplist = cur->next;//多个节点，记住下一个地址
	free(cur);
	cur = NULL;
	
}
pNode Find(pList plist,DataType d)
{
	pNode cur = plist;
	//pNode pre = plist;
	if (plist==NULL)
	{
		printf ("链表为空\n");
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
		printf ("链表为空\n");
		return;
	}
	while(cur)
	{	
		pNode del = cur;
		if (cur->data==d)
		{
			if (cur==*pplist)//要删除的在第一个
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
void Insert(pList *pplist,pNode pos,DataType d)//在指定位置后面插入
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
void Erase(pList *pplist,pNode pos)//指定位置删除
{
	pNode cur = NULL;
	assert(pplist);
	if(pos==NULL)
	{
		printf ("为空\n");
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

void ReverseList(pList *pplist)//逆序
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
		printf ("一个元素\n");
		return;
	}
	cur = newHead->next;//cur指向第二个
	newHead->next = NULL;
	while(cur)
	{
		tmp =cur;
		cur = cur->next;
		tmp->next = newHead;//后一个有能力指向前一个
		newHead = tmp;
	}
	*pplist = newHead;

}
void BubbleSort(pList *pplist)//冒泡排序,定义一个尾指针
{
	pNode cur = *pplist;
	pNode tail = NULL;
	assert(pplist);
	if (cur==NULL)
	{
		printf ("为空\n");
		return;
	}
	if (cur->next==NULL)
	{
		printf ("只有一个元素\n");
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
void DelNotTailNode(pNode pos)//删除指定位置的下一个，不是尾结点
{
	pNode del = NULL;
	assert (pos->next!=NULL);
	del = pos->next;
	pos->data = pos->next->data;//把下一个数给前一个
	pos->next = pos->next->next;//让这个指针有能力指向下下一个
	free(del);//释放后要置空
	del = NULL;
}
void InsertFrontNode(pNode pos,DataType d)//在指定位置的前面插入一个,非头
{
	DataType tmp = 0;
	pNode newnode = BuyNode(d);
	newnode->next = pos->next;//newnode指向的next有能力指向pos指向的next就可以指向下一个
	pos->next = newnode;//pos有能力指向newnode
	tmp =pos->data;//交换两个数的值，就可以实现前加
	pos->data = pos->next->data;
	pos->next->data = tmp;

}
void ReversePrint(pList plist)//逆序打印链表
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
pNode FindMidNode(pList plist)//找到中间结点，遍历一次
{
	pNode fast = plist;      //运用快慢指针二倍的关系
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
void DelKNode(pList *pplist,int k)//删除链表的倒数第K个结点
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
pList Merge(pList l1,pList l2)//合并两个链表，合并后依然有序
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
pNode JosephCircle(pList *pplist,int num)//约瑟夫环
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

pNode CheckCircle(pList plist)//判断是否带环
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
	{
		return NULL;
	}
	while (fast&&fast->next)//链表长度不同停下的条件也不同
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)//相等则说明相遇了，带环，
		{
			return slow;
		}
	}
	return NULL;
}
int GetCircleLen(pNode meet)//求环的长度
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
pNode GetCircleEntry(pList plist,pNode meet)//求环的入口点
{
	pNode cur = plist;
	pNode fast = plist;
	pNode slow = plist;
	while(cur!=meet)//根据画图可分析出
	{
		cur  = cur->next;
		meet = meet->next;
	}
	return cur;
}
int CheckCross(pList l1,pList l2)//判断两个单链表是否相交
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
pComplexNode CrecteComplexNode(DataType d)//创建复杂链表的结点

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

pComplexNode CloneComplexNode(pComplexNode head)//复制复杂链表
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
	}//复制每个节点并插入到节点后
	cur = head;
	while(cur)
	{
		cur->next->random = cur->random->next;
		cur = cur->next->next;
	}//调整random指针
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