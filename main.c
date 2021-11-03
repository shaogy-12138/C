#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define Swap(a,b) \
	*a = (*a)^(*b);\
	*b = (*a)^(*b);\
	*a = (*a)^(*b);

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div_(int a, int b);

void test1();
void test2();
void test3();
void test4();
void test5();
void test(int arr[]);
void swap(int*, int*);
void Calc(int (*)(int, int));
void display(int arr[], int size);
void bubble_sort(int arr[], int size);
int main() {

	/*
	�Ƽ���վ��
		www.stackoverflow.com   ջ���
		www.segmentfault.com	�δ���
	�Ƽ��鼮��
		��ָoffer
		C������ȱ��

*/
	/*
	
		�ַ�ָ��
		����ָ��
		ָ������
		���鴫�κ�ָ�봫��
		����ָ��
		����ָ������
		ָ����ָ�������ָ��
		�ص�����
		ָ�����������

	*/
	/*
	
		1. ָ���Ǹ���������ŵ��ǵ�ַ����ַ��Ψһ��ʶ��һ���ڴ�ռ�
		2. ָ��Ĵ�С�ǹ̶���4��8�ֽڣ���32λ��64λƽ̨����
		3. ָ���������͵ģ�ָ������;�����ָ���+ - �����Ĳ�����ָ������ò���ʱ���Ȩ��
		4. ָ�������
	
	*/
	// int arr[10] = { 0 };
	// test(arr);  // ��� ��1 ��32λƽ̨�� �� 2��64λƽ̨��
	/*
		�ַ�ָ�룺char *
		1. ָ�򵥸��ַ�
		2. ָ���ַ�����/�ַ���

		��������� char* cptr = 'c' ���� char* sptr = 'hello world' ���ȼ��� const char *cptr ���� const char *sptr
		�����ַ���������ϵͳ�Ὺ��һ�οռ�洢����ָ��ָ���ַ���������ʱ�򣬽���οռ�ĵ�ַ���ݸ�ָ�룬ָ�벻���޸�
		���е����ݣ�����ָ������޸���ָ�� ����������͵ȼ��� �ַ�������ָ�� char const * cptr ���� const char *cptr�����ַ�ʽ�ǵȼ۵ģ�

		char c = 'a';
		char* cptr = &c;
		char *cptr = 'c';
		char *sptr1 = "hello world";
		char *sptr2 = "hello world";
		printf("%s, %p\n", "hello world", &"hello world");
		printf("%p \n",cptr);
		printf("%p \n",sptr1);
		printf("%p \n",sptr2);

		char arr[] = "abcdef";
		char* cptr = "abcdef";	// �������ַ���"abcdef" ���׵�ַ��a�ĵ�ַ������ָ��
		char* pc = arr;			// arr pc ��ŵĶ����������Ԫ�ص�ַ
		// *cptr = 'W';			// error
		printf("%s\n", cptr);	// ����ַ���"abcdef"
		printf("%c\n", *cptr);  // ����ַ�'a'
		printf("%s\n", arr);	// abcdef
		printf("%s\n", pc);		// abcdef

		char arr1[] = "abcdef";
		char arr2[] = "abcdef";
		char* ap1 = "abcdef";
		char* ap2 = "abcdef";

		// ��� hehe  ��������������Ԫ�ص�ַ����������ռ䲢����ͬ������ǲ�ͬ��
		if (arr1 == arr2) {
			printf("haha \n");
		}
		else
		{
			printf("hehe\n");
		}

		// ��� haha  ����ָ���ŵĶ����ַ����������׵�ַ��ָ�����ͬһ���ַ�������
		if (ap1 == ap2) {
			printf("haha \n");
		}
		else
		{
			printf("hehe\n");
		}
	*/
	/*
	
		�������飺 ������α���������	 => ����	; int  iptr[10];											
		ָ�����飺 ���ָ�����������    => ����	; int *iptr[10];	���ȼ�: [] > * , iptr������[]��� = ���� , int * ������������� , ��Ϊ ָ������
					����10������ָ�����


		����ָ�룺 ָ�����α�����ָ��	=> ָ��		; int *iptr;
		����ָ�룺 ָ�����������ָ��	=> ָ��		; int (*iptr)[10];  ���ȼ�: [] > * ,��()������*�����ȼ��� iptr������*��� = ָ�� , int [10] ����ָ�����͵����� , 
					ָ�����10�����α���������;
		int* arr1[10]; //����ָ������� ���10������ָ�������
		char* arr2[4]; //һ���ַ�ָ������� ���4���ַ�ָ�������
		char** arr3[5];//�����ַ�ָ������� ���5�������ַ�ָ�������


		// ָ������ - ���ָ�������

		int arr1[] = { 1, 2, 3, 4, 5 };
		int arr2[] = { 2, 3, 4, 5, 6 };
		int arr3[] = { 3, 4, 5, 6, 7 };
		int arr4[] = { 4, 5, 6, 7, 8 };


		int *parr[4] = { &arr1, &arr2, &arr3, &arr4 }; // ָ������
		int i = 0;
		for (; i < 3; i++) {
			int j = 0;
			for (; j < 5; j++) {
				printf("%d ", *( parr[i] + j));
			}
			printf("\n");
	}
		
		������ vs &������

		int arr[10] = {0}; // ����һ�����10������Ԫ�ص����飬����ʼ��Ϊ0

		arr : ����ֵ�ϱ�ʾ

		// ����ָ�� - �������ĵ�ַ
		// ע�����������ַ��������Ԫ�ص�ַ
		// ������ = &������[0]����ʾ����������Ԫ�صĵ�ַ;
		// &������ �� ��ʾ��������ĵ�ַ
		// * �� 1. ָ�붨�� 2. ������
		int arr[5] = { 1, 2, 3, 4, 5 };
		int(*iptr)[5] = &arr; // iptr�������ĵ�ַ iptr��ָ����5������Ԫ�ص�����ָ��


		char* arr[5]; // arr Ϊһ���ַ� ָ������
		char *(*ptr)[5] = &arr; // cptr��ָ�� ָ�������ָ��

		// ����ָ��ʹ��
		int arr[10] = { 1, 2, 3, 4, 5 , 6, 7, 8, 9, 10 };
		int(*aptr)[10] = &arr; // *aptr = arr
		int* p = arr;
		int i = 0;
		for (; i < 10; i++) {
			printf("%d ", *((*aptr)+i));
			printf("%d \n", (*aptr)[i]);
			printf("%d \n", p[i]);
		}

		// ��ά���� - 1. ����������  2. ָ��������
		// int *p = arr; *(p + i) = *(arr + i) = p[i] = arr[i]


		int arr[5];
		int *parr[10]; // ָ�����飺���10��ָ��
		int (*parr2)[5]; //ָ����5�����ε�����ָ��
		int (*parr3[10])[5]; // ָ�����飺 ���10ָ��洢5����������ָ�������
		// parr3  ������[10]��� => ����; int (*X)[5] => X ��ָ����5��int������ָ�롣����parr3��һ�� "����ָ��"����

		// һά���飺
			// �����飺
				1. ����������飺 int arr[]
				2. ����������飺 int arr[5] //�������5û��ʵ������
				3. ָ���������
			// ��ָ�����飺
				1. ָ���������  // ע��һά������Ϊ�����������ʱ�򳤶ȿ���ʡ�ԡ���д
				2. ����ָ��**����
		
		��ά���飺
			�����飺
				1. �����������  // ��ά���鲻������ͨ���廹�ǲ������壬�ж��ǲ���ʡ�Ե�
				2. ����ָ�����  // ��ά�����������ǵ�һ������ĵ�ַ����Ԫ��Ϊ��һ�е����飩
	
		һ��ָ�봫�Σ�
			1. ָ�����

			
		��������Ϊһ��ָ�룬���Խ��գ�
			1. ָ��
			2. ��ַ��������ַ����������

		����ָ����Խ��գ�
			1. ����ָ��
			2. һ��ָ���ַ
			3. ָ������
	*/
	/*
	
		����ָ�룺 ָ�������ָ��
		����ָ�룺 ָ������ָ��;��ź�����ַ��ָ��

		int a = 10;
		int b = 20;
		int (*p)(int, int) = Add;
		Add(a, b);
		(&Add)(a, b);
		p(a, b);
		(*p)(a, b);
		(**p)(a, b);
		printf("%p \n", Add);
		printf("%p \n", &Add); // &������ == �������� ���Ǻ����ĵ�ַ��û������

		
		�������壺
			Type name = Value;

		// code1:
		(* ( void  (*)() ) 0)();
			1. void  (*)()  ����ָ������  
			2.�����ͣ����� = ǿ������ת��  ( void  (*)() ) 0 �ͱ�ʾ��0ǿ������ת��Ϊ����ָ�����ͣ� 0��ʾ������ַ
			3. *�����ã�(* ( void  (*)() ) 0)(); �������ã�����0��ַ���ĺ���������

		// code2:
		void ( *signal(int, void(*)(int) ) )(int);
			1. void(*)(int) �� ����ָ�룬����Ϊint����������Ϊvoid
			2. signal(int, void(*)(int) )������
			3. void(*)(int): ����ָ��
			4. ���signal��һ������ָ��ĺ��������������Ǻ���ָ��ĺ�������һ������Ϊint���ڶ�������Ϊ����ָ�루����Ϊint����������Ϊvoid��

			// �����ض���
			typedef void (* Fp)(int);
			Fp signal(int, Fp);


	*/
	/*
	
		ָ�����飺 ���ָ�����������
		����ָ�����飺 ��ź���ָ�����������
		
		1. ����ָ�룺  int (*p)(int, int);
		2. ����ָ�����飺 int (*p[10])(int, int); 
			1. p��һ������: p[10]
			2. ����������� int(*)(int, int)������ָ��
			3. p��������Ϊ����ָ������飬��p�Ǵ��10����ָ�������
		
		int (*parr1[10])();  // ����ָ������ - ���10�� int(*)()����������
		int *parr2[10]();	 // ָ������ - ��� 10 ��int * ����������
		int (*)() parr3[10]; // error д������		

		// ����ָ�������ʹ��

		int(*fp[4])(int, int) = { &add, &sub, &mul, &div };
		while (1) {
			int i = 0;
			scanf("%d", &i);
			if (i > 4)
				break;
			int x = fp[i](8, 2);
			printf("%d \n", x);

	}

		
	*/
	/*
	
		����ָ�룺 ָ�������ָ��
		����ָ������ָ�룺 ָ����ָ�������ָ�룬�����Ǻ���ָ�����飬����ŵ��Ǻ���ָ��
		1. ����ָ�� int(*p)(int,int) : p��һ������ָ�룬�����Ĳ�����int int������������int  ���ͣ� int(*)(int, int)
		2. ����ָ������ int(*pa[10])(int, int) �� ����ָ�����飬������10��Ԫ�أ����Ǻ���ָ��p ���ͣ� int(*[10])(int, int)
		3. ����ָ������ָ�� int(*(*pap)[10])(int, int) : ����ָ������ָ�룬 ָ�����һ�����飬���������10������ָ�� ���ͣ�int (*(*)[10])(int, int)
	*/
	/*
	
		�ص�������
			int(*fp[5])(int, int) = {0, &add, &sub, &mul, &div_ };
			do {
				printf("******************************\n");
				printf("**     1. add    2. sub     **\n");
				printf("**     3. nul    4. div     **\n");
				printf("**         0. exit          **\n");
				printf("******************************\n");

				int choose = 0;
				scanf("%d",&choose);
				if (1 <= choose && choose <= 4) {
					printf("%d \n", choose);
					Calc(fp[choose]); // �ص�������ͨ������ĳ������Ȼ���ں����е���ĳЩ����

				}
				else if (choose == 0) {
					printf("exit\n");
					break;
				}
				else
					printf("�������\n");
			} while (1);								
	
	
	*/
	/*
		
		ð������
		int arr[7] = {1, 2, 3, 4, 5, 9, 7 };
		display(arr, 7);
		bubble_sort(arr, 7);
		display(arr, 7);
	*/
	/*
	
	�궨��Swap��ʹ�ò��ԣ�
		int a = 10;
		int b = 20;
		int* p1 = &a;
		int* p2 = &b;
		Swap(p1, p2);
		printf("%d %d\n", a, b);
	
	*/
	/*
	
		qsort����ԭ�ͣ�
			void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
				����1�� base - �������е���ʼ��ַ
				����2�� nitems - ��������Ԫ�ظ���
				����3�� size - ������ÿ��Ԫ�صĴ�С�����ֽ�Ϊ��λ
				����4�� cmpar - ����ָ�룬��ʾ������
	
	*/

	
test1();
	
	return 0;
}
int add(int a, int b) {

	return a + b;
}

