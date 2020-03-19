#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H


class SymbolTable
{
    public:
        SymbolTable();
        void free();
        SymbolTableEntry* lookup(string symbol);
        SymbolTableEntry* insert(string symbol);
        //set attributes
        //get attributes

    protected:

    private:
};

#endif // SYMBOLTABLE_H
