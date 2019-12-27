namespace blip{
    int i = 16, j = 15, k = 23;
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
void manip(){
    using namespace blip;
    ++i;
    // ++j; 有二义性
    ++::j;
    ++blip::j;
    int k = 97;
    ++k;
}
