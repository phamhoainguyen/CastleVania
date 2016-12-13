//#include <stdio.h>
//
//class A{
//public:
//	A();
//	virtual ~A();
//	virtual void logging() = 0;
//
//};
//
//
//class B : public A
//{
//public:
//	B();
//	~B();
//	virtual void logging();
//};
//
//class C : public B
//{
//public:
//	C();
//	~C();
//	virtual void logging();
//};
//
//
//A::A()
//{
//	//logging();
//}
//A::~A()
//{
//	printf("Destructor A\n");
//}
//
////void A::logging()
////{
////	printf(" Phuong thuc logging cua class A! \n");
////}
//
//B::B()
//{
//	logging();
//}
//
//B::~B()
//{
//	  printf("Destructor B\n");
//}
//
//void B::logging()
//{
//	printf("Phuong thuc logging cua class B! \n");
//}
//
//C::C()
//{
//	logging();
//}
//
//C::~C()
//{
//	printf("Destructor C\n");
//}
//
//void C::logging()
//{
//	printf("Phuong thuc logging cua class C! \n");
//}
//
//
//int main()
//{
//	//B* b = new B();
//	//b->~B();
//	//B b;
//	//b.~B();
//
//	A* a = new C;
//	a->logging();
//	a->~A();  // Day la ly do su dung virtual Destructor
//	
//	for (;;);
//	return 0;
//}