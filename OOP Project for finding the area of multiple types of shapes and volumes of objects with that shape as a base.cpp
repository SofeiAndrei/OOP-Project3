#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
class Punct{
    private:
    float x,y;
    public:
    //constructor fara parametrii
    Punct(){
        this->x=0;
        this->y=0;
    }
    //constructor cu parametrii
    Punct(float x, float y){
        this->x=x;
        this->y=y;
    }
    //destructor
    ~Punct(){
        this->x=0;
        this->y=0;
    }
    float get_x(){
        return this->x;
    }
    float get_y(){
        return this->y;
    }
    //constructor de copiere
    Punct(const Punct& pct){
        this->x=pct.x;
        this->y=pct.y;
    }
    //operator =
    Punct& operator=(const Punct& pct){
        if(this != &pct){
            this->x=pct.x;
            this->y=pct.y;
        }
        return *this;
    }
    friend istream& operator>>(istream& in, Punct& pct);
    friend ostream& operator<<(ostream& out, const Punct& pct);
};
istream& operator>>(istream& in, Punct& pct){
    cout<<"X: ";
    in>>pct.x;
    cout<<"Y: ";
    in>>pct.y;
    return in;
}
ostream& operator<<(ostream& out, const Punct& pct){
    out<<"X este: "<<pct.x<<'\n';
    out<<"Y este: "<<pct.y<<'\n';
    return out;
}
class Patrat{
    protected:
        bool valid;
        Punct stanga_jos;
        float latura;
        static int n;
    public:
        Patrat(){
            n++;
            Punct pct;
            this->stanga_jos=pct;
            this->latura=0;
            this->valid=0;
        }
        //constructor cu parametrii
        Patrat(Punct stanga_jos, float latura){
            this->stanga_jos=stanga_jos;
            this->latura=latura;
            if(latura>0){
                this->valid=1;
            }
            else
            this->valid=0;
        }
        //destructor
        ~Patrat(){
            Punct pct;
            this->stanga_jos=pct;
            this->latura=0;
            this->valid=0;
        }
        Punct get_stanga_jos(){
            return this->stanga_jos;
        }
        float get_latura(){
            return this->latura;
        }
        //constructor de copiere
        Patrat(const Patrat& patrat){
            this->stanga_jos=patrat.stanga_jos;
            this->latura=patrat.latura;
            this->valid=patrat.valid;
        }
        //operator =
        Patrat& operator=(const Patrat& patrat){
            if(this!= &patrat){
                this->stanga_jos=patrat.stanga_jos;
                this->latura=patrat.latura;
                this->valid=patrat.valid;
            }
            return *this;
        }
        virtual bool get_valid(){
            return this->valid;
        }
        virtual ostream& AfisareVirtuala(ostream& out)const{
            out<<"Punctul din stanga jos are coordonatele: "<<'\n'<<this->stanga_jos;
            out<<"Latura are lungimea: "<<this->latura<<'\n';
            if(this->valid==1){
                out<<"Figura este valida"<<'\n';
            }
            else
            out<<"Figura nu este valida"<<'\n';
            return out;
        }

