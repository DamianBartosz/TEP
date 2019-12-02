#ifndef LIST7_CREFCOUNTER_H
#define LIST7_CREFCOUNTER_H


class CRefCounter {
public:
    CRefCounter();

    int iAdd();

    int iDec();

    int iGet();

private:
    int i_count;
};//class CRefCounter


#endif //LIST7_CREFCOUNTER_H
