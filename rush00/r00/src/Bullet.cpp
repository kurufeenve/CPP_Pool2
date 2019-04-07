/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlitvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:21:26 by dmlitvin          #+#    #+#             */
/*   Updated: 2019/04/06 17:47:06 by dmlitvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#include "../includes/Bullet.hpp"

unsigned    Bullet::_bulletCount = 0;

Bullet::Bullet() {}

Bullet::Bullet(const Bullet &object)
{
	operator=(object);
}

Bullet &Bullet::operator=(Bullet const &object)
{
	GameObject::operator=(object);
	return *this;
}

Bullet::Bullet(unsigned x, unsigned y, unsigned level, unsigned moveSpeed,
unsigned livesCount, int direction)
	: GameObject(x, y, level, moveSpeed, livesCount, "*", "Bullet"), _direction(direction)
{
	_bulletCount++;
}

Bullet::~Bullet()
{
	_bulletCount--;
}

void	Bullet::die(void) {}
