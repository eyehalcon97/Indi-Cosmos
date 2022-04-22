#ifndef dispositivo
#define dispositivo

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


class Dispositivo{
    private:
    indigo_client *cliente;
    public:
    Dispositivo(indigo_client *client);
};

#endif