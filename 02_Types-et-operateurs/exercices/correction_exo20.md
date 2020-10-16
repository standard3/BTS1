```c
int main ()
{
    int a = 5, b = 5, somme;
    somme = a + b;  
    // a= 5   b= 5   somme= 10
    somme = a++ + b;  
    // a= 6   b= 5   somme= 10
    somme = ++a + b;    
    // a= 7   b= 5   somme= 12
    somme = --a + b;    
    // a= 6   b= 5   somme= 11
    somme = a-- + b--;    
    // a= 5   b= 4   somme= 11
    return 0;
}
```