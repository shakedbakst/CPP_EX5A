#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm> 
#include <cstddef>

using namespace std;
namespace ariel{};

class MagicalContainer {

private:
    std::vector<int> elements;

public:
    MagicalContainer() = default;
    ~MagicalContainer() = default;

    void addElement(int element);
    void removeElement(int element);
    int size() const;
    std::vector<int> getElements() const;


    class AscendingIterator {
    private:
        const MagicalContainer& container;
        int index;

    public:
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();
        AscendingIterator(const MagicalContainer& container);

        AscendingIterator begin() const;
        AscendingIterator end() const;

        AscendingIterator& operator++();
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        int operator*() const;
    };

    class SideCrossIterator {
        private:
            const MagicalContainer& container;
            int index;
            bool fromStart;

        public:
            SideCrossIterator(const MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator();

            SideCrossIterator begin() const;
            SideCrossIterator end() const;

            SideCrossIterator& operator++();
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
    };

    class PrimeIterator {
        private:
            const MagicalContainer& container;
            int index;

        public:
            PrimeIterator(const MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();

            PrimeIterator begin() const;
            PrimeIterator end() const;

            PrimeIterator& operator++();
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
    };

};

#endif