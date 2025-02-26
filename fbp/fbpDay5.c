#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
    1/23/2025
    Fow now, just to get it working and running a bit more, we'll finish out a starting stage,
    an adjacent room in each cardinal diretion, and hopefully the ability to move and look.
    We may have to continue this portion tomorrow as per below.

    <sigh> I guess that means a state system after all~ Just breathe, and start small. Start
    with a simple current state to hold just that.
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
    float   stageID;                // Unique ID number for each stage.
    char    stageName[150];         // Unique stage name. Yes, we do need both name and unique id. Idk why yet but we do.
    char    description[2500];
    struct  exits                   // Hold directions you can exit or enter from.
    {
        bool validExits[8];
    }exits;
//    char    items[1][1];           // To hold items in the stage, a UID and description.
} Stage;


// Build this into states that hold information about the game state for display and manipulation and storage.
// Also use to declare a State currentState; State previousState; and State saveState where appropriate.
typedef struct
{
    float   stateStageID;
    char    statestageName[150];
    char    stateDescription[2500];
    /*
        Add for objects, items, present npcs, player state, etc etc...
    */
} State;

int main_Game_Loop();
void get_action(char *callingBuffer, size_t size, Action *action);
void doAction(Action action);
bool validVerb(Action action);

int main()
{
    // Place holder for main menu. main menu will call new game or save state.
    // Maybe something about {if previousState = NULL State currentState = Stage *intro}  ??? *menu ???
    main_Game_Loop();
}

int main_Game_Loop()
{
    Stage intro;
    intro.stageID = 0.0;
    strcpy(intro.description,   "You wake up groggy and foggy. You're not Sure what just happened.\n"
                                "You find yourself in an empty dilaptidated old room."
                                ""
                                "");

    printf("%s\n", intro.description);
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

        doAction(action);       // Here we execute on the users input.

        //updateStage(Stage *previous, Stage *current)
    }
    while (quit == false);
return 0;
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
/*    switch (action.command)
    {
        case (strcmp(action.command))"look":
        break;
    }
*/
}

bool validateCommand(Action action)
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
        //if (isVerb)
    }

    // debug printf() We now properly retrieve both command and target into action.
    printf("%s %s %s\n", action.command, action.target, isVerb ? "true" : "false");

return isVerb;
}


// random thought: What if players are able to define the state of their own final boss in a training setting?
// IE: allow the player to dictate the stats/strengths/weaknesses of the final boss, and vary reward based on total strength of boss defeated~
// This could be achieved by calling for input that is then used to create a struct entry for mob.


/*
Random idea for random choice generation which may or may not end up becoming extremely important;
Pseudo coded;
loop this obviously;
rand1 = rand(time);
rand2 = rand((wait)time);
rand3 = rand((wait)time);
rand4 = rand((wait)time);
rand5 = rand((wait)time);
rand6 = rand((wait)time);
rand7 = rand((wait)time);
rand8 = rand((wait)time);
rand9 = rand((wait)time);

get_mean(rand1-4);
get_mean(rand6-9);
if rand5 != mean1 && rand5 != mean2
let trueRand = get_mean(mean1, mean2, rand5);
else let trueRand = rand5;  // I mean, the chances of rand5 == mean1 or mean2
*/