int sub(int a, int b) {

	return a - b;
}

int mul(int a, int b) {

	return a * b;
}

int div_(int a, int b) {

	return a / b;
}

void test1() {
	//һά����
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));		// 4*4=16
	printf("%d\n", sizeof(a + 0));	//4 / 8 ��ƽ̨���
	printf("%d\n", sizeof(*a));		//4
	printf("%d\n", sizeof(a + 1));	// 4/8
	printf("%d\n", sizeof(a[1]));	// 4
	printf("%d\n", sizeof(&a));		// 4/8
	printf("%d\n", sizeof(*&a));	// 4
	printf("%d\n", sizeof(&a + 1));	// 4/8
	printf("%d\n", sizeof(&a[0]));	// 4/8
	printf("%d\n", sizeof(&a[0] + 1));	// 4/8
}

void test2() {
	// �ַ�����
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr + 0));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(&arr[0] + 1));
	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr + 0));
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));

	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));
}

void test3() {

	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr + 0));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(&arr[0] + 1));
	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr + 0));
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));
}

void test4() {
	
	char* p = "abcdef";
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(p + 1));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(p[0]));
	printf("%d\n", sizeof(&p));
	printf("%d\n", sizeof(&p + 1));
	printf("%d\n", sizeof(&p[0] + 1));
	printf("%d\n", strlen(p));
	printf("%d\n", strlen(p + 1));
	printf("%d\n", strlen(*p));
	printf("%d\n", strlen(p[0]));
	printf("%d\n", strlen(&p));
	printf("%d\n", strlen(&p + 1));
	printf("%d\n", strlen(&p[0] + 1));
}

