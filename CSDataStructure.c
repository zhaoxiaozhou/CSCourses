/******************/
/*CSDataStructure*/
/*1.2 Maximum Subsequence Sum*/
/*Method 1*/
#include<stdio.h>
#define MAXN 10000

int MaxSubseqSum(int List[], int N);


int main()
{
	int Array[MAXN];
	int n;
	int i;
	int max;


	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&Array[i]);
	}
	MaxSubseqSum(Array, n);
	return 0;

}


int MaxSubseqSum(int List[], int N)
{
	int thissum;
	int maxsum;
	int thissum1;
	int maxsum1;
	int i;
	int lefttemp;
	int left = -1;
	int right = -1;
	lefttemp = 0;

	thissum = 0;
	maxsum = -1;


	for(i = 0; i < N; i++)
	{
		thissum += List[i];
		if (thissum < 0)
		{
			thissum = 0;
			lefttemp = i + 1;
		}
		else
		{
			if(thissum > maxsum)
			{
				maxsum = thissum;
				left = lefttemp;
				right = i;
			}
			/*still don't understand the judgement condition*/
			else if(thissum == maxsum && left + right > lefttemp + i)
			{
				left = lefttemp;
				right = i;
			}
		}
	}
	if (left == -1)
	{
		printf("0 %d %d", List[0],List[N-1]);
	}
	else
	{
		printf("%d %d %d",maxsum, List[left],List[right]);
	}
	return maxsum;
}

/*Method 2*/
//Easy to understand
//Take more into consideration
//A very good algorithm
#include<stdio.h>
#define MAXN 10000

int MaxSubseqSum(int List[], int N);


int main()
{
	int Array[MAXN];
	int n;
	int i;
	int max;


	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&Array[i]);
	}
	MaxSubseqSum(Array, n);
	return 0;

}


int MaxSubseqSum(int List[], int N)
{
	int thissum = 0;
	int maxsum = 0;

	int i;
	int lefttemp = 0;
	int left = 0;
	int right = 0;
	int flag = 0;

	for(i = 0; i < N; i++)
	{
		thissum += List[i];
		if (thissum < 0)
		{
			thissum = 0;
			lefttemp = i + 1;
		}
		else if(thissum > maxsum)
		{
			
			maxsum = thissum;
			left = lefttemp;
			right = i;
			
		}
		else if(thissum == 0 )
		{
			if(maxsum == 0 && flag == 0)
			{
				left = right =i;
				flag = 1;
			}
			
		}  
		
	}

	if (maxsum == 0 && flag == 0)
	{
		printf("0 %d %d", List[0],List[N-1]);
	}
	else
	{
		printf("%d %d %d",maxsum, List[left],List[right]);
	}
	return maxsum;
}

/*Chapter 2 the foundation of Data Structure*/
/*2.1 A Simple Calculator*/
/*all four kinds of operation have the same priority*/

#include <stdio.h>
int main()
{
	int Sum;
	int X;
	char Op;
	scanf("%d %c", &Sum, &Op);
	while(Op != '=')
	{
		scanf("%d", &X);
		switch(Op)
		{
			case '+':
				Sum += X;
				break;

			case '-':
				Sum -= X;
				break;

			case '*':
				Sum *= X;
				break;

			case '/':
				if(X == 0)
				{
					printf("除法分母为0\n");
					return 0;
				}
				Sum /= X;
				break;
			default :
				printf("输入非法");
				return 0;
		}
		scanf("%c", &Op);
	}

	printf("%d\n", Sum);
	return 0;
}

/*联合体存储是按照最大元素的存储空间来计算的*/
#include <stdio.h>

int main()
{
	union key
	{
		int k;
		char ch[2];
	}u;

	u.k = 65537;
	printf("The size of int is: %d\n", sizeof(int));
	printf("The size of char is: %d\n",sizeof(char));
	printf("The vaule of k is: %d\n", u.k);
	printf("The value of ch[0] is: %d ch[1] is: %d\n", u.ch[0], u.ch[1]);
	return 0;

}

/*链表的建立，头部插入*/
#include <stdio.h>
#include<stdlib.h>

#define ElementType int
typedef struct Node
{
	ElementType Data;
	struct Node *Next;
}LNode, *LinkList;
/*链表的建立，头部插入方法*/
void Create1(LinkList L) 
{
	LinkList Rear, S;
	int e;
	L = (LinkList) malloc (sizeof(LNode));
	L->Next = NULL;
	Rear = L;
	scanf("Please enter the element:%d", &e);
	while(e != 0)
	{
		S = (LinkList) malloc(sizeof(LNode));
		S->Data = e;
		S->Next = NULL;
		Rear->Next = S;
		Rear = S;
		scanf("%d",&e);
	}

}

void Output(LinkList L)
{
	LinkList S = L->Next;
	printf("Now i am going to output all the data in the link list:");
	while(S)
	{
		printf("Data:%d\n",S->Data);
		S = S->Next;
	}
	printf("The end");
}

int main()
{
	LinkList L;
	L = NULL;
	Create1(L);
	Output(L);
	return 0;
}


/*function 1*/
/*In this function ,the total movement of the number is N*M*/
#include<stdio.h>
#define MAXN 100
void Shift(int Array[], int ArrayLength, int Shiftnum);
int main()
{
	int N;
	int M;
	int i;
	int Num[MAXN];

	scanf("%d %d",&N,&M);
	/*When M is larger than N, take the remainder*/
	M %= N;
	for(i = 0;i < N;i++)
	{
		scanf("%d", &Num[i]);
	}

	Shift(Num, N, M);

	for(i = 0; i < N;i++)
	{
		printf("%d ", Num[i]);
	}
	return 0;

}

