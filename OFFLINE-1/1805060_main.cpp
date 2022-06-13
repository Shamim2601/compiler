#include <iostream>
#include<cstring>
#include <fstream>

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
            cout<<"Inserted in ScopeTable# "<<ID<<" at position "<<k<<", "<<c<<endl;
            return true;
        }else{
            return false;
        }
    }

    //print the hash table in console
    void print()
    {
        cout<<endl<<endl<<"ScopeTable # "<<ID<<endl;
        for(int i = 0; i<bucket_size; i++)
        {
            cout<<i<<" --> ";
            SymbolInfo* tmp = SI_Array[i];
            while(tmp)
            {
                if(!(tmp->getName().empty())) {cout<<"< "<<tmp->getName()<<" : "<<tmp->getType()<<" >";}
                tmp = tmp->getNext();
            }
            cout<<endl;
        }
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
                cout<<"Found in ScopeTable # "<<ID<<" at position "<<k<<","<<c<<endl;
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
               cout<<"Deleted entry "<<k<<","<<c<<" from current ScopeTable"<<endl;
               return true;
           }else{
               SymbolInfo* tmp = SI_Array[k];
               while(tmp->getNext())
               {
                   if(tmp->getNext()->getName()==entry)
                   {
                       SymbolInfo* toDel = tmp->getNext();
                       tmp->setNext(toDel->getNext());
                       cout<<"Deleted entry "<<k<<","<<c+1<<" from current ScopeTable"<<endl;
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

//symbol table to store list of scope tables
class SymbolTable
{
public:
    int numOfScopes;
    int bucket_size;
    ScopeTable* CurrentScopeTable;
    SymbolTable(int bs){CurrentScopeTable = NULL; numOfScopes =0; bucket_size = bs;}
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
        cout<<"New Scope Table with id "<<st->getID()<<" created"<<endl; //#
    }

    void exit_scope()
    {
        if(CurrentScopeTable)
        {
            ScopeTable* delSC = CurrentScopeTable;
            cout<<"ScopeTable with ID "<<delSC->getID()<<" removed"<<endl;
            CurrentScopeTable = CurrentScopeTable->getParentScope();
            delete delSC;
        }else{
            cout<<"No Current ScopeTable"<<endl;
        }
    }

    void print_current()
    {
        if(CurrentScopeTable){CurrentScopeTable->print();}
        else{cout<<"No Current Scope Table";}
    }

    void print_all()
    {
        ScopeTable* tmp = CurrentScopeTable;
        if(tmp)
        {
            while(tmp)
           {
               //cout<<tmp->getID()<<":"<<endl;
               tmp->print();
               tmp = tmp->getParentScope();
           }
        }else{
           cout<<"No Current Scope Table";
        }
    }

    bool insert(string s1, string s2)
    {
        if(CurrentScopeTable)
        {
            if(CurrentScopeTable->insert(s1,s2))
            {
                return true;
            }
            else{
                cout<<"<"<<s1<<":"<<s2<<"> already exists in current ScopeTable."<<endl;
                return false;
            }
        }else{
            enter_scope();
            insert(s1,s2);
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
                cout<<"Not found"<<endl;
                cout<<symbolname<<" not found"<<endl;
                return false;
            }
        }else{
            cout<<"No Current ScopeTable"<<endl;
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
        cout<<"Not found"<<endl;
        return NULL;
    }
};


int main()
{
    int numOfBuckets = 0;

    ifstream inpFile("input.txt");
    string line;
    if(inpFile.is_open())
    {
        inpFile>>numOfBuckets;
        SymbolInfo si;
        ScopeTable* sc = new ScopeTable(numOfBuckets);
        sc->setID("1");
        SymbolTable st(sc, numOfBuckets);
        getline(inpFile, line);
        while(getline(inpFile, line))
        {
            string str[2];
            char ch;
            int i;
            switch (line.at(0))
            {
                case 'I':
                    i = 2;
                    for(;line[i]!=' ';i++)
                    {
                        str[0].push_back(line[i]);
                    }
                    for(;i<line.length();i++)
                    {
                        str[1].push_back(line[i]);
                    }

                    cout<<"I\t"<<str[0]<<" "<<str[1]<<endl;
                    st.insert(str[0],str[1]);
                    cout<<endl;
                    break;

                case 'L':
                    for(int j=2;j<line.length();j++)
                    {
                        str[0].push_back(line[j]);
                    }
                    cout<<"L\t"<<str[0]<<endl;
                    st.look_up(str[0]);
                    cout<<endl;
                    break;

                case 'D':
                    for(int i=2;i<line.length();i++)
                    {
                        str[0].push_back(line[i]);
                    }
                    cout<<"D\t"<<str[0]<<endl;
                    st.remove(str[0]);
                    cout<<endl;
                    break;

                case 'P':
                    cout<<"P ";
                    switch (line[2])
                    {
                    case 'A':
                        cout<<"A"<<endl;
                        st.print_all();
                        break;

                    case 'C':
                        cout<<"C"<<endl;
                        st.print_current();
                        break;
                    
                    default:
                        cout<<endl;
                        break;
                    }
                    cout<<endl;
                    break;

                case 'S':
                    cout<<"S"<<endl;
                    st.enter_scope();
                    cout<<endl;
                    break;

                case 'E':
                    cout<<"E"<<endl;
                    st.exit_scope();
                    cout<<endl;
                    break;

                default:
                    cout<<"Don't know what to do."<<endl;
                    cout<<endl;
                    break;

            }
        }
        inpFile.close();
    }
    else
    {
        cout<<"Unable to open input file."<<endl;
    }
   
    return 0;
}
