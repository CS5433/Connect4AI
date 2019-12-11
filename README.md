## Project Name: 
_Connect 4 AI_

## About:
_Using C++ we designed an AI for the game Connect 4. We used a heuristic function to guide the AI
into choosing it's next move._
 
## Members:
List each team member along with a short description of their responsibility.

1. Joe Thomas - _Algorithm design and debugging_
2. Daniel Woodar - _Interface design and implementation, debugging, rubber ducky_
3. Brody Modglin - _Code Monkey, Main driver behind the code_

## Instructions:
_Place as 1 player to compete against the AI._

1. ### How to compile:
	_Very simple C++. Compile on the virtual server, we used 147.97.156.234._

2. ### How to execute:
	_Just run the ./a.out executable._

3. ### Expected output:
	_The user will see a short list of rules, then a prompt to play 1-player or 2-player. After choosing one or the other a prompt for the first player, the person, will appear
    and ask for a column input. After input, the board will appear and then the game is on. Try to win against the AI or a friend._

4. ### Known issues:
	_So, quite a few known issues and probably a few unknown. We built this from the ground up and without looking up any reference to previously created Connect 4 AIs. Our first
    version of the win condition function was too long so we shortened it. Then we modified the shortened code to use it in our heuristic functions. After getting the heuristic function
    working for the AI opponent and making a function for its move choices, we tried to conquer a defensive function using a heuristic function for the human player. After about 2 weeks
    of debugging, tears, blood, and sweat, we found out that the heuristic function would be much better using the older, larger code from the win condition. Unfortunately, the heuristic
    value for either player does not reset consistently or easily. This makes the AI very angry and will only try to block the human player in one direction or move randomly. If we had
    one or two more weeks without other projects taking up time, we could have fixed these issues. The solution to the heuristic would be for us to start over from the older, larger
    win condition code and modify it instead of trying to use the shorter version. Unfortunately, we figured this out a little too late. There were some segmentation faults and we
    believe we have fixed them all, however, one or two may show up as we did not have enough time to vigorously test our code._
