#include <iostream>
using namespace std;
class data_angajare{
    private:
        int zi, luna, an;
    public:
        data_angajare(){
            this->zi=0;
            this->luna=0;
            this->an=0;
        }
        data_angajare(int zi, int luna, int an){
            this->zi=zi;
            this->luna=luna;
            this->an=an;
        }
        data_angajare(const data_angajare &data){
            this->zi=data.zi;
            this->luna=data.luna;
            this->an=data.an;
        }
        ~data_angajare(){
            this->zi=0;
            this->luna=0;
            this->an=0;
        }
        data_angajare& operator=(const data_angajare& data){
            if(this != &data){
                this->zi=data.zi;
                this->luna=data.luna;
                this->an=data.an;
            }
            return *this;
        }
        int get_zi(){
            return this->zi;
        }
        int get_luna(){
            return this->luna;
        }
        int get_an(){
            return this->an;
        }
        void set_zi(int zi){
            this->zi=zi;
        }
        void set_luna(int luna){
            this->luna=luna;
        }
        void set_an(int an){
            this->an=an;
        }
        //supraincarcare >>
        friend istream& operator>>(istream& in, data_angajare& data);
        //supraincarcare <<
        friend ostream& operator<<(ostream& out, const data_angajare& data);
};
istream& operator>>(istream& in, data_angajare& data){
    cout<<"Dati ziua: ";
    in>>data.zi;
    cout<<"Dati luna: ";
    in>>data.luna;
    cout<<"Dati anul: ";
    in>>data.an;
    return in;
}
ostream& operator<<(ostream& out, const data_angajare& data){
    out<<"Data de angajare este:"<<'\n';
    out<<data.zi<<"."<<data.luna<<"."<<data.an;
    out<<'\n';
    return out;
}

