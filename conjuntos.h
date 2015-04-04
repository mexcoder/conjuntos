//
//  conjuntos.h
//
//
//  Created by OrozcoBianchi on 29/03/15.
//
//
#pragma clang diagnostic ignored "-Wc++11-extensions"
#ifndef ____conjuntos__
#define ____conjuntos__

#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>

using namespace std;

class conjuntos {
    
protected:
    
    tr1::unordered_map< std::string, vector <string> > sets;
    
    void initVector(vector<string> *vec,int);
    
    vector<string> setUnion(vector<string> s1,vector<string> s2,vector<string> *dest);
    
    vector<string> setIntersection(vector<string> s1,vector<string> s2,vector<string> *dest);
    
    
public:
    
    void addItem(string,vector<string>*);
    
    vector<string> Union(string, string);
    vector<string> intersection(string s1,string s2);
    vector<string> setUnion(string s1,string s2,string dest);
    vector<string> setIntersection(string s1,string s2,string dest);
    vector<string> getSetNames();
    tr1::unordered_map< std::string, vector <string> > getSets();
    
};

#endif /* defined(____conjuntos__) */
