 /* bo6-2.c �������Ķ��������洢(�洢�ṹ��c6-2.h����)�Ļ�������(22��) */
 Status InitBiTree(BiTree *T)
 { /* �������: ����ն�����T */
   *T=NULL;
   return OK;
 }

 void DestroyBiTree(BiTree *T)
 { /* ��ʼ����: ������T���ڡ��������: ���ٶ�����T */
   if(*T) /* �ǿ��� */
   {
     if((*T)->lchild) /* ������ */
       DestroyBiTree(&(*T)->lchild); /* ������������ */
     if((*T)->rchild) /* ���Һ��� */
       DestroyBiTree(&(*T)->rchild); /* �����Һ������� */
     free(*T); /* �ͷŸ���� */
     *T=NULL; /* ��ָ�븳0 */
   }
 }

 void CreateBiTree(BiTree *T)
 { /* �㷨6.4:�������������������н���ֵ����Ϊ�ַ��ͻ����ͣ��������� */
   /* ���壩���������������ʾ�Ķ�����T������Nil��ʾ�գ��ӣ������иĶ� */
   TElemType ch;
 #ifdef CHAR
   scanf("%c",&ch);
 #endif
 #ifdef INT
   scanf("%d",&ch);
 #endif
   if(ch==Nil) /* �� */
     *T=NULL;
   else
   {
     *T=(BiTree)malloc(sizeof(BiTNode));
     if(!*T)
       exit(OVERFLOW);
     (*T)->data=ch; /* ���ɸ���� */
     CreateBiTree(&(*T)->lchild); /* ���������� */
     CreateBiTree(&(*T)->rchild); /* ���������� */
   }
 }

 Status BiTreeEmpty(BiTree T)
 { /* ��ʼ����: ������T���� */
   /* �������: ��TΪ�ն�����,�򷵻�TRUE,����FALSE */
   if(T)
     return FALSE;
   else
     return TRUE;
 }

 #define ClearBiTree DestroyBiTree

 int BiTreeDepth(BiTree T)
 { /* ��ʼ����: ������T���ڡ��������: ����T����� */
   int i,j;
   if(!T)
     return 0;
   if(T->lchild)
     i=BiTreeDepth(T->lchild);
   else
     i=0;
   if(T->rchild)
     j=BiTreeDepth(T->rchild);
   else
     j=0;
   return i>j?i+1:j+1;
 }

 TElemType Root(BiTree T)
 { /* ��ʼ����: ������T���ڡ��������: ����T�ĸ� */
   if(BiTreeEmpty(T))
     return Nil;
   else
     return T->data;
 }

 TElemType Value(BiTree p)
 { /* ��ʼ����: ������T���ڣ�pָ��T��ĳ����� */
   /* �������: ����p��ָ����ֵ */
   return p->data;
 }

 void Assign(BiTree p,TElemType value)
 { /* ��p��ָ��㸳ֵΪvalue */
   p->data=value;
 }

 typedef BiTree QElemType; /* �����Ԫ��Ϊ��������ָ������ */
 #include "../ch3/c3-2.h"
 #include "../ch3/bo3-2.c"
 TElemType Parent(BiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ��e��T�ķǸ����,�򷵻�����˫��,���򷵻أ��գ� */
   LinkQueue q;
   QElemType a;
   if(T) /* �ǿ��� */
   {
     InitQueue(&q); /* ��ʼ������ */
     EnQueue(&q,T); /* ������� */
     while(!QueueEmpty(q)) /* �Ӳ��� */
     {
       DeQueue(&q,&a); /* ����,����Ԫ�ظ���a */
       if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e)
       /* �ҵ�e(��������Һ���) */
         return a->data; /* ����e��˫�׵�ֵ */
       else /* û�ҵ�e,����������Һ���ָ��(����ǿ�) */
       {
         if(a->lchild)
           EnQueue(&q,a->lchild);
         if(a->rchild)
           EnQueue(&q,a->rchild);
       }
     }
   }
   return Nil; /* ���ջ�û�ҵ�e */
 }

 BiTree Point(BiTree T,TElemType s)
 { /* ���ض�����T��ָ��Ԫ��ֵΪs�Ľ���ָ�롣���� */
   LinkQueue q;
   QElemType a;
   if(T) /* �ǿ��� */
   {
     InitQueue(&q); /* ��ʼ������ */
     EnQueue(&q,T); /* �������� */
     while(!QueueEmpty(q)) /* �Ӳ��� */
     {
       DeQueue(&q,&a); /* ����,����Ԫ�ظ���a */
       if(a->data==s)
         return a;
       if(a->lchild) /* ������ */
         EnQueue(&q,a->lchild); /* ������� */
       if(a->rchild) /* ���Һ��� */
         EnQueue(&q,a->rchild); /* ����Һ��� */
     }
   }
   return NULL;
 }

 TElemType LeftChild(BiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e�����ӡ���e������,�򷵻أ��գ� */
   BiTree a;
   if(T) /* �ǿ��� */
   {
     a=Point(T,e); /* a�ǽ��e��ָ�� */
     if(a&&a->lchild) /* T�д��ڽ��e��e�������� */
       return a->lchild->data; /* ����e�����ӵ�ֵ */
   }
   return Nil; /* ����������ؿ� */
 }

 TElemType RightChild(BiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e���Һ��ӡ���e���Һ���,�򷵻أ��գ� */
   BiTree a;
   if(T) /* �ǿ��� */
   {
     a=Point(T,e); /* a�ǽ��e��ָ�� */
     if(a&&a->rchild) /* T�д��ڽ��e��e�����Һ��� */
       return a->rchild->data; /* ����e���Һ��ӵ�ֵ */
   }
   return Nil; /* ����������ؿ� */
 }

 TElemType LeftSibling(BiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e�����ֵܡ���e��T�����ӻ������ֵ�,�򷵻أ��գ� */
   TElemType a;
   BiTree p;
   if(T) /* �ǿ��� */
   {
     a=Parent(T,e); /* aΪe��˫�� */
     p=Point(T,a); /* pΪָ����a��ָ�� */
     if(p->lchild&&p->rchild&&p->rchild->data==e) /* p�������Һ������Һ�����e */
       return p->lchild->data; /* ����p������(e�����ֵ�) */
   }
   return Nil; /* ���ջ�û�ҵ�e�����ֵ� */
 }

 TElemType RightSibling(BiTree T,TElemType e)
 { /* ��ʼ����: ������T����,e��T��ĳ����� */
   /* �������: ����e�����ֵܡ���e��T���Һ��ӻ������ֵ�,�򷵻أ��գ� */
   TElemType a;
   BiTree p;
   if(T) /* �ǿ��� */
   {
     a=Parent(T,e); /* aΪe��˫�� */
     p=Point(T,a); /* pΪָ����a��ָ�� */
     if(p->lchild&&p->rchild&&p->lchild->data==e) /* p�������Һ�����������e */
       return p->rchild->data; /* ����p���Һ���(e�����ֵ�) */
   }
   return Nil; /* ���ջ�û�ҵ�e�����ֵ� */
 }

 Status InsertChild(BiTree p,int LR,BiTree c) /* �β�T���� */
 { /* ��ʼ����: ������T����,pָ��T��ĳ�����,LRΪ0��1,�ǿն�����c��T */
   /*           ���ཻ��������Ϊ�� */
   /* �������: ����LRΪ0��1,����cΪT��p��ָ���������������p��ָ���� */
   /*           ԭ��������������Ϊc�������� */
   if(p) /* p���� */
   {
     if(LR==0)
     {
       c->rchild=p->lchild;
       p->lchild=c;
     }
     else /* LR==1 */
     {
       c->rchild=p->rchild;
       p->rchild=c;
     }
     return OK;
   }
   return ERROR; /* p�� */
 }

 Status DeleteChild(BiTree p,int LR) /* �β�T���� */
 { /* ��ʼ����: ������T����,pָ��T��ĳ�����,LRΪ0��1 */
   /* �������: ����LRΪ0��1,ɾ��T��p��ָ������������� */
   if(p) /* p���� */
   {
     if(LR==0) /* ɾ�������� */
       ClearBiTree(&p->lchild);
     else /* ɾ�������� */
       ClearBiTree(&p->rchild);
     return OK;
   }
   return ERROR; /* p�� */
 }

 void PreOrderTraverse(BiTree T,Status(*Visit)(TElemType))
 { /* ��ʼ����: ������T����,Visit�ǶԽ�������Ӧ�ú������㷨6.1���иĶ� */
   /* �������: ����ݹ����T,��ÿ�������ú���Visitһ���ҽ�һ�� */
   if(T) /* T���� */
   {
     Visit(T->data); /* �ȷ��ʸ���� */
     PreOrderTraverse(T->lchild,Visit); /* ��������������� */
     PreOrderTraverse(T->rchild,Visit); /* ���������������� */
   }
 }

 void InOrderTraverse(BiTree T,Status(*Visit)(TElemType))
 { /* ��ʼ����: ������T����,Visit�ǶԽ�������Ӧ�ú��� */
   /* �������: ����ݹ����T,��ÿ�������ú���Visitһ���ҽ�һ�� */
   if(T)
   {
     InOrderTraverse(T->lchild,Visit); /* ��������������� */
     Visit(T->data); /* �ٷ��ʸ���� */
     InOrderTraverse(T->rchild,Visit); /* ���������������� */
   }
 }

 typedef BiTree SElemType; /* ��ջԪ��Ϊ��������ָ������ */
 #include "../ch3/c3-1.h"
 #include "../ch3/bo3-1.c"
 Status InOrderTraverse1(BiTree T,Status(*Visit)(TElemType))
 { /* ���ö��������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú������㷨6.3 */
   /* �������������T�ķǵݹ��㷨(����ջ)����ÿ������Ԫ�ص��ú���Visit */
   SqStack S;
   InitStack(&S);
   while(T||!StackEmpty(S))
   {
     if(T)
     { /* ��ָ���ջ,���������� */
       Push(&S,T);
       T=T->lchild;
     }
     else
     { /* ��ָ����ջ,���ʸ����,���������� */
       Pop(&S,&T);
       if(!Visit(T->data))
         return ERROR;
       T=T->rchild;
     }
   }
   printf("\n");
   return OK;
 }

 Status InOrderTraverse2(BiTree T,Status(*Visit)(TElemType))
 { /* ���ö��������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú������㷨6.2 */
   /* �������������T�ķǵݹ��㷨(����ջ)����ÿ������Ԫ�ص��ú���Visit */
   SqStack S;
   BiTree p;
   InitStack(&S);
   Push(&S,T); /* ��ָ���ջ */
   while(!StackEmpty(S))
   {
     while(GetTop(S,&p)&&p)
       Push(&S,p->lchild); /* �����ߵ���ͷ */
     Pop(&S,&p); /* ��ָ����ջ */
     if(!StackEmpty(S))
     { /* ���ʽ��,����һ�� */
       Pop(&S,&p);
       if(!Visit(p->data))
         return ERROR;
       Push(&S,p->rchild);
     }
   }
   printf("\n");
   return OK;
 }

 void PostOrderTraverse(BiTree T,Status(*Visit)(TElemType))
 { /* ��ʼ����: ������T����,Visit�ǶԽ�������Ӧ�ú��� */
   /* �������: ����ݹ����T,��ÿ�������ú���Visitһ���ҽ�һ�� */
   if(T) /* T���� */
   {
     PostOrderTraverse(T->lchild,Visit); /* �Ⱥ������������ */
     PostOrderTraverse(T->rchild,Visit); /* �ٺ������������ */
     Visit(T->data); /* �����ʸ���� */
   }
 }

 void LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType))
 { /* ��ʼ������������T����,Visit�ǶԽ�������Ӧ�ú��� */
   /* �������������ݹ����T(���ö���),��ÿ�������ú���Visitһ���ҽ�һ�� */
   LinkQueue q;
   QElemType a;
   if(T)
   {
     InitQueue(&q);
     EnQueue(&q,T);
     while(!QueueEmpty(q))
     {
       DeQueue(&q,&a);
       Visit(a->data);
       if(a->lchild!=NULL)
         EnQueue(&q,a->lchild);
       if(a->rchild!=NULL)
         EnQueue(&q,a->rchild);
     }
     printf("\n");
   }
 }