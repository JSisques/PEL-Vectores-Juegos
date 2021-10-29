//Version de dinamismo con arrays normales
//Equivalente FreeSpace
#include <iostream>
#include <string>
#include<vector>

using namespace std;

//Definimos la clase videojuego con su conrespondiente constructor
class Videojuego {
	private:
    	string nombre;
        string genero;
        string plataforma;
    public:
    	void set(string n, string g, string p){
        	nombre=n;
            genero=g;
            plataforma=p;
        }
        Videojuego(){}
        
        string getnombre(){
            return nombre;
        }
        string getgenero(){
            return genero;
        }
        string getplataforma(){
            return plataforma;
        }
};


int main() {
	//Inicialmente no sabemos cuantos juegos tiene, por tanto se lo preguntamos.
    int njuegos;
    
    cout<<"¿Cuantos juegos tienes?"<<endl;
    cin>>njuegos;
    cin.ignore ( 100 , '\n');//Protección para el enter
    cout<<"\n\n"<<endl;
    
    //Teniendo el número de juegos ya podemos dimensionar nuestro array;
    //Utilizamos el freespace para poder gestionar la variable
    
    Videojuego *listadejuegos= new Videojuego[njuegos];
    
    //Introduce los juegos 
    for(int i=0; i<njuegos; i++){
        string aname,agenero,aplataforma;
        cout<<"introduce el nombre para el juego "<<i+1<<endl;
        getline (cin, aname);
        cout<<"introduce el genero para el juego "<<i+1<<endl;
        getline (cin, agenero);
        cout<<"introduce la plataforma para el juego "<<i+1<<endl;
        getline (cin, aplataforma);
        listadejuegos[i].set(aname,agenero,aplataforma);
        cout<<"Registrado\n\n"<<endl;
    }
    cout<<"JUEGOS:"<<endl;
    cout<<"----------------------------------------"<<endl;
    
    for(int i=0; i<njuegos;i++){
        cout<<listadejuegos[i].getnombre()<<endl;

    }
     cout<<"----------------------------------------"<<endl;

    //Si se le ha olvidado alguno o se ha comprado otro juego:
    int nNewGame;
    cout<<"¿Cuantos juegos te has comprado"<<endl;
    cin>>nNewGame;
    cin.ignore ( 100 , '\n');
    //A los que teníamos tenemos que sumarle los nuevos, pero me tengo que guardar el valor antiguo (para copiar en el for)
    int prevGames= njuegos;
    njuegos= njuegos +nNewGame;
    //Me tendría que crear otro array y copiar el array antiguo
    Videojuego *listadejuegosUpdated= new Videojuego[njuegos];
    for(int i=0; i<prevGames; i++){
        listadejuegosUpdated[i].set(listadejuegos[i].getnombre(), listadejuegos[i].getgenero(), listadejuegos[i].getplataforma());
    }

    //Como ya está copiado, el array anterior no nos sirve, nos lo cargamos, ahorramos memoria
    delete [] listadejuegos; 
    //Capturo los juegos nuevos

    for(int i=prevGames; i<njuegos; i++){
        string aname,agenero,aplataforma;
        cout<<"introduce el nombre para el juego "<<i+1<<endl;
        getline (cin, aname);
        cout<<"introduce el genero para el juego "<<i+1<<endl;
        getline (cin, agenero);
        cout<<"introduce la plataforma para el juego "<<i+1<<endl;
        getline (cin, aplataforma);
        listadejuegosUpdated[i].set(aname,agenero,aplataforma);
        cout<<"Registrado\n\n"<<endl;
    }
    
    //Justo aquí podríamos eliminar otras variables si no necesitamos usarlas.
    
    cout<<"JUEGOS:"<<endl;
    cout<<"----------------------------------------"<<endl;
    for(int i=0; i<njuegos;i++){
        cout<<listadejuegosUpdated[i].getnombre()<<endl;

    }
    cout<<"----------------------------------------"<<endl;

    delete [] listadejuegosUpdated;

    return 0;

}


