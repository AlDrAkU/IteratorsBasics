#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include "Player.h"

// Vector of integer numbers
void Print( const  std::vector<int>& numbers );
void AddValue( std::vector<int>& numbers, int value );
void PrintReverse( const std::vector<int>& numbers );

// Vector of Player objects
void CreatePlayers( std::vector<Player>& players );
void PrintNames( const std::vector<Player>& players );
void ChangeScores( std::vector<Player>& players );
void Print( const std::vector<Player>& players );

// Vector of pointers to Player objects
void CreatePlayers( std::vector<std::unique_ptr<Player>>& players );
void PrintNames( const std::vector<std::unique_ptr<Player>>& players );
void ChangeScores( std::vector<std::unique_ptr<Player>>& players );
void Print( const std::vector<std::unique_ptr<Player>>& players );

// Special cases
void Print( const  std::list<int>& numbers );

int main( )
{
	// Vector of integer numbers
	std::cout << "-->Vector of integer numbers\n";
	std::vector<int> numbers{ 1,2,3,4,5,6,7,8,9,10 };
	Print( numbers );
	AddValue( numbers, 10 );
	PrintReverse( numbers );

	// Vector of Player objects
	std::cout << "\n-->Vector of Player objects\n";
	std::vector<Player> players{};
	CreatePlayers( players );
	PrintNames( players );
	ChangeScores( players );
	Print( players );

	// Vector of pointers to Player objects
	std::cout << "\n-->Vector of pointers to Player objects\n";
	std::vector<std::unique_ptr<Player>> pPlayers{};
	CreatePlayers( pPlayers );
	PrintNames( pPlayers );
	ChangeScores( pPlayers );
	Print( pPlayers );

	// Special cases
	std::cout << "\n-->List of integer numbers\n";
	std::list<int> numbersList{ 1,2,3,4,5,6,7,8,9,10 };
	Print( numbersList );


	std::cout << "Press ENTER to quit\n";
	std::cin.get( );
	return 0;
}


void Print( const  std::vector<int>& numbers )
{
	std::vector<int>::const_iterator it{};
	for (it = numbers.begin(); it != numbers.end();++it)
	{
		std::cout << *it << '\n';
	
	}
	// TODO: 1a. Replace this code by a for loop using an iterator
	//for ( int number: numbers )
	//{
	//	std::cout << number << " ";
	//}
	//std::cout << '\n';
}

void AddValue( std::vector<int>& numbers, int value )
{
	// TODO: 1b. Replace this code by a for loop using an iterator
	std::vector<int>::iterator it{};
	for (it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it + value << '\n';

	}
	/*for ( int& number : numbers )
	{
		number += value;
	}*/
}

void PrintReverse( const  std::vector<int>& numbers )
{
	// TODO: 1c. Replace this code by a for loop using an iterator
	//int size{ int( numbers.size( ) ) };
	//for ( int i{ size - 1}; i >= 0 ; --i )
	//{
	//	std::cout << numbers[i] << " ";
	//}
	//std::cout << '\n';

	//std::vector<int>::const_iterator it{};
	/*std::vector<int>::const_reverse_iterator it{};

	for (it = numbers.rbegin(); it != numbers.rend(); ++it)
	{

		std::cout << &(*it)  << '\n';

	}*/

	
	std::vector<int>::reverse_iterator rit = numbers.rend();
	for (; rit != numbers.rbegin(); ++rit)
	std::cout << *rit << '\n';



}


void CreatePlayers( std::vector<Player>& players )
{
	players.push_back( Player( "Marleen" ) );
	players.push_back( Player( "Koen" ) );
	players.push_back( Player( "Steven" ) );
}

void PrintNames( const std::vector<Player>& players )
{
	//// TODO: 2a. Replace this code by a for loop using an iterator
	//for ( const Player player : players )
	//{
	//	std::cout << player.GetName( ) << ", ";
	//}
	//std::cout << '\n';

	std::vector<Player>::const_iterator it{};
	for (it = players.begin(); it != players.end(); ++it)
	{
		std::cout << *it << '\n';

	}


}

void ChangeScores( std::vector<Player>& players )
{
	// TODO: 2b. Replace this code by a for loop using an iterator
	//for (  Player& player : players )
	//{
	//	player.IncrementScore( rand( ) % 11 + 10 ); //[10,20]
	//}

	std::vector<Player>::iterator it{};
	for (it = players.begin(); it != players.end(); ++it)
	{


		&it  + (rand() % 11 + 10) ; 
		
	}

}

void Print( const std::vector<Player>& players )
{
	// TODO: 2c. Replace this code by a for loop using an iterator
	/*for ( const Player player : players )
	{
		std::cout << player << ", ";
	}
	std::cout << '\n';*/


	std::vector<Player>::const_iterator it{};
	for (it = players.begin(); it != players.end(); ++it)
	{
		std::cout << *it << ", ";
	}
	std::cout << '\n';


}


void CreatePlayers( std::vector<std::unique_ptr<Player>>& pPlayers )
{
	pPlayers.push_back( std::make_unique<Player>( "Bart" ) );
	pPlayers.push_back( std::make_unique<Player>( "Thomas" ) );
	pPlayers.push_back( std::make_unique<Player>( "Stephanie" ) );
}


void PrintNames( const std::vector<std::unique_ptr<Player>>& pPlayers )
{
	// TODO: 3a. Replace this code by a for loop using an iterator
	//for ( const std::unique_ptr<Player>& pPlayer : pPlayers )
	//{
	//	std::cout << pPlayer->GetName( ) << ", ";
	//}
	//std::cout << '\n';





	std::vector<std::unique_ptr<Player>>::const_iterator it{};
	for (it = pPlayers.begin(); it != pPlayers.end(); ++it)
	{
		std::cout << (*it)->GetName() << ", ";
	}
	std::cout << '\n';

}

void ChangeScores( std::vector<std::unique_ptr<Player>>& pPlayers )
{
	// TODO: 3b. Replace this code by a for loop using an iterator
	//for (  std::unique_ptr<Player>& pPlayer : pPlayers )
	//{
	//	pPlayer->IncrementScore( rand( ) % 11 + 10 );//[10,20]
	//}




	
	for (std::vector<std::unique_ptr<Player>>::iterator it{ pPlayers.begin() }; it != pPlayers.end(); ++it)
	{
		(*it)->IncrementScore(rand() % 11 + 10);

	}
	/*std::cout << '\n';*/



}

void Print( const std::vector<std::unique_ptr<Player>>& pPlayers )
{
	// TODO: 3c. Replace this code by a for loop using an iterator
	for ( const std::unique_ptr<Player>& pPlayer : pPlayers )
	{
		std::cout << *pPlayer << ", ";
	}
	std::cout << '\n';




}

void Print( const  std::list<int>& numbers )
{
	// TODO: 4a. Replace this code by a for loop using an iterator deducing its type 
	//			from its initializer using auto
	/*for ( int number : numbers )
	{
		std::cout << number << " ";
	}
	std::cout << '\n';
*/

	std::list<int>::const_iterator it{};
	for (it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';

}
