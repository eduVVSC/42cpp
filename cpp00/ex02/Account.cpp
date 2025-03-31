/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:27:16 by edvieira          #+#    #+#             */
/*   Updated: 2025/03/31 22:14:29 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"


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

	// private method
	void	Account::_displayTimestamp( void ){
		std::cout << "[" << std::time(nullptr) << "] ";
	}

	int Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;
	int Account::_nbAccounts = 0;

	Account::Account( int initial_deposit )
	{
		_amount = initial_deposit;
		_nbDeposits = 1;
		_nbWithdrawals = 0;
		_accountIndex = _nbAccounts;

		_nbAccounts++;
		_totalNbDeposits++;
		_totalAmount += initial_deposit;
	}

	Account::Account( void )
	{
		_amount = 0;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
		_accountIndex = _nbAccounts;
		_nbAccounts++;
	}

	void	Account::makeDeposit( int deposit )
	{
		_amount += deposit;
		_totalAmount += deposit;
		_nbDeposits++;
		_totalNbDeposits++;
	}

	bool	Account::makeWithdrawal( int withdrawal )
	{
		if (_amount < withdrawal)
			return (false);
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		return (true);
	}

	int		Account::checkAmount( void ) const { return (_amount); }

	int		Account::getNbAccounts( void ) { return (_nbAccounts); }

	int		Account::getTotalAmount( void ) { return (_totalAmount); }

	int		Account::getNbDeposits( void ) { return (_totalNbDeposits); }

	int		Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

	/// @brief print each account info and status if it is closed
	void	displayStatus( void ){

	}

	/// @brief Print the info of all the accounts together
	void		Account::displayAccountsInfos( void ){
		_displayTimestamp();
		std::cout << "accounts:" << _nbAccounts
					<< ";total:" << _totalAmount
					<< ";deposits:" << _totalNbDeposits
					<< ";withdrawals:" << _totalNbWithdrawals << std::endl;

		// should I print all the accounts
	}
