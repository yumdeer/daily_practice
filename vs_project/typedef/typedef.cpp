#include <stdio.h>

typedef void (CbkFuncPoint)(int i, int j); // ָ������

void (*CbkFunc)(int i, int j); // ָ�����
typedef void (*CbkFuncVar)(int i, int j); // ָ�����


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
    (*((CbkFuncPoint*)testCbk2))(30, 40); // ������һ�µ��������Ҳ��ǿתƥ��

    void* tt = testCbk;
    ((CbkFuncPoint*)tt)(40, 50);


    return 0;
}

