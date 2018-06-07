//PTA 2.4 Pop Sequence
//有问题的答案
// #include<stdio.h>
// #include<stdlib.h>
// #define MAXN 1000
// #define ElementType int
// typedef struct Stack *PtrS;
// //the definition of Stack
// struct Stack
// {
// 	ElementType Data[MAXN];
// 	int Top;
// };

// int Create(PtrS *P1);
// void Push(PtrS P1, ElementType item);
// ElementType Pop(PtrS P1);

// int main()
// {
// 	int m, n, k;
// 	PtrS Stack1;
// 	PtrS Stack2;

// 	scanf("%d %d %d", &m, &n, &k);
// 	/*对于多次输入序列的循环*/
// 	for(int i = 0; i < k; i++)
// 	{
// 		printf("1\n");
// 		Create(&Stack1);
// 		Create(&Stack2);
// 		printf("2\n");
// 		/*把输入的序列存储在一个堆栈Stack1里面*/
// 		for(int j = n - 1; j >= 0;j--)
// 		{
// 			scanf("%d", &Stack1->Data[j]);
// 			Stack1->Top ++;
// 		}

// 		//模拟进堆栈出堆栈
// 		int k = 1;
// 		while(k <= n)
// 		{
// 			//这里应该有一个模拟1-n的入栈Stack2的操作
// 			Push(Stack2, k);
// 			//堆栈顶部的元素是相同的
// 			if(Stack2->Data[Stack2->Top] == Stack1->Data[Stack1->Top]&& Stack2->Top!= -1)
// 			{
// 				Pop(Stack1);
// 				Pop(Stack2);
// 			}
// 			//堆栈顶部的元素不相同，但是Stack2未满
// 			else if(Stack2->Top < n && i < n)
// 			{
// 				k++;
// 				continue;
// 			}
// 			else 
// 			{
// 				break;
// 			}
// 			if(Stack1->Top == -1 && Stack2->Top == -1)
// 			{
// 				printf("YES\n");
// 			}
// 			else
// 			{
// 				printf("NO\n");
// 			}
// 		}

// 	}

// 	return 0;
// }

// //Create Stack
// //这个函数是有问题的？？？
// int Create(PtrS *P1)
// {
// 	(*P1)->Top = -1;
// 	return 0;
// }

// //Push into Stack
// void Push(PtrS P1, ElementType item)
// {
// 	if(P1->Top == MAXN - 1)
// 	{
// 		printf("堆栈满");
// 		return;
// 	}
// 	else
// 	{
// 		P1->Data[++P1->Top] = item;
// 		return;
// 	}
// }

// //Pop from Stack
// ElementType Pop(PtrS P1)
// {
// 	if(P1->Top == -1)
// 	{
// 		printf("堆栈空");
// 		return -1;
// 	}
// 	else
// 	{
// 		return(P1->Data[P1->Top--]);
// 	}
// }

//正确的答案
// #include <stdio.h>  
  
// #define MAXSIZE 1000  
  
// typedef struct{  
//     int data[MAXSIZE];  
//     int top;  
// }SqStack;  
  
// int InitStack(SqStack *s)  
// {  
//     s->top = -1;  
//     return 0;  
// }  
  
// int Push(SqStack *s, int e)  
// {  
//     if(s->top==MAXSIZE)return 1;  
//     s->top++;  
//     s->data[s->top]=e;  
//     return 0;  
// }  
  
// int Pop(SqStack *s){  
//     int e;  
//     if(s->top==-1)return 1;  
//     e=s->data[s->top];  
//     s->top--;  
//     return e;  
// }  
  
// int main()  
// {  
//     int m, n, k,i;  
//     SqStack s,t;  
//     scanf("%d%d%d",&m,&n,&k);  
//     while(k--){  
//         InitStack(&s);/*初始化栈s和栈t*/  
//         InitStack(&t);  
//         for(i=n-1;i>=0;i--){    /*将给出的序列依次压入栈t中(首元素为栈顶)*/  
//             scanf("%d",&(t.data[i]));  
//         }   
//         t.top=n-1;  
//         i=0;  
//         while(i<=n){    /*模拟进栈出栈*/  
//             if(s.data[s.top]==t.data[t.top]&&s.top!=-1){/*如果s的栈顶元素和t的栈顶元素相同*/  
//                 Pop(&s);  
//                 Pop(&t);  
//             }else if(s.top<m-1 && i<n){/*如果不相同且s栈未满*/  
//                 i++;  
//                 Push(&s,i);  
//             }else{  /*以上两种情况都不匹配则说明匹配失败*/  
//                 break;  
//             }  
//         }  
//         if(s.top==-1 && t.top==-1){  
//             printf("YES\n");  
//         }else{  
//             printf("NO\n");  
//         }  
  
//     }  
//     return 0;  
// }  

//习题课本，队列的应用
// #include<stdio.h>

// #define MaxQSize 1000
// #define ERROR -1
// typedef struct
// {	
// 	int Customer[MaxQSize];
// 	int front;
// 	int rear;
// }Queue;

// void InitQ(Queue *PtrQ)
// {
// 	//循环队列这里要取0？？？
// 	PtrQ->front = PtrQ->rear = 0;
// }

// int IsEmptyQ(Queue *PtrQ)
// {
// 	return PtrQ->front == PtrQ->rear;
// }

// void AddQ(Queue *PtrQ, int Item)
// {
// 	if((PtrQ->rear+1) % MaxQSize == PtrQ->front)
// 	{
// 		printf("队列满");
// 		return;
// 	}
// 	PtrQ->rear = (PtrQ->rear+1)%MaxQSize;
// 	PtrQ->Customer[PtrQ->rear] = Item;
// }

// int DeleteQ(Queue *PtrQ)
// {
// 	if(PtrQ->front == PtrQ->rear)
// 	{
// 		printf("队列空");
// 		return ERROR;
// 	}
// 	else
// 	{
// 		PtrQ->front = (PtrQ->front+1)%MaxQSize;
// 		return PtrQ->Customer[PtrQ->front];
// 	}
// }

// int main()
// {
// 	int N;
// 	int current;
// 	int flag;
// 	Queue A, B;
// 	InitQ(&A);
// 	InitQ(&B);
// 	scanf("%d", &N);
// 	for(int i=0;i<N;i++)
// 	{
// 		scanf("%d",&current);
// 		if(current%2)
// 		{
// 			AddQ(&A, current);
// 		}
// 		else
// 		{
// 			AddQ(&B, current);
// 		}
// 	}
// 	flag = 0;/*为了控制输出格式中的空格*/
// 	/*A, B两个队列都不为空*/
// 	while(!IsEmptyQ(&A)&&!IsEmptyQ(&B))
// 	{
// 		if(flag == 0)
// 		{
// 			printf("%d",DeleteQ(&A));
// 			flag = 1;
// 		}
// 		else
// 		{
// 			printf(" %d",DeleteQ(&A));
// 		}
// 		if(!IsEmptyQ(&A))
// 		{
// 			printf(" %d",DeleteQ(&A));
// 		}
// 		printf(" %d",DeleteQ(&B));
// 	}
// 	/*A不为空*/
// 	while(!IsEmptyQ(&A))
// 	{
// 		if(flag == 0)
// 		{
// 			printf("%d",DeleteQ(&A));
// 		}
// 		else
// 		{
// 			printf(" %d",DeleteQ(&A));
// 			flag = 1;
// 		}		
// 	}
// 	/*B不为空*/
// 	while(!IsEmptyQ(&B))
// 	{
// 		if(flag == 0)
// 		{
// 			printf("%d",DeleteQ(&B));
// 		}
// 		else
// 		{
// 			printf(" %d",DeleteQ(&B));
// 			flag = 1;
// 		}				
// 	}
// 	printf("\n");
// }

// int PostOrderGetHeight(BinTree BT)
// {
// 	int HL, HR, MaxH;
// 	if(BT)
// 	{
// 		HL = PostOrderGetHeight(BT->Left);
// 		HR = PostOrderGetHeight(BT->Right);
// 		MaxH = (HL > HR)? HL : HR;
// 		return MaxH + 1;
// 	}
// 	else
// 		return 0;
// }


// #include<stdio.h>
// #include <stdlib.h>
// #define MaxTree 10
// #define ElementType char
// #define Tree int
// #define Null -1 /*NULL 在stdio.h中定义为0*/

// struct TreeNode
// {
// 	ElementType Element;
// 	Tree Left;
// 	Tree Right;
// };

// struct TreeNode T1[MaxTree], T2[MaxTree];

// Tree BuildTree(struct TreeNode T[]);
// int Isomorphic(Tree R1, Tree R2);

// int main()
// {
// 	Tree R1, R2;
// 	R1 = BuildTree(T1);
// 	printf("1\n");
// 	R2 = BuildTree(T2);
// 	if(Isomorphic(R1, R2))
// 		printf("Yes\n");
// 	else
// 		printf("No\n");
// 	return 0;
// }

// Tree BuildTree(struct TreeNode T[]) /*返回值为树根index*/
// {
// 	int N;
// 	int i;
// 	int check[MaxTree];
// 	char cl, cr;
// 	Tree Root = Null; //初始化树根为-1，也就是空树

// 	scanf("%d\n",&N);
// 	/*
// 	等同于下面的写法，输入的时候，回车符号也进入输入流中，下一次
// 	scanf直接取得这个符号。
// 	针对除了％c而言空格，回车，跳格等结束符在输入前碰到的话，会自
// 	动抛弃，输入后碰到的话，就会认为结束。
    
