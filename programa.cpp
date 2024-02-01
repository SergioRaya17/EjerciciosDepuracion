#include <iostream>
#include <string>
#include <string.h>

using namespace std;

// Estructura articulo
struct articulo
{
  char codigo[20];
  char nombre[20];
  char categoria[20];
  float precio;
  int margen;
  int cantidad;
};

void inicializarVector (struct articulo []);
int insertarArticulo (struct articulo[], int);
int buscarArticulo (struct articulo articulos[], int, char []);

int main ()
{
  // Opci�n del men� principal (por defecto: salir)
  int opcion = 4;

  // C�digo del art�culo que se va a buscar, posici�n (si se encuentra) y cantidad a descontar
  char codigo [20];
  int posicion = 0, cantidad = 0;

  // Registros insertados en el vector
  int registros = 0;

  // Vector que almacena los registros de los art�culos
  struct articulo articulos[25];

  // Se inicializa el vector de registros de art�culos
  inicializarVector(articulos);

  // Se muestra el men� al usuario
  do
  {
    cout << "SuperPrecios! - Gestion de almacen" << endl;
    cout << " Opcion 1) Insertar articulo" << endl;
    cout << " Opcion 2) Descontar articulo" << endl;
    cout << " Opcion 3) Imprimir inventario" << endl;
    cout << " Opcion 4) Salir de la aplicacion" << endl;
    cout << endl;
    cout << " Introduce una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
      case 1:
      {
        // Insertar art�culo
        registros = insertarArticulo(articulos, registros);
        break;
      }

      case 2:
      {
        // Descontar art�culo
        cout << endl;
        cout << "Descontar articulo: " << endl;
        cout << "Codigo a buscar: ";
        getchar();
        cin.getline(codigo, 20);
        cout << "Cantidad a descontar: ";
        cin >> cantidad;

        // Se busca el art�culo
        posicion = buscarArticulo (articulos, registros, codigo);

        if (posicion != -1)
        {
          // Se ha encontrado el art�culo
          // Se descuenta la cantidad siempre que la cantidad sea correcta
          if (articulos[posicion].cantidad >= cantidad)
          {
            cout << endl;
            cout << "*** Registro encontrado ***" << endl;
            cout << "*** Se han descontado " << cantidad << " unidades ***" << endl;
            cout << "Codigo: " << articulos[posicion].codigo << endl;
            cout << "Nombre: " << articulos[posicion].nombre << endl;
            cout << "Categoria: " << articulos[posicion].categoria << endl;
            cout << "Precio: " << articulos[posicion].precio << endl;
            cout << "Margen: " << articulos[posicion].margen << endl;
            cout << "Cantidad: " << articulos[posicion].cantidad << endl;
            cout << endl;
          }
          else
          {
            cout << endl << "INFO: el articulo " << articulos[posicion].codigo << " no tiene suficientes unidades" << endl << endl;
          }

        }
        else
        {
          cout << endl << "INFO: registro no encontrado" << endl << endl;
        }

        break;
      }

      case 3:
      {
        cout << endl;
        cout << "*** Inventario ***" << endl;

        // Se imprime informe
        cout << "Codigo \t Nombre \t Categoria \t Precio \t Margen \t Cantidad\t PVP" << endl;

        float inventario = 0.0f;

        for (int i = 0; i < registros; i++)
        {
          // Se calcula el PVP y el coste de inventario del art�culo
          float pvp = (articulos[i].precio + ((articulos[i].precio*articulos[i].margen))) * 1.10f;
          inventario += articulos[i].precio * articulos[i].cantidad;

          cout << articulos[i].codigo << "\t";
          cout << articulos[i].nombre << "\t";
          cout << articulos[i].categoria << "\t";
          cout << articulos[i].precio << "�\t" ;
          cout << articulos[i].margen << "\t";
          cout << articulos[i].cantidad << "\t";
          cout << pvp << endl;
        }

        // Se muestra el importe total del inventario
        cout << endl << "Importe total del inventario: ";
        cout << inventario << "�";
        cout << endl << endl;

        break;
      }

      case 4:
        break;

      default:
        break;
    }

  } while (opcion != 4);


  return 1;
}

// Inicializa los datos del vector
void inicializarVector (struct articulo articulos[25])
{
  for (int i = 0; i < 25; i++)
  {
    // Se graban los valores por defecto en cada registro
    articulos[i].codigo[0] = '\0';
    articulos[i].nombre[0] = '\0';
    articulos[i].categoria[0] = '\0';
    articulos[i].precio = 0.0f;
    articulos[i].margen = 0;
    articulos[i].cantidad = 0;
  }
}

// Inserta un art�culo en el vector
int insertarArticulo (struct articulo articulos[25], int registros)
{
  // Comprueba si hay espacio disponible
  if(registros < 25)
  {
    // Se piden los datos al usuario y se guardan en el registro
    cout << endl;
    cout << "Insertar articulo: " << endl;
    cout << "Codigo: ";
    getchar();
    cin.getline(articulos[registros].codigo, 20);
    cout << "Nombre: ";
    cin.getline(articulos[registros].nombre, 20);
    cout << "Categoria: ";
    cin.getline(articulos[registros].categoria, 20);
    cout << "Precio: ";
    cin >> articulos[registros].precio;
    cout << "Margen: ";
    cin >> articulos[registros].margen;
    cout << "Cantidad: ";
    cin >> articulos[registros].cantidad;

    // Se suma 1 al vector de registros
    registros++;
    cout << endl << "El vector tiene " << registros << " registros" << endl << endl;

    return registros;
  }
  else
  {
    cout << endl << "INFO: no hay espacio disponible en el vector" << endl << endl;
    return registros;
  }
}

// Busca un art�culo en el vector
int buscarArticulo (struct articulo articulos[25], int registros, char codigo[20])
{
  for (int i = 0; i < registros; i++)
  {
    if (strcmp(articulos[i].codigo, codigo) == 0)
      return i;
  }

  return -1;
}
