char *my_strcpy(char *dest, const char *source)
{
    int i = 0;
    while (source[i])
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
