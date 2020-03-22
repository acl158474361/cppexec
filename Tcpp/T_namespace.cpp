namespace blip{
    int i = 16, j = 15, k = 23;
}

inline namespace ns_name{
    int l = 10;
}
namespace primerLib{
    void compute() {};
    void compute(const void *){};
}


void compute(int){}
void compute(double, double = 3.4){}
void compute(char*, char* = 0){}


void f(){
    using primerLib::compute; //覆盖外层的compute
    compute(0);
}


int j = 0;
namespace man_ns{
    void manip(){
        using namespace blip; //把blip中的symbols注入 全局作用域
        ++i;
        // ++j; 有二义性
        ++::j;
        ++blip::j;
        ++l; //Declarations inside inline ns_name will be visible in its enclosing namespace. (enclosing 仅仅是外面一层作用域)
        int k = 97;
        ++k;
    }
}
namespace foo {
    namespace bar {
         inline namespace baz {
             int qux = 42;
         }
         void bar_qux(){
             int a = qux;
         }
    }
    void foo_qux(){
        //error: ‘qux’ was not declared in this scope
        int a = qux; //qux is undefined;
    }
}

int main(void){

}