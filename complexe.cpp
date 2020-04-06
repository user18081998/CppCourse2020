#include<iostream>
#include<cmath>

using namespace std;
inline float square(float f){return f*f;};

class Complex{
    private :
    float re=0,im=0;
    
    public:
    Complex(float r,float i=0) : re{r},im{i}{}
    Complex() : re{0},im{0}{} 
    float getReal() const {return re;}
    float getImag() const {return im;}
    Complex(const Complex& other) : re{other.getReal()},im{other.getImag()}{}


    Complex conjugate() {return Complex(re,-im);}
    float module() {return sqrt(square(re)+square(im));}

    Complex operator=(const Complex& other){re=other.getReal();im=other.getImag(); return *this;}
    Complex operator+(const Complex& other) {return Complex(re+other.getReal(),im+other.getImag());}
    Complex operator-(const Complex& other) {return Complex(re-other.getReal(),im-other.getImag());}
    Complex operator*(const Complex& other) {return Complex(re*other.getReal()-im*other.getImag(),re*other.getImag()+im*other.getReal());}
    Complex operator/(const Complex& other) {
        float q=(square(Complex(other).module()));
        Complex p=*this * Complex(other).conjugate();
        return Complex(p.getReal()/q,p.getImag()/q);
    }

    Complex operator+=(const Complex& other){re+=other.getReal();im+=other.getImag();return *this;}
    bool operator==(const Complex& other) {return (re==other.getReal() && im==other.getImag());}
    bool operator!=(const Complex& other) {return !(*this==other);}

    friend ostream& operator<<(ostream& out,const Complex& z);
    friend istream& operator>>(istream& in,Complex& z);
};
ostream& operator<<(ostream& out,const Complex& z){
    return out<<z.getReal()<<"+"<<z.getImag()<<"i";
}
istream& operator>>(istream& in,Complex& z){
    cout<<endl<<"Entrer la partie Reelle : ";
    cin>>z.re;
    cout<<"Entrer la partie imaginaire : ";
    cin>>z.im;
    return in;
}

int main(){
    Complex z1;
    Complex z2;
    Complex z3;
    cout<<"z1: ";
    cin>>z1;
    cout<<"z2: ";
    cin>>z2;
    cout<<"z1 ="<<z1<<endl<<"z2 ="<<z2<<endl;
    z3=z1/z2;
    cout << "z3 = z1*z2 =" << z3<<endl;
    return 0;
}
