#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
class max_si_poz{
    private:
        int maxim, pozitie;
    public:
    max_si_poz(const max_si_poz& MAX){
        this->maxim=MAX.maxim;
        this->pozitie=MAX.pozitie;
    }
    max_si_poz(int maxim, int pozitie){
        this->maxim=maxim;
        this->pozitie=pozitie;
    }
    void afisare(){
        cout<<"Maximul din vector este: "<<this->maxim<<'\n';
        cout<<"El se afla pe pozitia: "<<this->pozitie;
    }
};
class Vector{
    private:
        int numar_elem;
        int *elemente;
    public:
    //constructor fara parametrii
        Vector(){
            this->numar_elem = 0;
            this->elemente = NULL;
        }
    //constructor cu parametrii
        Vector(int valoare,int numar_elem){
            this->numar_elem=numar_elem;
            this->elemente = new int[numar_elem];
            for(int i=0;i<numar_elem;i++){
                this->elemente[i]=valoare;
            }
        }
    //destructor
        ~Vector(){
            if(this->elemente != NULL){
                delete[] this->elemente;
            }
        }
    //constructor de copiere
        Vector(const Vector& vec){
            this->numar_elem=vec.numar_elem;
            this->elemente = new int[this->numar_elem];
            for(int i=0;i<numar_elem;i++){
                this->elemente[i]=vec.elemente[i];
            }
        }
    //supraincarcare >>
    friend istream& operator>>(istream& in, Vector& vec);
    //supraincarcare <<
    friend ostream& operator<<(ostream& out, const Vector& vec);
    //operator =
    Vector& operator=(const Vector& vec){
        if(this != &vec){
            if(this->elemente != NULL){
                delete[] this->elemente;
            }
            this->numar_elem=vec.numar_elem;
            this->elemente = new int[this->numar_elem];
            for(int i=0;i<numar_elem;i++){
                this->elemente[i]=vec.elemente[i];
            }
        }
        return *this;
    }
    //getNrElemente
    int get_NrElemente(){
        return this->numar_elem;
    }
    //getElemente
    int* get_Elemente(){
        return this->elemente;
    }
    //setNrElemente
    void set_NrElemente(int numar_elem){
        this->numar_elem=numar_elem;
    }
    //setElemente
    void set_Elemente(int* elemente, int numar_elem){
        this->numar_elem=numar_elem;
        if(this->elemente != NULL){
            delete[] elemente;
        }
        this->elemente = new int[numar_elem];
        for(int i=0;i<numar_elem;i++){
            this->elemente[i]=elemente[i];
        }
    }
    //reactualizare nr de componente
    void reactualizare(int valoare, int numar_elem){
        this->numar_elem=numar_elem;
        if(this->elemente!=NULL){
            delete[] this->elemente;
        }
        this->elemente = new int[numar_elem];
        for(int i=0;i<numar_elem;i++){
            this->elemente[i]=valoare;
        }
    }
    //suma tuturor elem vectorului
    int suma(){
        int S=0;
        for(int i=0;i<this->numar_elem;i++){
            S=S+this->elemente[i];
        }
        return S;
    }
    //maxim si pozitia lui din vector
    max_si_poz maxim(){
        int Max=this->elemente[0];
        int poz=0;
        for(int i=1;i<this->numar_elem;i++){
            if(this->elemente[i]>Max){
                Max=this->elemente[i];
                poz=i;
            }
        }
        max_si_poz rez(Max, poz);
        return rez;
    }
    //sortare crescatoare
    void sortare(){
        sort(elemente, elemente+this->numar_elem);
    }
};
istream& operator>>(istream& in, Vector& vec){
    cout<<"Numar de elemente: ";
    in>>vec.numar_elem;
    if(vec.elemente!=NULL){
        delete[] vec.elemente;
    }
    cout<<"Elementele vectorului: ";
    vec.elemente=new int[vec.numar_elem];
    for(int i=0;i<vec.numar_elem;i++){
        in>>vec.elemente[i];
    }
    return in;
}
ostream& operator<<(ostream& out, const Vector& vec){
    out<<"Numar de elemente: "<<vec.numar_elem<<'\n';
    out<<"Elementele vectorului sunt:"<<'\n';
    for(int i=0;i<vec.numar_elem;i++){
        out<<vec.elemente[i]<<' ';
    }
    out<<'\n';
    return out;
}
int main ()
{
    bool OK=1;
    int N;
    cout<<"SPUNE CATE OBIECTE VREI!!"<<'\n';
    cin>>N;
    cout<<"INTRODU CEI N VECTORI!!!"<<'\n';
    Vector* v[N];
    int I=0;
    while(I<N){
        cout<<"Vectorul cu indicele "<<I<<":"<<'\n';
        v[I] = new Vector;
        cin>>*v[I];
        cout<<'\n';
        cout<<"Afisarea vectorului initial cu indicele "<<I<<":"<<'\n';
        cout<<*v[I]<<'\n';
        I++;
    }
    while(OK==1){
        cout<<'\n';
        cout<<"INSTRUCTIUNI:"<<'\n'<<'\n';
        cout<<"Pentru a opri programul apasa 0"<<'\n';
        cout<<"Pentru a initializa un vector cu un numar dat pe toate componentele apasa 1"<<'\n';
        cout<<"Pentru a afla suma tuturor elementelor unui vector apasa 2"<<'\n';
        cout<<"Pentru a afla maximul si pozitia lui intr-un vector apasa 3"<<'\n';
        cout<<"Pentru a sorta un vector apasa 4"<<'\n';
        cout<<"Pentru a reactualiza un vector cu un numar dat pe toate componentele apasa 5"<<'\n';
        cout<<"Pentru a copia datele unui vector in alt vector cu un constructor de copiere apasa 6"<<'\n';
        cout<<"Pentru a copia datele unui vector in alt vector cu operatorul = apasa 7"<<'\n';
        cout<<"Pentru a modifica un vector apasa 8"<<'\n';
        int TO_DO;
        cin>>TO_DO;
        switch(TO_DO){
        case 0:{
            OK=0;
        }
        case 1:{
            int numar_elemente, valoare_elemente,indice;
            cout<<"Indrodu numarul de elemente"<<'\n';
            cin>>numar_elemente;
            cout<<"Introdu valoarea elementelor"<<'\n';
            cin>>valoare_elemente;
            cout<<"Introdu indicele vectorului pe care vrei sa il modifici"<<'\n';
            cin>>indice;
            v[indice] = new Vector(valoare_elemente, numar_elemente);
            cout<<"Vectorul cu indicele "<<indice<<" initializat cu "<<numar_elemente<<" componente si toate au valoarea "<<valoare_elemente<<" :"<<'\n';
            cout<<*v[indice];
            break;
        }
        case 2:{
            int indice;
            cout<<"Introdu indicele vectorului pentru care vrei suma elementelor"<<'\n';
            cin>>indice;
            int S=v[indice]->suma();
            cout<<S<<'\n';
            break;
        }
        case 3:{
            int indice;
            cout<<"Introdu indicele vectorului pentru care vrei maximul"<<'\n';
            cin>>indice;
            max_si_poz rezultat(v[2]->maxim());
            rezultat.afisare();
            cout<<'\n';
            break;
        }
        case 4:{
            int indice;
            cout<<"Introdu indicele vectorului pe care vrei sa il sortezi"<<'\n';
            cin>>indice;
            v[indice]->sortare();
            cout<<"Vectorul cu indicele "<<indice<<" sortat:"<<'\n';
            cout<<*v[indice];
            break;
        }
        case 5:{
            int indice, numar_elemente, valoare_elemente;
            cout<<"Indrodu numarul de elemente"<<'\n';
            cin>>numar_elemente;
            cout<<"Introdu valoarea elementelor"<<'\n';
            cin>>valoare_elemente;
            cout<<"Introdu indicele vectorului pe care vrei sa il modifici"<<'\n';
            cin>>indice;
            v[indice]->reactualizare(valoare_elemente,numar_elemente);
            cout<<"Vectorul cu indicele "<<indice<<" initializat cu "<<numar_elemente<<" componente si toate au valoarea "<<valoare_elemente<<" :"<<'\n';
            cout<<*v[indice];
            break;
        }
        case 6:{
            int indice1, indice2;
            cout<<"Introdu indicele vectorului pe care vrei sa il copiezi"<<'\n';
            cin>>indice1;
            cout<<"Introdu indicele vectorului in care vrei sa copiezi primul vector"<<'\n';
            cin>>indice2;
            v[indice2] = new Vector(*v[indice1]);
            cout<<"Vectorul cu indicele "<<indice2<<" dupa ce a fost modificat:"<<'\n';
            cout<<*v[indice2];
            break;
        }
        case 7:{
            int indice1, indice2;
            cout<<"Introdu indicele vectorului pe care vrei sa il copiezi"<<'\n';
            cin>>indice1;
            cout<<"Introdu indicele vectorului in care vrei sa copiezi primul vector"<<'\n';
            cin>>indice2;
            *v[indice2]=*v[indice1];
            cout<<"Vectorul cu indicele "<<indice2<<" dupa ce a fost modificat:"<<'\n';
            cout<<*v[indice2];
            break;
        }
        case 8:{
            int indice,K;
            cout<<"Introdu indicele vectorului pe care vrei sa il modifici"<<'\n';
            cin>>indice;
            cout<<"Introdu cate elemente vrei sa aiba vectorul"<<'\n';
            cin>>K;
            int ELEMENTE[K];
            cout<<"Introdu cele "<<K<<" elemente ale vectorului"<<'\n';
            for(int i=0;i<K;i++){
                cin>>ELEMENTE[i];
            }
            cout<<*v[indice];
            v[indice]->set_Elemente(ELEMENTE, K);
            cout<<"Vectorul modificat:"<<'\n';
            cout<<*v[indice];
            break;
        }
        default:{
            cout<<"NU ESTE O OPTIUNE VALIDA"<<'\n';
            break;
        }
        }
    }
    return 0;
}