// 	scanf("%d", &N);
// 	getchar() //目的就是为了把回车符号吃掉，因为下面的输入是一个char
// 	会接收回车符号的。
// 	*/
// 	if(N)
// 	{
// 		for(i = 0; i<N; i++)
// 		{
// 			check[i] = 0;
// 		}
// 		for(i = 0; i<N; i++)
// 		{
// 			fflush(stdout);
// 			printf("%d",i);
			
// 			scanf("%c %c %c\n",&T[i].Element, &cl, &cr);		
			
// 			//printf("2\n");
// 			if(cl != '-')
// 			{
// 				T[i].Left = cl - '0';
// 				check[T[i].Left] = 1;
// 			}
// 			else
// 			{
// 				T[i].Left = Null;
// 			}
// 			if(cr != '-')
// 			{
// 				T[i].Right = cr - '0';
// 				check[T[i].Right] = 1;
// 			}
// 			else
// 			{
// 				T[i].Right = Null;
// 			}
// 		}
// 		for(i = 0; i<N; i++)
// 			if(!check[i])
// 			{
// 				Root = i;
// 				break;
// 			}	
		
// 	}
// 	return Root;
// }

// /*同构的意思就是若干次左右结点的互换*/
// int Isomorphic(Tree R1, Tree R2)
// {
// 	/*both tree is empty*/
// 	/*这里对于空树是-1，不太确定？？？？*/
// 	if((R1 == Null) && (R2 == Null)) 
// 		return 1;

// 	/*one is empty, the other is not*/
// 	if(((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
// 		return 0;

// 	/*roots are different*/
// 	if(T1[R1].Element != T2[R2].Element)
// 		return 0;

// 	/*both have no left subtree*/
// 	if((T1[R1].Left == Null) && T2[R2].Left == Null)
// 		return Isomorphic(T1[R1].Right, T2[R2].Right);

// 	//
// 	if((T1[R1].Left != Null) && (T2[R2].Left != Null) && ((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
// 		return(Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
// 		/*no need to swap the left and the right.*/
// 	else
// 		return(Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
// 		/*need to swap the left and the right.*/
// }

// #include<stdio.h>
// #include<stdlib.h>
// typedef struct TreeNode *Tree;
// struct TreeNode
// {
// 	int v;
// 	Tree Left, Right;
// 	/*flag指示的是某个结点是否被访问过*/
// 	int flag;
// };

// Tree MakeTree(int N);
// int Judge(Tree T, int N);
// void FreeTree(Tree T);
// Tree NewNode(int V);
// Tree Insert(Tree T, int V);
// int Check(Tree T, int V);
// void Reset(Tree T);
// int main()
// {
// 	int N;
// 	int L;
// 	int i;

// 	Tree T;
// 	scanf("%d",&N);
// 	while(N)
// 	{
// 		scanf("%d",&L);
// 		T = MakeTree(N);
// 		for(i=0;i<L;i++)
// 		{
// 			if(Judge(T,N))
// 			{
// 				printf("Yes\n");
// 			}
// 			else
// 			{
// 				printf("No\n");
// 			}
// 			/*清楚T树木中的flag*/
// 			Reset(T);
// 		}
// 		FreeTree(T);
// 		scanf("%d",&N);
// 	}
// 	return 0;
// }

// Tree MakeTree(int N)
// {
// 	Tree T;
// 	int i, V;
// 	scanf("%d",&V);
// 	T = NewNode(V);
// 	for(i=1; i<N; i++)
// 	{
// 		scanf("%d",&V);
// 		Insert(T, V);
// 	}
// 	return T;
// }

// Tree NewNode(int V)
// {
// 	Tree T = (Tree)malloc(sizeof(struct TreeNode));
// 	T->v = V;
// 	T->Left = T->Right = NULL;
// 	/*没有被访问过的结点为0，访问过的结点为1*/
// 	T->flag = 0;

// 	return T;
// }

// Tree Insert(Tree T, int V)
// {
// 	if(!T)
// 	{
// 		如果树为空
// 		T = NewNode(V);
// 	}
// 	else
// 	{
// 		if(V > T->v)
// 		{
// 			T->Right = Insert(T->Right, V);
// 		}
// 		else
// 		{
// 			T->Left = Insert(T->Left, V);
// 		}
// 	}
// 	return T;
// }

// int Check(Tree T, int V)
// {
// 	if(T->flag) /*T->flag = 1表示根节点访问过*/
// 	{
// 		if(V < T->v)
// 		{
// 			return Check(T->Left, V);

// 		}
// 		else if(V > T->v)
// 		{
// 			return Check(T->Right, V);
// 		}
// 		else
// 		{
// 			/*这个数字出现了两次，认为是错误的！！！*/
// 			return 0;
// 		}
// 	}
// 	else
// 	{
// 		if(V == T->v)
// 		{
// 			T->flag = 1;
// 			return 1;
// 		}
// 		else 
// 		{
// 			return 0;
// 		}
// 	}
// }

// int Judge(Tree T, int N)
// {
// 	int i, V;
// 	int flag = 0;
// 	scanf("%d",&V);
// 	if(V!=T->v) flag = 1;
// 	else 
// 	{
// 		T->flag = 1;
// 	}
// 	for(i = 1; i < N; i++)
// 	{
// 		scanf("%d",&V);
// 		if((!flag) && !Check(T,V)) flag = 1;
// 	}
// 	if(flag)
// 	{
// 		return 0;
// 	}
// 	else
// 	{
// 		return 1;
// 	}
// }

// void Reset(Tree T)
// {
// 	if(T->Left)
// 	{
// 		Reset(T->Left);
// 	}
// 	if(T->Right)
// 	{
// 		Reset(T->Right);
// 	}
// 	T->flag = 0;
// }

// void FreeTree(Tree T)
// {
// 	if(T->Left)
// 	{
// 		FreeTree(T->Left);
// 	}
// 	if(T->Right)
// 	{
// 		FreeTree(T->Right);
// 	}
// 	free(T);
// }
// #include <stdio.h>
// #include <stdlib.h>

// typedef int ElementType;
// typedef struct TNode *Position;
// typedef Position BinTree;
// struct TNode{
//     ElementType Data;
//     BinTree Left;
//     BinTree Right;
// };
// void PreOrderTravesal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
// void InOrderTravesal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

// BinTree Insert( BinTree BST, ElementType X );
// BinTree Delete( BinTree BST, ElementType X );
// Position Find( BinTree BST, ElementType X );
// Position FindMin( BinTree BST );
// Position FindMax( BinTree BST );

// int main()
// {
//     BinTree BST, MinP, MaxP, Tmp;
//     ElementType X;
//     int N, i;

//     BST = NULL;
//     scanf("%d", &N);
//     for ( i=0; i<N; i++ )
//     {
//         scanf("%d", &X);
//         BST = Insert(BST, X);
//     }
//     printf("Preorder:"); 
//     PreOrderTravesal(BST); 
//     printf("\n");


//     MinP = FindMin(BST);
//     MaxP = FindMax(BST);
//     scanf("%d", &N);
//     for( i=0; i<N; i++ ) {
//         scanf("%d", &X);
//         Tmp = Find(BST, X);
//         if (Tmp == NULL) printf("%d is not found\n", X);
//         else {
//             printf("%d is found\n", Tmp->Data);
//             if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
//             if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
//         }
//     }
//     scanf("%d", &N);
//     for( i=0; i<N; i++ ) {
//         scanf("%d", &X);
//         BST = Delete(BST, X);
//     } 
//     printf("Inorder:"); InOrderTravesal(BST); printf("\n");

//     return 0;
// }


// BinTree Insert(BinTree BST, ElementType X )
// {
// 	if(!BST)
// 	{
// 		BST = (BinTree)malloc(sizeof(struct TNode));
// 		BST->Left = NULL;
// 		BST->Right = NULL;
// 		BST->Data = X;
// 	}
// 	else
// 	{
// 		if(X > BST->Data)
// 		{
// 			BST->Right = Insert(BST->Right, X);
// 		}
// 		else if(X < BST->Data)
// 		{
// 			BST->Left = Insert(BST->Left, X);
// 		}
// 	}
// 	return BST;
// }


// BinTree Delete( BinTree BST, ElementType X )
// {

// 	BinTree Temp, Temp1;
// 	Temp1 = BST;

// 	if(!BST)
// 	{
// 		printf("Not Found\n");
// 		return Temp1;
// 	}
// 	else
// 	{
// 		if(X < BST->Data)
// 		{
// 			BST->Left = Delete(BST->Left, X);
// 		}
// 		else if(X > BST->Data)
// 		{
// 			BST->Right = Delete(BST->Right, X);
// 		}
// 		else
// 		{
// 			if(BST->Left && BST->Right)
// 			{
// 				Temp = FindMin(BST->Right);
// 				BST->Data = Temp->Data;
// 				BST->Right = Delete(BST->Right, Temp->Data);
// 			}
// 			else
// 			{
// 				Temp = BST;
// 				if(!BST->Left)
// 				{
// 					BST = BST->Right;
// 				}
// 				else if(!BST->Right)
// 				{
// 					BST = BST->Left;
// 				}
// 				free(Temp);
// 			}
		
// 		}

// 	}
// 	return BST;
// }

// Position Find( BinTree BST, ElementType X )
// {
// 	while(BST)
//     {
//         if (X > BST->Data)
//         {
//             BST = BST->Right;
//         }
//         else if (X < BST->Data)
//         {
//             BST = BST->Left;
//         }
//         else
//             return BST;
//     }
//     return NULL;
// }

// Position FindMin(BinTree BST)
// {
//     if(BST)
//     {
//         while(BST->Left)
//         {
//             BST = BST->Left;
//         }
//     }
//     return BST;/*不管BST是否空，最后返回BST，*/
// }

