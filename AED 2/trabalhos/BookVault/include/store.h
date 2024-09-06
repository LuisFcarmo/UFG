#ifndef STORE_H
#define STORE_H
#include "./defines.h"

typedef struct {
    Tree Bookstorage;
    int qtd;
    int id;
} store;

/**
 * @brief Creates a new book storage.
 * @param id A pointer to the storage ID.
 * @return The created store.
 */
store CreateStorage(int *id);

/**
 * @brief Finds a book in the store.
 * @param title The title of the book to find.
 * @param store A pointer to the store.
 * @return The book found.
 */
book FindBook(char *title, store *store);

/**
 * @brief Borrows a book from the store.
 * @param title The title of the book to borrow.
 * @param days The number of days to borrow the book.
 * @param store A pointer to the store.
 * @return An order for the borrowed book.
 */
order borrowAbook(char *title, int days, store *store);

/**
 * @brief Adds a book to the store's stock.
 * @param store A pointer to the store.
 * @param book A pointer to the book to add.
 * @return True if the book was successfully added, false otherwise.
 */
bool AddToStock(store *store, book *book);

/**
 * @brief Migrates book data to the database.
 * @param book A pointer to the book to migrate.
 * @return True if the migration was successful, false otherwise.
 */
bool MigrationToDatabe(book *book);

#endif // STORE_H
