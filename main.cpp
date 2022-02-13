#include "console.h"

int main() {
    Console* application = new Console();

    application->run();

    application->~Console();

    return 0;
}