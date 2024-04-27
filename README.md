* Summarize the project and what problem it was solving.

This project was made to take in and proccess data in the from of a txt file conatining the produce purchased during a day.
The data is ran parsed and added to a map, that stores the item name and number of times the item appears in the file, counting the number of times the item is purchased.
The data is then added to a dat file with the item name and the count of how many times the item is purchased, the program also allows the user to search for individual items and see the counts,
or to display each item and count in the main loop of the program.

* What did you do particularly well?

During the creation of this project, I did a great job handling the data taken from the files and using a map to store the data and make it easy to count the data accordingly. I also did a good job handling the file input,
if the file inputed does not exist, the program will reloop so the program wont crash, or create an empty file.

* Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

I could have broke down some of my functions more, made the creation of the dat outsid eof the search file fucntion, and also kept the search file function inside of the DataProcessor class. As far as security goes, i beleive I avoided direct memory access well, I inlcuded strong input error handling to ensure the program could not be broken, I think I overlooked a memory leak, when the user inputs a new file, the old object gets destroyed, however the map in that object does not get deleted. This is an easy fix.

* Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

There wasn't any part of this that was really too challanging to me, I knew immediatly to use a map to store the data to mak eit easily accessable and to make it easy to count each purchase. I think I could use some work structuring the code in more of a clean way, and seeing where memory leaks occor.

* What skills from this project will be particularly transferable to other projects or course work?

Processing data from files and parsing data, also using maps is a big thing that can be easily trasnferable to other projects. Also my use of error handling of course.

* How did you make this program maintainable, readable, and adaptable?

I made sure to use easy to understand naming conventions for the functions, and kept each fucntion relativly simple. I also provided good comments to breifly explain how the code functions.
