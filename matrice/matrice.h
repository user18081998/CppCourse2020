#ifndef MATRICE_H
#define MATRICE_H

#include<iostream>
using namespace std;

template<class Scalaire> class Matrice{
    private :

    Scalaire* mat;
    unsigned int n_lignes;
    unsigned int n_colonnes;
    
    public:
    
    Matrice(const unsigned int i,const unsigned int j,const Scalaire& x=0);
    Matrice();
    ~Matrice();
    
    Matrice<Scalaire>& operator=(const Matrice<Scalaire>& other);
    
    template<class S>
    friend Matrice<S> operator+(const Matrice<S>& m1,const Matrice<S>& m2);
    template<class S> 
    friend Matrice<S> operator+(const Matrice<S>& m,const S& scal);
    template<class S> 
    friend Matrice<S> operator+(const S& scal,const Matrice<S>& m);

    template<class S>
    friend ostream& operator<<(ostream& out,const Matrice<S>& M);

    unsigned int getLignes() const;
    unsigned int getColonnes() const;
    Scalaire* getMat() const;

    void setLignes(const unsigned int& i);
    void setColones(const unsigned int& j);
    void setMat(const Scalaire* Mat);

};

#endif