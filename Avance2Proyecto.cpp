#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <sstream>

using namespace std;
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
class persona 
{
    private:
    string nombre, apellido, ocupacion;
    int edad, DPI;
    
    public:
    // Constructor sin DPI
    persona(string nombre1, string apellido1, string ocupacion1, int edad1) {
        nombre = nombre1;
        apellido = apellido1;
        ocupacion = ocupacion1;
        edad = edad1;
    }

    // Constructor con DPI
    persona(string nombre1, string apellido1, string ocupacion1, int edad1, int DPI1) {
        nombre = nombre1;
        apellido = apellido1;
        ocupacion = ocupacion1;
        edad = edad1;
        DPI = DPI1;
    }

    void mostrarInfo()
    {
        cout << "_________________________________"
            << "\nNombre: " << nombre << "\nApellido: " << apellido << "\nOcupacion: " << ocupacion << "\nEdad: " << edad << "\nDPI: " << DPI <<"\n_________________________________" << endl;
    }
    void mostrarInfoArchivo(ofstream& archivo) const {
        archivo << nombre << "," << apellido << "," << ocupacion << "," << edad << "," << DPI << endl;
    }

    const string& getNombre() const { return nombre; } // Se hace esto para poder acceder a esta información
    const string& getApellido() const { return apellido; }
    const string& getOcupacion() const { return ocupacion; }
    const int& getEdad() const { return edad; }
    const int& getDPI() const { return DPI; }
};

class estudiante : public persona // Hereda de la clase persona
{
private:
    string numeroCarnet;
    double promedioCalificaciones;

public:
    estudiante(string nombre1, string apellido1, int edad1, string carnet, double promedio)
        : persona(nombre1, apellido1, "", edad1), numeroCarnet(carnet), promedioCalificaciones(promedio) {}

    void mostrarInfo() const
    {
        cout << "_________________________________" 
            << "\nNombre: " << getNombre() 
            << "\nApellido: " << getApellido() 
            << "\nEdad: " << getEdad()
            << "\nCarnet: " << numeroCarnet 
            << "\nPromedio: " << promedioCalificaciones 
            << "\n_________________________________" << endl;
    }
    void mostrarInfoArchivo(ofstream& archivo) const {
        archivo << getNombre() << "," << getApellido() << "," << getEdad() << "," << numeroCarnet << "," << promedioCalificaciones << endl;
    }

    const string& getNumeroCarnet() const { return numeroCarnet; }
    const double& getPromedioCalificaciones() const { return promedioCalificaciones; }
};

vector<estudiante> listaEstudiantes; // Se inicializan estos vectores que son como listas, para manejar de mejor manera los datos.
vector<persona> listaPersonas;
void modificarEstudiante(const string& nombreArchivo);
void eliminarPersona(const string& nombreArchivo);
void eliminarEstudiante(const string& nombreArchivo);
int main()
{
    //string nombreArchivo = crearArchivo();
    system("cls");
    int opc;
    string nombreArchivo;
    do
    {
        gotoxy(45, 1);
        cout << "MENU PRINCIPAL" << endl;
        cout << "1- Crear archivo.txt y trabajar con el apartir de ahora." << endl;
        cout << "2- Crear persona." << endl;
        cout << "3- Crear estudiante." << endl;
        cout << "4- Modificar persona" << endl;
        cout << "5- Modificar estudiante." << endl;
        cout << "6- Eliminar persona." << endl;
        cout << "7- Eliminar estudiante" << endl;
        cout << "8- Buscar persona por su DPI." << endl;
        cout << "9- Buscar estudiante por su Carnet." << endl;
        cout << "10- Leer todo el archivo .txt" << endl;
        cout << "11- Salir del menu." << endl;
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            system("cls");


            system("pause");
            cout << endl;
            break;
        }

        case 2:
		{
            system("cls");


            system("pause");
            cout << endl;
            break;
		}

        case 3:
		{
            system("cls");


            system("pause");
            cout << endl;
            break;
		}

        case 4:
		{
            system("cls");


            system("pause");
            cout << endl;
            break;
		}

        case 5:
		{
            system("cls");

            modificarEstudiante(nombreArchivo);

            system("pause");
            cout << endl;
            break;
		}

        case 6:
		{
            system("cls");

            eliminarPersona(nombreArchivo);

            system("pause");
            cout << endl;
            break;
		}

        case 7:
        {
            system("cls");

            eliminarEstudiante(nombreArchivo);

            system("pause");
            cout << endl;
            break;
        }

        case 8:
        {
            system("cls");

            

            system("pause");
            cout << endl;
            break;
        }

        case 9:
        {
            system("cls");

           

            system("pause");
            cout << endl;
            break;
        }

        case 10:
        {
            system("cls");

           

            system("pause");
            cout << endl;
            break;
        }
    
        default:
			break;
		}
        system("cls");
	} while (opc != 11);

    cout << "Fuera del programa" << endl;
    system("pause");
    return 0;
}


