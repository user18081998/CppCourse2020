#include "matrice.h"
#include "matrice.cpp"

using namespace std;
int main(){
    Matrice<double> matDouble1{3,3,-0.0009},matDoubleIdentite{3,3,1.0};
    Matrice<float> matFloat1{3,3,3.02324},matFloat2,matFloatNul{3,3};
    Matrice<int> matInt1{3,3,3};
    cout<<"tester avec des matrices doubles :"<<endl<<matDouble1+matDoubleIdentite<<endl;
    cout<<"tester avec des matrices float :"<<endl;
    matFloat2=matFloat1+matFloatNul;
    cout<<matFloat2;
    cout<<"tester avec des matrices entieres :"<<endl;
    cout<<matInt1+5<<endl;
    return 0;
}