/*Array ArrayLength shift to right by shiftnum*/
void Shift(int Array[], int ArrayLength, int Shiftnum)
{
	int temp;
	int j;
	int k;
	for (k = 0; k < Shiftnum; k++)
	{
		temp = Array[ArrayLength - 1];
		for(j = ArrayLength - 2 ; j >= 0; j--)
		{
			Array[j + 1] = Array[j];
		}
		Array[0] = temp;
	}

}

/*function 2*/
/*The total movement of the number is 3*N */
#include<stdio.h>
#define MAXN 100
/*The operation of nor compelete the exchange of a and b*/
/*HighLight 1*/
#define Swap(a, b) a = a^b, b = b^a, a = a^b;

void Shift(int Array[], int ArrayLength, int Shiftnum);
int main()
{
	int N;
	int M;
	int i;
	int Num[MAXN];

	while(1)
	{
		scanf("%d %d",&N,&M);
		/*When M is larger than N, take the remainder*/
		M %= N;
		for(i = 0;i < N;i++)
		{
			scanf("%d", &Num[i]);
		}

		Shift(Num, N, M);

		for(i = 0; i < N;i++)
		{
			printf("%d ", Num[i]);
		}
		printf("\n");
		
	}
	return 0;

}

/*Array ArrayLength shift to right by shiftnum*/
/*HighLight 1*/
void Shift(int Array[], int ArrayLength, int Shiftnum)
{
	/*it is difficult to understand when using only one*/
	/*loop parameter i, it is easier when use two parameter*/
	if (0)
		{
		int i;
		for(i = 0; i < ArrayLength/2 ; i++)
		{
			Swap(Array[i], Array[ArrayLength-1-i]);
		}

		for(i = 0; i < Shiftnum/2; i++)
		{
			Swap(Array[i], Array[Shiftnum-1-i]);
		}

		/*the change of the number in the last is easy to make mistake*/
		for(i = Shiftnum; i < (ArrayLength + Shiftnum)/2; i++)
		{
			Swap(Array[i], Array[ArrayLength-1-(i - Shiftnum)]);
		}
	}
	else
	{
		int i, j;
		for(i = 0,j = ArrayLength-1; i < j; i++, j--)
		{
			Swap(Array[i], Array[j]);
		}
		for(i = 0,j = Shiftnum-1; i < j; i++,j--)
		{
			Swap(Array[i], Array[j]);
		}
		for(i = Shiftnum,j = ArrayLength-1; i < j; i++,j--)
		{
			Swap(Array[i], Array[j]);
		}
	}

}

/*function 3*/
/*The total movement of the number less than 2*N */
#include<stdio.h>
#define MAXN 100

void Shift(int Array[], int ArrayLength, int Shiftnum);
int main()
{
	int N;
	int M;
	int i;
	int Num[MAXN];

	while(1)
	{
		scanf("%d %d",&N,&M);
		/*When M is larger than N, take the remainder*/
		M %= N;
		for(i = 0;i < N;i++)
		{
			scanf("%d", &Num[i]);
		}

		Shift(Num, N, M);

		for(i = 0; i < N;i++)
		{
			printf("%d ", Num[i]);
		}
		printf("\n");
		
	}
	return 0;

}

/*Array ArrayLength shift to right by shiftnum*/
/*HighLight 1*/
void Shift(int Array[], int ArrayLength, int Shiftnum)
{
	int i;
	int j;
	int temp;
	temp = Array[0];
	i = 0;

	while(i != ((0 - Shiftnum + ArrayLength)%ArrayLength))
	{
		j = (i - Shiftnum + ArrayLength) % ArrayLength;
		Array[i] = Array[j];
		i = j;
	}

	Array[(0 - Shiftnum + ArrayLength)%ArrayLength] = temp;

}


#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
	ElementType Data;
	PtrToNode Next;
};
typedef  PtrToNode List;

List Read()
{
	int n;
	int i;
	/*建立头结点，头结点的目的是为了函数返回整个链表*/
	List Temp;
	Temp = (List) malloc(sizeof(struct Node));
	Temp->Next = NULL;

	List Rear ;
	Rear = Temp;
	ElementType x;

	scanf("%d", &n);
	if(n == 0)
	{
		return NULL;
	}

	for(i = 0; i < n ; i++)
	{
		List p;
		p = (List)malloc(sizeof(struct Node));
		scanf("%d",&x);
		p->Data = x;
		p->Next = NULL; /*这里一定要把p下一个指定为NULL,否则链表不会停止*/
		Rear->Next = p;
		Rear = p;
	}
	/*返回头结点就是返回整个链表*/
	return Temp;
} 

void Print(List L)
{
	List S;
	if(L->Next == NULL)
	{
		printf("NULL\n");
	}
	S = L->Next; /*因为表头为一个空指针，所以真正的第一个是下一个！*/
	while(S != NULL)
	{
		printf("%d->",S->Data);
		S = S->Next;
	}
}

