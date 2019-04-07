/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlitvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:21:34 by dmlitvin          #+#    #+#             */
/*   Updated: 2019/04/06 17:21:34 by dmlitvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#include "./../includes/GameObject.hpp"

unsigned GameObject::_gameObjectsCount = 0;

GameObject::GameObject(const GameObject &object)
{
	operator=(object);
}

GameObject &GameObject::operator = (GameObject const &object)
{
	_x = object._x;
	_y = object._y;
	_level = object._level;
	_moveSpeed = object._moveSpeed;
	_livesCount = object._livesCount;
	_symbol = object._symbol;
	_type = object._type;
	return *this;
}

GameObject::GameObject(unsigned x, unsigned y, unsigned level, 
		unsigned moveSpeed, unsigned livesCount, const char *symbol, std::string const & type)
		: _x(x), _y(y), _level(level),
		_moveSpeed(moveSpeed), _livesCount(livesCount), _symbol(symbol), _type(type)
{
	GameObject::_gameObjectsCount++;
}

GameObject::~GameObject()
{
	GameObject::_gameObjectsCount--;
}

GameObject::GameObject() {}

unsigned int GameObject::getX() const
{
	return _x;
}

void GameObject::setX(unsigned int x)
{
	_x = x;
}

unsigned int GameObject::getY() const
{
	return _y;
}

void GameObject::setY(unsigned int y)
{
	_y = y;
}

unsigned int GameObject::getLivesCount() const
{
	return _livesCount;
}

void GameObject::setLivesCount(unsigned int livesCount)
{
	_livesCount = livesCount;
}

unsigned int	GameObject::getLevel(void) const
{
	return _level;
}

const char		*GameObject::getSymbol(void) const
{
	return _symbol;
}

void	GameObject::setLevel(unsigned int lvl) {

	this->_level = lvl;
}
