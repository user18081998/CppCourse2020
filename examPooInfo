#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

using namespace std;

// #####################################################################
// ############################## HEADER ###############################
// #####################################################################

class Fichier{
    string nom;
    string extension;
    double taille=0;
    public:
    Fichier(const string& n,const string& e, const double& t);
    ~Fichier();
    double getTaille() const;
    string getExtension() const;
    friend bool operator<(const Fichier&,const Fichier&);       // comparer
    friend ostream& operator<<(ostream& out, const Fichier&);   // affichage des caracteristiques
};
class Peripherique{
    protected :
    string nomLogique;
    double espaceDeStockage=0;
    vector<Fichier> fichiers;
    public :
    virtual double getEspaceDeStockage() const =0;
    virtual double getEspaceLibre() const =0;
    virtual int ajouterFichier(const Fichier&)=0;
    virtual vector<Fichier> rechercheExtension(const string&) const =0;
    virtual int supprimerFichiers()=0;

};
class CleUSB : protected Peripherique{
    double capaciteDeStockage=0;
    double zoneInutilisable=0;
    // double espaceDeStockage; taille-freeStorage
    public :
    CleUSB(const string& n, const double& cds, const double& zi);
    ~CleUSB();
    double getEspaceDeStockage() const;
    double getEspaceLibre() const;
    int ajouterFichier(const Fichier&);
    vector<Fichier> rechercheExtension(const string&) const;
    int supprimerFichiers();
};

class DisqueDur : protected Peripherique{
    double tailleSecteur=0;
    int nombreSecteursParPiste=0;
    int nombreDePistesParSurface=0;
    int nombreDeSurfaces=0;
    // double espaceDeStockage; mul les trois variables
    public :
    DisqueDur(const string&,const double&, const int&,const int&,const int&);
    ~DisqueDur();
    double getEspaceDeStockage() const;
    double getEspaceLibre() const;
    int ajouterFichier(const Fichier&);
    vector<Fichier> rechercheExtension(const string&) const;
    int supprimerFichiers();
};

class DataCenter{
    string nom;
    vector<Peripherique*> peripheriques;
    public :
    DataCenter(const string&);
    ~DataCenter();
    int ajouterPStockage(Peripherique*);
    int ajouterFichier(const Fichier&);
    double getEspaceStockage() const ;
    double getEspaceLibre() const ;
    int supprimerFichiers();
    friend ostream& operator<<(ostream&,const DataCenter&); //nom, espace utilisable, espace restant
};

// #####################################################################
// ################################ CODE ###############################
// #####################################################################
// Fichier
Fichier::Fichier(const string& n,const string& e, const double& t){
    nom=n; extension=e; taille=t;
}
Fichier::~Fichier(){}
double Fichier::getTaille() const{return taille;}
bool operator<(const Fichier& fichier1, const Fichier& fichier2){
    return fichier1.taille<fichier2.taille;
}
string Fichier::getExtension() const{
    return extension;
}
ostream& operator<<(ostream& out, const Fichier& fichier){
    out<<"Nom du fichier : "<<fichier.nom<<endl;
    out<<"Extension : "<<fichier.extension<<endl;
    out<<"Taille : "<<fichier.taille<<"ko"<<endl;
    return out;
}

// CleUSB
CleUSB::CleUSB(const string& n, const double& cds, const double& zi){
    nomLogique=n; capaciteDeStockage=cds; zoneInutilisable=zi; 
    espaceDeStockage=this->getEspaceDeStockage();
}
CleUSB::~CleUSB(){}
double CleUSB::getEspaceDeStockage() const{
    return capaciteDeStockage-zoneInutilisable;
}
double CleUSB::getEspaceLibre() const{
    double espaceUtilise=0;
    for(auto& fichier : fichiers) espaceUtilise+=fichier.getTaille();
    return getEspaceDeStockage()-espaceUtilise;
}
int CleUSB::ajouterFichier(const Fichier& fichier){
    fichiers.push_back(fichier);
    espaceDeStockage=this->getEspaceDeStockage();
    return 1;
}
vector<Fichier> CleUSB::rechercheExtension(const string& extension) const{
    vector<Fichier> resultat;
    for(auto& fichier : fichiers) if(fichier.getExtension()==extension) resultat.push_back(fichier);
    return resultat;
}
int CleUSB::supprimerFichiers(){
    for(auto& fichier : fichiers) fichiers.pop_back();
    espaceDeStockage=this->getEspaceDeStockage();
    return 1;
}

