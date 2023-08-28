#include "Fixed.hpp"

Fixed::Fixed() { 
    _rawBits = 0; 
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &p ) {
    // std::cout << "Copy constructor called" << std::endl;
    // *this = p;
    this->operator=(p);
}

Fixed::Fixed( const int num ) {
    _rawBits = num << _fractionalBits;
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) {
    _rawBits = (roundf(num * (1 << _fractionalBits)));
    // std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed &p ) { 
    
    // std::cout << "Copy assignment operator called" << std::endl;
    _rawBits = p.getRawBits();
    return *this; 
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const { 
    // std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits( int const raw ) { 
    this->_rawBits = raw;
}

float Fixed::toFloat( void ) const {
    return (float)(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
    return _rawBits >> _fractionalBits;
}

std::ostream& operator << (std::ostream& os, const Fixed& p) {
    os << p.toFloat();
    return os;
}


bool Fixed::operator>( const Fixed &p ) const {
    return _rawBits > p.getRawBits();
}

bool Fixed::operator<( const Fixed &p ) const {
    return _rawBits < p.getRawBits();
}

bool Fixed::operator>=( const Fixed &p ) {
    return _rawBits >= p.getRawBits();
}

bool Fixed::operator<=( const Fixed &p ) {
    return _rawBits <= p.getRawBits();
}

bool Fixed::operator==( const Fixed &p ) {
    return _rawBits == p.getRawBits();
}

bool Fixed::operator!=( const Fixed &p ) {
    return _rawBits != p.getRawBits();
}

Fixed Fixed::operator+( const Fixed &p ) {
    
    Fixed result(this->_rawBits + p.getRawBits());
    return result;
}

Fixed Fixed::operator-( const Fixed &p ) {
    
    Fixed result(this->_rawBits - p.getRawBits());
    return result;
}

Fixed Fixed::operator*( const Fixed &p ) {
    
    Fixed result(this->toFloat() * p.toFloat());
    return result;
}

Fixed Fixed::operator/( const Fixed &p ) {
    Fixed result(this->toFloat() / p.toFloat());
    return result;
}

Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed old = *this;
    ++_rawBits;
    return old;
}

Fixed& Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed old = *this;
    --_rawBits;
    return old;
}

Fixed& Fixed::min( Fixed& num1, Fixed& num2 ) {
    
    if (num1 > num2)
        return num2;
    else
        return num1;
}

const Fixed& Fixed::min( const Fixed& num1, const Fixed& num2 ) {
    
    if (num1 > num2)
        return num2;
    else
        return num1;
}

Fixed& Fixed::max( Fixed& num1, Fixed& num2 )  {
    
    if (num1 < num2)
        return num2;
    else
        return num1;
}

const Fixed& Fixed::max( const Fixed& num1, const Fixed& num2 )  {
    
    if (num1 < num2)
        return num2;
    else
        return num1;
}