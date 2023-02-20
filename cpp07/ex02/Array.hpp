#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array {
private:
	T 				*_arr;
	unsigned int	_size;

public:

	Array() : _arr(new T()), _size(0) {};
	Array(unsigned int n) : _arr(new T[n]), _size(n) {};
	Array(const Array &copy) : _arr(new T [copy.size()]), _size(copy.size()) {
	 	for (unsigned int i = 0; i < _size; i++)
	 		this->_arr[i] = copy._arr[i];
	 };
	~Array() { delete [] _arr;}
	Array &operator=(const Array &dcopy) {
		if (this != &dcopy)
		{
			delete [] _arr;
			this->_arr = new T[dcopy.size()];
			this->_size = dcopy._size;
			for(unsigned int i = 0; i < _size; i++)
				this->_arr[i] = dcopy._arr[i];
		}
		return *this;
	}

	T &operator[](unsigned int i) const {
		if (i >= _size)
			throw OutOfBoundsException();
		return _arr[i];
	}

	unsigned int size(void) const {
		return _size;
	}

	class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Index is out of bounds";
			}
	};
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>&arr) {
	for(unsigned int i = 0; i < arr.size(); i++)
		out << arr[i] << " ";
	return out;
}

#endif 