// Position FindMax( BinTree BST )
// {
//     if(BST)
//     {
//         while(BST->Right)
//         {
//             BST = BST->Right;
//         }
//     }
//     return BST;/*不管BST是否空，最后返回BST，*/
// }


// void PreOrderTravesal(BinTree BT)
// {

//     if (BT)
//     {
//         printf(" %d", BT->Data);
//         PreOrderTravesal(BT->Left);
//         PreOrderTravesal(BT->Right);
//     }
// }

// void InOrderTravesal(BinTree BT)
// {
//     if (BT)
//     {
//         InOrderTravesal(BT->Left);
//         printf(" %d", BT->Data);
//         InOrderTravesal(BT->Right);
//     }
// }

// //04-树5 Root of AVL Tree（25 分）
// #include<stdio.h>
// #include<stdlib.h>

// typedef int ElementType;
// typedef struct AVLTreeNode *AVLTree;
// struct AVLTreeNode
// {
// 	ElementType Data;
// 	AVLTree Left;
// 	AVLTree Right;
// 	int Height;
// };

// int PostOrderGetHeight(AVLTree BT);
// int MAX(int A, int B);
// AVLTree AVL_Insert(ElementType X, AVLTree T);
// AVLTree SingleLeftRightRotation(AVLTree A);
// AVLTree SingleRightLeftRotation(AVLTree A);
// AVLTree SingleLeftRotation(AVLTree A);
// AVLTree SingleRightRotation(AVLTree A);

// int main()
// {
// 	int i;
// 	int N;
// 	int X;
// 	scanf("%d", &N);
// 	AVLTree Tree;
// 	Tree = NULL;
// 	for(i = 0;i < N;i++)
// 	{
// 		scanf("%d", &X);
// 		Tree = AVL_Insert(X, Tree);
// 	}
// 	printf("%d",Tree->Data);
// 	return 0;
// }

// AVLTree AVL_Insert(ElementType X, AVLTree T)
// {
// 	if(!T)
// 	/*空树*/
// 	{
// 		T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
// 		T->Data = X;
// 		T->Left = T->Right = NULL;

// 	}
// 	else if(X < T->Data)
// 	{
// 		T->Left = AVL_Insert(X, T->Left);
// 		if(PostOrderGetHeight(T->Left)-PostOrderGetHeight(T->Right)==2)
// 		{
// 			if(X < T->Left->Data)
// 			{
// 				T = SingleLeftRotation(T);
// 			}
// 			else
// 			{
// 				T = SingleLeftRightRotation(T);
// 			}
// 		}

// 	}
// 	else if(X > T->Data)
// 	{
// 		T->Right = AVL_Insert(X, T->Right);
// 		if(PostOrderGetHeight(T->Left)-PostOrderGetHeight(T->Right)==-2)
// 		{
// 			if(X > T->Right->Data)
// 			{
// 				T = SingleRightRotation(T);
// 			}
// 			else
// 			{
// 				T = SingleRightLeftRotation(T);
// 			}

// 		}
// 	}
// 	T->Height = MAX(PostOrderGetHeight(T->Left) , PostOrderGetHeight(T->Right));
		        

// 	return T;

// }

// int PostOrderGetHeight(AVLTree BT)
// {
//     int HL, HR, MaxH;
//     if(BT)
//     {
//         HL = PostOrderGetHeight(BT->Left);
//         HR = PostOrderGetHeight(BT->Right);
//         MaxH = (HL > HR)? HL : HR;
//         return MaxH + 1;
//     }
//     else
//         return 0;
// }

// AVLTree SingleRightRotation(AVLTree A)
// {
// 	AVLTree B = A->Right;
// 	A->Right = B->Left;
// 	B->Left = A;
// 	A->Height = MAX(PostOrderGetHeight(A->Left),PostOrderGetHeight(A->Right))+1;
// 	B->Height = MAX(PostOrderGetHeight(B->Right), A->Height);
// 	return B;
// }
// AVLTree SingleLeftRotation(AVLTree A)
// {
// 	AVLTree B = A->Left;
// 	A->Left = B->Right;
// 	B->Right = A;
// 	A->Height = MAX(PostOrderGetHeight(A->Left),PostOrderGetHeight(A->Right))+1;
// 	B->Height = MAX(PostOrderGetHeight(B->Left), A->Height);
// 	return B;

// }
// AVLTree SingleRightLeftRotation(AVLTree A)
// {
// 	A->Right = SingleLeftRotation(A->Right);
// 	return SingleRightRotation(A);
// }
// AVLTree SingleLeftRightRotation(AVLTree A)
// {
// 	A->Left = SingleRightRotation(A->Left);
// 	return SingleLeftRotation(A);
// }

// int MAX(int A, int B)
// {
// 	return (A>B)?A:B;
// }
// #include<stdio.h>
// #include<stdlib.h>

// #define MaxData 10000000
// #define MaxSize 100

// typedef struct HeadStruct *MaxHeap;
// typedef int ElementType;
// struct HeapStruct
// {
// 	ElementType *Elements; //这里目前看不懂，数组？？
// 	int size; //
// 	int Capacity;
// };

// MaxHeap Create(int MaxSize)
// {
// 	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
// 	H->Elements = malloc((MaxSize+1)*sizeof(ElementType));
// 	H->size = 0; //堆的当前元素个数
// 	H->Capacity = MaxSize; //堆的最大容量
// 	//MaxData为哨兵，大于堆中所有可能的元素
// 	h->Elements[0] = MaxData;
// 	return H;

// }

// void Insert(MaxHeap H, ElementType item)
// {
// 	int i;
// 	if(IsFull(H))
// 	{
// 		printf("堆满");
// 		return;
// 	}
// 	i = ++ H->size;
// 	for(; H->Elements[i/2] < item; i = i/2)
// 	{
// 		//判断条件里面，由于哨兵的存在，不需要限制i
// 		H->Elements[i] = H->Elements[i/2]; //向下过滤结点
// 	}
// 	H->Elements[i] = item;

// }

// ElementType Delte(MaxHeap H)
// {
// 	int Parent;
// 	int Child;

// 	ElementType MaxItem, temp;
// 	if(IsEmpty(H))
// 	{
// 		printf("堆为空");
// 		return;
// 	}
// 	MaxItem = H->Elements[1];
// 	temp = H->Elements[H->size--];//最后一个结点

// 	for(Parent = 1; Parent*2 <= H->size; Parent = Child)
// 	{
// 		Child = Parent * 2;
// 		if((Child != H->size)&&(H->Elements[Child]<H->Elements[Child+1]))
// 		{
// 			Child ++; //child指向左右结点中的最大值
// 		}
// 		if(temp < H->Elements[Child])
// 		{
// 			H->Elements[Parent] = H->Elements[Child];
// 		}

// 	}
// 	H->Elements[Parent] = temp;
// 	return MaxItem;
// }

// int Find(SetType S[], ElementType X)
// {
// 	int i;
// 	/*先找一下元素X在不在数组中*/
// 	for(i = 0; i < MaxSize && S[i]!= X; i++);
// 	if(i >= MaxSize)
// 	{
// 		return -1;
// 	}
// 	/*若X在数组中，则找父节点*/
// 	for(;S[i].Parent != -1;i = S[i].Parent);
// 	return i;
// }

// void Union(SetType S[], ElementType X1, ElementType X2)
// {
// 	int Root1, Root2;
// 	Root1 = Find(S, X1);
// 	Root2 = Find(S, X2);
// 	if(Root1 != Root2)
// 	{
// 		/*把Root2指向Root1*/
// 		S.[root2].Parent = Root1;
// 	}
// }


// //05-树7 最小堆中的路径
// #include<stdio.h>
// #include<stdlib.h>

// #define MAXN 1001
// #define MINH -10001

// int H[MAXN], size;

// /*堆建立函数*/
// void Create()
// {
// 	size = 0;
// 	H[0] = MINH;
// 	/*设置岗哨*/
// }

// /*最小堆的插入*/
// void Insert(int X)
// {
// 	if(size >= MAXN)
// 	{
// 		printf("Heap is full");
// 		return;
// 	}
// 	int i;
// 	for(i = ++size; H[i/2] > X; i /= 2)
// 	{
// 		H[i] = H[i/2];
// 	}
// 	H[i] = X;
// }

// int main()
// {
// 	int N;
// 	int M;
// 	int i;
// 	int X;

// 	scanf("%d %d",&N, &M);
// 	Create();
// 	for(i = 0; i < N;i++)
// 	{
// 		scanf("%d",&X);
// 		Insert(X);
// 	}

// 	int j;
// 	for(i = 0; i < M; i++)
// 	{
// 		scanf("%d", &j);
// 		printf("%d", H[j]);
// 		while(j > 1)
// 		{
// 			j /= 2;
// 			printf(" %d", H[j]);
// 		}
// 		printf("\n");
// 	}

// 	return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>

// #define MaxSize 10001
// typedef int ElementType; /*默认元素可以用非负的整数来表示*/
// typedef int SetName;/*默认用根结点的下标来表示集合的名称*/
// typedef ElementType SetType[MaxSize];

// SetName Find1(SetType S, ElementType X)
// {
// 	for(; S[X]>=0; X = S[X]);
// 	return X;
// }
// /*路径压缩算法*/
// SetName Find(SetType S, ElementType X)
// {
// 	if(S[X] < 0)
// 		return X;
// 	else
// 		return S[X] = Find(S, S[X]);
// }
// /*按照高度来*/
// void Union(SetType S, SetName Root1, SetName Root2)
// {
// 	/*这里默认Root1和Root2是两个不同树的根结点*/
// 	if(S[Root2] < S[Root1])
// 	{
// 		/*把矮树贴到高树上面去，同时树的高度不变的*/
// 		/*Root2高*/
// 		S[Root1] = Root2;
// 	}
// 	else
// 	{
// 		if(S[Root1] == S[Root2])
// 		{
// 			S[Root1]--;
// 		}
// 		S[Root2] = Root1;
// 	}

