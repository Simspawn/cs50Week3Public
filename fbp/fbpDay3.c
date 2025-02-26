#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    1/12/25
    Yet again not enough coding done.
    Bad day at work. Really need to step down on the dicipline.
    Want to code more. Mentally exhausted~
    Need to construct stages using the new stage struct.
    Need a struct for targets/nouns.
    Need to validate new actions like look and go and north etc...
    Need to validate targetless commands and targeted commands.
    Need to create header files to organize functions into seperate .c files to create systems.
*/

/*
1/13/25 technically day 4, but no work or progress was done. Much pissed about that. Off 3 days soon. Hell yeah.
Maybe some touchups but no real progress today. Had something worth commenting but seem to have lost it for now.
Until I remember, if I do, it needs to be noted that I need to better plan out how I'm going to use the logic
I code into the functions I create. I still need to define stages, items, uses... I still need to in use
implement header .h files.

Ahh, yes, I remember now. I wanted to document that not only have I not used one snippet or paste of AI derived code,
I have been exceedingly sparing on my use of such tools. When I do use AI, chaptgpt, gemini, never copilot, it is a last
resort when I truly find myself stuck and unable to progress after hours of beating my head on the keyboard. Even then,
I stick to asking questions about how why what regarding the working of the code or logic.
I never copy and paste any code it geneterates. I only use it to learn how to do what I'm trying to do
myself, or why something isn't working, or what's the best approach
to take on a problem.

I'm adding this comment in for my own sake, knowing I prolly won't get audited and even if I do it doesn't matter.
I'm taking the course to learn, and won't be paying for the validation. Still, I actually hope I get audited.
I think it would be a shame if no one witnesses the journey I've made from day 1 to now, and beyond.
*/



const bool FirstBigProject = true, fbp = FirstBigProject;       // After I completed Substitution in week 2
bool quit = false;                                              // I realized the best way to learn more at the
                                                                // time was to put it all together into something
typedef struct                                                  // creative which I could be passionate about.
{                                                               // Obviously, a game~ One day RPG???
    char command[25];
    char target[50];
} Action;

typedef struct
{
                                // All [1] values are place holders to complie.
    char stageID[20];           // Unique ID number for each stage.
    char stageName[20];         // Unique stage name. Yes, we do need both name and unique id. Idk why yet but we do.
    char description[1];
    char exits[1];              // Hold directions you can exit or enter from.
    char items[1][1];           // To hold items in the stage, a UID and description.
} Stage;

/*
struct Save_State       // For future use to be able to save a state for return play.
{
    float currentStage;
};
*/

int main_Game_Loop();
void get_action(char *callingBuffer, size_t size, Action *action);
void doAction(Action action);
bool validVerb(Action action);

int main()
{
    // Place holder for main menu. main menu will call new game or save state.
    main_Game_Loop();
}

int main_Game_Loop()
{
    printf("Stage description here.\n");      // Place holder for stage description.
    do
    {
        Action action;

        char playerInput[75];    // callingBuffer
        get_action(playerInput, sizeof(playerInput), &action);      // Here parse the user input into something useable.

        //validVerb(action);


        //if you need to be able to quit early or not, un/comment below.

        if (strcmp(playerInput, "quit") == 0)
            quit = true;
        printf("what do you mean you want to %s %s? \n", action.command, action.target);  // debugging prfintf()
        validVerb (action);

        doAction(action);       // Here we execute on the users input.
    }
    while (quit == false);
return 1;
}

void get_action(char *callingBuffer, size_t size, Action *action)      // fgets(playerInput) delim, and return action.command and action.target
{
if (fgets(callingBuffer, size, stdin) != NULL)
{
    size_t length = strlen(callingBuffer);
    if (length > 0 && callingBuffer[length - 1] == '\n')// Removes newline char.
    {
        callingBuffer[length - 1] = '\0';
    }
    char *token = strtok(callingBuffer, " ");
    if (token != NULL)
    {
        strncpy(action->command, token, sizeof(action->command) - 1);
        action->command[sizeof(action->command) -1] = '\0';
    }
    token = strtok(NULL, "");
    if (token != NULL)
    {
        strncpy(action->target, token, sizeof(action->target) - 1);
        action->target[sizeof(action->target) -1] = '\0';
    } else
        {
            action->target[0] = '\0';       // Null terminate that shit if there's no target.
        }

}
}

// This is our next starting point, we want to pass
// the action struct as an argument the same way we did
// for get_action(). We can use an if else to check for a target.
// We can then use a switch for either case to code action resonses.
// Will prolly have to pass the stages struct in the future
// to advance or interact with the stage.
void doAction(Action action)

{
    if (validVerb(action))
    {
        ;
    }
}

bool validVerb(Action action)
{
    char validVerb[6][15] = {"look", "go", "north", "south", "east", "west"};
    int validVerbs = 6;
    bool isVerb = false;
    // loop (action.commannd) through validVerb
    for (int i = 0; i < validVerbs; i++)
    {
        if (strcmp(action.command, validVerb[i]) == 0)
        {
            isVerb = true;
            break;
        } else isVerb = false;
    }
    printf("%s %s %s\n", action.command, action.target, isVerb ? "true" : "false"); // debug printf() We now properly retrieve both command and target into action.
return isVerb;
}


// random thought: What if players are able to define the state of their own final boss in a training setting?
// IE: allow the player to dictate the stats/strengths/weaknesses of the final boss, and vary reward based on total strength of boss defeated~
// This could be achieved by calling for input that is then used to create a struct entry for mob.
