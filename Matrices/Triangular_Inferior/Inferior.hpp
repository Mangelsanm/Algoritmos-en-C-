class Inferior {
    private:
    int *matriz;
    int dimension;

    public:
    Inferior(int dimension);
    ~Inferior();
    void setValue(int renglon, int columna, int valor);
    void getValue(int renglon, int columna);
    void display();
};