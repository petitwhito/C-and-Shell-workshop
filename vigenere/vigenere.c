void cipher(const char *key, const char *msg, char *res)
{
    int key_count = 0;
    char clef;
    int i = 0;
    for (; msg[i]; i++)
    {
        if (key[key_count] == '\0')
        {
            key_count = 0;
        }
        clef = key[key_count];

        if (clef >= 'a' && clef <= 'z')
            clef = clef - 32;

        char c = msg[i];

        if (c >= 'a' && c <= 'z')
        {
            c = c - 32;
        }
        if (c >= 'A' && c <= 'Z')
        {
            c = ((c - 'A') + (clef - 'A')) % 26 + 'A';
            key_count++;
        }
        res[i] = c;
    }
    res[i] = '\0';
}

void decipher(const char *key, const char *msg, char *res)
{
    int key_count = 0;
    char clef;
    int i = 0;
    for (; msg[i]; i++)
    {
        if (key[key_count] == '\0')
        {
            key_count = 0;
        }
        clef = key[key_count];

        if (clef >= 'a' && clef <= 'z')
            clef = clef - 32;

        char c = msg[i];

        if (c >= 'a' && c <= 'z')
        {
            c = c - 32;
        }

        if (c >= 'A' && c <= 'Z')
        {
            c = ((c - 'A') - (clef - 'A'));
            while (c < 0)
            {
                c += 26;
            }
            c = c % 26 + 'A';
            key_count++;
        }
        res[i] = c;
    }
    res[i] = '\0';
}