        virtual istream& CitireVirtuala(istream& in){
            cout<<"Dati Coordonatele coltului din stanga jos: "<<'\n';
            in>>this->stanga_jos;
            cout<<"Dati latura: "<<'\n';
            in>>this->latura;
            if(this->latura>0){
                this->valid=1;
            }
            else
            this->valid=0;
            return in;
        }
        friend istream& operator>>(istream& in, Patrat& patrat);
        friend ostream& operator<<(ostream& out, const Patrat& patrat);
        virtual float calculeazaArie(){
            if(valid==1){
                return latura*latura;
            }
            else
            return -1;
        }
        virtual float calculeazaVolum(){
            if(valid==1){
                float h;
                cout<<"Dati inaltimea corpului: ";
                cin>>h;
                return this->calculeazaArie()*h;
            }
            else
            return -1;
        };
        static int nr_obiecte(){
            return n;
        }
};
int Patrat::n;
istream& operator>>(istream& in, Patrat& patrat){
    return patrat.CitireVirtuala(in);
}
ostream& operator<<(ostream& out, const Patrat& patrat){
    return patrat.AfisareVirtuala(out);
}
class Dreptunghi:virtual public Patrat{
    protected:
        float latura2;
    public:
        //constructor fara parametrii
        Dreptunghi():Patrat(){
            this->latura2=0;
        }
        //constructor cu parametrii
        Dreptunghi(Punct pct, float latura, float latura2):Patrat(pct,latura){
            this->latura2=latura2;
            if(valid==1){
                if(latura2<=0){
                    valid=0;
                }
            }
        }
        //constructor de copiere
        Dreptunghi(const Dreptunghi& drept):Patrat(drept){
            this->latura2=drept.latura2;
        }
        //destructor
        ~Dreptunghi(){
            this->latura2=0;
        }
        //operator =
        Dreptunghi& operator=(const Dreptunghi& drept){
            if(this != &drept){
                Patrat::operator=(drept);
                this->latura2=drept.latura2;
            }
            return *this;
        }
        virtual bool get_valid(){
            return this->valid;
        }
        virtual ostream& AfisareVirtuala(ostream& out)const{
            Patrat::AfisareVirtuala(out);
            out<<"Latura2 are lungimea: "<<this->latura2<<'\n';
            return out;
        }
        virtual istream& CitireVirtuala(istream& in){
            Patrat::CitireVirtuala(in);
            cout<<"Dati latura 2: "<<'\n';
            in>>this->latura2;
            if(valid==1){
                if(latura2<=0){
                    valid=0;
                }
            }
            return in;
        }
        virtual float calculeazaArie(){
            if(valid==1){
                return latura*latura2;
            }
            else
            return -1;
        }
        virtual float calculeazaVolum(){
            if(valid==1){
                float h;
                cout<<"Dati inaltimea corpului: ";
                cin>>h;
                return this->calculeazaArie()*h;
            }
            else
            return -1;
        };
};
///--------------------------------------------
class Romb:virtual public Patrat{
    protected:
        Punct colt_opus;
    public:
        //constructor fara parametrii
        Romb();
        //constructor cu parametrii
        Romb(Punct pct, float latura, Punct colt):Patrat(pct,latura){
            this->colt_opus=colt;
            float x1,x2,y1,y2;
            x1=stanga_jos.get_x();
            y1=stanga_jos.get_y();
            x2=colt_opus.get_x();
            y2=colt_opus.get_y();
            if(4*latura*latura>(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) && latura>0){
                this->valid=1;
            }
            else
            this->valid=0;
        }
        virtual bool get_valid(){
            return this->valid;
        }
        //constructor de copiere
        Romb(const Romb& romb):Patrat(romb){
            this->colt_opus=romb.colt_opus;
        }
        //destructor
        ~Romb(){
            Punct pct;
            this->colt_opus=pct;
        }
        //operator =
        Romb& operator=(const Romb& romb){
            if(this != &romb){
                Patrat::operator=(romb);
                this->colt_opus=romb.colt_opus;
            }
            return *this;
        }
        virtual ostream& AfisareVirtuala(ostream& out)const{
            Patrat::AfisareVirtuala(out);
            out<<"Coltul opus are coordonatele: "<<'\n'<<this->colt_opus;
            return out;
        }
        virtual istream& CitireVirtuala(istream& in){
            Patrat::CitireVirtuala(in);
            cout<<"Dati coordonatele coltului opus: "<<'\n';
            in>>this->colt_opus;
            float x1,x2,y1,y2;
            x1=stanga_jos.get_x();
            y1=stanga_jos.get_y();
            x2=colt_opus.get_x();
            y2=colt_opus.get_y();
            if(4*latura*latura>=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) && latura>0){
                this->valid=1;
            }
            else
            this->valid=0;
            return in;
        }
        virtual float calculeazaArie(){
            if(valid==1){
                float x1,y1,x2,y2,diag1,diag2;
                x1=stanga_jos.get_x();
                y1=stanga_jos.get_y();
                x2=colt_opus.get_x();
                y2=colt_opus.get_y();
                diag1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                ///diag1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)
                diag2=2*sqrt(latura*latura-(diag1*diag1)/4);
                ///diag2=2*sqrt(latura^2-diag1^2/4)
                return diag1*diag2/2;
            }
            else
            return -1;
        }
        virtual float calculeazaVolum(){
            if(valid==1){
                float h;
                cout<<"Dati inaltimea corpului: ";
                cin>>h;
                return this->calculeazaArie()*h;
            }
            else
            return -1;
        };
};
Romb::Romb():Patrat(){
    Punct colt;
    this->colt_opus=colt;
}
class Paralelogram:public Dreptunghi,public Romb{
    public:
    //constructor fara parametrii
    Paralelogram();
    //constructor cu parametrii
    Paralelogram(Punct pct, float latura, float latura2, Punct pct2):Dreptunghi(pct, latura, latura2), Romb(pct, latura, pct2){}
    ///nu are nevoie de destructor, se apeleaza destructorii parintilor automat
    //constructor de copiere
    Paralelogram(const Paralelogram& para):Dreptunghi(para), Romb(para){}
    //operator =
    Paralelogram& operator=(const Paralelogram& para){
        if(this != &para){
            Dreptunghi::operator=(para);
            Romb::operator=(para);
        }
        return *this;
    }
    virtual bool get_valid(){
        return this->valid;
    }
    virtual ostream& AfisareVirtuala(ostream& out)const{
        Patrat::AfisareVirtuala(out);
        out<<"Latura 2 are lungimea: "<<this->latura2<<'\n';
        out<<"Coltul opus are coordonatele: "<<'\n'<<this->colt_opus<<'\n';
        return out;
    }
    virtual istream& CitireVirtuala(istream& in){
        Patrat::CitireVirtuala(in);
        cout<<"Dati latura 2: "<<'\n';
        in>>this->latura2;
        cout<<"Dati coodonatele coltului opus: "<<'\n';
        in>>this->colt_opus;
        float x1,x2,y1,y2;
        x1=stanga_jos.get_x();
        y1=stanga_jos.get_y();
        x2=colt_opus.get_x();
        y2=colt_opus.get_y();
        if(latura>0 && latura2>0 && latura*latura+latura2*latura2>=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)){
            this->valid=1;
        }
        else
        this->valid=0;
        return in;
    }
    virtual float calculeazaArie(){
        if(valid==1){
            float y1,y2;
            y1=stanga_jos.get_y();
            y2=colt_opus.get_y();
            return abs(y2-y1)*latura;
        }
        else
        return -1;
    }
    virtual float calculeazaVolum(){
        if(valid==1){
            float h;
            cout<<"Dati inaltimea corpului: ";
            cin>>h;
            return this->calculeazaArie()*h;
        }
        else
        return -1;
    }
};
Paralelogram::Paralelogram():Dreptunghi(), Romb(){}
class Trapez:public Paralelogram{
    private:
    float baza2;
    short caz;
    public:
    //constructor fara parametrii
    Trapez():Paralelogram(){
        this->baza2=0;
        this->caz=0;
    }
    //constructor cu parametrii
    Trapez(Punct pct, float latura, float latura2, Punct pct2, float baza2):Paralelogram(pct, latura, latura2, pct2){
        this->baza2=baza2;
        caz=VALIDARE();
        if(caz>0){
            valid=1;
        }
        else
        valid=0;
    }
    ~Trapez(){
        this->baza2=0;
        this->caz=0;
    }
    //constructor de copiere
    Trapez(const Trapez& trap):Paralelogram(trap){
        this->baza2=trap.baza2;
        this->caz=trap.caz;
    }
    //operator =
    Trapez& operator=(const Trapez& trap){
        if(this != &trap){
            Paralelogram::operator=(trap);
            this->baza2=trap.baza2;
            this->caz=trap.caz;
        }
        return *this;
    }
    bool get_valid(){
        return this->valid;
    }
    ostream& AfisareVirtuala(ostream& out)const{
        Paralelogram::AfisareVirtuala(out);
        out<<"Baza 2 are lungimea: "<<this->baza2<<'\n';
        return out;
    }
    istream& CitireVirtuala(istream& in){
        Paralelogram::CitireVirtuala(in);
        cout<<"Dati baza 2: "<<'\n';
        in>>this->baza2;
        caz=VALIDARE();
        if(caz>0){
            valid=1;
        }
        else
        valid=0;
        return in;
    }
    float calcul_baza1(){
        if(caz==1 || caz==4){
            return latura2;
        }
        if(caz==2 || caz==3){
            return latura;
        }
    }
    short VALIDARE(){
        float x1,x2,x3,y1,y2,y3;
        x1=stanga_jos.get_x();
        y1=stanga_jos.get_y();
        x2=colt_opus.get_x();
        y2=colt_opus.get_y();
        x3=x1+baza2;
        y3=y1;
        if((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)==latura*latura){
            return 1;
        }
        if((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)==latura2*latura2){
            return 2;
        }
        x3=x2-latura;
        y3=y2;
        if((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)==latura2*latura2){
            return 3;
        }
        x3=x2-latura2;
        y3=y2;
        if((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)==latura*latura){
            return 4;
        }
        return 0;
    }
    float calculeazaArie(){
        if(valid==1){
            float inaltime;
            inaltime=abs(stanga_jos.get_y()-colt_opus.get_y());
            float baza1;
            baza1=calcul_baza1();
            return (baza2+baza1)*inaltime/2;
        }
        else
        return -1;
    }
    float calculeazaVolum(){
        if(valid==1){
            float h;
            cout<<"Dati inaltimea corpului: ";
            cin>>h;
            return this->calculeazaArie()*h;
        }
        else
        return -1;
    }
};
int main()
{
    bool OK=1;
    while(OK==1){
        cout<<'\n';
        cout<<"INSTRUCTIUNI:"<<'\n'<<'\n';
        cout<<"Pentru a opri programul apasa 0"<<'\n';
        cout<<"Pentru a citi, memora si afisa N elemente apasa 1"<<'\n';
        cout<<"Pentru a citi si afisa o figura geometrica apasa 2"<<'\n';
        cout<<"Pentru a afisa daca o figura este valida sau nu apasa 3"<<'\n';
        cout<<"Pentru a afisa aria unei figuri apasa 4"<<'\n';
        cout<<"Pentru a afisa volumul unui corp cu baza in forma unei forme geometrice introdusa de la tastatura apasa 5"<<'\n';
        cout<<"Pentru a afisa cate figuri geometrice ai introdus pana acum apasa 6"<<'\n';
        cout<<"Pentru a evidentia conceptul de upcasting pe un obiect apasa 7"<<'\n';
        cout<<"Pentru a evidentia conceptul de downcasting pe un obiect apasa 8"<<'\n';
        short TO_DO;
        cin>>TO_DO;
        switch(TO_DO){
            case 0:{
                OK=0;
                break;
            }
            case 1:{
                int N;
                cout<<"Introduceti numarul de figuri geometrice"<<'\n';
                cin>>N;
                Patrat* Fig[N];
                for(int I=0;I<N;I++){
                    short optiune;
                    cout<<'\n'<<"Pentru a introduce un PATRAT apasa 1"<<'\n';
                    cout<<'\n'<<"Pentru a introduce un DREPTUNGHI apasa 2"<<'\n';
                    cout<<'\n'<<"Pentru a introduce un ROMB apasa 3"<<'\n';
                    cout<<'\n'<<"Pentru a introduce un PARALELOGRAM apasa 4"<<'\n';
                    cout<<'\n'<<"Pentru a introduce un TRAPEZ apasa 5"<<'\n';
                    cin>>optiune;
                    if(optiune==1){
                        Fig[I] = new Patrat;
                    }
                    else
                    if(optiune==2){
                        Fig[I] = new Dreptunghi;
                    }
                    else
                    if(optiune==3){
                        Fig[I] = new Romb;
                    }
                    else
                    if(optiune==4){
                        Fig[I] = new Paralelogram;
                    }
                    else
                    if(optiune==5){
                        Fig[I] = new Trapez;
                    }
                    else{
                        cout<<'\n'<<"RESPECTA INSTRUCTIUNILE!!!";
                        return 0;
                    }
                    cin>>*Fig[I];
                }
                cout<<'\n';
                for(int I=0;I<N;I++){
                    if(typeid(*Fig[I]) == typeid(Patrat)){
                        cout<<"Figura "<<I+1<<" este un Patrat"<<'\n';
                    }
                    if(typeid(*Fig[I]) == typeid(Dreptunghi)){
                        cout<<"Figura "<<I+1<<" este un Dreptunghi"<<'\n';
                    }
                    if(typeid(*Fig[I]) == typeid(Romb)){
                        cout<<"Figura "<<I+1<<" este un Romb"<<'\n';
                    }
                    if(typeid(*Fig[I]) == typeid(Paralelogram)){
                        cout<<"Figura "<<I+1<<" este un Paralelogram"<<'\n';
                    }
                    if(typeid(*Fig[I]) == typeid(Trapez)){
                        cout<<"Figura "<<I+1<<" este un Trapez"<<'\n';
                    }
                    cout<<*Fig[I]<<'\n';
                }
                break;
            }
            case 2:{
                cout<<'\n'<<"Pentru a introduce un PATRAT apasa 1"<<'\n';
                cout<<'\n'<<"Pentru a introduce un DREPTUNGHI apasa 2"<<'\n';
                cout<<'\n'<<"Pentru a introduce un ROMB apasa 3"<<'\n';
                cout<<'\n'<<"Pentru a introduce un PARALELOGRAM apasa 4"<<'\n';
                cout<<'\n'<<"Pentru a introduce un TRAPEZ apasa 5"<<'\n';
                short optiune;
                cin>>optiune;
                if(optiune==1){
                    Patrat Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<Figura<<'\n';
                }
                else
                if(optiune==2){
                    Dreptunghi Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<Figura<<'\n';
                }
                else
                if(optiune==3){
                    Romb Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<Figura<<'\n';
                }
                else
                if(optiune==4){
                    Paralelogram Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<Figura<<'\n';
                }
                else
                if(optiune==5){
                    Trapez Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<Figura<<'\n';
                }
                else{
                    cout<<'\n'<<"RESPECTA INSTRUCTIUNILE!!!";
                    return 0;
                }
                break;
            }
            case 3:{
                cout<<'\n'<<"Pentru a introduce un PATRAT apasa 1"<<'\n';
                cout<<'\n'<<"Pentru a introduce un DREPTUNGHI apasa 2"<<'\n';
                cout<<'\n'<<"Pentru a introduce un ROMB apasa 3"<<'\n';
                cout<<'\n'<<"Pentru a introduce un PARALELOGRAM apasa 4"<<'\n';
                cout<<'\n'<<"Pentru a introduce un TRAPEZ apasa 5"<<'\n';
                short optiune;
                cin>>optiune;
                if(optiune==1){
                    Patrat Figura;
                    cin>>Figura;
                    cout<<'\n';
                    bool valid_sau_nu = Figura.get_valid();
                    if(valid_sau_nu==1){
                        cout<<"Figura este valida"<<'\n';
                    }
                    else
                    cout<<"Figura nu este valida"<<'\n';
                }
                else
                if(optiune==2){
                    Dreptunghi Figura;
                    cin>>Figura;
                    cout<<'\n';
                    bool valid_sau_nu = Figura.get_valid();
                    if(valid_sau_nu==1){
                        cout<<"Figura este valida"<<'\n';
                    }
                    else
                    cout<<"Figura nu este valida"<<'\n';
                }
                else
                if(optiune==3){
                    Romb Figura;
                    cin>>Figura;
                    cout<<'\n';
                    bool valid_sau_nu = Figura.get_valid();
                    if(valid_sau_nu==1){
                        cout<<"Figura este valida"<<'\n';
                    }
                    else
                    cout<<"Figura nu este valida"<<'\n';
                }
                else
                if(optiune==4){
                    Paralelogram Figura;
                    cin>>Figura;
                    cout<<'\n';
                    bool valid_sau_nu = Figura.get_valid();
                    if(valid_sau_nu==1){
                        cout<<"Figura este valida"<<'\n';
                    }
                    else
                    cout<<"Figura nu este valida"<<'\n';
                }
                else
                if(optiune==5){
                    Trapez Figura;
                    cin>>Figura;
                    cout<<'\n';
                    bool valid_sau_nu = Figura.get_valid();
                    if(valid_sau_nu==1){
                        cout<<"Figura este valida"<<'\n';
                    }
                    else
                    cout<<"Figura nu este valida"<<'\n';
                }
                else{
                    cout<<'\n'<<"RESPECTA INSTRUCTIUNILE!!!";
                    return 0;
                }
                break;
            }
            case 4:{
                cout<<'\n'<<"Pentru a introduce un PATRAT apasa 1"<<'\n';
                cout<<'\n'<<"Pentru a introduce un DREPTUNGHI apasa 2"<<'\n';
                cout<<'\n'<<"Pentru a introduce un ROMB apasa 3"<<'\n';
                cout<<'\n'<<"Pentru a introduce un PARALELOGRAM apasa 4"<<'\n';
                cout<<'\n'<<"Pentru a introduce un TRAPEZ apasa 5"<<'\n';
                short optiune;
                cin>>optiune;
                if(optiune==1){
                    Patrat Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Aria este egala cu: "<<Figura.calculeazaArie()<<'\n';
                }
                else
                if(optiune==2){
                    Dreptunghi Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Aria este egala cu: "<<Figura.calculeazaArie()<<'\n';
                }
                else
                if(optiune==3){
                    Romb Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Aria este egala cu: "<<Figura.calculeazaArie()<<'\n';
                }
                else
                if(optiune==4){
                    Paralelogram Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Aria este egala cu: "<<Figura.calculeazaArie()<<'\n';
                }
                else
                if(optiune==5){
                    Trapez Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Aria este egala cu: "<<Figura.calculeazaArie()<<'\n';
                }
                else{
                    cout<<'\n'<<"RESPECTA INSTRUCTIUNILE!!!";
                    return 0;
                }
                break;
            }
            case 5:{
                cout<<'\n'<<"Pentru a introduce un PATRAT apasa 1"<<'\n';
                cout<<'\n'<<"Pentru a introduce un DREPTUNGHI apasa 2"<<'\n';
                cout<<'\n'<<"Pentru a introduce un ROMB apasa 3"<<'\n';
                cout<<'\n'<<"Pentru a introduce un PARALELOGRAM apasa 4"<<'\n';
                cout<<'\n'<<"Pentru a introduce un TRAPEZ apasa 5"<<'\n';
                short optiune;
                cin>>optiune;
                if(optiune==1){
                    Patrat Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Volumul este egal cu: "<<Figura.calculeazaVolum()<<'\n';
                }
                else
                if(optiune==2){
                    Dreptunghi Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Volumul este egal cu: "<<Figura.calculeazaVolum()<<'\n';
                }
                else
                if(optiune==3){
                    Romb Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Volumul este egal cu: "<<Figura.calculeazaVolum()<<'\n';
                }
                else
                if(optiune==4){
                    Paralelogram Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Volumul este egal cu: "<<Figura.calculeazaVolum()<<'\n';
                }
                else
                if(optiune==5){
                    Trapez Figura;
                    cin>>Figura;
                    cout<<'\n';
                    cout<<"Volumul este egal cu: "<<Figura.calculeazaVolum()<<'\n';
                }
                else{
                    cout<<'\n'<<"RESPECTA INSTRUCTIUNILE!!!";
                    return 0;
                }
                break;
            }
            case 6:{
                cout<<'\n'<<Patrat::nr_obiecte()<<'\n';
                break;
            }
            case 7:{
                ///upcasting
                cout<<'\n'<<"Exemple de transformari:"<<'\n';
                cout<<'\n'<<"Pentru a transforma un DREPTUNGHI intr-un PATRAT apasa 1"<<'\n';
                cout<<'\n'<<"Pentru a transforma un ROMB intr-un PATRAT apasa 2"<<'\n';
                short optiune;
                cin>>optiune;
                if(optiune==1){
                    Dreptunghi Figura_Copil;
                    cin>>Figura_Copil;
                    cout<<"Figura Tata este un Patrat de forma:"<<'\n'<<'\n';
                    Patrat Figura_Tata = static_cast<Dreptunghi>(Figura_Copil);
                    cout<<Figura_Tata<<'\n';
                }
                else
                if(optiune==2){
                    Romb Figura_Copil;
                    cin>>Figura_Copil;
                    cout<<"Figura Tata este un Patrat de forma:"<<'\n'<<'\n';
                    Patrat Figura_Tata = static_cast<Romb>(Figura_Copil);
                    cout<<Figura_Tata<<'\n';
                }
                else{
                    cout<<'\n'<<"RESPECTA INSTRUCTIUNILE!!!";
                    return 0;
                }
                break;
            }
            case 8:{
                ///downcasting
                cout<<"Patrat in dreptunghi"<<'\n';
                Patrat* Figura_Tata = new Dreptunghi;
                Dreptunghi* Figura_Copil;
                cin>>*Figura_Tata;
                Figura_Copil=dynamic_cast<Dreptunghi*>(Figura_Tata);
                cout<<*Figura_Copil<<'\n';
                break;
            }
            default:{
                cout<<"Nu este o instructiune valida";
                break;
            }
        }
    }
    return 0;
}
