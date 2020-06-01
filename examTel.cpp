#include<iostream>
#include<vector>
#include<string>

using namespace std;

// ################################################## Exemplaire ##################################################
class Exemplaire{
    string identifiant;
    bool reservation;
    public :
    Exemplaire();
    Exemplaire(const string& id, const bool& res);
    ~Exemplaire();
    string getIdentifiant()const;
    void setIdentifiant(const string& val);
    bool getReservation() const;
    void setReservation(const bool val);

};
Exemplaire::Exemplaire(){}
Exemplaire::Exemplaire(const string& id, const bool& res){
    identifiant=id; reservation=res;
}
Exemplaire::~Exemplaire(){}
string Exemplaire::getIdentifiant() const{return identifiant;}
void Exemplaire::setIdentifiant(const string& val){identifiant=val;}
bool Exemplaire::getReservation() const{return reservation;}
void Exemplaire::setReservation(const bool val){reservation=val;}


// ################################################## OUVRAGE ##################################################
class Ouvrage{
    protected :
    string ISBN;
    string titre;
    vector<Exemplaire> exemplaires;

    public :
    Ouvrage();
    Ouvrage(const string& isbn, const string& t,const vector<Exemplaire>& exemp);
    Ouvrage(const string& isbn, const string& t);
    ~Ouvrage();
    string getISBN() const;
    vector<Exemplaire> getExemplaires() const;

    void AjouterExemplaire(const Exemplaire& exem);
    virtual string auteurOuImpact()const =0;
};
Ouvrage::Ouvrage(){}
Ouvrage::Ouvrage(const string& isbn, const string& t,const vector<Exemplaire>& exemp){
    ISBN=isbn; titre=t; exemplaires=exemp;
}
Ouvrage::Ouvrage(const string& isbn, const string& t){
    ISBN=isbn; titre=t;
}
Ouvrage::~Ouvrage(){}
string Ouvrage::getISBN() const{return ISBN;}
vector<Exemplaire> Ouvrage::getExemplaires() const{return exemplaires;}
void Ouvrage::AjouterExemplaire(const Exemplaire& exem){
    exemplaires.push_back(exem);
}

// ################################################## Revue ##################################################
class Revue : protected Ouvrage {
    string editeur;
    string impactScientifique;

    public:
    Revue();
    Revue(const string& isbn, const string& t,const vector<Exemplaire>& exemp,const string& edit, const string is);
    Revue(const string& isbn, const string& t,const string& edit, const string is);
    ~Revue();
    string getEditeur() const;
    void setEditeur(const string& val);
    string getImpactScientifique() const;
    void setImpactScientifique(const string val);

    string auteurOuImpact() const;
};
Revue::Revue(){}
Revue::Revue(const string& isbn, const string& t,const vector<Exemplaire>& exemp,const string& edit, const string is){
    ISBN=isbn; titre=t; exemplaires=exemp; editeur=edit; impactScientifique=is;
}
Revue::Revue(const string& isbn, const string& t,const string& edit, const string is){
    ISBN=isbn; titre=t; editeur=edit; impactScientifique=is;
}
Revue::~Revue(){}
string Revue::getEditeur() const{
    return editeur;
}
void Revue::setEditeur(const string& val){editeur=val;}
string Revue::getImpactScientifique() const{return impactScientifique;}
void Revue::setImpactScientifique(const string val){impactScientifique=val;}
string Revue::auteurOuImpact() const {return "impact : " + impactScientifique;}

// ################################################## Livre ##################################################
class Livre : protected Ouvrage {
    string auteur;
    string resume;
    public :
    Livre();
    Livre(const string& isbn, const string& t,const vector<Exemplaire>& exemp,const string& aut, const string& res);
    Livre(const string& isbn, const string& t,const string& aut, const string& res);
    ~Livre();
    string getAuteur() const;
    void setAuteur(const string& val);
    string getResume() const;
    void setResume(const string& val);

    string auteurOuImpact() const ;
};
Livre::Livre(){}
Livre::Livre(const string& isbn, const string& t,const vector<Exemplaire>& exemp,const string& aut, const string& res){
    ISBN=isbn; titre=t; exemplaires=exemp; auteur=aut; resume=res;
}
Livre::Livre(const string& isbn, const string& t,const string& aut, const string& res){
    ISBN=isbn; titre=t; auteur=aut; resume=res;
}
Livre::~Livre(){}
string Livre::getAuteur() const{return auteur;}
void Livre::setAuteur(const string& val){auteur=val;}
string Livre::getResume() const{return resume;}
void Livre::setResume(const string& val){resume=val;}
string Livre::auteurOuImpact()const {return "auteur : " + auteur;}