// Disque Dur
DisqueDur::DisqueDur(const string& n,const double& ts, const int& nspp, const int& ndpps ,const int& nds){
    tailleSecteur=ts; nombreSecteursParPiste=nspp; nombreDePistesParSurface=ndpps; nombreDeSurfaces=nds;
    espaceDeStockage=this->getEspaceDeStockage();
}
DisqueDur::~DisqueDur(){}
double DisqueDur::getEspaceDeStockage() const{
    return tailleSecteur*nombreSecteursParPiste*nombreDePistesParSurface*nombreDeSurfaces;
}
double DisqueDur::getEspaceLibre() const{
    double espaceUtilise=0;
    for(auto& fichier : fichiers) espaceUtilise+=fichier.getTaille();
    return getEspaceDeStockage()-espaceUtilise;
}
int DisqueDur::ajouterFichier(const Fichier& fichier){
    fichiers.push_back(fichier);
    espaceDeStockage=this->getEspaceDeStockage();
    return 1;
}
vector<Fichier> DisqueDur::rechercheExtension(const string& extension) const{
    vector<Fichier> resultat;
    for(auto& fichier : fichiers) if(fichier.getExtension()==extension) resultat.push_back(fichier);
    return resultat;
}
int DisqueDur::supprimerFichiers(){
    for(auto& fichier : fichiers) fichiers.pop_back();
    espaceDeStockage=this->getEspaceDeStockage();
    return 1;
}

// Data Center
DataCenter::DataCenter(const string& n){
    nom=n;
}
DataCenter::~DataCenter(){}
int DataCenter::ajouterPStockage(Peripherique* peripherique){
    peripheriques.push_back(peripherique);
    return 1;
}
int DataCenter::ajouterFichier(const Fichier& fichier){
    int state=0;
    for(auto& peripherique : peripheriques) if(peripherique->getEspaceDeStockage()>fichier.getTaille()) {
        peripherique->ajouterFichier(fichier);
        state=1;
        break;
    }
    return state;
}
double DataCenter::getEspaceStockage() const{
    double espace=0;
    for(auto& peripherique : peripheriques) espace+=peripherique->getEspaceDeStockage();
    return espace;
}
double DataCenter::getEspaceLibre() const{
    double espace=0;
    for(auto& peripherique : peripheriques) espace+=peripherique->getEspaceLibre();
    return espace;
}
int DataCenter::supprimerFichiers(){
    for(auto& peripherique : peripheriques) peripherique->supprimerFichiers();
    return 1;
}
ostream& operator<<(ostream& out,const DataCenter& dataCenter){
    out<<"Nom du data center : "<<dataCenter.nom<<endl;
    out<<"Espace utilisable : "<<dataCenter.getEspaceStockage()<<endl;
    out<<"Espace restant : "<<dataCenter.getEspaceLibre();
    return out;
}

int main(){
    cout.setf(ios::fixed);
    // DisqueDur dd=DisqueDur((string) "C",512,520,1024,16);
    DisqueDur dd=DisqueDur((string) "C",512,520,1024,16);
    dd.ajouterFichier(Fichier("fichier1","txt",45));
    dd.ajouterFichier(Fichier("fichier2","doc",100));
    dd.ajouterFichier(Fichier("fichier3","txt",30));
    for(auto& fichier : dd.rechercheExtension("doc")) cout<<fichier;
    cout<<endl;
    DataCenter dataCenter=DataCenter("myDataCenter");
    Peripherique* dd_ptr=(Peripherique*)&dd;
    dataCenter.ajouterPStockage(dd_ptr);
    CleUSB cusb=CleUSB("D",1000000,0);
    Peripherique* cusb_ptr=(Peripherique*) &cusb;
    dataCenter.ajouterPStockage(cusb_ptr);
    cout<<"Data center apres ajout du disque dur et de la cle usb : "<<endl;
    cout<<dataCenter<<endl;
    dataCenter.ajouterFichier(Fichier("fichier3","pdf",150));
    cout<<"Data center apres ajout du fichier : "<<endl;
    cout<<dataCenter<<endl;
    dataCenter.supprimerFichiers();
    cout<<"Data center apres formatage : "<<endl;
    cout<<dataCenter<<endl;
    return 0;
}
/*
data center 512*520*1024*16+1000000=4 363 076 160 
*/
