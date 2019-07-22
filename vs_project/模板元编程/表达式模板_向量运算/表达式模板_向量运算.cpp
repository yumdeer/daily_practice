//#include <iostream> // std::cout
//#include <cmath>    // std::sqrt()
//
//// 表达式类型
//class DExprLiteral {                    // 文字量
//	double a_;
//public:
//	DExprLiteral(double a) : a_(a) { }
//	double operator()(double x) const { return a_; }
//};
//class DExprIdentity {                   // 自变量
//public:
//	double operator()(double x) const { return x; }
//};
//template<class A, class B, class Op>    // 双目操作
//class DBinExprOp {
//	A a_; B b_;
//public:
//	DBinExprOp(const A& a, const B& b) : a_(a), b_(b) { }
//	double operator()(double x) const { return Op::apply(a_(x), b_(x)); }
//};
//template<class A, class Op>             // 单目操作
//class DUnaryExprOp {
//	A a_;
//public:
//	DUnaryExprOp(const A& a) : a_(a) { }
//	double operator()(double x) const { return Op::apply(a_(x)); }
//};
//// 表达式
//template<class A>
//class DExpr {
//	A a_;
//public:
//	DExpr() { }
//	DExpr(const A& a) : a_(a) { }
//	double operator()(double x) const { return a_(x); }
//};
//
//// 运算符，模板参数 A、B 为参与运算的表达式类型
//// operator /, division
//class DApDiv { public: static double apply(double a, double b) { return a / b; } };
//template<class A, class B> DExpr<DBinExprOp<DExpr<A>, DExpr<B>, DApDiv> >
//	operator/(const DExpr<A>& a, const DExpr<B>& b) {
//		typedef DBinExprOp<DExpr<A>, DExpr<B>, DApDiv> ExprT;
//		return DExpr<ExprT>(ExprT(a, b));
//	}
//	// operator +, addition
//class DApAdd { public: static double apply(double a, double b) { return a + b; } };
//template<class A, class B> DExpr<DBinExprOp<DExpr<A>, DExpr<B>, DApAdd> >
//	operator+(const DExpr<A>& a, const DExpr<B>& b) {
//		typedef DBinExprOp<DExpr<A>, DExpr<B>, DApAdd> ExprT;
//		return DExpr<ExprT>(ExprT(a, b));
//	}
//	// sqrt(), square rooting
//class DApSqrt { public: static double apply(double a) { return std::sqrt(a); } };
//template<class A> DExpr<DUnaryExprOp<DExpr<A>, DApSqrt> >
//	sqrt(const DExpr<A>& a) {
//		typedef DUnaryExprOp<DExpr<A>, DApSqrt> ExprT;
//		return DExpr<ExprT>(ExprT(a));
//	}
//	// operator-, negative sign
//class DApNeg { public: static double apply(double a) { return -a; } };
//template<class A> DExpr<DUnaryExprOp<DExpr<A>, DApNeg> >
//	operator-(const DExpr<A>& a) {
//		typedef DUnaryExprOp<DExpr<A>, DApNeg> ExprT;
//		return DExpr<ExprT>(ExprT(a));
//	}
//
//	// evaluate()
//	template<class Expr>
//	void evaluate(const DExpr<Expr>& expr, double start, double end, double step) {
//		for (double i = start; i < end; i += step) std::cout << expr(i) << ' ';
//	}
//
//	int main() {
//		DExpr<DExprIdentity> x;
//		evaluate(-x / sqrt(DExpr<DExprLiteral>(1.0) + x), 0.0, 10.0, 1.0);
//		std::cin.get(); return 0;
//	}

//#include <iostream> // std::cout
//#include <cmath>    // std::sqrt()
//
//void evaluate(double start, double end, double step) {
//	double _temp = 1.0;
//	for (double i = start; i < end; i += step)
//		std::cout << -i / std::sqrt(_temp + i) << ' ';
//}
//
//int main() {
//	evaluate(0.0, 10.0, 1.0);
//	std::cin.get(); return 0;
//}

#include <iostream> // std::cout

// A CRTP base class for Vecs with a size and indexing:
template <typename E>
class VecExpr {
public:
	double operator[](int i) const { return static_cast<E const&>(*this)[i]; }
	operator E const&() const { return static_cast<const E&>(*this); } // 向下类型转换
};
// The actual Vec class:
class Vec : public VecExpr<Vec> {
	double _data[1000];
public:
	double&  operator[](int i) { return _data[i]; }
	double operator[](int i) const { return _data[i]; }
	template <typename E>
	Vec const& operator=(VecExpr<E> const& vec) {
		E const& v = vec;
		for (int i = 0; i < 1000; ++i) _data[i] = v[i];
		return *this;
	}
	// Constructors
	Vec() { }
	Vec(double v) { for (int i = 0; i < 1000; ++i) _data[i] = v; }
};

template <typename E1, typename E2>
class VecDifference : public VecExpr<VecDifference<E1, E2> > {
	E1 const& _u; E2 const& _v;
public:
	VecDifference(VecExpr<E1> const& u, VecExpr<E2> const& v) : _u(u), _v(v) { }
	double operator[](int i) const { return _u[i] - _v[i]; }
};
template <typename E>
class VecScaled : public VecExpr<VecScaled<E> > {
	double _alpha; E const& _v;
public:
	VecScaled(double alpha, VecExpr<E> const& v) : _alpha(alpha), _v(v) { }
	double operator[](int i) const { return _alpha * _v[i]; }
};

// Now we can overload operators:
template <typename E1, typename E2> VecDifference<E1, E2> const
operator-(VecExpr<E1> const& u, VecExpr<E2> const& v) {
	return VecDifference<E1, E2>(u, v);
}
template <typename E> VecScaled<E> const
operator*(double alpha, VecExpr<E> const& v) {
	return VecScaled<E>(alpha, v);
}

int main() {
	Vec u(3), v(1); double alpha = 9; Vec y;
	y = alpha * (u - v);
	std::cout << y[999] << '\n';
	
	std::cin.get();
	return 0;
}