// }

// /*按照树的规模来合并*/
// void Union1(SetType S, SetName Root1, SetName Root2)
// {
// 	/*这里默认Root1和Root2是两个不同树的根结点*/
// 	if(S[Root2] < S[Root1])
// 	{
// 		/**/
// 		/*Root2高*/
// 		S[Root2] += S[Root1];
// 		S[Root1] = Root2;
// 	}
// 	else
// 	{
// 		S[Root1] += S[Root2];
// 		S[Root2] = Root1;
// 	}

// }

// void Initiliazation(SetType S, int n)
// {
// 	int i;
// 	for(i = 0; i<n; i++)
// 	{
// 		S[i] = -1;
// 	}
// }

// void Input_Connection(SetType S)
// {
// 	ElementType u, v;
// 	SetName Root1, Root2;
// 	scanf("%d %d" , &u, &v);
// 	Root1 = Find(S, u-1);
// 	Root2 = Find(S, v-1);
// 	if(Root1 != Root2)
// 	{
// 		Union(S, Root1, Root2);
// 	}

// }

// void Check_Connection(SetType S)
// {
// 	ElementType u,v;
// 	SetName Root1, Root2;
// 	scanf("%d %d" , &u, &v);
// 	Root1 = Find(S, u-1);
// 	Root2 = Find(S, v-1);
// 	if(Root1 == Root2)
// 	{
// 		printf("yes\n");
// 	}
// 	else
// 	{
// 		printf("no\n");
// 	}

// }

// void Check_Network(SetType S, int n)
// {
// 	int i;
// 	int counter = 0;
// 	for(i = 0; i<n; i++)
// 	{
// 		if(S[i]<0)
// 		{
// 			counter ++;
// 		}
// 	}
// 	if(counter == 1)
// 	{
// 		printf("The network is connected.\n");
// 	}
// 	else
// 	{
// 		printf("There are %d components.\n", counter);
// 	}
// }

// int main()
// {
// 	SetType S;
// 	int n;
// 	char in;

// 	scanf("%d", &n);
// 	Initiliazation(S, n);
// 	do
// 	{
// 		scanf("%c", &in);
// 		switch(in)
// 		{
// 			case 'I': Input_Connection(S);break;
// 			case 'C': Check_Connection(S);break;
// 			case 'S': Check_Network(S, n);break;
// 		}
// 	}while(in != 'S');
// }

/*06-图1 列出连通集（25 分）*/
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// #define MaxVertexNum 100
// typedef int WeightType;
// typedef int DataType;
// typedef int Vertex;

// char B[] = {'B', 'F', 'S'};     // 用于选择BFS遍历  
// char D[] = {'D', 'F', 'S'};     // 用于选择DFS遍历  

// typedef struct GNode *PtrToGNode;
// struct GNode
// {
// 	int Nv; //顶点数
// 	int Ve; //边数
// 	WeightType G[MaxVertexNum][MaxVertexNum];

// 	//DataType Data[MaxVertexNum];  //如果顶点有其它含义，不是0-maxvertexnum-1
// };//存储顶点的数据
// typedef PtrToGNode MGraph;  //以邻接矩阵存储的图

// //初始化一个有VertexNum顶点数，但是没有边的图
// MGraph CreateGraph(int VertexNum)
// {
// 	Vertex V, W;
// 	MGraph Graph;
// 	Graph = (MGraph)malloc(sizeof(struct GNode));
// 	Graph->Nv = VertexNum;
// 	Graph->Ve = 0;

// 	for(V = 0; V < VertexNum; V++)
// 		for(W = 0; W < VertexNum; W++)
// 		{
// 			Graph->G[V][W] = 0;
// 		}
// 	return Graph;
// }

// typedef struct ENode *PtrToENode;
// struct ENode
// {
// 	Vertex V1,V2; /*有向边*/
// 	WeightType Weight; //权重
// };
// typedef PtrToENode Edge;
// //插入一条边
// void InsertEdge(MGraph Graph, Edge E)
// {
// 	Graph->G[E->V1][E->V2] = 1;
// 	//如果是一个无向图
// 	Graph->G[E->V2][E->V1] = 1;
// }

// MGraph BuildGraph()
// {
// 	MGraph Graph;
// 	int Nv;
// 	int i;
// 	//Vertex V;
// 	scanf("%d", &Nv);
// 	Graph = CreateGraph(Nv);
// 	scanf("%d", &(Graph->Ve));
// 	if(Graph->Ve != 0)
// 	{
// 		Edge E = (Edge)malloc(sizeof(struct ENode));
// 		for(i = 0; i<Graph->Ve; i++)
// 		{
// 			//scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
// 			scanf("%d %d", &E->V1, &E->V2);
// 			InsertEdge(Graph, E); 
// 		}
// 	}

// 	/*如果顶点有数据，读入数据*/
// 	// for(V = 0; V < Graph->Nv ; V ++)
// 	// {
// 	// 	scanf("%c", &(Graph->Data[V]));
// 	// }

// 	return Graph;
// }

// int visited[MaxVertexNum];

// /*Depth First Search*/
// void DFS(int v, MGraph graph)
// {
// 	visited[v] = 1;
// 	printf(" %d",v);
// 	/*从第V个顶点出发访问图*/
// 	for(int i=0; i < graph->Nv; i++)
// 	{
// 		if(!visited[i] && graph->G[v][i])
// 		{
// 			DFS(i, graph);
// 		}
// 	}
// }

// /*breadth first search*/
// void BFS(int v, MGraph graph)
// {
// 	int Q[graph->Nv];//创建一个队列
// 	int front = -1;
// 	int rear = -1;
// 	Q[++rear] = v;
// 	visited[v] = 1;
// 	while(front < rear)
// 	{
// 		int de = Q[++front]; //出队
// 		printf(" %d",de);
// 		for(int i = 0; i< graph->Nv; i++)
// 		{
// 			if(visited[i] !=1 && graph->G[de][i])
// 			{
// 				visited[i] = 1;
// 				Q[++rear] = i; //入队操作
// 			}
// 		}

// 	}
// }

// void Show(MGraph graph)
// {
// 	for(int i=0; i < graph->Nv; i++)
// 	{
// 		for(int j=0; j < graph->Nv; j++)
// 		{
// 			printf("%d", graph->G[i][j]);
// 		}
// 		printf("\n");
// 	}

// }


// void Print(MGraph graph, char ch[])
// {
// 	for(int i = 0; i < graph->Nv; i++)
// 	{
// 		visited[i] = 0;  /*初始化visited数组*/
// 	}

// 	for(int i=0; i < graph->Nv; i++)
// 	{
// 		if(!visited[i])
// 		{
// 			printf("{");
// 			if(!strcmp(ch,B))
// 				BFS(i, graph);
// 			else if(!strcmp(ch,D))
// 				DFS(i, graph);
// 			printf(" }\n");
// 		}
// 	}
// }

// int main()
// {
// 	MGraph graph = BuildGraph();
// 	Show(graph);
// 	Print(graph,D);
// 	Print(graph,B);
// }



// typedef struct GNode *PtrToGNode;
// struct GNode
// {
// 	int Nv;
// 	int Ne;
// 	AdjList G;
// }
// typedef PtrToGNode LGraph;


// typedef struct Vnode
// {
// 	PtrToAdjVNode FirstEdge;

// }AdjList[MaxVertexNum];


// typedef struct AdjVNode *PtrToAdjVNode;
// struct AdjVNode
// {
// 	Vertex Adjv;
// 	WeightType Weight;
// 	PtrToAdjVNode Next;
// };

// LGraph CreateGraph(int VertexNum)
// {
// 	Vertex V, W;
// 	LGraph Graph;
// 	Graph = (LGraph)malloc(sizeof(struct GNode));
// 	Graph->Nv = VertexNum;
// 	Graph->Ve = 0;

// 	for(V = 0; V < VertexNum; V++)
// 		{
// 			Graph->G[V].FirstEdge = NULL;
// 		}
// 	return Graph;
// }

// void InsertEdge(LGraph Graph, Edge E)
// {
// 	 PtrToAdjVNode NewNode;
// 	/***************** 插入边 <V1, V2> ****************/
// 	/* 为V2建立新的邻接点 */
// 	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
// 	NewNode->AdjV = E->V2;
// 	NewNode->Weight = E->Weight;
// 	/* 将V2插入V1的表头 */
// 	NewNode->Next = Graph->G[E->V1].FirstEdge;
// 	Graph->G[E->V1].FirstEdge = NewNode;
// 	/********** 若是无向图，还要插入边 <V2, V1> **********/
// 	/* 为V1建立新的邻接点 */
// 	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
// 	NewNode->AdjV = E->V1;
// 	NewNode->Weight = E->Weight;
// 	/* 将V1插入V2的表头 */
// 	NewNode->Next = Graph->G[E->V2].FirstEdge;
// 	Graph->G[E->V2].FirstEdge = NewNode;
// }

// /*06-图2 Saving James Bond - Easy Version*/
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>

// #define MAXN 100

// typedef struct Node
// {
//  	int  X;
//  	int Y;
// }Coord; /*Coordinate 坐标*/
// Coord List[MAXN];

