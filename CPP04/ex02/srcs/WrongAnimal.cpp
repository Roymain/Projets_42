/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:21:52 by rcuminal          #+#    #+#             */
/*   Updated: 2022/09/29 16:32:44 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

void WrongAnimal::makeSound( void ) const {
		std::cout << "WrongWTF?!" << std::endl;
}



WrongAnimal::WrongAnimal(const WrongAnimal &Animal){
	*this = Animal;
	return;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal &rhs){
	if (&rhs != this)
		_type = rhs._type;
	return (*this);
}



WrongAnimal::WrongAnimal( void ){
    std::cout << "An wronganimal constructor has been called for" << std::endl;
};

WrongAnimal::WrongAnimal( std::string type ):  _type(type){
    std::cout << "An wronganimal constructor has been called for" << type << std::endl;
	this->_type = type;
};


WrongAnimal::~WrongAnimal( void ){
    std::cout << "An Wronganimal destructor has been called" << std::endl;
};