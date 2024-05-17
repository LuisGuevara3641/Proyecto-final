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
string crearArchivo();
bool archivoExiste(const string& nombreArchivo);
void crearPersona(const string& nombreArchivo);
void crearEstudiante(const string& nombreArchivo);
void actualizarArchivo(const string& nombreArchivo);
void modificarPersona(const string& nombreArchivo);
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

            nombreArchivo = crearArchivo();

            system("pause");
            cout << endl;
            break;
        }

        case 2:
		{
            system("cls");

            crearPersona(nombreArchivo);

            system("pause");
            cout << endl;
            break;
		}

        case 3:
		{
            system("cls");

            crearEstudiante(nombreArchivo);

            system("pause");
            cout << endl;
            break;
		}

        case 4:
		{
            system("cls");

            modificarPersona(nombreArchivo);

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
/************************************************************crearArchivo()*************************************************************************/
string crearArchivo() {
    string nombreArchivo;
    do {
        system("cls");
        gotoxy(45, 1);
        cout << "Crear archivo txt:" << endl << endl;
        cout << "Ingrese el nombre del archivo (sin .txt): ";
        getline(cin, nombreArchivo); // Leer toda la línea, permitiendo espacios
        nombreArchivo += ".txt";

        if (archivoExiste(nombreArchivo)) {
            cout << "El archivo '" << nombreArchivo << "' ya existe. Desea utilizarlo? (s/n): ";
            char respuesta;
            cin >> respuesta;
            cin.ignore(); // Ignorar el salto de línea
            if (respuesta == 's' || respuesta == 'S') {
                return nombreArchivo;
            } else {
                continue;
            }
        } else {
            ofstream archivo(nombreArchivo.c_str());
            if (archivo.is_open()) {
                cout << "Archivo '" << nombreArchivo << "' creado exitosamente." << endl;
                archivo.close();
                return nombreArchivo;
            } else {
                cout << "No se pudo crear el archivo '" << nombreArchivo << "'." << endl;
            }
        }
    } while (true);
}
/************************************************************comprobacionArchivo()******************************************************************/
bool archivoExiste(const string& nombreArchivo) { // Verifica si el archivo existe
    ifstream archivo(nombreArchivo.c_str());
    bool existe = archivo.good();
    archivo.close();
    return existe;
}
/************************************************************crearPersona()******************************************************************/
void crearPersona(const string& nombreArchivo) {
    string nombre, apellido, ocupacion;
    int edad, dpi;
    gotoxy(45,1);
    cout << "Ingresar Persona:" << endl << endl;
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    cout << "Ingrese el apellido: ";
    getline(cin, apellido);
    cout << "Ingrese la ocupacion: ";
    getline(cin, ocupacion);
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese el DPI: ";
    cin >> dpi;

    persona p(nombre, apellido, ocupacion, edad, dpi);
    listaPersonas.push_back(p);

    ofstream archivo(nombreArchivo.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << "1,"; // Identificador de tipo para persona
        p.mostrarInfoArchivo(archivo);
        cout << "Persona creada exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}

/************************************************************CrearEstudiante()******************************************************************/
void crearEstudiante(const string& nombreArchivo) {
    string nombre, apellido, carnet;
    int edad;
    double promedio;
    gotoxy(45,1);
    cout << "Ingresar Estudiante:" << endl << endl;
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    cout << "Ingrese el apellido: ";
    getline(cin, apellido);
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese el carnet: ";
    cin >> carnet;
    cout << "Ingrese el promedio: ";
    cin >> promedio;

    estudiante e(nombre, apellido, edad, carnet, promedio);
    listaEstudiantes.push_back(e);

    ofstream archivo(nombreArchivo.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << "2,"; // Identificador de tipo para estudiante
        e.mostrarInfoArchivo(archivo);
        cout << "Estudiante creado exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}
/************************************************************actualizarArchivo()******************************************************************/
void actualizarArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str()); // Convertir std::string a const char*
    if (archivo.is_open()) {
        // Escribir información de personas
        for (size_t i = 0; i < listaPersonas.size(); ++i) {
            archivo << "1,";
            listaPersonas[i].mostrarInfoArchivo(archivo);
        }

        // Escribir información de estudiantes
        for (size_t i = 0; i < listaEstudiantes.size(); ++i) {
            archivo << "2,";
            listaEstudiantes[i].mostrarInfoArchivo(archivo);
        }

        cout << "Archivo actualizado exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo para actualizar." << endl;
    }
    archivo.close();
}
/************************************************************modificarPersona()******************************************************************/
void modificarPersona(const string& nombreArchivo) {
    int dpi;
    gotoxy(45,1);
    cout << "Modificar Persona:" << endl << endl;
    cout << "Ingrese el DPI de la persona a modificar: ";
    cin >> dpi;
    cin.ignore();

    vector<persona>::iterator it;
    for (it = listaPersonas.begin(); it != listaPersonas.end(); ++it) {
        if ((*it).getDPI() == dpi) {
            break;
        }
    }

    if (it != listaPersonas.end()) {
        string nombre, apellido, ocupacion;
        int edad;

        cout << "Ingrese el nuevo nombre: ";
        getline(cin, nombre);
        cout << "Ingrese el nuevo apellido: ";
        getline(cin, apellido);
        cout << "Ingrese la nueva ocupacion: ";
        getline(cin, ocupacion);
        cout << "Ingrese la nueva edad: ";
        cin >> edad;
        cin.ignore();

        *it = persona(nombre, apellido, ocupacion, edad, dpi);

        ofstream archivo(nombreArchivo.c_str(), ios::out);
        if (archivo.is_open()) {
            for (vector<persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); ++it) {
                archivo << "1," << it->getNombre() << "," << it->getApellido() << "," << it->getOcupacion() << "," << it->getEdad() << "," << it->getDPI() << endl;
            }
            for (vector<estudiante>::iterator it = listaEstudiantes.begin(); it != listaEstudiantes.end(); ++it) {
                archivo << "2," << it->getNombre() << "," << it->getApellido() << "," << it->getEdad() << "," << it->getNumeroCarnet() << "," << it->getPromedioCalificaciones() << endl;
            }
            cout << "Persona modificada exitosamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
        archivo.close();
    } else {
        cout << "No se encontro una persona con el DPI ingresado." << endl;
    }
}

