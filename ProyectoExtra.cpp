#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <math.h>

using namespace std;

class Persona{
	public:
		char nombre_per[50];
		int edad_per;
		
	protected:
		char direccion_per[100];
		
	public:
		void capturar_per();
		void mostrar_per();
		void buscar_per();
		void modificar_per();
}per[10];

class Empleado{
	public:
		int codigo_e;
		char tiempo[30];
		
	public:
		void capturar_e();
		void mostrar_e();
		void buscar_e();
		void modificar_e();
}e[10];

class Servicios
{
    public:
        int codigo;
        char n_serv[20],descripcion[50];
        float precio;
        int time;

     public:
         void capturar();
         void mostrar();
         void buscar();
         void modificar();
         
}s[10];

class Masajista:public Persona, public Empleado{
    public:
        int id_mas;
        char especialidad[50];
   
    protected:
    char ec[10];
   
    public:
         void capturar_m();
         void mostrar_m();
         void buscar_m();
         void modificar_m();
         
}m[10];

class Producto
{
    public:
    char n_p[100];
    float costo;
    int codigo_p;

public:
    void capturar_p();
    void mostrar_p();
    void buscar_p();
    void modificar_p();

}p[10];

class ProductoRelajantes: public Producto{
	public:
		int codigo_pr;
		char name_producto_r[50];
		int disponible;

	public:
		void capturar_p_r();
    	void mostrar_p_r();
		void buscar_p_r();
	    void modificar_p_r();
}pr[10];

void Masajista::capturar_m(){
	int i;
	system("CLS");
	for(i=0; i<2; i++){
		cout<<"\t\n Id de la masajista"<< i+1 << ":" << endl;
		cin>>m[i].id_mas;
		cout<<"\t\n Especialidad"<< i+1 << ":" << endl;
		cin.getline(m[i].especialidad,50,'\n');
		cin.ignore( 10000, '\n');
		cout<<"\t\n Estado civil"<< i+1 << ":" << endl;
		cin>>m[i].ec;
		cin.ignore( 10000, '\n');
		system("CLS");
	}
}

void Masajista::mostrar_m(){
	int i;
	for(i=0; i<2; i++){
		cout<<"\n\n";
		cout<<"\t\nId de la masajista "<< i+1 << ":" <<m[i].id_mas;
		cout<<"\t\nNombre de la masajista "<< i+1 << ":" <<per[i].nombre_per;
		cout<<"\t\nEdad "<< i+1 << ":" <<per[i].edad_per;
		cout<<"\t\nEspecialidad "<< i+1 << ":" <<m[i].especialidad;
		cout<<"\t\nTiempo que lleva trabajando " << i+1 << ":" <<e[i].tiempo;
	}
}