// void Print(Coord G[], int size);
// int IsSafe(int V);
// int Jump(int V, int W);
// int FirstJump(int V);
// int DFS(int V);
// void Save007();
// /*这里用指针数组并不对，具体还要分析一下子*/


// int visited[MAXN];
// int Number;  /*the number of crocodile*/
// int Distance; /*the distance james bond can jump*/
// const double ISLAND_RADIUS = 15.0 / 2; /*the diameter of the island is 15*/

// int main()
// {
// 	scanf("%d %d", &Number, &Distance);

// 	for(int i = 0; i < Number; i++)
// 	{
// 		visited[i] = 0;
// 		scanf("%d",&List[i].X);
// 		scanf("%d",&List[i].Y);
// 	}
// 	//Print(List, Number);
// 	//printf("%d" ,Jump(1,2));
// 	Save007();

// 	return 0;
// }

// void Save007()
// {
// 	int save = 0;
// 	for(int i = 0; i < Number; i++)
// 	{
// 		if(!visited[i] && FirstJump(i))
// 		{
// 			save = DFS(i);
// 			if(save)
// 			{
// 				break;
// 			}	
// 		}
// 	} 
// 	if(save)
// 		printf("Yes\n");
// 	else
// 		printf("No\n");

// }

// void Print(Coord G[], int size)
// {
// 	for(int i = 0; i < size; i++)
// 	{
// 		printf("%d ", G[i].X);
// 		printf("%d\n", G[i].Y);
// 	}
// }

// int FirstJump(int V)
// {
// 	double Z;
// 	Z = sqrt(List[V].X * List[V].X + List[V].Y * List[V].Y);
// 	return Z <= (Distance + ISLAND_RADIUS) ? 1 : 0;
// }

// int Jump(int V, int W)
// {
// 	double Z;
// 	Z = sqrt((List[V].X - List[W].X)*(List[V].X - List[W].X) + (List[V].Y - List[W].Y)*(List[V].Y - List[W].Y));
// 	return Distance >= Z ? 1 : 0;
// }

// int IsSafe(int V)
// {
// 	return ((50 - abs(List[V].X)) <= Distance || (50 - abs(List[V].Y)) <= Distance)? 1 : 0;
// }

// int DFS(int V)
// {
// 	visited[V] = 1;
// 	int answer = 0;
// 	if(IsSafe(V))
// 	{
// 		answer = 1;
// 	}
// 	else
// 	{
// 		for(int i = 0; i < Number; i++)
// 			if(!visited[i]  && Jump(V, i))
// 			{
// 				answer = DFS(i);
// 				if(answer)
// 				{
// 					break;
// 				}
// 			}
// 	}
// 	return answer;
// }

// #include<stdio.h>
// #include<stdlib.h>

// #define MaxVertexNum 10000
// typedef int Vertex;
// typedef int DataType;
// typedef int ElementType;

// /****************************图的建立开始*************************************/
// /*这里用邻接表来表示：G[N]为指针数组,对应矩阵每行一个链表，只存非0元素*/
// /**/
// /*边的定义*/
// typedef struct ENode *PtrToENode;
// struct ENode
// {
// 	Vertex V1, V2;
// 	//WeightType Weight;

// };
// typedef PtrToENode Edge;

// /*邻接点的定义*/
// typedef struct AdjVNode *PtrToAdjVNode;
// struct AdjVNode
// {
// 	Vertex AdjV;
// 	//WeightType Weight  /*边权重*/
// 	PtrToAdjVNode Next;
// };

// /*顶点表头结点定义*/
// typedef struct Vnode
// {
// 	PtrToAdjVNode FirstEdge;
// 	//DataType Data /*存顶点的数据*/
// }AdjList[MaxVertexNum];


// /*图的定义*/
// typedef struct GNode *PtrToGNode;
// struct GNode
// {
// 	int Nv;
// 	int Ne;
// 	AdjList G;
// };
// typedef PtrToGNode LGraph;

// LGraph CreateGraph(int VertexNum);
// void InsertEdge(LGraph Graph, Edge E);
// LGraph BuildGraph();

// /*初始化一个有VertexNum个顶点，没有边的图*/
// LGraph CreateGraph(int VertexNum)
// {
// 	Vertex V;
// 	LGraph Graph;
// 	Graph = (LGraph)malloc(sizeof(struct GNode));
// 	Graph->Nv = VertexNum;
// 	Graph->Ne = 0;
// 	for(V = 0; V < Graph->Nv; V++)
// 		Graph->G[V].FirstEdge = NULL;
// 	return Graph;
// }

// /*插入图的边*/
// void InsertEdge(LGraph Graph, Edge E)
// {
// 	/**********************插入边<V1, V2>**************************/
// 	PtrToAdjVNode NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
// 	NewNode->AdjV = E->V2;
// 	//NewNode->Weight = E->Weight;
// 	NewNode->Next = Graph->G[E->V1].FirstEdge;
// 	Graph->G[E->V1].FirstEdge = NewNode;

// 	/****************若为无向图，还需要插入<V2, V1>*****************/
// 	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
// 	NewNode->AdjV = E->V1;
// 	//NewNode->Weight = E->Weight;
// 	NewNode->Next = Graph->G[E->V2].FirstEdge;
// 	Graph->G[E->V2].FirstEdge = NewNode;
// }

// /*完整建立一个LGraph*/
// LGraph BuildGraph()
// {
// 	LGraph Graph;
// 	Edge  E;
// 	//Vertex V;
// 	int Nv, i;
// 	scanf("%d", &Nv);
// 	Graph = CreateGraph(Nv);
// 	scanf("%d", &(Graph->Ne));
// 	if(Graph->Ne != 0)
// 	{
// 		E = (Edge)malloc(sizeof(struct ENode));
// 		for(i = 0; i < Graph->Ne; i++)
// 		{
// 			scanf("%d %d", &(E->V1), &(E->V2));
// 			//scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
// 			InsertEdge(Graph, E);
// 		}
// 	}

// 	//如果顶点有数据，读入数据
// 	// for(V = 0; V < Graph->Nv; V++)
// 	// {
// 	// 	scanf("%c", &Graph->Data[V]);
// 	// }

// 	return Graph;
// }

// /****************************图的建立结束*************************************/




// int visited[MaxVertexNum];
// void InitVisited()
// {
//     for(int i = 0; i < MaxVertexNum; i++)
//         visited[i] = 0;
// }  
// /****************************队列的建立开始***********************************/
// #define MAXSIZE 10000
// typedef struct
// {
//     ElementType Data[MAXSIZE];
//     int front;
//     int rear;
// }Queue;


// void InitQ(Queue *PtrQ)
// {
// 	//循环队列这里要取0？？？
// 	PtrQ->front = PtrQ->rear = 0;
// }

// /*队列插入操作*/
// /*这里判断队列为空或者为满，是基于队列少用一个元素*/
// void Enqueue(Queue *PtrQ, ElementType item)
// {
//     if((PtrQ->rear+1)%MAXSIZE == PtrQ->front)
//     {
//         printf("队列满");
//         return;
//     }
//     PtrQ->rear = (PtrQ->rear+1) % MAXSIZE;
//     PtrQ->Data[PtrQ->rear] = item;
// }

// /*队列删除操作*/
// /*基于队列少用一个元素,front指向的位置其实并没有元素*/
// ElementType Dequeue(Queue *PtrQ)
// {
//     if(PtrQ->rear == PtrQ->front)
//     {
//         printf("队列为空"); 
//     }
//     PtrQ->front = (PtrQ->front+1) % MAXSIZE;
//     return PtrQ->Data[PtrQ->front];
// }

// int IsEmpty(Queue *PtrQ)
// {
// 	return PtrQ->rear == PtrQ->front;
// }
// /****************************队列的建立结束***********************************/

// int BFS(LGraph Graph, Vertex V)
// {

// 	/*这里有个很大的问题，Queue *Q Init(Q)不对*/
// 	Queue Q;
// 	InitQ(&Q);
// 	visited[V] = 1;
// 	int count = 1;
// 	int level = 0;
// 	Vertex last = V, tail;

// 	Enqueue(&Q, V);
// 	while(!IsEmpty(&Q))
// 	{
// 		V = Dequeue(&Q);
// 		for(PtrToAdjVNode W = Graph->G[V].FirstEdge; W; W=W->Next)
// 		{
// 			if(!visited[W->AdjV])
// 			{
// 				visited[W->AdjV] = 1;
// 				Enqueue(&Q, W->AdjV);
// 				count ++;
// 				tail = W->AdjV;
// 			}
// 		}
// 		if(V == last)
// 		{
// 			level ++;
// 			last = tail;
// 		}
// 		if(level == 6)
// 		{
// 			break;
// 		}
// 	}
// 	return count;
// }


// int main()
// {
// 	LGraph graph;
// 	graph = BuildGraph();
//     for(int i = 1; i <= graph->Nv; i++) 
//     {
// 	    InitVisited();
// 	    int count = BFS(graph, i);
// 	    printf("%d: %.2f%%\n",i,count*100.0/graph->Nv);
//     }
//     return 0;
// }



// /*03-树3 Tree Traversals Again（25 分）*/
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// void solve(int preL, int inL, int postL, int n);

// /******************Stack Definition**********************/
// #define ERROR -1
// #define MAXSIZE 30
// #define ElementType int
// typedef struct 
// {
// 	int Data[MAXSIZE];
// 	int Top;
// }Stack;

// void Push(Stack *PtrS, ElementType item)
// {
// 	if(PtrS->Top == MAXSIZE - 1)
// 	{
// 		//printf("堆栈满");
// 		return;
// 	}
// 	else
// 	{
// 		PtrS->Data[++(PtrS->Top)] = item;
// 		return;
// 	}
// }

