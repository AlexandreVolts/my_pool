void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    *div = b == 0 ? 42 : a / b;
}
void mul_div_short(int *a, int *b)
{
    int cpy_a = *a;
    int cpy_b = *b;

    *a = cpy_a * cpy_b;
    *b = cpy_b == 0 ? 42 : cpy_a / cpy_b;
}