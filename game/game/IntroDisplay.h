// ----------------------------------------------------------------------------
/**  File: introDisplay.h
  
 *System:         windows 10
 *Project Name:   betrayal
 *Status:         Version 1.0 Release 1  
 *Language: C++
 *Additional library dependencies : SFML

 *License: GNU Public License 
   
 *Address:
 *  cs16btech11029 , cs16btech11031 , cs16btech11039
 *  iit hyderabad
 *  boys hostel
 *  india
  
 *Author: cs16btech11029 , cs16btech11031 , cs16btech11039
 *E-Mail: cs16btech11029@iith.ac.in , cs16btech11031@iith.ac.in ,cs16btech11039@iith.ac.in
 
  
 *Description: Header file for game "betrayal"
 *             This file contains the defined types for Project betrayal 
              
 *Limitations: - 
  
 *Function: 1)Image_player
 *          2)image_display_function
 *          3)~Image_player
 
 *params : num_strings , sleep_time , str 
 
 *Database tables used: No
  
 *Thread Safe: Yes
  
 *Extendable: Yes
  
 *Platform Dependencies: no 

 *Compiler Options: -lm
  
 *Date         Author                                               Description
 *7/11/2017    cs16btech11029 , cs16btech11031 , cs16btech11039     student@iit-hyd
*/ 
#pragma once
#pragma once
#include <SFML\Graphics.hpp>
class Image_player
{
private:
	/** 
	* num_strings store number of substrings we have to take from arguments given
	* sleep_time represents the time one image should be on screen
	* pointer str has address of image file names passed as argument in image_player function seperated with @
	*/
	int num_strings, *sleep_time;
	std::string * str;

public:
	/** Image player function assigns value to thread * str
	*   
	*   arguments  :: string a => has image file names representing images to be displayed seperated with '@'
	*                 string t => has time each image should be on screen seperated with '@'
	* 		  int    n => has number of images
	*
	*    returns  ::  ----
	*    
	*     parses through a and t and assigns value to private members
	*/
	Image_player(std::string a, std::string t, int n);
	/** image display function ..
	*   
	*    arguments :: takes Renderwindow as argument
	*    return    :: integer
	*
	*    diplays a series of images in the window passed .
	*    where image file names are present *str adress
	*/
	int image_display_function(sf::RenderWindow *);
	/**  ~Image_player() deallocates memory assigned to str 
	*     deallocates *str,*sleeptime	
	*/
	~Image_player();
};