List Merge(List L1, List L2)
{

	/*首先要申请一个头结点，并且把头结点下一个结点指向空*/
	/*头结点的目的是为了最后的返回*/
	List S;
	S = (List)malloc(sizeof(struct Node));
	S->Next = NULL;

	/*为链表定义一个尾结点，用于结点的插入*/
	List Rear;
	Rear = S;
	/*还是不明白为什么要申请两个List结点，指向L1，L2，直接用不可以吗*/

	List p = L1->Next;    /*把p, L2的空的头结点去掉*/
	List q = L2->Next;	  /*把p, L2的空的头结点去掉*/

	while(p!=NULL&&q!=NULL)
	{	
		/*这里不用再临时构造一个结点，存储p和q中比较大的结点，把Rear指向较大的结点*/
		//List Temp;
		//Temp = (List)malloc(sizeof(struct Node));

		if(p->Data < q->Data)
		{
			//Temp->Data = p->Data;
			Rear->Next = p;
			Rear = Rear->Next;   /*这一点非常重要，把Rear向后面移动*/
			p = p->Next;

		}
		else
		{
			Rear->Next = q;
			Rear = Rear->Next;
			q = q->Next;
			
		}
	}

	Rear->Next = NULL;	

	if(p == NULL)
	{
		Rear->Next = q;
	}
	if(q == NULL)
	{
		Rear->Next = p;
	}


	L1->Next = NULL;
	L2->Next = NULL;
	
	return S;
}


List ReturnNull(List L)
{
	while(L->Next != NULL)
	{
	L = L->Next;
	}
	return L;
}

int main()
{
	List L1,L2,L;
	L1 = Read();
	printf("List L1 Complete\n");
	Print(L1);
	printf("\n");

	L2 = Read();
	printf("List L2 Complete\n");
	Print(L2);
	printf("\n");
	L = Merge(L1, L2);

	printf("Merge of list L1 and L2:\n");
	Print(L);

	printf("\n");
	Print(L1);
	printf("\n");
	Print(L2);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct PolyNode *Polynomial;
struct PolyNode
{
	ElementType Coef;
	ElementType Expon;
	Polynomial Link;
};

void Attach(int c, int e, Polynomial * PRear);
Polynomial ReadPoly();
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult();
void PrintPoly(Polynomial L);

int main()
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	//PrintPoly(P1);
	PP = Mult(P1,P2);
	PrintPoly(PP);
	
	PS = Add(P1,P2);
	PrintPoly(PS);


	return 0;
}

void Attach(int c, int e, Polynomial * PRear)/*这里是指针的指针啊*/
{
	/*申请一个空的结点*/
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Coef = c;
	P->Expon = e;
	P->Link = NULL;
	/*把该结点P放在Rear最后*/
	(*PRear)->Link = P;
	/*修改尾结点*/
	(*PRear) = P;	
}


Polynomial ReadPoly()
{	
	int length;
	int Coef;
	int Expon;

	Polynomial P, Rear, t;
	scanf("%d", &length);	

	/*链表头空结点*/
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Link = NULL;
	Rear = P;

	
	while(length--)
	{	
		scanf("%d %d", &Coef, &Expon);
		/*输入注意如果出现系数为0的话去掉！！*/
		if(Coef != 0)
			Attach(Coef,Expon,&Rear);
	}
	/*把链表头部的临时的空结点删除掉*/
	t = P;
	P = P->Link;
	free(t);
	return P;
}

void PrintPoly(Polynomial L)
{
	int flag = 0;
	//L = L->Link;
	
	if(!L)
	{
		printf("0 0\n");
		return;
	}
	/*非零项不需要输出*/
	while(L)
	{
		if(!flag)
		{
			flag = 1;
		}
		else
		{
			printf(" ");
		}

		printf("%d ",L->Coef);
		printf("%d",L->Expon);	

		L = L->Link;
	}
	printf("\n");
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial P, t1, t2, Rear;
	t1 = P1;
	t2 = P2;
	/*申请一个空的头结点*/
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Link = NULL;
	Rear = P;

	while(t1&&t2)
	{
		if(t1->Expon == t2->Expon)
		{
			/*系数为0项目要去掉*/
			if((t1->Coef + t2->Coef)!=0)
			{
				Attach((t1->Coef + t2->Coef),t1->Expon,&Rear);
			}			
			t1 = t1->Link;
			t2 = t2->Link;
		}
		else if(t1->Expon > t2->Expon)
		{
			Attach(t1->Coef,t1->Expon,&Rear);
			t1 = t1->Link;

		}
		else
		{
			Attach(t2->Coef,t2->Expon,&Rear);
			t2 = t2->Link;
		}
	}
	while(t1)
	{
		Attach(t1->Coef,t1->Expon,&Rear);
		t1 = t1->Link;
	}
	while(t2)
	{
		Attach(t2->Coef,t2->Expon,&Rear);
		t2 = t2->Link;
	}

	t2 = P;
	P = P->Link;
	free(t2);
	return P;

}


Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial t1, t2, P, Rear,t;
	ElementType c,e;

	if(!P1 || !P2) /*判断P1， P2是否为空结点*/
	{
		return NULL;
	}
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	Rear = P;

	while(t2)/*用P1的第一项先乘以P2的每一项,得到P*/
	{
		Attach(t1->Coef*t2->Coef, t1->Expon+t2->Expon,&Rear);
		t2 = t2->Link;
	}
	t1 = t1->Link;
	while(t1)
	{
		t2 = P2;
		Rear = P;
		while(t2)
		{	
			c = t1->Coef * t2->Coef;
			e = t1->Expon + t2->Expon;

			while(Rear->Link && Rear->Link->Expon > e)
			{
				Rear = Rear->Link;
			}
			if(Rear->Link && Rear->Link->Expon == e)
			{
				if(Rear->Link->Coef +c)
				{
					Rear->Link->Coef += c;
				}
				else
				{
					t = Rear->Link;
					Rear->Link = t->Link;
					free(t);
				}
			}
			else
			{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->Coef = c;
				t->Expon = e;
				t->Link = Rear->Link;
				Rear->Link = t;
				Rear = Rear->Link;
			}

			t2 = t2->Link;

		}
		t1 = t1->Link;
	}
	/*表头的空结点去掉*/
	t2 = P;
	P = P->Link;
	free(t2);

	return P;
}