// ElementType Pop(Stack *PtrS)
// {
// 	if(PtrS->Top == -1)
// 	{
// 		//printf("堆栈空");
// 		return ERROR;
// 	}
// 	else
// 	{
// 		return PtrS->Data[(PtrS->Top)--];
// 	}
// }
// /******************Stack End****************************/
// #define STR_LEN 5
// int pre[MAXSIZE];
// int count1 = 0;
// int in[MAXSIZE];
// int count2 = 0;
// int post[MAXSIZE];

// void solve(int preL, int inL, int postL, int n);
// int main()
// {
// 	int n;
// 	int value;
// 	char operation[STR_LEN];

// 	Stack S;
// 	S.Top = -1;

// 	scanf("%d", &n);
	
// 	for(int i = 0; i < 2 * n; i++)
// 	{
// 		scanf("%s", operation);
// 		/*strcmp() returns 0 when two string is the same*/
// 		/*这里花了非常多的时间，还以为什么错了呢*/
// 		if(!strcmp(operation, "Push"))
// 		{
// 			scanf("%d", &value);
// 			Push(&S, value);
// 			pre[count1++] = value;
	
// 		}
// 		else
// 		{
// 			value = Pop(&S);
// 			in[count2++] = value;
// 		}
// 	}

// 	solve(0, 0, 0, n);

// 	for(int i = 0; i < n-1; i++)
// 	{
// 		printf("%d ", post[i]);
// 	}
// 	printf("%d", post[n-1]);

// }


// /******************Pre In To Post***********************/
// void solve(int preL, int inL, int postL, int n)
// {
// 	int root;
// 	int L;
// 	int R;
// 	int i;
// 	if(n == 0) return;
// 	if(n == 1)
// 	{
// 		post[postL] = pre[preL];
// 		return;
// 	}

// 	root = pre[preL];
// 	post[postL + n - 1] = root;
// 	for(i = 0; i < n; i++)
// 	{
// 		if(in[inL+i] == root)
// 			break;
// 	} 
// 	L = i;
// 	R = n - L - 1;
// 	solve(preL + 1, inL, postL, i);
// 	solve(preL + L + 1, inL + L + 1, postL + L, R);
// }


// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #define MAXSIZE 1000

// #define min(a, b)  (a) < (b) ? (a) : (b)

// int T[MAXSIZE];
// int A[MAXSIZE];

// int GetLeftLength(int n)
// {
// 	int height;
// 	int LeftNum;
// 	int LastLevelNum;
// 	/*C语言取整的函数，floor() ceil()*/
// 	height = floor(log(n + 1) / log(2));
// 	LastLevelNum = n + 1 - pow(2, height);
// 	LastLevelNum = min(LastLevelNum, pow(2, height - 1));

// 	LeftNum = pow(2, height-1) - 1 + LastLevelNum;
// 	return LeftNum;
// }

// void solve(int Aleft, int Aright, int TRoot)
// {
// 	int LeftTRoot;
// 	int RightTRoot;
// 	/*A为已经从小到大拍好序列*/
// 	/*初始调用solve(0, N-1,0)*/
// 	int n = Aright - Aleft + 1;
// 	if(n == 0) return;

// 	int L;
// 	L = GetLeftLength(n);
// 	/*根结点的元素*/
// 	T[TRoot] = A[Aleft + L];

// 	LeftTRoot = TRoot * 2 + 1;
// 	RightTRoot = LeftTRoot + 1;

// 	solve(Aleft, Aleft + L - 1, LeftTRoot);
// 	solve(Aleft + L + 1, Aright, RightTRoot);

// }

// /*这个看不太懂啊*/
// int compare(const void * a, const void * b)
// {
// 	return (*(int *)a - *(int *)b);
// }

// int main()
// {
// 	int N;
// 	scanf("%d", &N);
	
// 	int i;
// 	for(i = 0; i < N; i++)
// 	{
// 		scanf("%d", &A[i]);
// 	}

// 	qsort(A, N, sizeof(int), compare);

// 	//printf("The length of the left tree is:%d\n", GetLeftLength(N));
	
// 	solve(0, N-1, 0);

// 	for(int i = 0; i < N-1; i++)
// 	{
// 		printf("%d ", T[i]);
// 	}

// 	printf("%d", T[N-1]);
// }

// /*07-图4 哈利·波特的考试（25 分）*/
// #include<stdio.h>
// #include<stdlib.h>

// #define MaxVertexNum 100 /*最大的顶点数目*/
// #define INFINITY 65536  /*unsigned double(16bits) max 65536*/
// typedef int Vertex;   /*用顶点下标表示顶点，为整型*/
// typedef int WeightType; /*边的权值*/
// //typedef char DataType; /*顶点存储的数据类型*/

// /*边的定义*/
// typedef	struct ENode *PtrToENode;
// struct ENode
// {
// 	Vertex V1, V2;  /*有向边<v1, v2>*/
// 	WeightType Weight; /*权重*/
// };
// typedef PtrToENode Edge;

// /*图结点的定义*/
// typedef struct GNode *PtrToGNode;
// struct GNode
// {
// 	int Nv; /*顶点树目*/
// 	int Ne; /*边数目*/
// 	WeightType G[MaxVertexNum][MaxVertexNum]; /*邻接矩阵*/
// //	DataType Data[MaxVertexNum]; /*存储顶点的数据*/
// };
// typedef PtrToGNode MGraph; /*以邻接矩阵存储的图类型*/

// MGraph CreateGraph(int VertexNum)
// {
// 	Vertex V, W;
// 	MGraph Graph;

// 	Graph = (MGraph)malloc(sizeof(struct GNode));
// 	Graph->Nv = VertexNum;
// 	Graph->Ne = 0;

// 	for( V = 0; V < Graph->Nv; V++)
// 	{
// 		for(W = 0; W < Graph->Nv; W++)
// 		{
// 			Graph->G[V][W] = INFINITY;
// 		}
// 	}
// 	return Graph;
// }

// void InsertEdge(MGraph Graph, Edge E)
// {
// 	/*插入边*/
// 	Graph->G[E->V1][E->V2] = E->Weight;
// 	/*无向图，插入*/
// 	Graph->G[E->V2][E->V1] = E->Weight;
// }

// MGraph BuildGraph()
// {
// 	MGraph Graph;
// 	Edge E;
// 	// Vertex V;
// 	int Nv, i;

// 	scanf("%d", &Nv);  /*读入顶点个数*/
// 	Graph = CreateGraph(Nv); /*初始化有Nv个顶点但是没有边的图*/

// 	scanf("%d", &(Graph->Ne)); /*读入边数目*/

// 	if(Graph->Ne != 0) /*如果有边*/
// 	{
// 		E = (Edge)malloc(sizeof(struct ENode));
// 		for(i = 0; i < Graph->Ne; i++)
// 		{
// 			/*读入格式，起点，终点，权重*/
// 			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
// 			E->V1--;
// 			E->V2--;    /*编号修改为0*/
// 			InsertEdge(Graph, E);
// 		}
// 	}

// 	/*如果顶点有数据的话，读入数据*/
// 	// for(V = 0; V < Graph->Nv; V++)
// 	// {
// 	// 	scanf(" %c", &(Graph->Data[V]));
// 	// }

// 	return Graph;
// }

// void /*bool*/ Floyd(MGraph Graph, WeightType D[][MaxVertexNum] /*, Vertex path[][MaxVertexNum]*/)
// {
// 	Vertex i, j, k;
// 	for(i = 0; i < Graph->Nv; i++)
// 	{
// 		for(j = 0; j < Graph->Nv; j++)
// 		{
// 			D[i][j] = Graph->G[i][j];
// 			// path[i][j] = 1;
// 		}
// 	}

// 	for(k = 0; k < Graph->Nv; k++)
// 	{
// 		for(i = 0; i < Graph->Nv; i++)
// 		{
// 			for(j = 0; j < Graph->Nv; j++)
// 			{
// 				if(D[i][k] + D[k][j] < D[i][j])
// 				{
// 					D[i][j] = D[i][k] + D[k][j];
// 					// if(i == j && D[i][j] < 0)   /*如果发现负值圈*/
// 					// 	return false
// 					// path[i][j] = k;
// 				}
// 			}
// 		}
// 	}

// 	// return true;

// }

// WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex i, int 	N)
// {
// 	WeightType MaxDist;
// 	Vertex j;
// 	MaxDist = 0;

// 	for(j = 0; j < N; j++)
// 	{
// 		if(i !=j && D[i][j] > MaxDist)  /*对角元素为无穷大*/
// 		{
// 			MaxDist = D[i][j];
// 		}
// 	}
// 	return MaxDist;
// }


// void FindAnimal(MGraph Graph)
// {
// 	WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
// 	Vertex Aninal, i;

// 	Floyd(Graph , D);
// 	MinDist = INFINITY;
// 	for(i = 0; i < Graph->Nv; i++)
// 	{
// 		MaxDist = FindMaxDist(D, i, Graph->Nv);

// 		if(MaxDist == INFINITY)  /*图不连通的情况*/
// 		{
// 			printf("0\n");
// 			return ;
// 		}

// 		if(MinDist > MaxDist)
// 		{
// 			MinDist = MaxDist;
// 			Aninal = i + 1;
// 		}
// 	}
// 	printf("%d %d\n", Aninal, MinDist);
// }

// int main()
// {
// 	MGraph G = BuildGraph();
// 	FindAnimal(G);
// 	return 0;
// } 


// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>

// #define MAXN 100

