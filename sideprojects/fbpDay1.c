#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
const bool FirstBigProject = true, fbp = FirstBigProject;       // This will be my first big project. After I completed
bool quit = false;                                              // Substitution in week 2 I realized the best way to learn
                                                                // more at the time was to put it all together into something
typedef struct                                                  // creative which I could be passionate about.
{
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
void doAction();

int main()
{
    main_Game_Loop();
}

int main_Game_Loop()
{
    printf("Stage description here.\n");      // Place holder for initial login.
    do
    {
        Action action;
        //doAction();
        char playerInput[75];    // Calling buffer
        get_action(playerInput, sizeof(playerInput), &action);

        //if you need to be able to quit early or not, un/comment below.
        /*
        if (strcmp(playerInput, "quit") == 0)
            quit = true;
        printf("what do you mean you want to %s? \n", playerInput);*/

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
        strncpy(action->command, token, sizeof(action->target) - 1);
        action->target[sizeof(action->target) -1] = '\0';
    } else
        {
            action->target[0] = '\0';       // Null terminate that shit if there's no target.
        }

}
}

void doAction()     // will have to change entire function to
                    // take action.command and action.
                    // target or just Action.action?
                    // as an argument. It's prolly just Action *action
                    // This is our next starting point, we want to pass
                    // the action struct as an argument the same way we did
                    // for get_action(). We can use an if else to check for a target.
                    // We can then use a switch for either case to code action resonses.
                    // Will prolly have to pass the stages struct in the future
                    // to advance or interact with the stage.
{
    if (strcmp(action.command, "quit") == 0)
    {
        quit = true;
    }
}

