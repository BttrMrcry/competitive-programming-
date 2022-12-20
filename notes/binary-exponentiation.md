# Exponenciación binaria

Es una manera más eficiente de calcular la potencia de un número $a^b$. El algoritmo ingenuo se deduce a partir de la definición común de una potencia, que es la siguiente:

$$ a^b = a \cdot a \dots a$$ 
multiplicando a $a$, $b$ veces.

Este algoritmo tiene una complejidad de $O(b)$ ya que se debe realizar una multiplicación b veces, mientras que que el método de exponenciación binaria tiene una complejdad de $O(\log(n))$.


El truco de la exponenciación binaria es representar el exponente de la operación de mamera binaria y para cada bit que esté en 1, se multiplica su correspondiente potencia. Así por ejemplo:

$$3^5 = 3^{101_b} = 1 \cdot 3^{100_b} \cdot 0 \cdot 3^{010_b} \cdot 1 \cdot 3^{001_b} = 3^4 \cdot 3^1$$

En este caso, como el primer bit, está en 1, se toma en cuenta $3^4$, como el segundo está apagado, no se toma en cuenta, y como el último está bit encendido, se toma en cuenta $3^1$

Entonces, para la implementación del algoritmo, simplemente se hará un ciclo que se repetirá $c$ veces, donde $c$ es el número de dígitos que tiene la representación binaria del exponente. Los bits se leeran de derecha a izquierda utilizando corrimiento a la izquierda y en cada iteración se calculara la potencia par correspondiente y se multiplcará por el resultado acumulado hasta el momento dependiendo de si el bit que el corresponde está encendido o apagado.

La relación entre c y b es la siguiente:

$$c = \lfloor \log_2(n) + 1 \rfloor$$ 

Esto es lo que permite que la complejidad sea logarítma siempre y cuando sepamos el valor de las potencias pares de un número. Esto es muy fácil sacarlo ya que para cualquier potencia par n:

$$b^n = (b^{n-1})^2$$

El código luce como lo siguiente:
```
void solve() {
    int exp; // exponente de la operación
    cin >> exp;
    long long res = 1; //resultado
    long long power = 2; // potencia par actual, al inicio es la base
    while(exp > 0){
        if(exp & 1) // Revisa el primer bit
            res = res * power % MODC; //multiplica por el resultado acomulado si el bit está activado
        power = power * power % MODC; //Calcula la siguiente potencia par
        exp = exp >> 1; //recorre el exponente a la derecha para tener acceso al siguiente bit.
    }
    cout << res << endl;
}
```