```c
int main ()
{
    int a, b, z;
    z = (a > b ? a : b) + (a <= b ? a : b);
    // Si a >  b alors : z = a + b
    // Si a <= b alors : z = b + a
    z = a + b;
    return 0;
}
```