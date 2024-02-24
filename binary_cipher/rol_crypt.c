#include <stddef.h>

#include "binary_cipher.h"

void my_rol_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    unsigned char *val_data = data;
    const unsigned char *key_data = key;
    size_t count = 0;
    for (size_t i = 0; i < data_len; i++)
    {
        if (count == key_len)
            count = 0;
        val_data[i] = val_data[i] + key_data[count];
        count++;
    }
}
