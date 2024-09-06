#ifndef SESSION
#define SESSION
#include "defines.h"

typedef struct {
    user CurrentUser;
    struct tm *Expired;
} session;

/**
 * @brief Creates an empty session.
 * @return A pointer to an empty session.
 */
session *CreateSessionEmpty();

/**
 * @brief Creates a session for the given user.
 * @param user The user for whom the session is being created.
 * @return A pointer to the created session.
 */
session *CreateSession(user user);

/**
 * @brief Gets the name of the user in the session.
 * @param session A pointer to the session.
 * @return The name of the user in the session.
 */
char *GetName(session *session);

/**
 * @brief Gets the ID of the user in the session.
 * @param session A pointer to the session.
 * @return The ID of the user in the session.
 */
int GetId(session *session);

/**
 * @brief Compares two dates.
 * @param date1 The first date to compare.
 * @param date2 The second date to compare.
 * @return -1 if date1 is earlier than date2, 1 if date1 is later than date2, and 0 if they are equal.
 */
int compare_dates(int date1, int date2);

#endif // SESSION
