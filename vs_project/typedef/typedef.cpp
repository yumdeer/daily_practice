#include <stdio.h>

typedef void (CbkFuncPoint)(int i, int j); // 指针类型

void (*CbkFunc)(int i, int j); // 指针变量
typedef void (*CbkFuncVar)(int i, int j); // 指针变量


struct TestStru {
    int id;
    void* func;
};

void testCbk(int i, int j)
{
    printf("TestCbk %d\n", i + j);
}

void testCbk2(int i, int j, int k)
{
    printf("TestCbk2 %d\n", i + j);
    (void)k;
}

int main()
{
#if 1
    CbkFunc = &testCbk;
    testCbk(0, 10);
    ((CbkFuncPoint*)testCbk)(0, 10);

    CbkFuncPoint* FuncPoint;
    FuncPoint = testCbk;
    FuncPoint(0, 10);

    CbkFuncVar FuncVar;
    FuncVar = &testCbk;
    FuncVar(0, 10);
#endif

    struct TestStru struvar = {
        10, testCbk
    };

    (*((CbkFuncPoint*)struvar.func))(10, 20);
    ((CbkFuncPoint*)struvar.func)(10, 20);
    (*((CbkFuncPoint*)testCbk))(30, 40); // (void(*)(int, int))&testCbk
    (*((CbkFuncPoint*)testCbk2))(30, 40); // 参数不一致的特殊情况也能强转匹配

    void* tt = testCbk;
    ((CbkFuncPoint*)tt)(40, 50);


    return 0;
}

