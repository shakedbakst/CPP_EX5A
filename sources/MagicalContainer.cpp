#include <algorithm> 
#include <vector>
#include <iostream>

#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {}

int MagicalContainer::size() const {
    return this->elements.size();
}

std::vector<int> MagicalContainer::getElements() const{
    return this->elements;
}


// AscendingIterator
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other): container(other.container), index(other.index){}

MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container) : container(container), index(0) {}

//MagicalContainer::AscendingIterator::AscendingIterator() {}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    return AscendingIterator(container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
    AscendingIterator iterator(container);
    iterator.index = container.elements.size();
    return iterator;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
    index++;
    return *this;
}

/*MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    return *this;
}*/
     
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
    return this->index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
    return this ->index != other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
    return this ->index > other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
    return this ->index < other.index;
}
        
int MagicalContainer::AscendingIterator::operator*() const{ 
    return container.elements[static_cast<std::vector<int>::size_type>(index)];
}

// SideCrossIterator
MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container) : container(container) {}
        
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(other.container), index(other.index){}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

//MagicalContainer::SideCrossIterator::SideCrossIterator() {}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
    SideCrossIterator iterator(container);
    iterator.index = container.elements.size();
    return iterator;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(){
    index++;
    return *this;
}

/*MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const AscendingIterator& other) {
    return *this;
}*/
     
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
    return this->index == other.index;
}
 
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
    return this ->index != other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
    return this ->index > other.index;
}
        
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
    return this ->index < other.index;
}
        
int MagicalContainer::SideCrossIterator::operator*() const{ 
    return container.elements[static_cast<std::vector<int>::size_type>(index)];
}

// PrimeIterator
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : container(container) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container) {}

MagicalContainer::PrimeIterator::~PrimeIterator() = default;

/*MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    return *this;
}*/

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
    return PrimeIterator(container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
    PrimeIterator iterator(container);
    iterator.index = container.elements.size();
    return iterator;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    index++;
    return *this;
}

//MagicalContainer::PrimeIterator::PrimeIterator() {}

bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator &other) const {
    return this->index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator &other) const {
    return this ->index != other.index;
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const {
    return this ->index > other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const {
    return this ->index < other.index;
}

int MagicalContainer::PrimeIterator::operator*() const{
    return container.elements[static_cast<std::vector<int>::size_type>(index)];
}