#pragma once
#include <iostream>
#include<cstring>
#include<fstream>
#include "SymbolInfo.cpp"

using namespace std;

//hash table of a scope. have an unique id and a pointer to parent scope.
//hash table is 2d array of symbolinfo type pointer.
class ScopeTable
{
    string ID;
    ScopeTable* ParentScope;
public:
    int numOfChild;
    SymbolInfo** SI_Array;
    int bucket_size;
    ScopeTable(int n)
    {
        ParentScope = NULL; 
        bucket_size = n;
        numOfChild = 0;
        SI_Array = new SymbolInfo*[bucket_size];
        for(int i = 0;i<bucket_size; i++)
        {
            SI_Array[i] = NULL;
        }
    }
    
    ScopeTable(ScopeTable* ob)  //copy constructor
    {
        ID = ob->getID();
        ParentScope = ob->ParentScope;
        bucket_size = ob->bucket_size;
        numOfChild = ob->numOfChild;
        SI_Array = ob->SI_Array;
    }
    ~ScopeTable()
    {
        for(int i = 0;i<bucket_size; i++)
        {
            SymbolInfo* toDel = SI_Array[i];
            while(toDel)
            {
                SymbolInfo* next = toDel->getNext();
                delete toDel;
                toDel = next;
            }
        }
        delete []SI_Array;
    }

    string getID(){return ID;}
    void setID(string id){ID = id;}

    ScopeTable* getParentScope()
    {
        return ParentScope;
    }
    void setParentScope(ScopeTable* parent)
    {
        ParentScope = parent;
    }

    unsigned long sdbm(string str)  //standard sdbm hash for string
    {
        unsigned long hash = 0;
        int c;
        int i = 0;
        while(c = str[i++])
        {
            hash = c + (hash <<6 )+(hash << 16) - hash;
        }
        return hash;
    }

    int hashFunc(string str, int total_buckets)
    {
        return sdbm(str) % total_buckets;
    }

    //if a symbol is not already there,it's inserted to hash table and returned true
    bool insert(string s1, string s2)
    {       
        if(!look_up(s1))  //a symbol will be inserted only if it's not already exists
        {
            SymbolInfo* si = new SymbolInfo(s1,s2);
            int k = hashFunc(s1, bucket_size);
            int c = 0;
            SymbolInfo* tmp = SI_Array[k];
            if(!tmp){SI_Array[k] = si; }
            else{    //chaining mechanism to deal with collision
                while(tmp->getNext())
                {
                    tmp = tmp->getNext();
                }
                c++;
                tmp->setNext(si);
            }
            //cout<<"Inserted in ScopeTable# "<<ID<<" at position "<<k<<", "<<c<<endl;
            return true;
        }else{
            return false;
        }
    }

    //print the hash table in console
    void print(FILE* logout)
    {
        //lout<<"ScopeTable # "<<ID<<endl;
        fprintf(logout,"Scopetable #%s\n", ID.c_str());
        for(int i = 0; i<bucket_size; i++)
        {
            if(SI_Array[i])
            {
                //lout<<i<<" --> ";
                fprintf(logout,"%d -->> ", i);
                SymbolInfo* tmp = SI_Array[i];
                while(tmp)
                {
                    //lout<<"< "<<tmp->getName()<<" : "<<tmp->getType()<<" >";
                    fprintf(logout,"< %s : %s >", tmp->getName().c_str(), tmp->getType().c_str());
                    tmp = tmp->getNext();
                }
                delete tmp;
                //lout<<endl;
                fprintf(logout,"\n");
            }
        }
        fprintf(logout,"\n");
    }

    //if a symbol is present in the hash table, pointer to it is returned
    SymbolInfo* look_up(string ob)
    {
        int k = hashFunc(ob, bucket_size);
        int c=0;
        SymbolInfo* tmp = SI_Array[k];
        while(tmp)
        {
            if(tmp->getName()==ob)
            {
                //cout<<"Found in ScopeTable # "<<ID<<" at position "<<k<<","<<c<<endl;
                return tmp;
            }
            tmp = tmp->getNext();
            c++;
        }
        return NULL;  
    }

    //to remove a symbol from hash table
    bool delete_entry(string entry)
    {
        int k = hashFunc(entry, bucket_size);
        int c =0;
        if(SI_Array[k])
        {
           if(SI_Array[k]->getName()==entry)
           {
               SymbolInfo* toDel = SI_Array[k];
               SI_Array[k] = toDel->getNext();
               delete toDel;
               //cout<<"Deleted entry "<<k<<","<<c<<" from current ScopeTable"<<endl;
               return true;
           }else{
               SymbolInfo* tmp = SI_Array[k];
               while(tmp->getNext())
               {
                   if(tmp->getNext()->getName()==entry)
                   {
                       SymbolInfo* toDel = tmp->getNext();
                       tmp->setNext(toDel->getNext());
                       //cout<<"Deleted entry "<<k<<","<<c+1<<" from current ScopeTable"<<endl;
                       delete toDel;
                       return true;
                   }
                   c++;
                   tmp = tmp->getNext();
               }
               return false;
           }
        }else{
            return false;
        }
    }
};