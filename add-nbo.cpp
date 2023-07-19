#include <stdio.h>
#include <stdint.h>

uint32_t convertToBigEndian(uint8_t buffer[4]) {
    return ((uint32_t)buffer[0] << 24) |
           ((uint32_t)buffer[1] << 16) |
           ((uint32_t)buffer[2] << 8) |
           (uint32_t)buffer[3];
}

int main() {
    const char* file1 = "thousand.bin";
    const char* file2 = "five-hundred.bin";

    FILE* file1ptr = fopen(file1, "rb");
    FILE* file2ptr = fopen(file2, "rb");


    uint8_t buffer1[4];
    uint8_t buffer2[4];

    fclose(file1ptr);
    fclose(file2ptr);

    uint32_t value1 = convertToBigEndian(buffer1);
    uint32_t value2 = convertToBigEndian(buffer2);
    uint32_t sum = value1 + value2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", value1, value1, value2, value2, sum, sum);

    return 0;
}
