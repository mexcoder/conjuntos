//
//  main.c
//
//
//  Created by OrozcoBianchi on 29/03/15.
//
//

#include <iostream>
#include "conjuntos.h"
#include "structs.h"

using namespace std;

vector<string> *item;
conjuntos c;

string name;

extern "C" void new_Item(char *it){
    
    name = string(it);
    
    item = new vector<string>();
    
}

extern "C" void addItem(char *it){
    
    item->push_back(string(it));
    
}

extern "C" void commitSet(){
    
    c.addItem(name,item);
    
}


extern "C" void errors(){//error de sintanxis
    cout<<"error de sintaxis en el comando"<<endl;
    
}

extern "C" void error(char* comando){
	cout<<"Comando desconocido: \"" << comando << "\"";
}

extern "C" void exitProgram(){
	cout<<"saliendo del programa"<<endl;
	exit(0);
}

extern "C" void sets(){
    
    
    vector<string> a = c.getSetNames();
    
    for(auto str : a){
        cout<<str<<", ";
    }
    cout<<endl;
    
}

extern "C" void PrepareTokens(){
    
    tokenList.c1 = "";
    tokenList.c2 = "";
    tokenList.c3 = "";
    
}

extern "C" void addToken(char *token){
    
    string t = string(token);
    
    if(tokenList.c1 == ""){
        tokenList.c1 = t;
    }
    else if(tokenList.c2 == ""){
        tokenList.c2 = t;
    }
    else{
        tokenList.c3 = t;
    }

}


extern "C" void showsets(){
    auto map = c.getSets();
    auto keys = c.getSetNames();
    
    for(auto key : keys){
        
        cout<<key<<" = { ";
        for(int x=0;x<map[key].size();x++){
            cout<<map[key][x];
            
            if(x<(map[key].size()-1))//pretty print
                cout<<", ";
        }
        cout<<" }"<<endl;
        
    }
    
}

void printset(string tittle,vector <string> source){

    cout<<tittle<<" = { ";
    
    for(int x=0;x<source.size();x++){
        
        cout<<source[x];
        
        if(x<(source.size()-1))//pretty print
            cout<<", ";
    }
    
    cout<<" }"<<endl;
    
}

extern "C" void runIns(tipoIns ins){
    
    vector<string> res;
    
    if(tokenList.c1 == "" || tokenList.c2 == ""){
        cout<<"faltan argumentos";
        return;
    }
    if( ( ins == setUNION || ins == setINTERSEC ) && tokenList.c3 == ""){
        cout<<"faltan argumentos";
        return;
    }
    
    
    switch (ins) {
            
        case UNION:
            res = c.Union(tokenList.c1,tokenList.c2);
            break;
        case INTERSEC:
            res = c.intersection(tokenList.c1,tokenList.c2);
            break;
            

        case setINTERSEC:
            res = c.setIntersection(tokenList.c1,tokenList.c2,tokenList.c3);
            break;
        case setUNION:
            res = c.setUnion(tokenList.c1,tokenList.c2,tokenList.c3);
            break;

    }
    
    printset("resultado",res);
}

#include "lex.yy.c"

int main(){
    
    //set values for debbugin
    new_Item("a");
    addItem("a");
    commitSet();
    
    new_Item("b");
    addItem("b");
    commitSet();
    
    showsets();
    
    //end debug values
    
    cout<<"esperando instrucciones"<<endl;
	yylex();
}