//PTA 2.3 Reversing Linked List

#include<stdio.h>
#include<stdlib.h>
//#include<algorithm>    ///使用到reverse 翻转函数 

#define max 100005

typedef struct Node *PtrToNode;
struct Node
{
    int data;
    int next;    
};

struct Node NodeList[max];
/*用来存储修正过顺序的结点*/
int list[max];
void reverse(int *i, int *j);
int main()
{
    int FirstAddress;
    int Address;
    int length;
    int K;
    // int loop;
    int i;
    int j;
    

    scanf("%d %d %d ", &FirstAddress, &length, &K);

    for(i = 0;i < length;i ++)
    {
        scanf("%d", &Address);
        scanf("%d", &NodeList[Address].data);
        scanf("%d", &NodeList[Address].next);
        // printf("%d ", NodeList[Address].data);
        // printf("%d\n", NodeList[Address].next);
    }

    int m = 0;
    int p = FirstAddress;
    while(p != -1)
    {
        list[m++] = p;
        p = NodeList[p].next;
    }

    // for(loop = 0;loop < length;loop++)
    // {
    //     printf("%d ", list[loop]);
    // }

    // printf("\n");

    // printf("Program Here!!");

    
    /*每k个结点翻转*/
    /*不理解啊*/
    // i = 0;
    // while(i + K <= j)
    // {
    //     reverse(&list[i], &list[i+K]);
    //     i = i + K;
    // }

    int around = length /K;
    for(i = 0; i< around ;i++)
    {
        int start = i * K;
        int end = (i+1) * K - 1;
        for(j = 0 ; j< K/2; j++)
        {
            reverse(&list[start+j], &list[end-j]);
        }
        
    }

    for(i = 0;i < length - 1; i++)
    {
        printf("%05d %d %05d\n", list[i], NodeList[list[i]].data, list[i+1]);
    }
    printf("%05d %d -1", list[i], NodeList[list[i]].data);

    return 0;

}

void reverse(int * i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

//04-树5 Root of AVL Tree（25 分）
//
#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct AVLTreeNode *AVLTree;
struct AVLTreeNode
{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int PostOrderGetHeight(AVLTree BT);
int MAX(int A, int B);
AVLTree AVL_Insert(ElementType X, AVLTree T);
AVLTree SingleLeftRightRotation(AVLTree A);
AVLTree SingleRightLeftRotation(AVLTree A);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);

int main()
{
	int i;
	int N;
	int X;
	scanf("%d", &N);
	AVLTree Tree;
	Tree = NULL;
	for(i = 0;i < N;i++)
	{
		scanf("%d", &X);
		Tree = AVL_Insert(X, Tree);
	}
	printf("%d",Tree->Data);
	return 0;
}

AVLTree AVL_Insert(ElementType X, AVLTree T)
{
	if(!T)
	/*空树*/
	{
		T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
		T->Data = X;
		T->Left = T->Right = NULL;

	}
	else if(X < T->Data)
	{
		T->Left = AVL_Insert(X, T->Left);
		if(PostOrderGetHeight(T->Left)-PostOrderGetHeight(T->Right)==2)
		{
			if(X < T->Left->Data)
			{
				T = SingleLeftRotation(T);
			}
			else
			{
				T = SingleLeftRightRotation(T);
			}
		}

	}
	else if(X > T->Data)
	{
		T->Right = AVL_Insert(X, T->Right);
		if(PostOrderGetHeight(T->Left)-PostOrderGetHeight(T->Right)==-2)
		{
			if(X > T->Right->Data)
			{
				T = SingleRightRotation(T);
			}
			else
			{
				T = SingleRightLeftRotation(T);
			}

		}
	}
	T->Height = MAX(PostOrderGetHeight(T->Left) , PostOrderGetHeight(T->Right));
		        

	return T;

}

int PostOrderGetHeight(AVLTree BT)
{
    int HL, HR, MaxH;
    if(BT)
    {
        HL = PostOrderGetHeight(BT->Left);
        HR = PostOrderGetHeight(BT->Right);
        MaxH = (HL > HR)? HL : HR;
        return MaxH + 1;
    }
    else
        return 0;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = MAX(PostOrderGetHeight(A->Left),PostOrderGetHeight(A->Right))+1;
	B->Height = MAX(PostOrderGetHeight(B->Right), A->Height);
	return B;
}
AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = MAX(PostOrderGetHeight(A->Left),PostOrderGetHeight(A->Right))+1;
	B->Height = MAX(PostOrderGetHeight(B->Left), A->Height);
	return B;

}
AVLTree SingleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}
AVLTree SingleLeftRightRotation(AVLTree A)
{
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}

int MAX(int A, int B)
{
	return (A>B)?A:B;
}

//05-树7 最小堆中的路径
#include<stdio.h>
#include<stdlib.h>

#define MAXN 1001
#define MINH -10001

int H[MAXN], size;

/*堆建立函数*/
void Create()
{
	size = 0;
	H[0] = MINH;
	/*设置岗哨*/
}

/*最小堆的插入*/
void Insert(int X)
{
	if(size >= MAXN)
	{
		printf("Heap is full");
		return;
	}
	int i;
	for(i = ++size; H[i/2] > X; i /= 2)
	{
		H[i] = H[i/2];
	}
	H[i] = X;
}

