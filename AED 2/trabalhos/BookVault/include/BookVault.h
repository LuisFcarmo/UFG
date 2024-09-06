#ifndef BOOKVAULT_H
#define BOOKVAULT_H

#include <gtk-3.0/gtk/gtk.h>
#include "../include/defines.h"

/**
 * @brief Initializes the book database.
 * @param None
 * @return None
 */
void InitBookDataBase();

/**
 * @brief Generates a unique ID.
 * @param None
 * @return A unique integer ID.
 */
int gerarID();

/**
 * @brief Initializes environment variables.
 * @param None
 * @return None
 */
void InitVariablesAmbiente();

/**
 * @brief Initializes the book database (duplicate function, consider removing one).
 * @param None
 * @return None
 */
void InitBookDataBase();

/**
 * @brief Handles the destruction of the main window.
 * @param None
 * @return None
 */
void on_main_window_destroy();

/**
 * @brief Registers a new user.
 * @param None
 * @return None
 */
void Register();

/**
 * @brief Navigates back to the login screen.
 * @param None
 * @return None
 */
void VoltarLogin();

/**
 * @brief Renders the main hub of the application.
 * @param None
 * @return None
 */
void render_hub();

/**
 * @brief Renders the book registration page.
 * @param None
 * @return None
 */
void render_cad_livro_pag();

/**
 * @brief Renders the login screen.
 * @param None
 * @return None
 */
void render_login();

/**
 * @brief Renders the book rental page.
 * @param None
 * @return None
 */
void render_alugar_livro();

/**
 * @brief Clears the text area.
 * @param entry A pointer to the GtkEntry widget to be cleared.
 * @return None
 */
void CleanArea(GtkEntry *entry);

/**
 * @brief Verifies if the session has expired.
 * @param None
 * @return True if the session has expired, false otherwise.
 */
bool Verify_expired_session();

/**
 * @brief Logs out the current user.
 * @param None
 * @return None
 */
void Logout();

/**
 * @brief Verifies the current session.
 * @param None
 * @return None
 */
void verify_session();

/**
 * @brief Handles the user login process.
 * @param None
 * @return None
 */
void Login();

/**
 * @brief Confirms the user registration.
 * @param None
 * @return None
 */
void ConfirmRegister();

/**
 * @brief Confirms the book registration.
 * @param None
 * @return None
 */
void confirm_cad_livro();

/**
 * @brief Applies the user interface style sheets.
 * @param None
 * @return None
 */
void usar_estilo();

#endif // BOOKVAULT_H
