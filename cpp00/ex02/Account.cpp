/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:27:16 by edvieira          #+#    #+#             */
/*   Updated: 2025/04/01 14:01:00 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

	// private method
	void	Account::_displayTimestamp( void ){
		time_t timestamp;
		std::cout << "[" << std::time(&timestamp) << "] ";
	}

	int Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;
	int Account::_nbAccounts = 0;

	Account::Account( int initial_deposit )
	{
		_amount = initial_deposit;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
		_accountIndex = _nbAccounts;

		_nbAccounts++;
		_totalAmount += initial_deposit;

		_displayTimestamp();
		std::cout << "index:" << _accountIndex
					<< ";ammout:" << _amount
					<< ";created" << std::endl;
	}

	Account::Account( void )
	{
		_amount = 0;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
		_accountIndex = _nbAccounts;

		_nbAccounts++;

		_displayTimestamp();
		std::cout << "index:" << _accountIndex
					<< ";ammout:" << _amount
					<< ";created" << std::endl;
	}

	Account::~Account(void)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
					<< ";ammout:" << _amount
					<< ";closed" << std::endl;
	}

	void	Account::makeDeposit( int deposit )
	{
		int		oldAmount = 0;

		oldAmount = _amount;

		_amount += deposit;
		_nbDeposits++;
		_totalAmount += deposit;

		_totalNbDeposits++;

		// display deposit details
		_displayTimestamp();
		std::cout << "index:" << _nbAccounts
					<< ";p_amount:" << oldAmount
					<< ";deposit:" << deposit
					<< ";ammount:" << _amount
					<< ";nb_deposits:" << _nbDeposits
					<< std::endl;
	}

	bool	Account::makeWithdrawal( int withdrawal )
	{
		int		oldAmount = 0;

		if (_amount < withdrawal)
		{
			// refused message display
			_displayTimestamp();
			std::cout << "index:" << _nbAccounts
						<< ";p_amount:" << _amount
						<< ";withdrawal:refused"
						<< std::endl;
			return (false);
		}

		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;

		_totalNbWithdrawals++;

		// success message display
		_displayTimestamp();
		std::cout << "index:" << _nbAccounts
					<< ";p_amount:" << oldAmount
					<< ";withdrawal:" << withdrawal
					<< ";ammount:" << _amount
					<< ";nb_withdrawals:" << _nbWithdrawals
					<< std::endl;

		return (true);
	}

	int		Account::checkAmount( void ) const { return (_amount); }

	int		Account::getNbAccounts( void ) { return (_nbAccounts); }

	int		Account::getTotalAmount( void ) { return (_totalAmount); }

	int		Account::getNbDeposits( void ) { return (_totalNbDeposits); }

	int		Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

	/// @brief print each account info and status if it is closed
	void	Account::displayStatus( void ) const {
		std::cout << "in here with the account " << _accountIndex << std::endl;
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
