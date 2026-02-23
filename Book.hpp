/**
 * @file Book.hpp
 * @brief Header file for the Book class
 *
 * This file demonstrates fundamental C++ concepts including:
 * - Composition (Book HAS-A Author)
 * - Constructors and Destructors
 * - Const methods
 * - Friend functions
 * - Inline/Outline implementations
 * - Static members
 * - Function overloading (not operators overloading)
 */

#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <iostream>

namespace library {

    // Forward declaration
    class LibraryCard;

    /**
     * @brief Author struct - demonstrates composition
     * Book will contain (compose) an Author object
     * 
     * IMPLEMENTATION NOTE FOR STUDENTS:
     * This struct is provided as-is. In your Book. cpp implementation,
     * you will CREATE Author objects and store them in the Book's private member. 
     * Example in Book.cpp:
     *   this->author = Author(authorName, "Unknown", 0);
     * or: 
     *   this->author = authorParam;
     */
    struct Author {
        std::string name;
        std::string country;
        int birthYear;

        Author() : name("Unknown"), country("Unknown"), birthYear(0) {}
        Author(const std::string& n, const std::string& c, int y) 
            : name(n), country(c), birthYear(y) {}
    };

    /**
     * @brief Book class representing a library book
     * Demonstrates:  composition, constructors/destructors, const methods,
     * static members, inline/outline, friend functions
     */
    class Book {
    private:
        std::string title;
        Author author;              // COMPOSITION: Book HAS-A Author
                                    // Students will initialize this in constructors
        std::string isbn;
        int pages;
        bool isAvailable;
        
        // Static member:  tracks total books created
        static int totalBooksCreated;
        
        // Static member: tracks currently existing books
        static int currentBookCount;

    public:
        // ============ Constructors ============
        
        /**
         * @brief Default constructor
         * Creates an "Unknown" book with default author
         * STUDENTS: Initialize author using default Author constructor
         */
        Book();

        /**
         * @brief Parameterized constructor - overloaded version 1
         * @param title Book title
         * @param authorName Author's name
         * @param isbn ISBN number
         * @param pages Number of pages
         * STUDENTS: Create an Author object with just the name: 
         *   this->author = Author(authorName, "Unknown", 0);
         */
        Book(const std:: string& title, const std::string& authorName, 
             const std::string& isbn, int pages);

        /**
         * @brief Parameterized constructor - overloaded version 2
         * Demonstrates function overloading (same name, different parameters)
         * @param title Book title
         * @param author Complete Author object (COMPOSITION parameter)
         * @param isbn ISBN number
         * @param pages Number of pages
         * STUDENTS:  Store the author object: 
         *   this->author = author;
         */
        Book(const std::string& title, const Author& author, 
             const std::string& isbn, int pages);

        /**
         * @brief Copy constructor
         * @param other The book to copy from
         * STUDENTS: Copy the author object:
         *   this->author = other.author;
         */
        Book(const Book& other);

        /**
         * @brief Destructor
         * Decrements static book counter
         */
        ~Book();

        // ============ Getters - Inline implementations ============
        
        /**
         * @brief Get book title - const method
         * @return The title
         * INLINE IMPLEMENTATION in header file
         */
        inline std::string getTitle() const {
            return title;
        }

        /**
         * @brief Get ISBN - const method
         * @return The ISBN
         * INLINE IMPLEMENTATION in header file
         */
        inline std::string getISBN() const {
            return isbn;
        }

        /**
         * @brief Get number of pages - const method
         * @return Number of pages
         * INLINE IMPLEMENTATION in header file
         */
        inline int getPages() const {
            return pages;
        }

        /**
         * @brief Check if book is available - const method
         * @return true if available for borrowing
         * INLINE IMPLEMENTATION in header file
         */
        inline bool getAvailability() const {
            return isAvailable;
        }

        // ============ Getters - Outline implementations (in .cpp file) ============

