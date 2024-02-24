int binary_search(const int vec[], int size, int elt)
{
    if (size == 0)
    {
        return -1;
    }
    int low = 0;
    int high = size - 1;
    int middle = 0;
    while (high >= low)
    {
        middle = low + (high - low) / 2;
        if (vec[middle] > elt)
        {
            high = middle - 1;
        }
        else if (vec[middle] < elt)
        {
            low = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}
