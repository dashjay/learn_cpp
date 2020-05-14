#include "plog/Log.h"
#include <iostream>

int main() {
    plog::init(plog::debug, "Logfile.txt");
    LOGD << "main() called";
    return 0 ;}
