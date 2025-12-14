#ifndef NODEPP_BSOCKET
#define NODEPP_BSOCKET

/*────────────────────────────────────────────────────────────────────────────*/

#if   _KERNEL_ == NODEPP_KERNEL_WINDOWS
    #include <nodepp/dns.h>
    #include <nodepp/poll.h>
    #include <nodepp/socket.h>
    #include "windows/bluetooth.h"
#elif _KERNEL_ == NODEPP_KERNEL_POSIX
    #include <nodepp/dns.h>
    #include <nodepp/poll.h>
    #include <nodepp/socket.h>
    #include "posix/bluetooth.h"
#else
    #error "This OS Does not support bluetooth.h"
#endif

/*────────────────────────────────────────────────────────────────────────────*/

#endif
