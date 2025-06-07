#pragma once
#include "core/Request.h"
#include "core/Response.h"
#include "server/RequestParser.h"
#include "server/Router.h"
#include "server/AuthMiddleware.h"

class TCPServer
{
    int port;

public:
    TCPServer(int p) : port(p) {}
    void run();
};