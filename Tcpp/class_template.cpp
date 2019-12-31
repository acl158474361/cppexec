#include <vector>
#include <initializer_list>
#include <memory>
#include <string>

template<typename T> class Blob{
public:
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}
    void push_back(const T &t) { data->push_back(t);}
    void push_back(T &&t) { data->push_back(std::move(t));}
    void pop_back();

    T& back();
    T& operator[] (size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i,const std::string &msg) const;
};

template<typename T> class BlobPtr{
public:
    BlobPtr(): curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0):
            wptr(a.data), curr(sz) {}
    BlobPtr& operator++() { check(++curr, "++out of range"); return *this;}
    BlobPtr& operator--() { check(--curr, "--out of range"); return *this;}
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    T& operator*() const{
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }


private:
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

    std::shared_ptr<std::vector<T>> check(std::size_t,cosnt std::string&) const;
};


template<typename T>
void Blob<T>::check(size_type i,const std::string &msg) const{
    if(i >= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::back(){
    check(0,"back on empty Blob");
    return data->back();
}

template<typename T>
T& Blob<T>::operator[] (size_type i){
    check(i,"subscript out of range");
    return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back(){
    check(0,"pop on empty Blob");
    data->pop_back();
}

template<typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il):
        data(std::make_shared<std::vector<T>>(il)) {}


template<typename  T>
BlobPtr<T> BlobPtr<T>::operator++(int){
    BlobPtr ret = *this;
    ++*this;
    return ret;
} 

template<typename T>
std::shared_ptr<std::vector<T>> check(std::size_t sz, const std::string &msg){
    
}


int main(){
    Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};
    for(size_t i =0;i<squares.size();++i){
        squares[i] = i*i;
    }
}