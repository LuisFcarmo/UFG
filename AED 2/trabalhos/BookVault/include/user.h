#ifndef USER
#define USER
#include "./defines.h"

/**
 * @brief Creates a new user.
 * @param name The name of the user.
 * @param password The password of the user.
 * @param id The ID of the user.
 * @return The created user.
 */
user CreateUser(char *name, char *password, int id);

/**
 * @brief Registers a user.
 * @param user The user to register.
 */
void RegisterUser(user user);

/**
 * @brief Validates the user's data.
 * @return True if the data is valid, false otherwise.
 */
bool Validations();
void LoginUser(user UserRef);

#endif // USER
