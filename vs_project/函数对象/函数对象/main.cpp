//#include <boost/thread/thread.hpp>
//#include <iostream>
//#include <iterator>
//#include <algorithm>
// 
//void wait(int sec){
//    boost::this_thread::sleep(boost::posix_time::seconds(sec));
//}
//
//boost::mutex mutex;
//
//class SayHello{
//public:
//    explicit SayHello(const std::string & name,int times)
//        :_name(name),_times(times){}
//    void operator()()const{
//        for(int i=0;i<_times;i++){
//            wait(1);
//            boost::lock_guard<boost::mutex> lock(mutex);
//            std::cout<<_name<<" says hello ("<<i+1<<")"<<std::endl;
//        }
//    }
//private:
//    std::string _name;
//    int _times;
//};
//
//int main(int argc,char * argv[]){
//    SayHello lux("Lux",5);
//    SayHello jax("Jax",5);
//    
//    boost::thread thr1(lux);
//    boost::thread thr2(jax);
//    
//    thr1.join();
//    thr2.join();
//    return 0;
//}


