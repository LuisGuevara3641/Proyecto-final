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
}


/************************************************************tablaEstudiantes()*************************************************************************/
void tablaEstudiantes() {
}

/************************************************************tablaCursos()*************************************************************************/
void tablaCursos() {
}

/************************************************************tablaCalificaciones()*************************************************************************/
void tablaCalifiaciones() {
}