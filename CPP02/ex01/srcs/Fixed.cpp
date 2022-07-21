/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 01:13:38 by rcuminal          #+#    #+#             */
/*   Updated: 2022/07/15 22:44:42 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int Fixed::getRawBits( void ) const {
	return this->_value;
};

void Fixed::setRawBits( int const raw ){
	this->_value = raw;
};

float Fixed::toFloat( void ) const{
	return (this->_value / pow(2, this->_fractiobits));
};

int Fixed::toInt( void ) const{
	return (this->_value / pow(2, this->_fractiobits));
};




Fixed & Fixed::operator = ( const Fixed  &fixed){
	std::cout << "Copy assignement operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return (*this);
};




Fixed::Fixed( Fixed const &copy ){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
};

Fixed::Fixed( void ): _value(0){
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const int value ): _value(value * pow(2, this->_fractiobits)){
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed( const float value ){
	std::cout << "Float constructor called" << std::endl;
	this->_value = round(value * pow(2, this->_fractiobits));
};

// Fixed::Fixed( const int cstint ): _value(_fractiobits){
// 	std::cout << "Default with value constructor called" << std::endl;
// };

Fixed::~Fixed( void ){
	std::cout << "Destructor called" << std::endl;
};



std::ostream & operator << ( std::ostream & oper, Fixed const & rhs ){
	oper << rhs.toFloat();
	return oper ;
};