#pragma once
#include <bits/stdc++.h>
#include "ScopeTable.cpp"


using namespace std;
   
//symbol table to store list of scope tables
class SymbolTable
{
public:
    int numOfScopes;
    int bucket_size;
    ScopeTable* CurrentScopeTable;
    SymbolTable(int bs){CurrentScopeTable = NULL; numOfScopes = 1; bucket_size = bs;}
    SymbolTable(ScopeTable* scopeTable, int bs){CurrentScopeTable = scopeTable; numOfScopes= 1; bucket_size = bs;}
    ~SymbolTable()
    {
        ScopeTable* toDel = CurrentScopeTable;
        while(toDel)
        {
            ScopeTable* tmp = toDel->getParentScope();
            delete toDel;
            toDel = tmp;
        }
    }

    void enter_scope()
    {
        ScopeTable* st= new ScopeTable(bucket_size);
        if(CurrentScopeTable)
        {
            st->setParentScope(CurrentScopeTable);
            CurrentScopeTable->numOfChild++;
            st->setID(st->getParentScope()->getID()+'.'+to_string(st->getParentScope()->numOfChild));
        }else{
            st->setID(to_string(numOfScopes));
        }
        CurrentScopeTable = st;
        //cout<<"New Scope Table with id "<<st->getID()<<" created"<<endl; //#
    }

    void exit_scope()
    {
        if(CurrentScopeTable)
        {
            ScopeTable* delSC = CurrentScopeTable;
            //cout<<"ScopeTable with ID "<<delSC->getID()<<" removed"<<endl;
            CurrentScopeTable = CurrentScopeTable->getParentScope();
            delete delSC;
        }else{
            //cout<<"No Current ScopeTable"<<endl;
        }
    }

    // void print_current()
    // {
    //     if(CurrentScopeTable){CurrentScopeTable->print();}
    //     else{/*cout<<"No Current Scope Table";*/}
    // }

    void print_all(ofstream& log_file)
    {
        ScopeTable* tmp = CurrentScopeTable;
        if(tmp)
        {
            while(tmp)
           {
               //cout<<tmp->getID()<<":"<<endl;
               tmp->print(log_file);
               tmp = tmp->getParentScope();
           }
        }else{
           //cout<<"No Current Scope Table";
        }
    }

    bool insert(string s1, string s2)
    {
        if(CurrentScopeTable)
        {
            if(CurrentScopeTable->insert(s1,s2))
            {
                //print_all(fp);
                return true;
            }
            else{
                //cout<<"<"<<s1<<":"<<s2<<"> already exists in current ScopeTable."<<endl;
                return false;
            }
        }else{
            enter_scope();
            insert(s1,s2);
            return true;
        }
    }

    bool insert(SymbolInfo* si)
    {
        if(CurrentScopeTable)
        {
            if(CurrentScopeTable->insert(si))
            {
                //print_all(fp);
                return true;
            }
            else{
                //cout<<"<"<<s1<<":"<<s2<<"> already exists in current ScopeTable."<<endl;
                return false;
            }
        }else{
            enter_scope();
            insert(si);
            return true;
        }
    }

    bool remove(string symbolname)
    {
        if(CurrentScopeTable)
        {
            if(CurrentScopeTable->look_up(symbolname))
            {
                CurrentScopeTable->delete_entry(symbolname);
                return true;
            }
            else{
                //cout<<"Not found"<<endl;
                //cout<<symbolname<<" not found"<<endl;
                return false;
            }
        }else{
            //cout<<"No Current ScopeTable"<<endl;
            return false;
        }
    }

    SymbolInfo* look_up(string ob)
    {
        ScopeTable* temp = CurrentScopeTable;
        while(temp)
        {
            SymbolInfo* result = temp->look_up(ob);
            if(result)
            {
                return result;
            }
            temp = temp->getParentScope();
        }
        //cout<<"Not found"<<endl;
        return NULL;
    }
};