/************************************************************modificarEstudiante()******************************************************************/
void modificarEstudiante(const string& nombreArchivo) {
    string carnet;
    gotoxy(45,1);
    cout << "Modificar Estudiante:" << endl << endl;
    cout << "Ingrese el carnet del estudiante a modificar: ";
    getline(cin, carnet);

    vector<estudiante>::iterator it;
    for (it = listaEstudiantes.begin(); it != listaEstudiantes.end(); ++it) {
        if ((*it).getNumeroCarnet() == carnet) {
            break;
        }
    }

    if (it != listaEstudiantes.end()) {
        string nombre, apellido;
        int edad;
        double promedio;

        cout << "Ingrese el nuevo nombre: ";
        getline(cin, nombre);
        cout << "Ingrese el nuevo apellido: ";
        getline(cin, apellido);
        cout << "Ingrese la nueva edad: ";
        cin >> edad;
        cin.ignore();
        cout << "Ingrese el nuevo promedio: ";
        cin >> promedio;
        cin.ignore();

        *it = estudiante(nombre, apellido, edad, carnet, promedio);

        ofstream archivo(nombreArchivo.c_str(), ios::out);
        if (archivo.is_open()) {
            for (vector<persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); ++it) {
                archivo << "1," << it->getNombre() << "," << it->getApellido() << "," << it->getOcupacion() << "," << it->getEdad() << "," << it->getDPI() << endl;
            }
            for (vector<estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); ++it) {
                archivo << "2," << it->getNombre() << "," << it->getApellido() << "," << it->getEdad() << "," << it->getNumeroCarnet() << "," << it->getPromedioCalificaciones() << endl;
            }
            cout << "Estudiante modificado exitosamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
        archivo.close();
    } else {
        cout << "No se encontro un estudiante con el carnet ingresado." << endl;
    }
}
/************************************************************eliminarPersona()******************************************************************/
void eliminarPersona(const string& nombreArchivo) {
    int dpi;
    gotoxy(45,1);
    cout << "Eliminar Persona:" << endl << endl;
    cout << "Ingrese el DPI de la persona a eliminar: ";
    cin >> dpi;
    cin.ignore();

    vector<persona>::iterator it = listaPersonas.begin();
    bool encontrado = false;
    while (it != listaPersonas.end()) {
        if ((*it).getDPI() == dpi) {
            encontrado = true;
            break;
        }
        ++it;
    }

    if (encontrado) {
        listaPersonas.erase(it);

        ofstream archivo(nombreArchivo.c_str(), ios::out);
        if (archivo.is_open()) {
            for (vector<persona>::iterator pit = listaPersonas.begin(); pit != listaPersonas.end(); ++pit) {
                archivo << "1," << (*pit).getNombre() << "," << (*pit).getApellido() << "," << (*pit).getOcupacion() << "," << (*pit).getEdad() << "," << (*pit).getDPI() << endl;
            }
            for (vector<estudiante>::iterator eit = listaEstudiantes.begin(); eit != listaEstudiantes.end(); ++eit) {
                archivo << "2," << (*eit).getNombre() << "," << (*eit).getApellido() << "," << (*eit).getEdad() << "," << (*eit).getNumeroCarnet() << "," << (*eit).getPromedioCalificaciones() << endl;
            }
            cout << "Persona eliminada exitosamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
        archivo.close();
    } else {
        cout << "No se encontro una persona con el DPI ingresado." << endl;
    }
}

/************************************************************eliminarEstudiante()******************************************************************/
void eliminarEstudiante(const string& nombreArchivo) {
    string carnet;
    gotoxy(45,1);
    cout << "Eliminar Estudiante:" << endl << endl;
    cout << "Ingrese el carnet del estudiante a eliminar: ";
    getline(cin, carnet);

    vector<estudiante>::iterator it = listaEstudiantes.begin();
    bool encontrado = false;
    while (it != listaEstudiantes.end()) {
        if ((*it).getNumeroCarnet() == carnet) {
            encontrado = true;
            break;
        }
        ++it;
    }

    if (encontrado) {
        listaEstudiantes.erase(it);

        ofstream archivo(nombreArchivo.c_str(), ios::out);
        if (archivo.is_open()) {
            for (vector<persona>::iterator pit = listaPersonas.begin(); pit != listaPersonas.end(); ++pit) {
                archivo << "1," << (*pit).getNombre() << "," << (*pit).getApellido() << "," << (*pit).getOcupacion() << "," << (*pit).getEdad() << "," << (*pit).getDPI() << endl;
            }
            for (vector<estudiante>::iterator eit = listaEstudiantes.begin(); eit != listaEstudiantes.end(); ++eit) {
                archivo << "2," << (*eit).getNombre() << "," << (*eit).getApellido() << "," << (*eit).getEdad() << "," << (*eit).getNumeroCarnet() << "," << (*eit).getPromedioCalificaciones() << endl;
            }
            cout << "Estudiante eliminado exitosamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
        archivo.close();
    } else {
        cout << "No se encontro un estudiante con el carnet ingresado." << endl;
    }
}


