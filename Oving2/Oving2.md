## Oppgave 1
### a)

    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    # &i = adressen til i
    # &j = adressen til j
    # *p = referanse til i = 3
    # &*p =  p = adressen til i
    # *q = referanse til j = 5
    # &*q = q = adressen til j

Se ``1a.cpp``.

### b)

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << *p << " " << *q << endl;

*p settes lik 7, *q settes lik 5 + 4 = 9, så settes *q like *p + 1 = 8. Så settes adressen til *p lik adressen til *q (p = &*p), som fører til at begge får verdien til *q = 8 ('8 8\n' skrives ut)

## Oppgave 2

    char *line = nullptr;   // eller char *line = 0;
    strcpy(line, "Dette er en tekst");

char *line = nullptr; // char *line = 0; initialiserer pekeren *line til nullptr, en adresse som ikke brukes. Prøver man å tildele en verdi til denne pekeren uten å initialisere den til en ekte adresse vil man få en stack-feilmelding når man kjører programmet.

### Oppgave 3

    char text[5];
    char *pointer = text;
    char search_for = 'e';
    cin >> text;

    while (*pointer != search_for) {
        *pointer = search_for;
        pointer++;
    }

- koden endrer alle chars i text fram til 'e' fram til den finner en 'e' bed å iterere pointerverdien fram.
- text blir initialisert som et array med lengde 5, men det er ingen begrensning på hvor mye man kan skrive inn, så kan ende opp med å overskrive andre felt.
- hvisden ikke finner noen 'e' vil loopen fortsette å iterere pointeren utover og utenfor text-arrayet, og potensielt ende opp med rare char-vardier.

### Oppgave 4

    int a = 5;      //
    int &b;         // Må fortelle hvilken variabel den refererer
    int *c;         //
    c = &b;         //
    *a = *b + *c;   // a og b er ikke pointere så kan ikke refereres til som så
                    // Kan heller ikke summere sammen *int og int
    &b = 2;         // &b er referanseadressen, verdien ligger i b

Forslag til endring som kompilerer i ``4.cpp``

### Oppgave 5

Se filen ``5.cpp``.

### Oppgave 6

Se filen ``6.cpp``.