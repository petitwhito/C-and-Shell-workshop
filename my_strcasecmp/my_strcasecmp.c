int my_strcasecmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 >= 'A' && c1 <= 'Z')
        {
            c1 = c1 + 'a' - 'A';
        }
        if (c2 >= 'A' && c2 <= 'Z')
        {
            c2 = c2 + 'a' - 'A';
        }
        if (c1 != c2)
        {
            return c1 - c2;
        }
        i++;
    }
    return s1[i] - s2[i];
}
