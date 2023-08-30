template <typename T>
Array<T>::Array() {
    _array = new T[0];
    _n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
    _n = n;
}

template <typename T>
Array<T>::Array(const Array &copy) {
    _array = new T[copy._n];
    _n = copy._n;
    for (unsigned int i = 0; i < copy._n; i++) {
        _array[i] = copy._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &copy) {
    if (this != &copy) {
        delete[] _array;
        _array = new T[copy._n];
        _n = copy._n;
        for (unsigned int i = 0; i < copy._n; i++) {
            _array[i] = copy._array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= _n) {
        throw Array::OutOfLimitsException();
    }
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _n;
}

template <typename T>
const char* Array<T>::OutOfLimitsException::what() const throw() {
    return "Index out of limits";
}