#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <fstream>
#include <cctype>
#include <time.h>
#include <cassert>
using namespace std;

void swap(int &a, int &b, string &c, string &d ){	
	int	temp = a;	
	a =	b;	
	b =	temp;	
	string tempo = c;
	c = d;
	d = tempo;
}

void ordenar(vector<string> &palabras, vector<int> &cant){
int	N = cant.size();	
for	(int i = 1;	i <	N; ++i)	{	
	 	 for (int j	= i; j > 0; --j) {	
			 if	( cant[j-1] > cant[j] )	
				 swap(cant[j-1], cant[j], palabras[j-1], palabras[j] );	
			 else break;	
	 	 }	
	 }	
}

class Texto{
public:
	size_t n;
	vector<int> cant;
	vector<string> palabras;
	string palabra;
    map<string, int> c;	

public:
	Texto(ifstream &texto ){

		while(!texto.eof()) {
    		texto >> palabra;

    		formato(palabra);
     		if(!palabra.empty()){
    			c[palabra] += 1;
    		}	
    	}
    	
    	ingresarpalabras();
    	ordenar(palabras, cant);
    	imprimir();
	}

	void formato(string &a){
    	for(int i = a.size()-1; i !=-1 ;i--){
    		if( ((int(a[i]) >= 33) && ((int(a[i]) <=64))) || ((int(a[i]) >= 91) && (int(a[i]) <= 96)) || (int(a[i]) >=123 && (int(a[i]) <=126))){
    			a.erase(a.begin()+i);
    		}
    		a[i]= tolower(a[i]);
    	}
	}
	void ingresarpalabras(){
		for(auto it = c.begin(); it != c.end(); ++it) {
       		cant.push_back(it->second); 
       		palabras.push_back(it->first);
    	}
	}

	void imprimir(){
		cout << "escriba el numero de palabras que desea mostrar ";
		cin >> n;
		assert(n<= cant.size());
		int J=1;
		cout <<"TOP PALABRAS: "<<endl;
		for(size_t i=cant.size()-1; i>=cant.size()-n;i--){
	    	cout <<J <<"\t" << palabras[i] << " "<< cant[i] <<" apariciones"<<endl;
	    	J++;
    	}
	}
};


int main() {
    clock_t tStart = clock();

    ifstream texto;
	texto.open("biblia.txt");
	Texto biblia(texto);
 

    texto.close();


    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
