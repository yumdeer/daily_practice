// frnd2tmp.cpp -- template class with non-template friends
#include "hasfriend.h"

int main()
{
	counts<int>();
	counts<double>();
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    HasFriend<double> hfdb(10.5);
    reports(hfi1);  // generate report(HasFriendT<int> &)
   // reports(hfi2);  // generate report(HasFriendT<int> &)
   // reports(hfdb);  // generate report(HasFriendT<double> &)
    //cout << "counts<int>() output:\n";
   // counts<int>();
    //cout << "counts<double>() output:\n";

    // std::cin.get();
    return 0; 

 
}
