#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
    1/30/2025
    Start of day note. It's 8:52PM. Not sure why I was unable to force myself to begin coding all day.
    I'm getting really sick of this shit. I'd been looking forward to it so much. Then I just can't
    seem to force myself to do it. It's really pissing me off. Now that I've had a 2 beers, lets
    see if we can knock something out. Starting by reading every line of code we have so far.

    10pm and I haven't done anything consequential if anything at all. What is wrong with me. Is it
    really that the code is so disoganized? Is that really bothering me so much? I really don't wanna
    force a refactor into V2.0 before I have movement and looking functionality. I really might
    have to refactor into a 1.5 afterall just to to able to work on this... If that's even the problem tho...
    If we can't pull something useful out day9 may need to continue into 1/31/2025 (or involve a 1.5 refactor.
    Which should prolly be the plan.)

    Regardless you gotta figure out why you
    have so called "writers block" or "coders block" on this.
    You KNOW what you need to do, just do it.
    Either fuck off and do it or write the whole thing from scratch.
    Stop dicking around. In the morning have electrolytes, hot coffee,
    huel, workout, shower, give yourself the basics to have a chance at a
    good day. Then sit down, read this bullshit again, and write code....


    10:41PM
    Yeah, you need to refactor for using GameState.(previous, current, saveState), write a function to
    update_State(GameState) which is called within doAction() and updates both the previous and current
    by setting GameState.currentState by the solutions found in doAction(). You also need to lessen
    sideline comments and contain them to above function/struct/variable comments to explain what is
    directly below for large codeblocks or confusing variables. Having two different styles of comment
    to explain individual lines/vs/codeblocks is actually annoying as shit.

    11:23
    Is my paralysis instead caused by outscoping the project as it stands and trying to account for
    more than the code is ready to handle without solid foundations? Is the answer to simply do what
    I can and need to do to show the ability or do I really need to refactor into a 1.5 to do all of that?
    I'm really leaning toward re-writing the entire single file architecture, reformatting the comments,
    and attempting to streamline what I have before I try to do what I want to in the long run as
    compared to what I have at this time.

    I don't know... I really feel like just coding it out is the only real answer.... but
    forcing myself to do so is proving.... difficult given life, environment, and various other factors.

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
    bool isVerb;
    bool isTarget;
//    char validTarget[?][35];         // needs to be a 2d array that holds however many valid targets there may be
//  @^ What? Why? isTarget should handle this. Leave for now. Need may become clear again in future.
//  Hmm, maybe to hold the valid targets and information as to what to do with them when they are there~
//  Although that should prolly be handled in doAction() or something. It seems some of your functions are
//  already getting out of hand in terms of what exactly they handle.
} Action;

typedef struct
{
    float   stageID;                // Unique ID number for each stage.
    char    stageName[150];         // Unique stage name. Yes, we do need both name and unique id. Idk why yet but we do.
    char    description[2500];      // This will basically be the core, what tells all. May need multiple.
//    char    items[1][1];
    float   validExits[8][2];
/*
For float validExits;
    Construct this to hold a boolean value for each direction of
    travel as well as the linked valid stageID.
    IE
    if (validExits[2])
    {
        updateStage(Stage *allStages, validExit[2][1])
    }
*/
} Stage;

typedef struct
{
    Stage currentStage;
//    Player currentStatus;
//    Other state variables
} State;

typedef struct
{
    State currentState;
    State previousState;
    State saveState;
}GameState;

int main_Game_Loop();
void get_action(char *callingBuffer, size_t size, Action *action);
void doAction(Action *action);
void validVerb(Action *action);
void validateCommand(Action *action);
void validateTarget(Action *action);
struct updateState(GameState *currentGame);

int main()
{
    // Place holder for main menu. main menu will call new game or save state.
    // Maybe something about {if previousState = NULL State currentState = Stage *intro}  ??? *menu ???
    main_Game_Loop();
}

