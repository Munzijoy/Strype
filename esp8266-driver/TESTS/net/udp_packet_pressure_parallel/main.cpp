#include "mbed.h"
#include "ESP8266Interface.h"
#include "UDPSocket.h"
#include "greentea-client/test_env.h"
#include "unity/unity.h"
#include "utest.h"


int main() {
    return !Harness::run(specification);
}


