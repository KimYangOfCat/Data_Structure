#ifndef _LIST_
#define _LIST_

// ???????????
template <class ElemType>
class List {
public: 
    virtual bool IsEmpty() const=0; 
    virtual int  Length() const=0; 
    virtual void Clear() = 0;  
    virtual bool GetElem(ElemType &, int) const = 0;
    virtual bool SetElem(const ElemType &,int) = 0;
    virtual int  LocateElem(const ElemType &) const = 0;
    virtual int  LocatePrior(const ElemType &) const = 0;
    virtual int  LocateNext(const ElemType &) const = 0;
    virtual bool Insert(const ElemType &, int) = 0; 
    virtual bool TailInsert(const ElemType &) = 0;
    virtual bool Delete(ElemType & ,int i) = 0;
    virtual void Traverse(void(*visit)(const ElemType &)) const = 0;
};
#endif
