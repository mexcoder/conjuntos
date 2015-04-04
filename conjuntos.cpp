//
//  conjuntos.cpp
//  
//
//  Created by OrozcoBianchi on 29/03/15.
//
//

#include "conjuntos.h"

vector<string> conjuntos::getSetNames(){
    
    vector<string> names;
    names.reserve(this->sets.size());
    
    for(auto kv : this->sets){
        names.push_back(kv.first);
    }
    
    std::sort(names.begin(), names.end());
    
    return names;
    
}

void conjuntos::addItem(string title, vector<string> *item){
    
    
    std::sort(item->begin(), item->end());
    
    this->sets[string(title)] = *item;
    delete item;
    
}

tr1::unordered_map< std::string, vector <string> > conjuntos::getSets(){
    
    return this->sets;
}

void conjuntos::initVector(vector<string> *vec,int size){
    
    vec->reserve(size);
    //crazy bug
    // reserve do not instansiate de class
    // so all you get its a bunch of null pointers
    // neither set_union does, so you end assigning an empty value(segment fault)
    // to de null pointer
    // so lets init the vector with empy strings and the bug its gone
    //
    for (int x=0; x<=size; x++) {
        vec->push_back("");
    }


}

vector<string> conjuntos::setUnion(vector<string> s1,vector<string> s2,vector<string> *dest){

    std::vector<string>::iterator it;
    
    int size =s1.size()+s2.size();
    
    this->initVector(dest,size);
    
    it = std::set_union (s1.begin(), s1.end(), s2.begin(), s2.end(), dest->begin());
    
    dest->resize(it-dest->begin());
    
    return *dest;

}

vector<string> conjuntos::Union(string s1,string s2){
    
    return setUnion(this->sets[s1],this->sets[s2],new vector<string>());
    
}

vector<string> conjuntos::setUnion(string s1,string s2,string dest){
    
    return setUnion(this->sets[s1],this->sets[s2],&this->sets[dest]);
    
}



vector<string> conjuntos::setIntersection(vector<string> s1,vector<string> s2,vector<string> *dest){
    
    std::vector<string>::iterator it;
    
    int size =s1.size()+s2.size();
    
    this->initVector(dest,size);
    
    it = std::set_intersection (s1.begin(), s1.end(), s2.begin(), s2.end(), dest->begin());
    
    dest->resize(it-dest->begin());
    
    return *dest;
    
}


vector<string> conjuntos::intersection(string s1,string s2){
    
    return setIntersection(this->sets[s1],this->sets[s2],new vector<string>());
    
}


vector<string> conjuntos::setIntersection(string s1,string s2,string dest){
    
    return setIntersection(this->sets[s1],this->sets[s2],&this->sets[dest]);
}
