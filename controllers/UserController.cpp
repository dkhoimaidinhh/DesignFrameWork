#include "UserController.h"

Response UserController::handle(const Request &req)
{
    return {200, "Welcome, user VOTIEN!"};
}