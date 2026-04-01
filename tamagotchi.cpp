#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string nombre;
    int hambre = 50;
    int felicidad = 3; 
    int energia = 50;
    int edad = 0;
    int contadorAcciones = 0;
    string opcion; 
    bool jugando = true;

    cout << "¡Bienvenido al simulador de Mascota Virtual!\n";
    cout << "Introduce el nombre de tu mascota: ";
    cin >> nombre;

    while (jugando) {
        // Limpiador de pantalla para Linux/Web
        system("clear"); 

        // Mostrar Interfaz
        cout << "========================================\n";
        cout << "   NOMBRE: " << nombre << "   |   EDAD: " << edad << " años\n";
        cout << "----------------------------------------\n";
        cout << "   Hambre:    " << hambre << "/100\n";
        cout << "   Energia:   " << energia << "/100\n";
        cout << "   Felicidad: ";
        for (int i = 0; i < felicidad; i++) {
            cout << "<3 "; 
        }
        cout << "\n========================================\n";

        // Menú de opciones
        cout << "¿Que quieres hacer con " << nombre << "?\n";
        cout << " 1. Alimentar\n";
        cout << " 2. Jugar\n";
        cout << " 3. Dormir\n";
        cout << " 4. Salir del juego\n";
        cout << "Eleccion: ";
        cin >> opcion;

        // Lógica de acciones
        if (opcion == "1") {
            cout << "\n>> Le das de comer... ¡Le encanta!\n";
            hambre -= 25;
            energia += 5;
            contadorAcciones++;
        }
        else if (opcion == "2") {
            cout << "\n>> Juegas un rato... ¡Se ve muy feliz!\n";
            felicidad += 1;
            energia -= 20;
            hambre += 10;
            contadorAcciones++;
        }
        else if (opcion == "3") {
            cout << "\n>> Zzz... " << nombre << " esta descansando.\n";
            energia += 40;
            hambre += 15;
            contadorAcciones++;
        }
        else if (opcion == "4") {
            cout << "\n¡Adios! Gracias por cuidar a " << nombre << ".\n";
            jugando = false;
        }
        else {
            cout << "\nOpcion no valida, intenta de nuevo.\n";
        }

        // Lógica de Edad
        if (contadorAcciones >= 5) {
            edad++;
            contadorAcciones = 0;
            cout << "\n*** ¡Felicidades! " << nombre << " ha cumplido " << edad << " año(s) ***\n";
        }

        // Límites
        if (hambre < 0) hambre = 0;
        if (hambre >= 100) {
            cout << "\n¡OH NO! " << nombre << " tenia tanta hambre que se fue de casa.\n";
            jugando = false;
        }

        if (felicidad > 5) felicidad = 5;
        if (felicidad < 1) felicidad = 1;

        if (energia > 100) energia = 100;
        if (energia <= 0) {
            cout << "\n" << nombre << " se desmayo del cansancio. Fin del juego.\n";
            jugando = false;
        }

        // Pausa manual (Funciona en todos lados)
        if (jugando && opcion != "4") {
            cout << "\nPresiona la tecla ENTER para continuar...";
            cin.ignore(10000, '\n'); // Limpia la entrada anterior
            cin.get();               // Espera tu ENTER
        }
    }

    cout << "\n--- JUEGO TERMINADO ---\n";
    return 0;
}