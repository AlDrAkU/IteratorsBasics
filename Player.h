#pragma once
#include <string>

class Player
{
public:
	Player(const std::string& name, int score = 0 );
	void IncrementScore( int value );
	const std::string& GetName( ) const;
	int GetScore( ) const;

private:
	std::string m_Name;
	int m_Score;
};

std::ostream& operator<<( std::ostream& out, const Player& player );

