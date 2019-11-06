#ifndef SINGLETON_H_
#define SINGLETON_H_
template<class T> class singleton{
private:
    T _instance;
    static singleton<T> *flag_instance;
public:
    static T *getinstance(){
        if(!flag_instance){
            flag_instance = new singleton();
        }
        return &flag_instance->_instance;
    }
protected:
    singleton(){}
};

template<class T>
singleton<T> *singleton<T>::flag_instance = nullptr;

#endif