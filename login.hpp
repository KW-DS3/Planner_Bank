#ifndef __LOGIN_HPP__
#define __LOGIN_HPP__

#include "display.hpp"

#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define PERMS 0777

using namespace std;

void signin();
void signup();

#endif
