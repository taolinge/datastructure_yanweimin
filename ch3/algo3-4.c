/* algo3-4.c �б༭����,ʵ���㷨3.2 */
typedef char SElemType;
#include "../ch1/c1.h"
#include "c3-1.h"
#include "bo3-1.c"
FILE *fp;

Status copy(SElemType c)
{ /* ���ַ�c����fp��ָ���ļ��� */
	fputc(c, fp);
	return OK;
}

void LineEdit()
{ /* �����ַ�ջs�����ն˽���һ�в��������ù��̵����������㷨3.2 */
	SqStack s;
	char ch, c;
	InitStack(&s);
	printf("������һ���ı��ļ�,^Z��������:\n");
	ch = getchar();
	while (ch != EOF)
	{	 /* EOFΪ^Z����ȫ�Ľ����� */
		while (ch != EOF&&ch != '\n')
		{
			switch (ch)
			{
			case '#':Pop(&s, &c);
				break; /* ����ջ�ǿ�ʱ��ջ */
			case '@':ClearStack(&s);
				break; /* ����sΪ��ջ */
			default:Push(&s, ch); /* ��Ч�ַ���ջ */
			}
			ch = getchar(); /* ���ն˽�����һ���ַ� */
		}
		StackTraverse(s, copy); /* ����ջ�׵�ջ����ջ���ַ��������ļ� */
		ClearStack(&s); /* ����sΪ��ջ */
		fputc('\n', fp);
		if (ch != EOF)
			ch = getchar();
	}
	DestroyStack(&s);
}

void main()
{
	fp = fopen("ED.DAT", "w"); /* �ڵ�ǰĿ¼�½���ED.DAT�ļ�������д���ݣ� */
	if (fp)                  /* ������ͬ���ļ�����ɾ��ԭ�ļ� */
	{
		LineEdit();
		fclose(fp); /* �ر�fp��ָ���ļ� */
	}
	else
		printf("�����ļ�ʧ��!\n");
}
