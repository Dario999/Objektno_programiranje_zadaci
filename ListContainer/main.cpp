#include <iostream>
#include <cstring>
using namespace std;

class List{
private:
    int *lista;
    int brBroevi;
public:
    List(){
        lista = new int[0];
        brBroevi = 0;
    }
    List(int *l,int brBroevi){
        this->brBroevi = brBroevi;
        this->lista = new int[brBroevi];
        for(int i=0;i<brBroevi;i++)
            lista[i]=l[i];
    }
    List(const List &l){
        this->brBroevi = l.brBroevi;
        this->lista = new int[l.brBroevi];
        for(int i=0;i<brBroevi;i++)
            lista[i] = l.lista[i];
    }
    ~List(){
        delete[] lista;
    }
    List &operator=(const List &l){
        if(this!=&l){
            delete[] lista;
            lista = new int[l.brBroevi];
            for(int i=0;i<l.brBroevi;i++)
                lista[i] = l.lista[i];
            brBroevi = l.brBroevi;
        }
        return *this;
    }
    int sum(){
        int sum=0;
        for(int i=0;i<brBroevi;i++)
            sum+=lista[i];
        return sum;
    }
    double average(){
        return sum()*1.0/brBroevi;
    }
    void pecati(){
        cout<<brBroevi<<": ";
        for(int i=0;i<brBroevi;i++)
            cout<<lista[i]<<" ";
        cout<<"sum: "<<sum()<<" "<<"average: "<<average();
    }
    int getNumber(){
        return brBroevi;
    }
};

class ListContainer{
private:
    List *niza;
    int brojElementi;
    int brObidi;
public:
    ListContainer(){
        niza = new List[0];
        brojElementi = 0;
        brObidi = 0;
    }
    ListContainer(List *n,int broj,int obidi){
        niza = new List[broj];
        for(int i=0;i<broj;i++)
            niza[i] = n[i];
        brojElementi = broj;
        brObidi = obidi;
    }
    ListContainer(const ListContainer &lc){
        niza = new List[lc.brojElementi];
        for(int i=0;i<lc.brojElementi;i++)
            niza[i] = lc.niza[i];
        brojElementi = lc.brojElementi;
        brObidi = lc.brObidi;
    }
    ~ListContainer(){
        delete[] niza;
    }

    ListContainer &operator=(const ListContainer &lc){
        if(this!=&lc){
            brojElementi = lc.brojElementi;
            brObidi = lc.brObidi;
            niza = new List[brojElementi];
            for(int i=0;i<brojElementi;i++)
                niza[i] = lc.niza[i];
        }
        return *this;
    }
    int sum(){
        int sum = 0;
        for(int i=0;i<brojElementi;i++)
            sum+=niza[i].sum();
        return sum;
    }

    double average(){
        int suma=sum();
        int numElements = 0;
        for(int i=0;i<brojElementi;i++)
            numElements += niza[i].getNumber();
        return suma/(numElements*1.0);
    }

    void print(){
        if(brojElementi!=0){
            for(int i=0;i<brojElementi;i++){
                cout<<"List number: "<<i+1<<" List info: ";
                    niza[i].pecati();
                    cout<<endl;
            }
        cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
        cout<<"Successful attempts: "<<brojElementi<<" Failed attempts: "<<brObidi - brojElementi<<endl;
        }
        else
            cout<<"The list is empty"<<endl;
    }
    void addNewList(List l){
        brObidi++;
        int flag=1;
        for(int i=0;i<brojElementi;i++){
            if(l.sum() == niza[i].sum())
                flag=0;
        }
        if(flag){
            List *tmp = new List[brojElementi+1];
            for(int i=0;i<brojElementi;i++){
                tmp[i] = niza[i];
            }
            delete[] niza;
            niza = new List[brojElementi+1];
            for(int i=0;i<brojElementi;i++)
                niza[i] = tmp[i];
            niza[brojElementi++] = l;
        }
    }


};

int main() {

	ListContainer lc;
	int N;
	cin>>N;

	for (int i=0;i<N;i++) {
		int n;
		int niza[100];

		cin>>n;

		for (int j=0;j<n;j++){
			cin>>niza[j];

		}

		List l=List(niza,n);

		lc.addNewList(l);
	}


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;

    }
    else {
        lc.print();
    }
}
