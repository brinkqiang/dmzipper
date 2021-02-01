
#include "dmzipper.h"

int main( int argc, char* argv[] ) {

    Idmzipper* module = dmzipperGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
