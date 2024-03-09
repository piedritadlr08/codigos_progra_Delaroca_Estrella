#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Persona {
    string nombreCompleto;
    string apellido;
    string ciudadNacimiento;
    int fechaNacimiento[3];
};

int main() {
    const int num_personas = 2;

    Persona personas[num_personas];

    time_t t = time(0);
    tm* now = localtime(&t);
    int anio_actual = now->tm_year + 1900;
    int mes_actual = now->tm_mon + 1;
    int dia_actual = now->tm_mday;

    for (int i = 0; i < num_personas; ++i) {
        cout << "Ingrese los datos de la Persona " << i + 1 << ":" << endl;
        cout << "Nombre completo: ";
        getline(cin, personas[i].nombreCompleto);
        cout << "Apellido: ";
        getline(cin, personas[i].apellido);
        cout << "Ciudad de nacimiento: ";
        getline(cin, personas[i].ciudadNacimiento);
        cout << "Fecha de nacimiento (año mes día): ";
        cin >> personas[i].fechaNacimiento[0] >> personas[i].fechaNacimiento[1] >> personas[i].fechaNacimiento[2];
        cin.ignore();
    }

    for (int i = 0; i < num_personas; ++i) {
        cout << "\nInformación de la Persona " << i + 1 << ":" << endl;
        cout << "Nombre completo: " << personas[i].nombreCompleto << endl;
        cout << "Apellido: " << personas[i].apellido << endl;
        cout << "Ciudad de nacimiento: " << personas[i].ciudadNacimiento << endl;
        cout << "Fecha de nacimiento: " << personas[i].fechaNacimiento[0] << "-" << personas[i].fechaNacimiento[1] << "-" << personas[i].fechaNacimiento[2] << endl;

        int edad = anio_actual - personas[i].fechaNacimiento[0];
        if (mes_actual < personas[i].fechaNacimiento[1] || (mes_actual == personas[i].fechaNacimiento[1] && dia_actual < personas[i].fechaNacimiento[2]))
            edad--;

        cout << "Edad: " << edad << " años" << endl;
        cout << (edad >= 18 ? "Es mayor de edad." : "Es menor de edad.") << endl;
    }

    return 0;
}