class angajat{
    private:
        data_angajare hire_date;
        string nume;
        int salariu;
        int id_angajat;
        int id_manager;
    public:
        angajat(){
            data_angajare data_basic;
            this->hire_date=data_basic;
            this->nume="";
            this->salariu=0;
            this->id_angajat=0;
            this->id_manager=0;
        }
        angajat(data_angajare hire_date, string nume, int salariu, int id_angajat, int id_manager){
            this->hire_date=hire_date;
            this->nume=nume;
            this->salariu=salariu;
            this->id_angajat=id_angajat;
            this->id_manager=id_manager;
        }
        angajat(const angajat &angj){
            this->hire_date=angj.hire_date;
            this->nume=angj.nume;
            this->salariu=angj.salariu;
            this->id_angajat=angj.id_angajat;
            this->id_manager=angj.id_manager;
        }
        ~angajat(){
            data_angajare data_basic;
            this->hire_date=data_basic;
            this->nume="";
            this->salariu=0;
            this->id_angajat=0;
            this->id_manager=0;
        }
        angajat& operator=(const angajat& angj){
            if(this != &angj){
                this->hire_date=angj.hire_date;
                this->nume=angj.nume;
                this->salariu=angj.salariu;
                this->id_angajat=angj.id_angajat;
                this->id_manager=angj.id_manager;
            }
            return *this;
        }
        data_angajare get_data_angajare(){
            return this->hire_date;
        }
        string get_nume(){
            return this->nume;
        }
        int get_salariu(){
            return this->salariu;
        }
        int get_id_angajat(){
            return this->id_angajat;
        }
        int get_id_manager(){
            return this->id_manager;
        }
        void set_data_angajare(data_angajare hire_date){
            this->hire_date=hire_date;
        }
        void set_nume(string nume){
            this->nume=nume;
        }
        void set_salariu(int salariu){
            this->salariu=salariu;
        }
        void set_id_angajat(int id_angajat){
            this->id_angajat=id_angajat;
        }
        void set_id_manager(int id_manager){
            this->id_manager=id_manager;
        }
        //supraincarcare >>
        friend istream& operator>>(istream& in, angajat& angj);
        //supraincarcare <<
        friend ostream& operator<<(ostream& out, const angajat& angj);
};
istream& operator>>(istream& in, angajat& angj){
    cout<<"Dati data de angajare: ";
    in>>angj.hire_date;
    cout<<"Dati numele angajatului: ";
    in>>angj.nume;
    cout<<"Dati salariul: ";
    in>>angj.salariu;
    cout<<"Dati id-ul angajatului";
    in>>angj.id_angajat;
    cout<<"Dati id-ul managerului, daca nu are manager dati 0";
    in>>angj.id_manager;
    return in;
}
ostream& operator<<(ostream& out, const angajat& angj){
    out<<"Salariatul are numele:"<<'\n';
    out<<angj.nume<<'\n';
    out<<"A fost angajat in data de:"<<'\n';
    out<<angj.hire_date<<'\n';
    out<<"Are salariul:"<<'\n';
    out<<angj.salariu<<'\n';
    out<<"Are id-ul:"<<'\n';
    out<<angj.id_angajat;
    out<<"Managerul lui are id-ul:"<<'\n';
    out<<angj.id_manager;
    return out;
}
class departament{
    protected:
        string nume_departament;
        int numar_angajati;
        angajat *angajati;
        bool scutire;
    public:
        departament(){
            this->nume_departament="";
            this->numar_angajati=0;
            this->angajati=NULL;
            this->scutire=0;
        }
        departament(string nume_departament,int numar_angajati, bool scutire){
            this->nume_departament=nume_departament;
            this->numar_angajati=numar_angajati;
            this->angajati = new angajat[numar_angajati];
            this->scutire=scutire;
            angajat angajat_basic;
            for(int i=0;i<numar_angajati;i++){
                this->angajati[i]=angajat_basic;
            }
        }
        departament(const departament& dep){
            this->nume_departament=dep.nume_departament;
            this->numar_angajati=dep.numar_angajati;
            this->scutire=dep.scutire;
            for(int i=0;i<this->numar_angajati;i++){
                this->angajati[i]=dep.angajati[i];
            }
        }
        ~departament(){
            this->nume_departament="";
            this->numar_angajati=0;
            this->scutire=0;
            if(this->angajati!=NULL){
                delete[] this->angajati;
            }
        }
        departament& operator=(const departament& dep){
            if(this != &dep){
                if(this->angajati!=NULL){
                    delete[] this->angajati;
                }
                this->nume_departament=dep.nume_departament;
                this->numar_angajati=dep.numar_angajati;
                this->scutire=dep.scutire;
                this->angajati = new angajat[this->numar_angajati];
                for(int i=0;i<this->numar_angajati;i++){
                    this->angajati[i]=dep.angajati[i];
                }
            }
            return *this;
        }
        string get_nume_departament(){
            return this->nume_departament;
        }
        int get_numar_angajati(){
            return this->numar_angajati;
        }
        bool get_scutire(){
            return this->scutire;
        }
        angajat* get_angajati(){
            return this->angajati;
        }
        void set_nume_departament(string nume_departament){
            this->nume_departament=nume_departament;
        }
        void set_numar_angajati(int numar_angajati){
            this->numar_angajati=numar_angajati;
        }
        void set_scutire(bool scutire){
            this->scutire=scutire;
        }
        void set_angajati(int* angajati, int numar_angajati){
            this->numar_angajati=numar_angajati;
            if(this->angajati != NULL){
                delete[] angajati;
            }
            this->angajati=new angajat[numar_angajati];
            for(int i=0;i<this->numar_angajati;i++){
                angajat angajat_basic;
                cin>>angajat_basic;
                this->angajati[i]=angajat_basic;
            }
        }
        void adaugare_angajat(){
            angajat *temporar;
            temporar = new angajat[this->numar_angajati];
            for(int i=0;i<this->numar_angajati;i++){
                temporar[i]=angajati[i];
            }
            this->numar_angajati++;
            this->angajati=new angajat[this->numar_angajati];
            for(int i=0;i<this->numar_angajati;i++){
                angajati[i]=temporar[i];
            }
            cin>>angajati[this->numar_angajati-1];
        }
        void stergere_angajat(string nume_angajat){
            for(int i=0;i<this->numar_angajati;i++){
                if(nume_angajat==this->angajati[i].get_nume()){
                    for(int j=i;j<this->numar_angajati-1;j++){
                        this->angajati[j]=this->angajati[j+1];
                    }
                    break;
                }
            }
            this->numar_angajati--;
        }
        virtual ostream& AfisareVirtuala(ostream& out)const{
            out<<"Departamentul se numeste: "<<'\n'<<this->nume_departament<<'\n';
            out<<"Numarul de angajati al departamentului este: "<<'\n'<<this->numar_angajati<<'\n';
            out<<"Departamentul este scutit de impozit?"<<'\n';
            if(this->scutire==0){
                out<<"Nu"<<'\n';
            }
            else
            out<<"Da"<<'\n';
            out<<"Angajatii departamentului sunt:"<<'\n';
            for(int i=0;i<this->numar_angajati;i++){
                out<<this->angajati[i]<<" ";
            }
            out<<'\n';
            return out;
        }
        virtual istream& CitireVirtuala(istream& in){
            cout<<"Dati numele departamentului: "<<'\n';
            in>>this->nume_departament;
            cout<<"Dati numarul de angajati al departamentului: "<<'\n';
            in>>this->numar_angajati;
            cout<<"Este scutit de impozit? (1 pentru Da, 0 pentru Nu)"<<'\n';
            in>>this->scutire;
            cout<<"Dati angajatii departamentului: ";
            this->angajati=new angajat[this->numar_angajati];
            for(int i=0;i<this->numar_angajati;i++){
                in>>this->angajati[i];
            }
            return in;
        }
        friend istream& operator>>(istream& in, departament& dep);
        friend ostream& operator<<(ostream& out, const departament& dep);
        friend departament operator+(const departament &dep1,const departament &dep2);
};
istream& operator>>(istream& in, departament& dep){
    return dep.CitireVirtuala(in);
}
ostream& operator<<(ostream& out, const departament& dep){
    return dep.AfisareVirtuala(out);
}
departament operator+(const departament &dep1,const departament &dep2){
    departament dep;
    dep.nume_departament=dep1.nume_departament;
    dep.numar_angajati=dep1.numar_angajati+dep2.numar_angajati;
    dep.angajati=new angajat[dep.numar_angajati];
    for(int i=0;i<dep1.numar_angajati;i++){
        dep.angajati[i]=dep1.angajati[i];
    }
    for(int i=dep1.numar_angajati;i<dep.numar_angajati;i++){
        dep.angajati[i]=dep2.angajati[i-dep1.numar_angajati];
    }
    return dep;
}
class companie{
    private:
        string nume_companie;
        int numar_departamente;
        departament *departamente;
    public:
        companie(){
            this->nume_companie="";
            this->numar_departamente=0;
            this->departamente=NULL;
        }
        companie(string nume_companie, int numar_departamente){
            departament departament_basic;
            this->nume_companie=nume_companie;
            this->numar_departamente=numar_departamente;
            this->departamente = new departament[numar_departamente];
            for(int i=0;i<numar_departamente;i++){
                this->departamente[i]=departament_basic;
            }
        }
        companie(const companie& comp){
            this->nume_companie=comp.nume_companie;
            this->numar_departamente=comp.numar_departamente;
            for(int i=0;i<numar_departamente;i++){
                this->departamente[i]=comp.departamente[i];
            }
        }
        ~companie(){
            this->nume_companie="";
            this->numar_departamente=0;
            if(this->departamente!=NULL){
                delete[] this->departamente;
            }
        }
        companie& operator=(const companie& comp){
            if(this != &comp){
                if(this->departamente!=NULL){
                    delete[] this->departamente;
                }
                this->nume_companie=comp.nume_companie;
                this->numar_departamente=comp.numar_departamente;
                this->departamente = new departament[this->numar_departamente];
                for(int i=0;i<numar_departamente;i++){
                    this->departamente[i]=comp.departamente[i];
                }
            }
            return *this;
        }
        string get_nume_companie(){
            return this->nume_companie;
        }
        void adaugare_departament(){
            departament *temporar;
            temporar = new departament[this->numar_departamente];
            for(int i=0;i<this->numar_departamente;i++){
                temporar[i]=departamente[i];
            }
            this->numar_departamente++;
            this->departamente=new departament[this->numar_departamente];
            for(int i=0;i<this->numar_departamente;i++){
                departamente[i]=temporar[i];
            }
            cin>>departamente[this->numar_departamente-1];
        }
        void stergere_departament(string nume_departament){
            for(int i=0;i<this->numar_departamente;i++){
                if(nume_departament==this->departamente[i].get_nume_departament()){
                    for(int j=i;j<this->numar_departamente-1;j++){
                        this->departamente[j]=this->departamente[j+1];
                    }
                    break;
                }
            }
            this->numar_departamente--;
        }
        virtual ostream& AfisareVirtuala(ostream& out)const{
            out<<"Compania se numeste: "<<'\n'<<this->nume_companie<<'\n';
            out<<"Numarul de departamente al companiei este: "<<'\n'<<this->numar_departamente<<'\n';
            out<<"Departamentele companiei sunt:"<<'\n';
            for(int i=0;i<this->numar_departamente;i++){
                out<<this->departamente[i]<<" ";
            }
            out<<'\n';
            return out;
        }
        virtual istream& CitireVirtuala(istream& in){
            cout<<"Dati numele companiei: "<<'\n';
            in>>this->nume_companie;
            cout<<"Dati numarul de departamente al companiei: "<<'\n';
            in>>this->numar_departamente;
            cout<<"Dati departamentele companiei: ";
            this->departamente=new departament[this->numar_departamente];
            for(int i=0;i<this->numar_departamente;i++){
                in>>this->departamente[i];
            }
            return in;
        }
        friend istream& operator>>(istream& in, companie& comp);
        friend ostream& operator<<(ostream& out, const companie& comp);
        friend companie operator+(const companie &comp1,const companie &comp2);
};
istream& operator>>(istream& in, companie& comp){
    return comp.CitireVirtuala(in);
}
ostream& operator<<(ostream& out, const companie& comp){
    return comp.AfisareVirtuala(out);
}
companie operator+(const companie &comp1,const companie &comp2){
    companie comp;
    comp.nume_companie=comp1.nume_companie+"-"+comp2.nume_companie;
    comp.numar_departamente=comp1.numar_departamente+comp2.numar_departamente;
    comp.departamente=new departament[comp.numar_departamente];
    for(int i=0;i<comp1.numar_departamente;i++){
        comp.departamente[i]=comp1.departamente[i];
    }
    int I=0;
    int poz=comp1.numar_departamente;
    while(I<comp2.numar_departamente){
        for(int j=0;j<comp1.numar_departamente;j++){
            if(comp2.departamente[I].get_nume_departament()==comp1.departamente[j].get_nume_departament()){
                comp.departamente[j]=comp.departamente[j]+comp2.departamente[I];
                break;
            }
            else{
            comp.departamente[poz]=comp2.departamente[I];
            poz++;
            }
        }
        I++;
    }
    comp.numar_departamente=poz;
    return comp;
}
class HRManager{
    private:
        int numar_companii;
        companie* companii;
    public:
        HRManager(){
            this->numar_companii=0;
            this->companii=NULL;
        }
        HRManager(int numar_companii){
            companie companie_basic;
            this->numar_companii=numar_companii;
            this->companii = new companie[numar_companii];
            for(int i=0;i<numar_companii;i++){
                this->companii[i]=companie_basic;
            }
        }
        HRManager(const HRManager& manag){
            this->numar_companii=manag.numar_companii;
            for(int i=0;i<numar_companii;i++){
                this->companii[i]=manag.companii[i];
            }
        }
        ~HRManager(){
            this->numar_companii=0;
            if(this->companii!=NULL){
                delete[] this->companii;
            }
        }
        void adaugare_companie(){
            companie *temporar;
            temporar = new companie[this->numar_companii];
            for(int i=0;i<this->numar_companii;i++){
                temporar[i]=companii[i];
            }
            this->numar_companii++;
            this->companii=new companie[this->numar_companii];
            for(int i=0;i<this->numar_companii;i++){
                companii[i]=temporar[i];
            }
            cin>>companii[this->numar_companii-1];
        }
        void stergere_companie(string nume_companie){
            for(int i=0;i<this->numar_companii;i++){
                if(nume_companie==this->companii[i].get_nume_companie()){
                    for(int j=i;j<this->numar_companii-1;j++){
                        this->companii[j]=this->companii[j+1];
                    }
                    break;
                }
            }
            this->numar_companii--;
        }
        void contopire_companii(string nume_companie1, string nume_companie2){
            companie comp1,comp2;
            for(int i=0;i<numar_companii;i++){
                if(this->companii[i].get_nume_companie()==nume_companie1){
                    comp1=companii[i];
                }
                else
                if(this->companii[i].get_nume_companie()==nume_companie2){
                    comp2=companii[i];
                }
            }
            stergere_companie(nume_companie1);
            stergere_companie(nume_companie2);
            companie *temporar;
            temporar = new companie[this->numar_companii];
            for(int i=0;i<this->numar_companii;i++){
                temporar[i]=companii[i];
            }
            this->numar_companii++;
            this->companii=new companie[this->numar_companii];
            for(int i=0;i<this->numar_companii;i++){
                companii[i]=temporar[i];
            }
            companii[this->numar_companii-1]=comp1+comp2;
        }
        virtual ostream& AfisareVirtuala(ostream& out)const{
            out<<"Numarul de companii este: "<<'\n'<<this->numar_companii<<'\n';
            out<<"Companiile sunt:"<<'\n';
            for(int i=0;i<this->numar_companii;i++){
                out<<this->companii[i]<<" ";
            }
            out<<'\n';
            return out;
        }
        virtual istream& CitireVirtuala(istream& in){
            cout<<"Dati numarul de companii: "<<'\n';
            in>>this->numar_companii;
            cout<<"Dati companiile: ";
            this->companii=new companie[this->numar_companii];
            for(int i=0;i<this->numar_companii;i++){
                in>>this->companii[i];
            }
            return in;
        }
        friend istream& operator>>(istream& in, HRManager& manag);
        friend ostream& operator<<(ostream& out, const HRManager& manag);
};
istream& operator>>(istream& in, HRManager& manag){
    return manag.CitireVirtuala(in);
}
ostream& operator<<(ostream& out, const HRManager& manag){
    return manag.AfisareVirtuala(out);
}
int main ()
{
    return 0;
}
