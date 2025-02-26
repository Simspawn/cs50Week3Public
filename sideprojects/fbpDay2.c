#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 1/11/25 Not enough changes today. I napped too hard and then got drunk again too soon.
// Still need a struct for stages/rooms, still need to logic nouns somefuckinghow~
// Still need to make a custom header to clean this shit up into seperate files.
// Still need to learn exactly how to do that by actually doing that.
// Gotta step down on the dicipline.
// If access to primary work station hadn't been cut off 4 hours early
// I would have accomplished much more today. 

const bool FirstBigProject = true, fbp = FirstBigProject;       // After I completed Substitution in week 2
bool quit = false;                                              // I realized the best way to learn more at the
                                                                // time was to put it all together into something
typedef struct                                                  // creative which I could be passionate about.
{                                                               // Obviously, a game~ One day RPG???
    char command[25];
    char target[50];
} Action;

/*
struct Save_State       // For future use to be able to save a state for return play.
{
    float currentStage;
};
*/

int main_Game_Loop();
void get_action(char *callingBuffer, size_t size, Action *action);
void doAction(Action *action);
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

        //doAction();       // Here we execute on the users input.
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



// will have to change entire function to
// take action.command and action.
// target or just Action.action?
// as an argument. It's prolly just Action *action
// This is our next starting point, we want to pass
// the action struct as an argument the same way we did
// for get_action(). We can use an if else to check for a target.
// We can then use a switch for either case to code action resonses.
// Will prolly have to pass the stages struct in the future
// to advance or interact with the stage.
void doAction(Action *action)

{
    if (validVerb(*action))
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
