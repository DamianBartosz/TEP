#include <cassert>
#include "static.hpp"
template <typename T>
class PtrComparator {
public:
    enum Result {
        LessThan,       // pierwszy element porównywany
        // jest mniejszy od drugiego,
        GreaterThan,    // pierwszy element porównywany
        // jest większy od drugiego
        Equal           // elementy porównywane są równe
    };

    static Result compare(T* t1, T* t2){
        if(*t1>*t2){
            return GreaterThan;
        } else if(*t2>*t1){
            return LessThan;
        }else return Equal;
    }
    //  Twoja implementacja klasy szablonowej PtrComparator<T>
    //  zapewniająca poprawne działanie programu.
    //  W szczególności, powinna zostać zdefiniowana metoda
    //  compare przyjmująca jako argumenty dwa wskaźniki na typ T
    //  a zwracająca element enumeracji PtrComparator::Result.
    //
    //  Pamiętaj o zasadzie "Brzytwy Ockhama"
    //  znanej też jako KISS (Keep It Simple, Stupid)
    //  https://en.wikipedia.org/wiki/KISS_principle
};

class CustomClass {
public:
    CustomClass(){
        num = x;
        x+=10;
    }

    bool operator>(CustomClass cc){
        return num > cc.getNum();
    }

    bool operator<(CustomClass cc){
        return num < cc.getNum();
    }

    int getNum(){
        return num;
    }
private:
    int num;
};

int main()
{
    int three = 3, four = 4;

    typedef PtrComparator<int> IntPtrCmp;
    assert(IntPtrCmp::compare(&three, &four) == IntPtrCmp::LessThan);
    assert(IntPtrCmp::compare(&four, &three) == IntPtrCmp::GreaterThan);
    assert(IntPtrCmp::compare(&three, &three) == IntPtrCmp::Equal);

    CustomClass t1, t2;

    typedef PtrComparator<CustomClass> CustomClassPtrCmp;
    assert(CustomClassPtrCmp::compare(&t1, &t2) == CustomClassPtrCmp::LessThan);
    assert(CustomClassPtrCmp::compare(&t2, &t1) == CustomClassPtrCmp::GreaterThan);
    assert(CustomClassPtrCmp::compare(&t1, &t1) == CustomClassPtrCmp::Equal);

    return 0;
}