void test5() {

	//��ά����
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(a[0][0]));
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", sizeof(a[0] + 1));
	printf("%d\n", sizeof(*(a[0] + 1)));
	printf("%d\n", sizeof(a + 1));
	printf("%d\n", sizeof(*(a + 1)));
	printf("%d\n", sizeof(&a[0] + 1));
	printf("%d\n", sizeof(*(&a[0] + 1)));
	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(a[3]));
}

void test(int arr[]) {

	int sz = sizeof( arr) / sizeof(int);
	printf("%d \n", sz);
}

void Calc(int (*pf)(int, int)) {

	int a, b;
	int c;
	printf("��������������>> ");
	scanf("%d%d", &a, &b);
	c = pf(a, b);
	printf("%d \n", c);
}

void swap(int* a, int* b) {
	*a = (*a) ^ (*b);
	*b = (*a) ^ (*b);
	*a = (*a) ^ (*b);
}

void bubble_sort(int arr[], int size) {
	/*
	
		ð������
			����Ԫ�ظ���Ϊ i, ����Ҫ����ð�� i-1 ��, ÿ��ð��
			��Ѵ������е����Ԫ�طŵ�������еĵ�һ��λ��

			���磺
				1. ��һ�ˣ� 0~n-1 �������бȶԣ���� ���Ԫ�� ���� �ұ�Ԫ�أ� ��������Ԫ��ֵ ... ���ջ���������ŵ����
				2. �ڶ��ˣ� 0~n-2 �������бȶԣ�.... ..... ����Ѵδ�Ԫ�طŵ������ڶ�λ
				3. �ظ�����������ֱ��n-1��
			�Ż���
				��������һ����־�źţ��������������˵�����в���������У���־Ϊ1�� ÿɨ��һ�ˣ����һ�±�־λ�������־λΪ�棬˵����Ҫ����
				���������־λΪ�٣���ǰ����Ϊ�������У�����Ҫ�������������� [��־λ�����趨]
				1. ��һ�ˣ� 0~n-1 �������бȶԣ���� ���Ԫ�� ���� �ұ�Ԫ�أ� ��������Ԫ��ֵ ... ���ջ���������ŵ����
				2. �����־λΪ�棬��������ֱ��n-1�˻��߶���Ϊ�������
			

	*/
	int flag = 0;

	for (int i = 1; i < size; i++) {

		for (int j = 0; j < size - i; j++) {

			if (arr[j] > arr[j + 1]) {

				swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
			

		}
		if (flag == 0) {
			break;
		}

	}
}

void display(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}

	printf("\n");
}