int main()
{
	int N;
	int M;
	int i;
	int X;

	scanf("%d %d",&N, &M);
	Create();
	for(i = 0; i < N;i++)
	{
		scanf("%d",&X);
		Insert(X);
	}

	int j;
	for(i = 0; i < M; i++)
	{
		scanf("%d", &j);
		printf("%d", H[j]);
		while(j > 1)
		{
			j /= 2;
			printf(" %d", H[j]);
		}
		printf("\n");
	}

	return 0;
}



/*06-图1 列出连通集（25 分）*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxVertexNum 100
typedef int WeightType;
typedef int DataType;
typedef int Vertex;

char B[] = {'B', 'F', 'S'};     // 用于选择BFS遍历  
char D[] = {'D', 'F', 'S'};     // 用于选择DFS遍历  

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv; //顶点数
	int Ve; //边数
	WeightType G[MaxVertexNum][MaxVertexNum];

	//DataType Data[MaxVertexNum];  //如果顶点有其它含义，不是0-maxvertexnum-1
};//存储顶点的数据
typedef PtrToGNode MGraph;  //以邻接矩阵存储的图

//初始化一个有VertexNum顶点数，但是没有边的图
MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ve = 0;

	for(V = 0; V < VertexNum; V++)
		for(W = 0; W < VertexNum; W++)
		{
			Graph->G[V][W] = 0;
		}
	return Graph;
}


typedef struct ENode *PtrToENode;
struct ENode
{
	Vertex V1,V2; /*有向边*/
	WeightType Weight; //权重
};
typedef PtrToENode Edge;

//插入一条边
void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = 1;
	//如果是一个无向图
	Graph->G[E->V2][E->V1] = 1;
}

MGraph BuildGraph()
{
	MGraph Graph;
	int Nv;
	int i;
	//Vertex V;
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);

	scanf("%d", &(Graph->Ve));

	if(Graph->Ve != 0)
	{
		Edge E = (Edge)malloc(sizeof(struct ENode));
		for(i = 0; i<Graph->Ve; i++)
		{
			//scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E); 
		}
	}

	/*如果顶点有数据，读入数据*/
	// for(V = 0; V < Graph->Nv ; V ++)
	// {
	// 	scanf("%c", &(Graph->Data[V]));
	// }

	return Graph;
}

int visited[MaxVertexNum];

/*Depth First Search*/
void DFS(int v, MGraph graph)
{
	visited[v] = 1;
	printf(" %d",v);
	/*从第V个顶点出发访问图*/
	for(int i=0; i < graph->Nv; i++)
	{
		if(!visited[i] && graph->G[v][i])
		{
			DFS(i, graph);
		}
	}
}


/*breadth first search*/
void BFS(int v, MGraph graph)
{
	int Q[graph->Nv];//创建一个队列
	int front = -1;
	int rear = -1;
	Q[++rear] = v;
	visited[v] = 1;
	while(front < rear)
	{
		int de = Q[++front]; //出队
		printf(" %d",de);
		for(int i = 0; i< graph->Nv; i++)
		{
			if(visited[i] !=1 && graph->G[de][i])
			{
				visited[i] = 1;
				Q[++rear] = i; //入队操作
			}
		}

	}
}

void Show(MGraph graph)
{
	for(int i=0; i < graph->Nv; i++)
	{
		for(int j=0; j < graph->Nv; j++)
		{
			printf("%d", graph->G[i][j]);
		}
		printf("\n");
	}

}

void Print(MGraph graph, char ch[])
{
	for(int i = 0; i < graph->Nv; i++)
	{
		visited[i] = 0;  /*初始化visited数组*/
	}

	for(int i=0; i < graph->Nv; i++)
	{
		if(!visited[i])
		{
			printf("{");
			if(!strcmp(ch,B))
				BFS(i, graph);
			else if(!strcmp(ch,D))
				DFS(i, graph);
			printf(" }\n");
		}
	}
}

int main()
{
	MGraph graph = BuildGraph();
	Show(graph);
	Print(graph,D);
	Print(graph,B);
}

/*06-图2 Saving James Bond - Easy Version*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXN 100

typedef struct Node
{
 	int  X;
 	int Y;
}Coord; /*Coordinate 坐标*/
Coord List[MAXN];

void Print(Coord G[], int size);
int IsSafe(int V);
int Jump(int V, int W);
int FirstJump(int V);
int DFS(int V);
void Save007();
/*这里用指针数组并不对，具体还要分析一下子*/


int visited[MAXN];
int Number;  /*the number of crocodile*/
int Distance; /*the distance james bond can jump*/
const double ISLAND_RADIUS = 15.0 / 2; /*the diameter of the island is 15*/

int main()
{
	scanf("%d %d", &Number, &Distance);

	for(int i = 0; i < Number; i++)
	{
		visited[i] = 0;
		scanf("%d",&List[i].X);
		scanf("%d",&List[i].Y);
	}
	//Print(List, Number);
	//printf("%d" ,Jump(1,2));
	Save007();

	return 0;
}

void Save007()
{
	int save = 0;
	for(int i = 0; i < Number; i++)
	{
		if(!visited[i] && FirstJump(i))
		{
			save = DFS(i);
			if(save)
			{
				break;
			}	
		}
	} 
	if(save)
		printf("Yes\n");
	else
		printf("No\n");

}

void Print(Coord G[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", G[i].X);
		printf("%d\n", G[i].Y);
	}
}

int FirstJump(int V)
{
	double Z;
	Z = sqrt(List[V].X * List[V].X + List[V].Y * List[V].Y);
	return Z <= (Distance + ISLAND_RADIUS) ? 1 : 0;
}