// typedef struct Node
// {
//  	int  X;
//  	int Y;
// }Coord; /*Coordinate 坐标*/
// Coord List[MAXN];

// void Print(Coord G[], int size);
// int IsSafe(int V);
// int Jump(int V, int W);
// int FirstJump(int V);
// int DFS(int V);
// void Save007();
// /*这里用指针数组并不对，具体还要分析一下子*/


// int visited[MAXN];
// int Number;  /*the number of crocodile*/
// int Distance; /*the distance james bond can jump*/
// const double ISLAND_RADIUS = 15.0 / 2; /*the diameter of the island is 15*/


// int main()
// {
// 	scanf("%d", &Number);
// 	scanf("%d", &Distance);
	
// 	for(int i = 0; i < Number; i++)
// 	{
// 		visited[i] = 0;
// 		scanf("%d",&List[i].X);
// 		scanf("%d",&List[i].Y);
// 	}
// 	//Print(List, Number);
// 	//printf("%d" ,Jump(1,2));
// 	Save007();

// 	return 0;
// }


// void Save007()
// {
// 	int save = 0;
// 	if((Distance + ISLAND_RADIUS) > 50)
// 	{
// 		printf("Yes\n");
// 		return;
// 	}
// 	for(int i = 0; i < Number; i++)
// 	{
// 		if(!visited[i] && FirstJump(i))
// 		{
// 			save = DFS(i);
// 			if(save)
// 			{
// 				break;
// 			}	
// 		}
// 	} 
// 	if(save)
// 		printf("Yes\n");
// 	else
// 		printf("No\n");

// }


// void Print(Coord G[], int size)
// {
// 	for(int i = 0; i < size; i++)
// 	{
// 		printf("%d ", G[i].X);
// 		printf("%d\n", G[i].Y);
// 	}
// }


// int FirstJump(int V)
// {
// 	double Z;
// 	Z = sqrt(List[V].X * List[V].X + List[V].Y * List[V].Y);
// 	return Z <= Distance + ISLAND_RADIUS ? 1 : 0;
// }


// int Jump(int V, int W)
// {

// 	double Z;
// 	Z = sqrt((List[V].X - List[W].X)*(List[V].X - List[W].X) + (List[V].Y - List[W].Y)*(List[V].Y - List[W].Y));
// 	return Distance >= Z ? 1 : 0;

// }


// int IsSafe(int V)
// {

// 	return ((50 - abs(List[V].X)) <= Distance || (50 - abs(List[V].Y)) <= Distance)? 1 : 0;

// }



// int DFS(int V)
// {

// 	visited[V] = 1;
// 	int answer = 0;
// 	if(IsSafe(V))
// 	{
// 		answer = 1;
// 	}
// 	else
// 	{
// 		for(int i = 0; i < Number; i++)
// 			if(!visited[i]  && Jump(V, i))
// 			{
// 				answer = DFS(i);
// 				if(answer)
// 				{
// 					break;
// 				}
// 			}
// 	}
// 	return answer;

// }



// void Unweighted(Vertex S)
// {

// 	Enqueue(S, Q);

// 	while(!IsEmpty(Q))
// 	{

// 		V = Dequeue(Q);

// 		for(V 邻接点 W)

// 			if(dist[W] == -1)
// 			{
// 				dist[W] = dist[V] + 1;
// 				path[W] = V;  
// 				Enqueue(W, Q);
// 			}

// 	}

// }
 

// void Prim(MGraph * G, int Parent[])
// {
// 	/*默认从序号为0的顶点出发*/
// 	int LowCost[MaxVertexNum];
// 	int i, j, k;
// 	for(i = 0; i < G->n; i++)
// 	{
// 		/*这里如果有边没有和0顶点相连，初始的lowcost应该为无穷大*/
// 		LowCost[i] = G->Edge[0][i];
// 		/*暂时认为所有顶点的父节点是0(根结点)*/
// 		Parent[i] = 0;
// 	}

// 	LowCost[0] = 0;/*序号为0的顶点出发生成最小生成树*/
// 	Parent[0] = -1;/*树的根节点*/
// 	for(i = 0; i < G->n; i++)
// 	{
// 		k = FindMin(LowCost, G->n); /*从剩余顶点中找到这棵树最短距离的顶点*/
// 		if(k)/*如果可以找到这样的顶点*/
// 		{
// 			LowCost[k] = 0;
// 			/*更新当前的最小生成树*/
// 			for(j = 1 ; j < G->n; j++)
// 			{
// 				if(LowCost[j] && G->Edge[k][j] < LowCost[j])
// 				{
// 					LowCost[j] = G->Edge[k][j];/*更新最小距离*/
// 					Parent[j] = k; /*暂时认为顶点j的父节点为k*/
// 				}
// 			}

// 		}
// 		else
// 		{
// 			printf("图不连通");
// 			break;
// 		}
// 	}
// }


// void Kruskal(Graph G)
// {
// 	T = {};
// 	while(T中收集的边不到n-1 && 原图的边集合非空)
// 	{
// 		E中选择最小的边(v, w); /*最小堆来完成*/
// 		E中删除这个边(v, w);
// 		if((v, w) 不在T中构成回路)
// 		{
// 			Add (v, w) to T; /*并查集完成*/
// 		}
// 		else
// 		{
// 			ignore(v, w);
// 		}
// 	}
// 	if(T中的边不到n-1条)
// 		printf("不连通")
// }


// #include<stdio.h>
// #include<stdlib.h>

// #define MAXV 1000

// typedef int Vertex;
// struct EdgeType
// {
// 	Vertex V1, V2;
// 	int W;
// };

// typedef int DisjSet[MAXV + 1];
// DisjSet VSet;
// struct EdgeType *ESet; /*边数组？？？？*/


// /*结点并查集相关的函数*/
// void InitilializeVset(int N)
// {
// 	while(N)
// 	{
// 		VSet[N--] = -1;
// 	}
// }


// Vertex Find(Vertex V)
// {
// 	Vertex root, trail, lead;

// 	/*寻找V所在的集合的根root*/
// 	for(root = V; VSet[root] > 0; root = VSet[root]);
	
// 	/*路径压缩*/
// 	for(trail = V; trail != root; trail = lead)
// 	{
// 		lead = VSet[trail];
// 		VSet[trail] = root;
// 	}
// 	return root;	
// } 

// void SetUnion(Vertex Root1, Vertex Root2)
// {
// 	/*这里按照规模合并，把小的集合合并到大的集合上面*/
// 	if(VSet[Root2] < VSet[Root1]) /*root1合并入root2*/
// 	{
// 		VSet[Root2] += VSet[Root1];
// 		VSet[Root1] = Root2; 
// 	}
// 	else /*root2合并入root1里面*/
// 	{
// 		VSet[Root1] += VSet[Root2];
// 		VSet[Root2] = Root1;
// 	}


// }



// /*边的最小堆的问题*/
// void MinHeap(int i, int M)
// {
// 	/*将M个元素的数组中以Eset[i]为根的子堆调整为最小堆*/
// 	int child;
// 	struct EdgeType temp;

// 	temp = ESet[i];
// 	for(; ((i <<1) + 1) < M; i = child)
// 	{
// 		child = (i << 1) + 1;
// 		if(child != M -1 && ESet[child + 1].W < ESet[child].W)
// 		{
// 			child ++;
// 		}
// 		if(temp.W > ESet[child].W)
// 		{
// 			ESet[i] = ESet[child];
// 		}
// 		else
// 		{
// 			break;
// 		}
// 	}

// 	ESet[i] = temp;
// }



// void InitizlizeEset(int M)
// {
// 	/*初始化最小堆*/
// 	int i;
// 	for(i = M/2; i >= 0; i--)
// 	{
// 		MinHeap(i, M);
// 	}
// }


// int GetEdge(int CurrentSize)
// {
// 	/*给定当前堆的大小Currentsize，将当前最小位置弹出并且调整最小堆*/
// 	struct EdgeType temp;

// 	/*将最小边和当前堆的最后一个位置的边互换*/
// 	temp = ESet[0];
// 	ESet[0] = ESet[CurrentSize - 1];
// 	ESet[CurrentSize - 1] = temp;

// 	MinHeap(0, CurrentSize -1);
// 	return CurrentSize - 1;
// }


// int checkCycle(Vertex V1, Vertex V2)
// {
// 	/*检查V1, V2的边是否在现在的最小生成树中构成了回路*/
// 	Vertex Root1 = Find(V1); /*V1所属的连通集*/
// 	Vertex Root2 = Find(V2); /*V2所属的连通集*/
// 	if(Root1 == Root2)
// 	{
// 		return 0;
// 	}
// 	else
// 	{
// 		SetUnion(V1, V2);
// 		return 1;
// 	}
// }

// int Kruskal(int N, int M)
// {
// 	/*给定结点和边的数目，返回最小生成树的总权重和*/
// 	int EdgeN = 0;
// 	int Cost = 0;

// 	int NextEdge = M;

// 	InitilializeVset(N);

// 	InitizlizeEset(M);

// 	while(EdgeN < N - 1)
// 	{
		
// 		if(NextEdge <= 0)
// 			break;
// 		NextEdge = GetEdge(NextEdge);
// 		if(checkCycle(ESet[NextEdge].V1, ESet[NextEdge].V2))
// 		{
// 			Cost += ESet[NextEdge].W;
// 			printf("Cost is: %d\n" ,Cost);
// 			EdgeN ++;
// 		}
// 	}

// 	if(EdgeN < N - 1) Cost = -1;

// 	return Cost;
// }



// int main()
// {
// 	/*N means number of towns*/
// 	/*M means number of roads*/
// 	int N, M, i;

