#pragma once
#include <iostream>
#include<cstring>

using namespace std;

//contain name and type info of symbol and a next pointer to resolve collision
class SymbolInfo
{
    string Name;
    string Type;
    SymbolInfo* Next;
public:
    SymbolInfo()
    {
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
};