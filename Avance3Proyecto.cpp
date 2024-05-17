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

void buscarPersonaPorDPI(const string& nombreArchivo);
void buscarEstudiantePorCarnet(const string& nombreArchivo);
void leerTodo(const string& nombreArchivo);
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

            

            system("pause");
            cout << endl;
            break;
		}

        case 6:
		{
            system("cls");

            

            system("pause");
            cout << endl;
            break;
		}

        case 7:
        {
            system("cls");

            

            system("pause");
            cout << endl;
            break;
        }

        case 8:
        {
            system("cls");

            buscarPersonaPorDPI(nombreArchivo);

            system("pause");
            cout << endl;
            break;
        }

        case 9:
        {
            system("cls");

            buscarEstudiantePorCarnet(nombreArchivo);

            system("pause");
            cout << endl;
            break;
        }

        case 10:
        {
            system("cls");

            leerTodo(nombreArchivo);

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

/************************************************************buscarPersonaPorDPI()******************************************************************/
void buscarPersonaPorDPI(const string& nombreArchivo) {
    int dpi;
    gotoxy(45,1);
    cout << "Buscar Persona:" << endl << endl;
    cout << "Ingrese el DPI de la persona a buscar: ";
    cin >> dpi;
    cin.ignore();

    bool encontrado = false;
    ifstream archivo(nombreArchivo.c_str());
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            string tipo, nombre, apellido, ocupacion;
            int edad, dpiActual;
            getline(iss, tipo, ',');
            if (tipo == "1") {
                getline(iss, nombre, ',');
                getline(iss, apellido, ',');
                getline(iss, ocupacion, ',');
                iss >> edad;
                iss.ignore();
                iss >> dpiActual;
                if (dpiActual == dpi) {
                    encontrado = true;
                    persona p(nombre, apellido, ocupacion, edad, dpiActual);
                    p.mostrarInfo();
                    break;
                }
            }
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();

    if (!encontrado) {
        cout << "No se encontro una persona con el DPI ingresado." << endl;
    }
}

/***********************************************************buscarEstudiantePorCarnet()******************************************************************/
void buscarEstudiantePorCarnet(const string& nombreArchivo) {
    string carnet;
    gotoxy(45,1);
    cout << "Buscar Estudiante:" << endl << endl;
    cout << "Ingrese el carnet del estudiante a buscar: ";
    getline(cin, carnet);

    bool encontrado = false;
    ifstream archivo(nombreArchivo.c_str());
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            string tipo, nombre, apellido;
            int edad;
            double promedio;
            string carnetActual;
            getline(iss, tipo, ',');
            if (tipo == "2") {
                getline(iss, nombre, ',');
                getline(iss, apellido, ',');
                iss >> edad;
                iss.ignore();
                getline(iss, carnetActual, ',');
                iss >> promedio;
                if (carnetActual == carnet) {
                    encontrado = true;
                    estudiante e(nombre, apellido, edad, carnetActual, promedio);
                    e.mostrarInfo();
                    break;
                }
            }
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();

    if (!encontrado) {
        cout << "No se encontro un estudiante con el carnet ingresado." << endl;
    }
}
/************************************************************leerTodo()******************************************************************/
void leerTodo(const string& nombreArchivo) {
    gotoxy(45,1);
    cout << "Informacion del archivo:" << endl << endl;
    ifstream archivo(nombreArchivo.c_str());
    if (archivo.is_open()) {
        string linea;
        cout << "Personas:" << endl;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            string tipo, nombre, apellido, ocupacion;
            int edad, dpi;
            getline(iss, tipo, ',');
            if (tipo == "1") {
                getline(iss, nombre, ',');
                getline(iss, apellido, ',');
                getline(iss, ocupacion, ',');
                iss >> edad;
                iss.ignore();
                iss >> dpi;
                persona p(nombre, apellido, ocupacion, edad, dpi);
                p.mostrarInfo();
            }
        }

        cout << "Estudiantes:" << endl;
        archivo.clear(); // Limpiar el estado de error del archivo
        archivo.seekg(0, ios::beg); // Regresar al inicio del archivo

        while (getline(archivo, linea)) {
            istringstream iss(linea);
            string tipo, nombre, apellido;
            int edad;
            double promedio;
            string carnet;
            getline(iss, tipo, ',');
            if (tipo == "2") {
                getline(iss, nombre, ',');
                getline(iss, apellido, ',');
                iss >> edad;
                iss.ignore();
                getline(iss, carnet, ',');
                iss >> promedio;
                estudiante e(nombre, apellido, edad, carnet, promedio);
                e.mostrarInfo();
            }
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}

