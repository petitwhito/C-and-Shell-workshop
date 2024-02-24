void rot_x(char *s, int x)
{
    if (!s)
    {
        return;
    }
    while (x < 0)
    {
        x += 26;
    }
    for (int i = 0; s[i]; i++)
    {
        char tmp = s[i];
        if (tmp >= 'a' && tmp <= 'z')
        {
            tmp = (tmp - 'a' + x) % 26 + 'a';
        }
        else if (tmp >= 'A' && tmp <= 'Z')
        {
            tmp = (tmp - 'A' + x) % 26 + 'A';
        }
        s[i] = tmp;
    }
}
