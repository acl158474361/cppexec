#include <string>
#include <iostream>
#include <algorithm>


/* class ZooAnimal;
extern std::ostream& operator<<(std::ostream&, const ZooAnimal&);
class ZooAnimal{
    public:
        ZooAnimal() = default;
        ZooAnimal(std::string animal, bool exhibit, std::string family):
            nm(animal), exhibit_stat(exhibit), fam_name(family) {}
        virtual ~ZooAnimal()
            { std::cout << "Animal dtor" << std::endl; }
        
        virtual std::ostream& print() const
            { return std::cout << "Animal::print" << std::endl; }
        virtual int population() const
            { std::cout << "Animal::population" << std::endl; }
        virtual double max_weight() const
            { std::cout << "Animal::max_weight" << std::endl; return 0; }
        
        std::string name() const { return nm; }
        std::string family_name() const { return fam_name; }
        bool onExhibit() const { return exhibit_stat; }
    protected:
        std::string nm;
        bool exhibit_stat = false;
        std::string fam_name;
    private:
};



class Endangered{
    public:
        virtual ~Endangered()
            { std::cout << "Endangered dtor" << std::endl; }
        virtual std::ostream& print() const
            { return std::cout << "Endangered::print" << std::endl; }
        virtual void highlight() const
            { std::cout << "Endangered::highlight" << std::endl; }
        virtual double max_weight() const
            { std::cout << "Endangered::max_weight" << std::endl; return 0; }

};

using DanceType = unsigned;
constexpr DanceType two_left_feet = 0;
constexpr DanceType Astaire = 1;
constexpr DanceType Rogers = 42;

class Bear:public ZooAnimal{
    public:
        Bear() = default;
        Bear(std::string name, bool onExhibit=true, std::string family="Bear"):
            ZooAnimal(name, onExhibit, family), dancetype(two_left_feet) {}
        
        virtual std::ostream& print() const
            { return std::cout << "Bear::print" << std::endl; }
        virtual int toes() const
            { std::cout << "Bear::toes" << std::endl; return 0; }
        int mumble(int)
            { std::cout << "Bear::mumble" << std::endl; return 0; }
        void dance(DanceType) const
            { std::cout << "Bear::dance" << std::endl; }
        

        virtual ~Bear()
            { std::cout << "Bear dtor" << std::endl; }
    private:
        DanceType dancetype = Rogers;
};

class Panda:public Bear, public Endangered{
    Panda() = default;
    Panda(std::string name, bool onExhibit = true);
    virtual ~Panda()
        { std::cout << "Panda dtor" << std::endl; }


    virtual std::ostream& print() const
        { return std::cout << "Panda::print" << std::endl; }
    void highlight()
        { std::cout << "Panda::hightlight" << std::endl; }
    virtual int toes()
        { std::cout << "Panda::toes" << std::endl; }
    virtual void cuddle()
        { std::cout << "Panda::cuddle" << std::endl; }
    virtual double max_weight() const;
    
}; */


class A{
    public:
    A(){ std::cout << "A::A()" << std::endl; }
};

class B:public A{
    public:
    B(){ std::cout << "B::B()" << std::endl; }
};

class C:public B{
    public:
    C(){ std::cout << "C::C()" << std::endl; }
};

class X{
    public:
    X(){ std::cout << "X::X()" << std::endl; }
};

class Y{
    public:
    Y(){ std::cout << "Y::Y()" << std::endl; }
};

class Z:public X, public Y{
    public:
    Z(){ std::cout << "Z::Z()" << std::endl; }
};

class MI:public C, public Z{
    public:
    MI(){ std::cout << "MI::MI()" << std::endl; }
};

class D:public X, public C{
    public:
    D(){ std::cout << "X::X()" << std::endl; }
};

int main(void){
    D *pd = new D();
    X *px = pd;
    A *pa = pd;
    B *pb = pd;
    C *pc = pd;
}











