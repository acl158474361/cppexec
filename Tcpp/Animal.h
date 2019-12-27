#include <string>
#include <iostream>
#include <algorithm>


class ZooAnimal;
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
    public:
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
    
};

inline Panda::Panda(std::string name, bool onExhibit):
    Bear(name, onExhibit, "Panda") {}

inline double Panda::max_weight() const{
    return std::max(ZooAnimal::max_weight(), Endangered::max_weight());
}