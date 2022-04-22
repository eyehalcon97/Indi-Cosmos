#include <string>
#include <iostream>
#include <chrono>
#include <thread>


#if defined(INDIGO_LINUX) || defined(INDIGO_MACOS)
#include <unistd.h>
#endif
#if defined(INDIGO_WINDOWS)
#include <windows.h>
#pragma warning(disable:4996)
#endif
#include <indigo/indigo_bus.h>
#include <indigo/indigo_client.h>




static bool connected = false;
static int count = 5;
using namespace std;
indigo_property* mipropiedad;

#define CCD_SIMULATOR "CCD Imager Simulator @ localhost"


class Dispositivo{
	private: 
	indigo_client *cliente;
	float t_exposicion;
	public:
	Dispositivo(indigo_client *client){
		cliente=client;
	}
	void cambiarpropiedad(){
		static const char * items[] = { CCD_EXPOSURE_ITEM_NAME };
		static double values[] = { 24.0 };
		indigo_change_number_property(cliente,CCD_SIMULATOR,CCD_EXPOSURE_PROPERTY_NAME,1,items,values);
	}


};



static indigo_result client_attach(indigo_client *client) {
	indigo_log("attached to INDIGO bus...");
	indigo_enumerate_properties(client, &INDIGO_ALL_PROPERTIES);

	return INDIGO_OK;
}

static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message) {
	if (strcmp(property->device, CCD_SIMULATOR))
		return INDIGO_OK;

	if(!strcmp(property->name,CCD_EXPOSURE_PROPERTY_NAME)){
		mipropiedad = property;
	}
	if (!strcmp(property->name, CONNECTION_PROPERTY_NAME)) {
		if (indigo_get_switch(property, CONNECTION_CONNECTED_ITEM_NAME)) {
			connected = true;
			indigo_log("already connected...");
			static const char * items[] = { CCD_EXPOSURE_ITEM_NAME };
			static double values[] = { 3.0 };
			indigo_change_number_property(client, CCD_SIMULATOR, CCD_EXPOSURE_PROPERTY_NAME, 1, items, values);

		} else {
			indigo_device_connect(client, CCD_SIMULATOR);
			return INDIGO_OK;
		}
	}
	if (!strcmp(property->name, "FILE_NAME")) {
		char value[1024] = { 0 };
		static const char * items[] = { "PATH" };
		static const char *values[1];
		values[0] = value;
		for (int i = 0 ; i < 1023; i++)
			value[i] = '0' + i % 10;
		indigo_change_text_property(client, CCD_SIMULATOR, "FILE_NAME" , 1, items, values);
	}
	if (!strcmp(property->name, CCD_IMAGE_PROPERTY_NAME)) {
		if (device->version >= INDIGO_VERSION_2_0)
			indigo_enable_blob(client, property, INDIGO_ENABLE_BLOB_URL);
		else
			indigo_enable_blob(client, property, INDIGO_ENABLE_BLOB_ALSO);
	}
	if (!strcmp(property->name, CCD_IMAGE_FORMAT_PROPERTY_NAME)) {
		static const char * items[] = { CCD_IMAGE_FORMAT_FITS_ITEM_NAME };
		static bool values[] = { true };
		indigo_change_switch_property(client, CCD_SIMULATOR, CCD_IMAGE_FORMAT_PROPERTY_NAME, 1, items, values);
	}
	return INDIGO_OK;
}

static indigo_result client_update_property(indigo_client *client,indigo_device *device,indigo_property *property,const char *message) 
{
	
	if(property == mipropiedad){
		cout << "ES LA MISMA" << endl;
	}
	cout << "xxx" <<  mipropiedad->name << endl; 
	if (!strcmp(property->name, CCD_EXPOSURE_PROPERTY_NAME)) {
		if (property->state == INDIGO_BUSY_STATE) {

			indigo_log("exposure %gs...", property->items[0].number.value);
		} else if (property->state == INDIGO_OK_STATE) {
			indigo_log("exposure done...");
		}
		return INDIGO_OK;
	}
	return INDIGO_OK;
	
}
static indigo_result client_detach(indigo_client *client) {
	indigo_log("detached from INDIGO bus...");
	return INDIGO_OK;
}

static indigo_client client = {
	"Remote server client", 
	false, 
	NULL, 
	INDIGO_OK, 
	INDIGO_VERSION_CURRENT, 
	NULL,
	client_attach,
	client_define_property,
	client_update_property,
	NULL,
	NULL,
	client_detach
};

int main(int argc, const char * argv[]) {
	indigo_main_argc = argc;
	indigo_main_argv = argv;
	int valor;
	bool salir= false;
	
#if defined(INDIGO_WINDOWS)
	freopen("indigo.log", "w", stderr);
#endif

	indigo_set_log_level(INDIGO_LOG_DEBUG);
	indigo_start();
	indigo_server_entry *server;
	indigo_attach_client(&client);
	indigo_connect_server("localhost", "localhost", 7624, &server); // Check correct host name in 2nd arg!!!
	

	while (!(salir)) {
		this_thread::sleep_for(chrono::milliseconds(50));
		
		cout << "Menu:" << endl;
		cout << "Ver: 1" << endl;
		cout << "Cambiar popiedades: 2" << endl;
		cout << "Salir: 9" << endl;
		cout << "Introduce: ";
		cin >> valor;
		if(valor == 1){
			cout << "Las propiedades son: " << endl;
			cout << indigo_enumerate_properties(&client,&INDIGO_ALL_PROPERTIES);
		}
		if(valor == 2){
			cout << "Se ha cambiado la propiedad " << endl;
			Dispositivo dispositivo(&client);	
			dispositivo.cambiarpropiedad();
		}
		if(valor == 9){
			indigo_disconnect_server(server);
			indigo_detach_client(&client);
			this_thread::sleep_for(chrono::milliseconds(50));
			indigo_stop();
			salir=true;
		}
	}

	return 0;
}
