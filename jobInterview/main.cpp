// ************************************************************************** //
//	                                                                	      //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/21 10:02:31 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/21 10:02:31 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <stdexcept>
#include <iostream>

class Song
{
private:
	const std::string name;
public:
	Song* nextSong;
	Song* prevSong;
	bool rep;
	Song(std::string name): name(name), nextSong(NULL), prevSong(NULL), rep(false) {}
	
	void next(Song* song)
	{
		this->nextSong = song;
		song->prevSong = this;
		if (this->prevSong && this->nextSong &&
			song->prevSong && song->nextSong)
		{
			rep = true;
			song->rep = true;
		}
    }

    bool isRepeatingPlaylist(void) 
    {
    	if (rep)
    		return (true);
    	return (false);
    	// Song *root = this;
    	// Song *tmp = this;

    	// if (tmp->nextSong)
    	// {
    	// 	tmp = tmp->nextSong;
    	// 	while (tmp->nextSong)
    	// 	{
    	// 		if (tmp == root)
    	// 			return (true);
    	// 		tmp = tmp->nextSong;
    	// 	}
    	// }
    	// return (false);
    }

};

int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    Song* third = new Song("test");

    first->next(second);
    second->next(first);
    // third->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
}