// ################################################## EMPRUNTEUR ##################################################
class Emprunteur{
    private :
    string login;
    string motDePasse;
    string nom;
    string prenom;
    string niveauDEtude;
    public :
    Emprunteur();
    Emprunteur(const string& log, const string& mdps,const string& n,const string& pn,const string& nde);
    ~Emprunteur();
    
    string getLogin() const;
    void setLogin(const string& val);
    string getMotDePasse() const;
    void setMotDePasse(const string& val);
    string getNom() const;
    void setNom(const string& val);
    string getPrenom() const;
    void setPrenom(const string& val);
    string getNiveauDEtude() const;
    void setNiveauDEtude(const string& val);
    
};
Emprunteur::Emprunteur(){}
Emprunteur::Emprunteur(const string& log, const string& mdps,const string& n,const string& pn,const string& nde){
    login = log; motDePasse=mdps; nom=n; prenom=pn; niveauDEtude=nde;
}
Emprunteur::~Emprunteur(){}
string Emprunteur::getLogin() const{return login;}
void Emprunteur::setLogin(const string& val){login=val;}
string Emprunteur::getMotDePasse() const{return motDePasse;}
void Emprunteur::setMotDePasse(const string& val){motDePasse=val;}
string Emprunteur::getNom() const{return nom;}
void Emprunteur::setNom(const string& val){nom=val;}
string Emprunteur::getPrenom() const{return prenom;}
void Emprunteur::setPrenom(const string& val){prenom=val;}
string Emprunteur::getNiveauDEtude() const{return niveauDEtude;}
void Emprunteur::setNiveauDEtude(const string& val){niveauDEtude=val;}



// ################################################## GESTIONNAIRE ##################################################
class Gestionnaire{
    string login;
    string motDePasse;
    string nom;
    string prenom;
    string horairesDeTravail;

    public:
    Gestionnaire();
    Gestionnaire(const string& log, const string& mdps, const string& n, const string& pr, const string& hdt);
    ~Gestionnaire();

    string getLogin() const;
    void setLogin(const string& val);
    string getMotDePasse() const;
    void setMotDePasse(const string& val);
    string getNom() const;
    void setNom(const string& val);
    string getPrenom() const;
    void setPrenom(const string& val);
    string getHorairesDeTravail() const;
    void setHorairesDeTravail(const string& val);

};
Gestionnaire::Gestionnaire(){}
Gestionnaire::Gestionnaire(const string& log, const string& mdps, const string& n, const string& pr, const string& hdt){
    login=log; motDePasse=mdps; nom=n; prenom=pr; horairesDeTravail=hdt;
}
Gestionnaire::~Gestionnaire(){}
Gestionnaire::~Gestionnaire(){}
string Gestionnaire::getLogin() const{return login;}
void Gestionnaire::setLogin(const string& val){login=val;}
string Gestionnaire::getMotDePasse() const{return motDePasse;}
void Gestionnaire::setMotDePasse(const string& val){motDePasse=val;}
string Gestionnaire::getNom() const{return nom;}
void Gestionnaire::setNom(const string& val){nom=val;}
string Gestionnaire::getPrenom() const{return prenom;}
void Gestionnaire::setPrenom(const string& val){prenom=val;}
string Gestionnaire::getHorairesDeTravail() const{return horairesDeTravail;}
void Gestionnaire::setHorairesDeTravail(const string& val){horairesDeTravail=val;}



// ################################################## EMPRUNT ##################################################
class Emprunt{
    Emprunteur emprunteur;
    Exemplaire exemplaire;
    Gestionnaire gestionnaire;
    public :
    Emprunt(const Emprunteur& empr,const Exemplaire& exem, const Gestionnaire& gest);
    ~Emprunt();
    Emprunteur getEmprunteur() const;
    void setEmprunteur(const Emprunteur& val);
    Exemplaire getExemplaire() const;
    void setExemplaire(const Exemplaire& val);
    Gestionnaire getGestionnaire() const;
    void setGestionnaire(const Gestionnaire& val);

    void emprunter(const Emprunteur& empr,const Exemplaire& exem, const Gestionnaire& gest);

