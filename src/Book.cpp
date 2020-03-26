#include "Book.hpp"

Book::Book(Log& log) : log_(log) {
    log_.logDebug("Book is opened");
}

Book::~Book() {
    log_.logDebug("Book is closed");
}
