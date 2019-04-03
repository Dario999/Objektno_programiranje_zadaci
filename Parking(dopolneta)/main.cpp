#include <iostream>
#include <cstring>

using namespace std;

class Avtomobil{

private:
	char brand[20];
	char model[20];
	char boja[20];

public:
	//default constructor
	Avtomobil(){

		strcpy(brand, "");
		strcpy(model, "");
		strcpy(boja, "");
	}
	//argument constructor
	Avtomobil(const char* boja, const char* brand, const char* model){

		strcpy(this->brand, brand);
		strcpy(this->model, model);
		strcpy(this->boja, boja);
	}
	//assignment operator
	Avtomobil& operator=(Avtomobil& avto){

		if(this != &avto){

		strcpy(this->brand, avto.brand);
		strcpy(this->model, avto.model);
		strcpy(this->boja, avto.boja);
		}
		return *this;
	}

	void pecati(){

		cout << boja << " " << brand << " " << model << endl;
	}

};


class ParkingPlac{

private:
	char adresa[20];
	char *ID;
	int cena;
	int zarabotka;
	Avtomobil *parkiraniVozila;
	int brParkirani;

public:
    //default constructor
	ParkingPlac(){
		strcpy(adresa, "");
		ID = new char[0];
		cena = 0;
		zarabotka = 0;
		brParkirani = 0;
		parkiraniVozila = new Avtomobil[brParkirani];
	}
	//constructor
	ParkingPlac(const char *adresa,const char* id, int cena){

		zarabotka = 0;
		this->cena = cena;
		strcpy(this->adresa, adresa);
		ID = new char[strlen(id)+1];
		strcpy(ID, id);


		brParkirani = 0;
		parkiraniVozila = new Avtomobil[brParkirani];

	}
	//destructor
	~ParkingPlac(){
		delete [] ID;
		delete [] parkiraniVozila;
	}
	//copy constructor
	ParkingPlac(const ParkingPlac &a){

		ID = new char[strlen(a.ID)+1];
		strcpy(ID, a.ID);
		strcpy(adresa, a.adresa);
		cena = a.cena;
		zarabotka = a.zarabotka;
		//
		brParkirani = a.brParkirani;
		parkiraniVozila = new Avtomobil[a.brParkirani];
		for(int i = 0; i < brParkirani; ++i){

			(this->parkiraniVozila)[i] = a.parkiraniVozila[i];
		}

	}

	//assignment operator
	ParkingPlac& operator=(ParkingPlac &a){

		if (this != &a){

			delete [] ID;
			ID = new char[strlen(a.ID)+1];
			strcpy(ID, a.ID);
			cena = a.cena;
			zarabotka = a.zarabotka;
			strcpy(adresa, a.adresa);
			//
			delete [] parkiraniVozila;
			brParkirani = a.brParkirani;
			parkiraniVozila = new Avtomobil[a.brParkirani];
			for(int i = 0; i < brParkirani; ++i){

				(this->parkiraniVozila)[i] = a.parkiraniVozila[i];
			}
		}
		return *this;
	}

	const char* getId(){

		return ID;
	}

	void pecati(){
		//ova e bolje
		// cout << ID << " " << adresa << " - " << zarabotka << " denari" << endl;

		cout << ID << " " << adresa;
		if (zarabotka > 0){
			cout << " - " << zarabotka << " denari";
		}
		cout << endl;
	}

	void platiCasovi(int casovi){

		zarabotka += casovi*cena;
	}

	bool daliIstaAdresa(ParkingPlac p){

		if (strcmp(p.adresa, adresa) == 0) return true;
		return false;
	}


	void parkirajVozilo(Avtomobil novoVozilo){

		Avtomobil* novaLista = new Avtomobil[brParkirani+1];
		for(int i = 0; i < brParkirani; ++i){

			novaLista[i] = parkiraniVozila[i];
		}
		delete [] parkiraniVozila;
		parkiraniVozila = novaLista;
		parkiraniVozila[brParkirani++] = novoVozilo;
	}

	void pecatiParkiraniVozila(){

		cout << "Vo parkingot se parkirani slednite vozila: " << endl;

		for(int i = 0; i < brParkirani; ++i){

			cout << i+1 << ".";
			parkiraniVozila[i].pecati();
		}
	}
};


int main(){

	ParkingPlac p[100];
	int n,m;
	char adresa[50],id[50];
	int brojcasovi,cenacas;
	cin>>n;
	if(n > 0){


		for (int i=0;i<n;i++){
	        cin.get();
			cin.getline(adresa,50);
			cin>>id>>cenacas;

			ParkingPlac edna(adresa,id,cenacas);

	        //povik na operatorot =
	        p[i]=edna;
		}

		//plakjanje
		cin>>m;
		for (int i=0;i<m;i++){

			cin>>id>>brojcasovi;

	        int findId=false;
	        for (int j=0;j<m;j++){
	            if (strcmp(p[j].getId(),id)==0){
	                p[j].platiCasovi(brojcasovi);
	                findId=true;
	            }
	        }
			if (!findId)
	        cout<<"Ne e platen parking. Greshen ID."<<endl;
		}

	    cout<<"========="<<endl;
	    ParkingPlac pCentar("Cvetan Dimov","C10",80);
		for (int i=0;i<n;i++)
	        if (p[i].daliIstaAdresa(pCentar))
	            p[i].pecati();
	} else {

		ParkingPlac najdobarPlac("Mars", "1337", 1);
	    int brVozila;
	    cin >> brVozila;
	    for(int i = 0; i < brVozila; ++i){

	    	char boja[20];
	    	char brend[20];
	    	char model[20];

	    	cin >> boja >> brend >> model;
	    	Avtomobil novAvtomobil(boja, brend, model);
	    	najdobarPlac.parkirajVozilo(novAvtomobil);
	    }
	    if(brVozila != 0)
	    najdobarPlac.pecatiParkiraniVozila();

	}




}