        /**
         * @brief Get author object by reference - const method
         * Demonstrates:  reference-return, const method
         * @return Const reference to the Author object
         * OUTLINE IMPLEMENTATION in .cpp file
         * STUDENTS: return this->author;
         */
        const Author& getAuthor() const;

        /**
         * @brief Get author name - const method
         * @return Author's name
         * OUTLINE IMPLEMENTATION in .cpp file
         * STUDENTS: Access composed object's member: 
         *   return this->author.name;
         */
        std::string getAuthorName() const;

        // ============ Setters - Outline implementations ============

        /**
         * @brief Set book title
         * @param title New title
         * OUTLINE IMPLEMENTATION in . cpp file
         */
        void setTitle(const std::string& title);

        /**
         * @brief Set author - overloaded version 1
         * Demonstrates function overloading
         * @param authorName Author's name
         * OUTLINE IMPLEMENTATION in .cpp file
         * STUDENTS: Update the composed Author object:
         *   this->author.name = authorName;
         * or create new Author: 
         *   this->author = Author(authorName, "Unknown", 0);
         */
        void setAuthor(const std:: string& authorName);

        /**
         * @brief Set author - overloaded version 2
         * Demonstrates function overloading
         * @param author Complete Author object
         * OUTLINE IMPLEMENTATION in .cpp file
         * STUDENTS: Replace the composed Author object:
         *   this->author = author;
         */
        void setAuthor(const Author& author);

        /**
         * @brief Set availability status
         * @param available New availability status
         * OUTLINE IMPLEMENTATION in .cpp file
         */
        void setAvailability(bool available);

        // ============ Static methods ============

        /**
         * @brief Get total number of books ever created
         * @return Total books created
         */
        static int getTotalBooksCreated();

        /**
         * @brief Get current number of Book objects in memory
         * @return Current book count
         */
        static int getCurrentBookCount();

        // ============ Utility methods - const methods ============

        /**
         * @brief Check if this is a large book - const method
         * @return true if pages > 500
         * OUTLINE IMPLEMENTATION in .cpp file
         */
        bool isLargeBook() const;

        /**
         * @brief Get book category based on pages - const method
         * @return "Short", "Medium", or "Long"
         * OUTLINE IMPLEMENTATION in .cpp file
         */
        std::string getCategory() const;

        /**
         * @brief Get book info string - const method
         * @return Formatted string with book details
         * OUTLINE IMPLEMENTATION in .cpp file
         */
        std::string getInfo() const;

        /**
         * @brief Print book details to stream
         * NOT operator overloading - just a regular method
         * @param os Output stream
         * OUTLINE IMPLEMENTATION in .cpp file
         * STUDENTS: Access composed author: 
         *   os << title << " by " << author.name << " | " << pages << " pages";
         */
        void print(std::ostream& os) const;

        // ============ Reference-return methods ============

        /**
         * @brief Get mutable reference to author
         * Demonstrates:  reference-return (non-const)
         * Allows modification of the author through the returned reference
         * @return Reference to Author object
         * OUTLINE IMPLEMENTATION in .cpp file
         * STUDENTS: return this->author;
         */
        Author& getAuthorReference();

        // ============ Friend functions ============

        /**
         * @brief Compare two books by page count
         * Friend function can access private members
         * @param b1 First book
         * @param b2 Second book
         * @return true if b1 has more pages than b2
         * STUDENTS: Access private members and composed objects:
         *   return b1.pages > b2.pages;
         */
        friend bool compareByPages(const Book& b1, const Book& b2);

        /**
         * @brief Check if two books have the same author
         * Friend function can access private members
         * @param b1 First book
         * @param b2 Second book
         * @return true if same author name
         * STUDENTS: Access composed objects through private members:
         *   return b1.author.name == b2.author.name;
         */
        friend bool haveSameAuthor(const Book& b1, const Book& b2);

        /**
         * @brief Friend class declaration
         * LibraryCard can access private members of Book
         */
        friend class LibraryCard;
    };

} // namespace library

#endif // BOOK_HPP