    friend ostream& operator<<(ostream& out,const Emprunt& emprunt);
};
Emprunt::Emprunt(const Emprunteur& empr,const Exemplaire& exem, const Gestionnaire& gest){
    emprunteur=empr; exemplaire=exem; gestionnaire=gest;
}
Emprunt::~Emprunt(){}
Emprunteur Emprunt::getEmprunteur() const{return emprunteur;}
void Emprunt::setEmprunteur(const Emprunteur& val){emprunteur=val;}
Exemplaire Emprunt::getExemplaire() const{return exemplaire;}
void Emprunt::setExemplaire(const Exemplaire& val){exemplaire=val;}
Gestionnaire Emprunt::getGestionnaire() const{return gestionnaire;}
void Emprunt::setGestionnaire(const Gestionnaire& val){gestionnaire=val;}
void Emprunt::emprunter(const Emprunteur& empr,const Exemplaire& exem, const Gestionnaire& gest){
    emprunteur=empr; exemplaire=exem; gestionnaire=gest;
}
ostream& operator<<(ostream& out,const Emprunt& emprunt){
    out <<"Nom de l'emprunteur : "<<emprunt.getEmprunteur().getNom()<<endl
        <<"Numero de l'exemplaire : "<<emprunt.getExemplaire().getIdentifiant()<<endl;
    return out;
}

// ################################################## BIBLIOTHEQUE ##################################################
class Bibliotheque{
    vector<Ouvrage> ouvrages;
    vector<Emprunt> emprunts; 
    public :
    Bibliotheque();
    Bibliotheque(const vector<Emprunt>& emp);
    ~Bibliotheque();
    vector<Ouvrage> getOuvrages() const;
    void setOuvrages(const vector<Ouvrage>& val);
    vector<Emprunt> getEmprunts() const;
    void setEmprunts(const vector<Emprunt>& val);

    void AjouterOuvrage(const Ouvrage& val);
    bool Reserver(const Emprunteur& emprunteur,const Gestionnaire& gestionnaire, const Ouvrage& ouvrage);
    void Afficher() const;
};
Bibliotheque::Bibliotheque(){}
Bibliotheque::Bibliotheque(const vector<Emprunt>& emp){
    emprunts=emp;
}
Bibliotheque::~Bibliotheque(){}
vector<Ouvrage> Bibliotheque::getOuvrages() const{return ouvrages;}
void Bibliotheque::setOuvrages(const vector<Ouvrage>& val){ouvrages=val;}
vector<Emprunt> Bibliotheque::getEmprunts() const{return emprunts;}
void Bibliotheque::setEmprunts(const vector<Emprunt>& val){emprunts=val;}

void Bibliotheque::AjouterOuvrage(const Ouvrage& val){ouvrages.push_back(val);}

bool Bibliotheque::Reserver(const Emprunteur& emprunteur,const Gestionnaire& gestionnaire, const Ouvrage& ouvrage){
    bool verifEmprunt=false;
    for(auto& emp : emprunts) 
        if(emp.getEmprunteur().getLogin()==emprunteur.getLogin() && emp.getEmprunteur().getMotDePasse()==emprunteur.getMotDePasse())
            if(emp.getGestionnaire().getLogin()==gestionnaire.getLogin() && emp.getGestionnaire().getMotDePasse()==gestionnaire.getMotDePasse())
                verifEmprunt=true;
    if(! (verifEmprunt)) return false;

    for(auto& ouv : ouvrages)
        if(ouv.getISBN()==ouvrage.getISBN()) 
            for(auto& exem : ouv.getExemplaires()) 
                if(exem.getReservation==false){
                    exem.setReservation(true);
                    emprunts.push_back(Emprunt(emprunteur,exem,gestionnaire));
                }
    

    return true;
}
void Bibliotheque::Afficher() const{
    for(auto& emprunt:emprunts){ 
        cout    <<"----- EMPRUNT -----"<<endl
                <<"id de l'exemplaire : "<<emprunt.getExemplaire().getIdentifiant()<<endl;
        for(auto& ouvrage : ouvrages) for(auto& exemp : ouvrage.getExemplaires()) if(exemp.getIdentifiant()==emprunt.getExemplaire().getIdentifiant())
            cout<<ouvrage.auteurOuImpact()<<endl;
        cout<<"Nom emprunteur : "<<emprunt.getEmprunteur().getNom()<<endl;
        cout<<"Prenom emprunteur : "<<emprunt.getEmprunteur().getPrenom()<<endl;
        cout<<"Nom gestionnaire : "<<emprunt.getGestionnaire().getNom()<<endl;
        cout<<"Prenom gestionnaire : "<<emprunt.getGestionnaire().getNom()<<endl;
    }
}
