unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned pos = start;
    for (unsigned i = start; i < size; i++)
    {
        if (arr[i] < arr[pos])
        {
            pos = i;
        }
    }
    return pos;
}

void selection_sort(int arr[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        unsigned min = array_min(arr, i, size);
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