int Jump(int V, int W)
{
	double Z;
	Z = sqrt((List[V].X - List[W].X)*(List[V].X - List[W].X) + (List[V].Y - List[W].Y)*(List[V].Y - List[W].Y));
	return Distance >= Z ? 1 : 0;
}

int IsSafe(int V)
{
	return ((50 - abs(List[V].X)) <= Distance || (50 - abs(List[V].Y)) <= Distance)? 1 : 0;
}

int DFS(int V)
{
	visited[V] = 1;
	int answer = 0;
	if(IsSafe(V))
	{
		answer = 1;
	}
	else
	{
		for(int i = 0; i < Number; i++)
			if(!visited[i]  && Jump(V, i))
			{
				answer = DFS(i);
				if(answer)
				{
					break;
				}
			}
	}
	return answer;
}


/*03-树3 Tree Traversals Again（25 分）*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void solve(int preL, int inL, int postL, int n);

/******************Stack Definition**********************/
#define ERROR -1
#define MAXSIZE 30
#define ElementType int
typedef struct 
{
	int Data[MAXSIZE];
	int Top;
}Stack;

void Push(Stack *PtrS, ElementType item)
{
	if(PtrS->Top == MAXSIZE - 1)
	{
		//printf("堆栈满");
		return;
	}
	else
	{
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

ElementType Pop(Stack *PtrS)
{
	if(PtrS->Top == -1)
	{
		//printf("堆栈空");
		return ERROR;
	}
	else
	{
		return PtrS->Data[(PtrS->Top)--];
	}
}
/******************Stack End****************************/
#define STR_LEN 5
int pre[MAXSIZE];
int count1 = 0;
int in[MAXSIZE];
int count2 = 0;
int post[MAXSIZE];

void solve(int preL, int inL, int postL, int n);
int main()
{
	int n;
	int value;
	char operation[STR_LEN];

	Stack S;
	S.Top = -1;

	scanf("%d", &n);
	
	for(int i = 0; i < 2 * n; i++)
	{
		scanf("%s", operation);
		/*strcmp() returns 0 when two string is the same*/
		/*这里花了非常多的时间，还以为什么错了呢*/
		if(!strcmp(operation, "Push"))
		{
			scanf("%d", &value);
			Push(&S, value);
			pre[count1++] = value;
	
		}
		else
		{
			value = Pop(&S);
			in[count2++] = value;
		}
	}

	solve(0, 0, 0, n);

	for(int i = 0; i < n-1; i++)
	{
		printf("%d ", post[i]);
	}
	printf("%d", post[n-1]);

}


/******************Pre In To Post***********************/
void solve(int preL, int inL, int postL, int n)
{
	int root;
	int L;
	int R;
	int i;
	if(n == 0) return;
	if(n == 1)
	{
		post[postL] = pre[preL];
		return;
	}

	root = pre[preL];
	post[postL + n - 1] = root;
	for(i = 0; i < n; i++)
	{
		if(in[inL+i] == root)
			break;
	} 
	L = i;
	R = n - L - 1;
	solve(preL + 1, inL, postL, i);
	solve(preL + L + 1, inL + L + 1, postL + L, R);
}


/*07-图4 哈利·波特的考试（25 分）*/
#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100 /*最大的顶点数目*/
#define INFINITY 65536  /*unsigned double(16bits) max 65536*/
typedef int Vertex;   /*用顶点下标表示顶点，为整型*/
typedef int WeightType; /*边的权值*/
//typedef char DataType; /*顶点存储的数据类型*/

/*边的定义*/
typedef	struct ENode *PtrToENode;
struct ENode
{
	Vertex V1, V2;  /*有向边<v1, v2>*/
	WeightType Weight; /*权重*/
};
typedef PtrToENode Edge;

/*图结点的定义*/
typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv; /*顶点树目*/
	int Ne; /*边数目*/
	WeightType G[MaxVertexNum][MaxVertexNum]; /*邻接矩阵*/
//	DataType Data[MaxVertexNum]; /*存储顶点的数据*/
};
typedef PtrToGNode MGraph; /*以邻接矩阵存储的图类型*/

MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	for( V = 0; V < Graph->Nv; V++)
	{
		for(W = 0; W < Graph->Nv; W++)
		{
			Graph->G[V][W] = INFINITY;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/*插入边*/
	Graph->G[E->V1][E->V2] = E->Weight;
	/*无向图，插入*/
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	// Vertex V;
	int Nv, i;

	scanf("%d", &Nv);  /*读入顶点个数*/
	Graph = CreateGraph(Nv); /*初始化有Nv个顶点但是没有边的图*/

	scanf("%d", &(Graph->Ne)); /*读入边数目*/

	if(Graph->Ne != 0) /*如果有边*/
	{
		E = (Edge)malloc(sizeof(struct ENode));
		for(i = 0; i < Graph->Ne; i++)
		{
			/*读入格式，起点，终点，权重*/
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			E->V1--;
			E->V2--;    /*编号修改为0*/
			InsertEdge(Graph, E);
		}
	}

	/*如果顶点有数据的话，读入数据*/
	// for(V = 0; V < Graph->Nv; V++)
	// {
	// 	scanf(" %c", &(Graph->Data[V]));
	// }

	return Graph;
}

void /*bool*/ Floyd(MGraph Graph, WeightType D[][MaxVertexNum] /*, Vertex path[][MaxVertexNum]*/)
{
	Vertex i, j, k;
	for(i = 0; i < Graph->Nv; i++)
	{
		for(j = 0; j < Graph->Nv; j++)
		{
			D[i][j] = Graph->G[i][j];
			// path[i][j] = 1;
		}
	}

	for(k = 0; k < Graph->Nv; k++)
	{
		for(i = 0; i < Graph->Nv; i++)
		{
			for(j = 0; j < Graph->Nv; j++)
			{
				if(D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					// if(i == j && D[i][j] < 0)   /*如果发现负值圈*/
					// 	return false
					// path[i][j] = k;
				}
			}
		}
	}

	// return true;

}

WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex i, int 	N)
{
	WeightType MaxDist;
	Vertex j;
	MaxDist = 0;

	for(j = 0; j < N; j++)
	{
		if(i !=j && D[i][j] > MaxDist)  /*对角元素为无穷大*/
		{
			MaxDist = D[i][j];
		}
	}
	return MaxDist;
}


void FindAnimal(MGraph Graph)
{
	WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
	Vertex Aninal, i;

	Floyd(Graph , D);
	MinDist = INFINITY;
	for(i = 0; i < Graph->Nv; i++)
	{
		MaxDist = FindMaxDist(D, i, Graph->Nv);

		if(MaxDist == INFINITY)  /*图不连通的情况*/
		{
			printf("0\n");
			return ;
		}

		if(MinDist > MaxDist)
		{
			MinDist = MaxDist;
			Aninal = i + 1;
		}
	}
	printf("%d %d\n", Aninal, MinDist);
}

int main()
{
	MGraph G = BuildGraph();
	FindAnimal(G);
	return 0;
}


/*09-排序1 排序（25 分）	*/
/*9.1快速排序算法*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int cutoff = 10000;

void InsertSort(int A[],int n)
{ 
    int i,j,temp;
    for(i=1;i<n;i++){
        temp = A[i];
        for(j=i;j>0 && temp<A[j-1];j--){
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
}

//QuickSort
void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Median3(int A[],int left,int right)
{
    int center = (left + right)/2;
    if(A[left] > A[center]) Swap(&A[left],&A[center]);
    if(A[left] > A[right]) Swap(&A[left],&A[right]);
    if(A[center] > A[right]) Swap(&A[center],&A[right]);
    Swap(&A[center],&A[right - 1]);
    return A[right - 1];
}
void Qsort(int A[],int left,int right)
{
    if(cutoff <= right - left){
        int pivot = Median3(A,left,right);
        int i = left,j = right - 1;
        while(1){
            while(A[++i] < pivot) {}
            while(A[--j] > pivot) {}
            if(i < j) Swap(&A[i],&A[j]);
            else break;
        }
        Swap(&A[i],&A[right - 1]);
        Qsort(A,left,i-1);
        Qsort(A,i+1,right);
    }
    else InsertSort(A+left,right-left+1);
}
void QuickSort(int A[],int n)
{
    Qsort(A,0,n-1);
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    QuickSort(A,n);
    for(int i=0;i<n-1;i++) cout<<A[i]<<" ";
    cout<<A[n-1];

    return 0;
}

/*9.1快速排序，C语言版本*/
#include<stdio.h>
#define MAXN 100000
#define ElementType int 

const int cutoff = 1000;
void Quick_Sort(int A[], int N);

int main()
{
	int Num;
	int A[MAXN]; 
	int i;
	scanf("%d", &Num);
	for(i = 0; i < Num; i++)
	{
		scanf("%d", &A[i]);
	}

	Quick_Sort(A, Num);
	for(i = 0; i < Num - 1; i++)
	{
		printf("%d ", A[i]);
	}
	printf("%d\n", A[i]);

}

void Insert_Sort(int *a ,int N)
{
    for ( int i = 1 ; i < N ; i++){
        int tmp = a[i];
        int j;
        for(j = i ; j > 0 && a[j-1] > tmp ; j--){
            a[j] = a[j-1];
        } 
        a[j] = tmp;
    }
}

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int Median3(int A[], int Left, int Right)
{

	if(Left >= Right)
	{
		return 0;
	}

	int Center = (Left + Right)/2;

	if(A[Left] > A[Center])
	{
		Swap(&A[Left], &A[Center]);
	}

	if(A[Left] > A[Right])
	{
		Swap(&A[Left], &A[Right]);
	}

	if(A[Center] > A[Right])
	{
		Swap(&A[Center], &A[Right]);
	}

	Swap(&A[Center], &A[Right-1]);

	return A[Right - 1];
}

/*快速排序对于小规模数据处理非常不好，需要不停的递归递归*/
void QuickSort(int A[], int Left, int Right)
{
	
	// static int count = 0;
	int Pivot;
	int i,j;
	// if(cutoff <=  Right - Left)
	// {
		Pivot = Median3(A, Left, Right);

		i = Left;
		j = Right - 1;


		for(;;)
		{ 
			while(A[++i] < Pivot)
			{}
			while(A[--j] > Pivot)
			{}
			if(i < j)
			{
				Swap(&A[i], &A[j]);
			}
			else
			{
				break;
			}
		}


		Swap(&A[i], &A[Right-1]);

		//Show the process of the QuickSort!
		// printf("The %dth Sort:", ++count);
		// for(i = 0; i < 4; i++)
		// {
		// 	printf("%d ", A[i]);	
		// }
		// printf("\n");

		QuickSort(A, Left, i - 1);

		QuickSort(A, i + 1, Right);
	// }
	// else
	// {

	// 	Insert_Sort(A+Left, Right-Left+1);

	// }
	
}

void Quick_Sort(int A[], int N)
{
	QuickSort(A, 0, N-1);
}

/*09-排序2 Insert or Merge（25 分）*/
#include<stdio.h>
#include<stdlib.h>
#define MAXN 100
#define ElementType int

int OrigData[MAXN];
int ParData[MAXN];
int CopyA[MAXN];
int IsInsertion = 0;

void InsertionSort(int A[], int N);
void Merge_sort(int A[], int N);
void Merge_sort(ElementType A[], int N);


int main()
{
	int Num;
	int i;

	scanf("%d", &Num);
	for(i = 0; i < Num; i++)
	{
		scanf("%d", &OrigData[i]);
		CopyA[i] = OrigData[i];

	}
	for(i = 0; i < Num; i++)
	{
		scanf("%d", &ParData[i]);
	}

	InsertionSort(OrigData, Num);
	if(IsInsertion)
	{
		for(i = 0; i < Num - 1; i++)
		{
			printf("%d ", OrigData[i]);
		}
		printf("%d", OrigData[i]);
	}
	else
	{
		Merge_sort(CopyA, Num);

		for(i = 0; i < Num - 1; i++)
		{
			printf("%d ", CopyA[i]);
		}
		printf("%d", CopyA[i]);		
	}

}

int IsIdentical(int A[], int N)
{
	int i;
	for(i = 0; i < N; i++)
	{
		if(A[i] != ParData[i])
		{
			return 0;
		}
	}

	return 1;
}

void InsertionSort(int A[], int N)
{
	int i, j;
	int flag = 0;
	int temp;

	for(i = 1; i < N; i++)
	{
		/*取出未排序序列中的第一个元素*/
		temp = A[i];
		/*把元素取出来依次和已排序序列中元素比较右移*/
		for(j = i; (j>0) && (temp < A[j - 1]); j--)
		{
			A[j] = A[j - 1];
		}
		A[j] = temp;

		if(IsIdentical(A,  N))
		{
			printf("Insertion Sort\n");
			flag = 1;
			IsInsertion = 1;
			continue;
		}
		if(flag)
		{
			break;
		}

	}
}

void Merge(ElementType A[], ElementType TempA[], int L, int R, int RightEnd);

/*递归算法*/
void Msort(ElementType A[], ElementType TempA[], int Left, int Right)
{
	int center;
	if(Left < Right)
	{
		center = (Left + Right) / 2;
		Msort(A, TempA, Left, center);
		Msort(A, TempA, center + 1, Right);
		Merge(A, TempA, Left, center+1, Right);
	}
}

void Merge1(int A[], int TempA[], int L, int R, int RightEnd);
/*非递归算法*/

void Merge_pass(ElementType A[], ElementType TempA[], int N, int length)
{
	int i;
	int j;
	/*length指的是当前有序子列的长度，每一次加倍*/
	for(i = 0; i <= N - 2 * length; i += 2 * length)
	{
		/*Merge1和Merge相比，最后的元素存在TempA[]中的*/
		Merge1(A, TempA, i, i + length, i + 2* length - 1);
	}
	
	/*处理尾巴*/
	if(i+length < N) /*归并最后两个子列*/
	{
		Merge1(A, TempA, i, i + length, N -1);
	}

	else /*最后只有一个子列*/
	{
		for(j = i; j < N; j++)
		{
			TempA[j] = A[j];
		}
	}
}


/*统一函数的接口*/
void Merge_sort(ElementType A[], int N)
{
	int flag = 0;
	int length = 1;

	ElementType *TempA;

	TempA = malloc(N * sizeof(ElementType));
	if(TempA != NULL)
	{
		while(length < N)
		{
			Merge_pass(A, TempA, N, length);

			if(IsIdentical(A, N))
			{
				printf("Merge Sort\n");
				flag = 1;
				length *= 2;
				continue;

			}
			length *= 2;
			if(flag)
			{
				break;
			}
	
		}
		free(TempA);
	}
	else
	{
		return;
	}
}



/*A待排序列 TempA临时数组，L左边子序列起始位置  R右边子序列起始位置，RightEnd右边终点位置*/
void Merge(ElementType A[], ElementType TempA[], int L, int R, int RightEnd)
{
	int LeftEnd;
	int Tmp;
	int NumElements;

	Tmp = L;
	LeftEnd = R - 1; /*左边终点位置，这里假设左右两列都是挨着的*/
	NumElements = RightEnd - L + 1;/*元素的个数记录一下子*/

	while(L <= LeftEnd && R <= RightEnd)
	{
		if(A[L] <= A[R])
		{
			TempA[Tmp++] = A[L++];
		}
		else
		{
			TempA[Tmp++] = A[R++];
		}
	}

	while(L <= LeftEnd)
		TempA[Tmp++] = A[L++];

	while(R <= RightEnd)
		TempA[Tmp++] = A[R++];
	/*注意这里L已经不知道指导哪里了，Rightend还是在的*/
	for(int i = 0 ; i < NumElements; i++, RightEnd --)
	{
		A[RightEnd] = TempA[RightEnd];
	}
}

void Merge1(int A[], int TempA[], int L, int R, int RightEnd)
{
	int LeftEnd;
	int NumElements;

	LeftEnd = R - 1;

	int Tmp = L;
	NumElements = RightEnd - L + 1;/*元素的个数记录一下子*/

	while(L <= LeftEnd && R <= RightEnd)
	{
		if(A[L] <= A[R])
		{
			TempA[Tmp++] = A[L++];
		}
		else
		{
			TempA[Tmp++] = A[R++];
		}
	}

	while(L <= LeftEnd)
	{
		TempA[Tmp++] = A[L++];
	}

	while(R <= RightEnd)
	{
		TempA[Tmp++] = A[R++];
	}

	for(int i = 0 ; i < NumElements; i++, RightEnd --)
	{
		A[RightEnd] = TempA[RightEnd];
	}

}