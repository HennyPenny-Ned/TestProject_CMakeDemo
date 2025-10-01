#include "readTemp.h"
#include "procTemp.h"
#include "displayTemp.h"

int main(void) {
    float temp = readTemp();
    float processed = procTemp(temp);
    displayTemp(processed);

    while (1); // Infinite loop for embedded systems
    return 0;
}
