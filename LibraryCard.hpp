/**
 * @file LibraryCard.hpp
 * @brief Header file for the LibraryCard class
 *
 * This file demonstrates: 
 * - Composition (LibraryCard HAS-A Book array)
 * - Dynamic arrays with destructors (destruct-arrays)
 * - Reference parameters
 * - Const methods
 * - Static members
 * - Inline/Outline implementations
 */

#ifndef LIBRARYCARD_HPP
#define LIBRARYCARD_HPP

#include "Book.hpp"
#include <string>
#include <iostream>

namespace library {

    /**
     * @brief LibraryCard class for managing borrowed books
     * Demonstrates: composition, destruct-arrays, reference parameters
     * 
     * COMPOSITION NOTE FOR STUDENTS:
     * This class contains a dynamic array of Book pointers (Book**).
     * In your implementation, you will: 
     * 1. Allocate the array:  borrowedBooks = new Book*[capacity];
     * 2. Store Book objects:  borrowedBooks[i] = new Book(bookToBorrow);
     * 3. Access them: borrowedBooks[i]->getTitle()
     * 4. Delete them properly in destructor (destruct-arrays)
     */
    class LibraryCard {
    private:
        std::string memberName;
        std::string memberID;
        Book** borrowedBooks;      // COMPOSITION: Dynamic array of Book pointers
                                    // Students will manage this array's lifecycle
        int capacity;
        int borrowCount;
        
        // Static member: track total cards issued
        static int totalCardsIssued;

        /**
         * @brief Helper to resize the borrowed books array
         * OUTLINE IMPLEMENTATION in .cpp file
         * STUDENTS: Create new larger array, copy pointers, delete old array
         */
        void resize();

    public:
        // ============ Constructors ============

        /**
         * @brief Default constructor
         * Creates card for "Guest" with capacity 3
         * STUDENTS:  Allocate the Book array:
         *   borrowedBooks = new Book*[capacity];
         *   for(int i = 0; i < capacity; i++)
         *       borrowedBooks[i] = nullptr;
         */
        LibraryCard();

        /**
         * @brief Parameterized constructor
         * @param memberName Member's name
         * @param memberID Member ID
         * @param initialCapacity Initial capacity for books (default 3)
         * STUDENTS: Allocate the Book array as above
         */
        LibraryCard(const std::string& memberName, const std::string& memberID, 
                   int initialCapacity = 3);

        /**
         * @brief Copy constructor - deep copy
         * @param other Card to copy from
         * STUDENTS:  Perform DEEP copy of the Book array: 
         *   - Allocate new array
         *   - Copy each Book object (not just pointers!)
         *   borrowedBooks[i] = new Book(*other.borrowedBooks[i]);
         */
        LibraryCard(const LibraryCard& other);

        /**
         * @brief Destructor
         * CRITICAL: Must properly delete array of Book pointers
         * Demonstrates destruct-arrays concept
         * STUDENTS: 
         *   1. Delete each Book object: 
         *      for(int i = 0; i < borrowCount; i++)
         *          delete borrowedBooks[i];
         *   2. Delete the array itself:
         *      delete[] borrowedBooks;
         */
        ~LibraryCard();

        // ============ Getters - Inline implementations ============

        /**
         * @brief Get member name - const method
         * @return Member name
         * INLINE IMPLEMENTATION
         */
        inline std::string getMemberName() const {
            return memberName;
        }

        /**
         * @brief Get member ID - const method
         * @return Member ID
         * INLINE IMPLEMENTATION
         */
        inline std::string getMemberID() const {
            return memberID;
        }

        /**
         * @brief Get number of borrowed books - const method
         * @return Borrow count
         * INLINE IMPLEMENTATION
         */
        inline int getBorrowCount() const {
            return borrowCount;
        }

        /**
         * @brief Get capacity - const method
         * @return Current capacity
         * INLINE IMPLEMENTATION
         */
        inline int getCapacity() const {
            return capacity;
        }

        /**
         * @brief Check if card is full - const method
         * @return true if no more books can be borrowed
         * INLINE IMPLEMENTATION
         */
        inline bool isFull() const {
            return borrowCount >= capacity;
        }

        // ============ Setters - Outline implementations ============

        /**
         * @brief Set member name
         * @param name New name
         * OUTLINE IMPLEMENTATION
         */
        void setMemberName(const std::string& name);

        // ============ Static methods ============

        /**
         * @brief Get total cards issued
         * @return Total cards issued
         */
        static int getTotalCardsIssued();

        // ============ Book management - Reference parameters ============

        /**
         * @brief Borrow a book (adds to borrowed list)
         * Demonstrates:  reference parameter, composition
         * @param book Reference to the book to borrow
         * @return true if successful, false if card is full
         * OUTLINE IMPLEMENTATION
         * STUDENTS: Create a copy and store it:
         *   borrowedBooks[borrowCount] = new Book(book);
         *   borrowCount++;
         */
        bool borrowBook(const Book& book);

        /**
         * @brief Return a book by index
         * @param index Index of book to return
         * @return true if successful
         * OUTLINE IMPLEMENTATION
         * STUDENTS: Delete the Book and shift remaining books:
         *   delete borrowedBooks[index];
         *   // shift books down
         */
        bool returnBook(int index);

        /**
         * @brief Return a book by title
         * Demonstrates: reference parameter (const reference)
         * @param title Title of book to return
         * @return true if found and returned
         * OUTLINE IMPLEMENTATION
         * STUDENTS: Find book by accessing composed objects:
         *   if(borrowedBooks[i]->getTitle() == title)
         */
        bool returnBook(const std::string& title);

        /**
         * @brief Find a borrowed book - const method
         * Demonstrates: reference-return
         * @param title Title to search for
         * @return Pointer to book if found, nullptr otherwise
         * OUTLINE IMPLEMENTATION
         * STUDENTS: Search through composed Book array
         */
        Book* findBorrowedBook(const std::string& title) const;

        /**
         * @brief Get total pages of all borrowed books - const method
         * @return Total pages
         * OUTLINE IMPLEMENTATION
         * STUDENTS: Sum pages from all composed Book objects: 
         *   total += borrowedBooks[i]->getPages();
         */
        int getTotalBorrowedPages() const;

        /**
         * @brief Print all borrowed books - const method
         * OUTLINE IMPLEMENTATION
         * STUDENTS: Call print() on each composed Book: 
         *   borrowedBooks[i]->print(os);
         */
        void printBorrowedBooks() const;

        /**
         * @brief Print card details to stream
         * NOT operator overloading - just a regular method
         * @param os Output stream
         * OUTLINE IMPLEMENTATION
         */
        void print(std::ostream& os) const;

        /**
         * @brief Clear all borrowed books
         * Demonstrates proper array destruction
         * OUTLINE IMPLEMENTATION
         * STUDENTS: Delete all Book objects:
         *   for(int i = 0; i < borrowCount; i++)
         *       delete borrowedBooks[i];
         *   borrowCount = 0;
         */
        void clear();

        // ============ Friend functions ============

        /**
         * @brief Compare two cards by borrow count
         * @param c1 First card
         * @param c2 Second card
         * @return true if c1 has more borrowed books
         * STUDENTS: Access private members: 
         *   return c1.borrowCount > c2.borrowCount;
         */
        friend bool compareByBorrowCount(const LibraryCard& c1, const LibraryCard& c2);
    };

} // namespace library

#endif // LIBRARYCARD_HPP