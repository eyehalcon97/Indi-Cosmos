// Copyright (c) 2020 CloudMakers, s. r. o. & Rumen G.Bogdanovski
// All rights reserved.
//
// You can use this software under the terms of 'INDIGO Astronomy
// open-source license' (see LICENSE.md).
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHORS 'AS IS' AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// version history
// 2.0 by Peter Polakovic <peter.polakovic@cloudmakers.eu>
//      & Rumen G.Bogdanovski <rumen@skyarchive.org>


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
string CCD_SIMULATOR = "CCD Imager Simulator @ localhost";
static indigo_result client_attach(indigo_client *client) {
	indigo_log("attached to INDIGO bus...");
	indigo_enumerate_properties(client, &INDIGO_ALL_PROPERTIES);

	return INDIGO_OK;
}

static indigo_result client_define_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message) {

	if (property->device == CCD_SIMULATOR){

	}

	return INDIGO_OK;
}

static indigo_result client_update_property(indigo_client *client, indigo_device *device, indigo_property *property, const char *message) {



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
	string valor;
	bool salir= false;
#if defined(INDIGO_WINDOWS)
	freopen("indigo.log", "w", stderr);
#endif

	indigo_set_log_level(INDIGO_LOG_INFO);
	indigo_start();

	indigo_server_entry *server;
	indigo_attach_client(&client);
	indigo_connect_server("localhost", "localhost", 7624, &server); // Check correct host name in 2nd arg!!!
	
	
	cout.clear();

	while (!(salir)) {
		this_thread::sleep_for(chrono::milliseconds(50));
		cout << ("Menu:");
		cin >> valor;
		if(valor == "salir"){
			indigo_disconnect_server(server);
			indigo_detach_client(&client);
			this_thread::sleep_for(chrono::milliseconds(50));
			indigo_stop();
			salir=true;
		}
	}




	return 0;
}
