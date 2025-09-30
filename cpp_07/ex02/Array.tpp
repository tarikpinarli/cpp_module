// ========================== Constructors ==========================
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(0)
{
    allocate_and_value_init(n);
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0)
{
    copy_from(other);
}

// =========================== Destructor ===========================
template <typename T>
Array<T>::~Array()
{
    destroy();
}

// ========================== Assignment ============================
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        destroy();
        copy_from(other);
    }
    return *this;
}

// ========================= Element access =========================
template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= _size)
        throw std::out_of_range("Array: index out of range");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= _size)
        throw std::out_of_range("Array: index out of range");
    return _data[index];
}

// ============================ Observers ===========================
template <typename T>
size_t Array<T>::size() const
{
    return _size;
}

// ============================ Utilities ===========================
template <typename T>
void Array<T>::allocate_and_value_init(size_t n)
{
    if (n == 0)
    {
        this->_data = NULL;
        this->_size = 0;
        return;
    }
    _data = new T[n]();
    _size = n;
}

template <typename T>
void Array<T>::copy_from(const Array& other)
{
    allocate_and_value_init(other._size);
    for (size_t i = 0; i < _size; ++i)
        _data[i] = other._data[i];
}

template <typename T>
void Array<T>::destroy()
{
    delete[] _data;
    _data = NULL;
    _size = 0;
}

