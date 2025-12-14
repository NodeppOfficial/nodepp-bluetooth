#include <nodepp/nodepp.h>
#include <bluetooth/bth.h>

using namespace nodepp;

void onMain() {

    bluetooth_t bth;
   
    for( auto x:  bth.get_devices() ){
         console::log( "->", x );
    }

}