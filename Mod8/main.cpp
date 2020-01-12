#include <iostream>
#include <vector>

using namespace std;

class A {
private:
    int *m_number;
public:
    A(int number) {
        m_number = new int(number);
        cout << "Constructed A: " << *m_number << endl;
    }

    A(const A &a) {
        m_number = new int(*a.m_number);
        cout << "Copy constructed A: " << *m_number << endl;
    }

    A(A &&a) {
        m_number = a.m_number;
        a.m_number = NULL;
        cout << "Move constructed A: " << *m_number << endl;
    }

    ~A() {
        cout << "Desctructed A: ";
        if (m_number) {
            cout << *m_number;
            delete m_number;
            m_number = nullptr;
        } else {
            cout << "nullptr";
        }
        cout << endl;
    }

    A &operator=(const A &a) {
        if (m_number) delete m_number;
        m_number = new int(*a.m_number);
        cout << "Copied by operator A: " << *m_number << endl;
        return
    }

    A &operator=(A &&a) {
        if (m_number) delete m_number;
        m_number = a.m_number;
        a.m_number = NULL;
        cout << "Moved by operator A:" << *m_number << endl;
        return *this;
    }


};

int main() {
    vector <A> v;
    v.push_back(A{5});
    A a{15};
    a = A{10};
    return 0;
}