#include <bits/stdc++.h>

using namespace std;

class param
{
    string pName;
    string pType;
public:
    param(string name, string type)
    {
        pName = name;
        pType = type;
    }

    string getName(){return pName;}
    string getType(){return pType;}

};

//contain name and type info of symbol and a next pointer to resolve collision
class SymbolInfo
{
    string Name;
    string Type;
    SymbolInfo* Next;

    //for array and function
    int size;
    vector<param> param_list;

public:
    SymbolInfo()
    {
        Next = NULL;
    }
    SymbolInfo(string name)
    {
        Name = name;
        Next = NULL;
    }
    SymbolInfo(string name, string type)
    {
        Name = name;
        Type = type;
        Next = NULL;
    }
    SymbolInfo(SymbolInfo* ob)  //copy constructor
    {
        Name = ob->getName();
        Type = ob->getType();
        Next = ob->getNext();
        size = ob->size;
        param_list = ob->param_list;
    }

    void as_Array(string n, string t, int s)
    {
        Name = n;
        Type = t;
        size = s;
        Next = nullptr;
    }

    void as_Function(string n, string t)
    {
        Name = n;
        Type = t;
        size = -1;
        Next = nullptr;
    }

    ~SymbolInfo()
    {
        
    }

    string getName()
    {
        return Name;
    }
    void setName(string name)
    {
        Name = name;
    }
    string getType()
    {
        return Type;
    }
    void setType(string type)
    {
        Type = type;
    }
    void setNext(SymbolInfo* next)
    {
        Next = next;
    }
    SymbolInfo* getNext()
    {
        return Next;
    }

    void setSize(int s) {
            size = s;
        }

    int getSize() {
        return size;
    }

    bool isArray(){return (size>0);}
    bool isFunction(){return (size==-1);}
    bool isNotFixed(){return (size==0);}

    void addParam(string n, string t)
    {
        param p(n, t);
        param_list.push_back(p);
    }

    param getParam(int i)
    {
        return param_list.at(i);
    }

    vector<param> getParamList(){return param_list;}

    int getParamCount(){return param_list.size();}

};