class Diagonal {
    private:
    int *matriz;
    int dimension;

    public:
    Diagonal(int dimension);
    ~Diagonal();
    void setValue(int renglon, int columna, int valor);
    void getValue(int renglon, int columna);
    void mostrar();
};