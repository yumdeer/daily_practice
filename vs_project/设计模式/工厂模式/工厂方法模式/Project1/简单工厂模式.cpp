#if 0

#include <iostream>
using namespace std;
enum PRODUCTTYPE { SFJ, XSL, NAS };
class soapBase
{
public:
	virtual ~soapBase() {};
	virtual void show() = 0;
};

class SFJSoap :public soapBase
{
public:
	void show() { cout << "SFJ Soap!" << endl; }
};

class XSLSoap :public soapBase
{
public:
	void show() { cout << "XSL Soap!" << endl; }
};

class NASSoap :public soapBase
{
public:
	void show() { cout << "NAS Soap!" << endl; }
};

class Factory
{
public:
	soapBase* creatSoap(PRODUCTTYPE type)
	{
		switch (type)
		{
		case SFJ:
			return new SFJSoap();
			break;
		case XSL:
			return new XSLSoap();
			break;
		case NAS:
			return new NASSoap();
			break;
		default:break;
		}

	}
};

int main()
{
	Factory factory;
	soapBase* pSoap1 = factory.creatSoap(SFJ);
	pSoap1->show();
	soapBase* pSoap2 = factory.creatSoap(XSL);
	pSoap2->show();
	soapBase* pSoap3 = factory.creatSoap(NAS);
	pSoap3->show();
	delete pSoap1;
	delete pSoap2;
	delete pSoap3;
	return 0;
}

#endif 