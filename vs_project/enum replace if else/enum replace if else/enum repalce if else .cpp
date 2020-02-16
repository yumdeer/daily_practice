#include <iostream>
using namespace std;

//typedef unsigned long Item;
//
//class CEnumTest
//{
//public:
//	//CEnumTest();
//	//~CEnumTest();
//
//	const void show() const;		//后面的const表示该函数不可更改类对象，也即是不能更改类对象的成员变量
//private:
//	enum { One = 1, Two = 2, Three = 4 };
//
//	Item item[Three];
//};
//
////CEnumTest::CEnumTest()
////{
////}
////CEnumTest::~CEnumTest()
////{
////}
//
//const void CEnumTest::show() const
//{
//	std::cout << "this->Three==" << this->Three << std::endl;
//}
//
//
//int main()
//{
//	CEnumTest *enumTest = new CEnumTest();
//	enumTest->show();
//
//	system("pause");
//	return true;
//}

// https://mp.weixin.qq.com/s?__biz=Mzg2NzA4MTkxNQ==&mid=2247486954&idx
// =1&sn=747968cc77ca57602077c56f0d8294ff&chksm=ce40463ef937cf28629c1c9
// 35bf8e219ee0c17d20330c6222766f7a2d6275d5d15d412153170&mpshare=1&scene
// =23&srcid=&sharer_sharetime=1581667098639&sharer_shareid=84cb414b098b6c0d73da06b926caecab#rd

public interface RoleOperation
{
	String op();
	// 表示某个角色可以做哪些op操作
}

public enum RoleEnum implements RoleOperation
{
	// 系统管理员(有A操作权限)
	ROLE_ROOT_ADMIN {
		@Override
		public String op() {
				return "ROLE_ROOT_ADMIN:"+" has AAA permission"
		}
	},

	// 订单管理员(有B操作权限)
	ROLE_ORDER_ADMIN {
		@Override
		public	String op() {
			return	"ROLE_ORDER_ADMIN:"+" has BBB permission"
		}
	},

	// 普通用户(有C操作权限)
	ROLE_NORMAL {
		@Override
		public	String op() {
			return "ROLE_NORMAL:"+" has CCC permission"
		}
	};
}

public class JudgeRole
{
	public String judge(String roleName) {
		// 一行代码搞定！之前的if/else没了！
		return RoleEnum.valueOf(roleName).op();
	}
}


// https://schneide.blog/2010/12/13/avoid-switch-use-enum/
enum Status {
	INACTIVE{
		public void doSomething() {
			//do something
		}
	},
	ACTIVE{
		void doSomething() {
			//do something else
		}
	 },
	UNKNOWN{
		void doSomething() {
			//do something totally different
		 }
	}

	// void doSomething();
};

int main() {


	return 0;
}