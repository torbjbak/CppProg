const double pi = 3.141592;

class Circle {
    public:
        Circle(double radius_);                 // Stor C i klassenavnet
        int get_area() const;
        double get_circumference() const;
    private:                                    // Kolon etter private
        double radius;
};                                              // Semikolon etter klassedeklarasjonen

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) :                // Fjern public foran klassenavn
    radius(radius_) {}                          // Fjernet understrek så radius stemmer med 
                                                // felt-navnet i klassen og la til understrek 
                                                // bak argumentet så det stemmer          

int Circle::get_area() const {                  // Setter så returnerer const så det stemmer 
    return pi * radius * radius;                // med klassedeklarasjonen
}

double Circle::get_circumference() const {      // Spesifiserer returtype double
    return 2.0 * pi * radius;                   // Returnerer svaret direkte i stedet
    // return circumference;                    // for å lage variabel
}
