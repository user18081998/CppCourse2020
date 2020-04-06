#ifndef MATRICE_CPP
#define MATRICE_CPP

#include "matrice.h"
#include<iostream>
using namespace std;


//constructeurs
template<class S>
Matrice<S>::Matrice(const unsigned int i,const unsigned int j,const S& x) {
    if(i==0 || j==0){
        n_lignes=0;
        n_colonnes=0;
        mat=nullptr;
    }
    mat=new S[i*j]; n_lignes=i; n_colonnes=j;
    for(int c=0;c<i*j;c++)
        mat[c]=x;
}

template<class S>
Matrice<S>::Matrice(){
    mat=nullptr;
    n_lignes=0;
    n_colonnes=0;
}

//destructeur
template<class S> 
Matrice<S>::~Matrice(){ delete[] mat;}



// methodes setVal

template<class S> 
unsigned int Matrice<S>::getLignes() const {return n_lignes;}

template<class S> 
unsigned int Matrice<S>::getColonnes() const {return n_colonnes;}

template<class S> 
S* Matrice<S>::getMat() const {return mat;}



// methodes getVal

template<class S> 
void Matrice<S>::setLignes(const unsigned int& i){n_lignes=i;}

template<class S> 
void Matrice<S>::setColones(const unsigned int& j){n_colonnes=j;}

template<class S> 
void Matrice<S>::setMat(const S* Mat) {mat=Mat;};



//surcharger operateur =

template<class S> 
Matrice<S>& Matrice<S>::operator=(const Matrice<S>& other){
    n_lignes=other.getLignes();
    n_colonnes=other.getColonnes();
    mat= new S(n_colonnes*n_lignes);
    for(int i=0;i<n_lignes*n_colonnes;i++)
        mat[i]=other.getMat()[i];
    return *this;
}



//surcharger operateur +

template<class S>
Matrice<S> operator+(const Matrice<S>& m1,const Matrice<S>& m2){
    Matrice<S> resultat(m1.getLignes(),m1.getColonnes(),0);
    try{
        if(!(m1.getLignes()==m2.getLignes() && m1.getLignes()==m2.getColonnes()))
            throw "Matrices incompatibles";
        for(int i=0;i<m1.getLignes()*m1.getColonnes();i++)
            resultat.mat[i]=m1.getMat()[i]+m2.getMat()[i];
        
    } catch(const char* m){
    cerr << m <<endl;
    }
    return resultat;
}

template<class S>
Matrice<S> operator+(const Matrice<S>& m,const S& scal){
    Matrice<S> resultat(m.getLignes(),m.getColonnes(),scal);
    return resultat+m;
}

template<class S>
Matrice<S> operator+(const S& scal,const Matrice<S>& m){return m+scal;}



// surcharger operateur <<

template<class S>
ostream& operator<<(ostream& out,const Matrice<S>& M){
    out<<"["<<endl;
    for(int i=0;i<M.getLignes();i++){
        out<<" [";
        for(int j=0;j<M.getColonnes();j++) out<<M.mat[i+j]<<", ";
        out<<"],"<<endl;
    }
    out<<"]"<<endl;
    return out;
}


#endif