// 	scanf("%d %d", &N, &M);

// 	if(M < N-1)
// 	{
// 		printf("-1\n");
// 	}
// 	else
// 	{
// 		ESet = malloc( sizeof(struct EdgeType) * M );
// 		for(i = 0; i < M; i++)
// 		{
// 			scanf("%d %d %d", &ESet[i].V1, &ESet[i].V2, &ESet[i].W);
// 		}
// 		printf("%d\n", Kruskal(N, M));
// 	}

// 	return 0;
// }



// void  Bubble_Sort(ElementType A[], int N)
// {
// 	int i, j;
// 	int flag;
// 	ElementType temp;

// 	for(i = N-1; i >= 0; i--)
// 	{
// 		flag = 0;
// 		/*每次循环找出一个最大的元素，交换到最右边*/
// 		for(j = 0; j < i; j++)
// 		{
// 			if(A[j] > A[j+1])
// 			{
// 				temp = A[j];
// 				A[j] = A[j+1];
// 				A[j+1] = temp;
// 				flag = 1;
// 			}
// 		}
// 		if(flag == 0)
// 		{
// 			break;
// 		}
// 	}
// }





// void InsertionSort(ElementType	A[], int N)
// {
// 	int i, j;
// 	ElmentType temp;

// 	for(i = 1; i < N; i++)
// 	{
// 		/*取出未排序序列中的第一个元素*/
// 		temp = A[i];
// 		/*把元素取出来依次和已排序序列中元素比较右移*/
// 		for(j = i; (j>0) && (temp < A[j - 1]); j--)
// 		{
// 			A[j] = A[j - 1];
// 		}
// 		A[j] = temp;
// 	}
// }

// /*incre为M个增量序列，递减，最后一个元素为1*/
void Shell_sort(ElementType A[], int N, int Incre[], int M)
{
// 	int i, j, k, Increment;
// 	ElementType temp;
// 	/*M为增量序列数组的元素个数*/
// 	for(i = 0; i < M; i++)
// 	{
// 		Increment = Incre[i];
// 		/*这个循环就是简单插入排序的循环*/
// 		for(j = Increment; j < N; j++)
// 		{
// 			temp = A[j];
// 			for(k = j; k - Increment >= 0; k -= Increment)
// 			{
// 				if(temp >= A[k - Increment])
// 					break;
// 				else
// 					A[k] = A[k - Increment];
// 				A[k] = temp;
// 			}
// 		}
// 	}
// }

// /*选择排序*/
// void SimpleSelection_Sort(ElementType A[], int N)
// {
// 	int i, j, min, temp;
// 	for(i = 0; i < N-1; i++)
// 	{
// 		min = i;
// 		for(j = i + 1; j < N; j++)
// 		{
// 			if(A[j] < A[min])
// 				min = j;

// 		}
// 		temp = A[i];
// 		A[i] = A[min];
// 		A[min] = temp;
// 	}
// }

// /*堆排序算法1*/
// /*时间复杂度为O(NlogN)，但是需要一个额外的数组Temp，对于空间耗费比较大*/
// /*不可取*/
// void Heap_Sort(ElmentType A[], int N)
// {
// 	/*线性时间复杂度的算法把一个数组调整为一个个最小堆*/
// 	BuildHeap(A);
// 	for(int i =0; i < N; i++)
// 	{
// 		Temp[i] = DeleteMin(A);
// 	}
	
// 	for(i = 0; i < N; i++)
// 	{
// 		A[i] = Temp[i];
// 	}
// }

// /*堆排序算法2*/
// /*建立一个最大堆，把堆出来的元素放在最后一个数组，把最后一个元素去掉组成的堆继续Deltete*/

// void Heap_Sort(ElementType A[], int N)
// {
// 	int i;
// 	ElementType temp;

// 	/*建立最大堆*/
// 	for(i = (N-1)/2; i >= 0; i--)/*从有儿子的最后一个结点开始*/
// 	{
// 		Adjust(A, i, N);
// 	}

// 	for(i = N-1; i > 0; i--)
// 	{
// 		temp = A[0];
// 		A[0]= A[i];
// 		A[i] = temp;
// 		Adjust(A, 0, i);
// 	}

// }


// void Adjust(ElementType A[], int i, int N)
// {
// 	int Child;
// 	ElementType temp;

// 	temp = A[i];

// 	for(; (2 * i + 1) < N; i = Child)
// 	{
// 		/*左孩子结点*/
// 		Child = 2 * i + 1;
// 		/*child指向左右子结点中大的结点*/
// 		if((Child != N - 1 )&&(A[Child] < A[Child + 1]))
// 			Child ++;

// 		if(temp < A[Child])
// 			A[i] = A[child];
// 		else
// 			break
// 	}
// 	A[i] = temp;
// }


// /*A待排序列 TempA临时数组，L左边子序列起始位置  R右边子序列起始位置，RightEnd右边重点位置*/
// void Merge(ElementType A[], ElementType TempA[], int L, int R, int RightEnd)
// {
// 	int LeftEnd;
// 	int Tmp;

// 	Tmp = L
// 	LeftEnd = R - 1; /*左边终点位置，这里假设左右两列都是挨着的*/
// 	NumElements = RightEnd - L + 1;/*元素的个数记录一下子*/

// 	while(L <= LeftEnd && R < =RightEnd)
// 	{
// 		if(A[L] <= A[R])
// 		{
// 			TempA[Tmp++] = A[L++];
// 		}
// 		else
// 		{
// 			TempA[Tmp++] = A[R++];
// 		}
// 	}

// 	while(L <= LeftEnd)
// 		TempA[Tmp++] = A[L++];

// 	while(R <= RightEnd)
// 		TempA[Temp++] = A[R++];
// 	/*注意这里L已经不知道指导哪里了，Rightend还是在的*/
// 	for(int i = 0 ; i < NumElements; i++, RightEnd --)
// 	{
// 		A[RightEnd] = TempA[RightEnd];
// 	}
// }

// /*递归算法*/
// void Msort(ElementType A[], ElementType TempA[], int Left, int Right)
// {
// 	int center;
// 	if(Left < Right)
// 	{
// 		center = (Left + Right) / 2;
// 		Msort(A, TempA, Left, center);
// 		Msort(A, TempA, center + 1, Right);
// 		Merge(A, TempA, L, center+1, Right)
// 	}
// }

// /*统一函数的接口*/
// void Merge_sort(ElementType A[], int N)
// {
// 	ElementType *TempA;
// 	TempA = malloc(N * sizeof(ElementType));
// 	if(TempA != Null)
// 	{
// 		/*TempA数组在Msort函数里面调用的，但是不在Msort函数里面申请空间*/
// 		/*原因是需要不停调用malloc ，和free过程*/
// 		Msort(A, TempA, 0, N-1);
// 		free(TempA);
// 	}
// 	else Error("空间不足")
// }

// /*非递归算法*/
// void Merge_pass(ElementType A[], ElementType TempA[], int N, int length)
// {
// 	/*length指的是当前有序子列的长度，每一次加倍*/
// 	for(i = 0; i <= N - 2 * length; i += 2 * length)
// 		/*Merge1和Merge相比，最后的元素存在TempA[]中的*/
// 		Merge1(A, TempA, i, i + length, i + 2* length - 1);
// 	/*处理尾巴*/
// 	if(i+length < N) /*归并最后两个子列*/
// 		Merge1(A, TempA, i, i + length, N -1);
// 	else /*最后只有一个子列*/
// 		for(j = i; j < N; j++)
// 			TempA[j] = A[j];
// }

// /*统一函数的接口*/
// void Merge_sort(ElementType A[], int N)
// {
// 	ElementType *TempA;
// 	TempA = malloc(N * sizeof(ElementType));
// 	if(TempA != Null)
// 	{
// 		while(length < N)
// 		{
// 			Merge_pass(A, TempA, N, length);
// 			length *= 2;
// 			Merge_pass(TempA, A, N, length);
// 			length *= 2;
// 		}
// 		free(TempA);
// 	}
// 	else Error("空间不足");
// }





void QuickSort(int A[], )
/*用来得到主元*/
ElementType Median3(ElementType A[], int Left, int Right)
{
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
		Swap(&A[center], &A[Right]);
	}

	/*A[Left] < A[Center] < A[Right]*/

	Swap(&A[center], &A[Right - 1 ]);
	/*只需要考虑A[Left + 1].....A[Right-2]*/
	return A[Right - 1]; /*主元Pivot*/

}

void QuickSort(ElementType A[], int Left, int Right)
{
	
	if(Cutoff <= Right - Left)
	{
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
				Swap(&A[i], &A[j]);
			else
				break;
		}

		Swap(&A[i], &A[Right - 1]);
		QuickSort(A, Left, i-1);
		QuickSort(A, i + 1, Right);
	}

	else
	{
		InsertionSort(A+Left,Right-Left+1);
	}

}
void Quick_Sort(ElementType A[], int N)
{
	QuickSort(A, 0, N-1);
}






/*非递归算法*/
void Merge_pass(ElementType A[], ElementType TempA[], int N, int length)
{
	
	int i;
	/*length指的是当前有序子列的长度，每一次加倍*/
	for(i = 0; i <= N - 2 * length; i += 2 * length)
		/*Merge1和Merge相比，最后的元素存在TempA[]中的*/
		Merge1(A, TempA, i, i + length, i + 2* length - 1);
	/*处理尾巴*/
	if(i+length < N) /*归并最后两个子列*/
		Merge1(A, TempA, i, i + length, N -1);
	else /*最后只有一个子列*/
		for(j = i; j < N; j++)
			TempA[j] = A[j];

}