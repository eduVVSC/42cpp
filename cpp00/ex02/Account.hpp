/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:27:17 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/01 14:22:40 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

# include <iomanip>
# include <iostream>
# include <ctime>

class Account {
	public:
			typedef	Account	t;

			static int		getNbAccounts( void );
			static int		getTotalAmount( void );
			static int		getNbDeposits( void );
			static int		getNbWithdrawals( void );
			static void		displayAccountsInfos( void );

			Account( int initial_deposit );
			~Account( void );

			void	makeDeposit( int deposit );
			bool	makeWithdrawal( int withdrawal );
			int		checkAmount( void ) const;
			void	displayStatus( void ) const;


	private:

			static int	_nbAccounts;
			static int	_totalAmount;
			static int	_totalNbDeposits;
			static int	_totalNbWithdrawals;

			static void	_displayTimestamp( void );

			int			_accountIndex;
			int			_amount;
			int			_nbDeposits;
			int			_nbWithdrawals;

			Account( void );

	};

#endif
