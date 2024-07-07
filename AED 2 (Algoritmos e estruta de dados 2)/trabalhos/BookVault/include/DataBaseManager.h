#ifndef DATABASE_MANAGER
#define DATABASE_MANAGER

#include "defines.h"

/**
 * @brief Accesses the database file with the given mode.
 * @param path The path to the database file.
 * @param mode The mode in which to open the file (e.g., "r", "w").
 * @return A pointer to the opened file, or NULL if an error occurred.
 */
FILE *AcessDataBase(const char* path, const char *mode);

/**
 * @brief Closes the given database file.
 * @param db A pointer to the file to be closed.
 * @return A NULL pointer.
 */
FILE *CloseDataBase(FILE *db);

#endif // DATABASE_MANAGER
