/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:53:36 by edvieira          #+#    #+#             */
/*   Updated: 2025/07/11 10:53:38 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>
#include <cctype>

template < typename T >
void iter(T *begAdress, int length , void (*func)(T *a)){
    if (begAdress == NULL || func == NULL)
        return ;
    for(int i = 0; i < length; i++){
        func(begAdress);
        begAdress++;
    }
}


template < typename T >
void iter(T *begAdress, int length , void (*func)(T &a)){
    if (begAdress == NULL || func == NULL)
        return ;
    for(int i = 0; i < length; i++){
        func(begAdress);
        begAdress++;
    }
}


// do the handle for const
#endif
