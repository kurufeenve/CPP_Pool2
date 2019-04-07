/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlitvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:21:28 by dmlitvin          #+#    #+#             */
/*   Updated: 2019/04/06 17:23:26 by dmlitvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Dmitro LITVINENKO on 2019-04-06.
//

#ifndef RUSH00_GAMEOBJECT_HPP
#define RUSH00_GAMEOBJECT_HPP

#include <iostream>
#include <string>
#include <sys/time.h>

class GameObject
{

private:

	unsigned    _x;
	unsigned    _y;
	unsigned    _level;
	unsigned    _moveSpeed;
	unsigned    _livesCount;
	const char	*_symbol;

	std::string _type;

public:

	GameObject();
	GameObject(unsigned, unsigned, unsigned, unsigned, unsigned, const char *,
											std::string const &);
	GameObject(const GameObject &);
	virtual ~GameObject();

	GameObject &operator=(const GameObject &);

	virtual void    die() = 0;

	unsigned int    getX() const;
	void            setX(unsigned int x);
	unsigned int    getY() const;
	void            setY(unsigned int y);
	unsigned int    getLivesCount() const;
	void            setLivesCount(unsigned int livesCount);
	unsigned int	getLevel() const;
	const char		*getSymbol() const;
	void			setLevel(unsigned int);

	static unsigned _gameObjectsCount;

};

RUSH00_GAMEOBJECT_HPP
#endif //RUSH00_GAMEOBJECT_HPP
