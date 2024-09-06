#ifndef BOOK
#define BOOK

#include "./defines.h"

typedef struct {
    char Name[MaxLenghtName];
    char Author[MaxLenghtName];
    int Amount;
} book;

/**
 * @brief Creates a new book with the given details.
 * @param name Name of the book.
 * @param author Author of the book.
 * @param amount Amount of the book in stock.
 * @return A new book struct with the provided details.
 */
book CreateBook(char *name, char *author, int amount);

/**
 * @brief Updates the details of an existing book.
 * @param book_ptr Pointer to the book to be updated.
 * @param name New name of the book.
 * @param author New author of the book.
 * @param amount New amount of the book in stock.
 * @return True if the book was successfully updated, false otherwise.
 */
bool UpdateBook(book *book_ptr, char *name, char *author, int amount);

/**
 * @brief Reads the details of a book.
 * @param book_ptr Pointer to the book to be read.
 * @return A book struct with the details of the book.
 */
book ReadBook(book *book_ptr);

/**
 * @brief Validates the details of a book.
 * @param book_ptr Pointer to the book to be validated.
 * @return True if the book details are valid, false otherwise.
 */
bool validations(book *book_ptr);

// Getters

#endif // BOOK
