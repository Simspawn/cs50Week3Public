#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
    1/25/2025
    cleaned the code up quite a bit. Started working on validating verbs and targets.
    Started  validateCommand() and validateTarget() functions.
    Still working on the same, so same comment applies. Have made some progress in code,
    even more in theory crafting. It's long been far beyond time to stop theory crafting
    and actually code. That's the struggle I suppose. Theory crafting and learning is fun.
    Actually coding kinda sucks.

    We still need to finish look and movement functions, a starting stage,
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
    char command[35];
    char target[35];
    char firstWord[35];
    char secondWord[35];
    char thirdWord[35];
} Action;

typedef struct
{
    float   stageID;                // Unique ID number for each stage.
    char    stageName[150];         // Unique stage name. Yes, we do need both name and unique id. Idk why yet but we do.
    char    description[2500];      // This will basically be the core, what tells all. May need multiple.
    struct  exits                   // Hold directions you can exit or enter from.
    {
        bool validExits[8];         // Construct this to hold a boolean value for each direction of
                                    // travel as well as the next valid stageID.
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
void doAction(Action *action);
void validVerb(Action *action);
void validateCommand(Action *action);
void validateTarget(Action *action);

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
    strcpy(intro.description, "You wake up groggy and foggy. You're not Sure what just happened.\n"
                              "You find yourself in an empty dilaptidated old room."
                              ""
                              "");

    printf("%s\n", intro.description);
    do
    {
        Action action;
        char playerInput[75];    // callingBuffer
        get_action(playerInput, sizeof(playerInput), &action);              // Here parse the user input into something useable.

        //if you need to be able to quit early or not, un/comment below.
        if (strcmp(playerInput, "quit") == 0)
            quit = true;
        printf("what do you mean you want to %s %s? \n", action.command, action.target);  // debugging prfintf()

        doAction(&action);                                                  // Here we execute on the users input.

        //updateStage(Stage *previous, Stage *current)
    }
    while (quit == false);
return 0;
}

// refactor get_action to be get_input. Create a new function to validate if any
// given string is a validVerb, validNoun, or validModifier before assignment to proper field.
// Create modifer field in Action struct.
// Possibly create a recognizedSentenceStructure 2d(3d?) array for examples of common use syntax?
// if strtoken == validVerb {verb = token} hasVerb = true
// else if strtoken == validNoun {noun = token} hasNoun = true
// else if strtoken == validModifier {modifier = token} has modifier = true

void get_action(char *callingBuffer, size_t size, Action *action)           // fgets(playerInput) delim, and return action.command and action.target
{
if (fgets(callingBuffer, size, stdin) != NULL)
{
    size_t length = strlen(callingBuffer);
    if (length > 0 && callingBuffer[length - 1] == '\n')                    // Removes newline char.
    {
        callingBuffer[length - 1] = '\0';
    }
    char *token = strtok(callingBuffer, " ");
    if (token != NULL)
    {
        strncpy(action->firstWord, token, sizeof(action->firstWord) - 1);
        action->firstWord[sizeof(action->firstWord) -1] = '\0';
    }
    token = strtok(NULL, " ");
    if (token != NULL)
    {
        strncpy(action->secondWord, token, sizeof(action->secondWord) - 1);
        action->secondWord[sizeof(action->secondWord) -1] = '\0';
    } else
        {
            action->secondWord[0] = '\0';                                   // Null terminate that shit if there's no second word.
        }
    if (token != NULL)
    {
        strncpy(action->thirdWord, token, sizeof(action.thirdWord) - 1):
        action->thirdWord[sizeof(action->thirdWord) - 1] = '\0':            // Null terminate if there's no second word.
    }
}
    validateCommand(action);
    validateTarget(action);
}

// This is our next starting point, we want to pass
// the action struct as an argument the same way we did
// for get_action(). We can use an if else to check for a target.
// We can then use a switch for either case to code action resonses.
// Will prolly have to pass the stages struct in the future
// to advance or interact with the stage.
void doAction(Action *action)

{
/*    switch (action->command)
    {
        case (strcmp(action->command))"look" == 0):
        break;
    }
*/
}

void validateCommand(Action *action)
{
    char validVerb[6][15] = {"look", "go", "north", "south", "east", "west"};   // short list of validVerb.
    int validVerbs = 6;
    bool isVerb = false;
    // loop (action.firstWord) through validVerb
    for (int i = 0; i < validVerbs; i++)
    {
        if (strcmp(action->firstWord, validVerb[i]) == 0)
        {
            isVerb = true;
            break;
        }
    }
    // Once we find a validVerb
    if (isVerb)
    {
        strncpy(action->command, action->firstWord, sizeof(action->command) - 1);
        action->command[sizeof(action->command) -1] = '\0';
        return;
    }
    if (!isVerb)
    {
        // loop (action.secondWord) through validVerb
        for (int i = 0; i < validVerbs; i++)
        {
            if (strcmp(action->secondWord, validVerb[i]) == 0)
            {
               isVerb = true;
               break;
            }
        }
        if (isVerb)
        {
            strncpy(action->command, action->secondWord, sizeof(action->command) - 1);
            action->command[sizeof(action->secondWord) -1] = '\0';
            return;
        }
    }
    if (!isVerb)
    {
        printf("No valid verb.");
        return;
    }

    // debug printf() to check if we properly retrieve a verb into command.
    printf("Validate command failed: %s %s\n", action->command, isVerb ? "true" : "false");
}

void validateTarget(Action *action)
{
    char validTarget[4][15] = {"west", "north", "east", "south"};           // short list of validTarget.
    int validTargets = 4;
    bool isTarget = false;
    // loop (action.firstWord) through validTarget
    for (int i = 0; i < validTargets; i++)
    {
        if (strcmp(action->firstWord, validTarget[i]) == 0)
        {
            isTarget = true;
            break;
        }
    }
    // Once we find a validTarget copy it to target.
    if (isTarget)
    {
        strncpy(action->target, action->firstWord, sizeof(action->target) - 1);
        action->target[sizeof(action->firstWord) -1] = '\0';
        return;
    }
    if (!isTarget)
    {
        // loop (action.secondWord) through validVerb
        for (int i = 0; i < validTargets; i++)
        {
            if (strcmp(action->secondWord, validTarget[i]) == 0)
            {
               isTarget = true;
            }
        }
        if (isTarget)
        {
            strncpy(action->target, action->secondWord, sizeof(action->target) - 1);
            action->target[sizeof(action->secondWord) -1] = '\0';
            return;
        }
    }
        if (!isTarget)
    {
        // loop (action.secondWord) through validVerb
        for (int i = 0; i < validTargets; i++)
        {
            if (strcmp(action->thirdWord, validTarget[i]) == 0)
            {
               isTarget = true;
            }
        }
        if (isTarget)
        {
            strncpy(action->target, action->thirdWord, sizeof(action->target) - 1);
            action->target[sizeof(action->thirdWord) -1] = '\0';
            return;
        }
    }
    if (!isTarget)
    {
        strcpy(action->target, " "); // if no target, clear it.
        action->target[sizeof(action->target) -1] = '\0';
    }
    // debug printf() to check if we properly retrieve a validTarget into target.
    printf("%s %s %s\n", action->command, action->target, isTarget ? "true" : "false");
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
