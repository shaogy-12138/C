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
	推荐网站：
		www.stackoverflow.com   栈溢出
		www.segmentfault.com	段错误
	推荐书籍：
		剑指offer
		C陷阱与缺陷

*/
	/*
	
		字符指针
		数组指针
		指针数组
		数组传参和指针传参
		函数指针
		函数指针数组
		指向函数指针数组的指针
		回调函数
		指针和数组面试

	*/
	/*
	
		1. 指针是个变量，存放的是地址，地址是唯一标识的一块内存空间
		2. 指针的大小是固定的4或8字节，由32位或64位平台决定
		3. 指针是有类型的，指针的类型决定了指针的+ - 整数的步长，指针解引用操作时候的权限
		4. 指针的运算
	
	*/
	// int arr[10] = { 0 };
	// test(arr);  // 输出 ：1 （32位平台） 或 2（64位平台）
	/*
		字符指针：char *
		1. 指向单个字符
		2. 指向字符数组/字符串

		如果类似如 char* cptr = 'c' 或者 char* sptr = 'hello world' 都等价于 const char *cptr 或者 const char *sptr
		对于字符串常量，系统会开辟一段空间存储，当指针指向字符串常量的时候，将这段空间的地址传递给指针，指针不能修改
		其中的内容，但是指针可以修改其指向 ，因此其类型等价与 字符串常量指针 char const * cptr 或者 const char *cptr（两种方式是等价的）

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
		char* cptr = "abcdef";	// 将常量字符串"abcdef" 的首地址（a的地址）赋给指针
		char* pc = arr;			// arr pc 存放的都是数组的首元素地址
		// *cptr = 'W';			// error
		printf("%s\n", cptr);	// 输出字符串"abcdef"
		printf("%c\n", *cptr);  // 输出字符'a'
		printf("%s\n", arr);	// abcdef
		printf("%s\n", pc);		// abcdef

		char arr1[] = "abcdef";
		char arr2[] = "abcdef";
		char* ap1 = "abcdef";
		char* ap2 = "abcdef";

		// 输出 hehe  数组名是数组首元素地址，两个数组空间并不相同，因此是不同的
		if (arr1 == arr2) {
			printf("haha \n");
		}
		else
		{
			printf("hehe\n");
		}

		// 输出 haha  两个指针存放的都是字符串常量的首地址，指向的是同一个字符串常量
		if (ap1 == ap2) {
			printf("haha \n");
		}
		else
		{
			printf("hehe\n");
		}
	*/
	/*
	
		整形数组： 存放整形变量的数组	 => 数组	; int  iptr[10];											
		指针数组： 存放指针变量的数组    => 数组	; int *iptr[10];	优先级: [] > * , iptr优先与[]结合 = 数组 , int * 就是数组的类型 , 故为 指针数组
					包含10个整形指针变量


		整形指针： 指向整形变量的指针	=> 指针		; int *iptr;
		数组指针： 指向数组变量的指针	=> 指针		; int (*iptr)[10];  优先级: [] > * ,但()提升了*的优先级， iptr优先与*结合 = 指针 , int [10] 就是指针类型的类型 , 
					指向包含10个整形变量的数组;
		int* arr1[10]; //整形指针的数组 存放10个整形指针的数组
		char* arr2[4]; //一级字符指针的数组 存放4个字符指针的数组
		char** arr3[5];//二级字符指针的数组 存放5个二级字符指针的数组


		// 指针数组 - 存放指针的数组

		int arr1[] = { 1, 2, 3, 4, 5 };
		int arr2[] = { 2, 3, 4, 5, 6 };
		int arr3[] = { 3, 4, 5, 6, 7 };
		int arr4[] = { 4, 5, 6, 7, 8 };


		int *parr[4] = { &arr1, &arr2, &arr3, &arr4 }; // 指针数组
		int i = 0;
		for (; i < 3; i++) {
			int j = 0;
			for (; j < 5; j++) {
				printf("%d ", *( parr[i] + j));
			}
			printf("\n");
	}
		
		数组名 vs &数组名

		int arr[10] = {0}; // 定义一个存放10个整形元素的数组，并初始化为0

		arr : 在数值上表示

		// 数组指针 - 存放数组的地址
		// 注意区分数组地址和数组首元素地址
		// 数组名 = &数组名[0]：表示的是数组首元素的地址;
		// &数组名 ： 表示的是数组的地址
		// * ： 1. 指针定义 2. 解引用
		int arr[5] = { 1, 2, 3, 4, 5 };
		int(*iptr)[5] = &arr; // iptr存放数组的地址 iptr是指向含有5个整形元素的数组指针


		char* arr[5]; // arr 为一个字符 指针数组
		char *(*ptr)[5] = &arr; // cptr是指向 指针数组的指针

		// 数组指针使用
		int arr[10] = { 1, 2, 3, 4, 5 , 6, 7, 8, 9, 10 };
		int(*aptr)[10] = &arr; // *aptr = arr
		int* p = arr;
		int i = 0;
		for (; i < 10; i++) {
			printf("%d ", *((*aptr)+i));
			printf("%d \n", (*aptr)[i]);
			printf("%d \n", p[i]);
		}

		// 二维数组 - 1. 数组做参数  2. 指针做参数
		// int *p = arr; *(p + i) = *(arr + i) = p[i] = arr[i]


		int arr[5];
		int *parr[10]; // 指针数组：存放10个指针
		int (*parr2)[5]; //指向存放5个整形的数组指针
		int (*parr3[10])[5]; // 指针数组： 存放10指向存储5个整形数组指针的数组
		// parr3  优先于[10]结合 => 数组; int (*X)[5] => X 是指向含有5个int的数组指针。所以parr3是一个 "数组指针"数组

		// 一维数组：
			// 传数组：
				1. 数组接收数组： int arr[]
				2. 数组接收数组： int arr[5] //这个长度5没有实际意义
				3. 指针接收数组
			// 传指针数组：
				1. 指针数组接收  // 注意一维数组作为参数，定义的时候长度可以省略、不写
				2. 二级指针**接收
		
		二维数组：
			传数组：
				1. 数组接收数组  // 二维数组不管是普通定义还是参数定义，列都是不能省略的
				2. 数组指针接收  // 二维数组数组名是第一行数组的地址（首元素为第一行的数组）
	
		一级指针传参：
			1. 指针接收

			
		参数部分为一级指针，可以接收：
			1. 指针
			2. 地址（变量地址、数组名）

		二级指针可以接收：
			1. 二级指针
			2. 一级指针地址
			3. 指针数组
	*/
	/*
	
		数组指针： 指向数组的指针
		函数指针： 指向函数的指针;存放函数地址的指针

		int a = 10;
		int b = 20;
		int (*p)(int, int) = Add;
		Add(a, b);
		(&Add)(a, b);
		p(a, b);
		(*p)(a, b);
		(**p)(a, b);
		printf("%p \n", Add);
		printf("%p \n", &Add); // &函数名 == 函数名， 都是函数的地址，没有区别

		
		变量定义：
			Type name = Value;

		// code1:
		(* ( void  (*)() ) 0)();
			1. void  (*)()  函数指针类型  
			2.（类型）变量 = 强制类型转换  ( void  (*)() ) 0 就表示将0强制类型转换为函数指针类型， 0表示函数地址
			3. *解引用，(* ( void  (*)() ) 0)(); 函数调用，调用0地址处的函数，参数

		// code2:
		void ( *signal(int, void(*)(int) ) )(int);
			1. void(*)(int) ： 函数指针，参数为int，返回类型为void
			2. signal(int, void(*)(int) )：函数
			3. void(*)(int): 函数指针
			4. 因此signal是一个函数指针的函数，返回类型是函数指针的函数，第一个参数为int，第二个参数为函数指针（参数为int，返回类型为void）

			// 类型重定义
			typedef void (* Fp)(int);
			Fp signal(int, Fp);


	*/
	/*
	
		指针数组： 存放指针变量的数组
		函数指针数组： 存放函数指针变量的数组
		
		1. 函数指针：  int (*p)(int, int);
		2. 函数指针数组： int (*p[10])(int, int); 
			1. p是一个数组: p[10]
			2. 数组的类型是 int(*)(int, int)即函数指针
			3. p就是类型为函数指针的数组，即p是存放10函数指针的数组
		
		int (*parr1[10])();  // 函数指针数组 - 存放10个 int(*)()变量的数组
		int *parr2[10]();	 // 指针数组 - 存放 10 个int * 变量的数组
		int (*)() parr3[10]; // error 写法错误		

		// 函数指针数组的使用

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
	
		数组指针： 指向数组的指针
		函数指针数组指针： 指向函数指针数组的指针，数组是函数指针数组，即存放的是函数指针
		1. 函数指针 int(*p)(int,int) : p是一个函数指针，函数的参数是int int，返回类型是int  类型： int(*)(int, int)
		2. 函数指针数组 int(*pa[10])(int, int) ： 函数指针数组，数组中10个元素，都是函数指针p 类型： int(*[10])(int, int)
		3. 函数指针数组指针 int(*(*pap)[10])(int, int) : 函数指针数组指针， 指向的是一个数组，数组包含了10个函数指针 类型：int (*(*)[10])(int, int)
	*/
	/*
	
		回调函数：
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
					Calc(fp[choose]); // 回调函数，通过触发某条件，然后在函数中调用某些函数

				}
				else if (choose == 0) {
					printf("exit\n");
					break;
				}
				else
					printf("输入错误\n");
			} while (1);								
	
	
	*/
	/*
		
		冒泡排序：
		int arr[7] = {1, 2, 3, 4, 5, 9, 7 };
		display(arr, 7);
		bubble_sort(arr, 7);
		display(arr, 7);
	*/
	/*
	
	宏定义Swap的使用测试：
		int a = 10;
		int b = 20;
		int* p1 = &a;
		int* p2 = &b;
		Swap(p1, p2);
		printf("%d %d\n", a, b);
	
	*/
	/*
	
		qsort函数原型：
			void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
				参数1： base - 待排序列的起始地址
				参数2： nitems - 待排序列元素个数
				参数3： size - 数组中每个元素的大小，以字节为单位
				参数4： cmpar - 函数指针，表示排序函数
	
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
	//一维数组
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));		// 4*4=16
	printf("%d\n", sizeof(a + 0));	//4 / 8 跟平台相关
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
	// 字符数组
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

	//二维数组
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
	printf("请输入两个数字>> ");
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
	
		冒泡排序：
			数组元素个数为 i, 则需要进行冒泡 i-1 趟, 每次冒泡
			会把待排序列的最大元素放到有序队列的第一个位置

			例如：
				1. 第一趟： 0~n-1 两两进行比对，如果 左边元素 大于 右边元素， 交换两个元素值 ... 最终会把最大的数放到最后
				2. 第二趟： 0~n-2 两两进行比对，.... ..... 最后会把次大元素放到倒数第二位
				3. 重复上述操作，直到n-1趟
			优化：
				首先设置一个标志信号，如果发生交换即说明队列不是有序队列，标志为1， 每扫描一趟，检测一下标志位，如果标志位为真，说明需要继续
				排序，如果标志位为假，当前序列为有序序列，不需要继续，结束排序 [标志位自行设定]
				1. 第一趟： 0~n-1 两两进行比对，如果 左边元素 大于 右边元素， 交换两个元素值 ... 最终会把最大的数放到最后
				2. 如果标志位为真，继续排序，直到n-1趟或者队列为有序队列
			

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