#include <iostream>
#include <mysql/jdbc.h>
#include <string>


using namespace std;


void baseDeDatos();
void tablaCursos();
void tablaEstudiantes();
void tablaCalifiaciones();

/***********************************************************establecerConexion()*************************************************************************/
sql::Connection* establecerConexion() {
    sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect("tcp://127.0.0.1:3306", "sqluser", "password");
        con->setSchema("controlescolar");
    return con;
}

/************************************************************insertarEstudiante()*************************************************************************/
void insertarEstudiante(sql::Connection* con, std::string nombre, int grado) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute("INSERT INTO estudiantes (nombre_estudiante, grado) VALUES ('" + nombre + "', " + std::to_string(grado) + ")");
    delete stmt;
}

/************************************************************obtenerEstudiantes()*************************************************************************/
void obtenerEstudiantes(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM estudiantes");
    while (res->next()) {
        std::cout << res->getInt("id") << " " << res->getString("nombre_estudiante") << " " << res->getInt("grado") << std::endl;
    }
    delete res;
    delete stmt;
}

/************************************************************actualizarEstudiante()*************************************************************************/
void actualizarEstudiante(sql::Connection* con, int id, std::string nombre, int grado) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute("UPDATE estudiantes SET nombre_estudiante = '" + nombre + "', grado = " + std::to_string(grado) + " WHERE id = " + std::to_string(id));
    delete stmt;
}

/************************************************************eliminarEstudiante()*************************************************************************/
void eliminarEstudiante(sql::Connection* con, int id) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute("DELETE FROM estudiantes WHERE id = " + std::to_string(id));
    delete stmt;
}


/************************************************************insertarCurso()*************************************************************************/
void insertarCurso(sql::Connection* con, std::string nombre, int creditos) {
    sql::Statement* stmt = con->createStatement();
    try {
        stmt->execute("INSERT INTO cursos (nombre_cursos, creditos) VALUES ('" + nombre + "', " + std::to_string(creditos) + ")");
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error al insertar curso: " << e.what() << std::endl;
    }
    delete stmt;
}

/************************************************************obtenerCursos()*************************************************************************/
void obtenerCursos(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM cursos");
    while (res->next()) {
        std::cout << res->getInt("id") << " " << res->getString("nombre_cursos") << " " << res->getInt("creditos") << std::endl;
    }
    delete res;
    delete stmt;
}

/************************************************************actualizarCurso()*************************************************************************/
void actualizarCurso(sql::Connection* con, int id, std::string nombre, int creditos) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute("UPDATE cursos SET nombre_cursos = '" + nombre + "', creditos = " + std::to_string(creditos) + " WHERE id = " + std::to_string(id));
    delete stmt;
}

/************************************************************eliminarCurso()*************************************************************************/
void eliminarCurso(sql::Connection* con, int id) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute("DELETE FROM cursos WHERE id = " + std::to_string(id));
    delete stmt;
}

/************************************************************insertarCalificacion()*************************************************************************/
void insertarCalificacion(sql::Connection* con, int idEstudiante, int idCurso, int calificacion) {
    sql::Statement* stmt = con->createStatement();
    try {
        stmt->execute("INSERT INTO calificaciones (id_estudiante, id_curso, calificacion) VALUES (" + std::to_string(idEstudiante) + ", " + std::to_string(idCurso) + ", " + std::to_string(calificacion) + ")");
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error al insertar calificación: " << e.what() << std::endl;
    }
    delete stmt;
}

/************************************************************obtenerCalificaciones()*************************************************************************/
void obtenerCalificaciones(sql::Connection* con) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM calificaciones");
    while (res->next()) {
        std::cout << res->getInt("id") << " " << res->getInt("id_estudiante") << " " << res->getInt("id_curso") << " " << res->getInt("calificacion") << std::endl;
    }
    delete res;
    delete stmt;
}

/************************************************************actualizarCalificacion()*************************************************************************/
void actualizarCalificacion(sql::Connection* con, int id, int idEstudiante, int idCurso, int calificacion) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute("UPDATE calificaciones SET id_estudiante = " + std::to_string(idEstudiante) + ", id_curso = " + std::to_string(idCurso) + ", calificacion = " + std::to_string(calificacion) + " WHERE id = " + std::to_string(id));
    delete stmt;
}

/************************************************************eliminarCalificacion()*************************************************************************/
void eliminarCalificacion(sql::Connection* con, int id) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute("DELETE FROM calificaciones WHERE id = " + std::to_string(id));
    delete stmt;
}


/************************************************************MAIN()*************************************************************************/
int main() {
    baseDeDatos();
    return 0;
}

/************************************************************baseDeDatos()*************************************************************************/
void baseDeDatos() {
    int opcion;
    system("cls");

    do {
        cout << "Bienvenido a la base de datos\n\n";
        cout << "\tMenu de la base de datos\n\n";
        cout << "1. Tabla de estudiantes\n";
        cout << "2. Tabla de cursos\n";
        cout << "3. Tabla de calificaciones\n";
        cout << "4. Salir de la base de datos\n\n";
        cout << "Seleccionar tabla: ";
        cin >> opcion;
        cin.ignore();
        system("cls");

        switch (opcion) {
        case 1:
            tablaEstudiantes();
            break;
        case 2:
            tablaCursos();
            break;
        case 3:
            tablaCalifiaciones();
            break;
        }
    } while (opcion != 4);
}


/************************************************************tablaEstudiantes()*************************************************************************/
void tablaEstudiantes() {

    sql::Connection* con = establecerConexion();

    int opcion;
    do {
       
        string nombreEstudiante;
        int grado;
        int id;

        cout << "\tMenu de la tabla de estudiantes\n\n";
        cout << "1. Insertar estudiante: \n";
        cout << "2. Ver todos los estudiantes: \n";
        cout << "3. Actualizar estudiantes: \n";
        cout << "4. Eliminar estudiantes: \n";
        cout << "5. Salir de la tabla: \n\n";

        cout << "Opcion a elegir: ";
        cin >> opcion;
        cin.ignore();

        system("cls");

        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, nombreEstudiante);
            cout << "Ingrese el grado del estudiante: ";
            cin >> grado;
            cin.ignore();
            insertarEstudiante(con, nombreEstudiante, grado);
            break;
        case 2:
            cout << "ID - NOMBRE - GRADO\n";
            obtenerEstudiantes(con);
            break;
        case 3:
            cout << "Escribe el ID a actualizar del estudiante: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nuevo nombre del estudiante: ";
            getline(cin, nombreEstudiante);
            cout << "Ingrese el nuevo grado del estudiante: ";
            cin >> grado;
            cin.ignore();
            actualizarEstudiante(con, id, nombreEstudiante, grado);
            break;
        case 4: 
            cout << "Escribe el ID del estudiante a eliminar: ";
            cin >> id;
            cin.ignore();
            eliminarEstudiante(con, id);
            break;
        case 5:
            cout << "Has salido correctamente";
            break;
        }
        system("pause");
        system("cls");
    } while (opcion != 5);

    delete con;
}

/************************************************************tablaCursos()*************************************************************************/
void tablaCursos() {
}

/************************************************************tablaCalificaciones()*************************************************************************/
void tablaCalifiaciones() {
}
