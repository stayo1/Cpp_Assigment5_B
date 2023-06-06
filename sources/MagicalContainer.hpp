#pragma once
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> original;
        vector<int *> ascending;
        vector<int *> crossing;
        vector<int *> primed;

    public:
        int size();
        void addElement(int);
        void removeElement(int);
        void originalAscend();
        void originalPrime();
        void originalCross();
        bool isPrime(int);

        // --------------------------------------------------
        // ----------------AscendingIterator-----------------
        // --------------------------------------------------

        class AscendingIterator
        {
        private:
            vector<int *>::iterator asc;
            MagicalContainer &container;
            size_t size;

        public:
            // Destructors N' Constructors
            ~AscendingIterator() = default;
            AscendingIterator(MagicalContainer &cont);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(AscendingIterator &&other) noexcept = default;

            // Operators
            AscendingIterator &operator=(AscendingIterator &&) noexcept;
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            int operator*();
            AscendingIterator &operator++();

            // Begin N' End
            AscendingIterator &begin();
            AscendingIterator &end();
        };

        // --------------------------------------------------
        // ----------------SideCrossIterator-----------------
        // --------------------------------------------------

        class SideCrossIterator
        {
        private:
            vector<int *>::iterator cross;
            MagicalContainer &container;
            size_t size;

        public:
            // Destructors N' Constructors
            ~SideCrossIterator() = default;
            SideCrossIterator(MagicalContainer &cont);
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(SideCrossIterator &&) noexcept = default;

            // Operators
            SideCrossIterator &operator=(const SideCrossIterator &other);
            SideCrossIterator &operator=(SideCrossIterator &&) noexcept;
            bool operator==(const SideCrossIterator &) const;
            bool operator!=(const SideCrossIterator &) const;
            bool operator>(const SideCrossIterator &) const;
            bool operator<(const SideCrossIterator &) const;
            int operator*();
            SideCrossIterator &operator++();

            // Begin N' End
            SideCrossIterator &begin();
            SideCrossIterator &end();
        };

        // --------------------------------------------------
        // -------------------PrimeIterator------------------
        // --------------------------------------------------

        class PrimeIterator
        {
        private:
            vector<int *>::iterator prime;
            MagicalContainer &container;
            size_t size;

        public:
            // Destructors N' Constructors
            ~PrimeIterator() = default;
            PrimeIterator(MagicalContainer &cont);
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(PrimeIterator &&) noexcept = default;

            // Operators
            PrimeIterator &operator=(const PrimeIterator &other);
            PrimeIterator &operator=(PrimeIterator &&) noexcept;
            bool operator==(const PrimeIterator &) const;
            bool operator!=(const PrimeIterator &) const;
            bool operator>(const PrimeIterator &) const;
            bool operator<(const PrimeIterator &) const;
            int operator*();
            PrimeIterator &operator++();

            // Begin N' End
            PrimeIterator &begin();
            PrimeIterator &end();
        };
    };
};