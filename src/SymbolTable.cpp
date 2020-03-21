#include "../include/SymbolTable.h"

SymbolTable::SymbolTable()
{
    //ctor
}
void SymbolTable::free(){
}
SymbolTableEntry* SymbolTable::lookup(string symbol){

}
SymbolTableEntry* SymbolTable::insert(string symbol){
    symtab[symbol] = new SymbolTableEntry();
}