void Masajista::buscar_m(){
    system("CLS");
    int clave_m;
    int i;
    cout << "\nCodigo de la masajista:" << endl;
    cin >> clave_m;
    for (i=0; i<2; i++){
        if (e[i].codigo_e == clave_m){
            cout << "\t\nCombre de la masajista:" << per[i].nombre_per;
    		cout << "\t\nTiempo que lleva trabajando:" << e[i].tiempo;
    		cout << "\t\nEspecialidad de la masajista:" << m[i].especialidad;
    		cout << "\t\nEdad:" << per[i].edad_per << endl;
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE SERVICIO\n"
                 << endl;
    }
}

void Masajista::modificar_m(){
	system("CLS");
	int clave_m;
	cout << "\nCodigo servicio a modificar:" << endl;
	cin >> clave_m;
	for (int i = 0; i < 2; i++)
	{
        if (e[i].codigo_e == clave_m)
        {
            int opcion;
            cout << "\n¿Que desea modificar?:" << endl;
            cout << "\n1. Nombre\n2. Edad\n3. Tiempo que lleva trabajando\n4. Especialidad" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << "\nNuevo nombre:" << endl;
                cin.getline(per[i].nombre_per,50,'\n');
                cin.ignore(10000,'\n');
                break;
            case 2:
                cout << "\nNueva edad:" << endl;
                cin >> per[i].edad_per;
                break;
            case 3:
                cout << "\nActualice el tiempo de trabajo:" << endl;
                cin.getline(e[i].tiempo,30,'\n');
                cin.ignore(10000, '\n');
                break;
            case 4:
            	cout << "\nEspecialidad:" <<endl;
            	cin.getline(m[i].especialidad,50,'\n');
            	cin.ignore(10000, '\n');
            default:
                cout << "\nOpcion no valida" << endl;
                break;
            }
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE SERVICIO\n"
                 << endl;
    }
}

void Servicios::capturar(){
int i;
system("CLS");
for(i=0; i<2; i++){
cout<<"\t\n Codigo Servicio " << i+1 << ":" << endl;
cin>>s[i].codigo;
cin.ignore( 10000, '\n');
cout<<"\t\n Nombre Servicio " << i+1 << ":" << endl;
cin.getline(s[i].n_serv,20,'\n');
cin.ignore( 10000, '\n');
cout<<"\t\n Descripcion Servicio "<< i+1 << ":" << endl;
cin.getline(s[i].descripcion,50,'\n');
cin.ignore( 10000, '\n');
cout<<"\t\n Precio "<< i+1 << ":" << endl;
cin>>s[i].precio;
cin.ignore( 10000, '\n');
cout<<"\t\n Duracion "<< i+1 << ":" << endl;
cin>>s[i].time;
cin.ignore( 10000, '\n');
system("CLS");
}
}

void Servicios::mostrar(){
int i;
for(i=0; i<2; i++){
cout<<"\n\n";
cout<<"\t\nCodigo Servicio " << i+1 << ":" <<s[i].codigo;
cout<<"\t\nNombre Servicio "<<i+1 << ":" <<s[i].n_serv;
cout<<"\t\nDescripcion Servicio "<<i+1 << ":" <<s[i].descripcion;
cout<<"\t\nPrecio "<<i+1 << ":" <<s[i].precio;
cout<<"\t\nDuracion "<<i+1 << ":" <<s[i].time;
}
}

void Servicios::buscar(){
system("CLS");
int clave;
int i;
cout<<"\nCodigo servicio:"<<endl;
cin>>clave;
for(i=0; i<10; i++){
if(s[i].codigo==clave){
cout<<"\nCodigo Servicio:"<<s[i].codigo;
cout<<"\t\nNombre Servicio:" <<s[i].n_serv;
cout<<"\t\nDescripcion Servicio:"<<s[i].descripcion;
cout<<"\t\nPrecio:"<<s[i].precio;
cout<<"\t\nDuracion:"<<s[i].time;
break;
}
else if(i == 9) cout<<"NO EXISTE SERVICIO\n"<<endl;
}
}

void Servicios::modificar()
{
    system("CLS");
    int clave;
    int i;
    cout << "\nCodigo servicio a modificar:" << endl;
    cin >> clave;
    for (i=0; i<10; i++){
        if (s[i].codigo == clave){
            int opcion;
            cout << "\n¿Que desea modificar?:" << endl;
            cout << "\n1. Nombre\n2. Descripcion\n3. Precio\n4. Duracion\n" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << "\nNuevo nombre:" << endl;
                cin >> s[i].n_serv;
                break;
            case 2:
                cout << "\nNueva descripcion:" << endl;
                cin >> s[i].descripcion;
                break;
            case 3:
                cout << "\nNuevo precio:" << endl;
                cin >> s[i].precio;
                break;
            case 4:
                cout << "\nNueva duracion:" << endl;
                cin >> s[i].time;
                break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
            }
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE SERVICIO\n"
                 << endl;
    }
}

void Producto::capturar_p()
{
int i;
system("CLS");
    for (i=0; i<10; i++){
        cout << "\t\nCodigo del producto " << i+1 << ":" << endl;
        cin >> p[i].codigo_p;
        cout << "\t\nNombre del producto " << i+1 << ":" << endl;
        cin >> p[i].n_p;
        cout << "\t\nPrecio del producto " << i+1 << ":" << endl;
        cin >> p[i].costo;
        system("CLS");
    }
}

void Producto::mostrar_p()
{
int i;
    for (i=0; i<10; i++){
        cout<<"\n\n";
        cout << "\t\nCodigo del producto " << i + 1 << ":" << p[i].codigo_p;
        cout << "\t\nNombre del producto " << i + 1 << ":" << p[i].n_p;
        cout << "\t\nPrecio " << i + 1 << ":" << p[i].costo;
    }
}

void Producto::buscar_p()
{
    system("CLS");
    int clave_p;
    int i;
    cout << "\nCodigo producto:" << endl;
    cin >> clave_p;
    for (i=0; i<10; i++){
        if (p[i].codigo_p == clave_p){
            cout << "\t\nCodigo del producto:" << p[i].codigo_p;
    cout << "\t\n Nombre del producto:" << p[i].n_p;
    cout << "\t\nPrecio:" << p[i].costo << endl;
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE PRODUCTO\n"
                 << endl;
    }
}

void Producto::modificar_p()
{
    system("CLS");
    int clave_p;
    int i;
    cout << "\nCodigo producto a modificar:" << endl;
    cin >> clave_p;
    for (i=0; i<10; i++){
        if (p[i].codigo_p == clave_p){
            int opcion;
            cout << "\nQue desea modificar:" << endl;
            cout << "\n1. Nombre\n2. Precio\n" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << "\nNuevo nombre:" << endl;
                cin >> p[i].n_p;
                break;
            case 2:
                cout << "\nNuevo precio:" << endl;
                cin >> p[i].costo;
                break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
            }
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE PRODUCTO\n"
                 << endl;
    }
}

void ProductoRelajantes::capturar_p_r(){
int i;
system("CLS");
for (i=0; i<10; i++){
cout << "\t\nCodigo del producto relajante " << i+1 << ":" <<endl;
cin>>pr[i].codigo_pr;
        cout << "\t\nNombre del producto " << i+1 << ":" << endl;
        cin.getline(pr[i].name_producto_r,50, '\n');
cin.ignore( 10000, '\n');
        cout << "\t\n Disponibilidad 1. Para Si   2. Para No:" << endl;
        cin >> pr[i].disponible;
        system("CLS");
    }
}

void ProductoRelajantes::mostrar_p_r(){
int i;
    for (i=0; i<10; i++){
        cout<<"\n\n";
        cout << "\t\nCodigo del producto " << i + 1 << ":" << pr[i].codigo_pr;
        cout << "\t\nNombre del producto " << i + 1 << ":" << pr[i].name_producto_r;
        cout << "\t\nDisponible 1.Si 2.No " << i + 1 << ":" << pr[i].disponible;
        cout << "\t\nPrecio del producto original registrado: " << p[i].costo;
    }
}

void ProductoRelajantes::buscar_p_r(){
system("CLS");
    int clave_p;
    int i;
    cout << "\nCódigo del producto relajante:" << endl;
    cin >> clave_p;
    for (i=0; i<10; i++){
        if (pr[i].codigo_pr == clave_p){
    cout << "\t\n Nombre del producto:" << pr[i].name_producto_r;
    cout << "\t\n Disponible:" << pr[i].disponible << endl;
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE PRODUCTO\n"
                 << endl;
    }
}

void ProductoRelajantes::modificar_p_r(){
system("CLS");
    char clave_p;
    int i;
    cout << "\nCodigo del producto relajante a modificar:" << endl;
    cin >> clave_p;
    for (i=0; i<10; i++){
        if (pr[i].codigo_pr == clave_p){
            int opcion;
            cout << "\nQue desea modificar:" << endl;
            cout << "\n1. Nombre\n2. Disponibilidad\n" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << "\nNuevo nombre:" << endl;
                cin.getline(pr[i].name_producto_r, 50,'\n');
                cin.ignore( 10000, '\n');
                break;
            case 2:
                cout << "\nNuevo precio:" << endl;
                cin >> pr[i].disponible;
                break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
            }
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE PRODUCTO\n"
                 << endl;
    }
}

void Persona::capturar_per(){
	int i;
	system("CLS");
	for(i=0; i<2; i++){
		cout<<"\t\n Nombre de la persona "<< i+1 << ":" << endl;
		cin.getline(per[i].nombre_per,50,'\n');
		cin.ignore( 10000, '\n');
		cout<<"\t\n Edad de la persona "<< i+1 << ":" << endl;
		cin>>per[i].edad_per;
		cout<<"\t\n Direccion de la persona "<< i+1 << ":" << endl;
		cin.getline(per[i].direccion_per,100,'\n');
		cin.ignore( 10000, '\n');
		system("CLS");
	}
}

void Persona::mostrar_per(){
	int i;
	for(i=0; i<2; i++){
		cout<<"\n\n";
		cout<<"\t\nNombre de la persona registrada "<< i+1 << ":" <<per[i].nombre_per;
		cout<<"\t\nEdad de la persona "<< i+1 << ":" <<per[i].edad_per;
	}
}

void Persona::buscar_per(){
    system("CLS");
    char clave_m[50];
    int i;
    cout << "\nNombre de la persona:" << endl;
    cin.getline(clave_m,50,'\n');
    for (i=0; i<2; i++){
        if (per[i].nombre_per == clave_m){
            cout << "\t\nNombre de la persona:" << per[i].nombre_per;
    		cout << "\t\Edad de la persona:" << per[i].edad_per;
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE SERVICIO\n"<< endl;
    }
}

void Persona::modificar_per(){
	system("CLS");
    char clave_m[50];
    int i;
    cout << "\nNombre de la persona:\n" << endl;
    cin.getline(clave_m,50,'\n');
    for (i=0; i<2; i++)
    {
        if (per[i].nombre_per == clave_m)
        {
            int opcion;
            cout << "\n¿Que desea modificar?:" << endl;
            cout << "\n1. Nombre de la persona\n2. Edad de la persona\n" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << "\nNuevo nombre:" << endl;
                cin.getline(per[i].nombre_per,50,'\n');
                cin.ignore( 10000, '\n');
                break;
            case 2:
                cout << "\nNueva edad:" << endl;
                cin >> per[i].edad_per;
                break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
            }
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE ESA OPCION\n"<< endl;
    }
}

void Empleado::capturar_e(){
	int i;
	system("CLS");
	for(i=0; i<2; i++){
		cout<<"\t\n Codigo del empleado "<< i+1 << ":" << endl;
		cin>>e[i].codigo_e;
		cout<<"\t\n Tiempo que lleva trabajando "<< i+1 << ":" << endl;
		cin.getline(e[i].tiempo,30,'\n');
		cin.ignore( 10000, '\n');
		system("CLS");
	}
}

void Empleado::mostrar_e(){
	int i;
	for(i=0; i<2; i++){
		cout<<"\n\n";
		cout<<"\t\n Codigo del empleado "<< i+1 << ":" <<e[i].codigo_e;
		cout<<"\t\n Tiempo que lleva trabajando "<< i+1 << ":" <<e[i].tiempo;
	}
}

void Empleado::buscar_e(){
    system("CLS");
    int clave_m;
    int i;
    cout << "\n Codigo del empleado:" << endl;
    cin >> clave_m;
    for (i=0; i<2; i++){
        if (e[i].codigo_e == clave_m){
            cout << "\t\nCodigo del empleado:" << e[i].codigo_e;
    		cout << "\t\Tiempo que lleva trabajando:" << e[i].tiempo;
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE SERVICIO\n"<< endl;
    }
}

void Empleado::modificar_e(){
	system("CLS");
    int clave_m;
    int i;
    cout << "\nCodigo del empleado:\n" << endl;
    cin >> clave_m;
    for (i=0; i<2; i++)
    {
        if (e[i].codigo_e == clave_m)
        {
            int opcion;
            cout << "\n¿Que desea modificar?:" << endl;
            cout << "\n1. Codigo del empleado\n2. Tiempo que lleva trabajando\n" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << "\nNuevo codigo:" << endl;
                cin>>e[i].codigo_e;
                break;
            case 2:
                cout << "\nActualiza el tiempo:" << endl;
                cin.getline(e[i].tiempo,30,'\n');
                cin.ignore(10000, '\n');
                break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
            }
            break;
        }
        else if (i == 9)
            cout << "NO EXISTE ESA OPCION\n"<< endl;
    }
}

class NotaVenta{
	public:
		int precio, descuento, cantidad1, cantidad2, total, final;
	
	public:
		void Llenado_datos();
		void Calculo_total();
		void Mostrar_total();
}nv[10];

void NotaVenta::Llenado_datos(){
	int f;
	cout << "Precio del servicio (incluye el pago de la masajista):\n " << endl;
	cin >> precio;
	cout << "¿Compraste un producto? 1.Para SI	2.Para NO \n" << endl;
	cin >> f;
	if(f==1){
		cout << "Precio del producto :" << endl;
		cin >> cantidad1;
	}
	else if(f==2)
	cantidad1 = 1;
}

void NotaVenta::Calculo_total(){
	total = precio*cantidad1;
	descuento = total*.10;
	final = total - descuento;
}

void NotaVenta::Mostrar_total(){
	cout << "El monto total a pagar es (con descuento del 10%):\n" << final << endl;
}

class Cliente{
	protected:
		int tipo_cliente;
	public:
	 	char nombre[100];
}c[10];

class Individual_cliente : public Cliente{
	private:
		char curp[30];
	public:
		char servicio[50];
		void llenar_ic();
		void mostrar_ic();
}ic[10];

class Empresa_cliente : public Cliente{
	private:
		char _curp[30];
	public:
		char _servicio[50];
		char _nombre[100];
		void llenar_ec();
		void mostrar_ec();
}ec[10];

void Individual_cliente::llenar_ic(){
	cout << "Dame el nombre del cliente :" << endl;
	cin >> nombre;
	cout << "Cual es la curp de este cliente? :" << endl;
	cin >> curp;
	cout << "A que servicio a venido? :" << endl;
	cin >> servicio;
}

void Empresa_cliente::llenar_ec(){
	cout << "Dame el nombre del cliente :" << endl;
	cin >> _nombre;
	cout << "Cual es la curp de este cliente? :" << endl;
	cin >> _curp;
	cout << "A que servicio a venido? :" << endl;
	cin >> _servicio;
}

void Empresa_cliente::mostrar_ec(){
	cout << "Nombre :" << _nombre;
	cout << "Servicio :" << _servicio;
}

void Individual_cliente::mostrar_ic(){
	cout << "Nombre :" << nombre;
	cout << "Servicio :" << servicio;
}

int main() {
int op,x,u,y;
do{
cout<<"\n\t\t MONTE COXALA SPA \n\n"<<endl;
cout<<"\n\t\t Proyecto EXTRA \n\n"<<endl;
cout<<"\t1.Capturar\n \t2.Mostrar\n \t3.Buscar\n \t4.Modificar\n \t5.Nota de Venta\n \t6.Salir\n "<<endl;
cin>>op;
if(op==1){
	int clase;
			cout << "\n1.Persona\n2. Empleado\n3. Servicios\n4. Masajista\n5. Producto\n6. Producto Relajante\n7. Cliente\n" << endl;
			cin >> clase;
            switch (clase){
            	case 1:
                per[0].capturar_per();
                break;
            case 2:
                e[0].capturar_e();
                break;
            case 3:
                s[0].capturar();
                break;
            case 4:
            	m[0].capturar_m();
                break;
            case 5:
                p[0].capturar_p();
                break;
            case 6:
                pr[0].capturar_p_r();
                break;
            case 7:
            	cout << "El cliente pertenece a una empresa? 1 para si	2 para no:" << endl;
    			cin >> u;
    			if(u==1)
    			ec[0].llenar_ec();
    			else if(u==2)
    			ic[0].llenar_ic();
    			break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
			}
}
else if(op==2){
	int clase;
			cout << "\n1.Persona\n2. Empleado\n3. Servicios\n4. Masajista\n5. Producto\n6. Producto Relajante\n7. Cliente\n" << endl;
			cin >> clase;
            switch (clase){
            	case 1:
                per[0].mostrar_per();
                break;
            case 2:
                e[0].mostrar_e();
                break;
            case 3:
                s[0].mostrar();
                break;
            case 4:
            	m[0].mostrar_m();
                break;
            case 5:
                p[0].mostrar_p();
                break;
            case 6:
                pr[0].mostrar_p_r();
                break;
            case 7:
            	cout << "El cliente pertenece a una empresa? 1 para si 2 para no :" << endl;
				cin >> y;
				if(y==1)
				ec[0].mostrar_ec();
				if(y==2)
				ic[0].mostrar_ic();
				break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
			}
}
else if(op==3){
	int clase;
			cout << "\n1.Persona\n2. Empleado\n3. Servicios\n4. Masajista\n5. Producto\n6. Producto Relajante\n" << endl;
			cin >> clase;
            switch (clase){
            	case 1:
                per[0].buscar_per();
                break;
            case 2:
                e[0].buscar_e();
                break;
            case 3:
                s[0].buscar();
                break;
            case 4:
            	m[0].buscar_m();
                break;
            case 5:
                p[0].buscar_p();
                break;
            case 6:
                pr[0].buscar_p_r();
                break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
			}
}
else if(op==4){
	int clase;
			cout << "\n1.Persona\n2. Empleado\n3. Servicios\n4. Masajista\n5. Producto\n6. Producto Relajante\n" << endl;
			cin >> clase;
            switch (clase){
            	case 1:
                per[0].modificar_per();
                break;
            case 2:
                e[0].modificar_e();
                break;
            case 3:
                s[0].modificar();
                break;
            case 4:
            	m[0].modificar_m();
                break;
            case 5:
                p[0].modificar_p();
                break;
            case 6:
                pr[0].modificar_p_r();
                break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
			}
}
else if(op==5){
	int clase;
			cout << "\n1.Llenado de datos\n2. Hacer calculos\n3. Mostrar monto a pagar\n" << endl;
			cin >> clase;
            switch (clase){
            	case 1:
                nv[0].Llenado_datos();
                break;
            case 2:
                nv[0].Calculo_total();
                break;
            case 3:
                nv[0].Mostrar_total();
                break;
            default:
                cout << "\nOpcion no valida" << endl;
                break;
			}
}
else if(op==6)
break;

else
cout<<"\nEsa opcion no existe"<<endl;
cout<<"\nDesea regresar al menu: 1.Si 2.No"<<endl;
cin>>x;
system("CLS");

}while(x==1);

}
