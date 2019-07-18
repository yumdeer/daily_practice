#include <iostream>
using std::cout;
using std::endl;

template <typename TT> void counts();
template <typename TT> void reports(TT &);


template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFriend(const T & i) : item(i) {ct++;}
    ~HasFriend()  {ct--; }
    friend void counts<T>();
    friend void reports(HasFriend<T> &); // template parameter
};

 //each specialization has its own static data member
template <typename TT>
int HasFriend<TT>::ct = 0;

// non-template friend to all HasFriend<T> classes
template <typename TT>
void counts()
{
    cout << "int count: " << HasFriend<TT>::ct << "; ";
    //cout << "double count: " << HasFriend<T>::ct << endl;
}

// non-template friend to the HasFriend<int> class
template <typename TT>
void reports(TT & hf)
{
    cout <<" HasFriend<int>: " << hf.item << endl;
	//cout <<"HasFriend<double>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double> class
//void reports(HasFriend<double> & hf)
//{
//    cout <<"HasFriend<double>: " << hf.item << endl;
//}