int main_Game_Loop()
{
    // Eventually this will be moved to stages.h && .c.
    Stage intro;
    intro.stageID = 0.0;
    strcpy(intro.description, "You wake up groggy and foggy. You're not Sure what just happened.\n"
                              "You find yourself in an empty dilaptidated old room."
                              ""
                              "");

    printf("%s\n", intro.description);
    do
    {
        Action action;                                        // Eventually this will be moved to the current state function.
        char playerInput[75];                                 // callingBuffer
        get_action(playerInput, sizeof(playerInput), &action);// Here parse the user input into something useable.

        //if you need to be able to quit early or not, un/comment below.
        if (strcmp(playerInput, "quit") == 0)
            quit = true;
        printf("what do you mean you want to %s %s? \n", action.command, action.target);    // debugging prfintf()

        doAction(&action);                                                                  // Here we execute on the users input.

        //updateStage(Stage *previous, Stage *current)
    }
    while (quit == false);
return 0;
}
/*
    I think these comments are solved, but I'm going to leave them for now.

// refactor get_action to be get_input. Create a new function to validate if any
// given string is a validVerb, validNoun, or validModifier before assignment to proper field.
// Create modifer field in Action struct.
// Possibly create a recognizedSentenceStructure 2d(3d?) array for examples of common use syntax?
// if strtoken == validVerb {verb = token} hasVerb = true
// else if strtoken == validNoun {noun = token} hasNoun = true
// else if strtoken == validModifier {modifier = token} has modifier = true
*/


void get_action(char *callingBuffer, size_t size, Action *action) // fgets(playerInput) delim, and return action.command and action.target
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
        strncpy(action->thirdWord, token, sizeof(action->thirdWord) - 1);
        action->thirdWord[sizeof(action->thirdWord) - 1] = '\0';            // Null terminate if there's no second word.
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
   switch (action->command)
    {
        if (strcmp(action->command))"look" == 0)
        {
            printf(gameState.current.description);
        }
    }
}

void validateCommand(Action *action)
{
    char validVerb[6][15] = {"look", "go", "north", "south", "east", "west"};   // short list of validVerb.
    int validVerbs = 6;
    // loop (action.firstWord) through validVerb
    for (int i = 0; i < validVerbs; i++)
    {
        if (strcmp(action->firstWord, validVerb[i]) == 0)
        {
            action->isVerb = true;
            break;
        }
    }
    // Once we find a validVerb
    if (action->isVerb)
    {
        strncpy(action->command, action->firstWord, sizeof(action->command) - 1);
        action->command[sizeof(action->command) -1] = '\0';
        return;
    }
    if (!action->isVerb)
    {
        // loop (action.secondWord) through validVerb
        for (int i = 0; i < validVerbs; i++)
        {
            if (strcmp(action->secondWord, validVerb[i]) == 0)
            {
               action->isVerb = true;
               break;
            }
        }
        if (action->isVerb)
        {
            strncpy(action->command, action->secondWord, sizeof(action->command) - 1);
            action->command[sizeof(action->secondWord) -1] = '\0';
            return;
        }
    }
    if (!action->isVerb)
    {
        printf("No valid verb.");
        return;
    }

    // debug printf() to check if we properly retrieve a verb into command. Should never print.
    printf("Validate command failed: %s %s\n", action->command, action->isVerb ? "true" : "false");
}

void validateTarget(Action *action)
{
    char validTarget[4][15] = {"west", "north", "east", "south"};           // short list of validTarget.
    int validTargets = 4;
    // loop (action.firstWord) through validTarget
    for (int i = 0; i < validTargets; i++)
    {
        if (strcmp(action->firstWord, validTarget[i]) == 0)
        {
            action->isTarget = true;
            break;
        }
    }
    // Once we find a validTarget copy it to target.
    if (action->isTarget)
    {
        strncpy(action->target, action->firstWord, sizeof(action->target) - 1);
        action->target[sizeof(action->firstWord) -1] = '\0';
        return;
    }
    if (!action->isTarget)
    {
        // loop (action.secondWord) through validVerb
        for (int i = 0; i < validTargets; i++)
        {
            if (strcmp(action->secondWord, validTarget[i]) == 0)
            {
               action->isTarget = true;
            }
        }
        if (action->isTarget)
        {
            strncpy(action->target, action->secondWord, sizeof(action->target) - 1);
            action->target[sizeof(action->secondWord) -1] = '\0';
            return;
        }
    }
        if (!action->isTarget)
    {
        // loop (action.secondWord) through validVerb
        for (int i = 0; i < validTargets; i++)
        {
            if (strcmp(action->thirdWord, validTarget[i]) == 0)
            {
               action->isTarget = true;
            }
        }
        if (action->isTarget)
        {
            strncpy(action->target, action->thirdWord, sizeof(action->target) - 1);
            action->target[sizeof(action->thirdWord) -1] = '\0';
            return;
        }
    }
    if (!action->isTarget)
    {
        strcpy(action->target, " "); // if no target, clear it.
        action->target[sizeof(action->target) -1] = '\0';
    }
    // debug printf() to check if we properly retrieve a validTarget into target.
    printf("%s %s %s\n", action->command, action->target, action->isTarget ? "true" : "false");
return;
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
